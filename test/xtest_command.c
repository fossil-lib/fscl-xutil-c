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
#include "fossil/xutil/command.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Define Meson build commands for testing
ccommand meson_configure_cmd = "meson build";
ccommand ninja_build_cmd = "ninja -C build";

XTEST_CASE(test_meson_configure) {
    TEST_ASSERT_EQUAL_INT(0, fscl_command_success(meson_configure_cmd));
}

XTEST_CASE(test_ninja_build) {
    TEST_ASSERT_EQUAL_INT(0, fscl_command_success(ninja_build_cmd));
}

XTEST_CASE(test_command_exists) {
    // Assuming that 'ls' is a valid command
    TEST_ASSERT_EQUAL_INT(1, fscl_command_exists("ls"));

    // Assuming that 'nonexistentcommand' is not a valid command
    TEST_ASSERT_EQUAL_INT(0, fscl_command_exists("nonexistentcommand"));
}

XTEST_CASE(test_command_strcat_safe) {
    char result[100] = "start";
    fscl_command_strcat_safe(result, " && ", sizeof(result));
    fscl_command_strcat_safe(result, "echo Hello", sizeof(result));

    TEST_ASSERT_EQUAL_STRING("start && echo Hello", result);
}

XTEST_CASE(test_fscl_filesys_exists) {
    // Assuming that the directory 'build' does not exist initially
    TEST_ASSERT_EQUAL_INT(0, fscl_command_erase_exists("build"));

    // Creating the directory for testing purposes
    fscl_command_success("mkdir build");

    TEST_ASSERT_EQUAL_INT(1, fscl_command_erase_exists("build"));

    // Cleaning up: Remove the created directory
    fscl_command_success("rmdir build");
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(test_command_group) {
    XTEST_RUN_UNIT(test_meson_configure,     runner);
    XTEST_RUN_UNIT(test_ninja_build,         runner);
    XTEST_RUN_UNIT(test_command_exists,      runner);
    XTEST_RUN_UNIT(test_command_strcat_safe, runner);
    XTEST_RUN_UNIT(test_fscl_filesys_exists,    runner);
} // end of function main
