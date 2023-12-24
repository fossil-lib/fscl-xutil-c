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
#ifndef TSCL_ASSUME_H
#define TSCL_ASSUME_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdio.h>

// =================================================================
// Avalable functions
// =================================================================
bool tscl_assume(bool condition, const char* error_message);
bool tscl_assume_not_null(const void* pointer, const char* error_message);
bool tscl_assume_within_bounds(size_t index, size_t size, const char* error_message);
bool tscl_assume_warn(bool condition, const char* warning_message);
bool tscl_assume_not_null_warn(const void* pointer, const char* warning_message);
bool tscl_assume_within_bounds_warn(size_t index, size_t size, const char* warning_message);
bool tscl_assume_positive(int value, const char* error_message);
bool tscl_assume_non_negative(int value, const char* error_message);
bool tscl_assume_negative(int value, const char* error_message);
bool tscl_assume_finite(double value, const char* error_message);
bool tscl_assume_not_nan(double value, const char* error_message);
bool tscl_assume_digit(char c, const char* error_message);
bool tscl_assume_uppercase(char c, const char* error_message);
bool tscl_assume_lowercase(char c, const char* error_message);
bool tscl_assume_not_empty_string(const char* str, const char* error_message);
bool tscl_assume_aligned(const void* ptr, size_t alignment, const char* error_message);
bool tscl_assume_file_not_null(FILE* file, const char* error_message);
bool tscl_assume_file_open(FILE* file, const char* error_message);
bool tscl_assume_file_at_end(FILE* file, const char* error_message);
bool tscl_assume_not_empty_array(const void* array, size_t size, const char* error_message);
bool tscl_assume_not_dangling(const void* ptr, size_t size, const char* error_message);
bool tscl_assume_not_freed(const void* ptr, const char* error_message);
bool tscl_assume_within_range(int value, int min, int max, const char* error_message);
bool tscl_assume_valid_enum(int value, int min_enum, int max_enum, const char* error_message);
bool tscl_assume_false(bool condition, const char* error_message);
bool tscl_assume_null(const void* pointer, const char* error_message);
bool tscl_assume_strings_equal(const char* str1, const char* str2, const char* error_message);
bool tscl_assume_strings_not_equal(const char* str1, const char* str2, const char* error_message);
bool tscl_assume_whitespace(char c, const char* error_message);
bool tscl_assume_within_memory_region(const void* ptr, const void* start, size_t size, const char* error_message);
bool tscl_assume_valid_c_string(const char* str, const char* error_message);
bool tscl_assume_file_not_at_end(FILE* file, const char* error_message);
bool tscl_assume_power_of_two(size_t value, const char* error_message);
bool tscl_assume_ascii_char(char c, const char* error_message);
bool tscl_assume_writable_memory(const void* ptr, size_t size, const char* error_message);
bool tscl_assume_not_zero(int value, const char* error_message);
bool tscl_assume_even(int value, const char* error_message);
bool tscl_assume_odd(int value, const char* error_message);
bool tscl_assume_file_at_beginning(FILE* file, const char* error_message);
bool tscl_assume_string_length_less_than(const char* str, size_t max_length, const char* error_message);
bool tscl_assume_writable_memory(const void* ptr, size_t size, const char* error_message);
bool tscl_assume_positive_power_of_two(size_t value, const char* error_message);
bool tscl_assume_string_length_greater_than(const char* str, size_t min_length, const char* error_message);
bool tscl_assume_valid_ascii_string(const char* str, const char* error_message);
bool tscl_assume_string_length_within_range(const char* str, size_t min_length, size_t max_length, const char* error_message);
bool tscl_assume_writable_memory(const void* ptr, size_t size, const char* error_message);

#ifdef __cplusplus
}
#endif

#endif
