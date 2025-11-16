# Test suite Makefile for ViolaWWW
# Run: make test

# Detect project root (parent directory)
PROJECT_ROOT := ..
BUILD_DIR := build

# Compiler settings from main project
CC := cc
CFLAGS := -Os -arch arm64 -std=gnu17 -Wno-everything -funsigned-char
CFLAGS_LIBS := $(CFLAGS) -D__DARWIN__ -DUSE_ICU -DUSE_SSL -funsigned-char

# Include paths
ICU_INCLUDES := -I/opt/homebrew/opt/icu4c@77/include
SSL_INCLUDES := -I/opt/homebrew/opt/openssl@3/include
ICU_LIBS := -L/opt/homebrew/opt/icu4c@77/lib -licui18n -licuuc -licudata -liconv

# Check if ICU is available
ICU_AVAILABLE := $(shell pkg-config --exists icu-uc 2>/dev/null && echo yes || echo no)

# Source paths
LIBSTYLE_DIR := $(PROJECT_ROOT)/src/libStyle
VIOLA_DIR := $(PROJECT_ROOT)/src/viola
LIBWWW_DIR := $(PROJECT_ROOT)/src/libWWW

# All tests (add new tests here!)
TESTS := test-stg-minors test-stg-context test-xpm-injection test-htcharset test-wayback-detection test-biop test-hash-memory test-mystrings

.PHONY: all test clean $(TESTS)

# Default target
all: test

# Run all tests
test:
	@echo ""
	@echo "======================================="
	@echo "Running ViolaWWW Test Suite"
	@echo "======================================="
	@echo ""
	@mkdir -p $(BUILD_DIR)
	@> $(BUILD_DIR)/results.txt
	-@$(MAKE) test-stg-minors >$(BUILD_DIR)/test-stg-minors.log 2>&1 && echo "PASS" >> $(BUILD_DIR)/results.txt && echo "  ✓ test-stg-minors: PASS" || (echo "FAIL" >> $(BUILD_DIR)/results.txt && echo "  ✗ test-stg-minors: FAIL")
	-@$(MAKE) test-stg-context >$(BUILD_DIR)/test-stg-context.log 2>&1 && echo "PASS" >> $(BUILD_DIR)/results.txt && echo "  ✓ test-stg-context: PASS" || (echo "FAIL" >> $(BUILD_DIR)/results.txt && echo "  ✗ test-stg-context: FAIL")
	-@$(MAKE) test-xpm-injection >$(BUILD_DIR)/test-xpm-injection.log 2>&1 && echo "PASS" >> $(BUILD_DIR)/results.txt && echo "  ✓ test-xpm-injection: PASS" || (echo "FAIL" >> $(BUILD_DIR)/results.txt && echo "  ✗ test-xpm-injection: FAIL")
	-@$(MAKE) test-htcharset >$(BUILD_DIR)/test-htcharset.log 2>&1 && echo "PASS" >> $(BUILD_DIR)/results.txt && echo "  ✓ test-htcharset: PASS" || (echo "FAIL" >> $(BUILD_DIR)/results.txt && echo "  ✗ test-htcharset: FAIL")
	-@$(MAKE) test-wayback-detection >$(BUILD_DIR)/test-wayback-detection.log 2>&1 && echo "PASS" >> $(BUILD_DIR)/results.txt && echo "  ✓ test-wayback-detection: PASS" || (echo "FAIL" >> $(BUILD_DIR)/results.txt && echo "  ✗ test-wayback-detection: FAIL")
	-@$(MAKE) test-biop >$(BUILD_DIR)/test-biop.log 2>&1 && echo "PASS" >> $(BUILD_DIR)/results.txt && echo "  ✓ test-biop: PASS" || (echo "FAIL" >> $(BUILD_DIR)/results.txt && echo "  ✗ test-biop: FAIL")
	-@$(MAKE) test-hash-memory >$(BUILD_DIR)/test-hash-memory.log 2>&1 && echo "PASS" >> $(BUILD_DIR)/results.txt && echo "  ✓ test-hash-memory: PASS" || (echo "FAIL" >> $(BUILD_DIR)/results.txt && echo "  ✗ test-hash-memory: FAIL")
	-@$(MAKE) test-mystrings >$(BUILD_DIR)/test-mystrings.log 2>&1 && echo "PASS" >> $(BUILD_DIR)/results.txt && echo "  ✓ test-mystrings: PASS" || (echo "FAIL" >> $(BUILD_DIR)/results.txt && echo "  ✗ test-mystrings: FAIL")
	@echo ""
	@echo "======================================="
	@echo "Test Suite Summary"
	@echo "======================================="
	@passed=$$(grep "^PASS$$" $(BUILD_DIR)/results.txt 2>/dev/null | wc -l | tr -d ' '); \
	failed=$$(grep "^FAIL$$" $(BUILD_DIR)/results.txt 2>/dev/null | wc -l | tr -d ' '); \
	total=$$((passed + failed)); \
	echo "Passed: $$passed / $$total"; \
	if [ $$failed -gt 0 ]; then \
		echo "Failed: $$failed tests"; \
		echo ""; \
		echo "Check logs in test/$(BUILD_DIR)/ for details"; \
		echo "OVERALL: FAILURE"; \
	else \
		echo "OVERALL: SUCCESS"; \
	fi
	@echo "======================================="
	@echo ""

