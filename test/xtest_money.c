/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xutil/money.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

XTEST_CASE(test_money_add_same_currency) {
    // Test addition of money with the same currency
    cmoney money1 = money_create(10, 50, USD);
    cmoney money2 = money_create(5, 75, USD);

    cmoney sum = money_add(money1, money2);

    TEST_ASSERT_EQUAL_INT(16, sum.dollars);
    TEST_ASSERT_EQUAL_INT(25, sum.cents);
    TEST_ASSERT_EQUAL_INT(USD, sum.currency);
}

XTEST_CASE(test_money_add_different_currency) {
    // Test addition of money with different currencies
    cmoney money1 = money_create(10, 50, USD);
    cmoney money3 = money_create(3, 25, GBP);

    cmoney sum = money_add(money1, money3);

    TEST_ASSERT_EQUAL_INT(0, sum.dollars); // Currencies don't match, expect 0
    TEST_ASSERT_EQUAL_INT(0, sum.cents);
    TEST_ASSERT_EQUAL_INT(-1, sum.currency); // -1 represents unknown currency
}

XTEST_CASE(test_money_convert) {
    // Test money conversion
    cmoney money1 = money_create(10, 50, USD);

    cmoney converted_money = money_convert(money1, GBP);

    TEST_ASSERT_EQUAL_INT(10, converted_money.dollars);
    TEST_ASSERT_EQUAL_INT(50, converted_money.cents);
    TEST_ASSERT_EQUAL_INT(GBP, converted_money.currency);
}

XTEST_CASE(test_money_is_valid) {
    // Test money validity check
    cmoney valid_money = money_create(10, 50, USD);
    cmoney invalid_money = money_create(10, 120, USD);

    TEST_ASSERT_TRUE(money_is_valid(valid_money));
    TEST_ASSERT_FALSE(money_is_valid(invalid_money));
}

XTEST_CASE(test_money_compare) {
    // Test money comparison
    cmoney money1 = money_create(10, 50, USD);
    cmoney money2 = money_create(5, 75, USD);
    cmoney money3 = money_create(10, 50, USD);

    TEST_ASSERT_EQUAL_INT(-1, money_compare(money1, money2)); // money1 < money2
    TEST_ASSERT_EQUAL_INT(1, money_compare(money2, money1));  // money2 > money1
    TEST_ASSERT_EQUAL_INT(0, money_compare(money1, money3));  // money1 == money3
}

XTEST_CASE(test_money_subtract) {
    // Test money subtraction
    cmoney money1 = money_create(10, 50, USD);
    cmoney money2 = money_create(5, 75, USD);

    cmoney difference = money_subtract(money1, money2);

    TEST_ASSERT_EQUAL_INT(4, difference.dollars);
    TEST_ASSERT_EQUAL_INT(75, difference.cents);
    TEST_ASSERT_EQUAL_INT(USD, difference.currency);
}

XTEST_CASE(test_money_multiply_scalar) {
    cmoney m = money_create(5, 50, USD);
    
    cmoney result = money_multiply_scalar(m, 2);

    TEST_ASSERT_EQUAL_INT(11, result.dollars);
    TEST_ASSERT_EQUAL_INT(0, result.cents);
    TEST_ASSERT_EQUAL_INT(USD, result.currency);
}

XTEST_CASE(test_money_divide_scalar) {
    cmoney m = money_create(10, 25, USD);

    cmoney result = money_divide_scalar(m, 2);

    TEST_ASSERT_EQUAL_INT(5, result.dollars);
    TEST_ASSERT_EQUAL_INT(12, result.cents);
    TEST_ASSERT_EQUAL_INT(USD, result.currency);
}

XTEST_CASE(test_money_round) {
    cmoney m = money_create(15, 99, USD);

    cmoney result = money_round(m);

    TEST_ASSERT_EQUAL_INT(16, result.dollars);
    TEST_ASSERT_EQUAL_INT(0, result.cents);
    TEST_ASSERT_EQUAL_INT(USD, result.currency);
}

XTEST_CASE(test_money_is_positive) {
    cmoney m1 = money_create(5, 0, USD);
    cmoney m2 = money_create(0, 50, USD);
    cmoney m3 = money_create(-10, 0, USD);

    TEST_ASSERT_TRUE(money_is_positive(m1));
    TEST_ASSERT_TRUE(money_is_positive(m2));
    TEST_ASSERT_FALSE(money_is_positive(m3));
}

XTEST_CASE(test_money_is_negative) {
    cmoney m1 = money_create(-5, 0, USD);
    cmoney m2 = money_create(0, -50, USD);
    cmoney m3 = money_create(10, 0, USD);

    TEST_ASSERT_TRUE(money_is_negative(m1));
    TEST_ASSERT_TRUE(money_is_negative(m2));
    TEST_ASSERT_FALSE(money_is_negative(m3));
}

XTEST_CASE(test_money_is_zero) {
    cmoney m1 = money_create(0, 0, USD);
    cmoney m2 = money_create(0, 50, USD);
    cmoney m3 = money_create(-10, 0, USD);

    TEST_ASSERT_TRUE(money_is_zero(m1));
    TEST_ASSERT_FALSE(money_is_zero(m2));
    TEST_ASSERT_FALSE(money_is_zero(m3));
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_money_group) {
    XTEST_RUN_UNIT(test_money_add_same_currency,      runner);
    XTEST_RUN_UNIT(test_money_add_different_currency, runner);
    XTEST_RUN_UNIT(test_money_convert,  runner);
    XTEST_RUN_UNIT(test_money_is_valid, runner);
    XTEST_RUN_UNIT(test_money_compare,  runner);
    XTEST_RUN_UNIT(test_money_subtract, runner);
    XTEST_RUN_UNIT(test_money_multiply_scalar, runner);
    XTEST_RUN_UNIT(test_money_divide_scalar,   runner);
    XTEST_RUN_UNIT(test_money_round,           runner);
    XTEST_RUN_UNIT(test_money_is_positive,     runner);
    XTEST_RUN_UNIT(test_money_is_negative,     runner);
    XTEST_RUN_UNIT(test_money_is_zero,         runner);
} // end of function main
