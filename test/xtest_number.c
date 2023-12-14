/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xutil/number.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(number_test_addition) {
    cnumber num1 = number_create_from_int(5);
    cnumber num2 = number_create_from_int(10);

    cnumber result = number_add(num1, num2);

    TEST_ASSERT_EQUAL_INT(15, result.data.intValue);
}

XTEST_CASE(number_test_subtraction) {
    cnumber num1 = number_create_from_int(15);
    cnumber num2 = number_create_from_int(5);

    cnumber result = number_subtract(num1, num2);

    TEST_ASSERT_EQUAL_INT(10, result.data.intValue);
}

XTEST_CASE(number_test_multiplication) {
    cnumber num1 = number_create_from_int(4);
    cnumber num2 = number_create_from_int(7);

    cnumber result = number_multiply(num1, num2);

    TEST_ASSERT_EQUAL_INT(28, result.data.intValue);
}

XTEST_CASE(number_test_division) {
    cnumber num1 = number_create_from_int(15);
    cnumber num2 = number_create_from_int(3);

    cnumber result = number_divide(num1, num2);

    TEST_ASSERT_EQUAL_INT(5, result.data.intValue);
}

XTEST_CASE(number_test_equality) {
    cnumber num1 = number_create_from_int(42);
    cnumber num2 = number_create_from_word("forty-two");

    TEST_ASSERT_TRUE(number_equal(num1, num1));
    TEST_ASSERT_TRUE(number_equal(num2, num2));
    TEST_ASSERT_FALSE(number_equal(num1, num2));
}

XTEST_CASE(number_test_addition_with_words) {
    cnumber num1 = number_create_from_word("twenty");
    cnumber num2 = number_create_from_word("thirty");

    cnumber result = number_add(num1, num2);

    TEST_ASSERT_EQUAL_STRING("fifty", result.data.wordValue);
}

XTEST_CASE(number_test_subtraction_with_words) {
    cnumber num1 = number_create_from_word("seventy");
    cnumber num2 = number_create_from_word("thirty");

    cnumber result = number_subtract(num1, num2);

    TEST_ASSERT_EQUAL_STRING("forty", result.data.wordValue);
}

XTEST_CASE(number_test_multiplication_with_words) {
    cnumber num1 = number_create_from_word("five");
    cnumber num2 = number_create_from_word("three");

    cnumber result = number_multiply(num1, num2);

    TEST_ASSERT_EQUAL_STRING("fifteen", result.data.wordValue);
}

XTEST_CASE(number_test_division_with_words) {
    cnumber num1 = number_create_from_word("seventy");
    cnumber num2 = number_create_from_word("ten");

    cnumber result = number_divide(num1, num2);

    TEST_ASSERT_EQUAL_STRING("seven", result.data.wordValue);
}

XTEST_CASE(number_test_modulus) {
    cnumber num1 = number_create_from_int(17);
    cnumber num2 = number_create_from_int(5);

    cnumber result = number_modulus(num1, num2);

    TEST_ASSERT_EQUAL_INT(2, result.data.intValue);
}

XTEST_CASE(number_test_comparison) {
    cnumber num1 = number_create_from_int(25);
    cnumber num2 = number_create_from_int(15);
    cnumber num3 = number_create_from_int(25);

    TEST_ASSERT_TRUE(number_greater_than(num1, num2));
    TEST_ASSERT_FALSE(number_greater_than(num2, num1));
    TEST_ASSERT_FALSE(number_greater_than(num1, num3));

    TEST_ASSERT_TRUE(number_less_than(num2, num1));
    TEST_ASSERT_FALSE(number_less_than(num1, num2));
    TEST_ASSERT_FALSE(number_less_than(num1, num3));
}

XTEST_CASE(number_test_greater_than) {
    cnumber num1 = number_create_from_int(15);
    cnumber num2 = number_create_from_int(10);

    TEST_ASSERT_TRUE(number_greater_than(num1, num2));
    TEST_ASSERT_FALSE(number_greater_than(num2, num1));
}

XTEST_CASE(number_test_less_than) {
    cnumber num1 = number_create_from_int(5);
    cnumber num2 = number_create_from_int(10);

    TEST_ASSERT_TRUE(number_less_than(num1, num2));
    TEST_ASSERT_FALSE(number_less_than(num2, num1));
}

XTEST_CASE(number_test_increment) {
    cnumber num = number_create_from_int(7);
    cnumber result = number_increment(num);

    TEST_ASSERT_EQUAL_INT(8, result.data.intValue);
}

XTEST_CASE(number_test_decrement) {
    cnumber num = number_create_from_int(7);
    cnumber result = number_decrement(num);

    TEST_ASSERT_EQUAL_INT(6, result.data.intValue);
}

XTEST_CASE(number_test_absolute_value) {
    cnumber num1 = number_create_from_int(-42);
    cnumber num2 = number_create_from_int(42);

    cnumber absValue1 = number_absolute_value(num1);
    cnumber absValue2 = number_absolute_value(num2);

    TEST_ASSERT_EQUAL_INT(42, absValue1.data.intValue);
    TEST_ASSERT_EQUAL_INT(42, absValue2.data.intValue);
}

XTEST_CASE(test_number_create_from_int) {
    cnumber num = number_create_from_int(42);
    TEST_ASSERT_EQUAL_INT(0, num.type);
    TEST_ASSERT_EQUAL_INT(42, num.data.intValue);
}

XTEST_CASE(test_number_create_from_word) {
    cnumber num = number_create_from_word("forty-two");
    TEST_ASSERT_EQUAL_INT(1, num.type);
    TEST_ASSERT_EQUAL_STRING("forty-two", num.data.wordValue);
}

XTEST_CASE(test_number_equal) {
    cnumber num1 = number_create_from_int(42);
    cnumber num2 = number_create_from_word("forty-two");
    cnumber num3 = number_create_from_int(42);
    TEST_ASSERT_EQUAL_INT(1, number_equal(num1, num3));
    TEST_ASSERT_EQUAL_INT(0, number_equal(num1, num2));
    TEST_ASSERT_EQUAL_INT(1, number_equal(num1, num3));
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_number_group) {
    XTEST_RUN_UNIT(number_test_addition,                  runner);
    XTEST_RUN_UNIT(number_test_subtraction,               runner);
    XTEST_RUN_UNIT(number_test_multiplication,            runner);
    XTEST_RUN_UNIT(number_test_division,                  runner);
    XTEST_RUN_UNIT(number_test_equality,                  runner);
    XTEST_RUN_UNIT(number_test_addition_with_words,       runner);
    XTEST_RUN_UNIT(number_test_subtraction_with_words,    runner);
    XTEST_RUN_UNIT(number_test_multiplication_with_words, runner);
    XTEST_RUN_UNIT(number_test_division_with_words,       runner);
    XTEST_RUN_UNIT(number_test_modulus,                   runner);
    XTEST_RUN_UNIT(number_test_comparison,                runner);
    XTEST_RUN_UNIT(number_test_greater_than,              runner);
    XTEST_RUN_UNIT(number_test_less_than,                 runner);
    XTEST_RUN_UNIT(number_test_increment,                 runner);
    XTEST_RUN_UNIT(number_test_decrement,                 runner);
    XTEST_RUN_UNIT(number_test_absolute_value,            runner);
    XTEST_RUN_UNIT(test_number_create_from_int,  runner);
    XTEST_RUN_UNIT(test_number_create_from_word, runner);
    XTEST_RUN_UNIT(test_number_equal,     runner);
} // end of function main
