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
XTEST_CASE(test_is_little_endian) {
    TEST_ASSERT_EQUAL_INT(1, tscl_platform_is_little_endian());
}

XTEST_CASE(test_is_big_endian) {
    TEST_ASSERT_EQUAL_INT(0, tscl_platform_is_big_endian());
}

XTEST_CASE(test_swap_endian_16) {
    uint16_t original = 0xABCD;
    uint16_t swapped = tscl_platform_swap_endian_16(original);
    TEST_ASSERT_EQUAL_HEX16(0xCDAB, swapped);
}

XTEST_CASE(test_swap_endian_32) {
    uint32_t original = 0x12345678;
    uint32_t swapped = tscl_platform_swap_endian_32(original);
    TEST_ASSERT_EQUAL_HEX32(0x78563412, swapped);
}

XTEST_CASE(test_swap_endian_64) {
    uint64_t original = 0x0123456789ABCDEF;
    uint64_t swapped = tscl_platform_swap_endian_64(original);
    TEST_ASSERT_EQUAL_HEX64(0xEFCDAB8967452301, swapped);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_platform_group) {
    XTEST_RUN_UNIT(test_is_little_endian, runner);
    XTEST_RUN_UNIT(test_is_big_endian,  runner);
    XTEST_RUN_UNIT(test_swap_endian_16, runner);
    XTEST_RUN_UNIT(test_swap_endian_32, runner);
    XTEST_RUN_UNIT(test_swap_endian_64, runner);
} // end of func
