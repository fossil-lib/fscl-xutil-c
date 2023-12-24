/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xutil/assume.h"

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(f);

XTEST_CASE(test_tscl_assume_true) {
    TEST_ASSERT_TRUE(tscl_assume(true, "This should pass."));
}

XTEST_CASE(test_tscl_assume_false) {
    TEST_ASSERT_FALSE(tscl_assume(false, "This should fail."));
}

XTEST_CASE(test_tscl_assume_not_null_valid) {
    int* ptr = (int*)malloc(sizeof(int));
    TEST_ASSERT_TRUE(tscl_assume_not_null(ptr, "This should pass."));
    free(ptr);
}

XTEST_CASE(test_tscl_assume_not_null_invalid) {
    TEST_ASSERT_FALSE(tscl_assume_not_null(NULL, "This should fail."));
}

XTEST_CASE(test_tscl_assume_within_bounds_valid) {
    size_t size = 5;
    size_t index = 3;
    TEST_ASSERT_TRUE(tscl_assume_within_bounds(index, size, "This should pass."));
}

XTEST_CASE(test_tscl_assume_within_bounds_invalid) {
    size_t size = 5;
    size_t index = 7;
    TEST_ASSERT_FALSE(tscl_assume_within_bounds(index, size, "This should fail."));
}

XTEST_CASE(test_tscl_assume_positive_valid) {
    int value = 42;
    TEST_ASSERT_TRUE(tscl_assume_positive(value, "This should pass."));
}

XTEST_CASE(test_tscl_assume_positive_invalid) {
    int value = -5;
    TEST_ASSERT_FALSE(tscl_assume_positive(value, "This should fail."));
}

XTEST_CASE(test_tscl_assume_file_not_null_invalid) {
    FILE* file = NULL;
    TEST_ASSERT_FALSE(tscl_assume_file_not_null(file, "This should fail."));
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_assume_group) {
    XTEST_RUN_UNIT(test_tscl_assume_true,  runner);
    XTEST_RUN_UNIT(test_tscl_assume_false, runner);
    XTEST_RUN_UNIT(test_tscl_assume_not_null_valid,        runner);
    XTEST_RUN_UNIT(test_tscl_assume_not_null_invalid,      runner);
    XTEST_RUN_UNIT(test_tscl_assume_within_bounds_valid,   runner);
    XTEST_RUN_UNIT(test_tscl_assume_within_bounds_invalid, runner);
    XTEST_RUN_UNIT(test_tscl_assume_positive_valid,        runner);
    XTEST_RUN_UNIT(test_tscl_assume_positive_invalid,      runner);
    XTEST_RUN_UNIT(test_tscl_assume_file_not_null_invalid, runner);
} // end of func
