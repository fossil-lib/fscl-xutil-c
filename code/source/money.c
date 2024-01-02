/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include "fossil/xutil/money.h"
#include <stdio.h>
#include <math.h>

// Function to create a money object
cmoney fscl_money_create(dollars_type dollars, cents_type cents, Currency currency) {
    cmoney result;
    result.dollars = dollars;
    result.cents = cents;
    result.currency = currency;
    return result;
} // end of func

// Function to add two money objects if they have the same currency
cmoney fscl_money_add(cmoney m1, cmoney m2) {
    cmoney result;

    // Check if the currencies match
    if (m1.currency == m2.currency) {
        result.dollars = m1.dollars + m2.dollars;
        result.cents = m1.cents + m2.cents;

        // Adjust cents if it exceeds 100
        if (result.cents >= 100) {
            result.dollars += result.cents / 100;
            result.cents %= 100;
        }

        result.currency = m1.currency; // Use the currency of the first money object
    } else {
        // Currencies do not match, return a result with an unknown currency
        result.dollars = 0;
        result.cents = 0;
        result.currency = -1; // Representing an unknown currency
    }

    return result;
} // end of func

// Function to convert money to a different currency
cmoney fscl_money_convert(cmoney source, Currency target_currency) {
    // Assume a simple conversion rate of 1:1 for demonstration purposes
    cmoney result;
    result.dollars = source.dollars;
    result.cents = source.cents;
    result.currency = target_currency;

    return result;
} // end of func

// Function to display a money object
void fscl_money_display(cmoney m) {
    const char* currency_symbol;

    switch (m.currency) {
        case USD:
            currency_symbol = "$";
            break;
        case CAD:
            currency_symbol = "CA$";
            break;
        case GBP:
            currency_symbol = "£";
            break;
        case RUB:
            currency_symbol = "₽";
            break;
        case INR:
            currency_symbol = "₹";
            break;
        case JPY:
            currency_symbol = "¥";
            break;
        default:
            currency_symbol = "?";
    }

    printf("%s%d.%02d\n", currency_symbol, m.dollars, m.cents);
} // end of func

int fscl_money_is_valid(cmoney m) {
    return (m.cents >= 0 && m.cents <= 99);
} // end of func

int fscl_money_compare(cmoney m1, cmoney m2) {
    if (m1.currency == m2.currency) {
        if (m1.dollars == m2.dollars && m1.cents == m2.cents) {
            return 0; // Equal
        } else if (m1.dollars > m2.dollars || (m1.dollars == m2.dollars && m1.cents > m2.cents)) {
            return 1; // m1 is greater
        } else {
            return -1; // m2 is greater
        }
    } else {
        // Currencies do not match
        return -2; // Indicate an error or undefined comparison
    }
} // end of func

cmoney fscl_money_subtract(cmoney m1, cmoney m2) {
    cmoney result;
    
    // Check if the currencies match
    if (m1.currency == m2.currency) {
        result.dollars = m1.dollars - m2.dollars;
        result.cents = m1.cents - m2.cents;

        // Adjust if cents are negative
        if (result.cents < 0) {
            result.dollars -= 1;
            result.cents += 100;
        }

        result.currency = m1.currency; // Use the currency of the first money object
    } else {
        // Currencies do not match, return a result with an unknown currency
        result.dollars = 0;
        result.cents = 0;
        result.currency = -1; // Representing an unknown currency
    }

    return result;
} // end of func

// Function to multiply a cmoney object by a scalar value
cmoney fscl_money_multiply_scalar(cmoney m, int scalar) {
    cmoney result = m;
    result.dollars *= scalar;
    result.cents *= scalar;
    
    // Adjust cents to stay within the valid range (0 to 99)
    result.dollars += result.cents / 100;
    result.cents %= 100;

    return result;
} // end of func

// Function to divide a cmoney object by a scalar value
cmoney fscl_money_divide_scalar(cmoney m, int divisor) {
    if (divisor == 0) {
        // Division by zero, return original cmoney object
        return m;
    }

    cmoney result = m;
    result.dollars /= divisor;
    result.cents /= divisor;

    return result;
} // end of func

// Function to round the amount in a cmoney object to the nearest integer
cmoney fscl_money_round(cmoney m) {
    cmoney result = m;

    // Round the amount to the nearest integer
    result.cents = round((double)result.cents / 100.0 * 100.0);

    // Adjust dollars for any overflow from rounding cents
    result.dollars += result.cents / 100;
    result.cents %= 100;

    return result;
} // end of func

// Function to check if a cmoney object represents a positive amount
int fscl_money_is_positive(cmoney m) {
    return (m.dollars > 0) || (m.dollars == 0 && m.cents > 0);
} // end of func

// Function to check if a cmoney object represents a negative amount
int fscl_money_is_negative(cmoney m) {
    return (m.dollars < 0) || (m.dollars == 0 && m.cents < 0);
} // end of func

// Function to check if a cmoney object represents zero amount
int fscl_money_is_zero(cmoney m) {
    return (m.dollars == 0) && (m.cents == 0);
} // end of func
