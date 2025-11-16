# ViolaWWW Browser Build System
# Modern Makefile for macOS (Darwin)

# Build configuration
CC = cc
AR = ar rcs
RANLIB = ranlib

# Auto-detect Homebrew paths
BREW_PREFIX := $(shell brew --prefix 2>/dev/null || echo /opt/homebrew)
OPENMOTIF_PREFIX := $(shell brew --prefix openmotif 2>/dev/null || echo $(BREW_PREFIX)/opt/openmotif)
ICU_PREFIX := $(shell brew --prefix icu4c 2>/dev/null)
OPENSSL_PREFIX := $(shell brew --prefix openssl@3 2>/dev/null || echo $(BREW_PREFIX)/opt/openssl@3)

# Check if ICU is available
ICU_AVAILABLE := $(shell test -d "$(ICU_PREFIX)/include" && echo yes || echo no)

# Check if OpenSSL is available
OPENSSL_AVAILABLE := $(shell test -d "$(OPENSSL_PREFIX)/include" && echo yes || echo no)

# Compiler flags
ARCH_FLAGS = -arch arm64
CFLAGS = -Os $(ARCH_FLAGS) -std=gnu17 -Wno-everything -D__DARWIN__ -funsigned-char
CFLAGS_LIBS = -Os $(ARCH_FLAGS) -Wno-everything -no-cpp-precomp -fno-common -funsigned-char \
              -D__DARWIN__ -DNO_ALLOCA -DCSRG_BASED

# Add ICU support if available
ifeq ($(ICU_AVAILABLE),yes)
CFLAGS += -DUSE_ICU
CFLAGS_LIBS += -DUSE_ICU
ICU_INCLUDES = -I$(ICU_PREFIX)/include
ICU_LIBS = -L$(ICU_PREFIX)/lib -licui18n -licuuc -licudata -liconv
else
ICU_INCLUDES =
ICU_LIBS =
endif

# Add OpenSSL support if available
ifeq ($(OPENSSL_AVAILABLE),yes)
CFLAGS += -DUSE_SSL
CFLAGS_LIBS += -DUSE_SSL
SSL_INCLUDES = -I$(OPENSSL_PREFIX)/include
SSL_LIBS = -L$(OPENSSL_PREFIX)/lib -lssl -lcrypto
else
SSL_INCLUDES =
SSL_LIBS =
endif

# 64-bit migration warning flags (use with: make WARN_64BIT=1)
ifdef WARN_64BIT
CFLAGS := $(filter-out -Wno-everything,$(CFLAGS))
CFLAGS += -Wshorten-64-to-32 -Wconversion -Wformat -Wpointer-to-int-cast -Wint-to-pointer-cast
CFLAGS_LIBS := $(filter-out -Wno-everything,$(CFLAGS_LIBS))
CFLAGS_LIBS += -Wshorten-64-to-32 -Wconversion -Wformat -Wpointer-to-int-cast
endif
INCLUDES = -I$(BREW_PREFIX)/include \
           -I$(OPENMOTIF_PREFIX)/include \
           $(ICU_INCLUDES) \
           $(SSL_INCLUDES) \
           -I/opt/X11/include

# Dependency generation flags
DEPFLAGS = -MMD -MP

# Linker flags
LDFLAGS = $(ARCH_FLAGS) -L$(BREW_PREFIX)/lib \
          -L$(OPENMOTIF_PREFIX)/lib \
          -L/opt/X11/lib
LIBS = -lXm -lXext -lXmu -lXt -lSM -lICE -lX11 -lm $(ICU_LIBS) $(SSL_LIBS)

# Source directories
SRC_DIR = src
LIBWWW_DIR = $(SRC_DIR)/libWWW
LIBXPM_DIR = $(SRC_DIR)/libXPM
LIBXPA_DIR = $(SRC_DIR)/libXPA/src
LIBIMG_DIR = $(SRC_DIR)/libIMG
LIBSTYLE_DIR = $(SRC_DIR)/libStyle
VIOLA_DIR = $(SRC_DIR)/viola
VW_DIR = $(SRC_DIR)/vw

