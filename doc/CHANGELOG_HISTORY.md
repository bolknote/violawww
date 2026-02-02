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

### Writing rules (to avoid “fantasy”)

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
  - **Secondary source**: “first version of viola (0.8) released in 1991”
- **Note**
  - The exact release date is unclear in surviving public archives; **1991** is commonly cited.
- **Source**
  - [Olde Viola Montage (archived)](https://web.archive.org/web/19990830034431/http://viola.org/vintage/montage.html)

---

## ViolaWWW (Browser Era)

### 1991-12-09 to 1991-12-13 — “One-night hack” (initial X11 browser implementation)

- **Evidence**
  - **Announcement**: 1991-12-09 (intention announced) on WWW-Talk
  - **Announcement**: 1991-12-13 (technical details) on WWW-Talk
- **What the sources say**
  - Pei-Yuan Wei announced an intention to create an X11 browser by extending the Viola system, described the initial implementation as “a one-night hack”, and discussed reusing/connecting existing WWW code.
- **Sources**
  - [WWW-Talk 1991: SGML/HTML docs, X Browser](http://1997.webhistory.org/www.lists/www-talk.1991/0046.html)
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
  - Includes an explicit quote: “ViolaWWW works great…”
- **Source**
  - [WWW-Talk 1992: “Viola - WWW interface”](http://1997.webhistory.org/www.lists/www-talk.1992/0014.html)

---

### 1992-03-09 to 1992-04-20 — CERN testing phase (2.0.x)

- **Evidence**
  - **Version string (known by 1992-04-04)**: `Viola=2.0.4, date=April 4, 1992` (from surviving source)
  - **Review**: Tim Berners-Lee “Quick look” review dated 1992-04-11
  - **W3 News**: April 1992 release note about a search panel issue and fix
  - **Artifact**: “About/Status” screenshot lists “March 9 to April 20, 1992” as CERN test window (see later “About/Status screenshot” entry)
- **What the sources support**
  - ViolaWWW circulated to the WWW team at CERN for testing during this period.
  - A particular April 1992 build lacked a search panel and was not generally distributed; a corrected version followed.
- **Sources**
  - [WWW-Talk 1992: compilation issues (“problem yacc’ing violaWWW”)](http://1997.webhistory.org/www.lists/www-talk.1992/0064.html)
  - [W3.org: “A quick look at ViolaWWW” (1992-04-11)](https://www.w3.org/History/19921103-hypertext/hypertext/Viola/Review_0.html)
  - [W3.org History: “Spring releases” (April 1992)](https://www.w3.org/History/19921103-hypertext/hypertext/WWW/News/9204.html)
  - [Ancient Web Browsers: ViolaWWW](https://browsers.flanigan.us/browsers/violawww/)
  - [Ancient Web Browsers: About/Status page screenshot](https://browsers.flanigan.us/browsers/violawww/img/Viola-2.1.0_notes.jpg)
  - [Viola home page (archived; retrospective note “first released around April 1992”)](https://web.archive.org/web/20180203005145/http://www.viola.org/)

### 1992-05-10 to 1992-05-15 — Beta release phase (JENC3 demo; packaging dates)

- **Evidence**
  - **Demo date**: JENC3 conference (1992-05-10)
  - **“Last update”**: 1992-05-10 (noted inside `www.v` in surviving materials)
  - **README date**: 1992-05-15 (packaging date cited for `ViolaWWW_920515`)
  - **Review**: Tim Berners-Lee updated review dated 1992-05-15
- **What the sources support**
  - A widely described “beta test” version existed by mid-May 1992; TBL reviewed it and recorded both features and limitations.
- **Sources**
  - [W3.org: “An updated quick look at ViolaWWW” (1992-05-15)](https://www.w3.org/History/19921103-hypertext/hypertext/Viola/Review.html)
  - [W3.org: Installation instructions (May 1992)](https://www.w3.org/History/19921103-hypertext/hypertext/Viola/Installation.html)
  - [CERN mirror: updated quick look](https://info.cern.ch/hypertext/Viola/Review.html)
  - [CERN mirror: installation instructions](https://info.cern.ch/hypertext/Viola/Installation.html)
  - [Ancient Web Browsers: ViolaWWW](https://browsers.flanigan.us/browsers/violawww/)
  - [Ancient Web Browsers: About/Status page screenshot](https://browsers.flanigan.us/browsers/violawww/img/Viola-2.1.0_notes.jpg)

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
  - A built-in hypertext editor was in development; the architecture was moving towards SGML parsing and mapping document structure into multiple Viola objects.
- **Source**
  - [WWW-Talk 1992: Re: Hypertext editor](http://1997.webhistory.org/www.lists/www-talk.1992/0137.html)

---

### 1992-07-14 to 1992-07-30 — Version 2.1.2 (archives `viola920730.tar.Z`, `WWWViolaApps_920730.tar.Z`)

- **Evidence**
  - **Version string**: `Viola=2.1.2, date=July 14, 1992`
  - **Announcement**: 1992-07-15 on WWW-Talk
  - **README date**: 1992-07-27
  - **Archive snapshot**: 1992-07-30 (`viola920730.tar.Z`, `WWWViolaApps_920730.tar.Z`)
  - **CERN status page**: lists current release `920730` and X11R4+ requirement
- **Sources**
  - [WWW-Talk 1992: viola update (with latest W3 library)](http://1997.webhistory.org/www.lists/www-talk.1992/0152.html)
  - [W3.org History: `WWWViolaApps_920730.tar.Z`](https://www.w3.org/History/1992/WWWViolaApps_920730.tar.Z)
  - [CERN: Status of ViolaWWW](https://info.cern.ch/hypertext/WWW/Viola/Status.html)
  - [Ancient Web Browsers: ViolaWWW](https://browsers.flanigan.us/browsers/violawww/)
  - [Ancient Web Browsers: About/Status page screenshot](https://browsers.flanigan.us/browsers/violawww/img/Viola-2.1.0_notes.jpg)

### 1992-09 — Pei Wei joins O’Reilly & Associates (W3 News)

- **Evidence**
  - **Announcement (W3 News 9209)**: September 1992
- **Note**
  - This marks the start of O’Reilly-era work referenced in later WWW-Talk posts and in the 1994 beta announcements.
- **Source**
  - [W3.org History: W3 News (September ’92)](https://www.w3.org/History/19921103-hypertext/hypertext/WWW/News/9209.html)

### 1992-10 to 1992-11 — Stability and rendering notes (memory leaks; scrollable regions)

- **Evidence**
  - **Announcement**: reports/discussion on WWW-Talk (Oct 1992) about memory leaks
  - **Announcement**: 1992-11-04 note about scrollable regions for `LISTING`
- **Sources**
  - [WWW-Talk 1992: “WWW/VIOLA ‘Memory leak’ ?”](http://1997.webhistory.org/www.lists/www-talk.1992/0212.html)
  - [WWW-Talk 1992: “HTML” (scrollable region mention)](http://1997.webhistory.org/www.lists/www-talk.1992/0252.html)

---

### Early 1993 — “Next release” preparation (leaks/resources; libwww 2.0-alpha; HMML discussion)

- **Evidence**
  - **Announcement**: discussions across early 1993 WWW-Talk threads
  - **Secondary note**: Internet World (1995) narrative about “generally available” in Jan 1993 (treated as non-primary dating)
- **Sources**
  - [WWW-Talk 1993: memory leak discussion](http://1997.webhistory.org/www.lists/www-talk.1993q1/0173.html)
  - [WWW-Talk 1993: “Re HMML?”](http://1997.webhistory.org/www.lists/www-talk.1993q2/0488.html)
  - [WWW-Talk 1993: libwww 2.0-alpha usage](http://1997.webhistory.org/www.lists/www-talk.1993q1/0246.html)
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
- **Source**
  - [WWW-Talk 1994: “ViolaWWW beta release is available”](http://1997.webhistory.org/www.lists/www-talk.1994q1/0716.html)

### 1994-03-23 to 1994-03-24 — Version 3.1 Beta

- **Evidence**
  - **README date**: 1994-03-23
  - **Announcement**: 1994-03-24 (WWW-Talk)
- **Sources**
  - [WWW-Talk 1994: ViolaWWW Release (3.1 beta)](http://1997.webhistory.org/www.lists/www-talk.1994q1/1031.html)
  - [WWW-Talk 1994: FOLD attribute proposal](http://1997.webhistory.org/www.lists/www-talk.1994q1/1027.html)

### 1994-05-18 to 1994-05-20 — Cross-platform testing initiative

- **Evidence**
  - **Announcement**: May 1994 WWW-Talk posts about platform testing accounts and status
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
- **Source**
  - [WWW-Talk 1995: Release of ViolaWWW 3.3](http://1997.webhistory.org/www.lists/www-talk.1995q2/0128.html)

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
