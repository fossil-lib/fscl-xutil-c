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
#ifndef FSCL_MONEY_H
#define FSCL_MONEY_H

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

/**
 * Create a monetary value with the specified dollars, cents, and currency.
 *
 * @param dollars   The amount in dollars.
 * @param cents     The amount in cents.
 * @param currency  The currency of the monetary value.
 * @return          The created monetary value.
 */
cmoney fscl_money_create(dollars_type dollars, cents_type cents, Currency currency);

/**
 * Add two monetary values.
 *
 * @param m1 The first monetary value.
 * @param m2 The second monetary value.
 * @return   The result of adding the two monetary values.
 */
cmoney fscl_money_add(cmoney m1, cmoney m2);

/**
 * Convert a monetary value to a different currency.
 *
 * @param source         The source monetary value.
 * @param target_currency The target currency for conversion.
 * @return               The converted monetary value.
 */
cmoney fscl_money_convert(cmoney source, Currency target_currency);

/**
 * Display the details of a monetary value.
 *
 * @param m The monetary value to display.
 */
void fscl_money_display(cmoney m);

/**
 * Check if a monetary value is valid.
 *
 * @param m The monetary value to check.
 * @return  1 if the monetary value is valid, 0 otherwise.
 */
int fscl_money_is_valid(cmoney m);

/**
 * Compare two monetary values.
 *
 * @param m1 The first monetary value.
 * @param m2 The second monetary value.
 * @return   0 if m1 equals m2, 1 if m1 is greater, -1 if m1 is smaller.
 */
int fscl_money_compare(cmoney m1, cmoney m2);

/**
 * Subtract two monetary values.
 *
 * @param m1 The first monetary value.
 * @param m2 The second monetary value.
 * @return   The result of subtracting the second monetary value from the first.
 */
cmoney fscl_money_subtract(cmoney m1, cmoney m2);

/**
 * Multiply a monetary value by a scalar.
 *
 * @param m      The monetary value.
 * @param scalar The scalar to multiply by.
 * @return       The result of multiplying the monetary value by the scalar.
 */
cmoney fscl_money_multiply_scalar(cmoney m, int scalar);

/**
 * Divide a monetary value by a scalar.
 *
 * @param m       The monetary value.
 * @param divisor The divisor to divide by.
 * @return        The result of dividing the monetary value by the divisor.
 */
cmoney fscl_money_divide_scalar(cmoney m, int divisor);

/**
 * Round a monetary value to the nearest whole cent.
 *
 * @param m The monetary value to round.
 * @return  The rounded monetary value.
 */
cmoney fscl_money_round(cmoney m);

/**
 * Check if a monetary value is positive.
 *
 * @param m The monetary value to check.
 * @return  1 if the monetary value is positive, 0 otherwise.
 */
int fscl_money_is_positive(cmoney m);

/**
 * Check if a monetary value is negative.
 *
 * @param m The monetary value to check.
 * @return  1 if the monetary value is negative, 0 otherwise.
 */
int fscl_money_is_negative(cmoney m);

/**
 * Check if a monetary value is zero.
 *
 * @param m The monetary value to check.
 * @return  1 if the monetary value is zero, 0 otherwise.
 */
int fscl_money_is_zero(cmoney m);

#ifdef __cplusplus
}
#endif

#endif
