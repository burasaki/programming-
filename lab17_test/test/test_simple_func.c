#include <stdio.h>
#include <stdarg.h>
#include <setjmp.h>
#include "main.h"
#include <cmocka.h>

int __wrap_printf(const char *format, ...){
    return 0;
}

int __wrap_puts(const char *s) {
    return 0;
}

static void test_sum(void **state){
    assert_double_equal(add(2.1, 3.2), 5.3, 0.00005);
}


static void test_subtract(void **state){
    assert_double_equal(subtract(3.2, 2.1), 1.1, 0.00005);
}

static void test_multiply(void **state){
    assert_double_equal(multiply(2.1, 4), 8.4, 0.00005);
}

static void test_divide(void **state){
    assert_double_equal(divide(2, 4), 0.5, 0.00005);
}
static void test_zero_divide(void **state){
    assert_true(isnan(divide(2, 0)));
}


int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_sum),
        cmocka_unit_test(test_subtract),
        cmocka_unit_test(test_multiply),
        cmocka_unit_test(test_divide),
        cmocka_unit_test(test_zero_divide),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}