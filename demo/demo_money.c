/*  ----------------------------------------------------------------------------
    File: demo_money.c

    Description:
    This demo file serves as a showcase of the Trilobite Stdlib in action. It provides
    example code snippets and usage scenarios to help users understand how to leverage
    the library's features and functions in their own projects.

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
#include "trilobite/xutil/money.h" // lib source code
#include <stdio.h>

int main() {
    // Example usage
    cmoney money1 = money_create(10, 50, USD);
    cmoney money2 = money_create(5, 75, USD);
    cmoney money3 = money_create(3, 25, GBP);

    // Add money values only if the country codes match
    cmoney sum1 = money_add(money1, money2);
    cmoney sum2 = money_add(money1, money3);

    printf("Money 1: ");
    money_display(money1);

    printf("Money 2: ");
    money_display(money2);

    printf("Sum 1: ");
    money_display(sum1);

    printf("Money 3: ");
    money_display(money3);

    printf("Sum 2: ");
    money_display(sum2);

    // Convert money to a different currency (USD to GBP)
    cmoney converted_money = money_convert(money1, GBP);

    printf("Converted Money: ");
    money_display(converted_money);

    // Check if money objects are valid
    printf("Is Money 1 valid? %s\n", money_is_valid(money1) ? "Yes" : "No");

    // Compare money objects
    int comparison_result = money_compare(money1, money2);
    printf("Comparison Result: %s\n", (comparison_result == 0) ? "Equal" : ((comparison_result == 1) ? "Money 1 > Money 2" : "Money 1 < Money 2"));

    // Subtract money values only if the country codes match
    cmoney difference = money_subtract(money1, money2);
    printf("Difference (Money 1 - Money 2): ");
    money_display(difference);

    return 0;
} // end of func
