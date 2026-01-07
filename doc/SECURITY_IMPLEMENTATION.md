# ViolaWWW Security Implementation

> **Added in: ViolaWWW 4.0**
> The security model was defined in the original ViolaWWW (1994) but not fully implemented. The complete working implementation was completed in version 4.0 (2026).

## Overview

ViolaWWW 4.0 implements a complete security system to protect users from malicious web content. The security model uses two trust levels and requires user confirmation for dangerous operations.

## Security Model

### Two Trust Levels

| Level | Value | Meaning | Source |
|-------|-------|---------|--------|
| **Trusted** | `security = 0` | Full access | Local files (`file://`), built-in objects |
| **Untrusted** | `security = 1` | Restricted | Network content (`http://`, `https://`), external `.v` files |

### Trust by Origin

```
LOCAL (trusted, security = 0):
  file://localhost/path    → trusted
  /absolute/path           → trusted

REMOTE (untrusted, security = 1):
  http://...               → untrusted
  https://...              → untrusted
  ftp://...                → untrusted
```

### Trusted Documents List

When user clicks "Trust" in the security dialog, the document URL is added to a trusted documents list. All subsequent security checks for objects from that document are automatically allowed without prompting.

## Protected Operations

### Operations Requiring User Confirmation (`notSecureWithPrompt`)

When an untrusted object attempts these operations, a security dialog is shown:

| Operation | Description | Location |
|-----------|-------------|----------|
| `system()` | Execute shell command | `cl_generic.c` |
| `pipe()` | Execute shell command with I/O | `cl_generic.c` |
| `loadFile()` | Read file from disk | `cl_generic.c` |
| `saveFile()` | Write file to disk | `cl_generic.c` |
| `deleteFile()` | Delete file (non-temp only) | `cl_generic.c` |
| `violaPath(path)` | Modify object search path | `cl_generic.c` |
| `socket.startClient()` | Open TCP connection | `cl_socket.c` |
| `TTY.startClient()` | Execute subprocess | `cl_TTY.c` |
| `set("security", 0)` | Elevate to trusted status | `cl_generic.c` |

Note: `deleteFile()` for temp directories (`/tmp/`, `/var/tmp/`, `/var/folders/`) is allowed without prompting. Path traversal (`..`) is blocked.

### Operations Silently Blocked (`notSecure`)

These operations fail silently for untrusted objects without user prompt:

| Operation | Description | Location |
|-----------|-------------|----------|
| `exit()`, `quit()` | Terminate application | `cl_cosmic.c` |
| `destroy()` | Destroy object | `cl_cosmic.c` |
| `modalExit()` | Exit modal dialog | `cl_cosmic.c` |
| `save()`, `saveFormatted()` | Save object to file | `cl_cosmic.c` |
| `tweak()` | Execute script in another object's context | `cl_cosmic.c` |
| `cli()` | Command line interface | `cl_generic.c` |
| `environVar()` | Get environment variable | `cl_generic.c` |
| `accessible()` | Check file accessibility | `cl_generic.c` |
| `loadSTG()` | Load style file | `cl_generic.c` |
| `setResource()` | Set X11 resource | `cl_generic.c` |
| `unhash()` | Get symbol name | `cl_generic.c` |
| `HTTPHotList*()` | Hotlist operations (Add, Delete, Get, Change, Load, Save) | `cl_generic.c` |
| `SGML*()` | Document building (BuildDoc, BuildDocB, ReBuildDoc, setBuff) | `cl_generic.c` |

### Trust Inheritance

`loadObjFile()` does not prompt the user but assigns security level to loaded objects based on `current_addr`:
- Local files (`/...` or `file://`) → objects get `security = 0` (trusted)
- Remote URLs → objects get `security = 1` (untrusted)

## Security Dialog

When an untrusted object attempts a protected operation, the user sees:

```
┌─────────────────────────────────────────────────────┐
│  [?]  Privilege Elevation Request                   │
├─────────────────────────────────────────────────────┤
│                                                     │
│  Document:                                          │
│    https://example.com/app.html                     │
│                                                     │
│  is requesting full system access.                  │
│                                                     │
│  Reason:                                            │
│    open TCP connection to server.com:7777           │
│                                                     │
│  WARNING: Trusted documents can:                    │
│    - read and write files                           │
│    - execute system commands                        │
│    - load and execute code                          │
│                                                     │
│  Do you trust this document?                        │
│                                                     │
│            [ Trust ]      [ Don't Trust ]           │
└─────────────────────────────────────────────────────┘
```

### Dialog Behavior

- **Trust**: Document URL added to trusted list, operation proceeds, future operations from same document allowed automatically
- **Don't Trust**: Operation blocked, user can try again later

### Dialog Details

The dialog shows:
- Full document URL (shortened if > 60 characters)
- Specific operation being attempted (e.g., command for `system()`, host:port for socket)

## Implementation Details

### Core Functions

#### `notSecure(VObj* self)`

Returns 1 if object is untrusted, 0 if trusted. Does not prompt user.

```c
int notSecure(VObj* self) {
    if (self == NULL) return 1;  /* NULL = untrusted */
    return (GET_security(self) > 0) ? 1 : 0;
}
```

#### `notSecureWithPrompt(VObj* self, const char* operation)`

Checks security with user confirmation. Returns 1 if blocked, 0 if allowed.

1. Checks if document URL is in trusted list → allow
2. Checks object's security level → if 0, allow
3. Shows security dialog → if Trust, add to trusted list and allow
4. Otherwise → block

#### `ViolaRegisterSecurityCallback()`

Registers the C-based security dialog callback from VW frontend.

### Clone Security

Cloned objects inherit security from the original object. If `securityMode` global is set, it overrides.

## Files Modified

| File | Changes |
|------|---------|
| `src/viola/cl_cosmic.c` | `notSecure()`, `notSecureWithPrompt()`, trusted docs list, `loadObjFile()` security |
| `src/viola/cl_cosmic.h` | Security callback typedef and prototypes |
| `src/viola/cl_generic.c` | Security checks for `system()`, `pipe()`, `loadFile()`, `saveFile()`, `deleteFile()`, `violaPath()`, privilege escalation block |
| `src/viola/cl_socket.c` | Security check for `startClient()` |
| `src/viola/cl_TTY.c` | Security check for `startClient()` |
| `src/viola/loader.c` | `load_object_with_security()` for trust assignment |
| `src/viola/class.c` | Clone security inheritance |
| `src/vw/dialog.c` | `securityQuestionDialog()` implementation |
| `src/vw/dialog.h` | Dialog prototypes |
| `src/vw/vw.c` | Security callback registration |

## Known Limitations

1. **Clone crash**: Race condition between cloning and event handling causes heap-use-after-free (unrelated to security, tracked in TODO.md)
2. **Dialog icon position**: Motif MessageBox icon is centered, cannot be aligned to top
3. **Per-session trust**: Trusted documents list is not persisted between sessions

## References

- [SECURITY_REFERENCE.md](SECURITY_REFERENCE.md) — Security analysis and threat model
- [ViolaWWW Book, Chapter 4.7](https://web.archive.org/web/20030816230407/http://www.xcf.berkeley.edu/~wei/viola/book/chp4.html) — Original security design
