/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xutil/searchable.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(test_searchable_linear_search) {
    csearchable arr[] = {
        {.integer = 1},
        {.integer = 2},
        {.integer = 3},
        {.integer = 4},
        {.integer = 5},
    };

    int size = sizeof(arr) / sizeof(arr[0]);
    csearchable key = {.integer = 3};

    int index = tscl_searchable_linear_search(arr, size, &key);

    TEST_ASSERT_EQUAL_INT(2, index);
}

XTEST_CASE(test_searchable_binary_search) {
    csearchable arr[] = {
        {.integer = 1},
        {.integer = 2},
        {.integer = 3},
        {.integer = 4},
        {.integer = 5},
    };

    int size = sizeof(arr) / sizeof(arr[0]);
    csearchable key = {.integer = 3};

    int index = tscl_searchable_binary_search(arr, size, &key);

    TEST_ASSERT_EQUAL_INT(2, index);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_search_group) {
    XTEST_RUN_UNIT(test_searchable_linear_search, runner);
    XTEST_RUN_UNIT(test_searchable_binary_search, runner);
} // end of func
