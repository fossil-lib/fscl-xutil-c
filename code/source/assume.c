/*  ----------------------------------------------------------------------------
    File: assume.c

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
#include "trilobite/xutil/assume.h"
#include <stdio.h>
#include <stdlib.h>

// Assumption function to be used in conditions
bool tscl_assume(bool condition, const char *message) {
    if (!condition) {
        fprintf(stderr, "Assumption failed: %s\n", message);
        exit(EXIT_FAILURE);
    }
    return true;
}

// Assumption functions for different conditions using bitwise operators
bool tscl_assume_this(bool condition) {
    return tscl_assume(condition, "Condition not met: tscl_assume_this");
}

bool tscl_assume_this_and_that(bool condition1, bool condition2) {
    return tscl_assume(condition1 & condition2, "Conditions not met: tscl_assume_this_and_that");
}

bool tscl_assume_this_or_that(bool condition1, bool condition2) {
    return tscl_assume(condition1 | condition2, "Conditions not met: tscl_assume_this_or_that");
}

bool tscl_assume_this_unless(bool condition1, bool condition2) {
    return tscl_assume(~condition1 | condition2, "Conditions not met: tscl_assume_this_unless");
}

bool tscl_assume_this_not_that(bool condition1, bool condition2) {
    return tscl_assume(condition1 & !condition2, "Conditions not met: tscl_assume_this_not_that");
}

bool tscl_assume_range(int value, int min, int max) {
    return tscl_assume(value >= min && value <= max, "Value is not within the specified range");
}

bool tscl_assume_not_cnullptr(const void *ptr) {
    return tscl_assume(ptr != NULL, "Pointer is unexpectedly NULL");
}