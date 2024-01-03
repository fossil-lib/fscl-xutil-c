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
bool fscl_assume(bool condition, const char *message);
bool fscl_assume_this(bool condition);
bool fscl_assume_this_and_that(bool condition1, bool condition2);
bool fscl_assume_this_or_that(bool condition1, bool condition2);
bool fscl_assume_this_unless(bool condition1, bool condition2);
bool fscl_assume_this_not_that(bool condition1, bool condition2);
bool fscl_assume_range(int value, int min, int max);
bool fscl_assume_not_cnullptr(void *ptr);

#ifdef __cplusplus
}
#endif

#endif
