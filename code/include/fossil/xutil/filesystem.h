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

/**
 * Create a filesystem object for the specified path.
 *
 * @param path The path for the filesystem.
 * @return     The created filesystem object.
 */
cfilesystem fscl_filesys_create(const char* path);

/**
 * Erase a filesystem object.
 *
 * @param directory The filesystem object to be erased.
 */
void fscl_filesys_erase(cfilesystem* directory);

/**
 * List files in the specified directory.
 *
 * @param directory The directory to list files from.
 */
void fscl_filesys_list_files(const cfilesystem* directory);

/**
 * Create a subdirectory in the specified parent directory.
 *
 * @param parent            The parent directory.
 * @param subfscl_filesys_name The name of the subdirectory to be created.
 */
void fscl_filesys_create_subdirectory(const cfilesystem* parent, const char* subfscl_filesys_name);

/**
 * Check if a directory or filesystem exists at the specified path.
 *
 * @param directory The directory or filesystem to check.
 * @return          1 if it exists, 0 otherwise.
 */
int fscl_filesys_exists(const cfilesystem* directory);

/**
 * Remove a file from the specified directory.
 *
 * @param directory The directory from which to remove the file.
 * @param filename  The name of the file to be removed.
 */
void fscl_filesys_remove_file(const cfilesystem* directory, const char* filename);

/**
 * Change the current working directory of the filesystem object.
 *
 * @param directory The filesystem object to change the directory for.
 * @param new_path  The new path to set as the working directory.
 */
void fscl_filesys_change_directory(cfilesystem* directory, const char* new_path);

#ifdef __cplusplus
}
#endif

#endif
