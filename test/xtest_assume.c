/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include "fossil/xutil/assume.h"

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(test_fscl_assume_this) {
    TEST_ASSERT_TRUE(fscl_assume_this(1 == 1));
}

XTEST_CASE(test_fscl_assume_this_and_that) {
    TEST_ASSERT_TRUE(fscl_assume_this_and_that(1 == 1, 2 == 2));
}

XTEST_CASE(test_fscl_assume_this_or_that) {
    TEST_ASSERT_TRUE(fscl_assume_this_or_that(1 == 1, 2 == 2));
}

XTEST_CASE(test_fscl_assume_this_unless) {
    TEST_ASSERT_TRUE(fscl_assume_this_unless(1 == 1, 2 == 2));
}

XTEST_CASE(test_fscl_assume_this_not_that) {
    TEST_ASSERT_TRUE(fscl_assume_this_not_that(1 == 1, 2 != 1));
}

XTEST_CASE(test_fscl_assume_range) {
    TEST_ASSERT_TRUE(fscl_assume_range(5, 0, 10));
}

XTEST_CASE(test_fscl_assume_not_cnullptr) {
    int *ptr = malloc(sizeof(int));
    TEST_ASSERT_TRUE(fscl_assume_not_cnullptr(ptr));
    free(ptr);
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(test_assume_group) {
    XTEST_RUN_UNIT(test_fscl_assume_this);
    XTEST_RUN_UNIT(test_fscl_assume_this_and_that);
    XTEST_RUN_UNIT(test_fscl_assume_this_or_that);
    XTEST_RUN_UNIT(test_fscl_assume_this_unless);
    XTEST_RUN_UNIT(test_fscl_assume_this_not_that);
    XTEST_RUN_UNIT(test_fscl_assume_range);
    XTEST_RUN_UNIT(test_fscl_assume_not_cnullptr);
} // end of func
