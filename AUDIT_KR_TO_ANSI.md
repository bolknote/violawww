## Audit of K&R → ANSI Prototype Changes

This report lists functions where argument count, order, or types changed during K&R-to-ANSI conversions, evaluates call sites, and assesses justification/risks.

### Commits Covered
- eeb006b: src/viola/tfed.c, src/viola/tfed.h
- cf9d856: src/viola/tfed.c, src/viola/tfed_i.h, src/viola/cl_txtDisp.h, src/viola/event_x.h, src/viola/glib_x.h
- 39c9061: src/libXPA/src/xpa.c
- 35a3ecb: src/viola/biop.c, src/viola/biop.h
- c8feab0: src/vw/*.c, *.h; src/libIMG/*.h,*.c; src/libXPM/XpmRdFToI.c
- 92272b0: src/viola/cl_HTML.h, src/viola/cl_txtDisp.h

---

### 1) Argument COUNT changes

- scheduleEvent
  - Before: non-prototype.
  - After: `long scheduleEvent(int delay, long (*func)(), VObj* obj, int argc, Packet* argv)`
  - Calls verified:
    - src/viola/tfed.c: pass `(delay, TimedEraseCursor/TimedDrawCursor, self, 0, (Packet*)NULL)` – OK.
    - src/viola/cl_generic.c: `scheduleEvent(msec, sendMessagePackets, obj, argc-2, messages)` – OK.
  - Justification: event system needs argv/argc for callbacks; return value used as timer id. Low risk.

- tfed_expose
  - Before: non-prototype.
  - After: `int tfed_expose(VObj* self, int x, int y, int width, int height)`
  - Calls verified:
    - src/viola/HTML_share.c: forwards int coords from packets – OK.
  - Justification: explicit expose rectangle. Low risk.

- GLPrepareObjColor
  - Before: non-prototype (often used without args implicitly).
  - After: `ColorInfo* GLPrepareObjColor(VObj* self)`
  - Calls verified: numerous in src/viola/*.c now pass `self` – OK.
  - Justification: needs object to select colors; necessary. Low risk.

- str2EBuff
  - Before: third parameter was value; implicit.
  - After: `int str2EBuff(TFStruct* tf, char* str, int* fontID)`
  - Calls verified:
    - src/viola/tfed.c: `str2EBuff(tf, str, &fontID)` – OK.
  - Justification: returns font via out-parameter. Low risk.

- libIMG API (multiple)
  - clip, brighten, compress, halftone, reduce, rotate now have explicit arg lists.
  - Calls verified in src/libIMG/misc.c and related:
    - `brighten(image, options->bright, verbose)` – OK.
    - `compress(image, verbose)` – OK.
    - `halftone(image, verbose)` – OK.
    - `reduce(image, n, verbose)` – OK (misc.c, send.c).
    - `rotate(image, options->rotate, verbose)` – OK.
  - Justification: clarity and type safety. Low risk.

### 2) Argument ORDER changes

- rotate (libIMG)
  - Before: non-prototype; order not explicit.
  - After: `rotate(Image* simage, int rotate, unsigned int verbose)`
  - Calls verified: pass `(image, options->rotate, verbose)` – matches order. Low risk.

- scheduleEvent
  - Order expanded; all call sites updated consistently as above. Low risk.

No other order inversions were found in reviewed diffs; xpa.c K&R → ANSI retained original order.

### 3) Argument TYPE changes / substitutions

- TimedDrawCursor / TimedEraseCursor
  - Return type: `int` → `long` to satisfy callback type for `scheduleEvent`.
  - Parameter types standardized: `(VObj* self, Packet argv[], int argc)`
  - Calls updated to pass `(Packet*)NULL, 0` when direct – OK.
  - Justification: required by event system signature. Low risk.

- cancelEvent
  - Now `int cancelEvent(long timeInfoID)`
  - Calls pass `tf->cursorTimeInfo` (long). Verified in src/viola/tfed.c – OK.

- cl_HTML.h, cl_txtDisp.h helpers/methods
  - Now require `(VObj* self, Packet* result, int argc, Packet argv[] [, long labelID])`
  - These match existing messaging conventions; implementations use these types. No mismatches found. Low risk.

- xloadimage.h
  - `tail(char* path)`, `internalError(int sig)`, `usage(char* name)`, `int errorHandler(Display*, XErrorEvent*)`
  - Calls verified:
    - `tail(argv[0])` usage in misc.c/xloadimage.c – OK.
    - `internalError(int)` used as handler – OK.
    - `usage(name)` uses `tail(name)` internally – OK.
    - `errorHandler(disp, &event)` signature matches implementation – OK.

### Additional spot checks

- libXPA/src/xpa.c
  - K&R → ANSI for internal statics (`item_off`, `item_on`, `pane_on`, `pb_draw`, `title_draw`). No arg order/type change beyond explicit types. Local call sites consistent. Low risk.

- biop.c / biop.h
  - All operators now `void func(Packet* p1, Packet* p2)` etc.; previously K&R. These are internal and called consistently within `biOp`. No ordering swaps detected. Low risk.

### Potential Risks or Follow-ups

- Many `tfed.h` prototypes were filled in. While spot-checked key ones (cursor, expose, selection), a full build passes, indicating consistency. No anomalous call found in search.
- Ensure all external modules that might link against `libIMG` headers (if any outside this repo) are recompiled due to prototype strictness.

### Conclusion

- Changes are justified: they eliminate deprecated non-prototype warnings, align callback signatures, and make APIs explicit.
- All audited call sites conform to new argument counts, orders, and types. No incorrect substitutions detected.
- No action required at this time.


