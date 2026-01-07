# ViolaWWW Security Implementation Guide

> **Status:** Implementation plan for completing the unfinished security system  

## Security Model

### Two Trust Levels

| Level | Value | Meaning | Source |
|-------|-------|---------|--------|
| **Trusted** | `security = 0` | Full access | Local files (`file://localhost/...`), built-in objects |
| **Untrusted** | `security = 1` | Restricted | Network content, external `.v` files |

**Core Rule:** Untrusted objects cannot perform dangerous operations without user confirmation.

### Trust by Origin

ViolaWWW использует формат `file://hostname/path` (см. `HTFile.c:291`):
```c
sprintf(result, "file://%s%s", HTHostName(), name);
```

Парсер URL (`HTParse.c`) извлекает hostname между `//` и следующим `/`.

**Правило:** Локальным считается файл, если hostname совпадает с `HTHostName()` или пуст.

```
LOCAL (trusted):
  file://myhost/path    → security = 0  (myhost = текущая машина)
  /absolute/path        → security = 0

REMOTE (untrusted):
  http://...            → security = 1
  https://...           → security = 1
  ftp://...             → security = 1
  file://otherhost/path → security = 1  (другая машина)
  relative/path         → inherits from base document
```

### Operation Permissions

```
ALWAYS BLOCKED for untrusted (security = 1):
  set("security", 0)    — privilege escalation
  interpret()           — arbitrary code execution
  tweak()               — cross-object code injection

BLOCKED UNLESS USER APPROVES:
  loadObjFile()         — loading external code
  loadFile()/saveFile() — file access
  deleteFile()          — file deletion
  system()/exec()/pipe() — shell commands
  HTTPGet/Post()        — network access (from untrusted context)
  socket.startClient()  — arbitrary TCP/UDP connections (cl_socket.c)
  TTY.startClient()     — executes subprocess (cl_TTY.c)

ALWAYS ALLOWED:
  get/set attributes (except security)
  render, expose, config
  send() to child objects
  UI operations
```

---

## Vulnerabilities

### Critical (P0) — Security Bypass

#### P0-1. Shell Injection

**Location:** `src/viola/embeds/wwwSecurity_script.v`

```javascript
// VULNERABLE — user input goes directly to shell:
system(concat("mv ", dumpFile, " ", arg[2]));
system(concat("mail -s \"", arg[2], "\" ", arg[1], " < ", arg[3]));
```

**Fix:** Replace `system()` calls with safe C functions (`rename()`, SMTP library).

#### P0-2. Privilege Escalation via `set("security", 0)`

**Location:** `src/viola/cl_generic.c`, `case STR_security`

Any object can set its own security to 0. No check exists.

**Fix:** Block escalation from 1→0:

```c
case STR_security: {
    long newLevel = PkInfo2Int(&argv[1]);
    long currentLevel = GET_security(self);
    
    // Normalize (anything non-zero → 1)
    if (newLevel != 0) newLevel = 1;
    
    // Block privilege escalation
    if (currentLevel == 1 && newLevel == 0) {
        fprintf(stderr, "Security: privilege escalation denied for '%s'\n",
            GET_name(self));
        result->info.i = 1;
        result->type = PKT_INT;
        return 0;
    }
    
    helper_setSecurity(self, newLevel);
    // ...
}
```

#### P0-3. `loadObjFile()` Missing Security Check

**Location:** `src/viola/cl_cosmic.c`

No `notSecure()` check — untrusted objects can load arbitrary `.v` files.

**Fix:** Add at function start:

```c
if (notSecure(self)) {
    result->info.i = 0;
    result->type = PKT_INT;
    return 0;
}
```

#### P0-4. `clone()` Copies `security=0`

**Location:** `src/viola/class.c:755`

Bitwise copy of all slots including `security`:

```c
*clonep = *originalp;  // Copies security level!
```

**Exploit:**

```javascript
/* Untrusted script can escalate to trusted: */
trustedTemplate = object("HTML.txt");  /* trusted template, security=0 */
myClone = send(trustedTemplate, "clone", cloneID());
/* myClone inherits security=0! */
send(myClone, "interpret", "system(\"rm -rf /\")");
```

**Fix:** Force cloned object to inherit caller's security level:

```c
/* After cloning, in class.c */
*clonep = *originalp;

/* Security fix: clone inherits the HIGHER (more restrictive) security level */
int callerSecurity = GET_security(self);  /* self = object calling clone() */
int cloneSecurity = GET_security(clonep);
if (callerSecurity > cloneSecurity) {
    SET_security(clonep, callerSecurity);
}
```

**Alternative fix:** Always set clone's security to caller's security:

```c
SET_security(clonep, GET_security(self));
```

---

### High (P1) — Privilege Escalation / Data Leakage

#### P1-1. Path Traversal in `rmTmpFile`

**Location:** `src/viola/embeds/wwwSecurity_script.v`

Check for `/tmp/` prefix doesn't prevent `/../` escape.

**Fix:** Reject `..` and use atomic operations:

