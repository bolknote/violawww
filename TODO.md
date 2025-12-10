## TODO

### Bugs
- [ ] Fix history behavior
  - Ensure navigation history (back/forward) works consistently across pages and embedded views.
- [ ] Enable `mailto:` links
  - Clicking `mailto:` should open the default mail client with the correct address and subject/body.
- [ ] Stop launching external viewer for direct image links
  - Direct links to images should render inline; must not attempt to start `xv` or any external program.
- [ ] Fix STYLE/SCRIPT skipping
  - Skipping STYLE/SCRIPT elements doesn't seem to work everywhere; needs investigation and fixes.
- [ ] Implement file opening sandbox
  - Implement a "sandbox" mechanism for safely opening files to prevent security issues.
- [ ] Fix CHANGED tag (no yellow background)
- [ ] Remove default hint message at bottom of vw
- [ ] Fix URL bar in viola — address not displayed

### Styling
- [ ] Make FOSI styles functional
  - Load and apply FOSI stylesheets reliably; verify styling across key components and embeds.
- [ ] Add `fontFamily` in STG
  - Define and apply the desired `fontFamily` in the STG configuration so text renders as expected.
