# ViolaWWW: Ahead of Its Time

> This document summarizes technologies and ideas that ViolaWWW introduced or implemented **before** they became mainstream on the Web. It is intended for historical context and for discussions (e.g. issues) about Viola's place in browser history.
>
> For the origins of Viola and ViolaWWW at UC Berkeley's XCF (eXperimental Computing Facility), see the [XCF historical page](https://xcf.berkeley.edu/historical/) and [PEI_YUAN_WEI_BIOGRAPHY.md](PEI_YUAN_WEI_BIOGRAPHY.md).

## Summary Table

| # | Area | In Viola | Became mainstream (or standard) |
|---|------|----------|----------------------------------|
| 1 | Inline document inclusion | `<INSERT>` (1992–1994) | Frames (Netscape, 1995–1996); later `<iframe>` |
| 2 | Stylesheets | STG (Oct 1993) | CSS (proposed Dec 1994) |
| 3 | Scripting and applets | Viola language in HTML (1991–1992) | JavaScript (1995), Java applets (1995) |
| 4 | Bytecode VM, network-portable code | Viola VM (1991) | Java VM (1995) |
| 5 | Mathematical markup | `<math>`, `<box>`, `<over>`, etc. | MathML (late 1990s) |
| 6 | Console, file system, network | TTY, `system()`, `loadFile()`, `socket` | AJAX (2000s), Fetch API (2015); FS sandboxed |
| 7 | Collapsible/expandable content | `FOLD` attribute (Mar 1994) | HTML5 `<details>`/`<summary>` (~2011–2014) |
| 8 | `<FIGURE>` with captions and image maps | `<FIGURE>`, `<FIGA>`, `<FIGCAP>` (May 1993) | HTML5 `<figure>`/`<figcaption>` (2014); `<map>`/`<area>` |
| 9 | Dynamic toolbar (per-document) | `<LINK REL="tool">` (1994) | Browser extensions (Firefox 2004, Chrome 2009) |
| 10 | Sidebar panel | `<LINK REL="sidebar">` (1994–1995) | Opera/Firefox sidebar panels (2000s) |
| 11 | Multi-column layout | HPANE, COL2/COL3/COL4 (1994) | CSS Multi-column Layout (~2011) |
| 12 | Real-time peer sync | `discoveryBroadcast()` (1994–1995) | WebSocket (2011), WebRTC (2017) |
| 13 | Browser as application platform | Wei's vision (1992–1994) | Web apps, Chrome OS (2011) |

---

## 1. `<INSERT>` — Document Inclusion Before Frames

Viola's **`<INSERT>`** tag embeds another document (HTML or other) inline at a point in the page. The embedded content is fetched and laid out inside the current document, with support for attributes such as `HREF`, `AFTER` (refresh interval), `MAXWIDTH`/`MINWIDTH`, and `BORDER`.

- **In Viola**: Present in the "next generation" SGML-based architecture (1992–1993) and in the shipped embed script `HTML_insert_script.v`.
- **Mainstream**: **HTML frames** were proposed by Netscape in September 1995 and shipped in Netscape Navigator 2.0 (March 1996). Frames split the view into separate windows; Viola's INSERT is closer in spirit to **inline** inclusion (similar to later iframes or embedded content).

**Reference**: [src/viola/embeds/HTML_insert_script.v](../src/viola/embeds/HTML_insert_script.v), [CHANGELOG_HISTORY.md](CHANGELOG_HISTORY.md) (document insertion, client-side extensions).

---

## 2. STG — Stylesheets Before CSS

Viola's **STG** (Style Tag Group) is a stylesheet system that associates presentation (fonts, colors, alignment, etc.) with HTML elements. STG files are linked with `<link rel="style" href="...">` and support tag-based and attribute-based selectors. Pei Wei had a prototype in Viola and described the stylesheet language on WWW-Talk in **October 1993**; the earliest surviving source with STG is ViolaWWW 3.1 Beta (March 1994).

- **In Viola**: Public stylesheet proposal and prototype from **October 1993**; implementation in 1993–1994.
- **Mainstream**: **Cascading Style Sheets (CSS)** were first proposed by Håkon Wium Lie in **December 1994**. Viola was the only browser with any stylesheet support in Pei Wei's October 1993 capabilities chart.

