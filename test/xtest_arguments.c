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
XTEST_CASE(test_tscl_arg_parse_has) {
    // Test tscl_arg_parse_has function
    coption options[] = {
        {"option1", COPTION_TYPE_BOOL, {.bool_val = 0}, NULL, 0, 0},
        {"option2", COPTION_TYPE_INT, {.int_val = 42}, NULL, 0, 0}
    };
    int num_options = sizeof(options) / sizeof(options[0]);

    // Assuming tscl_arg_parse_has returns 1 for the existing option
    TEST_ASSERT_EQUAL_INT(1, tscl_arg_parse_has(options, num_options, "option1"));
}

XTEST_CASE(test_tscl_arg_parse) {
    // Test tscl_arg_parse function
    const char* argv[] = {"program", "-number", "42", "-name", "John", "-flag", "-choice", "choice2", "-feature", "enable"};
    const int argc = sizeof(argv) / sizeof(argv[0]);

    ccommandline cmd = {argc, (char **)argv};
    
    coption options[] = {
        {"option1", COPTION_TYPE_INT, {.int_val = 0}, NULL, 0, 0},
        {"option2", COPTION_TYPE_BOOL, {.bool_val = 0}, NULL, 0, 0}
    };
    int num_options = sizeof(options) / sizeof(options[0]);

    // Assuming tscl_arg_parse modifies the options array
    tscl_arg_parse(&cmd, options, num_options);

    TEST_ASSERT_EQUAL_INT(42, options[0].value.int_val);
    TEST_ASSERT_EQUAL_INT(0, options[1].value.bool_val);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_parser_group) {
    XTEST_RUN_UNIT(test_tscl_arg_parse_has,   runner);
    XTEST_RUN_UNIT(test_tscl_arg_parse,       runner);
} // end of function main
