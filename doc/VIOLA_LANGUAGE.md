# Viola Language Reference

> **Documentation created in: ViolaWWW 4.0**  
> This document describes the original Viola language from ViolaWWW v3.x (1992-1995).

Viola is a **two-level language** system consisting of an object file format for GUI declarations and a C-like scripting language for behavior.

---

## Object File Format (`.v` files)

The `.v` file format is a declarative notation for defining GUI objects and their properties.

### Basic Syntax

```
\class {vpane}
\name {hello}
\width {200}
\height {60}
\children {hello.mesg hello.bye}
\BGColor {grey45}
\script {
    ...script code...
}
\
```

### Syntax Elements

| Element | Description |
|---------|-------------|
| `\attribute {value}` | Attribute definition |
| `\` (alone on line) | Object separator (multiple objects in one file) |
| `\\comment text` | Comment (double backslash) |

### Common Attributes

| Attribute | Type | Description |
|-----------|------|-------------|
| `class` | string | Widget class name |
| `name` | string | Unique object identifier |
| `parent` | string | Parent object name |
| `children` | string | Space-separated list of child object names |
| `width` | integer | Width in pixels |
| `height` | integer | Height in pixels |
| `maxWidth` | integer | Maximum width constraint |
| `maxHeight` | integer | Maximum height constraint |
| `gapH` | integer | Horizontal padding |
| `gapV` | integer | Vertical padding |
| `border` | integer | Border width |
| `FGColor` | string | Foreground color |
| `BGColor` | string | Background color |
| `BDColor` | string | Border color |
| `font` | string | Font name |
| `label` | string | Display label text |
| `content` | string | Content text |
| `script` | code | Viola script code |
| `menuConfig` | config | Menu item configuration |

### Widget Classes

| Class | Description |
|-------|-------------|
| `generic` | Base class for all objects |
| `vpane` | Vertical container (children stacked vertically) |
| `hpane` | Horizontal container (children laid out horizontally) |
| `field` | Drawing canvas |
| `txtDisp` | Text display (read-only) |
| `txtEdit` | Editable text field |
| `txtEditLine` | Single-line text input |
| `txtButton` | Clickable text button |
| `txtLabel` | Static text label |
| `menu` | Dropdown menu |
| `toggle` | Toggle button |
| `radio` | Radio button |
| `slider` | Slider control |
| `socket` | Network socket connection |
| `XBM` | X Bitmap image |
| `XPM` | X Pixmap image |
| `GIF` | GIF image |
| `PS` | PostScript renderer |
| `HTML` | HTML document renderer |
| `glass` | Transparent overlay |
| `project` | Projection/overlay widget |

### Example: Hello World

```
\class {vpane}
\name {hello}
\width {200}
\height {60}
\children {hello.mesg hello.bye}
\BGColor {grey45}
\
\class {txtDisp}
\name {hello.mesg}
\parent {hello}
\content {Hello World!}
\font {normal_large}
\FGColor {black}
\BGColor {lightyellow1}
\
\class {txtButton}
\name {hello.bye}
\parent {hello}
\script {
    switch (arg[0]) {
    case "buttonRelease":
        send(parent(), "visible", 0);
    break;
    }
    usual();
}
\label {Goodbye...}
\FGColor {white}
\BGColor {grey45}
\
```

---

## Viola Scripting Language

The scripting language inside `\script {}` blocks is a C-like interpreted language with message-passing object communication.

### Data Types

| Type | Examples | Description |
|------|----------|-------------|
| Integer | `42`, `-10`, `0` | Whole numbers |
| Float | `3.14`, `0.5`, `-2.0` | Floating-point numbers |
| String | `"Hello"`, `"line\n"` | Character strings |
| Character | `'a'`, `'\n'`, `'\t'` | Single characters |
| Boolean | `true`, `false` | Boolean values (actually integers 1/0) |
| Array | `arr[0]`, `arr[i]` | Dynamic arrays |

### String Escape Sequences

| Sequence | Meaning |
|----------|---------|
| `\n` | Newline |
| `\t` | Horizontal tab |
| `\r` | Carriage return |
| `\v` | Vertical tab |
| `\b` | Backspace |
| `\f` | Form feed |
| `\\` | Backslash |
| `\'` | Single quote |
| `\"` | Double quote |
| `\NNN` | ASCII code (3 digits) |

