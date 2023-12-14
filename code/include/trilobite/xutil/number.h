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
#ifndef TRILOBITE_XTYPE_NUMBER_H
#define TRILOBITE_XTYPE_NUMBER_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct {
    int type;  // 0 for integer, 1 for English words
    union {
        int intValue;
        char wordValue[20]; // Assuming a maximum word length of 20 characters
    } data;
} cnumber;

/**
 * @brief Converts an integer value to a cnumber.
 *
 * @param value The integer value to convert.
 * @return A cnumber representing the integer value.
 */
cnumber number_create_from_int(int value);

/**
 * @brief Converts an English word to a cnumber.
 *
 * @param word The English word to convert.
 * @return A cnumber representing the English word.
 */
cnumber number_create_from_word(const char* word);

/**
 * @brief Checks if two cnumbers are equal.
 *
 * @param a The first cnumber.
 * @param b The second cnumber.
 * @return 1 if equal, 0 otherwise.
 */
int number_equal(cnumber a, cnumber b);

/**
 * @brief Negates a cnumber.
 *
 * @param number The cnumber to negate.
 * @return The negated cnumber.
 */
cnumber number_negate(cnumber number);

/**
 * @brief Calculates the absolute value of a cnumber.
 *
 * @param number The cnumber for which to find the absolute value.
 * @return The absolute value of the cnumber.
 */
cnumber number_abs(cnumber number);

/**
 * @brief Adds two cnumbers.
 *
 * @param a The first cnumber.
 * @param b The second cnumber.
 * @return The sum of the two cnumbers.
 */
cnumber number_add(cnumber a, cnumber b);

/**
 * @brief Subtracts one cnumber from another.
 *
 * @param a The cnumber to subtract from.
 * @param b The cnumber to subtract.
 * @return The result of subtracting b from a.
 */
cnumber number_subtract(cnumber a, cnumber b);

/**
 * @brief Multiplies two cnumbers.
 *
 * @param a The first cnumber.
 * @param b The second cnumber.
 * @return The product of the two cnumbers.
 */
cnumber number_multiply(cnumber a, cnumber b);

/**
 * @brief Divides one cnumber by another.
 *
 * @param a The cnumber to be divided.
 * @param b The cnumber to divide by.
 * @return The result of dividing a by b.
 */
cnumber number_divide(cnumber a, cnumber b);

/**
 * @brief Prints the value of a cnumber to the standard output.
 *
 * @param number The cnumber to print.
 */
void number_print(cnumber number);

/**
 * @brief Perform modulus operation on two cnumber values.
 *
 * @param a The first cnumber.
 * @param b The second cnumber.
 * @return The result of the modulus operation.
 */
cnumber number_modulus(cnumber a, cnumber b);

/**
 * @brief Check if the first cnumber is greater than the second.
 *
 * @param a The first cnumber.
 * @param b The second cnumber.
 * @return 1 if a > b, 0 otherwise.
 */
int number_greater_than(cnumber a, cnumber b);

/**
 * @brief Check if the first cnumber is less than the second.
 *
 * @param a The first cnumber.
 * @param b The second cnumber.
 * @return 1 if a < b, 0 otherwise.
 */
int number_less_than(cnumber a, cnumber b);

/**
 * @brief Increment the value of a cnumber.
 *
 * @param num The cnumber to increment.
 * @return The result of the increment operation.
 */
cnumber number_increment(cnumber num);

/**
 * @brief Decrement the value of a cnumber.
 *
 * @param num The cnumber to decrement.
 * @return The result of the decrement operation.
 */
cnumber number_decrement(cnumber num);

/**
 * @brief Calculate the absolute value of a cnumber.
 *
 * @param num The cnumber.
 * @return The absolute value of the cnumber.
 */
cnumber number_absolute_value(cnumber num);

/**
 * @brief Checks if a cnumber represents an integer value.
 *
 * @param number The cnumber to check.
 * @return 1 if the cnumber represents an integer, 0 otherwise.
 */
int number_is_integer(cnumber number);

/**
 * @brief Checks if a cnumber represents an English word.
 *
 * @param number The cnumber to check.
 * @return 1 if the cnumber represents an English word, 0 otherwise.
 */
int number_is_word(cnumber number);

/**
 * @brief Retrieves the integer value from a cnumber.
 *
 * @param number The cnumber to extract the integer value from.
 * @return The integer value.
 *
 * @note It is recommended to check if the cnumber represents an integer before calling this function.
 */
int number_get_integer(cnumber number);

#ifdef __cplusplus
}
#endif

#endif
