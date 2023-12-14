/*  ----------------------------------------------------------------------------
    File: demo_dir.c

    Description:
    This demo file serves as a showcase of the Trilobite Stdlib in action. It provides
    example code snippets and usage scenarios to help users understand how to leverage
    the library's features and functions in their own projects.

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
#include <trilobite/xutil/directory.h>
#include <trilobite/xutil/stream.h>
#include <stdio.h>

// Robotics demo function
void robotic_system_demo() {
    // Create a directory for the robotic system logs
    const char *log_directory_path = "robot_logs";
    cdirectory robot_logs_directory = directory_create(log_directory_path);

    // Check if the directory was successfully created
    if (!directory_exists(&robot_logs_directory)) {
        printf("Error creating the robot logs directory.\n");
        return;
    }

    // Create a log file within the robot logs directory
    const char *log_filename = "robot_movement_log.txt";
    cstream movement_log;
    if (stream_open(&movement_log, log_filename, "w") == -1) {
        printf("Error opening the movement log file.\n");
        directory_erase(&robot_logs_directory);
        return;
    }

    // Log some movements
    stream_write(&movement_log, "Forward 2.5 meters\n", 1, strlen("Forward 2.5 meters\n"));
    stream_write(&movement_log, "Right 1.0 meters\n", 1, strlen("Right 1.0 meters\n"));
    stream_write(&movement_log, "Backward 3.2 meters\n", 1, strlen("Backward 3.2 meters\n"));

    // Close the movement log file
    stream_close(&movement_log);

    // List files in the robot logs directory
    printf("Files in the robot logs directory:\n");
    directory_list_files(&robot_logs_directory);

    // Create a subdirectory within the robot logs directory
    const char *subdirectory_name = "images";
    directory_create_subdirectory(&robot_logs_directory, subdirectory_name);

    // Change the current working directory to the images subdirectory
    directory_change_directory(&robot_logs_directory, subdirectory_name);

    // List files in the images subdirectory
    printf("Files in the images subdirectory:\n");
    directory_list_files(&robot_logs_directory);

    // Clean up: erase the robot logs directory and its contents
    directory_erase(&robot_logs_directory);
} // end of func

int main() {
    robotic_system_demo();
    return 0;
} // end of func
