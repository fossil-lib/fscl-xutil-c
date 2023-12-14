/*  ----------------------------------------------------------------------------
    File: number.c

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
#include "trilobite/xutil/number.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int value;
    char word[20]; // Assuming a maximum word length of 20 characters
} PlaceValue;

typedef struct {
    int number;
    char word[20]; // Assuming a maximum word length of 20 characters
} EnglishWord;

PlaceValue placeValues[] = {
    {1, "one"},
    {10, "ten"},
    {100, "hundred"},
    {1000, "thousand"},
    {1000000, "million"},
    {1000000000, "billion"}
};

EnglishWord englishWords[] = {
    {0, "zero"},
    {1, "one"},
    {2, "two"},
    {3, "three"},
    {4, "four"},
    {5, "five"},
    {6, "six"},
    {7, "seven"},
    {8, "eight"},
    {9, "nine"},
    {10, "ten"},
    {11, "eleven"},
    {12, "twelve"},
    {13, "thirteen"},
    {14, "fourteen"},
    {15, "fifteen"},
    {16, "sixteen"},
    {17, "seventeen"},
    {18, "eighteen"},
    {19, "nineteen"},
    {20, "twenty"},
    {30, "thirty"},
    {40, "forty"},
    {50, "fifty"},
    {60, "sixty"},
    {70, "seventy"},
    {80, "eighty"},
    {90, "ninety"}
};

cnumber number_create_from_int(int value) {
    return (cnumber){.type = 0, .data.intValue = value};
} // end of func

cnumber number_create_from_word(const char* word) {
    cnumber number;
    number.type = 1;
    strncpy(number.data.wordValue, word, sizeof(number.data.wordValue) - 1);
    number.data.wordValue[sizeof(number.data.wordValue) - 1] = '\0'; // Ensure null-termination
    return number;
} // end of func

int number_equal(const cnumber a, const cnumber b) {
    if (a.type == b.type) {
        if (a.type == 0) {
            return a.data.intValue == b.data.intValue;
        } else {
            return strcmp(a.data.wordValue, b.data.wordValue) == 0;
        }
    }
    return 0;
} // end of func

cnumber number_negate(const cnumber number) {
    if (number.type == 0) {
        return number_create_from_int(-number.data.intValue);
    } else {
        fprintf(stderr, "Error: Negation is supported only for integer values.\n");
        exit(EXIT_FAILURE);
    }
} // end of func

cnumber number_abs(const cnumber number) {
    if (number.type == 0) {
        return number_create_from_int(abs(number.data.intValue));
    } else {
        fprintf(stderr, "Error: Absolute value is supported only for integer values.\n");
        exit(EXIT_FAILURE);
    }
} // end of func

cnumber number_add(cnumber a, cnumber b) {
    if (a.type == 0 && b.type == 0) {
        return number_create_from_int(a.data.intValue + b.data.intValue);
    }
    fprintf(stderr, "Error: Addition is supported only for integer values.\n");
    exit(EXIT_FAILURE);
} // end of func

cnumber number_subtract(cnumber a, cnumber b) {
    if (a.type == 0 && b.type == 0) {
        return number_create_from_int(a.data.intValue - b.data.intValue);
    }
    fprintf(stderr, "Error: Subtraction is supported only for integer values.\n");
    exit(EXIT_FAILURE);
} // end of func

cnumber number_multiply(cnumber a, cnumber b) {
    if (a.type == 0 && b.type == 0) {
        return number_create_from_int(a.data.intValue * b.data.intValue);
    }
    fprintf(stderr, "Error: Multiplication is supported only for integer values.\n");
    exit(EXIT_FAILURE);
} // end of func

cnumber number_divide(cnumber a, cnumber b) {
    if (a.type == 0 && b.type == 0) {
        if (b.data.intValue != 0) {
            return number_create_from_int(a.data.intValue / b.data.intValue);
        } else {
            fprintf(stderr, "Error: Division by zero.\n");
            exit(EXIT_FAILURE);
        }
    }
    fprintf(stderr, "Error: Division is supported only for integer values.\n");
    exit(EXIT_FAILURE);
} // end of func

cnumber number_operation(cnumber a, cnumber b, int operation) {
    if (a.type == 0 && b.type == 0) {
        switch (operation) {
            case 0: // Addition
                return number_create_from_int(a.data.intValue + b.data.intValue);
            case 1: // Subtraction
                return number_create_from_int(a.data.intValue - b.data.intValue);
            case 2: // Multiplication
                return number_create_from_int(a.data.intValue * b.data.intValue);
            case 3: // Division
                if (b.data.intValue != 0) {
                    return number_create_from_int(a.data.intValue / b.data.intValue);
                } else {
                    fprintf(stderr, "Error: Division by zero.\n");
                    exit(EXIT_FAILURE);
                }
            default:
                fprintf(stderr, "Error: Unknown operation.\n");
                exit(EXIT_FAILURE);
        }
    } else {
        fprintf(stderr, "Error: Operation supported only for integer values.\n");
        exit(EXIT_FAILURE);
    }
} // end of func

void number_print(const cnumber number) {
    if (number.type == 0) {
        printf("%d\n", number.data.intValue);
    } else {
        printf("%s\n", number.data.wordValue);
    }
} // end of func

cnumber number_modulus(cnumber a, cnumber b) {
    if (a.type == 0 && b.type == 0) {
        if (b.data.intValue != 0) {
            return number_create_from_int(a.data.intValue % b.data.intValue);
        } else {
            fprintf(stderr, "Error: Modulus by zero.\n");
            exit(EXIT_FAILURE);
        }
    } else {
        fprintf(stderr, "Error: Modulus is supported only for integer values.\n");
        exit(EXIT_FAILURE);
    }
} // end of func

int number_greater_than(cnumber a, cnumber b) {
    if (a.type == 0 && b.type == 0) {
        return a.data.intValue > b.data.intValue;
    } else {
        fprintf(stderr, "Error: Greater-than comparison is supported only for integer values.\n");
        exit(EXIT_FAILURE);
    }
} // end of func

int number_less_than(cnumber a, cnumber b) {
    if (a.type == 0 && b.type == 0) {
        return a.data.intValue < b.data.intValue;
    } else {
        fprintf(stderr, "Error: Less-than comparison is supported only for integer values.\n");
        exit(EXIT_FAILURE);
    }
} // end of func

cnumber number_increment(cnumber num) {
    if (num.type == 0) {
        return number_create_from_int(num.data.intValue + 1);
    } else {
        fprintf(stderr, "Error: Increment is supported only for integer values.\n");
        exit(EXIT_FAILURE);
    }
} // end of func

cnumber number_decrement(cnumber num) {
    if (num.type == 0) {
        return number_create_from_int(num.data.intValue - 1);
    } else {
        fprintf(stderr, "Error: Decrement is supported only for integer values.\n");
        exit(EXIT_FAILURE);
    }
} // end of func

cnumber number_absolute_value(cnumber num) {
    if (num.type == 0) {
        return number_create_from_int(abs(num.data.intValue));
    } else {
        fprintf(stderr, "Error: Absolute value is supported only for integer values.\n");
        exit(EXIT_FAILURE);
    }
} // end of func

int number_is_integer(cnumber number) {
    return number.type == 0;
} // end of func

int number_is_word(cnumber number) {
    return number.type == 1;
} // end of func

int number_get_integer(cnumber number) {
    if (number_is_integer(number)) {
        return number.data.intValue;
    } else {
        // Return a default value if it's not an integer
        return 0;
    }
} // end of func
