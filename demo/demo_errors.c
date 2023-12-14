/*  ----------------------------------------------------------------------------
    File: demo_errors.c

    Description:
    This demo file serves as a showcase of the Trilobite Stdlib in action. It provides
    example code snippets and usage scenarios to help users understand how to leverage
    the library's features and functions in their own projects.

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
#include <trilobite/xutil/errors.h>
#include <stdio.h>

// Function to perform a task that might encounter an error
void perform_task(int input, Error *error) {
    if (input < 0) {
        errors_init(error, ERROR_INVALID_INPUT, "Invalid input value");
        return;
    }

    // Simulate running out of memory
    if (input == 42) {
        errors_init(error, ERROR_OUT_OF_MEMORY, "Out of memory");
        return;
    }

    // Simulate successful task completion
    errors_init(error, ERROR_NONE, "No error");
}

int main() {
    // Example usage of error handling
    Error task_error;
    int input_value;

    printf("Enter a positive integer (or -1 to trigger an error): ");
    scanf("%d", &input_value);

    perform_task(input_value, &task_error);

    if (errors_has_what(&task_error)) {
        // Error occurred, handle it
        printf("Error occurred:\n");
        errors_handle_error(&task_error);
    } else {
        // No error, proceed with the result
        printf("Task completed successfully.\n");
    }

    // Clean up memory associated with error structure
    errors_erase(&task_error);

    return 0;
} // end of func
