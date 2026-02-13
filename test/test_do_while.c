/*
 * test_do_while.c
 *
 * Tests for the do-while loop in the Viola scripting language.
 * Syntax:  do (init_expr) stmt while (condition_expr);
 *
 * The grammar (gram.y:342) parses do-while and builds AST_DO nodes,
 * but codeGen() had no handler for AST_DO — it fell through to the
 * default error case. These tests verify parsing and execution.
 */
#include "support/viola_test_support.h"

extern AST *theAST;

/* ========================================================================
 * Parser tests
 * ======================================================================== */

static int test_parse_basic(void)
{
    if (!try_parse("do (i = 0) { i = i + 1; } while (i < 3);"))
        return 0;
    return find_ast_type(theAST, AST_DO) != NULL;
}

static int test_parse_false_cond(void)
{
    if (!try_parse("do (x = 0) { x = x + 1; } while (0);"))
        return 0;
    return find_ast_type(theAST, AST_DO) != NULL;
}

static int test_parse_structure(void)
{
    /* Verify AST structure: AST_DO -> children: init -> body -> condition */
    if (!try_parse("do (i = 0) { i = i + 1; } while (i < 5);"))
        return 0;
    AST *doNode = find_ast_type(theAST, AST_DO);
    if (!doNode || !doNode->children)
        return 0;
    AST *init = doNode->children;
    if (!init->next || init->next->type != AST_BODY)
        return 0;
    if (!init->next->next)
        return 0;
    return 1;
}

static int test_parse_single_stmt(void)
{
    if (!try_parse("do (i = 0) i = i + 1; while (i < 3);"))
        return 0;
    return find_ast_type(theAST, AST_DO) != NULL;
}

static int test_parse_nested(void)
{
    if (!try_parse("if (1) { do (i = 0) { i = i + 1; } while (i < 2); }"))
        return 0;
    if (!find_ast_type(theAST, AST_IF))
        return 0;
    return find_ast_type(theAST, AST_DO) != NULL;
}

/* ========================================================================
 * Execution tests
 * ======================================================================== */

static int eval_var0(char *script, long *out)
{
    int size = compile_script(script);
    if (size <= 0) {
        fprintf(stderr, "    compile failed (size=%d)\n", size);
        return 0;
    }
    *out = mini_exec_var(viola_test_pcode(), size, 0);
    return 1;
}

static int test_exec_basic_loop(void)
{
    long r;
    return eval_var0("do (i = 0) { i = i + 1; } while (i < 3);", &r) && r == 3;
}

static int test_exec_body_runs_once(void)
{
    long r;
    return eval_var0("do (x = 0) { x = x + 1; } while (0);", &r) && r == 1;
}

static int test_exec_count_to_five(void)
{
    long r;
    return eval_var0("do (i = 0) { i = i + 1; } while (i < 5);", &r) && r == 5;
}

static int test_exec_countdown(void)
{
    long r;
    return eval_var0("do (i = 10) { i = i - 1; } while (i > 0);", &r) && r == 0;
}

static int test_exec_init_value(void)
{
    long r;
    return eval_var0("do (i = 42) { i = i + 1; } while (0);", &r) && r == 43;
}

static int test_exec_single_iteration(void)
{
    long r;
    return eval_var0("do (i = 0) { i = i + 1; } while (i < 1);", &r) && r == 1;
}

static int test_exec_with_increment(void)
{
    long r;
    return eval_var0("do (i = 0) { i++; } while (i < 4);", &r) && r == 4;
}

/* ========================================================================
 * Test runner
 * ======================================================================== */

int main(void)
{
    int passed = 0, total = 0;

    printf("Do-While Loop Tests\n");
    printf("====================\n");

    if (!viola_test_init()) return 1;

    printf("\n--- Parser ---\n");
    RUN("parse basic do-while",     test_parse_basic);
    RUN("parse false condition",    test_parse_false_cond);
    RUN("parse AST structure",      test_parse_structure);
    RUN("parse single statement",   test_parse_single_stmt);
    RUN("parse nested in if",       test_parse_nested);

    printf("\n--- Execution ---\n");
    RUN("exec loop to 3",          test_exec_basic_loop);
    RUN("exec body runs once",     test_exec_body_runs_once);
    RUN("exec count to 5",         test_exec_count_to_five);
    RUN("exec countdown 10->0",    test_exec_countdown);
    RUN("exec init value 42",      test_exec_init_value);
    RUN("exec single iteration",   test_exec_single_iteration);
    RUN("exec with i++",           test_exec_with_increment);

    printf("\nResults: %d/%d passed\n", passed, total);
    return (passed == total) ? 0 : 1;
}
