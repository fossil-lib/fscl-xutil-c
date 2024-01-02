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
#include "fossil/xutil/ranges.h"

// Function to check if a value is within the specified range
bool fscl_crange_contains(const crange *range, int value) {
    return (value >= range->min) && (value <= range->max);
}

// Function to check if two ranges overlap
bool fscl_crange_overlaps(const crange *range1, const crange *range2) {
    return (range1->min <= range2->max) && (range1->max >= range2->min);
}

// Function to get the intersection of two ranges
crange fscl_crange_intersection(const crange *range1, const crange *range2) {
    crange intersection;
    intersection.min = (range1->min > range2->min) ? range1->min : range2->min;
    intersection.max = (range1->max < range2->max) ? range1->max : range2->max;
    return intersection;
}

// Function to check if a range is empty
bool fscl_crange_is_empty(const crange *range) {
    return range->min > range->max;
}

// Function to check if a range is valid (min <= max)
bool fscl_crange_is_valid(const crange *range) {
    return range->min <= range->max;
}

// Function to create a range with specified minimum and maximum values
crange fscl_crange_create(int min, int max) {
    crange range;
    range.min = min;
    range.max = max;
    return range;
}

// Function to check if a range is a subset of another range
bool fscl_crange_is_subset(const crange *subRange, const crange *superRange) {
    return (subRange->min >= superRange->min) && (subRange->max <= superRange->max);
}

// Function to check if a range is equal to another range
bool fscl_crange_is_equal(const crange *range1, const crange *range2) {
    return (range1->min == range2->min) && (range1->max == range2->max);
}

// Function to calculate the union of two ranges
crange fscl_crange_union(const crange *range1, const crange *range2) {
    crange unionRange;
    unionRange.min = (range1->min < range2->min) ? range1->min : range2->min;
    unionRange.max = (range1->max > range2->max) ? range1->max : range2->max;
    return unionRange;
}

// Function to expand a range by a specified amount
crange fscl_crange_expand(const crange *range, int amount) {
    crange expandedRange;
    expandedRange.min = range->min - amount;
    expandedRange.max = range->max + amount;
    return expandedRange;
}
