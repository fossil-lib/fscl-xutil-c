/*  ----------------------------------------------------------------------------
    File: demo_parser.c

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
#include <trilobite/xutil/parser.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
    // Create an option parser
    cparser* parser = parser_create_option_parser();

    // Add options to the parser
    parser_add_option(parser, "input", TRILO_STRING_OPTION, 0, 0, NULL);
    parser_add_option(parser, "output", TRILO_STRING_OPTION, 0, 0, NULL);
    parser_add_option(parser, "count", TRILO_INT_OPTION, 1, 100, NULL);
    parser_add_option(parser, "mode", TRILO_COMBO_OPTION, 0, 0, "fast,slow,normal");

    // Process command line arguments
    parser_process_arguments(parser, argc, argv);

    // Check if a command is present
    if (parser_has_command(argc, argv)) {
        printf("Command detected: %s\n", argv[1]);
    } else {
        printf("No command detected.\n");
    }

    // Print option values
    const char* input = parser_get_option_value(parser, "input");
    const char* output = parser_get_option_value(parser, "output");
    int count = *(int*)parser_get_option_value(parser, "count");
    const char* mode = parser_get_option_value(parser, "mode");

    printf("Input: %s\n", input ? input : "Not set");
    printf("Output: %s\n", output ? output : "Not set");
    printf("Count: %d\n", count);
    printf("Mode: %s\n", mode ? mode : "Not set");

    // Print usage information
    parser_print_usage(parser);

    // Reset options for reuse
    parser_reset_options(parser);

    // Handle unknown options
    parser_handle_unknown_option(parser, "--unknown-option");

    // Cleanup and deallocate memory
    parser_erase_option_parser(parser);

    return 0;
} // end of func