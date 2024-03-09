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

/**
 * Check if a value is within the specified range.
 *
 * @param range The range to check against.
 * @param value The value to check.
 * @return      True if the value is within the range, false otherwise.
 */
bool fscl_crange_contains(const crange *range, int value);

/**
 * Check if two ranges overlap.
 *
 * @param range1 The first range.
 * @param range2 The second range.
 * @return       True if the ranges overlap, false otherwise.
 */
bool fscl_crange_overlaps(const crange *range1, const crange *range2);

/**
 * Find the intersection of two ranges.
 *
 * @param range1 The first range.
 * @param range2 The second range.
 * @return       The intersection of the two ranges.
 */
crange fscl_crange_intersection(const crange *range1, const crange *range2);

/**
 * Check if a range is empty.
 *
 * @param range The range to check.
 * @return      True if the range is empty, false otherwise.
 */
bool fscl_crange_is_empty(const crange *range);

/**
 * Check if a range is valid.
 *
 * @param range The range to check.
 * @return      True if the range is valid, false otherwise.
 */
bool fscl_crange_is_valid(const crange *range);

/**
 * Create a range with the specified minimum and maximum values.
 *
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 * @return    The created range.
 */
crange fscl_crange_create(int min, int max);

/**
 * Check if one range is a subset of another.
 *
 * @param subRange   The potential subset range.
 * @param superRange The potential superset range.
 * @return           True if subRange is a subset of superRange, false otherwise.
 */
bool fscl_crange_is_subset(const crange *subRange, const crange *superRange);

/**
 * Check if two ranges are equal.
 *
 * @param range1 The first range.
 * @param range2 The second range.
 * @return       True if the ranges are equal, false otherwise.
 */
bool fscl_crange_is_equal(const crange *range1, const crange *range2);

/**
 * Find the union of two ranges.
 *
 * @param range1 The first range.
 * @param range2 The second range.
 * @return       The union of the two ranges.
 */
crange fscl_crange_union(const crange *range1, const crange *range2);

/**
 * Expand a range by a specified amount.
 *
 * @param range  The range to expand.
 * @param amount The amount by which to expand the range.
 * @return       The expanded range.
 */
crange fscl_crange_expand(const crange *range, int amount);

#ifdef __cplusplus
}
#endif

#endif
