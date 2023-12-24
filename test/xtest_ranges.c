/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xutil/platform.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(testLavaSeed) {}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_ranges_group) {
    XTEST_RUN_UNIT(testLavaSeed,   runner);
    XTEST_RUN_UNIT(testLavaRandom, runner);
} // end of func
