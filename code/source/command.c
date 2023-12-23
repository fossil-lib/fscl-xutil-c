/*  ----------------------------------------------------------------------------
    File: command.c

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
#include "trilobite/xutil/command.h"
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #include <windows.h>
    #define PATH_SEPARATOR ";"
#else
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #define PATH_SEPARATOR ":"
#endif

// Define a typedef for char* to make the code more readable
typedef char* ccommand;

// Function to run a command
int tscl_command(ccommand process) {
    int result = system(process);
    if (result == -1) {
        perror("Error executing command");
    }
    return result;
} // end of func

// Function to check if the command executed successfully
int tscl_command_success(ccommand process) {
    int result = tscl_command(process);
    if (result == 0) {
        printf("Command '%s' executed successfully.\n", process);
    } else {
        fprintf(stderr, "Error executing command '%s'.\n", process);
    }
    return result;
} // end of func

// Function to get the output of a command
int tscl_command_output(ccommand process, char *output, size_t output_size) {
#ifdef _WIN32
    FILE *pipe = _popen(process, "r");
    if (!pipe) {
        perror("Error opening pipe");
        return -1;
    }

    size_t bytesRead = fread(output, 1, output_size - 1, pipe);
    output[bytesRead] = '\0';

    if (ferror(pipe)) {
        perror("Error reading from pipe");
        _pclose(pipe);
        return -1;
    }

    int status = _pclose(pipe);
    if (status == -1) {
        perror("Error closing pipe");
    }

    return status;
#else
    int pipe_fd[2];
    pid_t child_pid;

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("Error creating pipe");
        return -1;
    }

    // Fork a child process
    if ((child_pid = fork()) == -1) {
        perror("Error forking process");
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        return -1;
    }

    if (child_pid == 0) {
        // Child process
        close(pipe_fd[0]);  // Close the read end of the pipe

        // Redirect stdout to the pipe
        if (dup2(pipe_fd[1], STDOUT_FILENO) == -1) {
            perror("Error redirecting stdout");
            exit(EXIT_FAILURE);
        }

        // Close the unused write end of the pipe
        close(pipe_fd[1]);

        // Execute the command
        execl("/bin/sh", "/bin/sh", "-c", process, (char *)NULL);
        perror("Error executing command");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        close(pipe_fd[1]);  // Close the write end of the pipe

        // Read the output from the pipe
        size_t bytesRead = read(pipe_fd[0], output, output_size - 1);
        if (bytesRead == -1) {
            perror("Error reading from pipe");
            close(pipe_fd[0]);
            waitpid(child_pid, NULL, 0);  // Wait for the child process to complete
            return -1;
        }

        // Null-terminate the output
        output[bytesRead] = '\0';

        close(pipe_fd[0]);  // Close the read end of the pipe

        // Wait for the child process to complete
        waitpid(child_pid, NULL, 0);

        return 0;  // Success
    }
#endif
} // end of func

// Function to check if a command exists and is executable
int tscl_command_exists(ccommand process) {
#ifdef _WIN32
    // On Windows, check if the command exists in the system path
    const char* env_path = getenv("PATH");
    if (env_path != NULL) {
        char path_copy[1024];
        strcpy(path_copy, env_path);

        char* token = strtok(path_copy, PATH_SEPARATOR);
        while (token != NULL) {
            char full_path[1024];
            snprintf(full_path, sizeof(full_path), "%s\\%s", token, process);
            if (GetFileAttributes(full_path) != INVALID_FILE_ATTRIBUTES) {
                printf("Command '%s' exists and is executable.\n", process);
                return 1;
            }
            token = strtok(NULL, PATH_SEPARATOR);
        }
    }
    fprintf(stderr, "Command '%s' does not exist or is not executable.\n", process);
    return 0;
#else
    // On Unix-like systems, use the access function
    if (access(process, X_OK) == 0) {
        printf("Command '%s' exists and is executable.\n", process);
        return 1;
    } else {
        fprintf(stderr, "Command '%s' does not exist or is not executable.\n", process);
        return 0;
    }
#endif
} // end of function

// Function to check if a directory exists
int tscl_command_erase_exists(ccommand path) {
    struct stat info;
    return stat(path, &info) == 0 && S_ISDIR(info.st_mode);
} // end of func

// Function to concatenate strings safely
void tscl_command_strcat_safe(char *dest, const char *src, size_t dest_size) {
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);

    // Calculate available space in dest buffer
    size_t space_left = dest_size - dest_len;

    // Copy only the part of src that fits in the remaining space
    size_t copy_len = (src_len < space_left) ? src_len : space_left;

    // Append src to dest
    strncat(dest, src, copy_len);
    
    // Ensure null-termination
    dest[dest_size - 1] = '\0';
} // end of func
