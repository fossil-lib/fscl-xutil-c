/*  ----------------------------------------------------------------------------
    File: ranges.c

    Description:
    This source file contains the code entry point for the Trilobite Stdlib project.
    It demonstrates the usage of various utilities and functions provided by the
    Trilobite Stdlib to enhance software development.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.home.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
*/
#include "trilobite/xutil/ranges.h"

// Function to check if a value is within the specified range
bool tscl_crange_contains(const crange *range, int value) {
    return (value >= range->min) && (value <= range->max);
}

// Function to check if two ranges overlap
bool tscl_crange_overlaps(const crange *range1, const crange *range2) {
    return (range1->min <= range2->max) && (range1->max >= range2->min);
}

// Function to get the intersection of two ranges
crange tscl_crange_intersection(const crange *range1, const crange *range2) {
    crange intersection;
    intersection.min = (range1->min > range2->min) ? range1->min : range2->min;
    intersection.max = (range1->max < range2->max) ? range1->max : range2->max;
    return intersection;
}

// Function to check if a range is empty
bool tscl_crange_is_empty(const crange *range) {
    return range->min > range->max;
}

// Function to check if a range is valid (min <= max)
bool tscl_crange_is_valid(const crange *range) {
    return range->min <= range->max;
}

// Function to create a range with specified minimum and maximum values
crange tscl_crange_create(int min, int max) {
    crange range;
    range.min = min;
    range.max = max;
    return range;
}

// Function to check if a range is a subset of another range
bool tscl_crange_is_subset(const crange *subRange, const crange *superRange) {
    return (subRange->min >= superRange->min) && (subRange->max <= superRange->max);
}

// Function to check if a range is equal to another range
bool tscl_crange_is_equal(const crange *range1, const crange *range2) {
    return (range1->min == range2->min) && (range1->max == range2->max);
}

// Function to calculate the union of two ranges
crange tscl_crange_union(const crange *range1, const crange *range2) {
    crange unionRange;
    unionRange.min = (range1->min < range2->min) ? range1->min : range2->min;
    unionRange.max = (range1->max > range2->max) ? range1->max : range2->max;
    return unionRange;
}

// Function to expand a range by a specified amount
crange tscl_crange_expand(const crange *range, int amount) {
    crange expandedRange;
    expandedRange.min = range->min - amount;
    expandedRange.max = range->max + amount;
    return expandedRange;
}
