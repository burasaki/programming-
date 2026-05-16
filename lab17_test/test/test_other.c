#include <stdio.h>
#include <stdarg.h>
#include <setjmp.h>
#include "main.h"
#include <cmocka.h>


static void test_logarithm(void **state){
    assert_double_equal(logarithm(2.718281), 1.0, 0.0001);
}

static void test_logarithm_negative(void **state){
    assert_true(isnan(logarithm(-1.0)));
}

static void test_power(void **state){
    assert_double_equal(power(4,2), 16, 0.001);
}

static void test_square_root(void **state){
    assert_double_equal(square_root(16), 4.0, 0.0001);
}

static void test_square_root_negative(void **state){
    assert_true(isnan(square_root(-1.0)));
}



int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_logarithm),
        cmocka_unit_test(test_logarithm_negative),
        cmocka_unit_test(test_power),
        cmocka_unit_test(test_square_root),
        cmocka_unit_test(test_square_root_negative)

    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}