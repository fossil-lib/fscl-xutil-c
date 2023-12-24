/*  ----------------------------------------------------------------------------
    File: shuffle.c

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
#include "trilobite/xutil/shuffle.h"
#include "trilobite/xutil/lavalamp.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tscl_shuffle_seed(unsigned int seed) {
    tscl_lava_seed(seed);
}

// Function to shuffle an array of integers
void tscl_shuffle_int(int* array, size_t size) {
    for (size_t i = size - 1; i > 0; --i) {
        size_t j = rand() % (i + 1);

        // Swap array[i] and array[j]
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Function to shuffle an array of doubles
void tscl_shuffle_double(double* array, size_t size) {
    for (size_t i = size - 1; i > 0; --i) {
        size_t j = rand() % (i + 1);

        // Swap array[i] and array[j]
        double temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Function to shuffle an array of C strings
void tscl_shuffle_cstring(char** array, size_t size) {
    for (size_t i = size - 1; i > 0; --i) {
        size_t j = rand() % (i + 1);

        // Swap array[i] and array[j]
        char* temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Function to shuffle an array of letters (char)
void tscl_shuffle_letter(char* array, size_t size) {
    for (size_t i = size - 1; i > 0; --i) {
        size_t j = rand() % (i + 1);

        // Swap array[i] and array[j]
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Function to shuffle an array of boolean values
void tscl_shuffle_bool(bool* array, size_t size) {
    for (size_t i = size - 1; i > 0; --i) {
        size_t j = rand() % (i + 1);

        // Swap array[i] and array[j]
        bool temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}