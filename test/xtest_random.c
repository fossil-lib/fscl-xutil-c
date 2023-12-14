/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xutil/random.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(random_let_random_seed) {
    random_seed(12345);
    TEST_ASSERT_EQUAL_UINT32(12345, random_generator());
}

XTEST_CASE(random_let_random_range) {
    int min = 5, max = 10;
    int randomValue = random_range(min, max);
    TEST_ASSERT_TRUE(randomValue >= min && randomValue <= max);
}

XTEST_CASE(random_let_random_shuffle_int) {
    int originalArray[5] = {1, 2, 3, 4, 5};
    int shuffledArray[5];
    memcpy(shuffledArray, originalArray, sizeof(originalArray));
    random_shuffle_int(shuffledArray, 5);
    
    int equal = 1;
    for (int i = 0; i < 5; i++) {
        if (shuffledArray[i] != originalArray[i]) {
            equal = 0;
            break;
        }
    }
    TEST_ASSERT_FALSE(equal);
}

XTEST_CASE(random_let_random_shuffle_char) {
    char originalArray[] = "abcde";
    char shuffledArray[] = "abcde";
    random_shuffle_char(shuffledArray, 5);
    
    int equal = 1;
    for (int i = 0; i < 5; i++) {
        if (shuffledArray[i] != originalArray[i]) {
            equal = 0;
            break;
        }
    }
    TEST_ASSERT_FALSE(equal);
}

XTEST_CASE(random_let_random_shuffle_string) {
    char *originalArray[] = {"apple", "banana", "cherry", "date"};
    char *shuffledArray[] = {"apple", "banana", "cherry", "date"};
    random_shuffle_string(shuffledArray, 4);
    
    int equal = 1;
    for (int i = 0; i < 4; i++) {
        if (strcmp(shuffledArray[i], originalArray[i]) != 0) {
            equal = 0;
            break;
        }
    }
    TEST_ASSERT_FALSE(equal);
}

// Test seeding and generating random number
XTEST_CASE(random_let_random_seed_and_generate) {
    // Seed the random number generator with a specific value
    random_seed(12345);
    
    // Test if the generated number matches the expected value
    TEST_ASSERT_EQUAL_UINT32(361505892, random_generator());
}

// Test random range with invalid range
XTEST_CASE(random_let_random_range_invalid_range) {
    // Test when the range is invalid (max < min)
    int min = 10, max = 5;
    int randomValue = random_range(min, max);

    // The result should be the minimum value as it is an invalid range
    TEST_ASSERT_EQUAL_INT(min, randomValue);
}


//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_random_group) {
    XTEST_RUN_UNIT(random_let_random_seed,           runner);
    XTEST_RUN_UNIT(random_let_random_range,          runner);
    XTEST_RUN_UNIT(random_let_random_shuffle_int,    runner);
    XTEST_RUN_UNIT(random_let_random_shuffle_char,   runner);
    XTEST_RUN_UNIT(random_let_random_shuffle_string, runner);
    XTEST_RUN_UNIT(random_let_random_seed_and_generate,   runner);
    XTEST_RUN_UNIT(random_let_random_range_invalid_range, runner);
} // end of function main
