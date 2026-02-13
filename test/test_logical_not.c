/*
 * test_logical_not.c
 *
 * Tests for the ! (logical NOT) operator in the Viola scripting language.
 * The ! operator was declared in the grammar's precedence table (gram.y:66)
 * but had no production rule, making it unparseable. These tests verify:
 *   1. Parsing: the operator is accepted and produces the correct AST.
 *   2. Execution: scripts compile to pcode containing CODE_NOT, and the
 *      mini-executor verifies the correct runtime behavior.
 */
#include "support/viola_test_support.h"

extern AST *theAST;

/* ========================================================================
 * Parser tests
 * ======================================================================== */

static int test_parse_not_integer(void)
{
    if (!try_parse("x = !0;")) return 0;
    return find_ast_type(theAST, AST_EXPR_NOT) != NULL;
}

static int test_parse_not_variable(void)
{
    if (!try_parse("x = !y;")) return 0;
    return find_ast_type(theAST, AST_EXPR_NOT) != NULL;
}

static int test_parse_not_in_if(void)
{
    if (!try_parse("if (!x) { y = 1; }")) return 0;
    return find_ast_type(theAST, AST_EXPR_NOT) != NULL;
}

static int test_parse_double_not(void)
{
    if (!try_parse("x = !!y;")) return 0;
    AST *first = find_ast_type(theAST, AST_EXPR_NOT);
    if (!first) return 0;
    return find_ast_type(first->children, AST_EXPR_NOT) != NULL;
}

static int test_parse_not_of_comparison(void)
{
    if (!try_parse("z = !(x == y);")) return 0;
    AST *n = find_ast_type(theAST, AST_EXPR_NOT);
    if (!n) return 0;
    return find_ast_type(n->children, AST_EXPR_EQ) != NULL;
}

static int test_parse_not_func_call(void)
{
    if (!try_parse("x = !func();")) return 0;
    AST *n = find_ast_type(theAST, AST_EXPR_NOT);
    if (!n) return 0;
    return find_ast_type(n->children, AST_CALL) != NULL;
}

static int test_parse_not_in_while(void)
{
    if (!try_parse("while (!done) { i++; }")) return 0;
    AST *w = find_ast_type(theAST, AST_WHILE);
    if (!w) return 0;
    return find_ast_type(w->children, AST_EXPR_NOT) != NULL;
}

static int test_parse_not_with_and(void)
{
    if (!try_parse("x = !a && !b;")) return 0;
    return find_ast_type(theAST, AST_EXPR_AND) != NULL;
}

static int test_parse_not_string(void)
{
    if (!try_parse("x = !\"\";")) return 0;
    return find_ast_type(theAST, AST_EXPR_NOT) != NULL;
}

/* ========================================================================
 * Execution tests
 * ======================================================================== */

static int eval(char *script, long *out)
{
    int size = compile_script(script);
    if (size < 0) return 0;
    *out = mini_exec_reg(viola_test_pcode(), size);
    return 1;
}

static int test_exec_not_zero(void)
{
    long r; return eval("!0;", &r) && r == 1;
}

static int test_exec_not_one(void)
{
    long r; return eval("!1;", &r) && r == 0;
}

static int test_exec_not_positive(void)
{
    long r; return eval("!42;", &r) && r == 0;
}

static int test_exec_not_negative(void)
{
    long r; return eval("!-1;", &r) && r == 0;
}

static int test_exec_double_not_zero(void)
{
    long r; return eval("!!0;", &r) && r == 0;
}

static int test_exec_double_not_one(void)
{
    long r; return eval("!!1;", &r) && r == 1;
}

static int test_exec_triple_not(void)
{
    long r; return eval("!!!0;", &r) && r == 1;
}

static int test_exec_not_empty_string(void)
{
    long r; return eval("!\"\";", &r) && r == 1;
}

static int test_exec_not_nonempty_string(void)
{
    long r; return eval("!\"hello\";", &r) && r == 0;
}

static int test_exec_not_char(void)
{
    long r; return eval("!'a';", &r) && r == 0;
}

static int test_exec_not_null_char(void)
{
    long r; return eval("!'\\000';", &r) && r == 1;
}

/* ========================================================================
 * Test runner
 * ======================================================================== */

int main(void)
{
    int passed = 0, total = 0;

    printf("Logical NOT Operator Tests\n");
    printf("==========================\n");

    if (!viola_test_init()) return 1;

    printf("\n--- Parser ---\n");
    RUN("parse !integer",       test_parse_not_integer);
    RUN("parse !variable",      test_parse_not_variable);
    RUN("parse if (!x)",        test_parse_not_in_if);
    RUN("parse !!y",            test_parse_double_not);
    RUN("parse !(x == y)",      test_parse_not_of_comparison);
    RUN("parse !func()",        test_parse_not_func_call);
    RUN("parse while (!done)",  test_parse_not_in_while);
    RUN("parse !a && !b",       test_parse_not_with_and);
    RUN("parse !\"\"",          test_parse_not_string);

    printf("\n--- Execution ---\n");
    RUN("exec !0 = 1",          test_exec_not_zero);
    RUN("exec !1 = 0",          test_exec_not_one);
    RUN("exec !42 = 0",         test_exec_not_positive);
    RUN("exec !-1 = 0",         test_exec_not_negative);
    RUN("exec !!0 = 0",         test_exec_double_not_zero);
    RUN("exec !!1 = 1",         test_exec_double_not_one);
    RUN("exec !!!0 = 1",        test_exec_triple_not);
    RUN("exec !\"\" = 1",       test_exec_not_empty_string);
    RUN("exec !\"hello\" = 0",  test_exec_not_nonempty_string);
    RUN("exec !'a' = 0",        test_exec_not_char);
    RUN("exec !'\\0' = 1",      test_exec_not_null_char);

    printf("\nResults: %d/%d passed\n", passed, total);
    return (passed == total) ? 0 : 1;
}
