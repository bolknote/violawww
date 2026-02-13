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
TESTS := test-stg-minors test-stg-context test-xpm-injection test-htcharset test-wayback-detection test-biop test-hash-memory test-mystrings test-pkinfo-concat test-sgmls-a2b test-notsecure test-security-escalation test-path-validation test-htmime test-string-funcs test-destroy-variable test-logical-not test-do-while

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
	-@$(MAKE) test-pkinfo-concat >$(BUILD_DIR)/test-pkinfo-concat.log 2>&1 && echo "PASS" >> $(BUILD_DIR)/results.txt && echo "  ✓ test-pkinfo-concat: PASS" || (echo "FAIL" >> $(BUILD_DIR)/results.txt && echo "  ✗ test-pkinfo-concat: FAIL")
	-@$(MAKE) test-sgmls-a2b >$(BUILD_DIR)/test-sgmls-a2b.log 2>&1 && echo "PASS" >> $(BUILD_DIR)/results.txt && echo "  ✓ test-sgmls-a2b: PASS" || (echo "FAIL" >> $(BUILD_DIR)/results.txt && echo "  ✗ test-sgmls-a2b: FAIL")
	-@$(MAKE) test-notsecure >$(BUILD_DIR)/test-notsecure.log 2>&1 && echo "PASS" >> $(BUILD_DIR)/results.txt && echo "  ✓ test-notsecure: PASS" || (echo "FAIL" >> $(BUILD_DIR)/results.txt && echo "  ✗ test-notsecure: FAIL")
	-@$(MAKE) test-security-escalation >$(BUILD_DIR)/test-security-escalation.log 2>&1 && echo "PASS" >> $(BUILD_DIR)/results.txt && echo "  ✓ test-security-escalation: PASS" || (echo "FAIL" >> $(BUILD_DIR)/results.txt && echo "  ✗ test-security-escalation: FAIL")
	-@$(MAKE) test-path-validation >$(BUILD_DIR)/test-path-validation.log 2>&1 && echo "PASS" >> $(BUILD_DIR)/results.txt && echo "  ✓ test-path-validation: PASS" || (echo "FAIL" >> $(BUILD_DIR)/results.txt && echo "  ✗ test-path-validation: FAIL")
	-@$(MAKE) test-htmime >$(BUILD_DIR)/test-htmime.log 2>&1 && echo "PASS" >> $(BUILD_DIR)/results.txt && echo "  ✓ test-htmime: PASS" || (echo "FAIL" >> $(BUILD_DIR)/results.txt && echo "  ✗ test-htmime: FAIL")
	-@$(MAKE) test-string-funcs >$(BUILD_DIR)/test-string-funcs.log 2>&1 && echo "PASS" >> $(BUILD_DIR)/results.txt && echo "  ✓ test-string-funcs: PASS" || (echo "FAIL" >> $(BUILD_DIR)/results.txt && echo "  ✗ test-string-funcs: FAIL")
	-@$(MAKE) test-destroy-variable >$(BUILD_DIR)/test-destroy-variable.log 2>&1 && echo "PASS" >> $(BUILD_DIR)/results.txt && echo "  ✓ test-destroy-variable: PASS" || (echo "FAIL" >> $(BUILD_DIR)/results.txt && echo "  ✗ test-destroy-variable: FAIL")
	-@$(MAKE) test-logical-not >$(BUILD_DIR)/test-logical-not.log 2>&1 && echo "PASS" >> $(BUILD_DIR)/results.txt && echo "  ✓ test-logical-not: PASS" || (echo "FAIL" >> $(BUILD_DIR)/results.txt && echo "  ✗ test-logical-not: FAIL")
	-@$(MAKE) test-do-while >$(BUILD_DIR)/test-do-while.log 2>&1 && echo "PASS" >> $(BUILD_DIR)/results.txt && echo "  ✓ test-do-while: PASS" || (echo "FAIL" >> $(BUILD_DIR)/results.txt && echo "  ✗ test-do-while: FAIL")
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

test-pkinfo-concat: test_pkinfo_concat.c $(PROJECT_ROOT)/src/viola/misc.o $(PROJECT_ROOT)/src/viola/mystrings.o
	@echo ""
	@echo "Building packet-info concat tests..."
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -I$(PROJECT_ROOT)/src/viola -o $(BUILD_DIR)/test_pkinfo_concat test_pkinfo_concat.c \
		$(PROJECT_ROOT)/src/viola/misc.o $(PROJECT_ROOT)/src/viola/mystrings.o
	@./$(BUILD_DIR)/test_pkinfo_concat

