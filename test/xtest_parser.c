/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xutil/parser.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST DATA
//
XTEST_DATA(ParserTestData) {
    cparser *parser;
}command_line;

//
// XUNIT FIXTURE
//
XTEST_FIXTURE(cli_parser_fixture);
XTEST_SETUP(cli_parser_fixture) {
    command_line.parser = parser_create_option_parser();
}
XTEST_TEARDOWN(cli_parser_fixture) {
    free(command_line.parser);
}

//
// XUNIT TEST CASES
//

// Test case for parser_create_option_parser
XTEST_CASE_FIXTURE(cli_parser_fixture, parser_let_create_option_parser) {
    TEST_ASSERT_NOT_NULL_PTR(command_line.parser);
    TEST_ASSERT_EQUAL_INT(0, command_line.parser->num_options);
}

// Test case for parser_has_option
XTEST_CASE_FIXTURE(cli_parser_fixture, parser_let_has_option) {
    parser_add_option(command_line.parser, "test_option", TRILO_BOOL_OPTION, 0, 1, NULL);

    // Before processing arguments, the option should not be set
    TEST_ASSERT_EQUAL_INT(0, parser_has_option(command_line.parser, "test_option"));

    // After processing arguments, set the option
    char* argv[] = {"program", "-test_option", "true"};
    parser_process_arguments(command_line.parser, 3, argv);

    // The option should now be set
    TEST_ASSERT_EQUAL_INT(1, parser_has_option(command_line.parser, "test_option"));
}

// Test case for parser_add_option
XTEST_CASE_FIXTURE(cli_parser_fixture, parser_let_add_option) {
    parser_add_option(command_line.parser, "bool_option", TRILO_BOOL_OPTION, 0, 1, NULL);

    // Check the added option
    TEST_ASSERT_EQUAL_INT(1, command_line.parser->num_options);
    TEST_ASSERT_EQUAL_STRING("bool_option", command_line.parser->options[0].name);
    TEST_ASSERT_EQUAL_INT(TRILO_BOOL_OPTION, command_line.parser->options[0].type);
}

// Test case for parser_process_arguments with invalid option
XTEST_CASE_FIXTURE(cli_parser_fixture, parser_let_process_arguments_invalid_option) {
    char* argv[] = {"program", "-invalid_option", "value"};
    
    // The function should print an error message and exit
    parser_process_arguments(command_line.parser, 3, argv);
    
    // Check that the parser state remains unchanged
    TEST_ASSERT_EQUAL_INT(0, command_line.parser->num_options);
}

// Test case for parser_process_arguments with missing value
XTEST_CASE_FIXTURE(cli_parser_fixture, parser_let_process_arguments_missing_value) {
    parser_add_option(command_line.parser, "int_option", TRILO_INT_OPTION, 0, 100, NULL);
    char* argv[] = {"program", "-int_option"};

    // The function should print an error message and exit
    parser_process_arguments(command_line.parser, 2, argv);
    
    // Check that the parser state remains unchanged
    TEST_ASSERT_EQUAL_INT(1, command_line.parser->num_options);
    TEST_ASSERT_EQUAL_INT(0, command_line.parser->options[0].is_set);
}

// Test case for parser_process_arguments with invalid value for integer option
XTEST_CASE_FIXTURE(cli_parser_fixture, parser_let_process_arguments_invalid_value) {
    parser_add_option(command_line.parser, "int_option", TRILO_INT_OPTION, 0, 100, NULL);
    char* argv[] = {"program", "-int_option", "invalid"};

    // The function should print an error message and exit
    parser_process_arguments(command_line.parser, 3, argv);
    
    // Check that the parser state remains unchanged
    TEST_ASSERT_EQUAL_INT(1, command_line.parser->num_options);
    TEST_ASSERT_EQUAL_INT(0, command_line.parser->options[0].is_set);
}

// Test case for parser_process_arguments with invalid value for feature option
XTEST_CASE_FIXTURE(cli_parser_fixture, parser_let_process_arguments_invalid_feature_value) {
    parser_add_option(command_line.parser, "feature_option", TRILO_FEATURE_OPTION, 0, 0, NULL);
    char* argv[] = {"program", "-feature_option", "invalid"};

    // The function should print an error message and exit
    parser_process_arguments(command_line.parser, 3, argv);
    
    // Check that the parser state remains unchanged
    TEST_ASSERT_EQUAL_INT(1, command_line.parser->num_options);
    TEST_ASSERT_EQUAL_INT(0, command_line.parser->options[0].is_set);
}

// Test case for parser_process_arguments with too many elements for array option
XTEST_CASE_FIXTURE(cli_parser_fixture, parser_let_process_arguments_too_many_array_elements) {
    parser_add_option(command_line.parser, "array_option", TRILO_ARRAY_OPTION, 0, 0, NULL);
    char* argv[] = {"program", "-array_option", "elem1,elem2,elem3,elem4,elem5,elem6,elem7,elem8,elem9,elem10,elem11"};

    // The function should print an error message and exit
    parser_process_arguments(command_line.parser, 3, argv);
    
    // Check that the parser state remains unchanged
    TEST_ASSERT_EQUAL_INT(1, command_line.parser->num_options);
    TEST_ASSERT_EQUAL_INT(0, command_line.parser->options[0].is_set);
}

// Test case for parser_process_arguments with invalid combo option value
XTEST_CASE_FIXTURE(cli_parser_fixture, parser_let_process_arguments_invalid_combo_value) {
    parser_add_option(command_line.parser, "combo_option", TRILO_COMBO_OPTION, 0, 0, "value1,value2,value3");
    char* argv[] = {"program", "-combo_option", "invalid"};

    // The function should print an error message and exit
    parser_process_arguments(command_line.parser, 3, argv);
    
    // Check that the parser state remains unchanged
    TEST_ASSERT_EQUAL_INT(1, command_line.parser->num_options);
    TEST_ASSERT_EQUAL_INT(0, command_line.parser->options[0].is_set);
}


//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_parser_group) {
    XTEST_RUN_FIXTURE(parser_let_create_option_parser, cli_parser_fixture, runner);
    XTEST_RUN_FIXTURE(parser_let_has_option,           cli_parser_fixture, runner);
    XTEST_RUN_FIXTURE(parser_let_process_arguments_too_many_array_elements, cli_parser_fixture, runner);
    XTEST_RUN_FIXTURE(parser_let_add_option,                              cli_parser_fixture, runner);
    XTEST_RUN_FIXTURE(parser_let_process_arguments_invalid_option,        cli_parser_fixture, runner);
    XTEST_RUN_FIXTURE(parser_let_process_arguments_missing_value,         cli_parser_fixture, runner);
    XTEST_RUN_FIXTURE(parser_let_process_arguments_invalid_value,         cli_parser_fixture, runner);
    XTEST_RUN_FIXTURE(parser_let_process_arguments_invalid_feature_value, cli_parser_fixture, runner);
    XTEST_RUN_FIXTURE(parser_let_process_arguments_invalid_combo_value,   cli_parser_fixture, runner);
} // end of function main
