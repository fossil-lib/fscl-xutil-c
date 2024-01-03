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
#ifndef FSCL_RANGES_H
#define FSCL_RANGES_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>

// Represents a range with a minimum and maximum value
typedef struct {
    int min;
    int max;
} crange;

// =================================================================
// Avalable functions
// =================================================================
bool fscl_crange_contains(const crange *range, int value);
bool fscl_crange_overlaps(const crange *range1, const crange *range2);
crange fscl_crange_intersection(const crange *range1, const crange *range2);
bool fscl_crange_is_empty(const crange *range);
bool fscl_crange_is_valid(const crange *range);
crange fscl_crange_create(int min, int max);
bool fscl_crange_is_subset(const crange *subRange, const crange *superRange);
bool fscl_crange_is_equal(const crange *range1, const crange *range2);
crange fscl_crange_union(const crange *range1, const crange *range2);
crange fscl_crange_expand(const crange *range, int amount);

#ifdef __cplusplus
}
#endif

#endif
