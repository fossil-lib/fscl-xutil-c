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

// =================================================================
// Avalable functions
// =================================================================
cmoney tscl_money_create(dollars_type dollars, cents_type cents, Currency currency);
cmoney tscl_money_add(cmoney m1, cmoney m2);
cmoney tscl_money_convert(cmoney source, Currency target_currency);
void tscl_money_display(cmoney m);
int tscl_money_is_valid(cmoney m);
int tscl_money_compare(cmoney m1, cmoney m2);
cmoney tscl_money_subtract(cmoney m1, cmoney m2);
cmoney tscl_money_multiply_scalar(cmoney m, int scalar);
cmoney tscl_money_divide_scalar(cmoney m, int divisor);
cmoney tscl_money_round(cmoney m);
int tscl_money_is_positive(cmoney m);
int tscl_money_is_negative(cmoney m);
int tscl_money_is_zero(cmoney m);

#ifdef __cplusplus
}
#endif

#endif