**Reference**: [STG_REFERENCE.md](STG_REFERENCE.md), WWW-Talk archives (Oct 1993, Oct 1994).

---

## 3. Viola Language — Scripting and Applets Before JavaScript and Java

The **Viola language** is a two-level system: declarative object (`.v`) files for GUI and a C-like script for behavior. It supports message-passing, event handlers, and embedding in HTML. Viola objects could be embedded in pages and scripted, giving interactive, programmable content in the browser.

By May 1993, Wei had "mini-applications" (applets): a network traffic monitor, a chessboard, a chat app that let you send text AND draw things, and a drawing tool called xplot. *"Two years later Sun released the Java language, complete with applets, to great fanfare, but Pei Wei had been there first."* (Cailliau & Gillies, *How the Web Was Born*).

- **In Viola**: Viola 0.8 (1991); embedded "program links" discussed **May 1992**; applets demonstrated **May 1993** and at the first Web Conference (August 1993).
- **Mainstream**: **JavaScript** was introduced in Netscape in **1995**; **Java applets** also in **1995**.

**Reference**: [VIOLA_LANGUAGE.md](VIOLA_LANGUAGE.md), [VIOLA_FUNCTIONS.md](VIOLA_FUNCTIONS.md), [CHANGELOG_HISTORY.md](CHANGELOG_HISTORY.md) (Program Links, May 1992; applets, May–Aug 1993).

---

## 4. Bytecode VM and Network-Portable Code Before Java

Viola was not just a scripting language — it was an **object-oriented programming language with a bytecode VM**. The browser itself was a VM application — the "killer app" that made most people care about the Viola platform. Pei Wei's vision was to create something generalized and network-portable: *"it wouldn't matter what kind of computer you were on."* Code could travel across the network and execute on the other side — the same idea that Java later made famous.

Tim Berners-Lee recognized this in 1998: *"an interpreted language which could be moved across the NET and could talk to a screen... in fact what he did was really ahead of his time."*

- **In Viola**: Bytecode VM from **1991**; network-portable objects from **1992**.
- **Mainstream**: **Java VM** released in **1995**.

**Reference**: [PEI_YUAN_WEI_BIOGRAPHY.md](PEI_YUAN_WEI_BIOGRAPHY.md) (architecture, Tim Berners-Lee quote).

---

## 5. MATH — Mathematical Markup Before MathML

Viola supports mathematical notation in HTML via tags such as `<math>`, `<sup>`, `<sub>`, `<box>...<over>...</box>` (fractions), and extensible parentheses and brackets. This allowed authoring of formulae directly in the document.

- **In Viola**: MATH infrastructure existed in original ViolaWWW; rendering of symbols, sub/superscripts, and extensible delimiters was completed in ViolaWWW 4.0.
- **Mainstream**: **MathML** and widespread browser support for math came later (late 1990s onward). Viola's approach predates standard math-on-the-web solutions.

**Reference**: [MATH_REFERENCE.md](MATH_REFERENCE.md).

---

## 6. Console, File System, and Network from Script

Viola's scripting environment exposed capabilities that later browsers either offered briefly and then restricted, or recreated in different forms:

- **Console / running programs**: The **TTY** class runs an external program and communicates with it via a pseudo-terminal. Scripts can call **`system()`** and **`pipe()`** to execute shell commands. This is analogous to early "power user" features in some Netscape/IE eras (e.g. console, limited local access), which were later locked down for security.
- **File system**: **`loadFile()`**, **`saveFile()`**, **`deleteFile()`** give scripted access to the local file system. Again, similar in spirit to early browser or host capabilities that later became sandboxed.
- **Network from script**: The **`socket`** widget and **`socket.startClient()`** open TCP connections and send/receive data from Viola scripts. This is conceptually similar to **AJAX** (early 2000s) and the **Fetch API** (2015): script-initiated network I/O without reloading the page. Viola had it in the early 1990s, with a security model (e.g. trusted vs untrusted documents) documented in 1994 and fully implemented in ViolaWWW 4.0.

**Reference**: [TTY_REFERENCE.md](TTY_REFERENCE.md), [SECURITY_IMPLEMENTATION.md](SECURITY_IMPLEMENTATION.md), [VIOLA_LANGUAGE.md](VIOLA_LANGUAGE.md) (socket class), [VIOLA_FUNCTIONS.md](VIOLA_FUNCTIONS.md) (`system()`, `loadFile()`, etc.).

