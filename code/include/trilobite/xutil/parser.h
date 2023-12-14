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
#ifndef TSCL_PARSER_H
#define TSCL_PARSER_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum {
    TRILO_BOOL_OPTION,
    TRILO_INT_OPTION,
    TRILO_FEATURE_OPTION,
    TRILO_ARRAY_OPTION,
    TRILO_STRING_OPTION,
    TRILO_COMBO_OPTION
} coption_type;

typedef struct coption {
    const char* name;
    coption_type type;
    union {
        int int_value;
        char* str_value;
        char** array_value;
        int feature_value; // 0 for disabled, 1 for enabled, 2 for auto
        int bool_value;    // 0 for false, 1 for true
    };
    int min_int_value;
    int max_int_value;
    char* combo_choices;
    int is_set; // Added to track if the option has been set
} coption;

typedef struct cparser{
    coption* options;
    int num_options;
} cparser;

/**
 * @brief Creates a cparser to parse command line options.
 *
 * @return A pointer to the newly created cparser.
 */
cparser* parser_create_option_parser(void);

/**
 * @brief Adds an option to the cparser.
 *
 * @param parser        The cparser to which the option will be added.
 * @param name          The name of the option.
 * @param type          The type of the option (coption_type).
 * @param min_int_value The minimum integer value allowed for this option.
 * @param max_int_value The maximum integer value allowed for this option.
 * @param combo_choices A string containing valid choices for combo options (comma-separated).
 */
void parser_add_option(cparser* parser, const char* name, coption_type type, int min_int_value, int max_int_value, const char* combo_choices);

/**
 * @brief Checks if an option has been set in the cparser.
 *
 * @param parser The cparser to check for the option.
 * @param name   The name of the option to check.
 *
 * @return 1 if the option has been set, 0 if it has not.
 */
int parser_has_option(cparser* parser, const char* name);

/**
 * @brief Processes command line arguments and populates the cparser.
 *
 * This function processes the command line arguments, setting values for options
 * based on the provided arguments and their associated types and constraints.
 *
 * @param parser The cparser to be populated with option values.
 * @param argc   The number of command line arguments.
 * @param argv   An array of strings representing the command line arguments.
 */
void parser_process_arguments(cparser* parser, int argc, char* argv[]);

/**
 * @brief Deallocates the memory associated with a cparser.
 *
 * This function frees the dynamically allocated memory for the options
 * array and the cparser itself. It should be called when the
 * cparser is no longer needed to avoid memory leaks.
 *
 * @param parser The cparser to be deallocated.
 */
void parser_erase_option_parser(cparser* parser);

/**
 * @brief Checks if a command has been provided in the command line arguments.
 *
 * This function examines the command line arguments to determine whether
 * a command has been provided. It returns 1 if a command is present and
 * 0 otherwise. A command is considered present if the second argument
 * (index 1) exists and does not start with a '-' character.
 *
 * @param argc The number of command line arguments.
 * @param argv The array of command line argument strings.
 *
 * @return 1 if a command is present, 0 otherwise.
 */
int parser_has_command(int argc, char* argv[]);

/**
 * @brief Gets the value of an option.
 *
 * @param parser The cparser containing the option.
 * @param name   The name of the option.
 *
 * @return The value of the option, or NULL if the option doesn't exist or has no value.
 */
const void* parser_get_option_value(cparser* parser, const char* name);

/**
 * @brief Prints usage information for the command-line options.
 *
 * @param parser The cparser containing the options.
 */
void parser_print_usage(cparser* parser);

/**
 * @brief Checks if a combo option choice is valid.
 *
 * @param parser The cparser containing the options.
 * @param name   The name of the combo option.
 * @param choice The choice to check.
 *
 * @return 1 if the choice is valid, 0 otherwise.
 */
int parser_is_combo_choice_valid(cparser* parser, const char* name, const char* choice);

/**
 * @brief Resets all option values to their default state.
 *
 * @param parser The cparser to reset.
 */
void parser_reset_options(cparser* parser);

/**
 * @brief Handles unknown options encountered during parsing.
 *
 * @param parser  The cparser containing the options.
 * @param arg     The unknown argument encountered.
 */
void parser_handle_unknown_option(cparser* parser, const char* arg);

#ifdef __cplusplus
}
#endif

#endif