```c
int safeDeleteTmpFile(const char* path) {
    if (strncmp(path, "/tmp/", 5) != 0) return -1;
    if (strstr(path, "..") != NULL) return -1;
    
    // No subdirectories allowed
    if (strchr(path + 5, '/') != NULL) return -1;
    
    // Check not a symlink
    struct stat st;
    if (lstat(path, &st) < 0) return -1;
    if (S_ISLNK(st.st_mode)) return -1;
    
    return unlink(path);
}
```

#### P1-2. `notSecure(NULL)` Crash

**Location:** `src/viola/cl_cosmic.c`

`notSecure()` dereferences NULL when called with `self = NULL` (e.g., from image loading).

**Fix:**

```c
int notSecure(VObj* self) {
    if (self == NULL) return 1;  // NULL = untrusted
    if (GET_security(self) > 0) {
        fprintf(stderr, "Security: denied for '%s'\n", GET_name(self));
        return 1;
    }
    return 0;
}
```

#### P1-3. Missing `HTML_security` Object

The `<SECURITY LEVEL="...">` tag is defined in DTD but has no handler — tag is silently ignored.

**Fix:** Create `src/viola/embeds/HTML_security_script.v` and register in `objs.c`.

#### P1-4. Empty Confirmation Dialog

**Location:** `src/viola/embeds/wwwDialog_confirm_script.v`

The dialog is empty — does nothing, returns nothing.

**Fix:** Implement using C-based `securityQuestionDialog()` to prevent spoofing.

---

### Medium (P2) — Missing Functionality

#### P2-1. Empty Security Functions

**Location:** `src/viola/embeds/mvw_script3.v`, lines 167-175

Three stubs: `queryDocSecurity`, `setSecurityClearence`, `querySecurityClearence`.

#### P2-2. Relative URL Trust Inheritance

Relative URLs (no `:`) incorrectly treated as local/trusted.

**Fix:** Inherit trust from base document URL.

#### P2-3. `file://host/` Confusion

`file://evil.com/malicious.v` is a valid `file:` URL but points to remote host.

**Fix:** Trust only if hostname = `HTHostName()` or empty.

---

## Implementation Details

### URL Trust Detection

```c
int isLocalURL(const char* url) {
    if (!url) return 0;
    
    // Absolute local path
    if (url[0] == '/') return 1;
    
    // Check protocol
    char* access = HTParse(url, "", PARSE_ACCESS);
    if (!access || !*access) {
        free(access);
        return -1;  // Relative path - caller must check base document
    }
    
    // Non-file protocols are remote
    if (strcmp(access, "file") != 0) {
        free(access);
    return 0;
}
    free(access);
    
    // file:// URL - check hostname
    char* host = HTParse(url, "", PARSE_HOST);
    int isLocal = (!host || !*host || strcmp(host, HTHostName()) == 0);
    free(host);
    return isLocal ? 1 : 0;
}

int getURLTrust(const char* url, const char* baseURL) {
    int local = isLocalURL(url);
    if (local >= 0) return local ? 0 : 1;
    
    // Relative URL - inherit from base
    if (!baseURL) return 1;  // No base = untrusted
    return isLocalURL(baseURL) ? 0 : 1;
}
```

### Input Validation (Whitelist)

```c
// Filename: alphanumeric, dot, underscore, hyphen, slash
int isValidFilename(const char* s) {
    if (!s || !*s || s[0] == '-') return 0;
    
    for (const char* p = s; *p; p++) {
        char c = *p;
        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9') ||
            c == '.' || c == '_' || c == '-' || c == '/') {
            continue;
        }
    return 0;
}
    
    return (strstr(s, "..") == NULL);  // No path traversal
}

// Email: alphanumeric, @, dot, underscore, hyphen, plus
int isValidEmail(const char* s) {
    if (!s || !*s) return 0;
    
    const char* at = strchr(s, '@');
    if (!at || at == s) return 0;
    if (strchr(at + 1, '@')) return 0;
    if (!strchr(at + 1, '.')) return 0;
    
    for (const char* p = s; *p; p++) {
        char c = *p;
        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9') ||
            c == '.' || c == '_' || c == '-' || c == '+' || c == '@') {
            continue;
        }
    return 0;
}
    return 1;
}
```

### Security Dialog (C Implementation)

Dialogs must be in C to prevent script spoofing.

```c
// In src/vw/dialog.c
int securityQuestionDialog(DocViewInfo* dvip, 
                           const char* title,
                           const char* message,
                           const char* yesLabel,
                           const char* noLabel) {
    if (!dvip || !message) return 0;
    if (!yesLabel) yesLabel = "Yes";
    if (!noLabel) noLabel = "No";
    
    char* answer = questionDialog(dvip, message, noLabel, yesLabel, noLabel, NULL);
    return (answer && strcmp(answer, yesLabel) == 0) ? 1 : 0;
}
```

### Privilege Elevation Logic

Dialog is shown **once** — when document attempts to elevate LEVEL from 1 to 0.

**When dialog is shown:**

1. Remote document contains `<SECURITY LEVEL=0>`
2. Object with LEVEL=1 calls `set("security", 0)`
3. Object with LEVEL=1 attempts a restricted operation