---

## 7. Collapsible/Expandable Content Before `<details>`/`<summary>`

ViolaWWW supported a **`FOLD`** attribute on list elements (`<UL>`, `<OL>`) that made their content collapsible and expandable by clicking a folder icon. `FOLD="yes"` started collapsed; `FOLD` (without value) started expanded.

- **In Viola**: Working prototype in **ViolaWWW 3.1 Beta (March 1994)**. The release announcement noted: *"its got a working prototype of the collapsible/expandable :-)"*. The v3.3 release (April 1995) listed *"collapsible/expandable lists"* among extensions.
- **Mainstream**: **HTML5 `<details>`/`<summary>`** elements (functionally equivalent) became a standard around **2011–2014**.

**Reference**: [FIGURE_REFERENCE.md](FIGURE_REFERENCE.md) (FOLD attribute description), [CHANGELOG_HISTORY.md](CHANGELOG_HISTORY.md) (v3.1 Beta, FOLD proposal).

---

## 8. `<FIGURE>` with Captions and Image Maps Before HTML5

Viola's **`<FIGURE>`** element (proposed by Pei Wei on WWW-Talk in **May 1993**) was an advanced image container supporting:
- **`<FIGCAP>`** — figure captions (predates HTML5 `<figcaption>`)
- **`<FIGA>`** — client-side image map hotspots with `HREF` and `AREA` attributes (predates HTML `<map>`/`<area>`)
- **`<FIGDATA>`** — inline image data (XBM, XPM, GIF, PostScript)
- **`MAYDELAY`** — lazy/delayed image loading

The proposal was later included in the HTML+ DTD specification by Dave Raggett.

- **In Viola**: `<FIGURE>` proposed **May 1993**; `<FIGA>` image maps implemented **January 1994**.
- **Mainstream**: HTML5 **`<figure>`/`<figcaption>`** standardized around **2014**; **`<map>`/`<area>`** became the standard image map mechanism.

