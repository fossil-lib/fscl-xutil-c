/*  ----------------------------------------------------------------------------
    File: demo_command.c

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
#include <trilobite/xutil/command.h>
#include <stdio.h>

// Define a maximum buffer size for command output
enum {MAX_OUTPUT_SIZE = 555};

// Function to build the project using Meson
int build_project() {
    char mesonCommand[MAX_OUTPUT_SIZE] = "meson build";
    int result;

    // Create the build directory if it doesn't exist
    if (command_erase_exists("build") != 1) {
        result = command_success("mkdir build");
        if (result != 0) {
            fprintf(stderr, "Error creating the build directory.\n");
            return result;
        }
    }

    // Change to the build directory
    result = command_success("cd build");
    if (result != 0) {
        fprintf(stderr, "Error changing to the build directory.\n");
        return result;
    }

    // Configure the project using Meson
    command_strcat_safe(mesonCommand, " && meson ..", sizeof(mesonCommand));
    result = command_success(mesonCommand);
    if (result != 0) {
        fprintf(stderr, "Error configuring the project.\n");
        return result;
    }

    // Build the project using Meson
    result = command_success("meson compile");
    if (result != 0) {
        fprintf(stderr, "Error building the project.\n");
        return result;
    }

    return 0;
} // end of func

int main() {
    // Build the project
    if (build_project() == 0) {
        printf("Project build successful!\n");
    } else {
        fprintf(stderr, "Project build failed.\n");
    }

    return 0;
} // end of func
