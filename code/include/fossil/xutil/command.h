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

/**
 * Execute a command and return the result.
 *
 * @param process The command to be executed.
 * @return        The result of the command execution.
 */
int fscl_command(ccommand process);

/**
 * Check if a command execution was successful.
 *
 * @param process The command to be checked.
 * @return        1 if the command was successful, 0 otherwise.
 */
int fscl_command_success(ccommand process);

/**
 * Retrieve the output of a command execution.
 *
 * @param process     The command to retrieve output from.
 * @param output      Buffer to store the output.
 * @param output_size Size of the output buffer.
 * @return            The result of the command execution.
 */
int fscl_command_output(ccommand process, char *output, size_t output_size);

/**
 * Check if a command exists.
 *
 * @param process The command to be checked.
 * @return        1 if the command exists, 0 otherwise.
 */
int fscl_command_exists(ccommand process);

/**
 * Erase a command and check if it exists.
 *
 * @param path The command to be erased.
 * @return     1 if the command exists, 0 otherwise.
 */
int fscl_command_erase_exists(ccommand path);

/**
 * Safely concatenate two strings into a destination buffer.
 *
 * @param dest      The destination buffer for the concatenated strings.
 * @param src       The source string to be concatenated.
 * @param dest_size The size of the destination buffer.
 */
void fscl_command_strcat_safe(char *dest, const char *src, size_t dest_size);

#ifdef __cplusplus
}
#endif

#endif
