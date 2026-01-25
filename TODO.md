## TODO

### Bugs
- [ ] Fix history behavior
  - Ensure navigation history (back/forward) works consistently across pages and embedded views.
- [ ] Enable `mailto:` links
  - Clicking `mailto:` should open the default mail client with the correct address and subject/body.
- [ ] Fix STYLE/SCRIPT skipping
  - Skipping STYLE/SCRIPT elements doesn't seem to work everywhere; needs investigation and fixes.
- [ ] Implement file opening sandbox
  - Implement a "sandbox" mechanism for safely opening files to prevent security issues.
- [ ] Remove default hint message at bottom of vw

### Styling
- [ ] Make FOSI styles functional
  - Load and apply FOSI stylesheets reliably; verify styling across key components and embeds.
- [ ] Add `fontFamily` in STG
  - Define and apply the desired `fontFamily` in the STG configuration so text renders as expected.
- [x] Implement `fontWeight=<weight>` in STG
  - Add support for fontWeight attribute in STG stylesheets (planned values: normal, bold).
- [ ] Implement `numStyle=<style>` in STG
  - Add support for list numbering styles in STG (planned values: roman, number, alpha).

### Core & HTML
- [ ] Implement HTML editing functions (`src/viola/html.c`)
  - `HText_applyStyle()`, `HText_updateStyle()`, `HText_selectionStyle()`, `HText_replaceSel()`, `HTextApplyToSimilar()`, `HTextSelectUnstyled()`, `HText_unlinkSelection()`.
