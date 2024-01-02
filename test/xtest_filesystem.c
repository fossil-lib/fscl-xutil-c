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
#include "fossil/xutil/filesystem.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test case for initializing error with a message
XTEST_CASE(test_fscl_filesys_create) {
    cfilesystem dir = fscl_filesys_create("path\\to\\directory");
    TEST_ASSERT_NOT_CNULLPTR(dir.path);
    TEST_ASSERT_TRUE(fscl_filesys_exists(&dir));
    fscl_filesys_erase(&dir);
}

XTEST_CASE(test_fscl_filesys_list_files) {
    cfilesystem dir = fscl_filesys_create("path\\to\\directory");
    // You may want to redirect stdout to capture the printed output for testing
    // Redirecting output in C is platform-dependent, so it's not included here.
    fscl_filesys_list_files(&dir);
    // Add assertions based on the expected output
    fscl_filesys_erase(&dir);
}

XTEST_CASE(test_fscl_filesys_create_subdirectory) {
    cfilesystem parentDirectory = fscl_filesys_create("path\\to\\parent");
    fscl_filesys_create_subdirectory(&parentDirectory, "new_subdirectory");
    TEST_ASSERT_TRUE(fscl_filesys_exists(&parentDirectory));
    cfilesystem subDirectory = fscl_filesys_create("path\\to\\parent\\new_subdirectory");
    TEST_ASSERT_TRUE(fscl_filesys_exists(&subDirectory));
    fscl_filesys_erase(&parentDirectory);
    fscl_filesys_erase(&subDirectory);
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(test_fscl_filesys_group) {
    XTEST_RUN_UNIT(test_fscl_filesys_create,              runner);
    XTEST_RUN_UNIT(test_fscl_filesys_list_files,          runner);
    XTEST_RUN_UNIT(test_fscl_filesys_create_subdirectory, runner);
} // end of function main
