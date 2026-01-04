# ViolaWWW Mathematical Notation Reference

> **Added in: ViolaWWW 4.0**  
> The `<math>` tag infrastructure existed in the original ViolaWWW, but the actual rendering of mathematical symbols (`&pi;`, `&sigma;`, `&integral;`, `&infin;`), subscripts, superscripts, and extensible parentheses/brackets was implemented in version 4.0 (2025).

## HTML Tags for Mathematics

### 1. `<math>...</math>` - Mathematical Expression Container
The main container for mathematical formulas.

```html
<math>E = mc<sup>2</sup></math>
```

---

### 2. `<sup>...</sup>` - Superscript (Exponent)
Creates superscript text, typically used for exponents.

```html
<math>x<sup>2</sup></math>          <!-- x² -->
<math>e<sup>i&pi;</sup></math>      <!-- e^(iπ) -->
<math>2<sup>n</sup></math>          <!-- 2^n -->
```

**Features:**
- Automatically scales content to 70% of normal size
- Positions content above baseline
- Supports nested mathematical symbols (`&pi;`, `&infin;`, etc.)
- Multiple elements laid out horizontally

---

### 3. `<sub>...</sub>` - Subscript (Index)
Creates subscript text, typically used for indices.

```html
<math>x<sub>i</sub></math>          <!-- xᵢ -->
<math>a<sub>1</sub></math>          <!-- a₁ -->
<math>log<sub>2</sub>x</math>       <!-- log₂(x) -->
```

**Features:**
- Automatically scales content to 70% of normal size
- Positions content below baseline
- Supports nested mathematical symbols
- Multiple elements laid out horizontally

**Combined sub/sup:**
```html
<math>x<sub>i</sub><sup>2</sup></math>   <!-- xᵢ² -->
```

---

### 4. `<box>...<over>...</box>` - Fractions
Creates vertical fractions with a horizontal division line.

```html
<box>numerator<over>denominator</box>
```

**Examples:**
```html
<math><box>a<over>b</box></math>                    <!-- a/b -->
<math><box>x + y<over>z</box></math>                <!-- (x+y)/z -->
<math><box>1<over>2</box></math>                    <!-- 1/2 -->
<math><box>x<sup>2</sup><over>y</box></math>        <!-- x²/y -->
```

**Multiple fractions:**
```html
<math><box>a<over>b</box> + <box>c<over>d</box></math>   <!-- a/b + c/d -->
```

**Features:**
- `<box>` creates a vertical container (VBOX)
- `<over>` inserts horizontal division line (HDIV)
- Content above `<over>` is the numerator
- Content below `<over>` is the denominator
- Automatically centers content horizontally
- Width adjusts to widest element

---

### 5. Extensible Parentheses `()` and Brackets `[]`
Use literal `()` and `[]` characters within `<math>` tags to create extensible parentheses and brackets that automatically stretch to match the height of their content.

**Examples:**
```html
<!-- Simple parentheses -->
<math>(x + y)</math>

<!-- Parentheses automatically stretch for fractions -->
<math>(<box>a<over>b</box>)</math>

<!-- Nested fractions with large outer parentheses -->
<math>(<box>d1 + d2<over>x1 + (<box>a1 + a2<over>b1 + b2</box>)</box>)</math>

<!-- Square brackets with fractions -->
<math>[<box>a<over>b</box>]</math>

<!-- Integral with brackets -->
<math>&integral;<sup>b</sup><sub>a</sub> [f(x) + g(x)] dx</math>

<!-- Nested structures -->
<math>[x + (y + z)]</math>
```

**Features:**
- Parentheses and brackets are drawn using vector graphics (not font characters)
- Height automatically adjusts to content (tallest child + 2 pixels)
- Width: 5px on each side
- Can contain any mathematical elements (fractions, symbols, text)
- Supports nesting: `(a + (b + c))` or `[(x)]`
- Works at any nesting level (in subscripts, superscripts, fractions, etc.)

**Technical Details:**
- Characters `(`, `)`, `[`, `]` are parsed by Viola scripts and converted to internal tokens
- Uses `MINFO_LPAREN` (15) and `MINFO_RPAREN` (16) for parentheses
- Uses `MINFO_LBRACK` (17) and `MINFO_RBRACK` (18) for square brackets
- Left parenthesis drawn with curved lines (5 segments)
- Right parenthesis drawn symmetrically
- Brackets drawn with vertical line and horizontal strokes
- Each opening bracket/paren creates a container node with its matching closing bracket/paren as a child

**Why extensible?**
- Regular text `()` and `[]` from fonts are fixed size
- Extensible brackets stretch to match tall content like fractions
- Compare: `(<box>a<over>b</box>)` with extensible vs. font-based parentheses

---

## Mathematical Entities (Symbols)

### 6. `&integral;` - Integral Symbol (∫)
The integral symbol, typically used with limits.

```html
<math>&integral; f(x) dx</math>
```

**With limits (using sup/sub):**
```html
<math>&integral;<sup>b</sup><sub>a</sub> f(x) dx</math>    <!-- ∫ₐᵇ f(x)dx -->
```

**Features:**
- Renders as a tall curved symbol
- Height adjusts to match parent container
- Superscript goes to upper right
- Subscript goes to lower right

---

### 7. `&sigma;` - Sigma Symbol (Σ) / Summation
The summation symbol.

```html
<math>&sigma;<sup>n</sup><sub>i=1</sub> i</math>    <!-- Σⁿᵢ₌₁ i -->
```

**Features:**
- Renders as large Greek sigma
- Commonly used with sup/sub for summation limits
- Upper limit in superscript
- Lower limit in subscript

---

### 8. `&infin;` - Infinity Symbol (∞)
The infinity symbol.

