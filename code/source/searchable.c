/*  ----------------------------------------------------------------------------
    File: searchable.c

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
#include "trilobite/xutil/searchable.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

// Function to perform linear search on an array of csearchable values
int tscl_searchable_linear_search(const csearchable *arr, int size, const csearchable *key) {
    for (int i = 0; i < size; i++) {
        if (tscl_searchable_compare(&arr[i], key) == 0) {
            return i;  // Return the index if the key is found
        }
    }
    return -1;  // Return -1 if the key is not found
}

// Function to perform binary search on a sorted array of csearchable values
int tscl_searchable_binary_search(const csearchable *arr, int size, const csearchable *key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (tscl_searchable_compare(&arr[mid], key) == 0) {
            return mid;  // Return the index if the key is found
        }

        if (tscl_searchable_compare(&arr[mid], key) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  // Return -1 if the key is not found
}

// Function to perform basic string search on an array of csearchable cstrings
int tscl_searchable_string_search(const csearchable *arr, int size, const csearchable *key) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].cstring, key->cstring) == 0) {
            return i;  // Return the index if the key is found
        }
    }
    return -1;  // Return -1 if the key is not found
}

// Function to perform interpolation search on a sorted array of csearchable values
int tscl_searchable_interpolation_search(const csearchable *arr, int size, const csearchable *key) {
    int low = 0, high = size - 1;

    while (low <= high && key->integer >= arr[low].integer && key->integer <= arr[high].integer) {
        int pos = low + ((double)(key->integer - arr[low].integer) / (arr[high].integer - arr[low].integer)) * (high - low);

        if (tscl_searchable_compare(&arr[pos], key) == 0) {
            return pos;  // Return the index if the key is found
        }

        if (tscl_searchable_compare(&arr[pos], key) < 0) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1;  // Return -1 if the key is not found
}

// Function to perform jump search on a sorted array of csearchable values
int tscl_searchable_jump_search(const csearchable *arr, int size, const csearchable *key) {
    int step = sqrt(size);
    int prev = 0;

    while (arr[min(step, size) - 1].integer < key->integer) {
        prev = step;
        step += sqrt(size);

        if (prev >= size) {
            return -1;
        }
    }

    for (int i = prev; i < min(step, size); i++) {
        if (tscl_searchable_compare(&arr[i], key) == 0) {
            return i;  // Return the index if the key is found
        }
    }

    return -1;  // Return -1 if the key is not found
}

// Function to compare two csearchable values
int tscl_searchable_compare(const csearchable *a, const csearchable *b) {
    // Implement your comparison logic based on the data type
    if (a->integer < b->integer) return -1;
    if (a->integer > b->integer) return 1;

    // Add comparisons for other types
    if (a->boolean < b->boolean) return -1;
    if (a->boolean > b->boolean) return 1;

    // For cstring comparison using strcmp
    if (strcmp(a->cstring, b->cstring) < 0) return -1;
    if (strcmp(a->cstring, b->cstring) > 0) return 1;

    return 0;
}

// Function to select a search algorithm based on the size of the array
int tscl_searchable_auto(const csearchable *arr, int size, const csearchable *key) {
    if (size < 10) {
        return tscl_searchable_linear_search(arr, size, key);
    } else if (size < 100) {
        return tscl_searchable_jump_search(arr, size, key);
    } else if (size < 1000) {
        return tscl_searchable_interpolation_search(arr, size, key);
    } else {
        return tscl_searchable_binary_search(arr, size, key);
    }
}
