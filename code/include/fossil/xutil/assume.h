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
#ifndef FSCL_ASSUME_H
#define FSCL_ASSUME_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>

// =================================================================
// Avalable functions
// =================================================================
/**
 * Assume a condition is true, and print a message if it's false.
 *
 * @param condition The condition to be assumed true.
 * @param message   The message to be printed if the condition is false.
 * @return          The value of the condition.
 */
bool fscl_assume(bool condition, const char *message);

/**
 * Assume a condition is true and print a default message if it's false.
 *
 * @param condition The condition to be assumed true.
 * @return          The value of the condition.
 */
bool fscl_assume_this(bool condition);

/**
 * Assume two conditions, both must be true, and print a default message if not.
 *
 * @param condition1 The first condition to be assumed true.
 * @param condition2 The second condition to be assumed true.
 * @return           The combined value of the conditions.
 */
bool fscl_assume_this_and_that(bool condition1, bool condition2);

/**
 * Assume either of two conditions is true, and print a default message if neither is true.
 *
 * @param condition1 The first condition to be assumed true.
 * @param condition2 The second condition to be assumed true.
 * @return           The combined value of the conditions.
 */
bool fscl_assume_this_or_that(bool condition1, bool condition2);

/**
 * Assume the first condition is true unless the second condition is true, and print a default message if not.
 *
 * @param condition1 The condition to be assumed true unless condition2 is true.
 * @param condition2 The condition that, if true, negates condition1.
 * @return           The value of the conditions.
 */
bool fscl_assume_this_unless(bool condition1, bool condition2);

/**
 * Assume the first condition is true and the second condition is false, and print a default message if not.
 *
 * @param condition1 The condition to be assumed true.
 * @param condition2 The condition to be assumed false.
 * @return           The value of the conditions.
 */
bool fscl_assume_this_not_that(bool condition1, bool condition2);

/**
 * Assume that a value is within a specified range (inclusive), and print a default message if not.
 *
 * @param value The value to be assumed within the specified range.
 * @param min   The minimum value of the range.
 * @param max   The maximum value of the range.
 * @return      True if the value is within the range, false otherwise.
 */
bool fscl_assume_range(int value, int min, int max);

/**
 * Assume that a pointer is not a null pointer, and print a default message if it is.
 *
 * @param ptr The pointer to be assumed not null.
 * @return    True if the pointer is not null, false otherwise.
 */
bool fscl_assume_not_cnullptr(void *ptr);

#ifdef __cplusplus
}
#endif

#endif