# Library targets
LIBWWW = $(LIBWWW_DIR)/libwww.a
LIBXPM = $(LIBXPM_DIR)/libXpm.a
LIBXPA = $(LIBXPA_DIR)/libXpa.a
LIBIMG = $(LIBIMG_DIR)/libIMG.a
LIBSTYLE = $(LIBSTYLE_DIR)/libstg.o

# Binary targets
VIOLA = $(VIOLA_DIR)/viola
VW = $(VW_DIR)/vw

# Default target
.PHONY: all
all: config_info $(VW) $(VIOLA)

.PHONY: config_info
config_info:
ifeq ($(ICU_AVAILABLE),no)
	@echo "⚠ Building without ICU (UTF-8 will not be transliterated)"
	@echo ""
endif
ifeq ($(OPENSSL_AVAILABLE),no)
	@echo "⚠ Building without OpenSSL (HTTPS will not be supported)"
	@echo "  Install with: brew install openssl@3"
	@echo ""
endif

# Help target
.PHONY: help
help:
	@echo "ViolaWWW Browser Build System"
	@echo ""
	@echo "Available targets:"
	@echo "  all        - Build everything (default)"
	@echo "  viola      - Build Viola browser"
	@echo "  vw         - Build VW browser (Motif interface)"
	@echo "  libs       - Build all libraries"
	@echo "  test       - Build and run all tests"
	@echo "  asan       - Build with AddressSanitizer (ASan)"
	@echo "  ubsan      - Build with UndefinedBehaviorSanitizer (UBSan)"
	@echo "  san        - Build with ASan + UBSan"
	@echo "  clean      - Remove object files"
	@echo "  distclean  - Remove all build artifacts"
	@echo "  check-64bit - Check for 64-bit migration issues (long->int truncation)"
	@echo "  check-help - Show code analysis tools (includes, libs, unused code)"
	@echo "  help       - Show this help message"

# ============================================================================
# Library targets
# ============================================================================

.PHONY: libs
libs: $(LIBWWW) $(LIBXPM) $(LIBXPA) $(LIBIMG) $(LIBSTYLE)

# libWWW (HTTP/HTML library)
LIBWWW_SRCS = $(LIBWWW_DIR)/HTParse.c $(LIBWWW_DIR)/HTAccess.c $(LIBWWW_DIR)/HTTP.c \
              $(LIBWWW_DIR)/HTFile.c $(LIBWWW_DIR)/HTFTP.c $(LIBWWW_DIR)/HTTCP.c \
              $(LIBWWW_DIR)/SGML.c $(LIBWWW_DIR)/HTML.c $(LIBWWW_DIR)/HTMLDTD.c \
              $(LIBWWW_DIR)/HTChunk.c $(LIBWWW_DIR)/HTPlain.c $(LIBWWW_DIR)/HTWriter.c \
              $(LIBWWW_DIR)/HTFWriter.c $(LIBWWW_DIR)/HTMLGen.c $(LIBWWW_DIR)/HTAtom.c \
              $(LIBWWW_DIR)/HTAnchor.c $(LIBWWW_DIR)/HTStyle.c $(LIBWWW_DIR)/HTList.c \
              $(LIBWWW_DIR)/HTString.c $(LIBWWW_DIR)/HTAlert.c $(LIBWWW_DIR)/HTRules.c \
              $(LIBWWW_DIR)/HTFormat.c $(LIBWWW_DIR)/HTInit.c $(LIBWWW_DIR)/HTMIME.c \
              $(LIBWWW_DIR)/HTHistory.c $(LIBWWW_DIR)/HTNews.c $(LIBWWW_DIR)/HTGopher.c \
              $(LIBWWW_DIR)/HTTelnet.c $(LIBWWW_DIR)/HTWSRC.c $(LIBWWW_DIR)/HTCharset.c \
              $(LIBWWW_DIR)/HTBTree.c $(LIBWWW_DIR)/HTAABrow.c $(LIBWWW_DIR)/HTAAUtil.c \
              $(LIBWWW_DIR)/HTAssoc.c $(LIBWWW_DIR)/HTUU.c $(LIBWWW_DIR)/HTAAProt.c \
              $(LIBWWW_DIR)/HTAAServ.c $(LIBWWW_DIR)/FOSI.c $(LIBWWW_DIR)/FOSIDTD.c \
              $(LIBWWW_DIR)/HTLex.c $(LIBWWW_DIR)/HTGroup.c $(LIBWWW_DIR)/HTACL.c \
              $(LIBWWW_DIR)/HTPasswd.c $(LIBWWW_DIR)/HTAuth.c $(LIBWWW_DIR)/HTAAFile.c \
              $(LIBWWW_DIR)/HTSSL.c $(LIBWWW_DIR)/HTTPS.c $(LIBWWW_DIR)/HTWayback.c \
              $(LIBWWW_DIR)/HTKeepAlive.c
