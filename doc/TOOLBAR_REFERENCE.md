# Dynamic Toolbar Reference

> **Documentation created in: ViolaWWW 4.0**  
> This document describes the **dynamic toolbar** feature in ViolaWWW: document-engaged tool applets added via HTML `<LINK REL="tool">` and implemented as Viola `.v` objects. It is based on the original ViolaWWW implementation, the Viola book, and archived examples.

This document describes the **dynamic toolbar** feature in ViolaWWW — the ability to have document-specific toolbar objects engaged while a document is being viewed, using the HTML `<LINK>` tag.

## Contents

- [Overview](#overview)
- [How It Works](#how-it-works)
- [HTML Syntax](#html-syntax)
- [Creating Toolbar Objects](#creating-toolbar-objects)
- [Implementation Details](#implementation-details)
- [Historical Context](#historical-context)
- [Related Features](#related-features)
- [References](#references)

<img width="636" height="849" alt="" src="https://github.com/user-attachments/assets/fa9e88e4-6503-4d5b-abac-e46b856f4471" />

---

## Overview

ViolaWWW includes **document-engaged tool applets** — toolbar objects that can be engaged per-document (appear while a document is being viewed, and be removed when navigating away). This allows documents to provide their own navigational aids or custom functionality directly in the browser toolbar.

As described in the Viola book ([Chapter 9](https://web.archive.org/web/20040302222006id_/http://www.xcf.berkeley.edu/~wei/viola/book/chp9.html)):

> "Dynamic toolbar: document engaged tool applets (ie: navigational aids)."
>
> "The scripting language system allows browser functionality to be extended dynamically. Can dynamically plug-in new tools into the browser toolbar. For example: navigational icons which do not scroll around (possibly out of view) with the document page, or self guiding slideshow presentation tool, etc."

The same chapter also describes the per-document nature of these tools:

> "... the right most three text buttons on the "toolbar" are little applets which are linked to the document."

---

## How It Works

1. An HTML document includes a `<LINK>` tag with `REL="tool"` in its `<HEAD>` section.
2. During parsing, `src/viola/embeds/HTML_link_script.v` handles `REL="tool"`:
   - Downloads the referenced `.v` via `HTTPGet(href)`
   - Loads it via `loadObjFile(...)`
   - Calls `send(objName, "init")` to initialize it
3. The current document object records the tool name via its `addTool` handler.
4. When the document is **displayed**, it adds the recorded tools to the toolbar container (by sending `addTool` to its parent, which routes to the toolbar manager).
5. When navigating away, the document receives `VIEW_OFF` and removes the tools from the toolbar container.

From the Viola book ([Chapter 1](https://web.archive.org/web/20040302222006id_/http://www.xcf.berkeley.edu/~wei/viola/book/chp1.html)):

> "The following picture shows a 'bookmark tool' that acts as a mini table of contents for the page. In this case, the bookmark is linked to the document (by using the `<LINK>` tag from HTML 3.0), and the bookmark will appear and disappear with the document."

The Viola book is archived on the Wayback Machine ([directory listing snapshot](https://web.archive.org/web/20040302222006id_/http://www.xcf.berkeley.edu/~wei/viola/book/)).

---

## HTML Syntax

### Basic Tool Button

```html
<HEAD>
<LINK REL="tool" HREF="myToolButton.v">
</HEAD>
```

The Viola book calls out toolbar objects via `LINK REL="tool"` in its LINK tag reference ([Chapter 11 links](https://web.archive.org/web/20040302222006id_/http://www.xcf.berkeley.edu/~wei/viola/book/chp11_links.html)):

```html
<LINK REL="tool" HREF="tool_violaTOC.v">
```

The book archive also includes a concrete example toolbar tool object file: [`tool_violaTOC.v`](https://web.archive.org/web/20040302222006id_/http://www.xcf.berkeley.edu/~wei/viola/book/tool_violaTOC.v).

### Multiple Tools

```html
<HEAD>
<LINK REL="tool" HREF="violaCentral.v">
<LINK REL="tool" HREF="whatsNew.v">
<LINK REL="tool" HREF="slideshow.v">
</HEAD>
```

### With Additional Arguments

The `ARG` attribute is parsed by the embedded HTML link handler (`HTML_link_script.v`). In this repository's current embedded scripts:

- `REL="sidebar"` **uses** the first `ARG` value as `barRatio`.
- `REL="tool"` collects `ARG` values and forwards them to `addTool`, but the current `addTool` handlers shown below **ignore** those extra arguments. So you should not rely on `ARG` to parameterize a toolbar tool unless you extend the `addTool` handling yourself.

```html
<LINK REL="tool" HREF="navigator.v" ARG="compact">
```

---

## Creating Toolbar Objects

A toolbar object is a standard Viola object file (`.v`) that typically defines a button widget. Here's an example:

```
\class {txtButton}
\name {violaCentral}
\label {Viola Central}
\width {100}
\height {25}
\BGColor {grey75}
\FGColor {black}
\script {
    switch (arg[0]) {
    case "buttonRelease":
        send("www", "show", "http://www.viola.org/");
        break;
    }
    usual();
}
\
```

### Key Attributes

| Attribute | Description |
|-----------|-------------|
| `\class` | Widget class (typically `txtButton` for toolbar buttons) |
| `\name` | Unique object name |
| `\label` | Button text displayed to user |
| `\width`, `\height` | Button dimensions in pixels |
| `\BGColor`, `\FGColor` | Background and foreground colors |
| `\script` | Event handler code |

### Common Actions in Scripts

```viola
/* Navigate to a URL */
send("www", "show", "http://example.com/");

/* Go to home page */
send("www", "home");

/* Navigate back/forward */
send("www", "back");
send("www", "next");
send("www", "prev");

/* Reload current page */
send("www", "reload");

/* Clone window (new window with same page) */
send("www", "tear");
```

### Practical Constraints

- A toolbar tool should expect the toolbar container to send it `visible 1` / `visible 0` when adding/removing it (see `www_script107.v`). Many tools implement a `case "visible"` handler for this.
- The Viola book notes that the toolbar height is fixed/non-adjustable, so tools should be designed to fit within the toolbar region (see Chapter 13 “[The Dynamic Toolbar](https://web.archive.org/web/20040302222006id_/http://www.xcf.berkeley.edu/~wei/viola/book/chp13.html)”).

### `VIEW_ON` / `VIEW_OFF` for Applets

The Viola book recommends that applets be sensitive to `VIEW_ON` and `VIEW_OFF` so they can stop timers/updates when not in view (see [Chapter 13](https://web.archive.org/web/20040302222006id_/http://www.xcf.berkeley.edu/~wei/viola/book/chp13.html)). In this repository, `VIEW_OFF` is also used to detach document-engaged tools from the toolbar when navigating away.

---

## Implementation Details

### Loading Process

The `<LINK REL="tool">` tag is handled by `HTML_link_script.v`:

```55:86:src/viola/embeds/HTML_link_script.v
		case "tool":
			localFile = HTTPGet(href);
			addrInfo = HTTPCurrentDocAddrParsed(localFile);

			if (nthChar(addrInfo[2], 0) == '/') path = addrInfo[2];
			else path = concat('/', addrInfo[2]);
			objFileName = addrInfo[3];

			addrInfo = HTTPCurrentDocAddrParsed(href);
			objName = nthChar(addrInfo[3], 0, 
					strlen(addrInfo[3]) - 3);
			if (exist(objName)) {
				send(send(parent(), "findTop"), "addTool", 
					objName);
				return "";
			}

			stat = loadObjFile(path, objFileName);

			send("wwwSecurity", "rmTmpFile", localFile);

			if (stat <= 0) {
				print("failed to load obj file {", objFileName,
					"} in {", path, "}\n");
			}
			send(objName, "init"); /* make new object(s) */

			send(send(parent(), "findTop"), "addTool", objName,
				oarg, oargc);
```

### Object Naming Constraint (Derived From Code)

`HTML_link_script.v` derives the tool object name from the `HREF` basename by stripping the trailing `.v`:

- `navigator.v` → `objName = "navigator"`

It then calls `send(objName, "init")` and later records/adds the tool using that same `objName`. In practice this means your `.v` file should create an object with a name that matches the filename (or otherwise ensure that an object named exactly like the filename (without `.v`) exists by the time `init` is sent).

### Toolbar Management

Tools are added/removed from the toolbar container via the `addTool`/`removeTool` messages, handled in `www_script107.v`:

```1:28:src/viola/embeds/www_script107.v

	switch (arg[0]) {
	case "addTool":
	case "addTool_sticky":
		new = object(arg[1]);
		for (i = objectListCount_children(); i >= 0; i--)
			if (nthChild(i) == new) return 1;
		objectListAppend("children", new);
		tweak(new, concat("set(\"parent\", \"", self(), "\");"));
		send(new, "visible", 1);
		config();
		return 1;
	break;
	case "removeTool":
		new = object(arg[1]);
		objectListDelete("children", new);
		send(new, "visible", 0);
		config();
		return 1;
	break;
	case "destroyTool":
		new = object(arg[1]);
		objectListDelete("children", new);
		send(new, "visible", 0);
		send(new, "freeSelf");
		config();
		return 1;
	break;
```

The `addTool` / `removeTool` / `destroyTool` messages are routed to that toolbar container by intermediate objects. For example, the document viewer forwards these messages to its parent:

```332:336:src/viola/embeds/www_script301.v
	case "addTool":
	case "removeTool":
	case "destroyTool":
		return send(parent(), arg[0], arg[1]);
	break;
```

And the top-level `www` UI script routes them to the toolbar child (`nthChild(2)`):

```2:11:src/viola/embeds/www_script.v
	switch (arg[0]) {
	case "addTool":
	case "addTool_sticky":
	case "removeTool":
	case "destroyTool":
		return send(nthChild(2), arg[0], arg[1]);
	break;
	case "clear":
		return send(nthChild(2), arg[0]);
	break;
```

The document object removes its tools on `VIEW_OFF` in `HTML__doc_script.v`:

```480:484:src/viola/embeds/HTML__doc_script.v
	case "VIEW_OFF":
		for (i = 0; i < toolsCount; i++)
			send(parent(), "removeTool", tools[i]);
		return;
	break;
```

The same document object **records tools during parsing** via `addTool`, and provides a separate `addTool_sticky` path:

```616:623:src/viola/embeds/HTML__doc_script.v
	case "addTool":
		tools[toolsCount] = arg[1];
		toolsCount++;
		return;
	break;
	case "addTool_sticky":
		return send(parent(), "addTool", arg[1]);
	break;
```

And it **adds tools to the toolbar when the document is displayed** (not on `VIEW_ON`):

```217:236:src/viola/embeds/HTML__doc_script.v
	case "display":
		/* ... */
		for (i = 0; i < toolsCount; i++) {
			send(get("parent"), "addTool", tools[i]);
			send(tools[i], "visible", 1);
		}
		return;
	break;
```

### Sticky Tools (`addTool_sticky`)

`addTool_sticky` is treated the same as `addTool` by the toolbar container (`www_script107.v`). The difference is **document bookkeeping**:

- Tools recorded via the document’s `addTool` are removed automatically on `VIEW_OFF`.
- Tools added via the document’s `addTool_sticky` are not recorded in `tools[]`, so they won’t be removed automatically on `VIEW_OFF` (you must remove/destroy them explicitly if you use this path).

Navigation triggers `VIEW_OFF` when switching documents (example from `www_script301.v`):

```179:187:src/viola/embeds/www_script301.v
			if (oldDocName != docName) {
				if (pageObj) {
					send(pageObj, "VW_event", "VIEW_OFF");
					send(pageObj, "visible", 0);
					send(pageObj, "freeSelf");
				}
				pageObj = oo;
				send(pageObj, "VW_event", "VIEW_ON");
			} else {
				pageObj = oo;
			}
```

### Message Flow

```
HTML Parser
    ↓
HTML_link_script.v (REL="tool")
    ↓
HTTPGet(href) — download .v file
    ↓
loadObjFile() — parse and create object
    ↓
send(objName, "init") — initialize object
    ↓
send(findTop, "addTool", objName, ...) — record tool for current document
    ↓
when the document is displayed: send(parent, "addTool", objName)
    ↓
objectListAppend() — add to children
    ↓
config() — recalculate toolbar layout
```

---

## Historical Context

This feature was one of ViolaWWW's notable extensibility capabilities:

The table below is an informal comparison to modern concepts.

| ViolaWWW (1993-1995) | Modern analogue (informal) |
|----------------------|-----------------|
| `<LINK REL="tool">` with `.v` applets | Browser extensions, toolbar APIs |
| Document-engaged tools | Per-site browser actions |
| Viola scripting in toolbar | JavaScript-based browser extensions |

From the Viola book (Chapter 9):

> "Plus, the extensibility simply lends a lot more flexibility in designing more sophisticated applications. For example: customized order forms, dynamic and continuously updating stock market quote monitors, interactive games, front-end to remote back-ends, etc."

### Archived Demo: Continuously Updating Toolbar Tool

The archived ViolaWWW demo pages include a concrete example of a **toolbar tool** that maintains a continuous network connection and updates itself in the toolbar (a “monitor bar” / activity monitor concept):

- [Embedding Applets in the ToolBar — monitorBarDemo.html (Wayback)](https://web.archive.org/web/20040307144710id_/http://www.xcf.berkeley.edu/~wei/viola/vw/monitorBarDemo.html)

Key takeaways for this repository’s dynamic toolbar implementation:

- A toolbar tool does **not** have to be a `txtButton`: the demo describes a toolbar-installed applet implemented as a `field` object with a `socket` child (i.e., it’s a live, updating widget).
- The mechanism is still the same: a document uses a “tool” link to a `.v` script, which is fetched, instantiated, and installed into the toolbar via `LINK REL="tool"`.

Related (non-toolbar) demo page showing the same “continuously updating field” concept:

- [Continuously Updating Field — monitorDemo.html (Wayback)](https://web.archive.org/web/20040302093724id_/http://www.xcf.berkeley.edu/~wei/viola/vw/monitorDemo.html)

---

## Related Features

### `<LINK REL="vobj">` — Embedded Objects

Similar to `REL="tool"`, but embeds the Viola object inline in the document rather than in the toolbar:

```html
<LINK REL="vobj" HREF="inset_chess.v">
```

### `<LINK REL="sidebar">` — Sidebar Panel

Creates a sidebar panel for navigation or metadata:

```html
<LINK REL="sidebar" HREF="toc.html" ARG="20">
```

See [PANELS_REFERENCE.md](PANELS_REFERENCE.md) for details.

### `<LINK REL="style">` — Stylesheets

Links a stylesheet (STG format):

```html
<LINK REL="style" HREF="mystyle.stg">
```

See [STG_REFERENCE.md](STG_REFERENCE.md) for details.

### Standard HTML 3.0 LINK Relationships

The [W3C HTML 3.0 specification](https://www.w3.org/MarkUp/html3/dochead.html) reserves a set of `REL=` values for **document-specific toolbars**.

**Note:** In this repository, `src/viola/embeds/HTML_link_script.v` does not implement these reserved values (it implements `made`, `style`, `sidebar`, `tool`, `vobj`). The table below is included as a spec reference, not as a statement of current implementation support.

| REL Value | Description |
|-----------|-------------|
| `Home` | Link to home page or top of hierarchy |
| `ToC` | Table of contents |
| `Index` | Document index |
| `Glossary` | Glossary of terms |
| `Copyright` | Copyright statement |
| `Up` | Parent document in hierarchy |
| `Next` | Next document in sequence |
| `Previous` | Previous document in sequence |
| `Help` | Help document |
| `Bookmark` | Key entry points (with TITLE attribute) |

---

## References

### Viola Book (Archived)

- **Particularly relevant files (Wayback snapshot)**:
  - [Chapter 1](https://web.archive.org/web/20040302222006id_/http://www.xcf.berkeley.edu/~wei/viola/book/chp1.html) — describes toolbar-plugged tools appearing/disappearing with the document
  - [Chapter 9](https://web.archive.org/web/20040302222006id_/http://www.xcf.berkeley.edu/~wei/viola/book/chp9.html) — feature description and screenshot note about toolbar applets linked to the document
  - [Chapter 11 links](https://web.archive.org/web/20040302222006id_/http://www.xcf.berkeley.edu/~wei/viola/book/chp11_links.html) — LINK tag note that `LINK REL="tool"` is for toolbar objects
  - [Chapter 13](https://web.archive.org/web/20040302222006id_/http://www.xcf.berkeley.edu/~wei/viola/book/chp13.html) — “The Dynamic Toolbar” section (constraints, examples)
  - [`tool_violaTOC.v`](https://web.archive.org/web/20040302222006id_/http://www.xcf.berkeley.edu/~wei/viola/book/tool_violaTOC.v) — concrete example of a toolbar tool object

### W3C Documentation

- [HTML 3.0: The Head Element and Related Elements](https://www.w3.org/MarkUp/html3/dochead.html) — LINK element specification

### Source Code

- `src/viola/embeds/HTML_link_script.v` — LINK tag handler
- `src/viola/embeds/www_script107.v` — Toolbar addTool/removeTool
- `src/viola/embeds/HTML__doc_script.v` — Document-level tool tracking

### Release Announcement

- [Release of ViolaWWW 3.3 (April 1995)](https://lists.w3.org/Archives/Public/www-talk/1995MarApr/0455.html) — Pei Wei's announcement mentioning dynamic toolbar
