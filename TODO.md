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
- [ ] Implement `do-while` loop code generation (`src/viola/cgen.c`)
  - `AST_DO` is parsed by the grammar (`gram.y:342`) but has no `case AST_DO:` handler in `codeGen()`. Needs implementation analogous to `AST_WHILE`/`AST_FOR`.
- [ ] Implement `!` (logical NOT) operator (`src/viola/gram.y`)
  - The `!` token is declared in precedence (`gram.y:66`) but has no grammar production rule `'!' expr`. Requires a new AST type and code generation. Currently only the `not()` built-in function works as a workaround.

### Core & HTML
- [ ] Implement HTML editing functions (`src/viola/html.c`)
  - `HText_applyStyle()`, `HText_updateStyle()`, `HText_selectionStyle()`, `HText_replaceSel()`, `HTextApplyToSimilar()`, `HTextSelectUnstyled()`, `HText_unlinkSelection()`.
