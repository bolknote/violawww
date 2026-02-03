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

### 1991-04-23 — Viola preview release (pre-WWW)

- **Evidence**
  - **Announcement**: Usenet (comp.windows.x), Message-ID `<9104231058.AA27453@scam.Berkeley.EDU>`
  - Mentions anonymous FTP availability on `scam.berkeley.edu`
- **What the source says**
  - First public announcement of the Viola system (before WWW support). Described as a “highly manipulable interactive-media authoring tool for UNIX/X11”.
- **Source**
  - [Usenet Archives: Viola announcement (Apr 1991)](https://www.usenetarchives.com/view.php?id=comp.windows.x&mid=PDkxMDQyMzEwNTguQUEyNzQ1M0BzY2FtLkJlcmtlbGV5LkVEVT4)

### 1991 — Viola 0.8 (date uncertain)

- **Evidence**
  - **Retrospective (author statement)**: “first version of viola (0.8) released in 1991”
- **Note**
  - This confirms the **year (1991)** as stated by the author, but does not provide an exact release date or an original announcement/packaging timestamp.
- **Source**
  - [Olde Viola Montage (archived; author retrospective note)](https://web.archive.org/web/19990830034431id_/http://viola.org/vintage/montage.html)

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
  - **Version string (known by 1992-04-04)**: `Viola=2.0.4, date=April 4, 1992` (from surviving source; see `ViolaWWW_920515/src/main.c` in `viola-2.0.4.tar`)
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
  - Tested on a NeXT with CubeX (grayscale and color versions).
  - Multifont text display; links highlighted with “button” boxes (single-click jump).
  - “Home”, “Back” and “Forward” buttons are listed among features.
  - Single-window operation with a “clone” facility; bookmark facility; online help buttons.
  - Remote index searching via a bottom input field; source viewer for HTML markup.
  - Navigation behavior at that time: “Up” acted like a destructive Back; “Left/Right” traversed history non-destructively.
  - “Fuzzy clicking”: clicking near a button could trigger the action.
  - Performance commentary: multifont version slower than an older monofont “1.0” reference; reviewer considered multifont worth the trade-off.
  - UI note: window looked “a little cluttered”; suggestion to move the “ViolaWWW” title to the window title bar.
  - Formatting note: the `LI` list style was described as too close to normal text; reviewer suggested indentation and whitespace between list elements.
  - Ease-of-use note: installation described as (binary + Viola scripts directory + shell script setting an environment variable), and starting the program by typing `vw` (default home page).
  - “Bells and whistles”: three small icons after the index search field (history, print, and source viewer); history and print were described as close to working at that time.
  - Clone UI detail: the clone button icon is described as “tearing a sheet off a pad”; clone windows were described as intentionally uncluttered (few/no buttons) while links opened in the master window.
- **Known issues reported in early 1992 testing notes**
  - Stability: reviewer noted crashes when closing a clone window or the main window.
  - UI: scroll bar and left-side icon buttons sometimes did not appear; resizing the window vertically made them reappear.
  - Color: a “minor bug” was reported to crash the program on color screens; “crashes on first jump” on a color display was also noted.
  - Documentation: reviewer noted there “isn't much documentation on the product.”
- **Sources**
  - [WWW-Talk 1992: “problem yacc’ing violaWWW”](http://1997.webhistory.org/www.lists/www-talk.1992/0035.html)
  - [W3.org: “A quick look at ViolaWWW” (1992-04-11)](https://www.w3.org/History/19921103-hypertext/hypertext/Viola/Review_0.html)
  - [W3.org History: “Spring releases” (April 1992)](https://www.w3.org/History/19921103-hypertext/hypertext/WWW/News/9204.html)
  - [Ancient Web Browsers: ViolaWWW](https://browsers.flanigan.us/browsers/violawww/)
  - [Ancient Web Browsers: About/Status page screenshot](https://browsers.flanigan.us/browsers/violawww/img/Viola-2.1.0_notes.jpg)
  - [Archive: `viola-2.0.4.tar` (contains `ViolaWWW_920515/src/main.c` version string)](https://browsers.flanigan.us/browsers/violawww/files/viola-2.0.4.tar)
  - [Archive snapshot: `viola920730.tar.gz` (contains `apps/www.v` “Overview, ViolaWWW”)](https://browsers.flanigan.us/browsers/violawww/files/viola920730.tar.gz)
  - [Viola home page (archived; retrospective note “first released around April 1992”)](https://web.archive.org/web/20180203005145/http://www.viola.org/)

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
  - Multifont support; “clone” facility; bookmarks and history list.
  - “Home”, “Back” and “Forward” buttons are listed among features.
  - Index search facility (bottom input field) and bottom-row icons for History/Printing/Source Viewer.
  - Hidden documentation (e.g., globe icon for Viola docs; question-mark icon for help).
  - Help caching behavior: local copies preferred; remote help cached in `/usr/tmp`.
  - Cut-and-paste was noted as not working yet (selection could be made and shown underlined).
  - “Font hang” mentioned as a possible startup issue on some systems (example: OpenWindows).
  - Formatting note: the `LI` list style was described as too close to normal text; reviewer suggested indentation and whitespace between list elements.
  - Clone UI detail: the clone button icon is described as “tearing a sheet off a pad”; clone windows were described as intentionally uncluttered (few/no buttons) while links opened in the master window.
  - Platform note: the updated review mentions it had been run on Sun4 and DECstation (in addition to NeXT used for testing).
  - Reviewer conclusion (from the April/May reviews): “A very neat browser … very intuitive and straightforward…”
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
- **Source**
  - [WWW-Talk 1992: Re: World Wide Web and Viola](http://1997.webhistory.org/www.lists/www-talk.1992/0064.html)

### 1992-05-23 — Version 2.1.0

- **Evidence**
  - **Version string**: `Viola=2.1.0, date=May 23, 1992` (from surviving source)
- **Note**
  - Described as an early public release with sources and binaries for multiple platforms.
- **Sources**
  - [Ancient Web Browsers: ViolaWWW](https://browsers.flanigan.us/browsers/violawww/)
  - (from surviving archives) ViolaWWW 2.1.0 source code (`Viola/old/src/main.c` in `viola92src.tar`)

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

### 1992-07-14 to 1992-07-30 — Version 2.1.2 (archives `viola920730.tar.Z`, `WWWViolaApps_920730.tar.Z`)

- **Evidence**
  - **Version string**: `Viola=2.1.2, date=July 14, 1992` (see `Viola/src/main.c` in `viola92src.tar`)
  - **Announcement**: 1992-07-15 on WWW-Talk
  - **README date**: 1992-07-27
  - **Archive snapshot**: 1992-07-30 (`viola920730.tar.Z`, `WWWViolaApps_920730.tar.Z`)
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
- **Sources**
  - [WWW-Talk 1992: viola update (with latest W3 library)](http://1997.webhistory.org/www.lists/www-talk.1992/0152.html)
  - [W3.org History: `WWWViolaApps_920730.tar.Z`](https://www.w3.org/History/1992/WWWViolaApps_920730.tar.Z)
  - [CERN: Status of ViolaWWW](https://info.cern.ch/hypertext/WWW/Viola/Status.html)
  - [Ancient Web Browsers: ViolaWWW](https://browsers.flanigan.us/browsers/violawww/)
  - [Ancient Web Browsers: About/Status page screenshot](https://browsers.flanigan.us/browsers/violawww/img/Viola-2.1.0_notes.jpg)
  - [Archive: `viola92src.tar` (combined sources; includes `Viola/src/main.c` and `Viola/apps/res.HTMLStyle.v`)](https://browsers.flanigan.us/browsers/violawww/files/viola92src.tar)
  - [Archive snapshot: `viola920730.tar.gz` (includes `viola/README` dated “July 27, 1992” and `src/main.c` version string)](https://browsers.flanigan.us/browsers/violawww/files/viola920730.tar.gz)
  - `tmp/viola920730/viola/README` (archive README; dated “July 27, 1992”)
  - `tmp/viola920730/viola/apps/www.v` (“Overview, ViolaWWW” content with Status list)

### 1992-09 — Pei Wei joins O’Reilly & Associates (W3 News)

- **Evidence**
  - **Announcement (W3 News 9209)**: September 1992
- **Note**
  - This marks the start of O’Reilly-era work referenced in later WWW-Talk posts and in the 1994 beta announcements.
  - W3 News notes he had a “prototype W3 browser” with features including embedded graphics, scrollable lists, and generic SGML parsing, and adds: “we hope an editor will come out of that work.”
- **Source**
  - [W3.org History: W3 News (September ’92)](https://www.w3.org/History/19921103-hypertext/hypertext/WWW/News/9209.html)

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

### 1993-04-21 — HMML mentioned as an O’Reilly multimedia extension

- **Evidence**
  - **Announcement**: WWW-Talk post dated 1993-04-21 (Tim Berners-Lee)
- **Source**
  - [WWW-Talk 1993: HTML, HMML, and HyperTeX (TBL)](https://ksi.cpsc.ucalgary.ca/archives/WWW-TALK/www-talk-1993q2.messages/127.html)

### 1993-05-08 — Applets demonstration (date appears in later WWW-Talk post; treat as secondary)

- **Evidence**
  - **Secondary source**: a 1995 WWW-Talk post recounts a May 8, 1993 demonstration at O’Reilly
- **Source**
  - [WWW-Talk 1995: Re: Java, Viola, and prior art](http://1997.webhistory.org/www.lists/www-talk.1995q3/0437.html)

### 1993-05-25 — HMML DTD discussion and “HTML+” mention

- **Evidence**
  - **Announcement**: WWW-Talk post dated 1993-05-25 (Dave Raggett)
- **Source**
  - [WWW-Talk 1993: Re HMML? (D. Raggett)](https://ksi.cpsc.ucalgary.ca/archives/WWW-TALK/www-talk-1993q2.messages/383.html)

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

### 1993-09-04 — HTML forms discussion (URL query syntax)

- **Evidence**
  - **Announcement**: WWW-Talk post dated 1993-09-04
- **Source**
  - [WWW-Talk 1993: Submitting input-form data to server](http://1997.webhistory.org/www.lists/www-talk.1993q3/0810.html)

### 1993-10-22 — STG “stylesheet language” posted (prototype in Viola)

- **Evidence**
  - **Announcement**: WWW-Talk post dated 1993-10-22 (Pei Wei)
- **Source**
  - [WWW-Talk 1993: Stylesheet Language (Pei Y. Wei)](http://1997.webhistory.org/www.lists/www-talk.1993q4/0264.html)

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
- **Sources**
  - [WWW-Talk 1994: ViolaWWW Release (3.1 beta)](http://1997.webhistory.org/www.lists/www-talk.1994q1/1031.html)
  - [WWW-Talk 1994: FOLD attribute proposal](http://1997.webhistory.org/www.lists/www-talk.1994q1/1027.html)
  - [Ancient Web Browsers: ViolaWWW (secondary index; links to release posts)](https://browsers.flanigan.us/browsers/violawww/)
  - [Archive: `viola940323.tar.gz` (contains `viola940323/README` and `viola940323/README.RUN`)](https://browsers.flanigan.us/browsers/violawww/files/viola940323.tar.gz)
  - `src/vw/changes` (repository file)

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

### 1994-10 — Stylesheet RFC re-published

- **Evidence**
  - **Announcement**: WWW-Talk posts in October 1994
- **Sources**
  - [WWW-Talk 1994: Stylesheet RFC](http://1997.webhistory.org/www.lists/www-talk.1994q4/0401.html)
  - [WWW-Talk 1994: Stylesheet Language](http://1997.webhistory.org/www.lists/www-talk.1994q4/0387.html)

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
| 1991-04-23 | Viola Preview | Usenet announcement (pre-WWW) |
| 1991 | Viola 0.8 | Secondary source; exact date unclear |
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
| 1993-10-22 | — | STG stylesheet language post (WWW-Talk) |
| 1994-01 | — | FIGA support (WWW-Talk) |
| 1994-02-23 to 1994-02-25 | 3.0 Beta | README date + announcement |
| 1994-03-23 to 1994-03-24 | 3.1 Beta | README date + announcement |
| 1994-10 | — | Stylesheet RFC re-published |
| 1995-04-10 to 1995-04-17 | 3.3 Beta | Final known release |
| 2025-10-17 | 4.0 (revival) | Project revival in this repo |

---

## References (selected)

This list is intentionally non-exhaustive; entries above should cite the primary source directly.

- [Ancient Web Browsers: ViolaWWW](https://browsers.flanigan.us/browsers/violawww/)
- [Ancient Web Browsers: ViolaWWW About/Status screenshot](https://browsers.flanigan.us/browsers/violawww/img/Viola-2.1.0_notes.jpg)
- [W3.org History: www-talk archive 1991–1992](https://www.w3.org/History/1992/www-talk.archive.Z)
- [W3.org History: www-talk archive Jan–Jun 1993](https://www.w3.org/History/1992/www-talk.9301-9306.Z)

*Last updated: February 2026*
