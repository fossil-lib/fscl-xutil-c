/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xutil/errors.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test case for initializing error with a message
XTEST_CASE(errors_let_error_handling_init) {
    Error *error = malloc(sizeof(Error));
    errors_init(error, ERROR_INVALID_INPUT, "Invalid input detected.");

    TEST_ASSERT_EQUAL_INT(ERROR_INVALID_INPUT, error->code);
    TEST_ASSERT_EQUAL_STRING("Invalid input detected.", error->message);

    free(error); // Deallocate memory
}

// Test case for checking error message content
XTEST_CASE(errors_let_error_handling_is_errors) {
    Error *error = malloc(sizeof(Error));

    // Initialize with a message
    errors_init(error, ERROR_INVALID_INPUT, "Invalid input detected.");

    TEST_ASSERT_EQUAL_INT(0, strcmp("Invalid input detected.", error->message)); // Check the error message

    free(error); // Deallocate memory
}

// Test case for initializing error with ERROR_NONE
XTEST_CASE(errors_let_error_handling_no_errors) {
    Error *error = malloc(sizeof(Error));
    errors_init(error, ERROR_NONE, "");

    TEST_ASSERT_EQUAL_INT(ERROR_NONE, error->code);
    TEST_ASSERT_EQUAL_STRING("", error->message);

    free(error); // Deallocate memory
}

// Test case for initializing error with NULL message
XTEST_CASE(errors_let_error_handling_null_message) {
    Error *error = malloc(sizeof(Error));
    errors_init(error, ERROR_INVALID_INPUT, NULL);

    TEST_ASSERT_EQUAL_INT(ERROR_INVALID_INPUT, error->code);
    TEST_ASSERT_EQUAL_STRING("Unknown error", error->message);

    free(error); // Deallocate memory
}

// Test case for initializing error with NULL pointer
XTEST_CASE(errors_let_error_handling_null_pointer) {
    Error *error = NULL;

    errors_init(error, ERROR_INVALID_INPUT, "Invalid input detected.");
    TEST_ASSERT_NULL_PTR(error); // Use TEST_ASSERT_NULL for NULL pointers
}

// Test case for handling error with ERROR_NONE
XTEST_CASE(errors_let_error_handling_handle_no_errors) {
    Error *error = malloc(sizeof(Error));
    errors_init(error, ERROR_NONE, "No error.");
    TEST_ASSERT_EQUAL_INT(ERROR_NONE, error->code);
    TEST_ASSERT_EQUAL_STRING("No error.", error->message);

    // Deallocate memory
    free(error);
}

//
// XUNIT TEST CASES - Edge Cases for ErrorCode Enumeration
//

// Test case for ERROR_UNKNOWN
XTEST_CASE(errors_let_edge_unknown) {
    Error *error = malloc(sizeof(Error));
    errors_init(error, ERROR_UNKNOWN, "Unknown error occurred.");
    TEST_ASSERT_EQUAL_INT(ERROR_UNKNOWN, error->code);
    TEST_ASSERT_EQUAL_STRING("Unknown error occurred.", error->message);

    // Deallocate memory
    free(error);
}

// Additional Edge Cases...

// Test case for ERROR_AN_INVALID_STATE
XTEST_CASE(errors_let_edge_invalid_state) {
    Error *error = malloc(sizeof(Error));
    errors_init(error, ERROR_AN_INVALID_STATE, "Invalid state.");
    TEST_ASSERT_EQUAL_INT(ERROR_AN_INVALID_STATE, error->code);
    TEST_ASSERT_EQUAL_STRING("Invalid state.", error->message);

    // Deallocate memory
    free(error);
}

// Test case for ERROR_NETWORK_FAILURE
XTEST_CASE(errors_let_edge_network_failure) {
    Error *error = malloc(sizeof(Error));
    errors_init(error, ERROR_NETWORK_FAILURE, "Network failure.");
    TEST_ASSERT_EQUAL_INT(ERROR_NETWORK_FAILURE, error->code);
    TEST_ASSERT_EQUAL_STRING("Network failure.", error->message);

    // Deallocate memory
    free(error);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_errors_group) {
    XTEST_RUN_UNIT(errors_let_error_handling_init,              runner);
    XTEST_RUN_UNIT(errors_let_error_handling_is_errors,         runner);
    XTEST_RUN_UNIT(errors_let_error_handling_no_errors,         runner);
    XTEST_RUN_UNIT(errors_let_error_handling_null_message,      runner);
    XTEST_RUN_UNIT(errors_let_error_handling_null_pointer,      runner);
    XTEST_RUN_UNIT(errors_let_error_handling_handle_no_errors,   runner);
    XTEST_RUN_UNIT(errors_let_edge_unknown,                 runner);
    XTEST_RUN_UNIT(errors_let_edge_invalid_state,           runner);
    XTEST_RUN_UNIT(errors_let_edge_network_failure,         runner);
} // end of function main
