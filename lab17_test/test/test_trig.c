#include <stdio.h>
#include <stdarg.h>
#include <setjmp.h>
#include "main.h"
#include <cmocka.h>


static void test_sin(void **state){
    assert_double_equal(sine(1.570796), 1.0, 0.001);
}

static void test_cosine(void **state){
    assert_double_equal(cosine(3.1415926), -1.0, 0.001);
}

static void test_tangent(void **state){
    assert_double_equal(tangent(3.1415926), 0.0, 0.001);
}

int main(void) {
    const struct CMUnitTest tests[] = {

        cmocka_unit_test(test_cosine),
        cmocka_unit_test(test_tangent),
        cmocka_unit_test(test_sin)
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}