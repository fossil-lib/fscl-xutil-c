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
XTEST_CASE(test_sorting_algorithms_integer) {
    csortable arr[] = {
        {.integer = 5},
        {.integer = 2},
        {.integer = 8},
        {.integer = 1},
        {.integer = 9}
    };

    int size = sizeof(arr) / sizeof(arr[0]);

    tscl_sortable_auto(arr, size);
    TEST_ASSERT_EQUAL_INT_ARRAY((int []){1, 2, 5, 8, 9}, (int *)arr, size);
}

XTEST_CASE(test_sorting_algorithms_float) {
    csortable arr[] = {
        {.floating_point = 5.2},
        {.floating_point = 2.8},
        {.floating_point = 8.1},
        {.floating_point = 1.9},
        {.floating_point = 9.7}
    };

    int size = sizeof(arr) / sizeof(arr[0]);

    tscl_sortable_auto(arr, size);
    TEST_ASSERT_EQUAL_FLOAT_ARRAY((float []){1.9, 2.8, 5.2, 8.1, 9.7}, (float *)arr, size);
}

XTEST_CASE(test_sorting_algorithms_char) {
    csortable arr[] = {
        {.character = 'e'},
        {.character = 'b'},
        {.character = 'h'},
        {.character = 'a'},
        {.character = 'i'}
    };

    int size = sizeof(arr) / sizeof(arr[0]);

    tscl_sortable_auto(arr, size);
    TEST_ASSERT_EQUAL_CHAR_ARRAY((char []){'a', 'b', 'e', 'h', 'i'}, (char *)arr, size);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_sortable_group) {
    XTEST_RUN_UNIT(test_sorting_algorithms_integer, runner);
    XTEST_RUN_UNIT(test_sorting_algorithms_float, runner);
    XTEST_RUN_UNIT(test_sorting_algorithms_char, runner);
} // end of func
