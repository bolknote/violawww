# Color Reference

Complete guide to color specification in ViolaWWW.

---

## Overview

ViolaWWW uses **X11 color names** for all color specifications. Colors are parsed using the X11 `XParseColor()` function, which means **any valid X11 color name** is supported, including the complete X11 color database (over 600 colors).

Both `grey` and `gray` spellings work identically throughout ViolaWWW.

---

## Where Colors Are Used

Colors can be specified in several contexts:

1. **STG Stylesheets** — `FGColor`, `BGColor`, `BDColor` attributes
2. **Viola Object Files** — `\FGColor`, `\BGColor`, `\BDColor` directives
3. **VPLOT Commands** — `fgcolor`, `bgcolor` commands
4. **Graphics Tags** (unimplemented) — `<FGCOLOR>`, `<BGCOLOR>`, `<BDCOLOR>` elements

---

## Basic Colors

The most commonly used color names:

| Color | Description |
|-------|-------------|
| `black` | Pure black |
| `white` | Pure white |
| `red` | Red |
| `green` | Green |
| `blue` | Blue |
| `yellow` | Yellow |
| `cyan` | Cyan |
| `magenta` | Magenta |

---

## Extended Basic Colors

Additional common colors:

| Color | Description |
|-------|-------------|
| `maroon` | Dark red |
| `orange` | Orange |
| `navy` | Dark blue |
| `brown` | Brown |
| `purple` | Purple |

---

## Light and Dark Variants

Many colors have light and dark variants:

### Light Variants
- `lightyellow`
- `lightgray` / `lightgrey`
- `lightcyan`
- `lightblue`
- `lightgreen`
- `lightpink`
- `lightcoral`
- `lightgoldenrod`
- `lightslategray` / `lightslategrey`

### Dark Variants
- `darkblue`
- `darkred`
- `darkgreen`
- `darkgray` / `darkgrey`
- `darkcyan`
- `darkviolet`
- `darkslategray` / `darkslategrey`
- `darkturquoise`

---

## Grey Scale

ViolaWWW supports a complete grey scale using X11 color names from `grey0` (black) to `grey100` (white).

### Format
- `grey0` through `grey100` (or `gray0` through `gray100`)
- You can use **any number from 0 to 100**: `grey0`, `grey1`, `grey2`, ..., `grey99`, `grey100`

### Common Values
- `grey0` = black (0% brightness)
- `grey25` = 25% brightness (dark grey)
- `grey50` = 50% brightness (medium grey)
- `grey75` = 75% brightness (light grey)
- `grey100` = white (100% brightness)

### Commonly Used in Codebase
The following grey values are frequently used in ViolaWWW examples and code:
- `grey24`, `grey30`, `grey40`, `grey45`, `grey55`, `grey60`, `grey70`, `grey75`, `grey80`, `grey95`, `grey97`

**Example:**
```
(BODY BGColor=grey70)
(SECTION FGColor=grey45)
```

---

## Extended X11 Color Names

ViolaWWW supports the complete X11 color database. Here are some popular categories:

### Slate Variants
- `slate`
- `slategray` / `slategrey`
- `slategray1`, `slategray2`, `slategray3`, `slategray4`
- `lightslategray` / `lightslategrey`
- `darkslategray` / `darkslategrey`

### Coral and Pink
- `coral`
- `lightcoral`
- `pink`
- `lightpink`
- `hotpink`
- `deeppink`

### Violet and Purple
- `violet`
- `darkviolet`
- `blueviolet`
- `purple`
- `mediumpurple`
- `darkorchid`

### Cyan and Aqua
- `cyan`
- `lightcyan`
- `darkcyan`
- `aquamarine`
- `turquoise`
- `darkturquoise`

### Gold and Tan
- `gold`
- `goldenrod`
- `lightgoldenrod`
- `tan`
- `wheat`
- `burlywood`

### Forest and Green Variants
- `forestgreen`
- `limegreen`
- `springgreen`
- `seagreen`
- `palegreen`

