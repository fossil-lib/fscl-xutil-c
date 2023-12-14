/*
   This C header file is part of the Trilobite Stdlib, a collection of utility functions and
   standard data structures for enhancing software development projects. Feel free to use
   and modify these utilities to streamline your software development process.

   Project: Trilobite Stdlib
   Author: Michael Gene Brockus (Dreamer)
   Email: michaelbrockus@gmail.com
   Website: [Trilobite Coder Blog](https://trilobite.home.blog)

   Trilobite Stdlib is designed to provide a robust set of functionalities that can be
   incorporated into various projects. The utilities included in this library aim to optimize
   and standardize common operations, ensuring efficient and reliable code.

   This header file is a part of a broader initiative to support developers in creating secure,
   efficient, and scalable software. Contributions, suggestions, and feedback are welcomed,
   as we strive to continuously improve and expand the capabilities of Trilobite Stdlib.

   License: Apache License 2.0
   SPDX Identifier: Apache-2.0

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software distributed under the License
   is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
   or implied. See the License for the specific language governing permissions and limitations
   under the License.

   The above copyright notice and this permission notice shall be included in all copies or
   substantial portions of the Software.

   Please review the full text of the Apache License 2.0 for the complete terms and conditions.

   (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
*/
#ifndef TSCL_DIRECTORY_H
#define TSCL_DIRECTORY_H

#ifdef __cplusplus
extern "C"
{
#endif

// Structure to represent a directory
typedef struct {
    char* path;
} cdirectory;

/**
 * @brief Creates a new directory.
 *
 * @param path The path of the directory to be created.
 * @return A structure representing the created directory.
 */
cdirectory directory_create(const char* path);

/**
 * @brief Deletes a directory.
 *
 * @param directory Pointer to the structure representing the directory to be deleted.
 */
void directory_erase(cdirectory* directory);

/**
 * @brief Lists files in a directory.
 *
 * @param directory Pointer to the structure representing the directory to list files in.
 */
void directory_list_files(const cdirectory* directory);

/**
 * @brief Creates a subdirectory within a parent directory.
 *
 * @param parent Pointer to the structure representing the parent directory.
 * @param subdirectory_name Name of the subdirectory to be created.
 */
void directory_create_subdirectory(const cdirectory* parent, const char* subdirectory_name);

/**
 * @brief Checks if a directory exists.
 *
 * @param directory Pointer to the structure representing the directory to check.
 * @return 1 if true (directory exists), 0 if false.
 */
int directory_exists(const cdirectory* directory);

/**
 * @brief Removes a file within a directory.
 *
 * @param directory Pointer to the structure representing the directory containing the file.
 * @param filename Name of the file to be removed.
 */
void directory_remove_file(const cdirectory* directory, const char* filename);

/**
 * @brief Navigates to a different directory.
 *
 * @param directory Pointer to the structure representing the current directory.
 * @param new_path The path of the directory to navigate to.
 */
void directory_change_directory(cdirectory* directory, const char* new_path);

#ifdef __cplusplus
}
#endif

#endif
