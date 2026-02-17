# ViolaWWW Release History (Evidence-Based Timeline)

> This document compiles the release history of ViolaWWW based on historical sources, announcements, and archived materials.
>
> For biographical information about Pei-Yuan Wei, the creator of ViolaWWW, see [PEI_YUAN_WEI_BIOGRAPHY.md](PEI_YUAN_WEI_BIOGRAPHY.md).

## How to read this document

This file is a **timeline**, not a conventional “changelog”. Wherever possible, each entry includes **direct evidence** and is written to avoid speculation.

### Evidence labels

- **Announcement**: date of a public mailing list / Usenet post.
- **README date**: date stated inside a distributed README (often reflects packaging time, not necessarily first public release).
- **Archive snapshot**: date implied by an archive filename or mirror timestamp (useful but not always authoritative).
- **Version string**: date/version embedded in source code.
- **Secondary source**: later narrative/compilation; useful for hints, but treated as non-primary dating.

### Editorial policy (for maintainers)

These rules are here to keep future edits evidence-based and to avoid silently “choosing” one date when sources disagree.

- If something is an inference, it is phrased as **“suggests/indicates”**, not “proves/confirms”.
- Retrospective claims are marked as such.
- Where different dates exist (announcement vs README vs archive filename), we keep all of them and avoid picking a single “true” date unless the sources clearly agree.

---

## Viola (Pre-WWW Era)

### Viola 0.5 (version number known; release date unknown)

- **Evidence**
  - **Usenet repost (alt.hypertext)**: 1991-04-30 — Lee Moore (Webster Research Center, Xerox Corp.) shared the Viola README on alt.hypertext with the note: “For those of you who didn’t see it, there is a hypercard-like prototype system for X11 that is now available.” The README header reads “VIOLA VERSION 0.5 (pre-release version).”
  - **Usenet repost (comp.archives)**: 1991-05-24 — Randolph K. Zeitvogel (Symbolics MACSYMA division) also cited the 0.5 README. The comp.archives verification of `scam.berkeley.edu:/src/local/viola/` lists `viola.0.8.tar.Z` (dated Apr 25, 17:41) and a `README` (dated Apr 26, 06:09). The cited README text reads “VERSION 0.5.”
- **Note**
  - Two independent Usenet reposters cited a README reading “VERSION 0.5 (pre-release version).” The README content is otherwise identical to the known 0.8 README (same platforms, same copyright, same development status note).
