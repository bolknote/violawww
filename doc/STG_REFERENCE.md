# ViolaWWW Stylesheet (STG) Reference

> **Documentation created in: ViolaWWW 4.0**  
> This document describes the original STG stylesheet system from ViolaWWW v3.x (1992-1995). Minor selectors and `traversedForegroundColor` support were restored/enhanced in v4.0.

## Introduction

ViolaWWW uses a hierarchical stylesheet system called **STG** (Stylesheet) that predates CSS and has its own unique syntax and capabilities. STG files have the `.stg` extension and provide context-sensitive styling for HTML documents.

> **Historical Note**: This stylesheet system was designed by **Pei Y. Wei** (pei@ora.com) at O'Reilly & Associates. An early public example of the stylesheet language was posted to WWW-Talk on **October 22, 1993**, noting a prototype implementation in Viola. A longer “Stylesheet RFC” text is dated **Oct 23, 1993** in its own header and was later re-posted to WWW-Talk (Oct 25, 1994). This work predates CSS (first proposed December 1994). It was never adopted as a web standard, but represents one of the earliest attempts at separating presentation from content on the web.

**References**:
- [WWW-Talk (Oct 22, 1993): "Stylesheet Language" sample stylesheet](https://www.wiumlie.no/2006/phd/archive/www.webhistory.org/www.lists/www-talk.1993q4/0264.html) - early public prototype example (notes a prototype implementation in Viola)
- [WWW-Talk (Oct 25, 1994): Re: Cascading HTML style sheets — includes “Stylesheet RFC, Oct 23 1993”](https://www.w3.org/Style/History/www.eit.com/www.lists/www-talk.1994q4/0401.html)
- [Stylesheet RFC archive (wiumlie.no)](https://www.wiumlie.no/2006/phd/archive/www.w3.org/Style/History/www.eit.com/www.lists/www-talk.1994q4/0387.html) - Håkon Wium Lie's CSS history archive
- [Viola Stylesheet Specification (Chapter 14)](https://web.archive.org/web/20000111003334/http://viola.org/book/chp14.html) - Web Archive snapshot from 2000
- Implementation: `src/libStyle/libstg.c`, `src/libStyle/libstg.h`

## Contents

- [Linking Stylesheets](#linking-stylesheets)
- [Quick Start](#quick-start)
- [STG Syntax Overview](#stg-syntax-overview)
- [Major Selectors (Tag-Based)](#major-selectors-tag-based)
- [Minor Selectors (Attribute-Based)](#minor-selectors-attribute-based)
- [Style Attributes Reference](#style-attributes-reference)
- [Complete Examples](#complete-examples)
- [Technical Implementation Details](#technical-implementation-details)
- [Limitations and Notes](#limitations-and-notes)
- [Comparison with CSS](#comparison-with-css)
- [See Also](#see-also)

---

## Linking Stylesheets

### Basic Syntax

Stylesheets are linked using the HTML `<LINK>` tag in the document head or body:

```html
<link rel="style" href="HTML_sodium.stg">
```

> **Note**: In the shipped `HTML_link_script.v`, the `REL` value is matched as `"style"`. Use lowercase `rel="style"`.

### Multiple Stylesheets and Live Switching

**⚠️ CRITICAL CONCEPT**: Unlike CSS, STG stylesheets apply **only from the point of inclusion downward** in the document. Viola processes `<link rel="style">` by freeing the currently loaded stylesheet (`STG_clean()` in `HTML_link_script.v`) and then loading the new file, so only **one** stylesheet is active at any time. This means:

1. **Position matters**: A `<link>` tag only affects HTML elements that appear **after** it in the document
2. **Multiple stylesheets**: You can include many `<link>` tags throughout your document to swap styles mid-stream
3. **No stacking**: Each `<link rel="style">` **replaces** the previous stylesheet rather than layering on top of it

```html
<html>
<head>
  <title>Multiple Stylesheets Demo</title>
  <link rel="style" href="base.stg">
</head>
<body>
  <h1>Title</h1>
  <p>This paragraph uses ONLY base.stg styles</p>
  
  <!-- Second stylesheet replaces the active one from here onward -->
  <link rel="style" href="special.stg">
  
  <p>This paragraph now uses ONLY special.stg</p>
  <p>All subsequent content uses special.stg until another link appears</p>
  
  <!-- Third stylesheet replaces special.stg -->
  <link rel="style" href="extra.stg">
  
  <p>This uses only extra.stg</p>
  
  <address>
    <!-- Fourth stylesheet loads for everything after this point -->
    <link rel="style" href="address.stg">
    <p>This uses only address.stg</p>
  </address>
</body>
</html>
```

**How it works**:
- First `<h1>` and first `<p>`: styled by **base.stg** (loaded in `<head>`)
- Second and third `<p>`: styled by **special.stg** (base was freed just before these paragraphs)
- Fourth `<p>`: styled by **extra.stg**
- `<address>` section: styled by **address.stg** (and everything after the link keeps using it until another stylesheet is loaded)

**Use case**: This allows you to change styles mid-document, useful for:
- Different sections with different visual themes
- Testing multiple style variations in one document
- Progressive style enhancement as the document loads

---

## Quick Start

1. Create a stylesheet file `mystyle.stg`:

```
(BODY
    FGColor=black
    BGColor=white

    (H1
        fontSlant=bold
        FGColor=darkblue
        align=center
    )

    (A
        FGColor=blue
        traversedForegroundColor=purple
    )
)
```

2. Link it in HTML **before** the content you want to affect:

```html
<link rel="style" href="mystyle.stg">
```

> Note: ViolaWWW loads only one STG at a time. A later `<link rel="style">` replaces the previous stylesheet (no stacking).

## STG Syntax Overview

### Basic Structure

STG files use a Lisp-like syntax with parentheses to define hierarchical rules:

```
(TAG_SELECTOR
    attribute=value
    
    (NESTED_TAG_SELECTOR
        attribute=value
    )
)
```

### Tokenization (Delimiters and Strings)

- **Whitespace**: space, tab, newline are treated equally.
- **Delimiters (always split tokens)**: `=`, `,`, `(`, `)`, `{`, `}`.
- **Quoted strings**: use double quotes to include spaces inside a single value, e.g. `mesg="Hi there\n"`.

### Comments

STG does **not** have a comment syntax. The `#` character is **not** treated as a comment delimiter — it will be parsed as part of an identifier or cause parse errors. Use whitespace liberally for readability, and add explanatory notes outside the stylesheet file if needed.

---

## Major Selectors (Tag-Based)

### Single Tag Selector

Select a single HTML tag:

```
(P
    FGColor=black
    BGColor=white
)
```

### Multiple Tag Selector

Select multiple tags with the same styles using comma separation:

```
(H1,H2,H3
    FGColor=red
    fontSlant=bold
)
```

This applies the same styles to `<H1>`, `<H2>`, and `<H3>` tags.

### Nested Selectors (Context Sensitivity)

Nested selectors create context-dependent styles. Child selectors only apply when they appear inside the parent tag:

```
(BODY
    FGColor=black
    BGColor=white
    
    (P
        fontSize=normal
    )
    
    (ADDRESS
        FGColor=blue
        
        (P
            fontSlant=italic
        )
    )
)
```

**How it works**:
- `<P>` tags directly in `<BODY>` get `fontSize=normal`
- `<P>` tags inside `<ADDRESS>` get `fontSlant=italic` and inherit `FGColor=blue` from `ADDRESS`

### Inheritance

Attributes are **inherited** down the tree unless explicitly overridden:

```
(BODY
    FGColor=black
    BGColor=white
    
    (H1
        FGColor=red
        BGColor=yellow
    )
    
    (P)
)
```

**Explanation**:
- All children of `BODY` inherit black text and white background
- `H1` overrides to red text on yellow background  
- `P` inherits black text, white background from `BODY` (the empty `(P)` engages the tag in this context even without additional attributes)

---

## Minor Selectors (Attribute-Based)

### Syntax

**⚠️ IMPORTANT**: Minor selectors work **ONLY** with the HTML `style=""` attribute. Other HTML attributes are not supported by the current implementation.

Minor selectors allow styling based on the value of the `style` attribute in HTML:

```
(TAG
    attribute=value
    
    {STYLE "VALUE"
        attribute=value
    }
)
```

**Technical detail**: The attribute name `STYLE` is hardcoded in the implementation (`libstg.c:562`). You cannot use other attribute names like `{CLASS "value"}` or `{ID "value"}` - only `{STYLE "value"}` is supported.

### Example: Style-Based Variants

```
(P
    BGColor=white
    FGColor=black
    
    {STYLE "WARNING"
        FGColor=red
        BDColor=orange
        border=2
    }
    
    {STYLE "NOTE"
        FGColor=blue
        BDColor=cyan
        border=2
    }
)
```

**HTML Usage**:

```html
<p>Normal paragraph with black text.</p>

<p style="WARNING">Warning paragraph with red text and orange border.</p>

<p style="NOTE">Note paragraph with blue text and cyan border.</p>
```

### How Minor Selectors Work

1. The base tag selector `(P)` applies default styles to all `<P>` tags
2. Minor selectors `{STYLE "WARNING"}` match when the HTML has `style="WARNING"`
3. Styles from the minor selector are **added** to the base styles
4. Minor styles take precedence over inherited styles

### Understanding Minor Selector Syntax

**Internal representation**: When the parser reads `{STYLE "WARNING"}`, it creates a minor selector with a list of **two separate identifiers**:
1. First ID: `STYLE` (the attribute name)
2. Second ID: `WARNING` (the attribute value)

Both identifiers are stored equally in the minor's `IDList`. The matching algorithm (`matchMinor` function) requires **both** identifiers to be present in the list for a match.

**Equivalent syntaxes**:

| Syntax | Notes |
|--------|-------|
| `{STYLE "WARNING"}` | With quotes (recommended) |
| `{STYLE WARNING}` | Without quotes (works if no spaces) |
| `{STYLE,WARNING}` | With explicit comma |

**When quotes are required**:
- Use quotes if the value contains spaces: `{STYLE "MY WARNING"}`
- Without quotes, each word becomes a separate ID: `{STYLE MY WARNING}` creates three IDs (incorrect)

**What won't work**:

| Syntax | Why |
|--------|-----|
| `{CLASS "highlight"}` | ❌ Only STYLE attribute is supported |
| `{ID "main"}` | ❌ Only STYLE attribute is supported |
| `{ROLE "navigation"}` | ❌ Only STYLE attribute is supported |

### Multiple Minor Selectors

You can define multiple minor selectors for the same tag:

```
(DIV
    BGColor=white
    
    {STYLE "HIGHLIGHT"
        BGColor=yellow
    }

    {STYLE "ALERT"
        BGColor=red
        FGColor=white
        border=2
        BDColor=black
    }

    {STYLE "INFO"
        BGColor=lightblue
    }
)
```

---

## Style Attributes Reference

### Color Attributes

#### `FGColor=<color>` - Foreground (Text) Color

Sets the text color.

```
(P FGColor=black)
(H1 FGColor=red)
```

**Supported Colors**: 
- **Basic colors**: `black`, `white`, `red`, `green`, `blue`, `yellow`, `cyan`, `magenta`
- **Extended colors**: `maroon`, `orange`, `navy`, `brown`, `purple`
- **Light variants**: `lightyellow`, `lightgray`, `lightcyan`, `lightblue`, `lightgreen`
- **Dark variants**: `darkblue`, `darkred`, `darkgreen`, `darkgray`
- **Grey scale** (X11 color names): `grey0` through `grey100` (also `gray0` through `gray100`)
  - You can use **any number from 0 to 100**: `grey0`, `grey1`, `grey2`, ..., `grey99`, `grey100`
  - `grey0` = black (0% brightness)
  - `grey25` = 25% brightness (dark grey)
  - `grey50` = 50% brightness (medium grey)
  - `grey75` = 75% brightness (light grey)
  - `grey100` = white (100% brightness)
  - **Commonly used in codebase**: `grey24`, `grey30`, `grey40`, `grey45`, `grey55`, `grey60`, `grey70`, `grey75`, `grey80`, `grey95`, `grey97`
  
> **Note**: ViolaWWW uses X11 color names via `XParseColor()`, so **any valid X11 color** is supported, including the complete X11 color database (over 600 colors). Both `grey` and `gray` spellings work identically.

**Additional X11 Colors** (partial list):
- **Slate variants**: `slate`, `slategray`, `slategray1` through `slategray4`, `lightslategray`, `darkslategray`
- **Coral/Pink**: `coral`, `lightcoral`, `pink`, `lightpink`, `hotpink`, `deeppink`
- **Violet/Purple**: `violet`, `darkviolet`, `blueviolet`, `purple`, `mediumpurple`, `darkorchid`
- **Cyan variants**: `cyan`, `lightcyan`, `darkcyan`, `aquamarine`, `turquoise`, `darkturquoise`
- **Gold/Tan**: `gold`, `goldenrod`, `lightgoldenrod`, `tan`, `wheat`, `burlywood`
- **Forest/Lime**: `forestgreen`, `limegreen`, `springgreen`, `seagreen`, `palegreen`
- **Fire brick/Sienna**: `firebrick`, `indianred`, `sienna`, `saddlebrown`, `peru`
- And hundreds more... (see `/usr/share/X11/rgb.txt` on Unix systems)

#### `BGColor=<color>` - Background Color

Sets the background color.

```
(BODY BGColor=white)
(ADDRESS BGColor=lightyellow)
```

#### `BDColor=<color>` - Border Color

Sets the border color (used with `border` attribute).

```
(SECTION BDColor=red border=1)
```

#### `traversedForegroundColor=<color>` - Visited Link Color

Sets the text color for **visited (traversed) links**. This is the ViolaWWW equivalent of CSS's `:visited` pseudo-class.

```
(A
    FGColor=red
    traversedForegroundColor=blue
)
```

**How it works**:
- `FGColor` sets the color for unvisited links
- `traversedForegroundColor` sets the color for links the user has already clicked
- ViolaWWW checks the browsing history to determine if a link has been visited

**CSS Equivalent**:

```css
a:link    { color: red; }   /* FGColor */
a:visited { color: blue; }  /* traversedForegroundColor */
```

**Historical Note**: The term "traversed" was used in early web browsers (including ViolaWWW, 1992-1994) to describe links that the user had "traversed" or navigated through. This predates the CSS `:visited` terminology.

**Original Source**: This attribute was found in the original ViolaWWW stylesheet from Pei Wei's archives:
- [Viola Styles Directory (Web Archive, 2004)](https://web.archive.org/web/20040427234619/http://www.xcf.berkeley.edu/~wei/viola/styles/)
- [hmml.stg (Web Archive, 2004)](https://web.archive.org/web/20040329164901/http://www.xcf.berkeley.edu/~wei/viola/styles/hmml.stg)

**Viola Function**: You can also programmatically check if a URL has been visited using the `isURLVisited(url)` function in Viola scripts:

```
if (isURLVisited("http://example.com/")) {
    /* URL has been visited */
}
```

### Font Attributes

#### `fontSize=<size>` - Font Size

Sets the font size.

```
(P fontSize=normal)
(H1 fontSize=largest)
```

**Values**:
- `smallest`
- `small`
- `normal` (default)
- `large`
- `largest`

#### `fontWeight=<weight>` - Font Weight (NOT IMPLEMENTED)

> **Warning**: This attribute was planned but **never implemented** in the codebase. The original author used it in some stylesheets (e.g., [HTML_sodium.stg](https://web.archive.org/web/20040308032623id_/http://www.xcf.berkeley.edu/~wei/viola/styles/HTML_sodium.stg)), but the parsing code does not process it.
>
> To achieve bold text, use `fontSlant=bold` instead (see below).

**Planned values** (not functional):
- `normal` (default)
- `bold`

#### `fontSlant=<slant>` - Font Slant

Sets the font style. Despite the name suggesting only italic/slant control, this attribute also controls **bold** text in ViolaWWW's implementation.

```
(I fontSlant=italic)
(EM fontSlant=italic)
(STRONG fontSlant=bold)
(B fontSlant=bold)
```

**Values**:
- `normal` (default)
- `italic` - italic/oblique text
- `bold` - bold text

> **Historical Note**: The original author experimented with both `fontWeight=bold` (in [HTML_sodium.stg](https://web.archive.org/web/20040308032623id_/http://www.xcf.berkeley.edu/~wei/viola/styles/HTML_sodium.stg)) and `fontSlant=bold` (in [HMML_red.stg](https://web.archive.org/web/20040329164857id_/http://www.xcf.berkeley.edu/~wei/viola/styles/HMML_red.stg)). Only `fontSlant` was ultimately implemented, with `bold` added as a non-standard value alongside `italic`.

#### `fontSpacing=<spacing>` - Font Spacing

Sets the font to monospace.

> **Historical note**: Early examples used `fontFamily=fixed` (see the 1993 WWW-Talk post above), but ViolaWWW's implementation uses `fontSpacing=mono`. The `fontFamily` attribute is not used by the current code.

```
(CODE fontSpacing=mono)
(KBD fontSpacing=mono)
(PRE fontSpacing=mono)
```

**Values**:
- `proportional` (default)
- `mono` (monospace)

### Layout Attributes

#### `align=<alignment>` - Text Alignment

Sets horizontal text alignment.

```
(H1 align=center)
(P align=left)
(H2 align=right)
```

**Values**:
- `left` (default)
- `center`
- `right`

#### `border=<width>` - Border Width

Sets the border width in pixels (requires `BDColor`).

```
(SECTION border=1 BDColor=black)
(DIV border=2 BDColor=red)
```

**Values**: Integer pixel values (e.g., `1`, `2`, `3`)

### Special Effects

#### `blink=<milliseconds>` - Text Blinking

Makes text blink at specified interval.

```
(P
    blink=1000
    blinkColorOn=green
    blinkColorOff=black
)
```

#### `blinkColorOn=<color>` - Blink "On" Color

Color when blink is in "on" state.

#### `blinkColorOff=<color>` - Blink "Off" Color

Color when blink is in "off" state.

**Example**:

```
(ADDRESS
    (P
        fontSlant=italic
        blinkColorOn=green
        blinkColorOff=black
        blink=1000
    )
)
```

### Unimplemented Attributes

The following attributes appear in original ViolaWWW stylesheets (e.g., [test1.stg](https://web.archive.org/web/20040329164633id_/http://www.xcf.berkeley.edu/~wei/viola/styles/test1.stg), [test3.stg](https://web.archive.org/web/20040329164722id_/http://www.xcf.berkeley.edu/~wei/viola/styles/test3.stg)) but are **parsed without effect** — the rendering code never queries them.

#### `compact` - Compact Mode (NOT IMPLEMENTED)

A boolean flag attribute (used without a value). Likely intended to reduce spacing in lists or other elements.

```
(HEAD,BODY
    compact
    BGColor=white
)
```

**Status**: Parsed by `libstg.c` as a flag attribute with `NULL` value, but never queried via `STG_attr()`.

#### `space` - Spacing Control (NOT IMPLEMENTED)

A boolean flag attribute. Purpose unknown — possibly related to whitespace handling or element spacing.

```
(HEAD,BODY
    space
    BGColor=white
)
```

**Status**: Parsed by `libstg.c` as a flag attribute with `NULL` value, but never queried via `STG_attr()`.

> **Note**: The parser comment in `libstg.c:210` also mentions `spacing` in a minor selector context: `{compact spacing}`. This suggests the author experimented with these as both flag attributes and minor selector identifiers.

#### `numStyle=<style>` - List Numbering Style (NOT IMPLEMENTED)

Intended to control list item numbering format. Defined in the [original Stylesheet RFC](https://www.w3.org/Style/History/www.eit.com/www.lists/www-talk.1994q4/0401.html):

```
(OL
    (LI numStyle=roman
        (LI numStyle=number
            (LI numStyle=alpha)
        )
    )
)
```

**Planned values**:
- `roman` - Roman numerals (I, II, III, IV...)
- `number` - Arabic numerals (1, 2, 3...)
- `alpha` - Alphabetic (a, b, c...)

**Status**: The parser may accept this attribute, but the list rendering code (`HTML_listNumbered_script.v`, `HTML_listSep_script.v`) only supports Arabic numerals via a simple integer counter (`itemN`). No conversion to roman numerals or alphabetic characters is implemented.

#### Other Planned Features (from `libstg.c` comments)

The example syntax in `libstg.c:207-215` reveals additional planned features that were never implemented:

```
(HEAD,BODY                  fontSize=18
                            mesg="Hi there\n"
    {compact                spacing}
                            foregroundColor=black
    (H1                     fontSize=28)
                            backgroundColor=white
)
```

**Observations**:

1. **Numeric font sizes** (`fontSize=18`, `fontSize=28`): The parser may accept these, but only keyword values (`normal`, `small`, `large`, `largest`) are processed by rendering code.

2. **Long attribute names** (`foregroundColor`, `backgroundColor`): Only short names (`FGColor`, `BGColor`, `BDColor`) are implemented and queried.

3. **Arbitrary string attributes** (`mesg="Hi there\n"`): Shows support for escape sequences in quoted strings. The `mesg` attribute is not used.

4. **Minor selector with multiple IDs** (`{compact spacing}`): The minor contains both `compact` and `spacing` as identifiers, suggesting planned support for compound minor selectors.

The TODO list in `libstg.c:5-10` also mentions:
- Caching mechanism in `$LIBSTG_CACHE`
- Input from file descriptors
- Cached lookups
- Support for `ROLE` attribute in minors (e.g., `<EM role="WARNING">`)

---

## Complete Examples

### Example 1: Basic Document Styles

**File**: `base.stg`

```
(BODY
    FGColor=black
    BGColor=white
    fontSize=normal
    
    (H1
        fontSize=largest
        fontSlant=bold
        FGColor=darkblue
        align=center
    )
    
    (H2
        fontSize=large
        fontSlant=bold
        FGColor=darkred
    )
    
    (P
        fontSize=normal
    )
    
    (A
        FGColor=blue
        traversedForegroundColor=purple
    )
    
    (CODE
        fontSpacing=mono
        FGColor=darkgreen
        BGColor=lightgray
    )
)
```

**Note**: In this example, unvisited links appear blue, and visited links appear purple (similar to classic web browser defaults).

### Example 2: Context-Sensitive Styles

**File**: `HTML_sodium.stg`

```
(BODY,HPANE,INPUT,P
    FGColor=black
    BGColor=grey70
    BDColor=grey70
    align=left

    (SECTION
        border=1
        BDColor=red
    )

    (H1
        FGColor=white
        BGColor=red
        BDColor=black
        align=center
    )

    (H2,H3
        FGColor=white
        BGColor=maroon
        BDColor=maroon
        align=right
    )

    (A FGColor=red)
    (BOLD,EMPH,STRONG fontSlant=bold)
    (CMD,KBD,SCREEN,LISTING,EXAMPLE fontSpacing=mono)
    (I fontSlant=italic)

    (ADDRESS
        align=left
        FGColor=white
        BGColor=blue
        BDColor=blue
        
        (P)
    )
)
```

**Explanation**:
- Base styles apply to `BODY`, `HPANE`, `INPUT`, and `P` tags
- `SECTION` tags get a red border
- `H1` gets centered white text on red background
- `H2` and `H3` get white text on maroon background, right-aligned
- Links (`A`) are red
- Bold tags get bold weight
- Monospace tags get mono spacing
- Italic tags get italic slant
- `ADDRESS` gets blue background
- `P` inside `ADDRESS` inherits all `ADDRESS` styles

### Example 3: Nested Context

**File**: `HTML_address1.stg`

```
(P
    FGColor=black
    BGColor=grey70
    BDColor=grey70
    align=left

    (ADDRESS
        align=left
        FGColor=black
        BGColor=grey70
        BDColor=grey70
        
        (P
            fontSlant=italic
            blinkColorOn=green
            blinkColorOff=black
            blink=1000
        )
    )
)
```

**Result**:
- Normal `<P>` tags: black text, grey background
- `<P>` inside `<ADDRESS>`: italic, blinking green/black

### Example 4: Attribute-Based Styling (Minors)

**File**: `test_minors.stg`

```
(P
    BGColor=white
    FGColor=black
    
    {STYLE "WARNING"
        FGColor=red
        BDColor=orange
        border=2
    }
    
    {STYLE "NOTE"
        FGColor=blue
        BDColor=cyan
        border=2
    }
)
```

**HTML**:

```html
<p>Normal paragraph.</p>

<p style="WARNING">
    This is a warning with red text and orange border.
</p>

<p style="NOTE">
    This is a note with blue text and cyan border.
</p>
```

### Example 5: Multiple Stylesheets in One Document

This example demonstrates the "cascading downward" behavior from the [original Viola specification](https://web.archive.org/web/20000111003334/http://viola.org/book/chp14.html).

**HTML File**: `test_multiple.html`

```html
<html>
<head>
    <title>Multiple Stylesheets Test</title>
</head>
<body>
    <link rel="style" href="HTML_sodium.stg">
    
    <h1>Simple Stylesheets Test</h1>
    
    <p>This document demonstrates three different stylesheets applied 
       at different points. Note that the H1 above is center-aligned 
       as specified by the first stylesheet.</p>
    
    <h2>Context Sensitivity</h2>
    
    <p>The following three ADDRESS sections are each under influence 
       of three different stylesheets.</p>
    
    <!-- First ADDRESS uses only HTML_sodium.stg -->
    <address>
        <p>wei@ora.com</p>
        <p>Digital Media Group, O'Reilly & Associates</p>
    </address>
    
    <link rel="style" href="HTML_address1.stg">
    <p>Second stylesheet in effect starting from here. 
       The ADDRESS paragraphs below will be blinking.</p>
    
    <!-- Second ADDRESS uses ONLY HTML_address1.stg (replaced HTML_sodium.stg) -->
    <address>
        <p>wei@ora.com</p>
        <p>Digital Media Group, O'Reilly & Associates</p>
    </address>
    
    <link rel="style" href="HTML_address2.stg">
    <p>Third stylesheet in effect starting from here.</p>
    
    <!-- Third ADDRESS uses ONLY HTML_address2.stg (replaced HTML_address1.stg) -->
    <address>
        <p>wei@ora.com</p>
        <p>Digital Media Group, O'Reilly & Associates</p>
    </address>
</body>
</html>
```

**First Stylesheet**: `HTML_sodium.stg`

```
(BODY,HPANE,INPUT,P
    FGColor=black
    BGColor=grey70
    BDColor=grey70
    align=left

    (H1
        FGColor=white
        BGColor=red
        BDColor=black
        align=center
    )

    (H2
        FGColor=white
        BGColor=maroon
        align=right
    )

    (ADDRESS
        align=left
        FGColor=white
        BGColor=blue
        BDColor=blue
        
        (P)
    )
)
```

**Second Stylesheet**: `HTML_address1.stg`

```
(P
    FGColor=black
    BGColor=grey70
    
    (ADDRESS
        align=left
        FGColor=black
        BGColor=grey70
        
        (P
            fontSlant=italic
            blinkColorOn=green
            blinkColorOff=black
            blink=1000
        )
    )
)
```

**Third Stylesheet**: `HTML_address2.stg`

```
(P
    FGColor=black
    BGColor=grey70
    
    (ADDRESS
        align=right
        
        (P
            fontSlant=italic
        )
    )
)
```

**Result**:
1. **First `<address>`**: White text on blue background (from `HTML_sodium.stg`)
2. **Second `<address>`**: Black italic text on grey background, blinking green/black (from `HTML_address1.stg`, which replaced the previous stylesheet before this block)
3. **Third `<address>`**: Black italic text, right-aligned (from `HTML_address2.stg`, which replaced the second stylesheet)

**Key Points**:
- Each `<link>` tag affects only content that appears **after** it
- Later stylesheets **replace** earlier ones instead of merging with them
- Switching styles mid-document still lets you give different sections distinct looks, but only one stylesheet is active at a time

---

## Technical Implementation Details

### Parser Structure

The STG parser (`libstg.c`) uses a hierarchical data structure:

- **STGLib**: Library containing all stylesheet groups
- **STGGroup**: A stylesheet file's parsed representation
- **STGMajor**: A major selector (tag-based) with:
  - Tag ID list (e.g., `P`, `H1`, `BODY`)
  - Attribute assertions (style properties)
  - Child major selectors (nested context)
  - Child minor selectors (attribute-based)
- **STGMinor**: A minor selector (attribute-based) with:
  - Attribute name/value pairs (e.g., `STYLE="WARNING"`)
  - Style property assertions
- **STGAssert**: A style property (e.g., `FGColor=red`)

### Context Matching Algorithm

When rendering an HTML element, the browser:

1. **Builds context array**: Creates an array of `[tag, attr]` pairs starting with the **current** element and walking up the ancestor chain. `context[0]` is the current tag ID, `context[1]` is the current element’s `style` value ID (or `NULL`), `context[2]`/`context[3]` represent the parent, and so on.
   - Example: for `<P style="WARNING">` inside `<ADDRESS>` inside `<BODY>`, the context array is `[P, WARNING, ADDRESS, NULL, BODY, NULL]` and `contextCount` is `3` (one entry per tag level).

2. **Searches for matching majors**: Finds all major selectors matching the current tag

3. **Filters by context**: Eliminates majors that don't match the parent hierarchy

4. **Validates context depth**: Rejects styles if the HTML context is shallower than the stylesheet nesting
   - **Important limitation**: If stylesheet has `(BODY (ADDRESS (P)))` but HTML only has `<P>` without parents, the style **won't apply**
   - Exception: First-level nesting is allowed (e.g., `(BODY (H1))` can match top-level `<H1>`)
   - This prevents deeply nested stylesheet rules from accidentally matching shallow HTML elements

5. **Checks for minor match**: If element has attributes (like `style="WARNING"`), searches for matching minor selector
   - The minor must have **both** `STYLE` and the attribute value in its IDList
   - Minor matching is performed by `matchMinor()` function (`libstg.c:487-533`)

6. **Applies styles**: Merges styles from:
   - Inherited styles from parent majors
   - Matching major selector
   - Matching minor selector (highest priority)
   
   Priority order (lowest to highest):
   - Parent inheritance → Major selector → Minor selector

### Style Priority

From lowest to highest priority:

1. **Inherited styles** from parent tags
2. **Major selector** styles (tag-based)
3. **Minor selector** styles (attribute-based)

Later styles override earlier ones.

### Memory Management

- Tag names and attribute names are converted to integer IDs for fast comparison
- Style strings are saved using `saveString()` for efficient memory usage
- Tree structures are freed recursively when stylesheet is unloaded

**Key memory functions**:
- `freeGroup(STGLib* lib, STGGroup** group)` - Free a single stylesheet group
- `freeLib(STGLib* lib)` - Free entire library and all groups (prevents memory leaks)
- Internal recursive freeing: `free_major_tree()`, `free_minor_list()`, `free_assert_list()`, `free_str_list()`

### API Functions

**Initialization**:
```c
STGLib* STG_init(
    int (*tagNameCmp_f)(),           // Tag name comparison function
    long (*tagName2ID_f)(),          // Convert tag name to ID
    char* (*tagID2Name_f)(),         // Convert tag ID to name
    int (*tagAttrNameCmp_f)(),       // Attribute name comparison
    long (*tagAttrName2ID_f)(),      // Convert attribute name to ID
    char* (*tagAttrID2Name_f)()      // Convert attribute ID to name
);
```

**Parsing**:
```c
STGGroup* STG_makeGroup(STGLib* lib, char* gspec);  // Parse stylesheet string
```

**Querying**:
```c
// Find matching style for element context
int STG_findStyle(
    STGGroup* group,
    char* context[],      // Array of [tag, attr, tag, attr, ...]
    int contextCount,     // Number of context levels
    STGResult results[],  // Output: array of major/minor pairs
    int maxResults        // Maximum results to return
);

// Find attribute in major/minor hierarchy
STGAssert* STGFindAssertWithMinor(STGMajor* major, STGMinor* minor, char* attrName);
STGAssert* STGFindAssert(STGMajor* major, char* attrName);  // Legacy, no minor support
```

**Debugging**:
```c
void STG_dumpLib(STGLib* lib);          // Print entire library
void STG_dumpGroup(STGGroup* group);    // Print stylesheet group
void STG_dumpMajor(STGMajor* major, int level);    // Print major selector tree
void STG_dumpMinor(STGMinor* minor, int level);    // Print minor selector
void STG_dumpAssert(STGAssert* assert, int level); // Print style assertion
```

**Tracing**: Set `WWW_TraceFlag = 1` to enable detailed parser trace output to stdout.

---

## Limitations and Notes

### Current Limitations

1. **Attribute selectors**: **ONLY** the `STYLE` attribute is supported for minor selectors
   - Hardcoded in `libstg.c:562`: `stg_tagName2ID("STYLE")`
   - No support for `CLASS`, `ID`, `ROLE`, or any other HTML attributes
   - **Note**: The original author intended to support `ROLE` attribute (see TODO comment in `libstg.c:9-10`: "Deal with minors, ie: distinction between `<EM role="WARNING">` and `<EM role="NOTE">`") but this was never implemented
   
2. **Context depth validation**: Stylesheet nesting must match or be shallower than HTML structure
   - Style `(BODY (ADDRESS (P)))` won't match standalone `<P>` tag
   - Exception: First-level nesting (`(BODY (H1))`) can match top-level tags
   - This prevents unintended style application but may surprise users
   
3. **Selector specificity**: No complex selectors like CSS (e.g., no `>`, `+`, `~` combinators)

4. **Pseudo-classes**: No `:hover`, `:active` support
   - **Note**: Visited link styling IS supported via `traversedForegroundColor` attribute (see below)

5. **Dynamic updates**: Stylesheets are loaded at document parse time, not dynamically

6. **Document-order replacement**: Order of `<link rel="style">` tags matters because each one replaces the active STG for the remainder of the document

7. **Parser token buffer limit (unsafe)**: the parser uses fixed 1000-byte buffers (`ParseContext` in `libstg.c`) and does **not** bounds-check writes.
   - Very long identifiers or quoted strings can overflow the internal buffer (undefined behavior).
   - There is no structured error reporting for this.

8. **Unimplemented attributes**: Some attributes from the original RFC are parsed but ignored
   - `fontWeight` - use `fontSlant=bold` instead
   - `numStyle` - list numbering (roman/number/alpha), only Arabic numerals supported
   - `compact` - flag attribute, never queried
   - `space` - flag attribute, never queried
   - See "Unimplemented Attributes" section for details

### Best Practices

1. **Use hierarchical nesting**: Leverage context-sensitive styles for maintainability
2. **Group similar tags**: Use comma separation for tags with identical styles
3. **Inherit wisely**: Set common properties at parent level to reduce repetition
4. **Test context**: Verify that nested selectors match intended HTML structure
5. **Minimize minor selectors**: Use minor selectors sparingly as they add complexity

### Known Issues

1. **Tag and attribute matching is case-sensitive in ViolaWWW**
   - In the ViolaWWW integration (`src/viola/stgcall.c`), tag names are interned exactly as seen; no case-folding is performed.
   - Practical rule: write selectors in the same case as the HTML parser provides (typically uppercase: `BODY`, `P`, `H1`).
   
2. **No error reporting**: Invalid syntax may be silently ignored
   - Parser prints errors to stdout with `printf()` but continues parsing
   - Example: `"libstg: major: error-- no left side to '='."`
   - No structured error handling or recovery mechanism
   
3. **Whitespace handling**: Spaces, tabs, and newlines are treated equally
   - Whitespace is skipped by `is_space()` helper (`libstg.c:23-25`)
   - Whitespace around `=` signs is automatically handled
   
4. **Quote handling**: String values should be quoted if they contain spaces or special characters
   - Without quotes, each space-separated word becomes a separate token
   - Special characters `=`,`,`,`(`,`)`,`{`,`}` always act as delimiters
   
5. **Memory management**: Tag and attribute names are converted to integer IDs and stored as `(char*)(long)` casts
   - This assumes pointer size equals long size (works on most modern systems)
   - Values are saved via `saveString()` which must be implemented by the caller
   
6. **Minor selector limitations**: Nested minors are not supported
   - If the parser encounters a `{` while already inside a minor block it simply bails out of the block, often without a helpful error message, so the rest of the minor definition is ignored
   - Only one level of attribute-based styling is supported

---

## Example HTML Document with Stylesheet

**HTML File**: `test.html`

```html
<html>
<head>
    <title>STG Test</title>
    <link rel="style" href="mystyle.stg">
</head>
<body>
    <h1>Welcome to ViolaWWW</h1>
    
    <p>This is a normal paragraph.</p>
    
    <p style="WARNING">
        <strong>Warning:</strong> This is important!
    </p>
    
    <address>
        <p>Contact: wei@ora.com</p>
    </address>
    
    <section>
        <h2>Section Title</h2>
        <p>Section content here.</p>
    </section>
</body>
</html>
```

**Stylesheet**: `mystyle.stg`

```
(BODY
    FGColor=black
    BGColor=white
    fontSize=normal
    
    (H1
        fontSize=largest
        fontSlant=bold
        FGColor=white
        BGColor=navy
        align=center
    )
    
    (H2
        fontSize=large
        fontSlant=bold
        FGColor=maroon
    )
    
    (P
        fontSize=normal
        
        {STYLE "WARNING"
            FGColor=red
            BDColor=orange
            border=2
            fontSlant=bold
        }
    )
    
    (ADDRESS
        FGColor=darkblue
        fontSlant=italic
        BGColor=lightyellow
    )
    
    (SECTION
        border=1
        BDColor=grey70
    )
    
    (STRONG
        fontSlant=bold
    )
)
```

---

## Comparison with CSS

| Feature | STG | CSS |
|---------|-----|-----|
| **Syntax** | Lisp-like parentheses | Curly braces |
| **Nesting** | Native hierarchical | Requires preprocessors (Sass/Less) |
| **Context sensitivity** | Built-in | Via descendant selectors |
| **Attribute selectors** | Limited (`{STYLE "value"}`) | Full support (`[attr="value"]`) |
| **Inheritance** | Automatic down tree | Via `inherit` keyword |
| **Specificity** | Context depth-based | Complex specificity rules |
| **Cascading** | Document order (top-down) | Multiple cascade layers |
| **Dynamic** | Static at load | Can be dynamic (JavaScript) |

---

## See Also

### Primary Sources
- [WWW-Talk (Oct 22, 1993): "Stylesheet Language" sample stylesheet](https://www.wiumlie.no/2006/phd/archive/www.webhistory.org/www.lists/www-talk.1993q4/0264.html)
- [WWW-Talk (Oct 25, 1994): Re: Cascading HTML style sheets — includes “Stylesheet RFC, Oct 23 1993”](https://www.w3.org/Style/History/www.eit.com/www.lists/www-talk.1994q4/0401.html)
- [Stylesheet RFC archive (wiumlie.no)](https://www.wiumlie.no/2006/phd/archive/www.w3.org/Style/History/www.eit.com/www.lists/www-talk.1994q4/0387.html) - Håkon Wium Lie's CSS history archive
- [Web Archive: Viola Stylesheet Specification](https://web.archive.org/web/20000111003334/http://viola.org/book/chp14.html) - Chapter 14 of Viola documentation
- [Web Archive: Viola Styles Directory](https://web.archive.org/web/20040427234619id_/http://www.xcf.berkeley.edu/~wei/viola/styles/) - Original `.stg` files from Pei Wei

### Related Documentation
- `HMML_REFERENCE.md` - HMML markup language reference
- `MATH_REFERENCE.md` - Mathematical notation in ViolaWWW
- `README.md` - Project overview

---

*Last updated: January 15, 2026*

