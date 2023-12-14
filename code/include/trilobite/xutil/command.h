/*
   This C header file is part of the Trilobite Stdlib, a collection of utility functions and
   standard data structures for enhancing software development projects. Feel free to use
   and modify these utilities to streamline your software development process.

   Project: Trilobite Stdlib
   Author: Michael Gene Brockus (Dreamer)
   Email: michaelbrockus@gmail.com
   Website: [Trilobite Coder Blog](https://trilobite.home.blog)

   Trilobite Stdlib is designed to provide a robust set of functionalities that can be
   incorporated into various projects. The utilities included in this library aim to optimize
   and standardize common operations, ensuring efficient and reliable code.

   This header file is a part of a broader initiative to support developers in creating secure,
   efficient, and scalable software. Contributions, suggestions, and feedback are welcomed,
   as we strive to continuously improve and expand the capabilities of Trilobite Stdlib.

   License: Apache License 2.0
   SPDX Identifier: Apache-2.0

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software distributed under the License
   is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
   or implied. See the License for the specific language governing permissions and limitations
   under the License.

   The above copyright notice and this permission notice shall be included in all copies or
   substantial portions of the Software.

   Please review the full text of the Apache License 2.0 for the complete terms and conditions.

   (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
*/
#ifndef TSCL_COMMAND_H
#define TSCL_COMMAND_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>

// Define a typedef for char* to make the code more readable
typedef char* ccommand;

/**
 * @brief Run a system command.
 *
 * This function executes a system command using the system() function.
 *
 * @param process The command to be executed.
 * @return The exit status of the executed command.
 */
int command(ccommand process);

/**
 * @brief Check if a system command executed successfully.
 *
 * This function checks if a system command executed successfully based on its exit status.
 *
 * @param process The command to be executed.
 * @return 0 if the command executed successfully, -1 otherwise.
 */
int command_success(ccommand process);

/**
 * @brief Get the output of a system command.
 *
 * This function executes a system command and captures its output into the provided buffer.
 *
 * @param process The command to be executed.
 * @param output Buffer to store the command output.
 * @param output_size Size of the output buffer.
 * @return The exit status of the executed command.
 */
int command_output(ccommand process, char *output, size_t output_size);

/**
 * @brief Check if a system command exists and is executable.
 *
 * This function checks if a system command exists and is executable by attempting to execute it.
 *
 * @param process The command to be checked.
 * @return 1 if the command exists and is executable, 0 otherwise.
 */
int command_exists(ccommand process);

/**
 * @brief Check if a directory exists.
 *
 * This function checks if a directory exists based on its path.
 *
 * @param path The path of the directory to be checked.
 * @return 1 if the directory exists, 0 otherwise.
 */
int command_erase_exists(ccommand path);

/**
 * @brief Concatenate strings safely for system commands.
 *
 * This function safely concatenates a source string to a destination string, ensuring no buffer overflow.
 * It is specifically designed for constructing system commands.
 *
 * @param dest Destination string.
 * @param src Source string to be concatenated.
 * @param dest_size Size of the destination buffer.
 */
void command_strcat_safe(char *dest, const char *src, size_t dest_size);

#ifdef __cplusplus
}
#endif

#endif