# Individual test targets
test-biop: test_biop.c test_biop_support.c $(PROJECT_ROOT)/src/viola/biop.o $(PROJECT_ROOT)/src/viola/mystrings.o
	@echo ""
	@echo "Building biop string ops tests..."
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -I$(PROJECT_ROOT)/src/viola -o $(BUILD_DIR)/test_biop test_biop.c test_biop_support.c \
		$(PROJECT_ROOT)/src/viola/biop.o $(PROJECT_ROOT)/src/viola/mystrings.o
	@./$(BUILD_DIR)/test_biop

test-stg-minors: test_stg_minors.c $(LIBSTYLE_DIR)/libstg.o $(VIOLA_DIR)/mystrings.o
	@echo ""
	@echo "Building STG minors tests..."
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS_LIBS) -I$(LIBSTYLE_DIR) -I$(VIOLA_DIR) \
		$(ICU_INCLUDES) $(SSL_INCLUDES) \
		-o $(BUILD_DIR)/test_stg_minors test_stg_minors.c \
		$(LIBSTYLE_DIR)/libstg.o $(VIOLA_DIR)/mystrings.o \
		$(ICU_LIBS)
	@./$(BUILD_DIR)/test_stg_minors

test-stg-context: test_stg_context.c $(LIBSTYLE_DIR)/libstg.o $(VIOLA_DIR)/mystrings.o
	@echo ""
	@echo "Building STG context tests..."
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS_LIBS) -I$(LIBSTYLE_DIR) -I$(VIOLA_DIR) \
		$(ICU_INCLUDES) $(SSL_INCLUDES) \
		-o $(BUILD_DIR)/test_stg_context test_stg_context.c \
		$(LIBSTYLE_DIR)/libstg.o $(VIOLA_DIR)/mystrings.o \
		$(ICU_LIBS)
	@./$(BUILD_DIR)/test_stg_context

test-xpm-injection: test_xpm_injection.c
	@echo ""
	@echo "Building XPM security tests..."
	@mkdir -p $(BUILD_DIR)
	@$(CC) -o $(BUILD_DIR)/test_xpm_injection test_xpm_injection.c
	@./$(BUILD_DIR)/test_xpm_injection

test-htcharset: test_htcharset.c $(PROJECT_ROOT)/src/libWWW/HTCharset.o
ifeq ($(ICU_AVAILABLE),yes)
	@echo ""
	@echo "Building HTCharset tests..."
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(ICU_INCLUDES) -I$(LIBWWW_DIR) \
		-o $(BUILD_DIR)/test_htcharset test_htcharset.c \
		$(PROJECT_ROOT)/src/libWWW/HTCharset.o \
		$(ICU_LIBS)
	@./$(BUILD_DIR)/test_htcharset
else
	@echo "⚠ ICU not available - skipping HTCharset tests"
endif

test-wayback-detection: test_wayback_detection.c
	@echo ""
	@echo "Building Web Archive URL detection tests..."
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -o $(BUILD_DIR)/test_wayback_detection test_wayback_detection.c
	@./$(BUILD_DIR)/test_wayback_detection

test-hash-memory: test_hash_memory.c $(PROJECT_ROOT)/src/viola/hash.o $(PROJECT_ROOT)/src/viola/mystrings.o
	@echo ""
	@echo "Building hash table memory leak tests..."
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -I$(PROJECT_ROOT)/src/viola -o $(BUILD_DIR)/test_hash_memory test_hash_memory.c \
		$(PROJECT_ROOT)/src/viola/hash.o $(PROJECT_ROOT)/src/viola/mystrings.o
	@./$(BUILD_DIR)/test_hash_memory

test-mystrings: test_mystrings.c $(PROJECT_ROOT)/src/viola/hash.o $(PROJECT_ROOT)/src/viola/mystrings.o
	@echo ""
	@echo "Building string functions tests..."
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -I$(PROJECT_ROOT)/src/viola -o $(BUILD_DIR)/test_mystrings test_mystrings.c \
		$(PROJECT_ROOT)/src/viola/hash.o $(PROJECT_ROOT)/src/viola/mystrings.o
	@./$(BUILD_DIR)/test_mystrings

# Clean test artifacts
clean:
	@echo "Cleaning test artifacts..."
	@if [ -d "$(BUILD_DIR)" ]; then \
		chmod -R u+w $(BUILD_DIR) 2>/dev/null || true; \
		rm -rf $(BUILD_DIR); \
		echo "All test artifacts removed"; \
	else \
		echo "Build directory does not exist"; \
	fi

# Help
help:
	@echo "ViolaWWW Test Suite"
	@echo ""
	@echo "Available targets:"
	@echo "  make test            - Run all tests"
	@echo "  make test-NAME       - Run specific test"
	@echo "  make clean           - Clean test artifacts"
	@echo ""
	@echo "Available tests:"
	@echo "  test-stg-minors      - Style markup minors tests"
	@echo "  test-stg-context     - Style context tests"
	@echo "  test-xpm-injection   - XPM security (command injection)"
	@echo "  test-htcharset       - Character set tests (requires ICU)"
	@echo "  test-wayback-detection - Web Archive URL detection tests"
	@echo "  test-hash-memory     - Hash table memory leak tests"
	@echo "  test-mystrings       - String functions tests"

