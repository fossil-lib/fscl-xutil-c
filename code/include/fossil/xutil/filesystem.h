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
#ifndef FSCL_FILESYSTEM_H
#define FSCL_FILESYSTEM_H

#ifdef __cplusplus
extern "C"
{
#endif

// Structure to represent a directory
typedef struct {
    char* path;
} cfilesystem;

// =================================================================
// Avalable functions
// =================================================================
cfilesystem fscl_filesys_create(const char* path);
void fscl_filesys_erase(cfilesystem* directory);
void fscl_filesys_list_files(const cfilesystem* directory);
void fscl_filesys_create_subdirectory(const cfilesystem* parent, const char* subfscl_filesys_name);
int fscl_filesys_exists(const cfilesystem* directory);
void fscl_filesys_remove_file(const cfilesystem* directory, const char* filename);
void fscl_filesys_change_directory(cfilesystem* directory, const char* new_path);

#ifdef __cplusplus
}
#endif

#endif
