/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xutil/ranges.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(test_tscl_crange_contains) {
    crange range = tscl_crange_create(1, 5);
    TEST_ASSERT_TRUE(tscl_crange_contains(&range, 3));
    TEST_ASSERT_FALSE(tscl_crange_contains(&range, 7));
}

XTEST_CASE(test_tscl_crange_overlaps) {
    crange range1 = tscl_crange_create(1, 5);
    crange range2 = tscl_crange_create(3, 7);
    TEST_ASSERT_TRUE(tscl_crange_overlaps(&range1, &range2));

    crange range3 = tscl_crange_create(6, 10);
    TEST_ASSERT_FALSE(tscl_crange_overlaps(&range1, &range3));
}

XTEST_CASE(test_tscl_crange_intersection) {
    crange range1 = tscl_crange_create(1, 5);
    crange range2 = tscl_crange_create(3, 7);
    crange intersection = tscl_crange_intersection(&range1, &range2);
    TEST_ASSERT_EQUAL_INT(3, intersection.min);
    TEST_ASSERT_EQUAL_INT(5, intersection.max);

    crange range3 = tscl_crange_create(6, 10);
    crange noIntersection = tscl_crange_intersection(&range1, &range3);
    TEST_ASSERT_TRUE(tscl_crange_is_empty(&noIntersection));
}

XTEST_CASE(test_tscl_crange_is_subset) {
    crange range1 = tscl_crange_create(1, 5);
    crange range2 = tscl_crange_create(3, 4);
    TEST_ASSERT_TRUE(tscl_crange_is_subset(&range2, &range1));

    crange range3 = tscl_crange_create(6, 10);
    TEST_ASSERT_FALSE(tscl_crange_is_subset(&range3, &range1));
}

XTEST_CASE(test_tscl_crange_is_equal) {
    crange range1 = tscl_crange_create(1, 5);
    crange range2 = tscl_crange_create(1, 5);
    TEST_ASSERT_TRUE(tscl_crange_is_equal(&range1, &range2));

    crange range3 = tscl_crange_create(6, 10);
    TEST_ASSERT_FALSE(tscl_crange_is_equal(&range1, &range3));
}

XTEST_CASE(test_tscl_crange_union) {
    crange range1 = tscl_crange_create(1, 5);
    crange range2 = tscl_crange_create(3, 7);
    crange unionRange = tscl_crange_union(&range1, &range2);
    TEST_ASSERT_EQUAL_INT(1, unionRange.min);
    TEST_ASSERT_EQUAL_INT(7, unionRange.max);

    crange range3 = tscl_crange_create(8, 10);
    crange disjointUnion = tscl_crange_union(&range1, &range3);
    TEST_ASSERT_TRUE(tscl_crange_is_empty(&disjointUnion));
}

XTEST_CASE(test_tscl_crange_expand) {
    crange range = tscl_crange_create(1, 5);
    crange expandedRange = tscl_crange_expand(&range, 2);
    TEST_ASSERT_EQUAL_INT(3, expandedRange.min);
    TEST_ASSERT_EQUAL_INT(7, expandedRange.max);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_ranges_group) {
    XTEST_RUN_UNIT(test_tscl_crange_contains,     runner);
    XTEST_RUN_UNIT(test_tscl_crange_overlaps,     runner);
    XTEST_RUN_UNIT(test_tscl_crange_intersection, runner);
    XTEST_RUN_UNIT(test_tscl_crange_is_subset,    runner);
    XTEST_RUN_UNIT(test_tscl_crange_is_equal,     runner);
    XTEST_RUN_UNIT(test_tscl_crange_union,        runner);
    XTEST_RUN_UNIT(test_tscl_crange_expand,       runner);
} // end of func
