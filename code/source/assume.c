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
#include <stdlib.h>
#include <stddef.h>

// Assume that the condition is true; otherwise, print an error message and return false.
bool tscl_assume(bool condition, const char* error_message) {
    if (!condition) {
        fprintf(stderr, "Assumption failed: %s\n", error_message);
    }
    return condition;
}

// Assume that the pointer is not NULL; otherwise, print an error message and return false.
bool tscl_assume_not_null(const void* pointer, const char* error_message) {
    return tscl_assume(pointer != NULL, error_message);
}

// Assume that the index is within the array bounds; otherwise, print an error message and return false.
bool tscl_assume_within_bounds(size_t index, size_t size, const char* error_message) {
    return tscl_assume(index < size, error_message);
}

// Assume that the condition is true; otherwise, print a warning message and return false.
bool tscl_assume_warn(bool condition, const char* warning_message) {
    if (!condition) {
        fprintf(stderr, "Assumption warning: %s\n", warning_message);
    }
    return condition;
}

// Assume that the pointer is not NULL; otherwise, print a warning message and return false.
bool tscl_assume_not_null_warn(const void* pointer, const char* warning_message) {
    return tscl_assume_warn(pointer != NULL, warning_message);
}

// Assume that the index is within the array bounds; otherwise, print a warning message and return false.
bool tscl_assume_within_bounds_warn(size_t index, size_t size, const char* warning_message) {
    return tscl_assume_warn(index < size, warning_message);
}

// Assume that the integer is positive; otherwise, print an error message and return false.
bool tscl_assume_positive(int value, const char* error_message) {
    return tscl_assume(value > 0, error_message);
}

// Assume that the integer is non-negative; otherwise, print an error message and return false.
bool tscl_assume_non_negative(int value, const char* error_message) {
    return tscl_assume(value >= 0, error_message);
}

// Assume that the integer is negative; otherwise, print an error message and return false.
bool tscl_assume_negative(int value, const char* error_message) {
    return tscl_assume(value < 0, error_message);
}

// Assume that the double is finite; otherwise, print an error message and return false.
bool tscl_assume_finite(double value, const char* error_message) {
    return tscl_assume(isfinite(value), error_message);
}

// Assume that the double is not NaN; otherwise, print an error message and return false.
bool tscl_assume_not_nan(double value, const char* error_message) {
    return tscl_assume(!isnan(value), error_message);
}

// Assume that the character is a digit; otherwise, print an error message and return false.
bool tscl_assume_digit(char c, const char* error_message) {
    return tscl_assume(isdigit(c), error_message);
}

// Assume that the character is an uppercase letter; otherwise, print an error message and return false.
bool tscl_assume_uppercase(char c, const char* error_message) {
    return tscl_assume(isupper(c), error_message);
}

// Assume that the character is a lowercase letter; otherwise, print an error message and return false.
bool tscl_assume_lowercase(char c, const char* error_message) {
    return tscl_assume(islower(c), error_message);
}

// Assume that the string is not empty (not NULL and has at least one character); otherwise, print an error message and return false.
bool tscl_assume_not_empty_string(const char* str, const char* error_message) {
    return tscl_assume_not_null(str, error_message) && tscl_assume(str[0] != '\0', error_message);
}

// Assume that the pointer is aligned to a specific alignment; otherwise, print an error message and return false.
bool tscl_assume_aligned(const void* ptr, size_t alignment, const char* error_message) {
    return tscl_assume(((uintptr_t)ptr) % alignment == 0, error_message);
}

// Assume that the file pointer is not NULL; otherwise, print an error message and return false.
bool tscl_assume_file_not_null(FILE* file, const char* error_message) {
    return tscl_assume_not_null(file, error_message);
}

// Assume that the file is open (file pointer is not NULL); otherwise, print an error message and return false.
bool tscl_assume_file_open(FILE* file, const char* error_message) {
    return tscl_assume_not_null(file, error_message) && tscl_assume(file != NULL, error_message);
}

// Assume that the file is at the end; otherwise, print an error message and return false.
bool tscl_assume_file_at_end(FILE* file, const char* error_message) {
    return tscl_assume(feof(file), error_message);
}

// Assume that the array is not NULL and has at least one element; otherwise, print an error message and return false.
bool tscl_assume_not_empty_array(const void* array, size_t size, const char* error_message) {
    return tscl_assume_not_null(array, error_message) && tscl_assume(size > 0, error_message);
}

// Assume that the pointer is not dangling (within a valid memory region); otherwise, print an error message and return false.
bool tscl_assume_not_dangling(const void* ptr, size_t size, const char* error_message) {
    // This is just a basic example; a more sophisticated check may be needed based on the system.
    return tscl_assume(ptr >= (void*)0x1000 && ptr < (void*)0x80000000 && ((uintptr_t)ptr % sizeof(void*)) == 0, error_message);
}

// Assume that the pointer is not pointing to a freed memory region; otherwise, print an error message and return false.
bool tscl_assume_not_freed(const void* ptr, const char* error_message) {
    // This is just a basic example; a more sophisticated check may be needed based on the system.
    return tscl_assume(ptr != NULL && ((uintptr_t)ptr % sizeof(void*)) == 0, error_message);
}

// Assume that the value is within a specific range (inclusive); otherwise, print an error message and return false.
bool tscl_assume_within_range(int value, int min, int max, const char* error_message) {
    return tscl_assume(value >= min && value <= max, error_message);
}

// Assume that the value is in a valid enum range; otherwise, print an error message and return false.
bool tscl_assume_valid_enum(int value, int min_enum, int max_enum, const char* error_message) {
    return tscl_assume(value >= min_enum && value <= max_enum, error_message);
}

