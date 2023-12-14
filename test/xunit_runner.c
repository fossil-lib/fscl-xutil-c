/*  ----------------------------------------------------------------------------
    File: xunit_runner.c

    Description:
    This test file contains unit tests for the various functions and utilities provided
    by the Trilobite Stdlib. These tests ensure the correctness and reliability of the
    library's components and demonstrate their intended usage.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.code.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
*/
#include <trilobite/xtest.h>

//
// XUNIT-GROUP: list of test groups for the runner
//
XTEST_GROUP_EXTERN(test_directory_group);
XTEST_GROUP_EXTERN(test_command_group);
XTEST_GROUP_EXTERN(test_errors_group);
XTEST_GROUP_EXTERN(test_money_group);
XTEST_GROUP_EXTERN(test_number_group);
XTEST_GROUP_EXTERN(test_parser_group);
XTEST_GROUP_EXTERN(test_random_group);

//
// XUNIT-TEST RUNNER
//
int main(int argc, char **argv) {
    XUnitRunner runner = XTEST_RUNNER_START(argc, argv);

    XTEST_GROUP_REGISTER(test_directory_group, runner);
    XTEST_GROUP_REGISTER(test_command_group, runner);
    XTEST_GROUP_REGISTER(test_errors_group, runner);
    XTEST_GROUP_REGISTER(test_money_group, runner);
    XTEST_GROUP_REGISTER(test_number_group, runner);
    XTEST_GROUP_REGISTER(test_parser_group, runner);
    XTEST_GROUP_REGISTER(test_random_group, runner);

    return XTEST_RUNNER_END(runner);
} // end of func
