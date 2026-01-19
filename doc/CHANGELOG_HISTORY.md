# ViolaWWW Release History

> This document compiles the release history of ViolaWWW based on historical sources, announcements, and archived materials.

**Conventions used below**:
- **Announcement**: date of a public mailing list / Usenet post.
- **README date**: the date stated inside a distributed README (often reflects packaging time, not necessarily the first public announcement).
- **Archive snapshot**: date implied by an archive filename or mirror timestamp (useful, but not always authoritative).
- **Version string**: date/version as embedded in the source code.

## Viola (Pre-WWW Era)

### April 23, 1991 — Viola Preview Release
**Announcement**: Usenet (comp.windows.x)

First public announcement of the Viola system (before WWW support). Described as a "highly manipulable interactive-media authoring tool for UNIX/X11" — the closest thing to Apple's HyperCard for that environment.

- Binary and source available via anonymous FTP on `scam.berkeley.edu`
- Announced by Pei-Yuan Wei as "Director, Experimental Computing Facility, University of California, Berkeley"

**Source**: [Usenet Archives, Message-ID `<9104231058.AA27453@scam.Berkeley.EDU>`](https://www.usenetarchives.com/view.php?id=comp.windows.x&mid=PDkxMDQyMzEwNTguQUEyNzQ1M0BzY2FtLkJlcmtlbGV5LkVEVT4)

### 1991 — Viola 0.8
First numbered release of the Viola language and toolkit.

The exact release date is unclear in surviving public archives; **1991** is commonly cited.

**Source**: [Olde Viola Montage (archived): “first version of viola (0.8) released in 1991”](https://web.archive.org/web/19990830034431/http://viola.org/vintage/montage.html)

---

## ViolaWWW (Browser Era)

### December 9–13, 1991 — "One-Night Hack" (Initial X11 Browser Implementation)
**Announcement**: December 9, 1991 (intention announced); December 13, 1991 (technical details shared) on WWW-Talk mailing list

Pei-Yuan Wei officially announced his intention to create an X11 browser by extending his Viola system (a HyperCard-like media tool).

The initial implementation was described by Wei as "a one-night hack" — he plugged the line mode browser code into Viola to create a rudimentary X-browser to prove feasibility. In his follow-up message, Wei detailed the technical approach:

- Used Viola as a frontend wrapper for the existing `www` line-mode browser
- Made only "very few and minor changes" to `www.c`
- Created an X11 interface that displays `www` output in a scrollable text field
- Added visual highlighting of reference numbers for better visibility
- Made references and commands (Back, Help...) clickable or keyboard-accessible
- Included buttons corresponding to `www` commands

Wei also outlined future plans to "teach the parser about viola object descriptions, and basically embed viola objects (GUIs & programmability) into html files."

**Sources**:
- [WWW-Talk 1991: SGML/HTML docs, X Browser](http://1997.webhistory.org/www.lists/www-talk.1991/0046.html) (initial announcement)
- [WWW-Talk 1991: X Browser](https://lists.w3.org/Archives/Public/www-talk/1991NovDec/0023.html) (technical implementation details)

### January 24, 1992 — First CERN Test Report
Tim Berners-Lee tested ViolaWWW at CERN and reported: *"ViolaWWW works great... A strange thing is that it seems to be so fast—a search in the CERN phone book seems to be instantaneous!"*

TBL noted that Viola appeared faster than the line-mode browser, possibly due to more efficient terminal rendering.

**Source**: [WWW-Talk 1992: Viola - WWW interface](http://1997.webhistory.org/www.lists/www-talk.1992/0014.html)

---

### March 9 – April 20, 1992 — CERN Testing Phase (2.0.x)
**Known version string (by Apr 4)**: `Viola=2.0.4, date=April 4, 1992` (from source code)

First versions circulated to the WWW team at CERN for testing.

On the archived viola.org home page, Wei later summarized the browser as "first released around April 1992" and highlighted early support for inline graphics, scripting, tables, and stylesheets (retrospective statement). During this period, Pei Wei was completing his degree at UC Berkeley, with plans for continued ViolaWWW support being developed.

- **March 9, 1992**: First CERN test release.
- **March 21, 1992**: First public reports of compilation issues (on Sun4/X11), indicating wider circulation beyond CERN.
- **April 4, 1992**: Version 2.0.4 released for continued testing.
- **April 11, 1992**: Tim Berners-Lee's first "Quick Look" review (detailed technical assessment of early ViolaWWW).
    - **Platform Testing**: Successfully tested on NeXT with CubeX in both grayscale and color versions.
    - **Key Features Evaluated**:
        - Multifont text display
        - Links highlighted with "button" boxes (single click to jump)
        - Home, Back, and Forward buttons
        - Single window operation with "clone" facility for documents
        - Bookmark facility
        - Online help buttons
        - Remote index searching via bottom input field
        - Hidden documentation (accessible via globe icon for Viola docs, question mark for help)
        - Source viewer for HTML markup
    - **Early Navigation**: Arrow buttons worked differently than in later versions: "Up" was a destructive backtrack (Back), while "Left" and "Right" were non-destructive traversal through history.
    - **Fuzzy Clicking**: Clicks did not have to be exactly on a button; clicking "somewhere near it" would trigger the jump (could cause accidental navigation).
    - **Performance Notes**: Display speed was "just slow enough to be frustrating" compared to the older "1.0" version referenced by TBL, which was much faster but limited to monofont display (single-font rendering, i.e. without multiple font styles). The multifont support in the current version was deemed worth the performance trade-off, as it provided clearer text formatting with distinct styles.
    - **UI Feedback**: Window looked "a little cluttered"; suggested moving "ViolaWWW" title to window title bar instead of within the window.
    - **Ease of Use**: Simple installation (three-part setup: binary, viola scripts directory, environment variable), started with `vw` command and default home page.
    - **Comparison**: TBL noted the browser was very intuitive and straightforward, with features most users would want, though some advanced capabilities might be excessive for casual users.
- **April 20, 1992**: Conclusion of the initial CERN testing phase.

#### Known Issues (April 1992)
- **Color Crashes**: A "minor bug" caused the program to crash when displaying on color screens (specifically noted on April 29 in the internal status page).
- **UI Glitches**: Scroll bars and side icons sometimes failed to appear; resizing the window vertically was the known workaround.
- **Stability**: Closing a clone window or the main window caused a crash (which TBL noted as "the only way to quit it").

**Sources**:
- [Ancient Web Browsers](https://browsers.flanigan.us/browsers/violawww/)
- [WWW-Talk 1992: problem yacc'ing violaWWW](http://1997.webhistory.org/www.lists/www-talk.1992/0064.html)
- [W3.org: A quick look at ViolaWWW (April 11, 1992)](https://www.w3.org/History/19921103-hypertext/hypertext/Viola/Review_0.html) (detailed technical review comparing with Erwise)
- [Ancient Web Browsers: ViolaWWW internal "About/Status" page (screenshot)](https://browsers.flanigan.us/browsers/violawww/img/Viola-2.1.0_notes.jpg) (status section lists "March 9 to April 20, 1992" CERN testing)
- [Viola Home Page (archived): "First released around April 1992" (retrospective)](https://web.archive.org/web/20180203005145/http://www.viola.org/)
- ViolaWWW 2.0.4 source code (`main.c`)
- ViolaWWW internal help page (`www.v`)

---

### May 10–15, 1992 — Beta Release Phase
**Last update**: May 10, 1992 (from `www.v`)  
**Demo**: JENC3 conference, May 10, 1992  
**README date**: May 15, 1992 (from `ViolaWWW_920515` archive)

Official beta release announcement and demonstration at the 3rd Joint European Networking Conference (JENC3). Tim Berners-Lee provided an updated review on May 15, 1992:
*"A very neat browser usable by anyone, very intuitive and straightforward. The extra features are probably more than 90 per cent of real users will actually use but just the things which an experienced user will want."*

The version string in the source code remained `Viola=2.0.4, date=April 4, 1992` during the early beta phase, before the transition to 2.1.0.

#### Features at Beta Stage
- **Multifont support**: Clear and distinct styles, though the `LI` (list) style was noted as needing more indentation.
- **"Clone" facility**: Icon represented by "tearing a sheet off a pad"; allowed cloning a document into a separate uncluttered window.
- **Bookmarks and History list**.
- **Index search facility** (added by May 10): Search field at the bottom of the window.
- **Bottom Icons**: Three small icons after the search field for History, Printing, and Source Viewer.
- **Hidden Documentation**: Accessible via the "globe icon" (general Viola docs) and the "big question mark" (online help).
- **Help Caching**: The program checks for local help copies and caches remote help in `/usr/tmp`.
- **Scripting Support**: Inclusion of the `<S>` tag for embedded Viola scripts, allowing for "programmable links" and subprocess execution (demonstrated by May 12, according to the internal status page).
- **Supported Platforms**: Confirmed running on NeXT (CubeX), Sun4, and DECstation. Support for both monochrome and color displays.

**Sources**:
- [Ancient Web Browsers](https://browsers.flanigan.us/browsers/violawww/)
- [W3.org: An updated quick look at ViolaWWW (May 15, 1992)](https://www.w3.org/History/19921103-hypertext/hypertext/Viola/Review.html)
- [W3.org: Installation instructions](https://www.w3.org/History/19921103-hypertext/hypertext/Viola/Installation.html)
- [Ancient Web Browsers: ViolaWWW internal "About/Status" page (screenshot)](https://browsers.flanigan.us/browsers/violawww/img/Viola-2.1.0_notes.jpg) (status section lists "May 10, 1992" beta release)

### May 23, 1992 — Version 2.1.0
**Version string**: `Viola=2.1.0, date=May 23, 1992` (from source code)

First public release with combined sources and binaries for multiple platforms (NeXT, DEC, RS6000, SGI, SPARC).

**Source**: 
- [Ancient Web Browsers](https://browsers.flanigan.us/browsers/violawww/)
- ViolaWWW 2.1.0 source code (`Viola/old/src/main.c` in `viola92src.tar`)

### June 30, 1992 — Next Generation Architecture
**Announcement**: June 30, 1992 on WWW-Talk mailing list

Pei Wei confirmed that a built-in **Hypertext Editor** was in development. He also detailed a major architectural shift for the next generation of ViolaWWW:

- **SGML Integration**: Moving away from the "unstructured single textfield" of the initial release to a model based on the `sgmls` parser.
- **Multi-Object Display**: The new architecture used a rough 1-1 mapping of SGML document structure to individual Viola objects (textfields, bitmaps, etc.), allowing for more complex and dynamic page layouts.

**Source**: [WWW-Talk 1992: Re: Hypertext editor](http://1997.webhistory.org/www.lists/www-talk.1992/0137.html)

---

### July 14–30, 1992 — Version 2.1.2
**Announcement**: July 15, 1992 on WWW-Talk mailing list  
**Version string**: `Viola=2.1.2, date=July 14, 1992` (from source code)  
**README date**: July 27, 1992  
**Archive snapshots**: 
- `viola920730.tar.Z` (July 30, 1992) — complete source and binaries.
- `WWWViolaApps_920730.tar.Z` (July 30, 1992) — dedicated archive for Viola application files.

#### Changes & Features
- **Library Update**: Updated to latest W3 library from Line Mode Browser 1.2h.
- **Internal Status**: "About" page includes a "Status" section documenting milestones from March 1992 (CERN tests; beta; W3 library upgrade).
- **Improved Tooling**: Added a `RUN` script to automate environment variable setup (`WWW_HOME`, `VIOLA_PATH`).
- **Printer Hook**: Added a rudimentary printer hook that utilizes the `www` line-mode browser for formatting.
- **Enhanced Reliability**: Improvements to reduce network traffic and increase stability.
- **Supported HTML Tags**: Handled via `res.HTMLStyle.v`, including `UL`, `DL`, `DIR`, `MENU`, `XMP`, `LISTING`, `ADDRESS`, and headers `H1` through `H7`.

#### Known Issues
- **"The Font Problem"**: A known issue where Viola could hang on startup due to font loading failures on certain X servers. The `README` suggests manual editing of `res.font.v` as a workaround.

#### Application Files
Included in the `apps` directory (and as a separate archive `WWWViolaApps_920730.tar.Z`):
- `www.v` — Main browser application (Status: July 14, 1992)
- `res.HTMLStyle.v` — HTML styling configuration
- `res.font.v` — Font specifications
- `wwwHistory.v` — History management
- `wwwSrc.v` — Source viewer
- `wais.v` — WAIS support
- `hello.v` — Sample Viola script

**Sources**: 
- [WWW-Talk 1992: viola update (with latest W3 library)](http://1997.webhistory.org/www.lists/www-talk.1992/0152.html)
- [W3.org History: WWWViolaApps_920730.tar.Z](https://www.w3.org/History/1992/WWWViolaApps_920730.tar.Z)
- ViolaWWW 2.1.2 archives from [Ancient Web Browsers](https://browsers.flanigan.us/browsers/violawww/)
- [Ancient Web Browsers: ViolaWWW internal "About/Status" page (screenshot)](https://browsers.flanigan.us/browsers/violawww/img/Viola-2.1.0_notes.jpg) (status section lists "July 14, 1992" W3 library upgrade)

---

### October – November 1992 — Stability & Rendering Updates
**Timeline**: October 5 – November 4, 1992

Community feedback led to several refinements during the latter half of 1992.

- **October 1992**: Users reported significant memory leaks on SunOS/Solaris systems. This led to the adoption of tools like **Purify** for debugging, which Pei Wei would later use to stabilize the February 1993 release.
- **November 4, 1992**: Introduction of **Scrollable Regions**. TBL noted that "Pei's latest Viola" allowed a `LISTING` section to be viewed as an embedded scrollable region, a key step towards handling large pre-formatted documents within the graphical interface.

**Sources**: 
- [WWW-Talk 1992: WWW/VIOLA "Memory leak" ?](http://1997.webhistory.org/www.lists/www-talk.1992/0212.html)
- [WWW-Talk 1992: HTML](http://1997.webhistory.org/www.lists/www-talk.1992/0252.html)

---

### Early 1993 — "Next Release" Preparation
Discussion on WWW-Talk during early 1993 indicates significant internal improvements to the Viola engine in preparation for a major new release.

#### Notable Improvements & Discussions
- **Memory Management**: Fixed numerous memory leaks and X11 resource handling issues (fonts/pixmaps not being correctly released), eventually causing the X server to require a restart.
- **Bitmap Support**: Discussed the proposed `IMG` tag. Wei revealed that Viola already utilized multiple "bitmap tags" but kept them in a separate experimental DTD (HMML) to avoid polluting the standard HTML specification.
- **WAIS Integration**: Improved handling of WAIS search results. At this stage, the browser "forgot" the result list after following a link; the recommended workaround was the "Clone Page" facility.

**Sources**:
- [WWW-Talk 1993: Re: viola/www memory leak](http://1997.webhistory.org/www.lists/www-talk.1993q1/0173.html)
- [WWW-Talk 1993: Re HMML?](http://1997.webhistory.org/www.lists/www-talk.1993q2/0488.html)

---

### April 21, 1993 — HMML Mentioned as an O'Reilly Multimedia Extension
**Date**: April 21, 1993 (WWW-Talk)

Tim Berners-Lee noted that **HMML already existed** as an extension of HTML for multimedia “from O'Reilly”, and also mentioned “O'Reilly's (unreleased) Viola.”

**Source**: [WWW-Talk 1993: HTML, HMML, and HyperTeX (T. Berners-Lee)](https://ksi.cpsc.ucalgary.ca/archives/WWW-TALK/www-talk-1993q2.messages/127.html)

### May 25, 1993 — HMML DTD Discussion and “HTML+” Mention
**Date**: May 25, 1993 (WWW-Talk)

Dave Raggett discussed HMML/HTML DTD direction and noted that extensions should be compatible with parsing “HTML+” efficiently. The message also includes an FTP location for `hmml.dtd`.

**Source**: [WWW-Talk 1993: Re HMML? (D. Raggett)](https://ksi.cpsc.ucalgary.ca/archives/WWW-TALK/www-talk-1993q2.messages/383.html)

### May 28, 1993 — `<FIGURE>` Proposal in HMML (Working Version)
**Date**: May 28, 1993 (WWW-Talk)

Pei-Yuan Wei described HMML as “my working version” and proposed a richer `<FIGURE>` structure (including captions and mapped/anchored regions).

**Source**: [WWW-Talk 1993: Proposal for FIGURE tag (Pei Wei)](https://ksi.cpsc.ucalgary.ca/archives/WWW-TALK/www-talk-1993q2.messages/409.html)

### Circa 1993 — About/Status Screenshot (Key Dates Only)

The archived viola.org home page includes a ViolaWWW “circa 1993” screenshot of the built-in About/Status page. The only information treated as dated evidence from this screenshot is its **Status** list:

- **April 1993**: “Alpha release. SGML and other hypermedia features...”
- **May 10, 1992**: “Beta release. HTML centric version.”
- **March 9 to April 20, 1992**: “Releases to the WWW people at CERN for tests.”

**Source**: [Viola Home Page (archived)](https://web.archive.org/web/20180203005145/http://www.viola.org/)

---

### October 22, 1993 — STG “Stylesheet Language” Posted (Prototype in Viola)
**Announcement**: October 22, 1993 on WWW-Talk mailing list

Pei-Yuan Wei shared an early stylesheet description language (STG) and noted that a prototype was already implemented in Viola, with the goal of producing a standalone library usable by multiple W3 browsers.

**Source**: [WWW-Talk Oct-Dec 1993: Stylesheet Language (Pei Y. Wei)](https://www.wiumlie.no/2006/phd/archive/www.webhistory.org/www.lists/www-talk.1993q4/0264.html)

---

### March 23–24, 1994 — Version 3.1 Beta
**Announcement**: March 24, 1994 on WWW-Talk mailing list  
**README date**: March 23, 1994

This release represents a significant advancement in ViolaWWW's capabilities, particularly in its support for emerging web standards and its integration with the Viola scripting language.

#### Notable Features
- **HTML+ support**: Added support for container paragraphs, input forms, and tables (experimental).
- **Advanced formatting**: Support for multiple columning and document insertion (client-side).
- **Dynamic lists**: Implementation of dynamically collapsible/expandable `<UL>` lists.
- **Programmable objects**: Embeddable in-document and in-toolbar programmable Viola objects/applets.
- **New GUI options**: Introduction of the Motif front-end (`vw`), alongside the traditional Xlib-based version (`viola`).
- **Simplified installation**: Transitioned to a single binary for easier deployment.

#### Technical Changes
- **Improved messaging**: Optimized communication between the Motif front-end and the Viola engine by switching from string-based to object pointer-based messaging, resulting in better scrolling performance.
- **UI refinements**:
    - Added a dedicated toolbar frame under the menu bar.
    - Moved navigation buttons ("BackUp", "Previous", "Next", "Show Source", "Clone Page") to the right side of the toolbar as icons.
    - Support for user/document-defined tools tiled from the left side of the toolbar.
    - Improved window title handling: Viola now manages title rendering, including automatic font scaling for long titles.
- **Bug fixes**:
    - Fixed the history mechanism, which was previously unreliable.
    - Added busy/idle cursor indicators.
- **Hook for help**: Added a hook for Viola scripts to send messages to the active help field (e.g., for HTTP progress reports).

#### Availability
- Source and binary (historical; unavailable today — `ftp.ora.com` no longer resolves): `ftp://ora.com/pub/www/viola`
- Archive: `viola940323.tar.gz` (dated March 23, 1994)

**Source**: [WWW-Talk 1994: ViolaWWW Release](http://1997.webhistory.org/www.lists/www-talk.1994q1/1031.html) and `src/vw/changes` from `viola940323.tar.gz`.

---

### April 10, 1995 — Version 3.3 Beta
**Announcement**: April 17, 1995 on WWW-Talk mailing list

Final known release of ViolaWWW. Self-contained single binary for easier installation.

#### Notable Features
- **HTML 3.0 support**: Highly container-based, plus many extensions for richer formatting
- **Multiple columns formatting**
- **Document insertion** (client-side)
- **Dynamically collapsible/expandable lists**
- **Sidebar panel**: For displaying meta-information or intra-document navigational links
- **Dynamic toolbar**: Document-engaged tool applets (navigational aids)
- **Rudimentary stylesheet mechanism**: For changing document fonts, colors, alignments
- **Scripting language**: Accessible from HTML, allowing embedded interactive scripts/applets
- **Hotlist facility** (bookmarks)
- **HTTP loading progress**: Displayed as a pie chart
- **Motif front-end**: X11 (non-Motif) version also available
- **Self-contained single binary**: Unlike older versions which required setup of various Viola application files

#### Availability
- Source and binary (historical; unavailable today — `ftp.ora.com` no longer resolves): `ftp://ftp.ora.com/pub/www/viola`
- Platform: Unix/X Windows
- Sparc binary supplied

**Source**: [WWW-Talk Apr-Jun 1995: Release of ViolaWWW 3.3](http://1997.webhistory.org/www.lists/www-talk.1995q2/0128.html)

---

## ViolaWWW 4.0 (Modern Era)

### October 17, 2025 — Project Revival
**Developer**: Evgeny Stepanischev

This phase, initiated in late 2025, aims to "revive" the browser for modern systems. The work began with a port of the 30-year-old C codebase from 32-bit to 64-bit architecture.

The project's scope has since expanded to fully realizing the concepts that Pei-Yuan Wei conceived and started but did not finish. This restoration work draws on the author's archived website, unfinished book, and various drafts. Crucially, the source code itself contains extensive commented-out or incomplete sections that provide a roadmap for the author's original intentions.

Work is ongoing as of **2026**.

---

## Version Summary Table

| Date | Version | Milestone |
|------|---------|-----------|
| Apr 23, 1991 | Viola Preview | First public announcement (pre-WWW) |
| 1991 | Viola 0.8 | First numbered release |
| Dec 9, 1991 | — | Official intention to create X11 W3 browser |
| Jan 24, 1992 | — | First successful test report by Tim Berners-Lee |
| Mar 9 – Apr 20, 1992 | 2.0.x (2.0.4 by Apr 4) | CERN testing phase |
| May 10 – 15, 1992 | — | Beta release demo at JENC3; packaging/README dates |
| May 23, 1992 | 2.1.0 | First public release |
| Jun 30, 1992 | — | Multi-object SGML architecture announced |
| Jul 14, 1992 | 2.1.2 | W3 library update, archive `viola920730.tar.Z` |
| Nov 4, 1992 | — | Scrollable regions for `LISTING` sections |
| Early 1993 | — | Memory/resource leak fixes, preparing "Next Release" |
| Apr–May 1993 | — | HMML discussions on WWW-Talk; About/Status screenshot lists key dates (not a confirmed release) |
| Oct 22, 1993 | — | STG “Stylesheet Language” posted (prototype in Viola) |
| Mar 23, 1994 | 3.1 Beta | Bug fixes, collapsible/expandable lists |
| Apr 10, 1995 | 3.3 Beta | Final release |
| Oct 17, 2025 | 4.0 (Revival) | 64-bit port, ongoing feature restoration |

---

## References

- [Ancient Web Browsers - ViolaWWW](https://browsers.flanigan.us/browsers/violawww/)
- [Ancient Web Browsers: ViolaWWW internal "About/Status" page (screenshot)](https://browsers.flanigan.us/browsers/violawww/img/Viola-2.1.0_notes.jpg)
- [WWW-Talk Archives: Release of ViolaWWW 3.3](http://1997.webhistory.org/www.lists/www-talk.1995q2/0128.html)
- [WWW-Talk Archives: viola update (with latest W3 library)](http://1997.webhistory.org/www.lists/www-talk.1992/0152.html)
- [WWW-Talk Archives: ViolaWWW Release (3.1 Beta)](http://1997.webhistory.org/www.lists/www-talk.1994q1/1031.html)
- [Usenet Archives: Viola Announcement (Apr 1991)](https://www.usenetarchives.com/view.php?id=comp.windows.x&mid=PDkxMDQyMzEwNTguQUEyNzQ1M0BzY2FtLkJlcmtlbGV5LkVEVT4)
- [Olde Viola Montage (archived): Viola 0.8 (1991)](https://web.archive.org/web/19990830034431/http://viola.org/vintage/montage.html)
- [WWW-Talk 1991: SGML/HTML docs, X Browser](http://1997.webhistory.org/www.lists/www-talk.1991/0046.html) (Pei Wei's announcement)
- [WWW-Talk 1992: Viola - WWW interface](http://1997.webhistory.org/www.lists/www-talk.1992/0014.html) (TBL test report)
- Robert Cailliau & James Gillies, "How the Web Was Born" (2000)
- ViolaWWW internal About page (version 2.1.x)
- [Viola Home Page (archived)](https://web.archive.org/web/20180203005145/http://www.viola.org/) — includes “First released around April 1992” retrospective note
- [W3.org History: www-talk archive 1991-1992](https://www.w3.org/History/1992/www-talk.archive.Z)
- [W3.org History: www-talk archive Jan-Jun 1993](https://www.w3.org/History/1992/www-talk.9301-9306.Z)
- [WWW-Talk 1993: Re: viola/www memory leak](http://1997.webhistory.org/www.lists/www-talk.1993q1/0173.html)
- [WWW-Talk 1993: Re HMML?](http://1997.webhistory.org/www.lists/www-talk.1993q2/0488.html)
- [WWW-Talk 1993: HTML, HMML, and HyperTeX (T. Berners-Lee)](https://ksi.cpsc.ucalgary.ca/archives/WWW-TALK/www-talk-1993q2.messages/127.html)
- [WWW-Talk 1993: Re HMML? (D. Raggett)](https://ksi.cpsc.ucalgary.ca/archives/WWW-TALK/www-talk-1993q2.messages/383.html)
- [WWW-Talk 1993: Proposal for FIGURE tag (Pei Wei)](https://ksi.cpsc.ucalgary.ca/archives/WWW-TALK/www-talk-1993q2.messages/409.html)
- [WWW-Talk Oct-Dec 1993: Stylesheet Language (Pei Y. Wei)](https://www.wiumlie.no/2006/phd/archive/www.webhistory.org/www.lists/www-talk.1993q4/0264.html)
- [W3.org: An updated quick look at ViolaWWW (May 15, 1992)](https://www.w3.org/History/19921103-hypertext/hypertext/Viola/Review.html)
- [W3.org: A quick look at ViolaWWW (April 11, 1992)](https://www.w3.org/History/19921103-hypertext/hypertext/Viola/Review_0.html)
- [W3.org: Viola installation instructions (May 1992)](https://www.w3.org/History/19921103-hypertext/hypertext/Viola/Installation.html)
- [W3.org: Using Viola At CERN](https://www.w3.org/History/19921103-hypertext/hypertext/Viola/AtCERN.html)
- [UNIX Browsers (UrbanCenter, University of Toronto)](http://www.urbancenter.utoronto.ca/webdocs/HTMLdocs/UNIXTOOLS/unix_browsers.html) — secondary list (updated 1995); contains outdated/possibly conflated Viola/ViolaWWW details (e.g., lists “ViolaWWW” as version 0.8 and points to an old FTP archive), so use with caution.

*Last updated: January 2026*
