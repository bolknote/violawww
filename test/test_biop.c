/* Minimal tests for string operations in biop.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/viola/packet.h"
#include "../src/viola/biop.h"
#include "../src/viola/mystrings.h"

static int approx_equal(float a, float b) {
    return fabsf(a - b) < 1e-6f;
}

static Packet make_str_packet(const char* s) {
    Packet p;
    p.type = PKT_STR;
    p.info.s = SaveString(s);
    p.canFree = PK_CANFREE_STR;
    p.sticky = 0;
    return p;
}

static int test_str_minus() {
    Packet p1 = make_str_packet("10.5");
    Packet p2 = make_str_packet("2");
    str_minus(&p1, &p2);
    if (p1.type != PKT_FLT || !approx_equal(p1.info.f, 8.5f)) {
        printf("FAIL: str_minus('10.5','2') => type=%d, val=%f (expected 8.5)\n", p1.type, p1.info.f);
        return 0;
    }
    return 1;
}

static int test_str_mult() {
    Packet p1 = make_str_packet("3");
    Packet p2 = make_str_packet("4.5");
    str_mult(&p1, &p2);
    if (p1.type != PKT_FLT || !approx_equal(p1.info.f, 13.5f)) {
        printf("FAIL: str_mult('3','4.5') => type=%d, val=%f (expected 13.5)\n", p1.type, p1.info.f);
        return 0;
    }
    return 1;
}

static int test_str_div() {
    Packet p1 = make_str_packet("9");
    Packet p2 = make_str_packet("3");
    str_div(&p1, &p2);
    if (p1.type != PKT_FLT || !approx_equal(p1.info.f, 3.0f)) {
        printf("FAIL: str_div('9','3') => type=%d, val=%f (expected 3.0)\n", p1.type, p1.info.f);
        return 0;
    }
    return 1;
}

static int test_str_mod() {
    Packet p1 = make_str_packet("10");
    Packet p2 = make_str_packet("3");
    str_mod(&p1, &p2);
    if (p1.type != PKT_INT || p1.info.i != 1) {
        printf("FAIL: str_mod('10','3') => type=%d, val=%ld (expected 1)\n", p1.type, p1.info.i);
        return 0;
    }
    return 1;
}

static int test_str_and_or() {
    Packet a = make_str_packet("");
    Packet b = make_str_packet("x");
    Packet c = make_str_packet("y");

    /* '' && 'x' => 0 */
    Packet p1 = make_str_packet("");
    str_and(&p1, &b);
    if (p1.type != PKT_INT || p1.info.i != 0) {
        printf("FAIL: str_and('', 'x') => %ld (expected 0)\n", p1.info.i);
        return 0;
    }

    /* 'a' && '' => 0 */
    p1 = make_str_packet("a");
    str_and(&p1, &a);
    if (p1.type != PKT_INT || p1.info.i != 0) {
        printf("FAIL: str_and('a', '') => %ld (expected 0)\n", p1.info.i);
        return 0;
    }

    /* 'a' && 'b' => 1 */
    p1 = make_str_packet("a");
    str_and(&p1, &c);
    if (p1.type != PKT_INT || p1.info.i != 1) {
        printf("FAIL: str_and('a', 'b') => %ld (expected 1)\n", p1.info.i);
        return 0;
    }

    /* '' || '' => 0 */
    p1 = make_str_packet("");
    str_or(&p1, &a);
    if (p1.type != PKT_INT || p1.info.i != 0) {
        printf("FAIL: str_or('', '') => %ld (expected 0)\n", p1.info.i);
        return 0;
    }

    /* 'a' || '' => 1 */
    p1 = make_str_packet("a");
    str_or(&p1, &a);
    if (p1.type != PKT_INT || p1.info.i != 1) {
        printf("FAIL: str_or('a', '') => %ld (expected 1)\n", p1.info.i);
        return 0;
    }

    /* '' || 'b' => 1 */
    p1 = make_str_packet("");
    str_or(&p1, &c);
    if (p1.type != PKT_INT || p1.info.i != 1) {
        printf("FAIL: str_or('', 'b') => %ld (expected 1)\n", p1.info.i);
        return 0;
    }

    return 1;
}

int main() {
    int passed = 0, total = 0;

    printf("Biop String Ops Tests\n");
    printf("======================\n");

    total++; if (test_str_minus()) { passed++; printf("✓ str_minus\n"); } else { printf("✗ str_minus\n"); }
    total++; if (test_str_mult())  { passed++; printf("✓ str_mult\n"); }  else { printf("✗ str_mult\n"); }
    total++; if (test_str_div())   { passed++; printf("✓ str_div\n"); }   else { printf("✗ str_div\n"); }
    total++; if (test_str_mod())   { passed++; printf("✓ str_mod\n"); }   else { printf("✗ str_mod\n"); }
    total++; if (test_str_and_or()){ passed++; printf("✓ str_and/str_or\n"); } else { printf("✗ str_and/str_or\n"); }

    printf("\nResults: %d/%d passed\n", passed, total);
    return (passed == total) ? 0 : 1;
}