```html
<math>lim<sub>n &infin;</sub></math>
<math>&integral;<sup>&infin;</sup><sub>0</sub></math>
```

**Features:**
- Renders as horizontal figure-eight (∞)
- Automatically scales when in superscript/subscript
- Height: 18 pixels (normal), 12.6px (in sup/sub)

---

### 9. `&pi;` - Pi Symbol (π)
The mathematical constant pi.

```html
<math>&pi;</math>                                   <!-- π -->
<math>&pi;r<sup>2</sup></math>                     <!-- πr² -->
<math>e<sup>i&pi;</sup></math>                     <!-- e^(iπ) -->
<math><box>&pi;<over>2</box></math>                <!-- π/2 -->
```

**Features:**
- Renders as Greek letter π
- Automatically scales when in superscript/subscript
- Dimensions: 18×18px (normal), 12.6×12.6px (in sup/sub)

---

## Complex Examples

### Euler's Identity
```html
<math>e<sup>i&pi;</sup> + 1 = 0</math>
```

### Quadratic Formula
```html
<math>x = <box>-b + c<over>2a</box></math>
```

### Definite Integral
```html
<math>&integral;<sup>b</sup><sub>a</sub> f(x) dx</math>
```

### Series Summation
```html
<math>&sigma;<sup>n</sup><sub>i=1</sub> i<sup>2</sup></math>
```

### Taylor Series for e^x
```html
<math>e<sup>x</sup> = &sigma;<sup>&infin;</sup><sub>n=0</sub> <box>x<sup>n</sup><over>n!</box></math>
```

### Riemann Zeta Function
```html
<math>&zeta;(s) = &sigma;<sup>&infin;</sup><sub>n=1</sub> <box>1<over>n<sup>s</sup></box></math>
```

### Area of Circle
```html
<math>A = &pi;r<sup>2</sup></math>
```

### Limit Definition
```html
<math>lim<sub>n &infin;</sub> (1 + <box>1<over>n</box>)<sup>n</sup> = e</math>
```

### Extensible Parentheses with Nested Fractions
```html
<!-- The original author's vision (from htmath.c sample code) -->
<math>v = (<box>d1 + d2<over>x1 + (<box>a1 + a2<over>b1 + b2</box>)</box>) e</math>
```

### Integral with Brackets
```html
<math>&integral;<sup>b</sup><sub>a</sub> [f(x) + g(x)] dx</math>
```

### Summation with Parentheses
```html
<math>&sigma;<sup>n</sup><sub>i=1</sub> (a<sub>i</sub> + b<sub>i</sub>)</math>
```

---

## Implementation Notes

### Internal Token Types
The math engine uses these internal tokens (not directly accessible in HTML):

- `MINFO_BEGIN` (1) - Start marker
- `MINFO_DATA` (2) - Text data
- `MINFO_ENTITY` (3) - Entity placeholder
- `MINFO_HDIV` (4) - Horizontal division line (`<over>`)
- `MINFO_S_BOX` (5) - Start box
- `MINFO_E_BOX` (6) - End box
- `MINFO_HBOX` (7) - Horizontal box (internal)
- `MINFO_VBOX` (8) - Vertical box (internal)
- `MINFO_S_SUB` (9) - Start subscript
- `MINFO_E_SUB` (10) - End subscript
- `MINFO_SUB` (11) - Subscript marker
- `MINFO_S_SUP` (12) - Start superscript
- `MINFO_E_SUP` (13) - End superscript
- `MINFO_SUP` (14) - Superscript marker
- `MINFO_LPAREN` (15) - Left parenthesis (internal)
- `MINFO_RPAREN` (16) - Right parenthesis (internal)
- `MINFO_LBRACK` (17) - Left bracket (internal)
- `MINFO_RBRACK` (18) - Right bracket (internal)
- `MINFO_INTEGRAL` (19) - Integral symbol
- `MINFO_SUM` (20) - Summation symbol
- `MINFO_INFIN` (21) - Infinity symbol
- `MINFO_PI` (22) - Pi symbol

### Limitations

1. **No Nested Superscripts**: `<sup><sup>...</sup></sup>` is not supported due to recursion protection
2. **No Square Roots**: No `<sqrt>` or similar tag implemented
3. **Limited Symbols**: Only `&integral;`, `&sigma;`, `&infin;`, `&pi;` are supported as special math symbols
4. **No Other Brackets**: Braces `{}` and angle brackets `<>` are not supported (only `()` and `[]`)

### Rendering Details

- **Layout Algorithm**: Three-phase process (tile → expandables → center)
- **Coordinate System**: Uses MAST (Math Abstract Syntax Tree) with absolute positioning
- **Font**: Uses system font; no special mathematical font
- **Colors**: Inherits from parent container
- **Borders**: Optional red debug borders (controlled by `drawBoxP` flag)

---

## File Locations

- **Math Engine**: `src/viola/htmath.c`
- **HTML Scripts**:
  - `src/viola/embeds/HTML_math_script.v` - Main math container, handles `()` and `[]` parsing
  - `src/viola/embeds/HTML_box_script.v`
  - `src/viola/embeds/HTML_over_script.v`
  - `src/viola/embeds/HTML_sup_script.v` - Superscripts, handles nested `()` and `[]`
  - `src/viola/embeds/HTML_sub_script.v` - Subscripts, handles nested `()` and `[]`
  - `src/viola/embeds/HTML_above_script.v` - Handles nested `()` and `[]`
  - `src/viola/embeds/HTML_below_script.v` - Handles nested `()` and `[]`
- **Entity Definitions**: `src/libWWW/HTMLDTD.c`, `src/libWWW/HTML.c`

---

*Last updated: November 18, 2025*

