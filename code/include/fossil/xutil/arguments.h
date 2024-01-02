/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#ifndef FSCL_ARG_PARSER_H
#define FSCL_ARG_PARSER_H

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
    char** argv;
} ccommandline;

// =================================================================
// Avalable functions
// =================================================================
void fscl_arg_parse_usage(const char* program_name, coption* options, int num_options);
int fscl_arg_parse_has(coption* options, int num_options, const char* option_name);
void fscl_arg_parse(ccommandline* cmd, coption* options, int num_options);
void fscl_arg_check_unrecognized(ccommandline* cmd, coption* options, int num_options);
void fscl_arg_print_parsed_options(coption* options, int num_options);
void fscl_arg_reset_parsed_flags(coption* options, int num_options);
combo_choice* fscl_arg_create_combo_choices(const char* names[], const int values[], int num_choices);
coption* fscl_arg_create_options(const char* names[], coption_type types[], coption_value values[], void* extra_data[], int num_options);

#ifdef __cplusplus
}
#endif

#endif