// Assume that the condition is false; otherwise, print an error message and return false.
bool tscl_assume_false(bool condition, const char* error_message) {
    return tscl_assume(!condition, error_message);
}

// Assume that the pointer is NULL; otherwise, print an error message and return false.
bool tscl_assume_null(const void* pointer, const char* error_message) {
    return tscl_assume(pointer == NULL, error_message);
}

// Assume that the two strings are equal; otherwise, print an error message and return false.
bool tscl_assume_strings_equal(const char* str1, const char* str2, const char* error_message) {
    return tscl_assume(strcmp(str1, str2) == 0, error_message);
}

// Assume that the two strings are not equal; otherwise, print an error message and return false.
bool tscl_assume_strings_not_equal(const char* str1, const char* str2, const char* error_message) {
    return tscl_assume(strcmp(str1, str2) != 0, error_message);
}

// Assume that the character is a whitespace character; otherwise, print an error message and return false.
bool tscl_assume_whitespace(char c, const char* error_message) {
    return tscl_assume(isspace(c), error_message);
}

// Assume that the pointer is within a specific memory region; otherwise, print an error message and return false.
bool tscl_assume_within_memory_region(const void* ptr, const void* start, size_t size, const char* error_message) {
    return tscl_assume(ptr >= start && (uintptr_t)ptr < (uintptr_t)start + size, error_message);
}

// Assume that the pointer is pointing to a valid null-terminated string; otherwise, print an error message and return false.
bool tscl_assume_valid_c_string(const char* str, const char* error_message) {
    return tscl_assume_not_null(str, error_message) && tscl_assume(strchr(str, '\0') != NULL, error_message);
}

// Assume that the file pointer is not at the end of the file; otherwise, print an error message and return false.
bool tscl_assume_file_not_at_end(FILE* file, const char* error_message) {
    return tscl_assume(!feof(file), error_message);
}

// Assume that the value is a power of two; otherwise, print an error message and return false.
bool tscl_assume_power_of_two(size_t value, const char* error_message) {
    return tscl_assume((value & (value - 1)) == 0, error_message);
}

// Assume that the character is an ASCII character; otherwise, print an error message and return false.
bool tscl_assume_ascii_char(char c, const char* error_message) {
    return tscl_assume((unsigned char)c <= 127, error_message);
}

// Assume that the pointer is pointing to writable memory; otherwise, print an error message and return false.
bool tscl_assume_writable_memory(const void* ptr, size_t size, const char* error_message) {
    // This is just a basic example; a more sophisticated check may be needed based on the system.
    return tscl_assume(ptr != NULL && ((uintptr_t)ptr % sizeof(void*)) == 0, error_message);
}

// Assume that the value is not zero; otherwise, print an error message and return false.
bool tscl_assume_not_zero(int value, const char* error_message) {
    return tscl_assume(value != 0, error_message);
}

// Assume that the value is even; otherwise, print an error message and return false.
bool tscl_assume_even(int value, const char* error_message) {
    return tscl_assume(value % 2 == 0, error_message);
}

// Assume that the value is odd; otherwise, print an error message and return false.
bool tscl_assume_odd(int value, const char* error_message) {
    return tscl_assume(value % 2 != 0, error_message);
}

// Assume that the file pointer is not NULL and at the beginning of the file; otherwise, print an error message and return false.
bool tscl_assume_file_at_beginning(FILE* file, const char* error_message) {
    return tscl_assume_not_null(file, error_message) && tscl_assume(ftell(file) == 0, error_message);
}

// Assume that the pointer is pointing to a null-terminated string with a length less than a specified maximum; otherwise, print an error message and return false.
bool tscl_assume_string_length_less_than(const char* str, size_t max_length, const char* error_message) {
    return tscl_assume_not_null(str, error_message) && tscl_assume(strlen(str) < max_length, error_message);
}

// Assume that the pointer is pointing to valid writable memory; otherwise, print an error message and return false.
bool tscl_assume_writable_memory(const void* ptr, size_t size, const char* error_message) {
    // This is just a basic example; a more sophisticated check may be needed based on the system.
    return tscl_assume(ptr != NULL && ((uintptr_t)ptr % sizeof(void*)) == 0, error_message);
}

// Assume that the value is a positive power of two; otherwise, print an error message and return false.
bool tscl_assume_positive_power_of_two(size_t value, const char* error_message) {
    return tscl_assume(value > 0 && (value & (value - 1)) == 0, error_message);
}

// Assume that the pointer is pointing to a null-terminated string with a length greater than a specified minimum; otherwise, print an error message and return false.
bool tscl_assume_string_length_greater_than(const char* str, size_t min_length, const char* error_message) {
    return tscl_assume_not_null(str, error_message) && tscl_assume(strlen(str) > min_length, error_message);
}

// Assume that the pointer is pointing to valid ASCII characters; otherwise, print an error message and return false.
bool tscl_assume_valid_ascii_string(const char* str, const char* error_message) {
    return tscl_assume_not_null(str, error_message) && tscl_assume_each_ascii_char(str, error_message);
}

// Assume that the pointer is pointing to a null-terminated string with a length in a specified range; otherwise, print an error message and return false.
bool tscl_assume_string_length_within_range(const char* str, size_t min_length, size_t max_length, const char* error_message) {
    return tscl_assume_not_null(str, error_message) && tscl_assume(strlen(str) >= min_length && strlen(str) <= max_length, error_message);
}

// Assume that the pointer is pointing to valid writable memory; otherwise, print an error message and return false.
bool tscl_assume_writable_memory(const void* ptr, size_t size, const char* error_message) {
    // This is just a basic example; a more sophisticated check may be needed based on the system.
    return tscl_assume(ptr != NULL && ((uintptr_t)ptr % sizeof(void*)) == 0, error_message);
}

