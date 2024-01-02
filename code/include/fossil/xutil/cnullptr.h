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
#ifndef FSCL_CNULLPTR_H
#define FSCL_CNULLPTR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>

// Define a custom null pointer constant
#define cnullptr ((void*)0)

/**
int main() {
    // Using cnullptr
    int *ptr = cnullptr;

    // Check if the pointer is null
    if (ptr == cnullptr) {
        // Handle null pointer case
    }

    return 0;
}
*/

#ifdef __cplusplus
}
#endif

#endif