**Reference**: [FIGURE_REFERENCE.md](FIGURE_REFERENCE.md), [IMAGE_FORMATS.md](IMAGE_FORMATS.md), [WWW-Talk 1993: Proposal for FIGURE tag](https://ksi.cpsc.ucalgary.ca/archives/WWW-TALK/www-talk-1993q2.messages/409.html).

---

## 9. Dynamic Toolbar — Per-Document Browser Extensions Before Extensions

ViolaWWW's **`<LINK REL="tool">`** tag allowed HTML documents to install **toolbar applets** — interactive Viola objects that appeared in the browser toolbar while the document was being viewed, and were removed when navigating away. These could be navigation aids, slideshow controllers, live network monitors, or any custom widget.

> *"The scripting language system allows browser functionality to be extended dynamically. Can dynamically plug-in new tools into the browser toolbar."* — ViolaWWW documentation.

- **In Viola**: Dynamic toolbar in **ViolaWWW 3.1 Beta (March 1994)**; described as a key feature in the v3.3 release (April 1995).
- **Mainstream**: **Browser extensions** — Firefox extensions (2004), Chrome extensions (2009) — and per-site browser actions.

**Reference**: [TOOLBAR_REFERENCE.md](TOOLBAR_REFERENCE.md), [CHANGELOG_HISTORY.md](CHANGELOG_HISTORY.md) (v3.1, v3.3 releases).

---

## 10. Sidebar Panel Before Browser Sidebars

Viola's **`<LINK REL="sidebar">`** tag declared a sidebar document (e.g. a table of contents) that the browser displayed alongside the main content, with a configurable width ratio via the `ARG` attribute. This gave documents a built-in navigation panel.

- **In Viola**: Implemented in **ViolaWWW 3.x (1994–1995)**; the v3.3 release listed *"sidebar panel for meta-information or intra-document navigation links."*
- **Mainstream**: **Opera sidebar panels** (~2000s), **Firefox sidebar** — dedicated side panel UI in browsers.

**Reference**: [PANELS_REFERENCE.md](PANELS_REFERENCE.md) (LINK rel=sidebar section), [TOOLBAR_REFERENCE.md](TOOLBAR_REFERENCE.md).

---

## 11. Multi-Column Layout Before CSS Columns

ViolaWWW provided several mechanisms for multi-column layout: the **`<HPANE>`** tag (horizontal columns formatter for side-by-side content), and **`<COL2>`**, **`<COL3>`**, **`<COL4>`** tags for 2-, 3-, and 4-column grids. The v3.3 release announcement listed *"multi-column formatting"* as an extension.

- **In Viola**: **HPANE** and **COL** tags in **ViolaWWW 3.0–3.3 (1994–1995)**.
- **Mainstream**: **CSS Multi-column Layout** (W3C Working Draft 2001, widespread browser support ~2011).

**Reference**: [PANELS_REFERENCE.md](PANELS_REFERENCE.md) (HPANE, COL2/COL3/COL4 sections).

---

## 12. Real-Time Peer Sync Before WebSocket and WebRTC

ViolaWWW included a **peer discovery and synchronization** system. When HTML elements had the `SC` attribute, ViolaWWW could broadcast property changes (position, color, rotation, scale) to **all other ViolaWWW instances viewing the same page** via `discoveryBroadcast()`. This enabled collaborative interactive content — games, demos, shared 3D views — without a central server managing state.

- **In Viola**: Discovery/sync system in **ViolaWWW 3.x (1994–1995)**.
- **Mainstream**: **WebSocket** (2011), **WebRTC** (2017), collaborative editing (Google Docs, 2006).

**Reference**: [VIOLA_FUNCTIONS.md](VIOLA_FUNCTIONS.md) (Peer Discovery Functions), [SECURITY_IMPLEMENTATION.md](SECURITY_IMPLEMENTATION.md) (Discovery Broadcast section).

---

## 13. Browser as Application Platform

Pei Wei's ultimate vision went beyond a document viewer:

> *"The Web back then was basically like reading a book, a really big book, but nothing was really interactive. His idea was to add interactivity to the Web so that it actually became the graphical user interface. You wouldn't need to have different programs to do spreadsheets or word processing or surfing the Web — you would do it all in ViolaWWW."*

In Wei's ideal world, *"you would never find a file you couldn't open because you didn't have the right program; the program would just come down the wire along with the information."*

This vision — the browser as the operating system, with code delivered over the network — is exactly what **web applications**, **Progressive Web Apps (PWA)**, and **Chrome OS** realized decades later.

- **In Viola**: Demonstrated in **1992–1994** with applets, embedded objects, and the Viola VM.
- **Mainstream**: **Rich web apps** (2000s), **Chrome OS** (2011), **PWA** (2015+).

**Reference**: [PEI_YUAN_WEI_BIOGRAPHY.md](PEI_YUAN_WEI_BIOGRAPHY.md) (Wei's Vision section).

---

## Other Notable Firsts

- **Bookmarks, Back/Forward, History** — Viola had these in 1992; they became standard browser UI. NCSA acknowledged that *"the initial version of Mosaic drew on the innovations of earlier browsers,"* including icon buttons, bookmarks, and varied fonts.
- **Tables** — Early support in a graphical browser, before HTML tables were standardized (HTML 3.2, 1997).
- **Multiple windows, clone** — Multi-window browsing and page cloning.
- **Embedded scrollable regions** — In November 1992, Tim Berners-Lee noted that Viola already allowed a `LISTING` section to be viewed as an embedded scrollable region, predating `overflow: scroll` and scrollable iframes.
- **Security model for web content** — Trusted vs untrusted content with restrictions on file system, `system()`, socket, and interpreter access. Described in the 1994 violaIntro paper; fully implemented in ViolaWWW 4.0. Predates the same-origin policy formalization.

---

## See Also

- [PEI_YUAN_WEI_BIOGRAPHY.md](PEI_YUAN_WEI_BIOGRAPHY.md) — Creator of ViolaWWW and XCF context.
- [CHANGELOG_HISTORY.md](CHANGELOG_HISTORY.md) — Evidence-based release and feature timeline.
- [XCF historical page](https://xcf.berkeley.edu/historical/) — UC Berkeley Experimental Computing Facility history (Viola's birthplace).
- [W3.org: ViolaWWW](https://www.w3.org/History/19921103-hypertext/hypertext/WWW/Viola/violaWWWAbout.html) — Early W3 documentation.
- [ViolaWWW – Wikipedia](https://en.wikipedia.org/wiki/ViolaWWW), [The History of the Web: ViolaWWW](https://thehistoryoftheweb.com/milestones/violawww/) — Short overviews.
