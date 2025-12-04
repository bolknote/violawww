# ViolaWWW Security Architecture Reference

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

#### 3. Irreversible Security Mode

Once `securityMode` becomes non-zero, it cannot be reset:

```c
if (securityMode == 0)  // One-way door
    securityMode = PkInfo2Int(&argv[1]);
```

**Impact**: A single compromised page can permanently compromise the browser.

### Attack Scenarios

#### Basic Privilege Escalation

1. Load HTML containing `<vobjf href="malicious.v">`
2. `malicious.v` contains an object with script: `set("security", 0)`
3. Attacker gains full privileges

#### Persistent Compromise

1. Malicious content sets `securityMode(1)`
2. All future objects created with `security = 1`
3. Security mode cannot be reset to safe state

## HTML Tag Security

### Active Tags

Tags that create interactive objects:

- `<VOBJF>` - Loads external `.v` files
- `<FORM>`, `<INPUT>` - Form elements with event handling
- `<A>` - Links with navigation scripts

## Implementation Status

The security system appears incomplete:

### Implemented Features
- Basic object-level security attributes
- Privilege checking for core operations
- Global security mode
- HTML tag processing

### Missing Features
- Sandboxing for loaded content
- Content validation
- Secure script execution
- Network request filtering

### Incomplete Tags
- `<SECURITY>` tag defined but unimplemented
- DTD attributes present but unused

## Historical Context

ViolaWWW was developed in 1992-1994, predating modern web security concepts:

- **No sandboxing**: Content runs with full application privileges
- **Trust-based model**: Assumes benign content
- **Object-oriented security**: Novel approach for the era
- **Incomplete implementation**: Security features not fully developed

## Modern Security Comparison

Contemporary browsers implement:

- **Process isolation**: Content runs in separate processes
- **Capability-based security**: Explicit permission grants
- **Content Security Policy**: Script and resource restrictions
- **Same-origin policy**: Cross-origin request restrictions

ViolaWWW's security model is fundamentally incompatible with modern web security requirements.

## Recommendations

For educational/research purposes only:

1. **Never expose ViolaWWW to untrusted content**
2. **Avoid loading external `.v` files**
3. **Consider the system as having no security boundaries**
4. **Use in isolated environments only**

## Conclusion

ViolaWWW's security architecture represents an early attempt at web security but suffers from critical design flaws and incomplete implementation. The system provides illusory protection while actually offering minimal security against determined attackers. Its design reflects the security assumptions of the early web, where content was generally trusted and malicious intent was not a primary concern.
