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
#include "fossil/xutil/ranges.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(test_fscl_crange_contains) {
    crange range = fscl_crange_create(1, 5);
    TEST_ASSERT_TRUE(fscl_crange_contains(&range, 3));
    TEST_ASSERT_FALSE(fscl_crange_contains(&range, 7));
}

XTEST_CASE(test_fscl_crange_overlaps) {
    crange range1 = fscl_crange_create(1, 5);
    crange range2 = fscl_crange_create(3, 7);
    TEST_ASSERT_TRUE(fscl_crange_overlaps(&range1, &range2));

    crange range3 = fscl_crange_create(6, 10);
    TEST_ASSERT_FALSE(fscl_crange_overlaps(&range1, &range3));
}

XTEST_CASE(test_fscl_crange_intersection) {
    crange range1 = fscl_crange_create(1, 5);
    crange range2 = fscl_crange_create(3, 7);
    crange intersection = fscl_crange_intersection(&range1, &range2);
    TEST_ASSERT_EQUAL_INT(3, intersection.min);
    TEST_ASSERT_EQUAL_INT(5, intersection.max);

    crange range3 = fscl_crange_create(6, 10);
    crange noIntersection = fscl_crange_intersection(&range1, &range3);
    TEST_ASSERT_TRUE(fscl_crange_is_empty(&noIntersection));
}

XTEST_CASE(test_fscl_crange_is_subset) {
    crange range1 = fscl_crange_create(1, 5);
    crange range2 = fscl_crange_create(3, 4);
    TEST_ASSERT_TRUE(fscl_crange_is_subset(&range2, &range1));

    crange range3 = fscl_crange_create(6, 10);
    TEST_ASSERT_FALSE(fscl_crange_is_subset(&range3, &range1));
}

XTEST_CASE(test_fscl_crange_is_equal) {
    crange range1 = fscl_crange_create(1, 5);
    crange range2 = fscl_crange_create(1, 5);
    TEST_ASSERT_TRUE(fscl_crange_is_equal(&range1, &range2));

    crange range3 = fscl_crange_create(6, 10);
    TEST_ASSERT_FALSE(fscl_crange_is_equal(&range1, &range3));
}

XTEST_CASE(test_fscl_crange_union) {
    crange range1 = fscl_crange_create(1, 5);
    crange range2 = fscl_crange_create(3, 7);
    crange unionRange = fscl_crange_union(&range1, &range2);
    TEST_ASSERT_EQUAL_INT(1, unionRange.min);
    TEST_ASSERT_EQUAL_INT(7, unionRange.max);

    crange range3 = fscl_crange_create(8, 10);
    crange disjointUnion = fscl_crange_union(&range1, &range3);
    TEST_ASSERT_TRUE(fscl_crange_is_empty(&disjointUnion));
}

XTEST_CASE(test_fscl_crange_expand) {
    crange range = fscl_crange_create(1, 5);
    crange expandedRange = fscl_crange_expand(&range, 2);
    TEST_ASSERT_EQUAL_INT(3, expandedRange.min);
    TEST_ASSERT_EQUAL_INT(7, expandedRange.max);
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(test_ranges_group) {
    XTEST_RUN_UNIT(test_fscl_crange_contains);
    XTEST_RUN_UNIT(test_fscl_crange_overlaps);
    XTEST_RUN_UNIT(test_fscl_crange_intersection);
    XTEST_RUN_UNIT(test_fscl_crange_is_subset);
    XTEST_RUN_UNIT(test_fscl_crange_is_equal);
    XTEST_RUN_UNIT(test_fscl_crange_union);
    XTEST_RUN_UNIT(test_fscl_crange_expand);
} // end of func
