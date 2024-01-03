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
#include "fossil/xutil/assume.h"
#include <stdio.h>
#include <stdlib.h>

// Assumption function to be used in conditions
bool fscl_assume(bool condition, const char *message) {
    if (!condition) {
        fprintf(stderr, "Assumption failed: %s\n", message);
        exit(EXIT_FAILURE);
    }
    return true;
}

// Assumption functions for different conditions using bitwise operators
bool fscl_assume_this(bool condition) {
    return fscl_assume(condition, "Condition not met: fscl_assume_this");
}

bool fscl_assume_this_and_that(bool condition1, bool condition2) {
    return fscl_assume(condition1 & condition2, "Conditions not met: fscl_assume_this_and_that");
}

bool fscl_assume_this_or_that(bool condition1, bool condition2) {
    return fscl_assume(condition1 | condition2, "Conditions not met: fscl_assume_this_or_that");
}

bool fscl_assume_this_unless(bool condition1, bool condition2) {
    return fscl_assume(!(condition1) || condition2, "Conditions not met: fscl_assume_this_unless");
}

bool fscl_assume_this_not_that(bool condition1, bool condition2) {
    return fscl_assume(condition1 & !condition2, "Conditions not met: fscl_assume_this_not_that");
}

bool fscl_assume_range(int value, int min, int max) {
    return fscl_assume(value >= min && value <= max, "Value is not within the specified range");
}

bool fscl_assume_not_cnullptr(void *ptr) {
    return fscl_assume(ptr != NULL, "Pointer is unexpectedly NULL");
}