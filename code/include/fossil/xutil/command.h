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
#ifndef FSCL_COMMAND_H
#define FSCL_COMMAND_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>

// Define a typedef for char* to make the code more readable
typedef char* ccommand;

// =================================================================
// Avalable functions
// =================================================================
int fscl_command(ccommand process);
int fscl_command_success(ccommand process);
int fscl_command_output(ccommand process, char *output, size_t output_size);
int fscl_command_exists(ccommand process);
int fscl_command_erase_exists(ccommand path);
void fscl_command_strcat_safe(char *dest, const char *src, size_t dest_size);

#ifdef __cplusplus
}
#endif

#endif
