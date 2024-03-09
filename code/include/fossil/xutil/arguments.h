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
// Available Functions
// =================================================================

/**
 * Print the usage information for command-line argument parsing.
 *
 * @param program_name The name of the program.
 * @param options      Array of coption structures representing available options.
 * @param num_options  The number of options in the array.
 */
void fscl_arg_parse_usage(const char* program_name, coption* options, int num_options);

/**
 * Check if a specific option is present in the parsed command-line arguments.
 *
 * @param options      Array of coption structures representing available options.
 * @param num_options  The number of options in the array.
 * @param option_name  The name of the option to check for.
 * @return             1 if the option is present, 0 otherwise.
 */
int fscl_arg_parse_has(coption* options, int num_options, const char* option_name);

/**
 * Parse the command-line arguments based on the provided options.
 *
 * @param cmd          Pointer to the ccommandline structure representing parsed command-line arguments.
 * @param options      Array of coption structures representing available options.
 * @param num_options  The number of options in the array.
 */
void fscl_arg_parse(ccommandline* cmd, coption* options, int num_options);

/**
 * Check for unrecognized command-line arguments and print an error message if found.
 *
 * @param cmd          Pointer to the ccommandline structure representing parsed command-line arguments.
 * @param options      Array of coption structures representing available options.
 * @param num_options  The number of options in the array.
 */
void fscl_arg_check_unrecognized(ccommandline* cmd, coption* options, int num_options);

/**
 * Print the parsed options along with their values.
 *
 * @param options      Array of coption structures representing available options.
 * @param num_options  The number of options in the array.
 */
void fscl_arg_print_parsed_options(coption* options, int num_options);

/**
 * Reset the parsed flags of the options to their initial state.
 *
 * @param options      Array of coption structures representing available options.
 * @param num_options  The number of options in the array.
 */
void fscl_arg_reset_parsed_flags(coption* options, int num_options);

/**
 * Create an array of combo_choice structures for combo-box style options.
 *
 * @param names        Array of names for the combo choices.
 * @param values       Array of values associated with each choice.
 * @param num_choices  The number of combo choices in the arrays.
 * @return             Pointer to the created array of combo_choice structures.
 */
combo_choice* fscl_arg_create_combo_choices(const char* names[], const int values[], int num_choices);

/**
 * Create an array of coption structures for command-line argument parsing.
 *
 * @param names        Array of names for the options.
 * @param types        Array of coption_type indicating the types of the options.
 * @param values       Array of coption_value representing default values for the options.
 * @param extra_data   Array of pointers to extra data associated with each option (can be NULL).
 * @param num_options  The number of options in the arrays.
 * @return             Pointer to the created array of coption structures.
 */
coption* fscl_arg_create_options(const char* names[], coption_type types[], coption_value values[], void* extra_data[], int num_options);

#ifdef __cplusplus
}
#endif

#endif