### Operators

#### Arithmetic
| Operator | Description |
|----------|-------------|
| `+` | Addition |
| `-` | Subtraction |
| `*` | Multiplication |
| `/` | Division |
| `%` | Modulo |

#### Comparison
| Operator | Description |
|----------|-------------|
| `==` | Equal |
| `!=` | Not equal |
| `<` | Less than |
| `>` | Greater than |
| `<=` | Less than or equal |
| `>=` | Greater than or equal |

#### Logical
| Operator | Description |
|----------|-------------|
| `&&` | Logical AND |
| `\|\|` | Logical OR |
| `!` | Logical NOT (**ViolaWWW 4.0**) |

> **Note on `!` operator:** The original code had `!` declared in the lexer keyword table (`violakeywords.h`) and in the parser's precedence declaration (`gram.y`), but no grammar production rule was ever written for it. The `not()` built-in function served as a workaround. The `!` prefix operator was implemented in ViolaWWW 4.0.

#### Assignment
| Operator | Description |
|----------|-------------|
| `=` | Assignment |
| `+=` | Add and assign |
| `-=` | Subtract and assign |
| `*=` | Multiply and assign |
| `/=` | Divide and assign |
| `%=` | Modulo and assign |

#### Increment/Decrement
| Operator | Description |
|----------|-------------|
| `++` | Increment (prefix/postfix) |
| `--` | Decrement (prefix/postfix) |

### Control Structures

#### Switch Statement

The primary control structure for message handling:

```c
switch (arg[0]) {
case "buttonRelease":
    /* handle button release */
    send(parent(), "visible", 0);
break;
case "init":
    usual();
    count = 0;
break;
default:
    /* default handler */
break;
}
```

#### If-Else

```c
if (x > 0) {
    print("positive\n");
} else {
    print("non-positive\n");
}
```

#### While Loop

```c
while (i < 10) {
    print(i, "\n");
    i++;
}
```

#### For Loop

```c
for (i = 0; i < count; i++) {
    process(data[i]);
}
```

#### Do-While Loop (**ViolaWWW 4.0**)

```c
do (init) {
    /* body */
} while (condition);
```

> **Note on `do-while`:** The original grammar (`gram.y`) parsed this construct and built `AST_DO` nodes, but `codeGen()` in `cgen.c` had no handler for `AST_DO` — it fell through to the error case. The do-while loop was implemented in ViolaWWW 4.0.

### Keywords

```
if      else    for     while   do
switch  case    default break   return
get     set     persistent
true    false
```

### Variables

Variables are dynamically typed and don't require declaration:

```c
x = 42;              /* integer */
name = "hello";      /* string */
pi = 3.14159;        /* float */
items[0] = "first";  /* array element */
```

#### Persistent Variables

Variables declared with `persistent` retain their values across script invocations:

```c
persistent count, total;

switch (arg[0]) {
case "init":
    count = 0;
    total = 0;
break;
case "increment":
    count++;
    total += arg[1];
break;
}
```

### Arrays

Arrays are dynamic and can hold mixed types:

```c
/* Setting elements */
data[0] = "first";
data[1] = 42;
data[10] = 3.14;

/* Getting array size */
size = data[];

/* Iterating */
for (i = 0; i < data[]; i++) {
    print(data[i], "\n");
}
```

### Built-in Functions

Viola provides a rich set of built-in functions. Key categories include:

