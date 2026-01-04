# Personal URL Catalog

> **Added in: ViolaWWW 4.0**  
> The Catalog feature existed as incomplete stubs in the original code. The full implementation was completed in 2024/2025.

The Personal URL Catalog is a hierarchical bookmark organizer for ViolaWWW, allowing users to save, organize, and access their favorite web pages.

## Opening the Catalog

- **Menu:** Navigation → Catalog
- **Add current page:** Navigation → Add to Catalog

## Features

### Organizing Links

- **Folders**: Create folders to organize links by topic
- **Links**: Save URLs with custom names and comments
- **Hierarchy**: Nest folders within folders for complex organization

### Navigation

- **Double-click** a folder to open it
- **Double-click** a link to open it in the browser
- **Go Up** (Backspace): Return to parent folder
- **Folder:** label shows current location

### Selection

- **Click** an item to select it
- **Shift+Click**: Add to selection
- **Drag** on empty space: Rubber-band selection of multiple items

### File Menu

| Command | Shortcut | Description |
|---------|----------|-------------|
| Open Selected | Ctrl+O | Open selected folder or link |
| Add Current Page | — | Add the browser's current page as a link |
| New Folder | Ctrl+N | Create a new folder |
| New Link | Ctrl+L | Create a new link manually |
| Delete | Delete | Remove selected items |
| Go Up | Backspace | Navigate to parent folder |
| Save | Ctrl+S | Save the catalog |
| Close | Ctrl+W | Close the catalog window |

### Edit Menu

| Command | Shortcut | Description |
|---------|----------|-------------|
| Select All | Ctrl+A | Select all items in current folder |
| Edit Label | Ctrl+E | Edit the label of the selected item (single selection only) |

### Organize Menu

| Command | Description |
|---------|-------------|
| Clean Up Window | Arrange icons in a neat grid (preserves order) |
| Alphabetize | Sort items alphabetically and arrange in grid |

## Storage

The catalog is saved to `~/.viola-catalog` in a hierarchical text format.

### File Format

```
FOLDER	Root
LINK	Example Site	http://example.com/	A sample website
FOLDER	News
LINK	Tech News	http://technews.example.com/	Technology news
END
LINK	Another Link	http://another.example.com/	
END
```

- `FOLDER <name>` — begins a folder
- `LINK <name> <TAB> <url> <TAB> <comment>` — defines a link
- `END` — closes the current folder

---

## Implementation Notes

### Original Code (from Pei-Yuan Wei's ViolaWWW)

The following elements were present in the original 1994 codebase:

1. **Data Structures**: `Item`, `Folder`, `Link`, `Catalog` structs in `catalog.h` (with `Pixmap icon` and `iconFile` fields)
2. **Menu Structure**: Commented-out `testMenuItems[]` with "Catalog" entry
3. **Basic Window Layout**: Shell, canvas, and menu bar setup code

### Reconstructed/Added (2024 restoration)

The following features were implemented based on the original design intent:

1. **Full Functionality**
   - Item creation, deletion, and renaming
   - Folder navigation (enter/go up)
   - Selection handling (single, multiple, rubber-band)
   - Drag-and-drop repositioning

2. **File I/O**
   - Hierarchical text format for `~/.viola-catalog`
   - Automatic save on close
   - Load on startup

3. **Layout Intelligence**
   - Dynamic cell width based on text length
   - Automatic column calculation based on window width
   - Centered icons and text within cells
   - Adaptive selection highlight box

4. **Visual Enhancements**
   - Folder icon: borrowed from `HTML__foldIcon` (used for `<UL FOLD=yes>` collapsible lists), scaled 2× to 32×32
   - Link icon: redrawn based on `link.xpm`, scaled 2× to 30×32
   - True transparency support via XPM masks
   - Item count displayed inside folder icons
   - Default application background color

5. **User Interface**
   - Catalog added to **Navigation menu** (original had commented-out "Test" menu)
   - "Add to Catalog" in Navigation menu
   - Edit Label dialog for renaming items
   - About Catalog dialog
   - Non-resizable window (per original design)
   - Proper window close handling (doesn't quit browser)

6. **Keyboard Shortcuts**
   - Standard shortcuts for common operations
   - Backspace for "Go Up"
   - Delete key for item deletion

---

## Design Philosophy

This restoration aimed to honor Pei-Yuan Wei's original vision while making the feature fully functional. Where the original code provided only stubs or comments, we implemented features consistent with:

- The conventions of early 1990s GUI applications
- Patterns established elsewhere in ViolaWWW
- Standard Motif/X11 interface guidelines

The folder icon was borrowed from the browser's `HTML__foldIcon` object (used for collapsible lists with `<UL FOLD=yes>`), maintaining visual consistency with the rest of the application.

