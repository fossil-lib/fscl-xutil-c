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
#ifndef TSCL_ERRORS_H
#define TSCL_ERRORS_H

#ifdef __cplusplus
extern "C"
{
#endif

// Error codes
typedef enum {
    ERROR_NONE,
    ERROR_INVALID_INPUT,
    ERROR_OUT_OF_MEMORY,
    ERROR_FILE_WAS_NOT_FOUND,
    ERROR_PERMISSION_DENIED,
    ERROR_AN_INVALID_OPERATION,
    ERROR_NETWORK_FAILURE,
    ERROR_DATABASE_CONNECTION,
    ERROR_THAT_TIMEOUT,
    ERROR_RESOURCE_UNAVAILABLE,
    ERROR_INVALID_ARGUMENT,
    ERROR_UNSUPPORTED_FEATURE,
    ERROR_AN_INVALID_STATE,
    ERROR_UNKNOWN
} ErrorCode;

// Error structure
typedef struct {
    ErrorCode code;
    char message[256];
} Error;

/**
 * @brief Initializes an error structure with the provided error code and message.
 *
 * This function initializes the fields of the given Error structure with the provided
 * error code and message. The message is copied into the error structure, and if the
 * message is NULL, a default "Unknown error" message is used.
 *
 * @param error   Pointer to the Error structure to be initialized.
 * @param code    The error code to be set in the error structure.
 * @param message The error message to be set in the error structure.
 */
void errors_init(Error *error, ErrorCode code, const char *message);

/**
 * @brief Handles an error by printing relevant information to the console.
 *
 * This function takes an Error structure as input and prints information about the error
 * to the console. If the error code is ERROR_NONE, it prints "No error"; otherwise, it
 * prints the error code and message.
 *
 * @param error Pointer to the Error structure to be handled.
 */
void errors_handle_error(Error *error);

/**
 * @brief Creates a new error structure with the provided error code and message.
 *
 * This function allocates memory for a new Error structure, initializes its fields
 * with the provided error code and message, and returns a pointer to the created error.
 * The caller is responsible for freeing the allocated memory when done.
 *
 * @param code    The error code to be set in the error structure.
 * @param message The error message to be set in the error structure.
 * @return A pointer to the newly created Error structure.
 */
Error *errors_create(ErrorCode code, const char *message);

/**
 * @brief Frees the memory associated with an error structure.
 *
 * This function deallocates the memory used by the given Error structure. It is the
 * caller's responsibility to ensure that the provided error pointer is not used after
 * calling this function.
 *
 * @param error Pointer to the Error structure to be freed.
 */
void errors_erase(Error *error);

/**
 * @brief Retrieves the error code from an error structure.
 *
 * @param error Pointer to the Error structure.
 * @return The error code from the provided Error structure.
 */
ErrorCode errors_get_code(const Error *error);

/**
 * @brief Retrieves the error message from an error structure.
 *
 * @param error Pointer to the Error structure.
 * @return A pointer to the error message from the provided Error structure.
 */
const char *errors_get_message(const Error *error);

/**
 * @brief Checks if an error structure represents an error (non-ERROR_NONE code).
 *
 * @param error Pointer to the Error structure.
 * @return 1 if the error code is not ERROR_NONE; 0 otherwise.
 */
int errors_has_what(const Error *error);

/**
 * @brief Sets the error code in an error structure.
 *
 * This function updates the error code in the provided Error structure.
 *
 * @param error Pointer to the Error structure.
 * @param code  The new error code to be set in the error structure.
 */
void errors_set_code(Error *error, ErrorCode code);

/**
 * @brief Sets the error message in an error structure.
 *
 * This function updates the error message in the provided Error structure. The message
 * is copied into the error structure, and if it is NULL, a default "Unknown error"
 * message is used.
 *
 * @param error   Pointer to the Error structure.
 * @param message The new error message to be set in the error structure.
 */
void errors_set_message(Error *error, const char *message);

#ifdef __cplusplus
}
#endif

#endif
