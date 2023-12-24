/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xutil/shuffle.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(test_shuffle_int) {
    // Test tscl_shuffle_int function
    int array[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(array) / sizeof(int);

    tscl_shuffle_int(array, size);

    // Assert that the array is shuffled
    for (size_t i = 0; i < size; ++i) {
        TEST_ASSERT_NOT_EQUAL(i + 1, array[i]);
    }
}

XTEST_CASE(test_shuffle_cstring) {
    // Test tscl_shuffle_cstring function
    char* array[] = {"apple", "banana", "cherry", "date", "elderberry"};
    size_t size = sizeof(array) / sizeof(char*);

    tscl_shuffle_cstring(array, size);

    // Assert that the array is shuffled
    for (size_t i = 0; i < size; ++i) {
        TEST_ASSERT_NOT_EQUAL_STRING(array[0], array[i]);
    }
}

XTEST_CASE(test_shuffle_letter) {
    // Test tscl_shuffle_letter function
    char array[] = {'a', 'b', 'c', 'd', 'e'};
    size_t size = sizeof(array) / sizeof(char);

    tscl_shuffle_letter(array, size);

    // Assert that the array is shuffled
    for (size_t i = 0; i < size; ++i) {
        TEST_ASSERT_NOT_EQUAL('a' + i, array[i]);
    }
}

XTEST_CASE(test_shuffle_bool) {
    // Test tscl_shuffle_bool function
    bool array[] = {true, false, true, false, true};
    size_t size = sizeof(array) / sizeof(bool);

    tscl_shuffle_bool(array, size);

    // Assert that the array is shuffled
    for (size_t i = 0; i < size; ++i) {
        TEST_ASSERT_NOT_EQUAL(array[0], array[i]);
    }
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_shuffle_group) {
    XTEST_RUN_UNIT(test_shuffle_int,     runner);
    XTEST_RUN_UNIT(test_shuffle_cstring, runner);
    XTEST_RUN_UNIT(test_shuffle_letter,  runner);
    XTEST_RUN_UNIT(test_shuffle_bool,    runner);
} // end of func
