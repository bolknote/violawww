/*
 * viola_test_support.h
 *
 * Shared infrastructure for Viola interpreter tests.
 * Provides parsing, compilation, AST search, and a mini pcode executor.
 */
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../src/viola/ast.h"
#include "../../src/viola/cgen.h"

/* Initialize interpreter subsystems (ident, scanutils, ast).
 * Returns 1 on success, 0 on failure.
 */
int viola_test_init(void);

/* Parse a Viola script string.
 * Returns 1 on success (theAST is non-NULL), 0 on parse failure.
 */
int try_parse(char *script);

/* Recursively search the AST for a node of the given type.
 * Returns the first matching node, or NULL.
 */
AST *find_ast_type(AST *ast, int type);

/* Compile a Viola script: parse + assignReferences + codeGen.
 * Pcode is stored in an internal buffer (see viola_test_pcode()).
 * Returns the pcode instruction count, or -1 on error.
 */
int compile_script(char *script);

/* Get pointer to the internal pcode buffer (valid after compile_script). */
union PCode *viola_test_pcode(void);

/* Execute pcode and return the final integer register value.
 * Suitable for expression-level tests (e.g., !0, !!1).
 */
long mini_exec_reg(union PCode *pcode, int size);

/* Execute pcode and return the value of variable at var_idx.
 * Suitable for tests with loops and variable mutations.
 */
long mini_exec_var(union PCode *pcode, int size, int var_idx);

/* Test runner macro */
#define RUN(name, func) do { \
    total++; \
    if (func()) { passed++; printf("  ok  %s\n", name); } \
    else { printf("  FAIL  %s\n", name); } \
} while (0)
