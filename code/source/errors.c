/*  ----------------------------------------------------------------------------
    File: errors.c

    Description:
    This source file contains the code entry point for the Trilobite Stdlib project.
    It demonstrates the usage of various utilities and functions provided by the
    Trilobite Stdlib to enhance software development.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.home.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
*/
#include "trilobite/xutil/errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to initialize an error structure
void errors_init(Error *error, ErrorCode code, const char *message) {
    if (error == NULL) {
        return; // Safety check
    }

    error->code = code;

    if (message != NULL) {
        strncpy(error->message, message, sizeof(error->message) - 1);
        error->message[sizeof(error->message) - 1] = '\0'; // Ensure null-termination
    } else {
        strcpy(error->message, "Unknown error");
    }
} // end of func

// Function to handle an error by printing to the console
void errors_handle_error(Error *error) {
    if (error == NULL) {
        return; // Safety check
    }

    if (error->code == ERROR_NONE) {
        printf("No error\n");
    } else {
        printf("Error Code: %d\n", error->code);
        printf("Error Message: %s\n", error->message);
    }
} // end of func

// Function to create a new error structure
Error *errors_create(ErrorCode code, const char *message) {
    Error *newError = (Error *)malloc(sizeof(Error));
    if (newError != NULL) {
        errors_init(newError, code, message);
    }
    return newError;
} // end of func

// Function to free the memory associated with an error structure
void errors_erase(Error *error) {
    free(error);
} // end of func

// Function to retrieve the error code from an error structure
ErrorCode errors_get_code(const Error *error) {
    return error != NULL ? error->code : ERROR_UNKNOWN;
} // end of func

// Function to retrieve the error message from an error structure
const char *errors_get_message(const Error *error) {
    return error != NULL ? error->message : "";
} // end of func

// Function to check if an error structure represents an error
int errors_has_what(const Error *error) {
    return error != NULL && error->code != ERROR_NONE;
} // end of func

// Function to set the error code in an error structure
void errors_set_code(Error *error, ErrorCode code) {
    if (error != NULL) {
        error->code = code;
    }
} // end of func

// Function to set the error message in an error structure
void errors_set_message(Error *error, const char *message) {
    if (error != NULL && message != NULL) {
        strncpy(error->message, message, sizeof(error->message) - 1);
        error->message[sizeof(error->message) - 1] = '\0'; // Ensure null-termination
    }
} // end of func
