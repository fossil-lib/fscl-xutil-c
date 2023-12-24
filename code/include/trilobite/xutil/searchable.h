/*
   This C header file is part of the Trilobite Stdlib, a collection of utility functions and
   standard data structures for enhancing software development projects. Feel free to use
   and modify these utilities to streamline your software development process.

   Project: Trilobite Stdlib
   Author: Michael Gene Brockus (Dreamer)
   Email: michaelbrockus@gmail.com
   Website: [Trilobite Coder Blog](https://trilobite.home.blog)

   Trilobite Stdlib is designed to provide a robust set of functionalities that can be
   incorporated into various projects. The utilities included in this library aim to optimize
   and standardize common operations, ensuring efficient and reliable code.

   This header file is a part of a broader initiative to support developers in creating secure,
   efficient, and scalable software. Contributions, suggestions, and feedback are welcomed,
   as we strive to continuously improve and expand the capabilities of Trilobite Stdlib.

   License: Apache License 2.0
   SPDX Identifier: Apache-2.0

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software distributed under the License
   is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
   or implied. See the License for the specific language governing permissions and limitations
   under the License.

   The above copyright notice and this permission notice shall be included in all copies or
   substantial portions of the Software.

   Please review the full text of the Apache License 2.0 for the complete terms and conditions.

   (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
*/
#ifndef TSCL_SEARCHABLE_H
#define TSCL_SEARCHABLE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>

enum {SEARCHABLE_MAX_CSTR = 100};

// Define the searchable union type
typedef union {
    int integer;
    float floating_point;
    char character;
    bool boolean;
    char cstring[SEARCHABLE_MAX_CSTR];  // Assuming a maximum length of 100 characters, adjust as needed
} csearchable;

// =================================================================
// Avalable functions
// =================================================================
int tscl_searchable_linear_search(const csearchable *arr, int size, const csearchable *key);
int tscl_searchable_binary_search(const csearchable *arr, int size, const csearchable *key);
int tscl_searchable_string_search(const csearchable *arr, int size, const csearchable *key);
int tscl_searchable_interpolation_search(const csearchable *arr, int size, const csearchable *key);
int tscl_searchable_jump_search(const csearchable *arr, int size, const csearchable *key);
int tscl_searchable_compare(const csearchable *a, const csearchable *b);
int tscl_searchable_auto(const csearchable *arr, int size, const csearchable *key);

#ifdef __cplusplus
}
#endif

#endif