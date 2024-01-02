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
#include "fossil/xutil/shuffle.h"
#include "fossil/xutil/lavalamp.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fscl_shuffle_seed(unsigned int seed) {
    fscl_lava_seed(seed);
}

// Function to shuffle an array of integers
void fscl_shuffle_int(int* array, size_t size) {
    for (size_t i = size - 1; i > 0; --i) {
        size_t j = rand() % (i + 1);

        // Swap array[i] and array[j]
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Function to shuffle an array of doubles
void fscl_shuffle_double(double* array, size_t size) {
    for (size_t i = size - 1; i > 0; --i) {
        size_t j = rand() % (i + 1);

        // Swap array[i] and array[j]
        double temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Function to shuffle an array of C strings
void fscl_shuffle_cstring(char** array, size_t size) {
    for (size_t i = size - 1; i > 0; --i) {
        size_t j = rand() % (i + 1);

        // Swap array[i] and array[j]
        char* temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Function to shuffle an array of letters (char)
void fscl_shuffle_letter(char* array, size_t size) {
    for (size_t i = size - 1; i > 0; --i) {
        size_t j = rand() % (i + 1);

        // Swap array[i] and array[j]
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Function to shuffle an array of boolean values
void fscl_shuffle_bool(bool* array, size_t size) {
    for (size_t i = size - 1; i > 0; --i) {
        size_t j = rand() % (i + 1);

        // Swap array[i] and array[j]
        bool temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}