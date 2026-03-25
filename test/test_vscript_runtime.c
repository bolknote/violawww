/*
 * test_vscript_runtime.c
 *
 * Viola interpreter-level tests for VSCRIPT / SCRIPT TYPE="viola" content.
 *
 * Verifies that typical script code placed inside <VSCRIPT> and
 * <SCRIPT TYPE="viola"> tags can be parsed, compiled, and executed
 * by the Viola interpreter pipeline.
 */
#include "support/viola_test_support.h"

/* ========================================================================
 * 1. Parsing tests — can typical VSCRIPT content be parsed?
 * ======================================================================== */

static int test_parse_assignment(void)
{
    return try_parse("x = 42;");
}

static int test_parse_if_else(void)
{
    return try_parse("if (x > 0) { y = 1; } else { y = 0; }");
}

static int test_parse_while_loop(void)
{
    return try_parse("while (i < 10) { i = i + 1; }");
}

static int test_parse_multiple_statements(void)
{
    return try_parse("x = 1; y = 2; z = x + y;");
}

static int test_parse_string_comparison(void)
{
    return try_parse("if (s == \"hello\") { x = 1; }");
}

static int test_parse_nested_if(void)
{
    return try_parse("if (a > 0) { if (b > 0) { c = 1; } }");
}

static int test_parse_function_call_syntax(void)
{
    return try_parse("interpret(\"x = 1;\");");
}

static int test_parse_empty_string_return(void)
{
    return try_parse("return \"\";");
}

/* ========================================================================
 * 2. Compilation tests — does code produce valid pcode?
 * ======================================================================== */

static int test_compile_assignment(void)
{
    return compile_script("x = 42;") > 0;
}

static int test_compile_arithmetic(void)
{
    return compile_script("x = 1 + 2 * 3;") > 0;
}

static int test_compile_loop(void)
{
    return compile_script("while (i < 5) { i = i + 1; }") > 0;
}

static int test_compile_conditional(void)
{
    return compile_script("if (x > 0) { y = 1; } else { y = 2; }") > 0;
}

static int test_compile_multiple_stmts(void)
{
    return compile_script("a = 1; b = 2; c = a + b;") > 0;
}

/* ========================================================================
 * 3. Execution tests — does the script produce correct results?
 * ======================================================================== */

static int test_exec_simple_assign(void)
{
    long r;
    return eval_var0("x = 42;", &r) && r == 42;
}

static int test_exec_arithmetic(void)
{
    long r;
    return eval_var0("x = 3 + 4;", &r) && r == 7;
}

static int test_exec_multiple_vars(void)
{
    long r;
    /* assignReferences gives refIDs in varArray order, which
     * ends up reversed from declaration order:
     *   c -> var 0, b -> var 1, a -> var 2 */
    return eval_var("a = 10; b = 20; c = a + b;", 0, &r) && r == 30;
}

static int test_exec_while_loop(void)
{
    long r;
    return eval_var0("i = 0; while (i < 5) { i = i + 1; }", &r) && r == 5;
}

static int test_exec_conditional_true(void)
{
    long r;
    /* y -> var 0 (last declared), x -> var 1 */
    return eval_var("x = 10; if (x > 5) { y = 1; } else { y = 0; }", 0, &r) && r == 1;
}

static int test_exec_conditional_false(void)
{
    long r;
    return eval_var("x = 2; if (x > 5) { y = 1; } else { y = 0; }", 0, &r) && r == 0;
}

static int test_exec_increment(void)
{
    long r;
    return eval_var0("x = 0; x++; x++; x++;", &r) && r == 3;
}

static int test_exec_decrement(void)
{
    long r;
    return eval_var0("x = 10; x--; x--; x--;", &r) && r == 7;
}

static int test_exec_nested_loop(void)
{
    long r;
    /* i -> var 0, sum -> var 1 (reversed from declaration order) */
    return eval_var(
        "sum = 0; i = 0; while (i < 3) { i = i + 1; sum = sum + i; }",
        1, &r) && r == 6;
}

static int test_exec_accumulator(void)
{
    long r;
    return eval_var0(
        "x = 1; x = x + x; x = x + x; x = x + x;",
        &r) && r == 8;
}

/* ========================================================================
 * Test runner
 * ======================================================================== */

TEST_BEGIN("VSCRIPT / SCRIPT Runtime Tests")

    printf("\n--- Parsing (typical VSCRIPT content) ---\n");
    RUN("parse assignment",             test_parse_assignment);
    RUN("parse if/else",                test_parse_if_else);
    RUN("parse while loop",             test_parse_while_loop);
    RUN("parse multiple statements",    test_parse_multiple_statements);
    RUN("parse string comparison",      test_parse_string_comparison);
    RUN("parse nested if",              test_parse_nested_if);
    RUN("parse function call syntax",   test_parse_function_call_syntax);
    RUN("parse empty string return",    test_parse_empty_string_return);

    printf("\n--- Compilation ---\n");
    RUN("compile assignment",           test_compile_assignment);
    RUN("compile arithmetic",           test_compile_arithmetic);
    RUN("compile loop",                 test_compile_loop);
    RUN("compile conditional",          test_compile_conditional);
    RUN("compile multiple statements",  test_compile_multiple_stmts);

    printf("\n--- Execution ---\n");
    RUN("exec simple assignment",       test_exec_simple_assign);
    RUN("exec arithmetic",             test_exec_arithmetic);
    RUN("exec multiple vars (a+b=c)",  test_exec_multiple_vars);
    RUN("exec while loop to 5",        test_exec_while_loop);
    RUN("exec conditional (true)",     test_exec_conditional_true);
    RUN("exec conditional (false)",    test_exec_conditional_false);
    RUN("exec increment",             test_exec_increment);
    RUN("exec decrement",             test_exec_decrement);
    RUN("exec nested loop (sum)",     test_exec_nested_loop);
    RUN("exec accumulator (doubling)", test_exec_accumulator);

TEST_END