**Dialog:**

```
┌─────────────────────────────────────────────────────┐
│  [!]  Privilege Elevation Request                   │
├─────────────────────────────────────────────────────┤
│                                                     │
│  Document:                                          │
│    http://example.com/app.html                      │
│                                                     │
│  is requesting full system access.                  │
│                                                     │
│  Reason:                                            │
│    <SECURITY LEVEL=0> tag in document               │
│    (or: call to system("ls -la"))                   │
│    (or: loading http://x.com/code.v)                │
│                                                     │
│  WARNING: Trusted documents can:                    │
│    • read and write files                           │
│    • execute system commands                        │
│    • load and execute code                          │
│                                                     │
│  Do you trust this document?                        │
│                                                     │
│            [ Trust ]      [ Don't Trust ]           │
└─────────────────────────────────────────────────────┘
```

**Logic:**

```
┌─────────────────┐
│ Request to      │
│ elevate         │
│ LEVEL 1 → 0     │
└────────┬────────┘
         │
         ▼
┌─────────────────┐    Yes      ┌─────────────────┐
│ User trusts?    │────────────▶│ LEVEL = 0       │
│                 │             │ All operations  │
└────────┬────────┘             │ allowed         │
         │ No                   └─────────────────┘
         ▼
┌─────────────────┐
│ LEVEL stays 1   │
│ Operation       │
│ blocked         │
│ Dialog not      │
│ shown again     │
└─────────────────┘
```

**Implementation:**

```c
/* Add flag to DocViewInfo */
typedef struct {
    /* ... */
    int security_asked;    /* 0=not asked, 1=trusted, -1=denied */
} DocViewInfo;

/* Check when attempting to elevate privileges */
int requestSecurityElevation(DocViewInfo* dvi, const char* reason) {
    /* Already asked */
    if (dvi->security_asked != 0) {
        return (dvi->security_asked == 1) ? 1 : 0;
    }
    
    /* Ask user */
    char message[1024];
    snprintf(message, sizeof(message),
        "Document:\n  %s\n\n"
        "is requesting full system access.\n\n"
        "Reason:\n  %s\n\n"
        "WARNING: Trusted documents can:\n"
        "  - read and write files\n"
        "  - execute system commands\n"
        "  - load and execute code\n\n"
        "Do you trust this document?",
        dvi->docURL, reason);
    
    int trusted = securityQuestionDialog(dvi, 
        "Privilege Elevation Request", message,
        "Trust", "Don't Trust");
    
    dvi->security_asked = trusted ? 1 : -1;
    
    if (trusted) {
        /* Set LEVEL=0 for entire document */
        setDocumentSecurityLevel(dvi, 0);
    }
    
    return trusted;
}
```

**Important:** After denial, dialog is not shown again — all subsequent requests are automatically blocked.

---

## Implementation Checklist

### P0 — Critical

- [ ] P0-1. Replace `system()` in `wwwSecurity_script.v` with safe C functions
- [ ] P0-2. Block `set("security", 0)` for untrusted objects in `cl_generic.c`
- [ ] P0-3. Add `notSecure()` check to `loadObjFile()` in `cl_cosmic.c`
- [ ] P0-4. Fix `clone()` in `class.c` — must not copy `security=0` from template

### P1 — High

- [ ] P1-1. Fix path traversal in `rmTmpFile` (block `..`, check symlinks)
- [ ] P1-2. Make `notSecure(NULL)` return 1 instead of crashing
- [ ] P1-3. Create `HTML_security` object handler
- [ ] P1-4. Implement security dialog in C (prevent spoofing)

### P2 — Medium

- [ ] P2-1. Implement security functions in `mvw_script3.v`
- [ ] P2-2. Make relative URLs inherit trust from base document
- [ ] P2-3. Fix `file://host/` to be untrusted

### Hardening

- [ ] Use whitelist validation for filenames and emails
- [ ] Add dialog rate limiting
- [ ] Show final URL after redirects in dialogs
- [ ] Audit all methods for `notSecure()` checks:
  - `system()`, `exec()`, `fork()`, `pipe()`
  - `loadFile()`, `saveFile()`, `deleteFile()`, `createFile()`
  - `HTTPPost()`
  - `socket._startClient()` in `cl_socket.c` — arbitrary TCP/UDP connections
  - `TTY.startClient()` in `cl_TTY.c` — executes `path` as subprocess

### Tests

- [ ] `test_security_escalation.c` — `set("security", 0)` blocked
- [ ] `test_loadobjfile_security.c` — `loadObjFile()` respects security
- [ ] `test_shell_injection.c` — metacharacter filtering
- [ ] `test_notsecure_null.c` — NULL handling

---

## References

- [SECURITY_REFERENCE.md](SECURITY_REFERENCE.md) — Security analysis
- [VIOLA_FUNCTIONS.md](VIOLA_FUNCTIONS.md) — Function reference
- [ViolaWWW Book, Chapter 4.7](https://web.archive.org/web/20030816230407/http://www.xcf.berkeley.edu/~wei/viola/book/chp4.html)
