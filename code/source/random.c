/*  ----------------------------------------------------------------------------
    File: random.c

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
#include "trilobite/xutil/random.h"
#include <string.h>

// Define the state for the random number generator
static uint32_t RANDOM_STATE = 123456789;

// Initialize the random seed with a given value
void random_seed(uint32_t seed) {
    RANDOM_STATE = seed;
} // end of func

// Generate a 32-bit random integer
uint32_t random_generator(void) {
    RANDOM_STATE ^= (RANDOM_STATE << 13);
    RANDOM_STATE ^= (RANDOM_STATE >> 17);
    RANDOM_STATE ^= (RANDOM_STATE << 5);
    return RANDOM_STATE;
} // end of func

// Generate a random integer in the specified range [min, max]
int random_range(int min, int max) {
    if (max < min) {
        // Invalid range, return a default value
        return min;
    }

    int range = max - min + 1;
    if (range <= 0) {
        // Invalid range, return a default value
        return min;
    }

    return min + (random_generator() % range);
} // end of func

// Generate a random floating-point number in the range [0, 1)
double random_lava() {
    return (double)random_generator() / UINT32_MAX;
} // end of func

// Shuffle an array of integers using the Fisher-Yates shuffle
void random_shuffle_int(int *array, size_t size) {
    if (!array || size <= 1) {
        // Nothing to shuffle
        return;
    }

    for (size_t i = size - 1; i > 0; i--) {
        size_t j = random_range(0, i);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
} // end of func

// Shuffle an array of char using the Fisher-Yates shuffle
void random_shuffle_char(char *array, size_t size) {
    if (!array || size <= 1) {
        // Nothing to shuffle
        return;
    }

    for (size_t i = size - 1; i > 0; i--) {
        size_t j = random_range(0, i);
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
} // end of func

// Shuffle an array of strings using the Fisher-Yates shuffle
void random_shuffle_string(char *array[], size_t size) {
    if (!array || size <= 1) {
        // Nothing to shuffle
        return;
    }

    for (size_t i = size - 1; i > 0; i--) {
        size_t j = random_range(0, i);
        char *temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
} // end of func

// Generates a random boolean value (true or false).
bool random_bool(void) {
    return rand() % 2 == 0;
} // end of func

// Generates a random float in the specified range [min, max).
float random_float_range(float min, float max) {
    return min + (float)rand() / RAND_MAX * (max - min);
} // end of func

// Generates a random double in the specified range [min, max).
double random_double_range(double min, double max) {
    return min + (double)rand() / RAND_MAX * (max - min);
} // end of func
