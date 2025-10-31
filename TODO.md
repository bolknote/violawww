## TODO

### Bugs
- [ ] Fix history behavior
  - Ensure navigation history (back/forward) works consistently across pages and embedded views.
- [ ] Fix Clone functionality
  - Cloning should produce an identical, independent copy without side effects or shared state.
- [ ] Enable `mailto:` links
  - Clicking `mailto:` should open the default mail client with the correct address and subject/body.
- [ ] Re-encode page `TITLE`
  - Page titles must be correctly encoded/decoded (no mojibake; proper charset handling).
- [ ] Stop launching external viewer for direct image links
  - Direct links to images should render inline; must not attempt to start `xv` or any external program.

### Styling
- [ ] Make FOSI styles functional
  - Load and apply FOSI stylesheets reliably; verify styling across key components and embeds.

### Environment (STG)
- [ ] Add `fontFamily` in STG
  - Define and apply the desired `fontFamily` in the STG configuration so text renders as expected.
