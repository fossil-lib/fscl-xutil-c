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
#ifndef TRILOBITE_XTYPE_MONEY_H
#define TRILOBITE_XTYPE_MONEY_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef int dollars_type;
typedef int cents_type;

// Enum to represent different currency types
typedef enum {
    USD,
    CAD,
    GBP,
    RUB,
    INR,
    JPY
} Currency;

// Structure to represent money
typedef struct {
    dollars_type dollars;
    cents_type cents;
    Currency currency;
} cmoney;

/**
 * @brief Initializes a cmoney object with the provided values.
 *
 * @param dollars The amount in dollars.
 * @param cents   The amount in cents (0 to 99).
 * @param currency The currency of the money object (e.g., USD, CAD, GBP).
 *
 * @return A cmoney object initialized with the provided values.
 */
cmoney money_create(dollars_type dollars, cents_type cents, Currency currency);

/**
 * @brief Adds two cmoney objects if they have the same currency.
 *
 * @param m1 The first cmoney object.
 * @param m2 The second cmoney object.
 *
 * @return The sum of the two cmoney objects, or a cmoney object with unknown currency if currencies don't match.
 */
cmoney money_add(cmoney m1, cmoney m2);

/**
 * @brief Converts a cmoney object to a different currency.
 *
 * @param source         The source cmoney object.
 * @param target_currency The target currency to convert to.
 *
 * @return The converted cmoney object.
 */
cmoney money_convert(cmoney source, Currency target_currency);

/**
 * @brief Displays the details of a cmoney object.
 *
 * @param m The cmoney object to be displayed.
 */
void money_display(cmoney m);

/**
 * @brief Checks if a cmoney object is valid (cents within the range 0 to 99).
 *
 * @param m The cmoney object to be validated.
 *
 * @return 1 if the cmoney object is valid, 0 otherwise.
 */
int money_is_valid(cmoney m);

/**
 * @brief Compares two cmoney objects.
 *
 * @param m1 The first cmoney object.
 * @param m2 The second cmoney object.
 *
 * @return  0 if the cmoney objects are equal,
 *          1 if m1 is greater than m2,
 *         -1 if m1 is less than m2,
 *         -2 if the currencies are different.
 */
int money_compare(cmoney m1, cmoney m2);

/**
 * @brief Subtracts one cmoney object from another if they have the same currency.
 *
 * @param m1 The cmoney object to subtract from.
 * @param m2 The cmoney object to subtract.
 *
 * @return The result of subtracting m2 from m1, or a cmoney object with unknown currency if currencies don't match.
 */
cmoney money_subtract(cmoney m1, cmoney m2);

/**
 * @brief Multiplies a cmoney object by a scalar value.
 *
 * @param m      The cmoney object to be multiplied.
 * @param scalar The scalar value to multiply by.
 *
 * @return The result of multiplying the cmoney object by the scalar value.
 */
cmoney money_multiply_scalar(cmoney m, int scalar);

/**
 * @brief Divides a cmoney object by a scalar value.
 *
 * @param m      The cmoney object to be divided.
 * @param divisor The scalar value to divide by.
 *
 * @return The result of dividing the cmoney object by the scalar value.
 */
cmoney money_divide_scalar(cmoney m, int divisor);

/**
 * @brief Rounds the amount in a cmoney object to the nearest integer.
 *
 * @param m The cmoney object to be rounded.
 *
 * @return The cmoney object with the amount rounded to the nearest integer.
 */
cmoney money_round(cmoney m);

/**
 * @brief Checks if a cmoney object represents a positive amount.
 *
 * @param m The cmoney object to be checked.
 *
 * @return 1 if the amount is positive, 0 otherwise.
 */
int money_is_positive(cmoney m);

/**
 * @brief Checks if a cmoney object represents a negative amount.
 *
 * @param m The cmoney object to be checked.
 *
 * @return 1 if the amount is negative, 0 otherwise.
 */
int money_is_negative(cmoney m);

/**
 * @brief Checks if a cmoney object represents zero amount.
 *
 * @param m The cmoney object to be checked.
 *
 * @return 1 if the amount is zero, 0 otherwise.
 */
int money_is_zero(cmoney m);

#ifdef __cplusplus
}
#endif

#endif
