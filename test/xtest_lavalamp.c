/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xutil/lavalamp.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(testLavaSeed) {
    // Test tscl_lava_seed function
    tscl_lava_seed(123);
    TEST_ASSERT_EQUAL_UINT(tscl_lava_random(), tscl_lava_random());
}

XTEST_CASE(testLavaRandom) {
    // Test tscl_lava_random function
    unsigned int seed = 456;
    tscl_lava_seed(seed);
    TEST_ASSERT_NOT_EQUAL_UINT(tscl_lava_random(), tscl_lava_random());
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_random_group) {
    XTEST_RUN_UNIT(testLavaSeed,   runner);
    XTEST_RUN_UNIT(testLavaRandom, runner);
} // end of func