- **Sources**
  - [Usenet Archives: alt.hypertext repost (Apr 30, 1991) — Lee Moore, Xerox Corp.](https://usenetarchives.com/view.php?id=alt.hypertext&mid=PDc5NkByb2Nrc2FubmUuV1JDLlhFUk9YLkNPTT4)
  - [Usenet Archives: comp.archives verification (May 24, 1991) — FTP directory listing](https://usenetarchives.com/view.php?id=comp.archives&mid=PDkxMDUyNDAwMDYuQUEwNTAyMkB2aW9sZXQuYXJib3J0ZXh0LmNvbT4)

### 1991-04-23 — Viola preview release (pre-WWW)

- **Evidence**
  - **Announcement**: Usenet (comp.windows.x), Message-ID `<9104231058.AA27453@scam.Berkeley.EDU>`
  - Mentions anonymous FTP availability on `scam.berkeley.edu`
- **What the source says**
  - First public announcement of the Viola system (before WWW support). Described as a “highly manipulable interactive-media authoring tool for UNIX/X11”.
- **Selected details from the Viola 0.8 README** (preserved in a June 1991 Usenet repost on comp.unix.sysv386)
  - README header: “VIOLA VERSION 0.8 (pre-release version)”.
  - Self-description: “a graphical user interface toolkit with an embedded command language. The interpretive nature of Viola enables it to be highly interactive.”
  - Supported binaries: DECstation 3100 (Ultrix T4.0-1), SparcStation (SunOS Release 4.0.3c).
  - Written in “plain C”, uses X11R4.
  - License: free public use with attribution; fees only with written permission of the copyright holder.
  - Mailing list: `viola-users@ic.berkeley.edu`.
  - Development status note: “Viola is unofficially supported only by me, not by the Experimental Computing Facility. Also, since I’m graduating next month (May’91), Viola’s future development is uncertain.”
- **Early third-party reception**
  - By June 1991, Chin Fang (Stanford University, Mechanical Engineering) had ported Viola to IBM RISC 6000 systems, describing it as a “tremendous pkg” and reporting the port required “just one line hack.”
  - By July 1991, a comp.windows.x thread (started by Dan Warburton, FAA Technical Center, NJ) shows international adoption within three months of the initial release:
    - A user at a Japanese institution reported making a **Japanese version** of Viola for his students — the earliest known internationalization/localization effort.
    - Dr Ray Saffin (Crosfield Electronics, UK) had already ported Viola to **IBM RS/6000-530** and **Intel 386 running ISC Unix 2.2** (noting the 14-character filename limit required renaming include files), and planned a port to **HP 9000-720**.
    - The thread also notes the lack of documentation — a problem later observed by Tim Berners-Lee in his 1992 review.
- **Sources**
  - [Usenet Archives: Viola announcement (Apr 1991)](https://www.usenetarchives.com/view.php?id=comp.windows.x&mid=PDkxMDQyMzEwNTguQUEyNzQ1M0BzY2FtLkJlcmtlbGV5LkVEVT4)
  - [Usenet repost (comp.unix.sysv386, Jun 1991): “X based HyperCard like application” (includes Viola 0.8 README)](https://mirrors.nycbug.org/pub/The_Unix_Archive/Unix_Usenet/comp.unix.sysv386/1991-June/004194.html)
  - [Usenet Archives: comp.windows.x thread (Jul 1991) — documentation, Japanese version, platform ports](https://usenetarchives.com/view.php?id=comp.windows.x&mid=PDE1NDBAZmFhdGNybC5VVUNQPg)

### 1991-04-23 — Viola 0.8

- **Evidence**
  - **Announcement**: Usenet (comp.windows.x), 1991-04-23 (see preview release entry above)
  - **README (from distribution)**: header reads "VIOLA VERSION 0.8 (pre-release version)"
  - **README archive date**: 1991-04-25 (from archived copy URL)
  - **FTP directory listing** (comp.archives verification, 1991-05-24): `viola.0.8.tar.Z` dated Apr 25, 17:41; `README` dated Apr 26, 06:09
  - **Retrospective (author statement)**: “first version of viola (0.8) released in 1991”
- **Note**
  - The Usenet announcement on April 23 directed users to FTP the Viola 0.8 distribution; the README was archived two days later (April 25). The README explicitly labels 0.8 as a “pre-release version.”
- **Sources**
  - [Olde Viola Montage (archived; author retrospective note)](https://web.archive.org/web/19990830034431id_/http://viola.org/vintage/montage.html)
  - [Viola 0.8 README (archived, dated Apr 25, 1991)](https://www.krsaborio.net/internet/research/1991/0425.htm)
  - [Usenet Archives: comp.archives FTP verification (May 1991) — directory listing of `scam.berkeley.edu`](https://usenetarchives.com/view.php?id=comp.archives&mid=PDkxMDUyNDAwMDYuQUEwNTAyMkB2aW9sZXQuYXJib3J0ZXh0LmNvbT4)

---

## ViolaWWW (Browser Era)

### 1991-12-09 to 1991-12-13 — “One-night hack” (initial X11 browser implementation)

- **Evidence**
  - **Announcement**: 1991-12-09 (intention announced) on WWW-Talk
  - **Announcement**: 1991-12-13 (technical details) on WWW-Talk
- **What the sources say**
  - Pei-Yuan Wei announced an intention to create an X11 browser by extending the Viola system, described the initial implementation as “a one-night hack”, and discussed reusing/connecting existing WWW code.
- **Selected technical details recorded in the 1991-12-13 message**
  - Viola used as a frontend wrapper for the existing `www` line-mode browser.
  - Only “very few and minor changes” were made to `www.c`.
  - An X11 interface displayed `www` output in a scrollable text field.
  - Reference numbers were visually highlighted; references and commands became clickable / keyboard-accessible.
  - Buttons corresponded to `www` commands (e.g., Back, Help).
  - Future direction: “embed viola objects … into html files” (GUI/programming objects in documents).
- **Sources**
  - [WWW-Talk 1991: Re: SGML/HTML docs, X Browser](http://1997.webhistory.org/www.lists/www-talk.1991/0026.html)
  - [WWW-Talk 1991: X Browser](https://lists.w3.org/Archives/Public/www-talk/1991NovDec/0023.html)
  - [Tim Berners-Lee FAQ: early browsers](https://www.w3.org/People/Berners-Lee/FAQ.html#browser)

### Early 1992-01 — Demonstration observed on Apollo and DECstation

- **Evidence**
  - **Announcement (W3 News 9201)**: “I just saw it running on an apollo and on a decstation… We hope to release it soon…”
- **Note**
  - This observation indicates that ViolaWWW was functional on multiple platforms by early January 1992, and that a public release was anticipated.
- **Source**
  - [W3.org History: What’s new in ’92 (January 1992)](https://www.w3.org/History/19921103-hypertext/hypertext/WWW/News/9201.html)

### 1992-01-24 — First CERN test report (Tim Berners-Lee)

- **Evidence**
  - **Announcement**: WWW-Talk post dated 1992-01-24
- **What the source says (selected)**
  - “ViolaWWW works great! It has impressed us here.”
  - It was “fine on decstation and apollo displays” (and one crash was attributed to an HP X server problem).
  - Performance note: “a search in the CERN phone book seems instantaneous (when done at CERN).”
- **Source**
  - [WWW-Talk 1992: “Viola - WWW interface”](http://1997.webhistory.org/www.lists/www-talk.1992/0002.html)

---

### 1992-03-09 to 1992-04-20 — CERN testing phase (2.0.x)

- **Evidence**
  - **Version string (known by 1992-04-04)**: `Viola=2.0.4, date=April 4, 1992` (from surviving source; see `ViolaWWW_920515/src/main.c` in [`viola-2.0.4.tar`](https://browsers.flanigan.us/browsers/violawww/files/viola-2.0.4.tar))
  - **Compilation report**: “problem yacc’ing violaWWW” dated 1992-03-21 (Sun/SPARC)
  - **Review**: Tim Berners-Lee “Quick look” review dated 1992-04-11
  - **W3 News**: April 1992 release note about a search panel issue and fix
  - **Artifact**: “About/Status” screenshot lists “March 9 to April 20, 1992” as CERN test window (see later “About/Status screenshot” entry)
  - **Archive artifact (920730 snapshot)**: the bundled “About” page content in `apps/www.v` includes the same “March 9 to April 20, 1992” status line
- **What the sources support**
  - ViolaWWW circulated to the WWW team at CERN for testing during this period.
  - Public compilation issues were reported by 1992-03-21, suggesting circulation outside CERN by late March 1992.
  - A particular April 1992 build lacked a search panel and was not generally distributed; a corrected version followed.
- **Selected details captured in the 1992-04-11 review (Tim Berners-Lee)**
  - **Environment**
    - Tested on a NeXT with CubeX (grayscale and color versions).
  - **UI and navigation**
    - Multifont text display; links highlighted with “button” boxes (single-click jump).
    - Navigation behavior at that time: “Up” acted like a destructive Back; “Left/Right” traversed history non-destructively.
    - “Fuzzy clicking”: clicking near a button could trigger the action.
    - UI note: window looked “a little cluttered”; suggestion to move the “ViolaWWW” title to the window title bar.
  - **Features and tools**
    - “Home”, “Back” and “Forward” buttons are listed among features.
    - Single-window operation with a “clone” facility; bookmark facility; online help buttons.
    - Remote index searching via a bottom input field; source viewer for HTML markup.
    - “Bells and whistles”: three small icons after the index search field (history, print, and source viewer); history and print were described as close to working at that time.
  - **Formatting and performance**
    - Formatting note: the `LI` list style was described as too close to normal text; reviewer suggested indentation and whitespace between list elements.
    - Performance commentary: multifont version slower than an older monofont “1.0” reference; reviewer considered multifont worth the trade-off.
  - **Installation**
    - Ease-of-use note: installation described as (binary + Viola scripts directory + shell script setting an environment variable), and starting the program by typing `vw` (default home page).
  - **Clone behavior (UI detail)**
    - The clone button icon is described as “tearing a sheet off a pad”; clone windows were described as intentionally uncluttered (few/no buttons) while links opened in the master window.
- **Known issues reported in early 1992 testing notes**
  - **Stability**
    - Crashes when closing a clone window or the main window.
  - **UI**
    - Scroll bar and left-side icon buttons sometimes did not appear; resizing the window vertically made them reappear.
  - **Color**
    - A “minor bug” was reported to crash the program on color screens; “crashes on first jump” on a color display was also noted.
  - **Documentation**
    - Reviewer noted there “isn't much documentation on the product.”
- **Sources**
  - [WWW-Talk 1992: “problem yacc’ing violaWWW”](http://1997.webhistory.org/www.lists/www-talk.1992/0035.html)
  - [W3.org: “A quick look at ViolaWWW” (1992-04-11)](https://www.w3.org/History/19921103-hypertext/hypertext/Viola/Review_0.html)
  - [W3.org History: “Spring releases” (April 1992)](https://www.w3.org/History/19921103-hypertext/hypertext/WWW/News/9204.html)
  - [Ancient Web Browsers: ViolaWWW](https://browsers.flanigan.us/browsers/violawww/)
  - [Ancient Web Browsers: About/Status page screenshot](https://browsers.flanigan.us/browsers/violawww/img/Viola-2.1.0_notes.jpg)
  - [Archive: `viola-2.0.4.tar` (contains `ViolaWWW_920515/src/main.c` version string)](https://browsers.flanigan.us/browsers/violawww/files/viola-2.0.4.tar)
  - [Archive snapshot: `viola920730.tar.gz` (contains `apps/www.v` “Overview, ViolaWWW”)](https://browsers.flanigan.us/browsers/violawww/files/viola920730.tar.gz)
  - [Viola home page (archived; retrospective note “first released around April 1992”)](https://web.archive.org/web/20180203005145/http://www.viola.org/)
  - [W3C: CERN-hosted ViolaWWW RS/6000 distribution](https://www.w3.org/History/1995/WWW/Viola/bin/rs6000/)
  - [W3C: CERN-hosted ViolaWWW RS/6000 source tree](https://www.w3.org/History/1995/WWW/Viola/bin/rs6000/ViolaWWW_920515/src/)
  - [W3C: CERN-hosted ViolaWWW multi-platform binaries](https://www.w3.org/History/1995/WWW/Viola/bin/)
- **CERN/W3-hosted source and binary trees**
  - The same `ViolaWWW_920515` distribution survives on the W3C server at `/History/1995/WWW/Viola/bin/rs6000/ViolaWWW_920515/` — an **IBM RS/6000 port** of ViolaWWW 2.0.4, with source, compiled objects, and apps. A tar archive (`ViolaWWW_920515.tar`, 2.8M, 1994-06-23) and a standalone RS/6000 binary (`viola`, 407K, 1992-06-19) are also at the parent level.
  - Base source files are dated **1992-05-10** (matching the JENC3 demo date). The RS/6000 port was patched on **1992-05-20 to 1992-05-21**; `.orig` files survive alongside the patched versions (`main.c.orig`, `cgen.c.orig`, `cl_cosmic.c.orig`, `class.c.orig`, `cl_pane.c.orig`, `event_x.c.orig`, `event_x.h.orig`, `ast.h.orig`, `mystrings.h.orig`, `slotaccess.h.orig`, `scanutils.c.orig`), documenting what was changed for the port.
  - The `main.c` (3.9K) is notably simpler than the later 2.1.0 version (4.9K): no `-snipet`/`-s` option, no `-obj`/`-o` option, no `setHTMLStyle()` call, no `scriptSnipet` support. Uses `-f` and `-i` instead of the later `-cli`/`-c`.
  - Contains the same double `init_sys()` bug (exit codes 2 and 3) that persists in 2.1.0 and is fixed in 2.1.2.
  - **Multi-platform binaries** survive at `/History/1995/WWW/Viola/bin/` for five platforms:

    | Platform | File | Date | Size |
    |---|---|---|---|
    | DECstation | `viola` | 1992-07-16 | 1.9M |
    | DECstation | `viola.old` | 1992-06-06 | 1.7M |
    | NeXT | `viola` | 1992-06-23 | 2.2M |
    | RS/6000 | `viola` | 1992-06-19 | 407K |
    | SPARC | `viola` | 1994-06-23 | 1.1M |
    | HP PA-RISC ("Snake") | *(build dir only)* | 1992-11 to 1993-01 | — |

  - The **NeXT binary** (1992-06-23) is notable because ViolaWWW is an X11 browser; NeXT supported X11 as a compatibility layer. The DECstation `viola.old` (1992-06-06) is the earliest surviving binary. An **HP PA-RISC ("Snake")** build directory also survives at `/History/1995/WWW/Viola/snake/` (with Makefiles from November 1992 and January 1993, symlinked to the shared `src/` tree), but no binary is present.

### 1992-05-10 to 1992-05-15 — Beta release phase (JENC3 demo; packaging dates)

- **Evidence**
  - **Demo date**: JENC3 conference (1992-05-10)
  - **“Last update”**: 1992-05-10 (noted inside `www.v` in surviving materials)
  - **README date**: 1992-05-15 (packaging date cited for `ViolaWWW_920515`)
  - **Review**: Tim Berners-Lee updated review dated 1992-05-15
  - **Archive artifact (920730 snapshot)**: `apps/www.v` Status list includes “May 10, 1992 — Beta release.”
- **What the sources support**
  - A widely described “beta test” version existed by mid-May 1992; TBL reviewed it and recorded both features and limitations.
- **Selected features/behavior noted in the 1992-05-15 review**
  - **Core features**
    - Multifont support; “clone” facility; bookmarks and history list.
    - “Home”, “Back” and “Forward” buttons are listed among features.
    - Index search facility (bottom input field) and bottom-row icons for History/Printing/Source Viewer.
  - **Documentation/help**
    - Hidden documentation (e.g., globe icon for Viola docs; question-mark icon for help).
    - Help caching behavior: local copies preferred; remote help cached in `/usr/tmp`.
  - **Notes and limitations**
    - Cut-and-paste was noted as not working yet (selection could be made and shown underlined).
    - “Font hang” mentioned as a possible startup issue on some systems (example: OpenWindows).
    - Formatting note: the `LI` list style was described as too close to normal text; reviewer suggested indentation and whitespace between list elements.
  - **Clone behavior (UI detail)**
    - The clone button icon is described as “tearing a sheet off a pad”; clone windows were described as intentionally uncluttered (few/no buttons) while links opened in the master window.
  - **Platforms**
    - The updated review mentions it had been run on Sun4 and DECstation (in addition to NeXT used for testing).
  - **Reviewer conclusion (quoted)**
    - “A very neat browser … very intuitive and straightforward…”
- **Selected overview points from the ViolaWWW “About” page (CERN/W3 mirror)**
  - Basic navigation described as: clickable hot-words, history traversal, and bookmark list.
  - Keyword search entry and page cloning (multiple windows).
  - A simple printer hook and an HTML source viewer (not editor).
- **Sources**
  - [W3.org: “An updated quick look at ViolaWWW” (1992-05-15)](https://www.w3.org/History/19921103-hypertext/hypertext/Viola/Review.html)
  - [W3.org: Installation instructions (May 1992)](https://www.w3.org/History/19921103-hypertext/hypertext/Viola/Installation.html)
  - [CERN mirror: updated quick look](https://info.cern.ch/hypertext/Viola/Review.html)
  - [CERN mirror: installation instructions](https://info.cern.ch/hypertext/Viola/Installation.html)
  - [CERN: Status of ViolaWWW](https://info.cern.ch/hypertext/WWW/Viola/Status.html)
  - [CERN/W3: ViolaWWW About page](https://info.cern.ch/hypertext/WWW/Viola/violaWWWAbout.html)
  - [Ancient Web Browsers: ViolaWWW](https://browsers.flanigan.us/browsers/violawww/)
  - [Ancient Web Browsers: About/Status page screenshot](https://browsers.flanigan.us/browsers/violawww/img/Viola-2.1.0_notes.jpg)
  - [Archive snapshot: `viola920730.tar.gz` (bundles “Overview, ViolaWWW” content in `apps/www.v`)](https://browsers.flanigan.us/browsers/violawww/files/viola920730.tar.gz)

### 1992-05-21 — Embedded Viola scripts (“program links”) discussed

- **Evidence**
  - **Announcement**: WWW-Talk post dated 1992-05-21
- **What the source says (selected)**
  - The intent of the `<S>` tag is to embed Viola scripts in HTML, enabling “program links” that can start subprocesses.
  - The author notes that the scripting experiment was unfinished and that internal demonstration files might not work for external users (example given: a demo that required a local Xmap program).
- **Related discussion**
  - A follow-up thread discusses “program links” more generally and points to document format negotiation as a possible way to deliver executable content in different languages (example given: Viola script and/or `/bin/sh`). (This is general WWW architecture discussion, not a ViolaWWW release note.)
- **Source**
  - [WWW-Talk 1992: Re: World Wide Web and Viola](http://1997.webhistory.org/www.lists/www-talk.1992/0064.html)
  - [WWW-Talk 1992: Program Links in WWW](http://1997.webhistory.org/www.lists/www-talk.1992/0065.html)

### 1992-05-23 — Version 2.1.0

- **Evidence**
  - **Version string**: `Viola=2.1.0, date=May 23, 1992` (from surviving source)
- **Note**
  - Described as an early public release with sources and binaries for multiple platforms.
- **CERN/W3-hosted source tree**
  - The complete ViolaWWW 2.1.0 source and apps survive on the W3C server at `/History/1995/WWW/Viola/old/` (with `src/`, `apps/`, and `xpm/` subdirectories). Base files are dated 1992-06-04 (upload to CERN, ~12 days after the version date); several source files were patched on 1992-06-23: `Makefile`, `ast.h`, `cl_pane.c`, `cl_PS.c`, `event_x.c`, `gram.c`, `html.c`, `mystrings.c` — interim fixes before the 2.1.2 release (July 14).
  - The `main.c` has two notable bugs absent from 2.1.2: `init_sys()` called twice (exit codes 2 and 3) and `init_html()` called twice (both exit code 13). It also lacks the `WWW_TraceFlag` integration and the Bede McCall / MITRE `initUserWWW()` patch that appear in 2.1.2.
  - The `apps/` directory contains a rich set of Viola applications: `www.v` (43K, the browser), `www.org.v` (29K, possibly the original unmodified version), `vw.v` (40K), `doodle.v` (drawing widget), `paint.v`, `clock.v`, `shell.v` (terminal), `wais.v` (WAIS integration), `map.v`, `edit.v` and `ed_*.v` (editor components), `xcf.v`, `lurnix.v`, and `picture.v` (336K).
  - The `src/` directory includes a `stylesheet` file (947 bytes, 1992-06-04) — an early stylesheet artifact, and a `www/Implementation/` subdirectory containing the bundled W3 library.
  - Platform-specific Imakefiles: `Imakefile.decstation`, `Imakefile.sparc`, `Imakefile.org`.
- **Sources**
  - [Ancient Web Browsers: ViolaWWW](https://browsers.flanigan.us/browsers/violawww/)
  - (from surviving archives) ViolaWWW 2.1.0 source code (`Viola/old/src/main.c` in [`viola92src.tar`](https://browsers.flanigan.us/browsers/violawww/files/viola92src.tar))
  - [W3C: CERN-hosted ViolaWWW 2.1.0 source tree](https://www.w3.org/History/1995/WWW/Viola/old/src/)
  - [W3C: CERN-hosted ViolaWWW 2.1.0 apps directory](https://www.w3.org/History/1995/WWW/Viola/old/apps/)

### 1992-06-30 — “Next generation” architecture described (SGML/multi-object)

- **Evidence**
  - **Announcement**: WWW-Talk post dated 1992-06-30
- **What the source says**
  - A built-in hypertext editor was in development.
  - The “current” browser version described there used output from a standard SGML parser (`sgmls`).
  - The display model shifted from a single unstructured textfield to multiple structured objects (textfield/bitmap/etc).
  - The approach described was a rough 1–1 mapping of SGML document structure to Viola objects, with the intention to allow editing and conversion back to SGML.
  - A possible interim release (HTML-based) with bitmap display (XBM/XPM) was mentioned, alongside interoperability concerns.
- **Sources**
  - [WWW-Talk 1992: Hypertext editor (TBL)](http://1997.webhistory.org/www.lists/www-talk.1992/0127.html)
  - [WWW-Talk 1992: Re: Hypertext editor (Pei Wei)](http://1997.webhistory.org/www.lists/www-talk.1992/0128.html)

---

### 1992-07-14 to 1992-07-30 — Version 2.1.2 (archives [`viola920730.tar.Z`](https://browsers.flanigan.us/browsers/violawww/files/viola920730.tar.gz), `WWWViolaApps_920730.tar.Z`)

- **Evidence**
  - **Version string**: `Viola=2.1.2, date=July 14, 1992` (see `Viola/src/main.c` in [`viola92src.tar`](https://browsers.flanigan.us/browsers/violawww/files/viola92src.tar))
  - **Announcement**: 1992-07-15 on WWW-Talk
  - **README date**: 1992-07-27
  - **Archive snapshot**: 1992-07-30 ([`viola920730.tar.Z`](https://browsers.flanigan.us/browsers/violawww/files/viola920730.tar.gz), `WWWViolaApps_920730.tar.Z`)
  - **CERN status page**: lists current release `920730`, requires X11R4+, notes monochrome+colour support, and lists binaries for sun4/decstation/SGI (15-Jul-92)
  - **Archive artifact (920730 snapshot)**: `apps/www.v` Status list includes “July 14, 1992 — Upgrade with latest W3 library.”
- **What the 1992-07-15 announcement says (selected)**
  - Uses “the latest W3 library (extracted from the LineMode Browser 1.2h)”.
  - Binaries and sources were offered via Berkeley FTP (decstation, sparc, and a source archive).
  - Reliability and network behavior: “slightly evermore reliable” and “gentler … in regards to network traffic”.
  - Notes an open issue: the “font metrix problem” (“eating up lots of CPU doing nothing”).
- **Archive contents (selected, from surviving archives)**
  - The distribution README (dated 1992-07-27) describes building with `BUILD` and running via a `RUN` script which sets environment variables.
  - The README lists core ViolaWWW app files in the `apps` directory: `res.HTMLStyle.v`, `res.font.v`, `res.v`, `www.v`, `wwwHistory.v`, `wwwSrc.v` (and the snapshot also includes other `.v` files such as `hello.v`, `shell.v`, and `wais.v`).
  - The README notes that startup hangs may be due to a “Font Problem” (and suggests adjusting `apps/res.font.v`).
  - `Viola/apps/res.HTMLStyle.v` includes style entries for tags including `UL`, `DL`, `DIR`, `MENU`, `XMP`, `LISTING`, `ADDRESS`, and headers `H1`–`H7`.
- **CERN/W3-hosted source tree** (separate from the distribution archives above)
  - A patched working copy of ViolaWWW 2.1.2 source code survives on the W3C server at `/History/1995/WWW/Viola/sun4/` (with an `sgi/` subdirectory for SGI platform). The base files are dated 1992-07-15 (matching the 2.1.2 release), but several files carry later modification dates, indicating continued maintenance at CERN:
    - **1992-10-06 to 1992-10-15**: `BUILD`, `gram.c`, `scan.c` (parser regenerated), `main.c`, `HTFont.h`, `cl_TTY.c`, `cl_menu.c`, `html.c` — patches during the memory leak / stability period (see Oct–Nov 1992 entry below).
    - **1993-01-18 to 1993-03-16**: `DefaultStyles.c` (Viola-specific style additions: VObj, PMenu, XPM, XBM, Icon, PS), `Imakefile`, `Makefile`, `Version.make` — build and style updates during the "next release" preparation period.
    - **1994-06-23**: `Makefile-dec` and `viola` binary (1.1M) — a DEC platform build, indicating CERN was still compiling 2.1.2-based code as late as June 1994, while Pei Wei had already released version 3.1 Beta (March 1994).
  - The `main.c` in this tree includes a **patch by Bede McCall, MITRE Corp** (`initUserWWW()` function, which creates a `~/WWW` directory for the user). The same function exists in the repository's `src/viola/viola.c` (line 687), though the call is commented out in the later 3.x code.
  - The CERN status page at the parent URL (`/History/1995/WWW/Viola/`) states: *"Long pause and new releases appearing again. Now ('94) available for Motif or non-Motif X."*
- **Sources**
  - [WWW-Talk 1992: viola update (with latest W3 library)](http://1997.webhistory.org/www.lists/www-talk.1992/0152.html)
  - [W3.org History: `WWWViolaApps_920730.tar.Z`](https://www.w3.org/History/1992/WWWViolaApps_920730.tar.Z)
  - [CERN: Status of ViolaWWW](https://info.cern.ch/hypertext/WWW/Viola/Status.html)
  - [W3C: CERN-hosted ViolaWWW source tree (sun4)](https://www.w3.org/History/1995/WWW/Viola/sun4/)
  - [W3C: CERN-hosted ViolaWWW source tree (sgi)](https://www.w3.org/History/1995/WWW/Viola/sun4/sgi/)
  - [W3C: ViolaWWW Status page](https://www.w3.org/History/1995/WWW/Viola/)
  - [Ancient Web Browsers: ViolaWWW](https://browsers.flanigan.us/browsers/violawww/)
  - [Ancient Web Browsers: About/Status page screenshot](https://browsers.flanigan.us/browsers/violawww/img/Viola-2.1.0_notes.jpg)
  - [Archive: `viola92src.tar` (combined sources; includes `Viola/src/main.c` and `Viola/apps/res.HTMLStyle.v`)](https://browsers.flanigan.us/browsers/violawww/files/viola92src.tar)
  - [Archive snapshot: `viola920730.tar.gz` (includes `viola/README` dated “July 27, 1992” and `src/main.c` version string)](https://browsers.flanigan.us/browsers/violawww/files/viola920730.tar.gz)
  - (inside [`viola920730.tar.gz`](https://browsers.flanigan.us/browsers/violawww/files/viola920730.tar.gz)) `viola/README` (archive README; dated “July 27, 1992”)
  - (inside [`viola920730.tar.gz`](https://browsers.flanigan.us/browsers/violawww/files/viola920730.tar.gz)) `viola/apps/www.v` (“Overview, ViolaWWW” content with Status list)

### 1992 summer — Viola at Xerox PARC (secondary source)

- **Evidence**
  - **Secondary source**: Tim Berners-Lee, *Weaving the Web* (1999)
- **What the source says**
  - When Berners-Lee visited Xerox PARC in summer 1992, the lab was not using Viola because it had to be compiled with special code to work through PARC’s firewall. “The first thing I did on arrival was to do that” so the team could use the browser.
- **Source**
  - Tim Berners-Lee, *Weaving the Web* (HarperCollins, 1999), Ch. 5

### 1992-09 — Pei Wei joins O’Reilly & Associates (W3 News)

- **Evidence**
  - **Announcement (W3 News 9209)**: September 1992
- **Note**
  - This marks the start of O’Reilly-era work referenced in later WWW-Talk posts and in the 1994 beta announcements.
  - W3 News notes he had a “prototype W3 browser” with features including embedded graphics, scrollable lists, and generic SGML parsing, and adds: “we hope an editor will come out of that work.”
  - **Secondary source**: Tim Berners-Lee’s May 1992 CERN review of ViolaWWW already stated that Pei Wei was “finishing his degree at UC Berkeley” and “will be with O’Reilly Associates” — the O’Reilly arrangement was thus known before the September W3 News announcement.
- **Source**
  - [W3.org History: W3 News (September ’92)](https://www.w3.org/History/19921103-hypertext/hypertext/WWW/News/9209.html)
  - [CERN/W3: An updated quick look at ViolaWWW (May 1992)](https://info.cern.ch/hypertext/Viola/Review.html)

### 1992-10 to 1992-11 — Stability and rendering notes (memory leaks; scrollable regions)

- **Evidence**
  - **Announcement**: reports/discussion on WWW-Talk (Oct 1992) about memory leaks
  - **Announcement**: 1992-11-04 note about scrollable regions for `LISTING`
- **What the 1992-11-04 thread says (selected)**
  - Tim Berners-Lee noted that “Pei’s latest Viola” allowed a `LISTING` section to be viewed as an embedded scrollable region.
- **Sources**
  - [WWW-Talk 1992: “WWW/VIOLA ‘Memory leak’ ?”](http://1997.webhistory.org/www.lists/www-talk.1992/0204.html)
  - [WWW-Talk 1992: “HTML” (scrollable region mention)](http://1997.webhistory.org/www.lists/www-talk.1992/0266.html)

---

### Early 1993 — “Next release” preparation (leaks/resources; libwww 2.0-alpha; HMML discussion)

- **Evidence**
  - **Announcement**: discussions across early 1993 WWW-Talk threads
  - **Secondary note**: Internet World (1995) narrative about “generally available” in Jan 1993 (treated as non-primary dating)
- **Context (secondary source)**
  - Tim Berners-Lee (*Weaving the Web*, 1999) reports that David Thompson, a manager at NCSA, had downloaded Viola, got it running, and demonstrated its use with the CERN server to NCSA’s Software Design Group. It was after this demonstration that Marc Andreessen and Eric Bina decided to create a browser for X — which became Mosaic (first alpha released February 1993).
- **Selected details from the 1993 threads**
  - Memory leaks: reports describe ViolaWWW “leaking memory” over time; Pei Wei replied that many leaks were found (via Purify) and plugged in a working copy, including issues around piling up pixmaps/fonts affecting the X server.
  - WAIS results: Pei Wei noted that a version of ViolaWWW “forgets” the search result page after following a link; the suggested workaround was to clone the results page before navigating.
  - Applets (retrospective, author): a later WWW-Talk post (1995) recalls inline interactive “applets” existing in ViolaWWW around late 1992 / early 1993 (treated as secondary dating).
  - libwww 2.0-alpha: Tim Berners-Lee announced new 2.0-alpha compatible sources and described feature areas such as module registration (formats, protocols, suffix mappings) and HTML generation as well as parsing.
- **Sources**
  - [WWW-Talk 1993: viola/www memory leak (report)](http://1997.webhistory.org/www.lists/www-talk.1993q1/0128.html)
  - [WWW-Talk 1993: Re: viola/www memory leak (Pei Wei)](http://1997.webhistory.org/www.lists/www-talk.1993q1/0129.html)
  - [WWW-Talk 1993: WAIS search results (question)](http://1997.webhistory.org/www.lists/www-talk.1993q1/0240.html)
  - [WWW-Talk 1993: Re: WAIS search results (Pei Wei)](http://1997.webhistory.org/www.lists/www-talk.1993q1/0247.html)
  - [WWW-Talk 1993: libwww 2.0-alpha sources announcement](http://1997.webhistory.org/www.lists/www-talk.1993q1/0246.html)
  - [WWW-Talk 1995: Re: Java, Viola, and prior art (author retrospective; applets timeline)](http://1997.webhistory.org/www.lists/www-talk.1995q3/0437.html)
  - [Internet World (Apr 1995): “Webolution” (archived text; secondary)](https://archive.org/stream/InternetWorldV06N04/Internet_World_V06N04_djvu.txt)
  - Tim Berners-Lee, *Weaving the Web* (HarperCollins, 1999), Ch. 6 — NCSA / Viola demonstration (secondary)

### 1993-04-21 — HMML mentioned as an O’Reilly multimedia extension

- **Evidence**
  - **Announcement**: WWW-Talk post dated 1993-04-21 (Tim Berners-Lee)
- **What the source says (selected)**
  - HMML is described as “already an extension of HTML for multimedia from O’Reilly” (and similar extensions from NCSA were noted).
  - Mosaic and an “unreleased” O’Reilly Viola are cited as handling embedded images in hypertext.
  - In the WWW context, embedded-image tags refer to a W3 address and the retrieval code negotiates a suitable transfer representation independently of the embedding document.
- **Source**
  - [WWW-Talk 1993: HTML, HMML, and HyperTeX (TBL)](http://1997.webhistory.org/www.lists/www-talk.1993q2/0129.html)

### 1993-05-08 — Applets demonstration (date appears in later WWW-Talk post; treat as secondary)

- **Evidence**
  - **Secondary source**: a 1995 WWW-Talk post recounts a May 8, 1993 demonstration at O’Reilly
- **Source**
  - [WWW-Talk 1995: Re: Java, Viola, and prior art](http://1997.webhistory.org/www.lists/www-talk.1995q3/0437.html)

### 1993-05-25 — HMML DTD discussion and “HTML+” mention

- **Evidence**
  - **Announcement**: WWW-Talk post dated 1993-05-25 (Dave Raggett)
- **What the source says (selected)**
  - Raggett notes that “HMML” was an internal experimental DTD developed by Pei Wei, and that the term later became confusing when it was also used for a proposed replacement HTML DTD; he uses the name “HTML+” to avoid ambiguity.
- **Source**
  - [WWW-Talk 1993: Re HMML? (D. Raggett)](https://ksi.cpsc.ucalgary.ca/archives/WWW-TALK/www-talk-1993q2.messages/383.html)
  - [WWW-Talk 1993: Re: RE dtd2.html (HMML naming confusion; “HTML+”)](http://1997.webhistory.org/www.lists/www-talk.1993q2/0393.html)

### 1993-05-28 — `<FIGURE>` proposal in HMML (“working version”)

- **Evidence**
  - **Announcement**: WWW-Talk post dated 1993-05-28 (Pei Wei)
- **Source**
  - [WWW-Talk 1993: Proposal for FIGURE tag (Pei Wei)](https://ksi.cpsc.ucalgary.ca/archives/WWW-TALK/www-talk-1993q2.messages/409.html)

### 1993-08 — First Web Conference demonstrations (date appears in later WWW-Talk post; treat as secondary)

- **Evidence**
  - **Secondary source**: 1995 WWW-Talk post describes demos at the first Web Conference (August 1993)
- **Source**
  - [WWW-Talk 1995: Re: Java, Viola, and prior art](http://1997.webhistory.org/www.lists/www-talk.1995q3/0437.html)

### 1993-09-04 — HTML forms discussion (URL query syntax)

- **Evidence**
  - **Announcement**: WWW-Talk post dated 1993-09-04
- **Source**
  - [WWW-Talk 1993: Submitting input-form data to server](http://1997.webhistory.org/www.lists/www-talk.1993q3/0810.html)
  - [WWW-Talk 1993: Submitting input-form data to server (reply; URL query syntax details)](http://1997.webhistory.org/www.lists/www-talk.1993q3/0812.html)

### 1993-10-22 — STG “stylesheet language” posted (prototype in Viola)

- **Evidence**
  - **Announcement**: WWW-Talk post dated 1993-10-22 (Pei Wei)
- **Source**
  - [WWW-Talk 1993: Stylesheet Language (Pei Y. Wei)](http://1997.webhistory.org/www.lists/www-talk.1993q4/0264.html)
  - [WWW-Talk 1993: Stylesheet Language (continuation; derived behavior and `<LINK REL=\"STYLE\">`)](http://1997.webhistory.org/www.lists/www-talk.1993q4/0265.html)

### Circa 1993 — About/Status screenshot (use only the dated “Status” list items)

- **Evidence**
  - **Artifact**: archived viola.org home page includes a “circa 1993” screenshot of the About/Status page
- **What we use it for (and what we do not)**
  - We treat only the screenshot’s **Status list** entries as dated claims:
    - “April 1993: Alpha release…”
    - “May 10, 1992: Beta release…”
    - “March 9 to April 20, 1992: Releases to the WWW people at CERN for tests.”
- **Source**
  - [Viola home page (archived)](https://web.archive.org/web/20180203005145/http://www.viola.org/)

---

### 1994-01 — FIGA support (rectangular image maps)

- **Evidence**
  - **Announcement**: WWW-Talk post dated January 1994
- **Source**
  - [WWW-Talk 1994: FIGA support](http://1997.webhistory.org/www.lists/www-talk.1994q1/0020.html)

### 1994-02-23 to 1994-02-25 — Version 3.0 Beta

- **Evidence**
  - **README date**: 1994-02-23
  - **Announcement**: 1994-02-25 (WWW-Talk)
- **Selected details from the announcement/README excerpt**
  - Notable features listed in the post include:
    - HTML+ support (container paragraphs, input forms, tables; not yet exact/complete compliance).
    - Additional extensions (e.g., column formatting and document insertion, client-side).
    - Embeddable programmable Viola objects (in-document and in-toolbar).
    - Motif front-end; X11 (non-Motif) version also available.
    - Single-binary installation (compared to older multi-file setups).
  - Build note: `BUILD` generates two binaries: `viola/src/viola/viola` and `viola/src/vw/vw`; recommendation to use `vw` as the more polished front-end at that time.
  - Requirements: X11R5; Motif toolkit library for the Motif front-end.
  - Networking library note: the included libwww “comes with ViolaWWW” and is modified; do not use an external libwww until changes are integrated upstream.
  - Contact and acknowledgements are included in the announcement.
- **Source**
  - [WWW-Talk 1994: “ViolaWWW beta release is available”](http://1997.webhistory.org/www.lists/www-talk.1994q1/0716.html)

### 1994-03-23 to 1994-03-24 — Version 3.1 Beta

- **Evidence**
  - **README date**: 1994-03-23
  - **Announcement**: 1994-03-24 (WWW-Talk)
- **Selected details (from announcement and preserved change notes)**
  - Release note: “Another beta release of Viola is now available… Aside from the numerous bug fixes, its got a working prototype of the collapsible/expandable :-)”
  - The `FOLD` attribute proposal suggests a foldable list attribute (with initial fold state) and a `LABEL` attribute to describe folded content.
  - Follow-up discussion (WWW-Talk) explains why attributes were preferred over a new enclosing folding tag, and notes that ViolaWWW already had a client-side `<INCLUDE>` tag (and discusses foldable/delayable includes).
  - The repository’s `src/vw/changes` file (from the 1994-era `vw` code) records UI/performance-focused changes such as:
    - Help hook for sending messages to `vw`’s active help field (e.g., HTTP progress reports).
    - Toolbar frame under the menu bar; navigation actions moved to toolbar icons.
    - Navigation icons mentioned include: “BackUp”, “Previous”, “Next”, “Show Source”, “Clone Page”.
    - Support for user/document-defined tools tiled from the left side of the toolbar.
    - Improved window title handling, including automatic font scaling for long titles.
    - Improved messaging between Motif front-end and Viola (string-based → object-pointer-based), improving scrolling speed.
    - History mechanism fixes; busy/idle cursor indicators.
- **Selected details from the 3.1 README in the distribution archive**
  - “ViolaWWW, Version 3.1 Beta … Mar 23 1994” (README header).
  - Availability: “Source and binary can be found in `ftp://ora.com/pub/www/viola`.” A Sparc binary was supplied.
  - Contact: “You can send mail to `viola@ora.com` … bug reports, patches, constructive criticisms…”
  - Platform/build: “I’d appreciate hearing about compilation success stories (and patches) for platforms other than SunOS and Ultrix.”
  - Packaging note: Motif front-end; an X11 (non-Motif) version was also available; described as a single-binary installation (compared to older multi-file setups).
  - Requirements note: Viola requires X11R5; Motif version requires a Motif toolkit library; libwww bundled with ViolaWWW is modified.
- **Archive source code contents (earliest surviving implementation of FOSI and STG)**
  - The [`viola940323.tar.gz`](https://browsers.flanigan.us/browsers/violawww/files/viola940323.tar.gz) archive is the **earliest surviving source code** that contains both FOSI and STG support. Neither FOSI nor STG appears in any earlier surviving archives ([`viola-2.0.4.tar`](https://browsers.flanigan.us/browsers/violawww/files/viola-2.0.4.tar) / v2.0.4, [`viola92src.tar`](https://browsers.flanigan.us/browsers/violawww/files/viola92src.tar) / v2.1.0, [`viola920730.tar.gz`](https://browsers.flanigan.us/browsers/violawww/files/viola920730.tar.gz) / v2.1.2).
  - **FOSI files**: `src/libWWW/Library/Implementation/FOSI.c`, `FOSI.h`, `FOSIDTD.c`, `FOSIDTD.h` (SGML parser infrastructure for FOSI DTD), and `src/viola/fosi.c` (Viola callback stubs for FOSI events).
  - **STG files**: `src/libStyle/libstg.c`, `libstg.h` (standalone stylesheet parsing library with `STGMajor`/`STGMinor`/`STGAssert` structures), and `src/viola/stgcall.c`, `stgcall.h` (Viola integration for STG lookups). The `sgml/styles/` directory contains `.stg` stylesheet files (e.g., `hmml.stg`, `HMML_default.stg`, `test.stg`) — tree-structured stylesheets with properties such as `fontSize`, `FGColor`, `BGColor`, `fontSlant`.
  - **Note**: The STG "Stylesheet Language" was first publicly discussed on [October 22, 1993](http://1997.webhistory.org/www.lists/www-talk.1993q4/0264.html), and FOSI support dates from the same development period (late 1993 to early 1994). See [STG_REFERENCE.md](STG_REFERENCE.md) and [FOSI_REFERENCE.md](FOSI_REFERENCE.md) for detailed documentation.
- **Sources**
  - [WWW-Talk 1994: ViolaWWW Release (3.1 beta)](http://1997.webhistory.org/www.lists/www-talk.1994q1/1031.html)
  - [WWW-Talk 1994: FOLD attribute proposal](http://1997.webhistory.org/www.lists/www-talk.1994q1/1027.html)
  - [WWW-Talk 1994: Re: folding elements (attributes vs tag; `<INCLUDE>`)](http://1997.webhistory.org/www.lists/www-talk.1994q1/1045.html)
  - [Ancient Web Browsers: ViolaWWW (secondary index; links to release posts)](https://browsers.flanigan.us/browsers/violawww/)
  - [Archive: `viola940323.tar.gz` (contains `viola940323/README` and `viola940323/README.RUN`)](https://browsers.flanigan.us/browsers/violawww/files/viola940323.tar.gz)
  - `src/vw/changes` (repository file)

### 1994-04-19 — SIGWEB panel at SLAC with Andreessen, Altis, Johnson, and Wei

- **Evidence**
  - **Announcement**: Usenet (ba.seminars), 1994-04-12, posted by Dave Lewis (SIGWEB meeting coordinator)
- **What the source says**
  - A SIGWEB panel discussion “Desktop Interfaces to Information Sources on the Internet: Perspectives from World Wide Web client interface developers” was held on April 19, 1994, 2:00–5:00 p.m. at the SLAC Auditorium (Stanford Linear Accelerator Center, 2575 Sand Hill Road, Menlo Park, CA).
  - Panelists:
    - Kevin Altis, Intel — creator of the Proxy Server
    - Marc Andreessen, Enterprise Integration Technologies — creator of Mosaic
    - Tony Johnson, Stanford Linear Accelerator Center — creator of MidasWWW
    - Pei Wei, O’Reilly & Associates — creator of violaWWW
  - Moderator: Bebo White, SLAC.
- **Note**
  - SIGWEB was an organization founded at the end of 1993 by Chris McRae (O’Reilly & Associates) to facilitate communication between practitioners of Networked Information Delivery and Retrieval (NIDR) in the Bay Area, with several hundred participants at its monthly events.
  - This panel places Pei Wei alongside Marc Andreessen — five months before the September 1994 Stanford WWW Workshop where Wei also spoke.
- **Source**
  - [Google Groups: ba.seminars — April 19th SIGWEB meeting announcement](https://groups.google.com/g/ba.seminars/c/gJDV-Owoo_A/m/4FAf_oQMAH4J)

### 1994-05-18 to 1994-05-20 — Cross-platform testing initiative

- **Evidence**
  - **Announcement**: May 1994 WWW-Talk posts about platform testing accounts and status
- **Selected details from the threads**
  - Pei Wei requested guest testing accounts (e.g., AIX R6000, DEC Alpha, HP “Snake”, SGI) to validate portability and provide updated executables.
  - In an HTML conformance thread, ViolaWWW was described as “the most 'featureful' browser” and “real close to 100% HTML+ conformance” (claims by a participant; not a formal conformance report).
  - Discussion included interest in multi-threaded libwww / “multiple independent … HTTP operations” to allow interacting with one page while another loads.
- **Sources**
  - [WWW-Talk 1994: testing accounts request](http://1997.webhistory.org/www.lists/www-talk.1994q2/0597.html)
  - [WWW-Talk 1994: thanks for testing accounts](http://1997.webhistory.org/www.lists/www-talk.1994q2/0626.html)
  - [WWW-Talk 1994: ViolaWWW status](http://1997.webhistory.org/www.lists/www-talk.1994q2/0271.html)
  - [WWW-Talk 1994: multithreaded libwww inquiry](http://1997.webhistory.org/www.lists/www-talk.1994q2/0519.html)
  - [WWW-Talk 1994: multiple HTTP operations](http://1997.webhistory.org/www.lists/www-talk.1994q2/0542.html)

### 1994-09-20 to 1994-09-21 — Pei Wei speaks on "Browsers" at Stanford WWW Workshop

- **Evidence**
  - **Primary source**: Stanford WWW Workshop program (Stanford Computer Forum, September 20–21, 1994)
- **What the source says**
  - Pei Wei is listed as a speaker in **Session 2: Browsers and presentation**, with the topic **"Browsers"** and affiliation "O'Reilly Associates - wei@ora.com (author of Viola)".
  - Other speakers in the same session included Steve Zilles (Adobe, "Page Layout and portability"), Ev Shafrir (Hewlett-Packard, "A Visual Design Perspective"), and Tom Gruber (Stanford, "Virtual documents on the web").
  - The workshop also featured Larry Masinter (Xerox PARC), Brewster Kahle (WAIS Inc), Terry Winograd (Stanford), Allan Schiffman (EIT), and Hector Garcia-Molina (Stanford) in other sessions.
- **Note**
  - This confirms that Wei was still recognized as a leading authority on web browsers in September 1994, during the period between the ViolaWWW 3.1 Beta (March 1994) and the Stylesheet RFC re-publication (October 1994).
- **Source**
  - [Stanford WWW Workshop program (archived)](https://www.krsaborio.net/internet/research/1994/0920-b.htm)

### 1994-10-24 to 1994-10-25 — Stylesheet RFC re-published (WWW-Talk)

- **Evidence**
  - **Announcement**: 1994-10-24 — first re-posting of Stylesheet RFC (with commentary on cascading, context sensitivity, minor selectors)
  - **Announcement**: 1994-10-25 — follow-up mentioning “Stylesheet RFC, Oct 23 1993”, library implementation, and Håkon Lie’s CSS proposal
- **Note**
  - Same evidence and dates as in [STG_REFERENCE.md](STG_REFERENCE.md) (WWW-Talk archive message dates).
- **Sources**
  - [WWW-Talk 1994: Stylesheet Language](http://1997.webhistory.org/www.lists/www-talk.1994q4/0387.html) (Oct 24)
  - [WWW-Talk 1994: Stylesheet RFC](http://1997.webhistory.org/www.lists/www-talk.1994q4/0401.html) (Oct 25)

### 1995-03-29 — W3C Clients page lists ViolaWWW as unsupported

- **Evidence**
  - **Archive snapshot**: W3C page “World Wide Web Client Software products” ([Clients.html](https://web.archive.org/web/20100616002711id_/http://www.w3.org/Clients.html)) states “This information has not been updated since 29 March 1995” and “Last updated 29 March 1995”.
  - Under X-Windows, ViolaWWW is listed as: *“ViolaWWW” Browser for X11 — Browser for X11. (Beta, unsupported).*
- **Note**
  - By this date the official W3C client list already marked ViolaWWW as unsupported; the final known release (3.3 Beta) was announced in April 1995.
- **Source**
  - [W3C Clients (archived 2010; page last updated 29 March 1995)](https://web.archive.org/web/20100616002711id_/http://www.w3.org/Clients.html)

---

### 1995-04-10 to 1995-04-17 — Version 3.3 Beta (final known release)

- **Evidence**
  - **Date in post**: 1995-04-10 (release text)
  - **Announcement**: 1995-04-17 (WWW-Talk listing header / archive)
- **Selected details from the announcement**
  - Described as “fundamentally HTML 3.0 … plus many extensions” (multi-column formatting, document insertion, collapsible/expandable lists).
  - Sidebar panel for meta-information or intra-document navigation links.
  - Dynamic toolbar with document-engaged tool applets.
  - Rudimentary stylesheet mechanism for fonts/colors/alignments.
  - Viola scripting language accessible from HTML for interactive scripts/applets.
  - “Miscellaneous niceties” mentioned include a hotlist and HTTP loading progress displayed as a pie chart (when information is available).
  - Described as an experimental platform; source available; much of the browser constructed in a high-level scripting language; customization emphasized.
  - Motif front-end plus an X11 (non-Motif) version; self-contained single binary installation.
- **Availability (from the release post)**
  - “Source and binary can be found in `ftp://ftp.ora.com/pub/www/viola`.”
  - “Platform: Unix/XWindows.” A Sparc binary is supplied.
- **Source**
  - [WWW-Talk 1995: Release of ViolaWWW 3.3](http://1997.webhistory.org/www.lists/www-talk.1995q2/0128.html)
  - [Ancient Web Browsers: ViolaWWW (secondary index; links to release posts)](https://browsers.flanigan.us/browsers/violawww/)

### 1996-01-23 — DEC Alpha (OSF/1) compilation attempt (Usenet report)

- **Evidence**
  - **Announcement**: Usenet (comp.infosystems.www.browsers.x), 1996-01-23, Message-ID `<4e57tg$iae@ftp.univie.ac.at>`
- **What the source says**
  - Andreas Ulovec (Institute for Mathematics, University of Vienna) reported attempting to compile ViolaWWW on a DEC Alpha running OSF/1. He encountered compilation errors, partially fixed them, but the resulting binary produced runtime errors. He asked whether precompiled binaries were available or whether anyone had successfully built ViolaWWW on DEC Alpha.
- **Note**
  - This is the latest known evidence of someone actively trying to use ViolaWWW — approximately 9 months after the final known release (3.3 Beta, April 1995).
  - DEC Alpha was a 64-bit platform; the compilation and runtime errors described are consistent with 32-bit to 64-bit portability issues (pointer size, integer width, etc.) — the same class of problems addressed by the 2025 revival of this project.
- **Source**
  - [Usenet Archives: comp.infosystems.www.browsers.x (Jan 1996)](https://usenetarchives.com/view.php?id=comp.infosystems.www.browsers.x&mid=PDRlNTd0ZyRpYWVAZnRwLnVuaXZpZS5hYy5hdD4)

---

## ViolaWWW 4.0 (Modern Era)

### 2025-10-17 — Project revival (this repository)

- **Evidence**
  - Repository history (project-level; not an external historical source)
- **Note**
  - Revival work began with porting the codebase to 64-bit systems and continuing restoration based on archived materials and the codebase itself.
- **Attribution**
  - **Developer**: Evgeny Stepanischev

---

## Version summary (high-level)

| Date / Range | Version | Notes (evidence-driven) |
|---|---:|---|
| pre-1991-04-25 | Viola 0.5 | Version number cited in two independent Usenet reposts |
| 1991-04-23 | Viola 0.8 | Usenet announcement (pre-WWW); README archived Apr 25 |
| 1991-12-09 to 1991-12-13 | — | “One-night hack” announcements on WWW-Talk |
| Early 1992-01 | — | Demonstration observed (W3 News 9201) |
| 1992-01-24 | — | CERN test report (WWW-Talk) |
| 1992-03-09 to 1992-04-20 | 2.0.x | CERN testing window (multiple sources; includes 2.0.4 by 1992-04-04) |
| 1992-05-10 to 1992-05-15 | — | Beta phase (JENC3 demo; README/review dates) |
| 1992-05-21 | — | Embedded Viola scripts (“program links”) discussed (WWW-Talk) |
| 1992-05-23 | 2.1.0 | Version string date |
| 1992-06-30 | — | Next-generation architecture described (WWW-Talk) |
| 1992-07-14 to 1992-07-30 | 2.1.2 | Version string / announcement / archives / CERN status |
| 1992-09 | — | O’Reilly join announcement (W3 News) |
| 1992-10 to 1992-11 | — | Memory leak and scrollable region discussions |
| Early 1993 | — | “Next release” preparation threads; some secondary dating exists |
| 1993-04-21 | — | HMML mention (WWW-Talk) |
| 1993-05-08 | — | Applets demonstration (secondary source) |
| 1993-05-25 | — | HMML DTD / “HTML+” mention (WWW-Talk) |
| 1993-05-28 | — | `<FIGURE>` proposal in HMML (WWW-Talk) |
| 1993-08 | — | First Web Conference demonstrations (secondary source) |
| 1993-09-04 | — | HTML forms discussion (WWW-Talk) |
| 1993-10-22 | — | STG stylesheet language post (WWW-Talk) |
| Circa 1993 | — | About/Status screenshot (artifact; Status list entries only) |
| 1994-01 | — | FIGA support (WWW-Talk) |
| 1994-02-23 to 1994-02-25 | 3.0 Beta | README date + announcement |
| 1994-03-23 to 1994-03-24 | 3.1 Beta | README date + announcement |
| 1994-04-19 | — | SIGWEB panel at SLAC (Wei, Andreessen, Altis, Johnson) |
| 1994-09-20 to 1994-09-21 | — | Pei Wei speaks on "Browsers" at Stanford WWW Workshop |
| 1994-10-24 to 1994-10-25 | — | Stylesheet RFC re-published (WWW-Talk) |
| 1995-03-29 | — | W3C Clients page lists ViolaWWW as (Beta, unsupported) |
| 1995-04-10 to 1995-04-17 | 3.3 Beta | Final known release |
| 1996-01-23 | — | DEC Alpha (OSF/1) compilation attempt reported (Usenet) |
| 2025-10-17 | 4.0 (revival) | Project revival in this repo |

---

## References (selected)

This list is intentionally non-exhaustive; entries above should cite the primary source directly.

- [Ancient Web Browsers: ViolaWWW](https://browsers.flanigan.us/browsers/violawww/)
- [Ancient Web Browsers: ViolaWWW About/Status screenshot](https://browsers.flanigan.us/browsers/violawww/img/Viola-2.1.0_notes.jpg)
- [W3.org History: www-talk archive 1991–1992](https://www.w3.org/History/1992/www-talk.archive.Z)
- [W3.org History: www-talk archive Jan–Jun 1993](https://www.w3.org/History/1992/www-talk.9301-9306.Z)
- [W3C: CERN-hosted ViolaWWW source tree and status page](https://www.w3.org/History/1995/WWW/Viola/)
- [W3C Clients (archived; page last updated 29 March 1995)](https://web.archive.org/web/20100616002711id_/http://www.w3.org/Clients.html)

*Last updated: February 2026*
