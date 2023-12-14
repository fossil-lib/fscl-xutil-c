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
#ifndef TSCL_RANDOM_H
#define TSCL_RANDOM_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Initialize the random seed with a given value.
 *
 * @param seed The seed value to initialize the random number generator.
 */
void random_seed(uint32_t seed);

/**
 * @brief Generate a 32-bit random integer.
 *
 * @return A 32-bit random integer.
 */
uint32_t random_generator(void);

/**
 * @brief Generate a random integer in the specified range [min, max].
 *
 * @param min The minimum value of the range (inclusive).
 * @param max The maximum value of the range (inclusive).
 * @return A random integer in the specified range [min, max].
 */
int random_range(int min, int max);

/**
 * @brief Generate a random floating-point number in the range [0, 1).
 *
 * @return A random floating-point number in the range [0, 1).
 */
double random_lava(void);

/**
 * @brief Shuffle an array of integers using the Fisher-Yates shuffle.
 *
 * @param array The array of integers to be shuffled.
 * @param size The size of the array.
 */
void random_shuffle_int(int *array, size_t size);

/**
 * @brief Shuffle an array of characters.
 *
 * @param array The array of characters to be shuffled.
 * @param size The size of the array.
 */
void random_shuffle_char(char *array, size_t size);

/**
 * @brief Shuffle an array of strings.
 *
 * @param array The array of strings to be shuffled.
 * @param size The size of the array.
 */
void random_shuffle_string(char *array[], size_t size);

/**
 * @brief Generates a random boolean value (true or false).
 *
 * @return A random boolean value.
 */
bool random_bool(void);

/**
 * @brief Generates a random float in the specified range [min, max).
 *
 * @param min The minimum value of the range (inclusive).
 * @param max The maximum value of the range (exclusive).
 * @return A random float in the specified range [min, max).
 */
float random_float_range(float min, float max);

/**
 * @brief Generates a random double in the specified range [min, max).
 *
 * @param min The minimum value of the range (inclusive).
 * @param max The maximum value of the range (exclusive).
 * @return A random double in the specified range [min, max).
 */
double random_double_range(double min, double max);

#ifdef __cplusplus
}
#endif

#endif
