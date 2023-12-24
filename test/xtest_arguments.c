/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xutil/arguments.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST DATA
//
XTEST_CASE(test_tscl_arg_parse) {
    // Set up test data
    const char* argv[] = {"program", "-number", "42", "-name", "John", "-flag", "-choice", "choice2", "-feature", "enable"};
    const int argc = sizeof(argv) / sizeof(argv[0]);

    // Initialize the command line structure
    ccommandline cmd = {argc, (char**)argv};  // Cast argv to char**

    // Define combo choices
    const char* combo_names[] = {"choice1", "choice2", "choice3"};
    const int combo_values[] = {1, 2, 3};
    combo_choice* combo_choices = malloc(sizeof(combo_choice) * 3);
    for (int i = 0; i < 3; ++i) {
        combo_choices[i].name = combo_names[i];
        combo_choices[i].value = combo_values[i];
    }

    // Define options
    const char* option_names[] = {"number", "name", "flag", "choice", "feature"};
    coption_type option_types[] = {COPTION_TYPE_INT, COPTION_TYPE_STRING, COPTION_TYPE_BOOL, COPTION_TYPE_COMBO, COPTION_TYPE_FEATURE};
    coption_value option_values[] = {{0}, {NULL}, {0}, {0, .combo_val = combo_choices, .num_choices = 3}, {.feature_val = FEATURE_AUTO}};

    // Create options array
    coption* options = malloc(sizeof(coption) * 5);
    for (int i = 0; i < 5; ++i) {
        options[i].name = option_names[i];
        options[i].type = option_types[i];
        options[i].value = option_values[i];
        options[i].extra_data = NULL;
        options[i].num_choices = 0;
        options[i].parsed = 0;
    }

    // Perform the test
    tscl_arg_parse(&cmd, options, 5);

    // Assert the expected results
    TEST_ASSERT_EQUAL_INT(42, options[0].value.int_val);
    TEST_ASSERT_EQUAL_STRING("John", options[1].value.str_val);
    TEST_ASSERT_EQUAL_INT(1, options[2].value.bool_val);
    TEST_ASSERT_EQUAL_INT(2, options[3].value.combo_val);
    TEST_ASSERT_EQUAL_INT(FEATURE_ENABLE, options[4].value.feature_val);

    // Clean up allocated memory
    free(combo_choices);
    free(options);
}


//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_parser_group) {
    XTEST_RUN_UNIT(test_tscl_arg_parse, runner);
} // end of function main