test-sgmls-a2b: test_sgmls_a2b.c $(PROJECT_ROOT)/src/viola/mystrings.o
	@echo ""
	@echo "Building SGMLS A2B converter tests..."
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -I$(PROJECT_ROOT)/src/viola -o $(BUILD_DIR)/test_sgmls_a2b test_sgmls_a2b.c \
		$(PROJECT_ROOT)/src/viola/mystrings.o
	@./$(BUILD_DIR)/test_sgmls_a2b

# Security tests
test-notsecure: test_notsecure.c
	@echo ""
	@echo "Building notSecure() NULL handling tests..."
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -o $(BUILD_DIR)/test_notsecure test_notsecure.c
	@./$(BUILD_DIR)/test_notsecure

test-security-escalation: test_security_escalation.c
	@echo ""
	@echo "Building security escalation prevention tests..."
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -o $(BUILD_DIR)/test_security_escalation test_security_escalation.c
	@./$(BUILD_DIR)/test_security_escalation

test-path-validation: test_path_validation.c
	@echo ""
	@echo "Building path validation security tests..."
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -o $(BUILD_DIR)/test_path_validation test_path_validation.c
	@./$(BUILD_DIR)/test_path_validation

test-htmime: test_htmime.c
	@echo ""
	@echo "Building HTMIME header parsing tests..."
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -o $(BUILD_DIR)/test_htmime test_htmime.c
	@cd $(BUILD_DIR) && ./test_htmime

test-string-funcs: test_string_funcs.c
	@echo ""
	@echo "Building string functions tests (deleteSubStr, replaceStrQ, sprintf, countWords, not, item, nthItem)..."
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -o $(BUILD_DIR)/test_string_funcs test_string_funcs.c
	@./$(BUILD_DIR)/test_string_funcs

test-destroy-variable: test_destroy_variable.c
	@echo ""
	@echo "Building destroyVariable integration tests..."
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -o $(BUILD_DIR)/test_destroy_variable test_destroy_variable.c
	@./$(BUILD_DIR)/test_destroy_variable

# Shared interpreter objects for Viola script tests
VIOLA_TEST_SUPPORT := support/viola_test_support.c
VIOLA_TEST_OBJS := $(VIOLA_DIR)/gram.o $(VIOLA_DIR)/ast.o $(VIOLA_DIR)/violalex.o \
	$(VIOLA_DIR)/cgen.o $(VIOLA_DIR)/ident.o $(VIOLA_DIR)/hash.o $(VIOLA_DIR)/mystrings.o

test-do-while: test_do_while.c $(VIOLA_TEST_SUPPORT) $(VIOLA_TEST_OBJS)
	@echo ""
	@echo "Building do-while loop tests..."
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -I$(VIOLA_DIR) -I$(LIBWWW_DIR) -o $(BUILD_DIR)/test_do_while \
		test_do_while.c $(VIOLA_TEST_SUPPORT) $(VIOLA_TEST_OBJS)
	@./$(BUILD_DIR)/test_do_while

test-logical-not: test_logical_not.c $(VIOLA_TEST_SUPPORT) $(VIOLA_TEST_OBJS)
	@echo ""
	@echo "Building logical NOT operator tests..."
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -I$(VIOLA_DIR) -I$(LIBWWW_DIR) -o $(BUILD_DIR)/test_logical_not \
		test_logical_not.c $(VIOLA_TEST_SUPPORT) $(VIOLA_TEST_OBJS)
	@./$(BUILD_DIR)/test_logical_not

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
	@echo "  test-sgmls-a2b       - SGMLS ASCII to Binary converter tests"
	@echo "  test-notsecure       - notSecure() NULL handling tests"
	@echo "  test-security-escalation - Security escalation prevention tests"
	@echo "  test-path-validation - Path validation security tests"
	@echo "  test-htmime          - HTTPS/HTMIME large header handling tests"
	@echo "  test-string-funcs    - String functions (deleteSubStr, replaceStrQ, sprintf, countWords, not, item, nthItem)"
	@echo "  test-destroy-variable - Variable destruction tests"
	@echo "  test-logical-not     - Logical NOT (!) operator tests"
	@echo "  test-do-while        - Do-while loop tests"

