# ViolaWWW Browser Build System
# Modern Makefile for macOS (Darwin)

# Build configuration
CC = cc
AR = ar rcs
RANLIB = ranlib

# Auto-detect Homebrew paths
BREW_PREFIX := $(shell brew --prefix 2>/dev/null || echo /opt/homebrew)
OPENMOTIF_PREFIX := $(shell brew --prefix openmotif 2>/dev/null || echo $(BREW_PREFIX)/opt/openmotif)

# Compiler flags
ARCH_FLAGS = -arch arm64
CFLAGS = -Os $(ARCH_FLAGS) -std=gnu89 -Wno-everything -D__DARWIN__
CFLAGS_LIBS = -Os $(ARCH_FLAGS) -Wno-everything -no-cpp-precomp -fno-common \
              -D__DARWIN__ -DNO_ALLOCA -DCSRG_BASED
INCLUDES = -I$(BREW_PREFIX)/include \
           -I$(OPENMOTIF_PREFIX)/include \
           -I/opt/X11/include

# Linker flags
LDFLAGS = $(ARCH_FLAGS) -L$(BREW_PREFIX)/lib \
          -L$(OPENMOTIF_PREFIX)/lib \
          -L/opt/X11/lib
LIBS = -lXm -lXext -lXmu -lXt -lSM -lICE -lX11 -lm

# Source directories
SRC_DIR = src
LIBWWW_DIR = $(SRC_DIR)/libWWW/Library/Implementation
LIBWWW_DARWIN = $(SRC_DIR)/libWWW/Library/darwin
LIBXPM_DIR = $(SRC_DIR)/libXPM
LIBXPA_DIR = $(SRC_DIR)/libXPA/src
LIBIMG_DIR = $(SRC_DIR)/libIMG
LIBSTYLE_DIR = $(SRC_DIR)/libStyle
VIOLA_DIR = $(SRC_DIR)/viola
VW_DIR = $(SRC_DIR)/vw

# Library targets
LIBWWW = $(LIBWWW_DARWIN)/libwww.a
LIBXPM = $(LIBXPM_DIR)/libXpm.a
LIBXPA = $(LIBXPA_DIR)/libXpa.a
LIBIMG = $(LIBIMG_DIR)/libIMG.a
LIBSTYLE = $(LIBSTYLE_DIR)/libstg.o

# Binary targets
VIOLA = $(VIOLA_DIR)/viola
VW = $(VW_DIR)/vw

# Default target
.PHONY: all
all: $(VW) $(VIOLA)

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
	@echo "  clean      - Remove object files"
	@echo "  distclean  - Remove all build artifacts"
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
              $(LIBWWW_DIR)/HTTelnet.c $(LIBWWW_DIR)/HTWSRC.c \
              $(LIBWWW_DIR)/HTBTree.c $(LIBWWW_DIR)/HTAABrow.c $(LIBWWW_DIR)/HTAAUtil.c \
              $(LIBWWW_DIR)/HTAssoc.c $(LIBWWW_DIR)/HTUU.c $(LIBWWW_DIR)/HTAAProt.c \
              $(LIBWWW_DIR)/HTAAServ.c $(LIBWWW_DIR)/FOSI.c $(LIBWWW_DIR)/FOSIDTD.c \
              $(LIBWWW_DIR)/HTLex.c $(LIBWWW_DIR)/HTGroup.c $(LIBWWW_DIR)/HTACL.c \
              $(LIBWWW_DIR)/HTPasswd.c $(LIBWWW_DIR)/HTAuth.c $(LIBWWW_DIR)/HTAAFile.c
LIBWWW_OBJS = $(patsubst $(LIBWWW_DIR)/%.c,$(LIBWWW_DARWIN)/%.o,$(LIBWWW_SRCS))

$(LIBWWW): $(LIBWWW_OBJS)
	@echo "=== Building libWWW ==="
	@mkdir -p $(LIBWWW_DARWIN)
	$(AR) $@ $^
	$(RANLIB) $@
	@echo ""

$(LIBWWW_DARWIN)/%.o: $(LIBWWW_DIR)/%.c
	@mkdir -p $(LIBWWW_DARWIN)
	$(CC) $(CFLAGS) -I$(LIBWWW_DIR) -DACCESS_AUTH -DVIOLA -c $< -o $@

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
             $(VIOLA_DIR)/HTML_style.c
VIOLA_OBJS = $(VIOLA_SRCS:.c=.o)

.PHONY: viola
viola: $(VIOLA)

$(VIOLA): $(VIOLA_OBJS) $(LIBWWW) $(LIBXPM) $(LIBXPA) $(LIBIMG) $(LIBSTYLE)
	@echo "=== Linking Viola ==="
	$(CC) $(LDFLAGS) -o $@ $(VIOLA_OBJS) $(LIBWWW) $(LIBXPM) $(LIBXPA) $(LIBIMG) $(LIBSTYLE) $(LIBS)
	@echo "=== Viola built successfully! ==="
	@ls -lh $@
	@echo ""

$(VIOLA_DIR)/%.o: $(VIOLA_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -I$(VIOLA_DIR) -I$(LIBWWW_DIR) -c $< -o $@

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

$(VW_DIR)/%.o: $(VW_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -I$(VW_DIR) -I$(VIOLA_DIR) -I$(LIBWWW_DIR) -c $< -o $@

# ============================================================================
# Utility targets
# ============================================================================

.PHONY: clean
clean:
	@echo "=== Cleaning object files ==="
	find $(SRC_DIR) -name '*.o' -delete
	@echo "Done"

.PHONY: distclean
distclean: clean
	@echo "=== Cleaning all build artifacts ==="
	rm -f $(LIBWWW) $(LIBXPM) $(LIBXPA) $(LIBIMG) $(LIBSTYLE)
	rm -f $(VIOLA) $(VW)
	@echo "Done"

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

# Make sure libWWW has its own Makefile
.PHONY: check-libwww
check-libwww:
	@if [ ! -f $(LIBWWW_DIR)/Makefile ]; then \
		echo "Creating libWWW Makefile..."; \
		cd $(LIBWWW_DIR) && $(MAKE) -f ../../All/darwin/Makefile.include; \
	fi

