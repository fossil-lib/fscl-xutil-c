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
#include "trilobite/xutil/arguments.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display usage information
void tscl_arg_parse_usage(const char* program_name, coption* options, int num_options) {
    printf("Usage: %s [options]\n\nOptions:\n", program_name);
    for (int i = 0; i < num_options; ++i) {
        printf("  -%s", options[i].name);
        switch (options[i].type) {
            case COPTION_TYPE_INT:
                printf(" <int>");
                break;
            case COPTION_TYPE_STRING:
                printf(" <string>");
                break;
            case COPTION_TYPE_BOOL:
                printf(" (flag)");
                break;
            case COPTION_TYPE_COMBO:
                printf(" {%s}", ((combo_choice*)options[i].extra_data)[0].name);
                for (int j = 1; j < options[i].num_choices; ++j) {
                    printf("|%s", ((combo_choice*)options[i].extra_data)[j].name);
                }
                break;
            case COPTION_TYPE_FEATURE:
                printf(" {enable|disable|auto}");
                break;
        }
        printf("\n");
    }
}

// Function to check if an option has been parsed
int tscl_arg_parse_has(coption* options, int num_options, const char* option_name) {
    for (int i = 0; i < num_options; ++i) {
        if (strcmp(option_name, options[i].name) == 0 && options[i].parsed) {
            return 1; // Option has been parsed
        }
    }
    return 0; // Option not found or not parsed
}

// Function to parse command line arguments
void tscl_arg_parse(ccommandline* cmd, coption* options, int num_options) {
    for (int i = 1; i < cmd->argc; ++i) {
        const char* arg = cmd->argv[i];
        if (arg[0] == '-') {
            // Parse options
            for (int j = 0; j < num_options; ++j) {
                if (strcmp(arg + 1, options[j].name) == 0) {
                    options[j].parsed = 1; // Mark the option as parsed
                    switch (options[j].type) {
                        case COPTION_TYPE_INT:
                            options[j].value.int_val = atoi(cmd->argv[++i]);
                            break;
                        case COPTION_TYPE_STRING:
                            options[j].value.str_val = cmd->argv[++i];
                            break;
                        case COPTION_TYPE_BOOL:
                            options[j].value.bool_val = 1;
                            break;
                        case COPTION_TYPE_COMBO: {
                            const char* choice_str = cmd->argv[++i];
                            for (int k = 0; k < options[j].num_choices; ++k) {
                                if (strcmp(choice_str, ((combo_choice*)options[j].extra_data)[k].name) == 0) {
                                    options[j].value.combo_val = ((combo_choice*)options[j].extra_data)[k].value;
                                    break;
                                }
                            }
                            break;
                        }
                        case COPTION_TYPE_FEATURE:
                            // Parse feature value
                            ++i;
                            if (strcmp(cmd->argv[i], "enable") == 0) {
                                options[j].value.feature_val = FEATURE_ENABLE;
                            } else if (strcmp(cmd->argv[i], "disable") == 0) {
                                options[j].value.feature_val = FEATURE_DISABLE;
                            } else if (strcmp(cmd->argv[i], "auto") == 0) {
                                options[j].value.feature_val = FEATURE_AUTO;
                            } else {
                                fprintf(stderr, "Error: Invalid value for feature.\n");
                                exit(EXIT_FAILURE);
                            }
                            break;
                    }
                    break; // Found and parsed the option, move to the next argument
                }
            }
        }
    }
}

void tscl_arg_check_unrecognized(ccommandline* cmd, coption* options, int num_options) {
    for (int i = 1; i < cmd->argc; ++i) {
        const char* arg = cmd->argv[i];
        if (arg[0] == '-') {
            int recognized = 0;
            for (int j = 0; j < num_options; ++j) {
                if (strcmp(arg + 1, options[j].name) == 0) {
                    recognized = 1;
                    break;
                }
            }
            if (!recognized) {
                fprintf(stderr, "Error: Unrecognized option '%s'\n", arg);
                exit(EXIT_FAILURE);
            }
        }
    }
}

void tscl_arg_check_unrecognized(ccommandline* cmd, coption* options, int num_options) {
    for (int i = 1; i < cmd->argc; ++i) {
        const char* arg = cmd->argv[i];
        if (arg[0] == '-') {
            int recognized = 0;
            for (int j = 0; j < num_options; ++j) {
                if (strcmp(arg + 1, options[j].name) == 0) {
                    recognized = 1;
                    break;
                }
            }
            if (!recognized) {
                fprintf(stderr, "Error: Unrecognized option '%s'\n", arg);
                exit(EXIT_FAILURE);
            }
        }
    }
}

void tscl_arg_print_parsed_options(coption* options, int num_options) {
    for (int i = 0; i < num_options; ++i) {
        printf("Option: %s, Parsed: %s\n", options[i].name, options[i].parsed ? "true" : "false");
    }
}

void tscl_arg_reset_parsed_flags(coption* options, int num_options) {
    for (int i = 0; i < num_options; ++i) {
        options[i].parsed = 0;
    }
}

// Function to create combo choices
combo_choice* tscl_arg_create_combo_choices(const char* names[], const int values[], int num_choices) {
    combo_choice* choices = malloc(num_choices * sizeof(combo_choice));
    if (!choices) {
        fprintf(stderr, "Memory allocation error for combo choices.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_choices; ++i) {
        choices[i].name = names[i];
        choices[i].value = values[i];
    }

    return choices;
}

// Function to create options
coption* tscl_arg_create_options(const char* names[], coption_type types[], coption_value values[], void* extra_data[], int num_options) {
    coption* options = malloc(num_options * sizeof(coption));
    if (!options) {
        fprintf(stderr, "Memory allocation error for options.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_options; ++i) {
        options[i].name = names[i];
        options[i].type = types[i];
        options[i].value = values[i];
        options[i].extra_data = extra_data[i];
        options[i].parsed = 0;
        options[i].num_choices = 0;
    }

    return options;
}
