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
### Styling
- [ ] Make FOSI styles functional
  - Load and apply FOSI stylesheets reliably; verify styling across key components and embeds.

### Viola Interpreter
- [x] Implement `do-while` loop code generation (`src/viola/cgen.c`)
  - `AST_DO` was parsed by the grammar (`gram.y:342`) but had no `case AST_DO:` handler in `codeGen()`. Now implemented with `CODE_NBR2_NZERO` for the conditional backward branch.

### Core & HTML
- [ ] Implement HTML editing functions (`src/viola/html.c`)
  - `HText_applyStyle()`, `HText_updateStyle()`, `HText_selectionStyle()`, `HText_replaceSel()`, `HTextApplyToSimilar()`, `HTextSelectUnstyled()`, `HText_unlinkSelection()`.
