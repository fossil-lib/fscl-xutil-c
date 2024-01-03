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
#ifndef FSCL_SHUFFLE_H
#define FSCL_SHUFFLE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>
#include <stdbool.h>

// =================================================================
// Avalable functions
// =================================================================
void fscl_shuffle_seed(unsigned int seed);
void fscl_shuffle_int(int* array, size_t size);
void fscl_shuffle_double(double* array, size_t size);
void fscl_shuffle_cstring(char** array, size_t size);
void fscl_shuffle_letter(char* array, size_t size);
void fscl_shuffle_bool(bool* array, size_t size);

#ifdef __cplusplus
}
#endif

#endif