LIBWWW_OBJS = $(LIBWWW_SRCS:.c=.o)

$(LIBWWW): $(LIBWWW_OBJS)
	@echo "=== Building libWWW ==="
	$(AR) $@ $^
	$(RANLIB) $@
	@echo ""

$(LIBWWW_DIR)/%.o: $(LIBWWW_DIR)/%.c
	$(CC) $(CFLAGS) -I$(LIBWWW_DIR) $(ICU_INCLUDES) $(SSL_INCLUDES) -DACCESS_AUTH -DVIOLA -c $< -o $@

# libXPM (XPM image support)
LIBXPM_SRCS = $(LIBXPM_DIR)/data.c $(LIBXPM_DIR)/create.c $(LIBXPM_DIR)/visual.c \
              $(LIBXPM_DIR)/misc.c $(LIBXPM_DIR)/rgb.c $(LIBXPM_DIR)/scan.c \
              $(LIBXPM_DIR)/parse.c $(LIBXPM_DIR)/XpmWrFFrP.c $(LIBXPM_DIR)/XpmRdFToP.c \
              $(LIBXPM_DIR)/XpmCrPFData.c $(LIBXPM_DIR)/XpmCrDataFP.c \
              $(LIBXPM_DIR)/XpmWrFFrI.c $(LIBXPM_DIR)/XpmRdFToI.c \
              $(LIBXPM_DIR)/XpmCrIFData.c $(LIBXPM_DIR)/XpmCrDataFI.c
LIBXPM_OBJS = $(LIBXPM_SRCS:.c=.o)

$(LIBXPM): $(LIBXPM_OBJS)
	@echo "=== Building libXpm ==="
	$(AR) $@ $^
	$(RANLIB) $@
	@echo ""

$(LIBXPM_DIR)/%.o: $(LIBXPM_DIR)/%.c
	$(CC) $(CFLAGS_LIBS) $(INCLUDES) -I$(LIBXPM_DIR) -DZPIPE -DWORD64 -c $< -o $@

# libXPA (X Pixmap Allocator)
LIBXPA_SRCS = $(LIBXPA_DIR)/xpa.c
LIBXPA_OBJS = $(LIBXPA_SRCS:.c=.o)

$(LIBXPA): $(LIBXPA_OBJS)
	@echo "=== Building libXpa ==="
	$(AR) $@ $^
	$(RANLIB) $@
	@echo ""

$(LIBXPA_DIR)/%.o: $(LIBXPA_DIR)/%.c
	$(CC) $(CFLAGS_LIBS) $(INCLUDES) -I$(LIBXPA_DIR) -c $< -o $@

# libIMG (Image loading library)
LIBIMG_SRCS = $(LIBIMG_DIR)/bright.c $(LIBIMG_DIR)/clip.c $(LIBIMG_DIR)/cmuwmraster.c \
              $(LIBIMG_DIR)/compress.c $(LIBIMG_DIR)/dither.c $(LIBIMG_DIR)/faces.c \
              $(LIBIMG_DIR)/fbm.c $(LIBIMG_DIR)/fill.c $(LIBIMG_DIR)/g3.c \
              $(LIBIMG_DIR)/gif.c $(LIBIMG_DIR)/halftone.c $(LIBIMG_DIR)/imagetypes.c \
              $(LIBIMG_DIR)/img.c $(LIBIMG_DIR)/mac.c $(LIBIMG_DIR)/mcidas.c \
              $(LIBIMG_DIR)/mc_tables.c $(LIBIMG_DIR)/merge.c $(LIBIMG_DIR)/misc.c \
              $(LIBIMG_DIR)/new.c $(LIBIMG_DIR)/options.c $(LIBIMG_DIR)/path.c \
              $(LIBIMG_DIR)/pbm.c $(LIBIMG_DIR)/pcx.c $(LIBIMG_DIR)/reduce.c \
              $(LIBIMG_DIR)/rle.c $(LIBIMG_DIR)/rlelib.c $(LIBIMG_DIR)/root.c \
              $(LIBIMG_DIR)/rotate.c $(LIBIMG_DIR)/send.c $(LIBIMG_DIR)/smooth.c \
              $(LIBIMG_DIR)/sunraster.c $(LIBIMG_DIR)/value.c $(LIBIMG_DIR)/window.c \
              $(LIBIMG_DIR)/xbitmap.c $(LIBIMG_DIR)/xpixmap.c \
              $(LIBIMG_DIR)/xwd.c $(LIBIMG_DIR)/zio.c $(LIBIMG_DIR)/zoom.c $(LIBIMG_DIR)/libxli.c