### Fire Brick and Earth Tones
- `firebrick`
- `indianred`
- `sienna`
- `saddlebrown`
- `peru`

### Numbered Color Variants

Many X11 colors have numbered variants (1-4, where 1 is lightest and 4 is darkest):

- `slategray1`, `slategray2`, `slategray3`, `slategray4`
- `LemonChiffon1`, `LemonChiffon2`, `LemonChiffon3`, `LemonChiffon4`
- `aliceblue`, `antiquewhite1` through `antiquewhite4`
- And many more...

---

## Complete X11 Color Database

ViolaWWW supports **all valid X11 color names** (over 600 colors). The complete list is available in the X11 color database file:

- **Unix/Linux**: `/usr/share/X11/rgb.txt`
- **macOS**: `/opt/X11/share/X11/rgb.txt` (if X11 is installed)
- **Online**: Various X11 color reference websites

To see all available colors on your system, you can run:
```bash
awk '!/^!/{print $4}' /usr/share/X11/rgb.txt | sort -u
```

---

## Usage Examples

### STG Stylesheets

```stg
(BODY
    BGColor=white
    FGColor=black
)

(H1
    FGColor=red
    BDColor=orange
)

(ADDRESS
    BGColor=lightyellow
    FGColor=blue
)

(SECTION
    BGColor=grey70
    FGColor=black
    BDColor=grey70
)
```

### Viola Object Files

```v
\BGColor {grey45}
\FGColor {black}

@vobjf {
    \BGColor {white}
    \FGColor {black}
}
```

### VPLOT Commands

```
fgcolor yellow
bgcolor white
```

### Blink Colors (STG)

For blinking text:

```stg
(BLINK
    blinkColorOn=green
    blinkColorOff=black
)
```

---

## Color Attributes Reference

### `FGColor` / `FGCOLOR` / `\FGColor`
Foreground (text) color.

**Used in:**
- STG stylesheets: `FGColor=red`
- Viola objects: `\FGColor {black}`
- Graphics tags: `<FGCOLOR name="blue">` (unimplemented)

### `BGColor` / `BGCOLOR` / `\BGColor`
Background color.

**Used in:**
- STG stylesheets: `BGColor=white`
- Viola objects: `\BGColor {grey45}`
- Graphics tags: `<BGCOLOR name="lightyellow">` (unimplemented)

### `BDColor` / `BDCOLOR` / `\BDColor`
Border color (used with `border` attribute).

**Used in:**
- STG stylesheets: `BDColor=red`
- Viola objects: `\BDColor {grey70}`
- Graphics tags: `<BDCOLOR name="red">` (unimplemented)

### `blinkColorOn` / `blinkColorOff` (STG only)
Colors for blinking text states.

**Used in:**
- STG stylesheets only

---

## Technical Details

### Color Parsing

ViolaWWW uses the X11 `XParseColor()` function to parse color names. This function:

1. First checks for standard X11 color names (case-insensitive)
2. Falls back to RGB hex format parsing (if supported by your X11 implementation)
3. Returns an error if the color name is not recognized

### Case Sensitivity

Color names are **case-insensitive**. All of these are equivalent:
- `black`, `Black`, `BLACK`
- `lightblue`, `LightBlue`, `LIGHTBLUE`

### Grey vs Gray

Both spellings work identically:
- `grey0` = `gray0`
- `grey50` = `gray50`
- `lightgrey` = `lightgray`
- `darkslategrey` = `darkslategray`

---

## See Also

- [STG_REFERENCE.md](STG_REFERENCE.md) - Stylesheet system and color attributes
- [VIOLA_LANGUAGE.md](VIOLA_LANGUAGE.md) - Viola object file format and color directives
- [VPLOT_REFERENCE.md](VPLOT_REFERENCE.md) - VPLOT color commands
- [GRAPHICS_TAGS_REFERENCE.md](GRAPHICS_TAGS_REFERENCE.md) - Graphics tag color attributes (unimplemented)

