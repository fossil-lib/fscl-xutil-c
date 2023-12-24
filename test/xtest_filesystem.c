/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xutil/filesystem.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test case for initializing error with a message
XTEST_CASE(test_tscl_filesys_create) {
    cfilesystem dir = tscl_filesys_create("path\\to\\directory");
    TEST_ASSERT_NOT_NULL_PTR(dir.path);
    TEST_ASSERT_TRUE(tscl_filesys_exists(&dir));
    tscl_filesys_erase(&dir);
}

XTEST_CASE(test_tscl_filesys_list_files) {
    cfilesystem dir = tscl_filesys_create("path\\to\\directory");
    // You may want to redirect stdout to capture the printed output for testing
    // Redirecting output in C is platform-dependent, so it's not included here.
    tscl_filesys_list_files(&dir);
    // Add assertions based on the expected output
    tscl_filesys_erase(&dir);
}

XTEST_CASE(test_tscl_filesys_create_subdirectory) {
    cfilesystem parentDirectory = tscl_filesys_create("path\\to\\parent");
    tscl_filesys_create_subdirectory(&parentDirectory, "new_subdirectory");
    TEST_ASSERT_TRUE(tscl_filesys_exists(&parentDirectory));
    cfilesystem subDirectory = tscl_filesys_create("path\\to\\parent\\new_subdirectory");
    TEST_ASSERT_TRUE(tscl_filesys_exists(&subDirectory));
    tscl_filesys_erase(&parentDirectory);
    tscl_filesys_erase(&subDirectory);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_tscl_filesys_group) {
    XTEST_RUN_UNIT(test_tscl_filesys_create,              runner);
    XTEST_RUN_UNIT(test_tscl_filesys_list_files,          runner);
    XTEST_RUN_UNIT(test_tscl_filesys_create_subdirectory, runner);
} // end of function main
