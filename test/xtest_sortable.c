/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xutil/sortable.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(test_func) {}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_sortable_group) {
    XTEST_RUN_UNIT(test_is_little_endian, runner);
} // end of func