- **Core Functions**: `send()`, `usual()`, `interpret()`, `exit()`, `quit()`
- **Object Functions**: `self()`, `parent()`, `get()`, `set()`, `clone()`
- **String Functions**: `concat()`, `nthChar()`, `nthWord()`, `strlen()`
- **Math Functions**: `sin()`, `cos()`, `random()`, `int()`, `float()`
- **Graphics Functions**: `drawLine()`, `drawRect()`, `clearWindow()`, `mouseX()`, `mouseY()`
- **File Functions**: `loadFile()`, `saveFile()`
- **I/O Functions**: `print()`, `sprintf()`
- **Time Functions**: `after()`, `time()`, `date()`
- **HTTP Functions**: `HTTPGet()`, `HTTPPost()`

For the complete function reference with parameters and examples, see **[VIOLA_FUNCTIONS.md](VIOLA_FUNCTIONS.md)**.

### Event Model

Scripts handle events through the message-passing `switch` pattern:

| Message | Description |
|---------|-------------|
| `"init"` | Object initialization |
| `"config"` | Size/position changed |
| `"expose"` | Widget needs redraw |
| `"buttonPress"` | Mouse button pressed |
| `"buttonRelease"` | Mouse button released |
| `"mouseMove"` | Mouse moved (with `arg[1]`, `arg[2]` for x, y) |
| `"keyPress"` | Key pressed |
| `"enter"` | Mouse entered widget |
| `"leave"` | Mouse left widget |
| `"VIEW_ON"` | Widget became visible |
| `"VIEW_OFF"` | Widget became hidden |

#### Event Arguments

Event handlers receive arguments in the `arg[]` array:

```c
switch (arg[0]) {
case "mouseMove":
    x = arg[1];  /* mouse X coordinate */
    y = arg[2];  /* mouse Y coordinate */
break;
case "keyPress":
    key = arg[1];  /* key code */
break;
}
```

### Complete Example: Drawing Application

```
\class {field}
\name {doodle}
\width {400}
\height {300}
\BGColor {white}
\FGColor {black}
\script {
    switch (arg[0]) {
    case "init":
        usual();
        penDown = 0;
        return;
    break;
    case "buttonPress":
        penDown = 1;
        lastX = arg[1];
        lastY = arg[2];
    break;
    case "buttonRelease":
        penDown = 0;
    break;
    case "mouseMove":
        if (penDown) {
            x = arg[1];
            y = arg[2];
            drawLine(lastX, lastY, x, y);
            lastX = x;
            lastY = y;
        }
    break;
    }
    usual();
}
\
```

### Menu Configuration

The `menuConfig` attribute uses a special syntax:

```
\menuConfig {
. {Menu Item Label}    {script code to execute}
. {Another Item}       {send(self(), "action");}
. {Sub Menu}           {/* nested items */}
}
```

---

## Parser Implementation

The Viola language is implemented using:

- **`gram.y`** — YACC/Bison grammar for the scripting language
- **`scan.l`** — Lex/Flex lexer definition
- **`violalex.c`** — Hand-optimized lexer with trie-based keyword lookup
- **`loader.c`** — Object file (`.v`) parser
- **`cgen.c`** / **`cexec.c`** — Code generation and execution

---

## Historical Context

The Viola language was developed by Pei-Yuan Wei in 1991-1992 as part of the ViolaWWW browser project. It was influenced by:

- **Smalltalk/Self** — Message-passing object model
- **C** — Syntax and operators
- **HyperCard** — Event-driven scripting for GUI objects
- **Tcl/Tk** — Embeddable scripting for UI toolkits

The language predates JavaScript (1995) and Java applets (1995), making it one of the earliest attempts at client-side web scripting.

---

## See Also

- [VIOLA_FUNCTIONS.md](VIOLA_FUNCTIONS.md) — Complete built-in function reference
- [HMML_REFERENCE.md](HMML_REFERENCE.md) — HMML markup language (uses VOBJF for embedded Viola objects)