LIBIMG_OBJS = $(LIBIMG_SRCS:.c=.o)

$(LIBIMG): $(LIBIMG_OBJS)
	@echo "=== Building libIMG ==="
	$(AR) $@ $^
	$(RANLIB) $@
	@echo ""

$(LIBIMG_DIR)/%.o: $(LIBIMG_DIR)/%.c
	$(CC) $(CFLAGS_LIBS) -I$(LIBIMG_DIR) $(INCLUDES) -c $< -o $@

# libStyle (Style library) - single object file
$(LIBSTYLE): $(LIBSTYLE_DIR)/libstg.c
	@echo "=== Building libStyle ==="
	$(CC) $(CFLAGS_LIBS) $(INCLUDES) -I$(LIBSTYLE_DIR) -c $< -o $@
	@echo ""

# ============================================================================
# Viola Browser
# ============================================================================

VIOLA_SRCS = $(VIOLA_DIR)/DefaultStyles.c $(VIOLA_DIR)/ast.c $(VIOLA_DIR)/attr.c \
             $(VIOLA_DIR)/biop.c $(VIOLA_DIR)/cexec.c $(VIOLA_DIR)/cgen.c \
             $(VIOLA_DIR)/cl_AC_SGML_txt.c $(VIOLA_DIR)/cl_BCard.c $(VIOLA_DIR)/cl_FCard.c \
             $(VIOLA_DIR)/cl_GIF.c $(VIOLA_DIR)/cl_HTML.c $(VIOLA_DIR)/cl_PS.c \
             $(VIOLA_DIR)/cl_TTY.c $(VIOLA_DIR)/cl_XBM.c $(VIOLA_DIR)/cl_XBMBG.c \
             $(VIOLA_DIR)/cl_XBMButton.c $(VIOLA_DIR)/cl_XPM.c $(VIOLA_DIR)/cl_XPMBG.c \
             $(VIOLA_DIR)/cl_XPMButton.c $(VIOLA_DIR)/cl_client.c $(VIOLA_DIR)/cl_cosmic.c \
             $(VIOLA_DIR)/cl_dial.c $(VIOLA_DIR)/cl_field.c $(VIOLA_DIR)/cl_generic.c \
             $(VIOLA_DIR)/cl_glass.c $(VIOLA_DIR)/cl_hpane.c $(VIOLA_DIR)/cl_menu.c \
             $(VIOLA_DIR)/cl_pane.c $(VIOLA_DIR)/cl_project.c $(VIOLA_DIR)/cl_radio.c \
             $(VIOLA_DIR)/cl_rubber.c $(VIOLA_DIR)/cl_slider.c $(VIOLA_DIR)/cl_socket.c \
             $(VIOLA_DIR)/cl_stack.c $(VIOLA_DIR)/cl_toggle.c $(VIOLA_DIR)/cl_tray.c \
             $(VIOLA_DIR)/cl_txt.c $(VIOLA_DIR)/cl_txtButton.c $(VIOLA_DIR)/cl_txtDisp.c \
             $(VIOLA_DIR)/cl_txtEdit.c $(VIOLA_DIR)/cl_txtEditLine.c $(VIOLA_DIR)/cl_txtLabel.c \
             $(VIOLA_DIR)/cl_vpane.c $(VIOLA_DIR)/class.c $(VIOLA_DIR)/classlist.c \
             $(VIOLA_DIR)/error.c $(VIOLA_DIR)/event.c $(VIOLA_DIR)/event_x.c \
             $(VIOLA_DIR)/file.c $(VIOLA_DIR)/glib.c $(VIOLA_DIR)/glib_x.c \
             $(VIOLA_DIR)/gram.c $(VIOLA_DIR)/hash.c $(VIOLA_DIR)/membership.c \
             $(VIOLA_DIR)/html.c $(VIOLA_DIR)/html2.c $(VIOLA_DIR)/fosi.c \
             $(VIOLA_DIR)/sgml.c $(VIOLA_DIR)/stgcall.c $(VIOLA_DIR)/ident.c \
             $(VIOLA_DIR)/loader.c $(VIOLA_DIR)/main.c $(VIOLA_DIR)/method.c \
             $(VIOLA_DIR)/misc.c $(VIOLA_DIR)/mystrings.c $(VIOLA_DIR)/obj.c \
             $(VIOLA_DIR)/packet.c $(VIOLA_DIR)/violalex.c $(VIOLA_DIR)/slib.c \
             $(VIOLA_DIR)/sys.c $(VIOLA_DIR)/tfed.c $(VIOLA_DIR)/tfed2.c \
             $(VIOLA_DIR)/vlist.c $(VIOLA_DIR)/HTML_share.c $(VIOLA_DIR)/htmath.c \
             $(VIOLA_DIR)/viola.c $(VIOLA_DIR)/msgHandler.c $(VIOLA_DIR)/objs.c \
             $(VIOLA_DIR)/HTML_style.c $(VIOLA_DIR)/memory_debug.c
