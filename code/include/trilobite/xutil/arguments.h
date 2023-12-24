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
#ifndef TSCL_ARG_PARSER_H
#define TSCL_ARG_PARSER_H

#ifdef __cplusplus
extern "C"
{
#endif

// Option types
typedef enum {
    COPTION_TYPE_INT,
    COPTION_TYPE_STRING,
    COPTION_TYPE_BOOL,
    COPTION_TYPE_COMBO,
    COPTION_TYPE_FEATURE
} coption_type;

// Feature values
typedef enum {
    FEATURE_ENABLE,
    FEATURE_DISABLE,
    FEATURE_AUTO
} feature_value;

// Combo choice structure
typedef struct {
    const char* name;
    int value;
} combo_choice;

// Option value union
typedef union {
    int int_val;
    char* str_val;
    int bool_val;
    int combo_val;
    feature_value feature_val;
} coption_value;

// Option structure
typedef struct {
    const char* name;
    coption_type type;
    coption_value value;
    void* extra_data; // Used for choices in COPTION_TYPE_COMBO
    int num_choices;  // Used for choices in COPTION_TYPE_COMBO
    int parsed;       // Flag to indicate if the option is parsed
} coption;

// Command line structure
typedef struct {
    int argc;
    const char** argv;
} ccommandline;

// =================================================================
// Avalable functions
// =================================================================
void tscl_arg_parse_usage(const char* program_name, coption* options, int num_options);
int tscl_arg_parse_has(coption* options, int num_options, const char* option_name);
void tscl_arg_parse(ccommandline* cmd, coption* options, int num_options);
void tscl_arg_check_unrecognized(ccommandline* cmd, coption* options, int num_options);
void tscl_arg_print_parsed_options(coption* options, int num_options);
void tscl_arg_reset_parsed_flags(coption* options, int num_options);
combo_choice* tscl_arg_create_combo_choices(const char* names[], const int values[], int num_choices);
coption* tscl_arg_create_options(const char* names[], coption_type types[], coption_value values[], void* extra_data[], int num_options);

#ifdef __cplusplus
}
#endif

#endif
