/*  ----------------------------------------------------------------------------
    File: errors.c

    Description:
    This source file contains the code entry point for the Trilobite Stdlib project.
    It demonstrates the usage of various utilities and functions provided by the
    Trilobite Stdlib to enhance software development.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.home.blog)

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
#include "trilobite/xutil/filesystem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#ifdef _WIN32
#include <direct.h>
#include <io.h>
#define PATH_SEPARATOR '\\'
#else
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#define PATH_SEPARATOR '/'
#endif

// Function to create a new directory
cfilesystem tscl_filesys_create(const char* path) {
    cfilesystem new_directory;
    new_directory.path = (char*)malloc(strlen(path) + 1);
    strcpy(new_directory.path, path);
    return new_directory;
} // end of func

// Function to delete a directory
void tscl_filesys_erase(cfilesystem* directory) {
    if (directory) {
        free(directory->path);
        directory->path = NULL;
    }
} // end of func

// Function to list files in a directory
void tscl_filesys_list_files(const cfilesystem* directory) {
    if (directory) {
        printf("Listing files in directory: %s\n", directory->path);

#ifdef _WIN32
        // Windows-specific listing logic
        intptr_t handle;
        struct _finddata_t file_info;
        if ((handle = _findfirst(strcat(directory->path, "\\*"), &file_info)) != -1L) {
            do {
                printf("%s\n", file_info.name);
            } while (_findnext(handle, &file_info) == 0);
            _findclose(handle);
        }
#else
        // POSIX-specific listing logic
        DIR* dir;
        struct dirent* entry;
        if ((dir = opendir(directory->path)) != NULL) {
            while ((entry = readdir(dir)) != NULL) {
                printf("%s\n", entry->d_name);
            }
            closedir(dir);
        }
#endif
    }
} // end of func

// Function to create a subdirectory
void tscl_filesys_create_subdirectory(const cfilesystem* parent, const char* subtscl_filesys_name) {
    if (parent) {
        printf("Creating subdirectory %s in %s\n", subtscl_filesys_name, parent->path);

#ifdef _WIN32
        // Windows-specific subdirectory creation logic
        _mkdir(strcat(parent->path, "\\"));
        _mkdir(strcat(parent->path, subtscl_filesys_name));
#else
        // POSIX-specific subdirectory creation logic
        char subtscl_filesys_path[256];
        snprintf(subtscl_filesys_path, sizeof(subtscl_filesys_path), "%s/%s", parent->path, subtscl_filesys_name);
        mkdir(subtscl_filesys_path, 0777);
#endif
    }
} // end of func

// Function to check if a directory exists
int tscl_filesys_exists(const cfilesystem* directory) {
    if (directory) {
#ifdef _WIN32
        struct _stat info;
        return (_stat(directory->path, &info) == 0 && S_ISDIR(info.st_mode));
#else
        struct stat info;
        return (stat(directory->path, &info) == 0 && S_ISDIR(info.st_mode));
#endif
    }
    return 0; // Invalid directory structure
} // end of func

// Function to remove a file within a directory
void tscl_filesys_remove_file(const cfilesystem* directory, const char* filename) {
    if (directory) {
        char filepath[256];
        snprintf(filepath, sizeof(filepath), "%s%c%s", directory->path, PATH_SEPARATOR, filename);
        printf("Removing file: %s\n", filepath);
        remove(filepath);
    }
} // end of func

// Function to navigate to a different directory
void tscl_filesys_change_directory(cfilesystem* directory, const char* new_path) {
    if (directory) {
        tscl_filesys_erase(directory);
        directory->path = (char*)malloc(strlen(new_path) + 1);
        strcpy(directory->path, new_path);
    }
} // end of func
