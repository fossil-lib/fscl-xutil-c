/*  ----------------------------------------------------------------------------
    File: demo_number.c

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
#include "trilobite/xutil/number.h" // lib source code
#include <stdio.h> // using the printf functions
#include <stdlib.h>

int main() {
    puts("Trilobite Math Calculator");

    cnumber num1, num2, result;
    char operation;

    // Input first number
    printf("Enter the first number (integer or English word): ");
    scanf("%s", num1.data.wordValue);
    num1.type = isalpha(num1.data.wordValue[0]) ? 1 : 0;

    // Input operation
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Input second number
    printf("Enter the second number (integer or English word): ");
    scanf("%s", num2.data.wordValue);
    num2.type = isalpha(num2.data.wordValue[0]) ? 1 : 0;

    // Perform the requested operation
    switch (operation) {
        case '+':
            result = number_add(num1, num2);
            break;
        case '-':
            result = number_subtract(num1, num2);
            break;
        case '*':
            result = number_multiply(num1, num2);
            break;
        case '/':
            result = number_divide(num1, num2);
            break;
        default:
            fprintf(stderr, "Error: Invalid operation.\n");
            return EXIT_FAILURE;
    }

    // Display the result
    printf("Result: ");
    number_print(result);

    return 0;
} // end of func
