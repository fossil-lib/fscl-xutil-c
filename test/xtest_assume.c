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
XTEST_CASE(test_tscl_assume_this) {
    TEST_ASSERT_TRUE(tscl_assume_this(1 == 1));
}

XTEST_CASE(test_tscl_assume_this_and_that) {
    TEST_ASSERT_TRUE(tscl_assume_this_and_that(1 == 1, 2 == 2));
}

XTEST_CASE(test_tscl_assume_this_or_that) {
    TEST_ASSERT_TRUE(tscl_assume_this_or_that(1 == 1, 2 == 2));
}

XTEST_CASE(test_tscl_assume_this_unless) {
    TEST_ASSERT_TRUE(tscl_assume_this_unless(1 == 1, 2 == 2));
}

XTEST_CASE(test_tscl_assume_this_not_that) {
    TEST_ASSERT_TRUE(tscl_assume_this_not_that(1 == 1, 2 != 1));
}

XTEST_CASE(test_tscl_assume_range) {
    TEST_ASSERT_TRUE(tscl_assume_range(5, 0, 10));
}

XTEST_CASE(test_tscl_assume_not_cnullptr) {
    int *ptr = malloc(sizeof(int));
    TEST_ASSERT_TRUE(tscl_assume_not_cnullptr(ptr));
    free(ptr);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_assume_group) {
    XTEST_RUN_UNIT(test_tscl_assume_this, runner);
    XTEST_RUN_UNIT(test_tscl_assume_this_and_that, runner);
    XTEST_RUN_UNIT(test_tscl_assume_this_or_that,  runner);
    XTEST_RUN_UNIT(test_tscl_assume_this_unless,   runner);
    XTEST_RUN_UNIT(test_tscl_assume_this_not_that, runner);
    XTEST_RUN_UNIT(test_tscl_assume_range,         runner);
    XTEST_RUN_UNIT(test_tscl_assume_not_cnullptr,  runner);
} // end of func
