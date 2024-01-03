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
#include "fossil/xutil/platform.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(test_is_little_endian) {
    TEST_ASSERT_EQUAL_INT(1, fscl_platform_is_little_endian());
}

XTEST_CASE(test_is_big_endian) {
    TEST_ASSERT_EQUAL_INT(0, fscl_platform_is_big_endian());
}

XTEST_CASE(test_swap_endian_16) {
    uint16_t original = 0xABCD;
    uint16_t swapped = fscl_platform_swap_endian_16(original);
    TEST_ASSERT_EQUAL_HEX16(0xCDAB, swapped);
}

XTEST_CASE(test_swap_endian_32) {
    uint32_t original = 0x12345678;
    uint32_t swapped = fscl_platform_swap_endian_32(original);
    TEST_ASSERT_EQUAL_HEX32(0x78563412, swapped);
}

XTEST_CASE(test_swap_endian_64) {
    uint64_t original = 0x0123456789ABCDEF;
    uint64_t swapped = fscl_platform_swap_endian_64(original);
    TEST_ASSERT_EQUAL_HEX64(0xEFCDAB8967452301, swapped);
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(test_platform_group) {
    XTEST_RUN_UNIT(test_is_little_endian);
    XTEST_RUN_UNIT(test_is_big_endian);
    XTEST_RUN_UNIT(test_swap_endian_16);
    XTEST_RUN_UNIT(test_swap_endian_32);
    XTEST_RUN_UNIT(test_swap_endian_64);
} // end of func
