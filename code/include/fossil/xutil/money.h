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
cmoney fscl_money_create(dollars_type dollars, cents_type cents, Currency currency);
cmoney fscl_money_add(cmoney m1, cmoney m2);
cmoney fscl_money_convert(cmoney source, Currency target_currency);
void fscl_money_display(cmoney m);
int fscl_money_is_valid(cmoney m);
int fscl_money_compare(cmoney m1, cmoney m2);
cmoney fscl_money_subtract(cmoney m1, cmoney m2);
cmoney fscl_money_multiply_scalar(cmoney m, int scalar);
cmoney fscl_money_divide_scalar(cmoney m, int divisor);
cmoney fscl_money_round(cmoney m);
int fscl_money_is_positive(cmoney m);
int fscl_money_is_negative(cmoney m);
int fscl_money_is_zero(cmoney m);

#ifdef __cplusplus
}
#endif

#endif
