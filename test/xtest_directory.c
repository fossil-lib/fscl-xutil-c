/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xutil/directory.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test case for initializing error with a message
XTEST_CASE(test_directory_create) {
    cdirectory dir = directory_create("path\\to\\directory");
    TEST_ASSERT_NOT_NULL_PTR(dir.path);
    TEST_ASSERT_TRUE(directory_exists(&dir));
    directory_erase(&dir);
}

XTEST_CASE(test_directory_list_files) {
    cdirectory dir = directory_create("path\\to\\directory");
    // You may want to redirect stdout to capture the printed output for testing
    // Redirecting output in C is platform-dependent, so it's not included here.
    directory_list_files(&dir);
    // Add assertions based on the expected output
    directory_erase(&dir);
}

XTEST_CASE(test_directory_create_subdirectory) {
    cdirectory parentDirectory = directory_create("path\\to\\parent");
    directory_create_subdirectory(&parentDirectory, "new_subdirectory");
    TEST_ASSERT_TRUE(directory_exists(&parentDirectory));
    cdirectory subDirectory = directory_create("path\\to\\parent\\new_subdirectory");
    TEST_ASSERT_TRUE(directory_exists(&subDirectory));
    directory_erase(&parentDirectory);
    directory_erase(&subDirectory);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_directory_group) {
    XTEST_RUN_UNIT(test_directory_create,              runner);
    XTEST_RUN_UNIT(test_directory_list_files,          runner);
    XTEST_RUN_UNIT(test_directory_create_subdirectory, runner);
} // end of function main
