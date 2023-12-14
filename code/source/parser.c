/*  ----------------------------------------------------------------------------
    File: parser.c

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
#include "trilobite/xutil/parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to print an error message and exit
void print_error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
} // end of func

// Helper function to find an option by name
coption* find_option(cparser* parser, const char* name) {
    for (int i = 0; i < parser->num_options; i++) {
        if (strcmp(name, parser->options[i].name) == 0) {
            return &parser->options[i];
        }
    }
    return NULL;
} // end of func

// Creates a cparser to parse command line options.
cparser* parser_create_option_parser(void) {
    cparser* parser = (cparser*)malloc(sizeof(cparser));
    if (parser == NULL) {
        perror("Failed to create option parser");
        exit(1);
    }

    parser->options = NULL;
    parser->num_options = 0;
    return parser;
} // end of func

// Adds an option to the cparser.
void parser_add_option(cparser* parser, const char* name, coption_type type, int min_int_value, int max_int_value, const char* combo_choices) {
    parser->num_options++;
    parser->options = (coption*)realloc(parser->options, parser->num_options * sizeof(coption));
    if (parser->options == NULL) {
        perror("Failed to add option");
        exit(1);
    }

    coption* option = &parser->options[parser->num_options - 1];
    option->name = name;
    option->type = type;
    option->min_int_value = min_int_value;
    option->max_int_value = max_int_value;
    strncpy(option->combo_choices, combo_choices, sizeof(option->combo_choices) - 1);
    option->combo_choices[sizeof(option->combo_choices) - 1] = '\0';  // Ensure null-terminated
    option->is_set = 0; // Initialize as not set
} // end of func

// Checks if an option has been set in the cparser.
int parser_has_option(cparser* parser, const char* name) {
    for (int i = 0; i < parser->num_options; i++) {
        if (strcmp(name, parser->options[i].name) == 0) {
            return parser->options[i].is_set;
        }
    }
    return 0; // Option not found
} // end of func

// Processes command line arguments and populates the cparser.
void parser_process_arguments(cparser* parser, int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        const char* arg = argv[i];
        if (arg[0] == '-') {
            i++; // Move to the next argument, which should be the value
            if (i >= argc) {
                print_error("Missing value for option");
            }
            char* value = argv[i];
            coption* option = find_option(parser, arg + 2);
            if (option == NULL) {
                print_error("Unknown option");
            }
            option->is_set = 1; // Mark the option as set
            switch (option->type) {
                case TRILO_BOOL_OPTION:
                    if (strcmp(value, "true") == 0) {
                        option->bool_value = 1;
                    } else if (strcmp(value, "false") == 0) {
                        option->bool_value = 0;
                    } else {
                        print_error("Invalid value for boolean option");
                    }
                    break;
                case TRILO_INT_OPTION:
                    option->int_value = atoi(value);
                    if (option->int_value < option->min_int_value || option->int_value > option->max_int_value) {
                        print_error("Invalid value for integer option");
                    }
                    break;
                case TRILO_FEATURE_OPTION:
                    if (strcmp(value, "enable") == 0) {
                        option->feature_value = 1;
                    } else if (strcmp(value, "disable") == 0) {
                        option->feature_value = 0;
                    } else if (strcmp(value, "auto") == 0) {
                        option->feature_value = 2;
                    } else {
                        print_error("Invalid value for feature option");
                    }
                    break;
                case TRILO_ARRAY_OPTION: {
                    char* token = strtok(value, ",");
                    int count = 0;
                    while (token != NULL && count < 10) {
                        strcpy(option->array_value[count], token);
                        token = strtok(NULL, ",");
                        count++;
                    }
                    if (count == 10) {
                        print_error("Too many elements in the array");
                    }
                    break;
                }
                case TRILO_STRING_OPTION:
                    strncpy(option->str_value, value, sizeof(option->str_value) - 1);
                    option->str_value[sizeof(option->str_value) - 1] = '\0'; // Ensure null-terminated
                    break;
                case TRILO_COMBO_OPTION:
                    if (strstr(option->combo_choices, value) == NULL) {
                        print_error("Invalid value for combo option");
                    }
                    break;
            }
        }
    }
} // end of func

// Deallocates the cparser and its associated memory.
void parser_erase_option_parser(cparser* parser) {
    if (parser == NULL) {
        return;
    }
    free(parser->options);
    free(parser);
} // end of func

// Checks if a command has been provided in the command line arguments.
int parser_has_command(int argc, char* argv[]) {
    // Ensure at least one argument is present and it does not start with '-'
    return (argc > 1 && argv[1][0] != '-');
} // end of func

const void* parser_get_option_value(cparser* parser, const char* name) {
    for (int i = 0; i < parser->num_options; ++i) {
        if (strcmp(parser->options[i].name, name) == 0 && parser->options[i].is_set) {
            switch (parser->options[i].type) {
                case TRILO_BOOL_OPTION:
                    return &(parser->options[i].bool_value);
                case TRILO_INT_OPTION:
                    return &(parser->options[i].int_value);
                case TRILO_FEATURE_OPTION:
                    return &(parser->options[i].feature_value);
                case TRILO_STRING_OPTION:
                    return parser->options[i].str_value;
                case TRILO_ARRAY_OPTION:
                    return parser->options[i].array_value;
                case TRILO_COMBO_OPTION:
                    return parser->options[i].str_value;
            }
        }
    }
    return NULL;
} // end of func

void parser_print_usage(cparser* parser) {
    printf("Usage: <program> [options]\n");
    for (int i = 0; i < parser->num_options; ++i) {
        printf("  --%s", parser->options[i].name);
        switch (parser->options[i].type) {
            case TRILO_BOOL_OPTION:
                printf(" (bool)");
                break;
            case TRILO_INT_OPTION:
                printf(" (int)");
                break;
            case TRILO_FEATURE_OPTION:
                printf(" (feature)");
                break;
            case TRILO_STRING_OPTION:
                printf(" (string)");
                break;
            case TRILO_ARRAY_OPTION:
                printf(" (array)");
                break;
            case TRILO_COMBO_OPTION:
                printf(" (combo: %s)", parser->options[i].combo_choices);
                break;
        }
        printf("\n");
    }
} // end of func

int parser_is_combo_choice_valid(cparser* parser, const char* name, const char* choice) {
    for (int i = 0; i < parser->num_options; ++i) {
        if (strcmp(parser->options[i].name, name) == 0 && parser->options[i].type == TRILO_COMBO_OPTION) {
            char* valid_choices = parser->options[i].combo_choices;
            char* token = strtok(valid_choices, ",");
            while (token != NULL) {
                if (strcmp(token, choice) == 0) {
                    return 1; // Valid choice found
                }
                token = strtok(NULL, ",");
            }
            return 0; // Invalid choice
        }
    }
    return 0; // Option not found
} // end of func

void parser_reset_options(cparser* parser) {
    for (int i = 0; i < parser->num_options; ++i) {
        parser->options[i].is_set = 0;
        switch (parser->options[i].type) {
            case TRILO_BOOL_OPTION:
                parser->options[i].bool_value = 0;
                break;
            case TRILO_INT_OPTION:
                parser->options[i].int_value = 0;
                break;
            case TRILO_FEATURE_OPTION:
                parser->options[i].feature_value = 0;
                break;
            case TRILO_STRING_OPTION:
                free(parser->options[i].str_value);
                parser->options[i].str_value = NULL;
                break;
            case TRILO_ARRAY_OPTION:
                free(parser->options[i].array_value);
                parser->options[i].array_value = NULL;
                break;
            case TRILO_COMBO_OPTION:
                free(parser->options[i].str_value);
                parser->options[i].str_value = NULL;
                break;
        }
    }
} // end of func

void parser_handle_unknown_option(cparser* parser, const char* arg) {
    fprintf(stderr, "Unknown option: %s\n", arg);
} // end of func
