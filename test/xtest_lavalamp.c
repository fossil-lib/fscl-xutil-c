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
#include "fossil/xutil/lavalamp.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(testLavaSeed) {
    // Test fscl_lava_seed function
    fscl_lava_seed(123);
    TEST_ASSERT_EQUAL_UINT(fscl_lava_random(), fscl_lava_random());
}

XTEST_CASE(testLavaRandom) {
    // Test fscl_lava_random function
    unsigned int seed = 456;
    fscl_lava_seed(seed);
    TEST_ASSERT_NOT_EQUAL_UINT(fscl_lava_random(), fscl_lava_random());
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(test_random_group) {
    XTEST_RUN_UNIT(testLavaSeed);
    XTEST_RUN_UNIT(testLavaRandom);
} // end of func