VIOLA_OBJS = $(VIOLA_SRCS:.c=.o)

.PHONY: viola
viola: $(VIOLA)

$(VIOLA): $(VIOLA_OBJS) $(LIBWWW) $(LIBXPM) $(LIBXPA) $(LIBIMG) $(LIBSTYLE)
	@echo "=== Linking Viola ==="
	$(CC) $(LDFLAGS) -o $@ $(VIOLA_OBJS) $(LIBWWW) $(LIBXPM) $(LIBXPA) $(LIBIMG) $(LIBSTYLE) $(LIBS)
	@echo "=== Viola built successfully! ==="
	@ls -lh $@
	@echo ""

# Compile Viola sources with automatic dependency generation
$(VIOLA_DIR)/%.o: $(VIOLA_DIR)/%.c
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDES) -I$(VIOLA_DIR) -I$(LIBWWW_DIR) -c $< -o $@

# Generate .h files from .v scripts (hex encoding for C string literals)
$(VIOLA_DIR)/embeds/%.v.h: $(VIOLA_DIR)/embeds/%.v
	@printf '"' > $@
	@hexdump -ve '1/1 "x%.2x"' $< | sed 's/x/\\x/g' >> $@
	@printf '"\n' >> $@

# objs.o depends on all .h files being generated
$(VIOLA_DIR)/objs.o: $(VIOLA_DIR)/objs.c $(patsubst %.v,%.v.h,$(wildcard $(VIOLA_DIR)/embeds/*.v))

# Generate gram.c from gram.y using byacc (Berkeley Yacc)
# Note: We use byacc instead of GNU Bison for compatibility with old SunOS yacc
$(VIOLA_DIR)/gram.c: $(VIOLA_DIR)/gram.y
	@echo "=== Generating gram.c from gram.y with byacc ==="
	@if ! command -v byacc >/dev/null 2>&1; then \
		echo "ERROR: byacc not found. Install with: brew install byacc"; \
		exit 1; \
	fi
	cd $(VIOLA_DIR) && byacc gram.y && mv y.tab.c gram.c
	@echo "gram.c generated successfully"

# Include automatically generated dependencies
-include $(VIOLA_OBJS:.o=.d)

# ============================================================================
# VW Browser (Motif interface)
# ============================================================================

VW_SRCS = $(VW_DIR)/box.c $(VW_DIR)/callbacks.c $(VW_DIR)/catalog.c \
          $(VW_DIR)/cursor.c $(VW_DIR)/dialog.c $(VW_DIR)/edit.c \
          $(VW_DIR)/fileIO.c $(VW_DIR)/fonts.c $(VW_DIR)/history.c \
          $(VW_DIR)/hotlist.c $(VW_DIR)/mail.c $(VW_DIR)/menu.c \
          $(VW_DIR)/selection.c $(VW_DIR)/vw.c
VW_OBJS = $(VW_SRCS:.c=.o)

# VW needs all Viola objects except main.o
VIOLA_OBJS_NO_MAIN = $(filter-out $(VIOLA_DIR)/main.o, $(VIOLA_OBJS))

.PHONY: vw
vw: $(VW)

$(VW): $(VW_OBJS) $(VIOLA_OBJS_NO_MAIN) $(LIBWWW) $(LIBXPM) $(LIBXPA) $(LIBIMG) $(LIBSTYLE)
	@echo "=== Linking VW ==="
	$(CC) $(LDFLAGS) -o $@ $(VW_OBJS) $(VIOLA_OBJS_NO_MAIN) \
	    $(LIBWWW) $(LIBXPM) $(LIBXPA) $(LIBIMG) $(LIBSTYLE) $(LIBS)
	@echo "=== VW built successfully! ==="
	@ls -lh $@
	@echo ""

# Compile VW sources with automatic dependency generation
$(VW_DIR)/%.o: $(VW_DIR)/%.c
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDES) -I$(VW_DIR) -I$(VIOLA_DIR) -I$(LIBWWW_DIR) -c $< -o $@

# Include automatically generated dependencies
-include $(VW_OBJS:.o=.d)

# ============================================================================
# Utility targets
# ============================================================================

.PHONY: clean
clean:
	@echo "=== Cleaning object files and dependencies ==="
	find $(SRC_DIR) \( -name '*.o' -o -name '*.d' \) -delete
	@echo "=== Cleaning generated embed headers ==="
	find $(VIOLA_DIR)/embeds -name '*.v.h' -delete
	@echo "Done"

.PHONY: distclean
distclean: clean
	@echo "=== Cleaning all build artifacts ==="
	rm -f $(LIBWWW) $(LIBXPM) $(LIBXPA) $(LIBIMG) $(LIBSTYLE)
	rm -f $(VIOLA) $(VW)
	@echo "Done"

# ============================================================================
# Sanitizer builds
# ============================================================================

.PHONY: asan
asan:
	@echo "=== Building with AddressSanitizer (ASan) ==="
	@$(MAKE) clean
	@$(MAKE) \
		CC=clang \
		CFLAGS='$(CFLAGS) -O1 -g -fno-omit-frame-pointer -fsanitize=address' \
		CFLAGS_LIBS='$(CFLAGS_LIBS) -O1 -g -fno-omit-frame-pointer -fsanitize=address' \
		LDFLAGS='$(LDFLAGS) -fsanitize=address' all
	@echo "Tip: run with ASAN_OPTIONS=halt_on_error=1:strict_string_checks=1"

.PHONY: ubsan
ubsan:
	@echo "=== Building with UndefinedBehaviorSanitizer (UBSan) ==="
	@$(MAKE) clean
	@$(MAKE) \
		CC=clang \
		CFLAGS='$(CFLAGS) -O1 -g -fno-omit-frame-pointer -fsanitize=undefined' \
		CFLAGS_LIBS='$(CFLAGS_LIBS) -O1 -g -fno-omit-frame-pointer -fsanitize=undefined' \
		LDFLAGS='$(LDFLAGS) -fsanitize=undefined' all

.PHONY: san
san:
	@echo "=== Building with ASan + UBSan ==="
	@$(MAKE) clean
	@$(MAKE) \
		CC=clang \
		CFLAGS='$(CFLAGS) -O1 -g -fno-omit-frame-pointer -fsanitize=address,undefined' \
		CFLAGS_LIBS='$(CFLAGS_LIBS) -O1 -g -fno-omit-frame-pointer -fsanitize=address,undefined' \
		LDFLAGS='$(LDFLAGS) -fsanitize=address,undefined' all

.PHONY: install
install: $(VW) $(VIOLA)
	@echo "=== Installing binaries ==="
	@mkdir -p $(HOME)/bin
	install -m 755 $(VW) $(HOME)/bin/
	install -m 755 $(VIOLA) $(HOME)/bin/
	@echo "Installed to $(HOME)/bin/"

# ============================================================================
# Development helpers
# ============================================================================

.PHONY: check-64bit
check-64bit:
	@echo "=== Checking for 64-bit migration issues ==="
	@echo "This will show warnings about long->int truncation and related problems"
	@$(MAKE) clean
	@$(MAKE) WARN_64BIT=1 all 2>&1 | tee 64bit-warnings.log
	@echo ""
	@echo "Warnings saved to: 64bit-warnings.log"

.PHONY: rebuild
rebuild: distclean all

.PHONY: libs-clean
libs-clean:
	@echo "=== Cleaning libraries ==="
	rm -f $(LIBWWW) $(LIBXPM) $(LIBXPA) $(LIBIMG) $(LIBSTYLE)
	find $(SRC_DIR)/libWWW $(SRC_DIR)/libXPM $(SRC_DIR)/libXPA $(SRC_DIR)/libIMG $(SRC_DIR)/libStyle -name '*.o' -delete
	@echo "Done"

.PHONY: info
info:
	@echo "ViolaWWW Build Configuration"
	@echo "=============================="
	@echo "CC:       $(CC)"
	@echo "CFLAGS:   $(CFLAGS)"
	@echo "LDFLAGS:  $(LDFLAGS)"
	@echo "LIBS:     $(LIBS)"
	@echo ""
	@echo "Detected paths:"
	@echo "  Homebrew:   $(BREW_PREFIX)"
	@echo "  OpenMotif:  $(OPENMOTIF_PREFIX)"
	@echo ""
	@echo "Source directories:"
	@echo "  libWWW:   $(LIBWWW_DIR)"
	@echo "  libXPM:   $(LIBXPM_DIR)"
	@echo "  libXPA:   $(LIBXPA_DIR)"
	@echo "  libIMG:   $(LIBIMG_DIR)"
	@echo "  libStyle: $(LIBSTYLE_DIR)"
	@echo "  Viola:    $(VIOLA_DIR)"
	@echo "  VW:       $(VW_DIR)"

# Check libWWW directory exists
.PHONY: check-libwww
check-libwww:
	@test -d $(LIBWWW_DIR) || echo "libWWW directory not found"

# Unit tests
.PHONY: test
test:
	@$(MAKE) -C test test

.PHONY: clean-test
clean-test:
	@$(MAKE) -C test clean

# ============================================================================
# Include and Library Analysis
# ============================================================================

# Check for unused includes using include-what-you-use
.PHONY: check-includes
check-includes:
	@echo "=== Checking for unused includes with include-what-you-use ==="
	@if ! command -v include-what-you-use >/dev/null 2>&1; then \
		echo "ERROR: include-what-you-use not found."; \
		echo "Install with: brew install include-what-you-use"; \
		echo ""; \
		echo "Alternative: use 'make check-includes-manual' for manual analysis"; \
		exit 1; \
	fi
	@echo "Analyzing glib_x.c..."
	@include-what-you-use -Xiwyu --no_fwd_decls -Xiwyu --max_line_length=120 \
		$(CFLAGS) $(INCLUDES) -I$(VIOLA_DIR) -I$(LIBWWW_DIR) \
		$(VIOLA_DIR)/glib_x.c 2>&1 | tee iwyu-glib_x.log
	@echo ""
	@echo "Results saved to: iwyu-glib_x.log"

# Check includes for all Viola sources
.PHONY: check-includes-all
check-includes-all:
	@echo "=== Checking all Viola sources for unused includes ==="
	@if ! command -v include-what-you-use >/dev/null 2>&1; then \
		echo "ERROR: include-what-you-use not found."; \
		echo "Install with: brew install include-what-you-use"; \
		exit 1; \
	fi
	@for src in $(VIOLA_SRCS); do \
		echo "Analyzing $$src..."; \
		include-what-you-use -Xiwyu --no_fwd_decls \
			$(CFLAGS) $(INCLUDES) -I$(VIOLA_DIR) -I$(LIBWWW_DIR) \
			$$src 2>&1 | grep -A 20 "should remove these lines" || true; \
	done | tee iwyu-all.log
	@echo "Results saved to: iwyu-all.log"

# Manual check: show which headers are actually included
.PHONY: check-includes-manual
check-includes-manual:
	@echo "=== Manual include analysis for glib_x.c ==="
	@echo "This will show all included headers in order:"
	@echo ""
	@$(CC) -H $(CFLAGS) $(INCLUDES) -I$(VIOLA_DIR) -I$(LIBWWW_DIR) \
		-c $(VIOLA_DIR)/glib_x.c -o /dev/null 2>&1 | head -100
	@echo ""
	@echo "Headers with multiple dots (.) are nested includes."
	@echo "To see full analysis, run without 'head -100'"

# Analyze preprocessor output to see what's actually used
.PHONY: check-preprocessor
check-preprocessor:
	@echo "=== Generating preprocessed output for glib_x.c ==="
	@$(CC) -E -dD $(CFLAGS) $(INCLUDES) -I$(VIOLA_DIR) -I$(LIBWWW_DIR) \
		$(VIOLA_DIR)/glib_x.c > glib_x.preprocessed.c
	@echo "Preprocessed output saved to: glib_x.preprocessed.c"
	@echo "File size: $$(wc -l < glib_x.preprocessed.c) lines"

# Check which libraries are actually used in the final binary
.PHONY: check-libs
check-libs:
	@echo "=== Checking linked libraries ==="
	@if [ ! -f $(VIOLA) ]; then \
		echo "ERROR: Viola binary not found. Build it first with 'make viola'"; \
		exit 1; \
	fi
	@echo ""
	@echo "Libraries linked to Viola:"
	@otool -L $(VIOLA)
	@echo ""
	@echo "=== Checking for unused library dependencies ==="
	@echo "Libraries from Makefile LIBS: $(LIBS)"
	@echo ""
	@echo "Note: On macOS, unused libraries may still be linked."
	@echo "Consider using 'make check-symbols' to see actual symbol usage."

# Check which symbols are actually used from libraries
.PHONY: check-symbols
check-symbols:
	@echo "=== Analyzing symbol usage in Viola binary ==="
	@if [ ! -f $(VIOLA) ]; then \
		echo "ERROR: Viola binary not found. Build it first with 'make viola'"; \
		exit 1; \
	fi
	@echo ""
	@echo "Undefined symbols (from external libraries):"
	@nm -u $(VIOLA) | head -50
	@echo ""
	@echo "Total undefined symbols: $$(nm -u $(VIOLA) | wc -l)"
	@echo ""
	@echo "For full list, run: nm -u $(VIOLA_DIR)/viola"

# Build with verbose warnings about unused code
.PHONY: check-unused
check-unused:
	@echo "=== Building with unused code warnings ==="
	@$(MAKE) clean
	@$(MAKE) \
		CC=clang \
		CFLAGS='$(CFLAGS) -Wunused -Wunused-parameter -Wunused-variable -Wunused-function -Wunused-macros' \
		CFLAGS_LIBS='$(CFLAGS_LIBS) -Wunused -Wunused-parameter -Wunused-variable -Wunused-function' \
		all 2>&1 | tee unused-warnings.log
	@echo ""
	@echo "Warnings saved to: unused-warnings.log"

# Summary of all analysis tools
.PHONY: check-help
check-help:
	@echo "Include and Library Analysis Tools"
	@echo "===================================="
	@echo ""
	@echo "Available targets:"
	@echo "  check-includes        - Use include-what-you-use on glib_x.c (requires IWYU)"
	@echo "  check-includes-all    - Check all Viola source files (requires IWYU)"
	@echo "  check-includes-manual - Show include hierarchy using compiler -H flag"
	@echo "  check-preprocessor    - Generate preprocessed output to analyze macros"
	@echo "  check-libs            - Show linked libraries in final binary"
	@echo "  check-symbols         - Show symbols used from external libraries"
	@echo "  check-unused          - Build with warnings for unused code"
	@echo ""
	@echo "Quick start:"
	@echo "  1. make check-includes-manual  (no extra tools needed)"
	@echo "  2. make check-unused           (checks for unused variables/functions)"
	@echo "  3. brew install include-what-you-use && make check-includes"

