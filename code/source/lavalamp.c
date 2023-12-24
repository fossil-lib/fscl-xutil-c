/*  ----------------------------------------------------------------------------
    File: lavalamp.c

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
#include "trilobite/xutil/lavalamp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to capture the state of a virtual lava lamp
void tscl_lava_capture_state(clavalamp* lamp) {
    // Simulate some changes in position and velocity (replace with your simulation logic)
    lamp->position += ((double)rand() / RAND_MAX) - 0.5;
    lamp->velocity += ((double)rand() / RAND_MAX) - 0.5;
}

// Function to combine the states of multiple virtual lava lamps
void tscl_lava_combine_states(clavalamp* lamps, int numLamps, char* combinedState) {
    // Combine the states by concatenating the raw memory
    memcpy(combinedState, lamps, numLamps * sizeof(clavalamp));
}

// Function to hash the combined state using a simple hash function (replace with a secure hash function)
unsigned int tscl_lava_hash_combined_state(const char* combinedState, int length) {
    unsigned int hash = 0;
    for (int i = 0; i < length; ++i) {
        hash = hash * 31 + combinedState[i];
    }
    return hash;
}

// Function to create an array of virtual lava lamps
clavalamp* tscl_lava_create(int numLamps) {
    clavalamp* lamps = (clavalamp*)malloc(numLamps * sizeof(clavalamp));
    if (lamps == NULL) {
        perror("Error allocating memory for virtual lava lamps");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numLamps; ++i) {
        tscl_lava_capture_state(&lamps[i]);
    }

    return lamps;
}

// Utility function to print the state of a virtual lava lamp
void tscl_lava_print_state(const clavalamp* lamp) {
    printf("Lamp State: Position = %f, Velocity = %f\n", lamp->position, lamp->velocity);
}

// Function to free memory allocated for virtual lava lamps
void tscl_lava_erase(clavalamp* lamps) {
    free(lamps);
}

// Function to visualize the state of virtual lava lamps
void tscl_lava_visualize(const clavalamp* lamps, int numLamps) {
    for (int i = 0; i < numLamps; ++i) {
        printf("Lamp %d: Position = %f, Velocity = %f\n", i + 1, lamps[i].position, lamps[i].velocity);
    }
}

// Function to analyze the state of virtual lava lamps
void tscl_lava_analyze(const clavalamp* lamps, int numLamps) {
    printf("Analysis Report:\n");

    for (int i = 0; i < numLamps; ++i) {
        printf("Lamp %d:\n", i + 1);

        // Analysis 1: Check for extreme position
        if (lamps[i].position > 10.0 || lamps[i].position < -10.0) {
            printf("   Warning: Extreme position detected (%f)\n", lamps[i].position);
        }

        // Analysis 2: Check for extreme velocity
        if (lamps[i].velocity > 5.0 || lamps[i].velocity < -5.0) {
            printf("   Warning: Extreme velocity detected (%f)\n", lamps[i].velocity);
        }

        // Analysis 3: Check for stagnant state (very low velocity)
        if (fabs(lamps[i].velocity) < 0.1) {
            printf("   Note: Stagnant state detected (low velocity)\n");
        }

        // Analysis 4: Check for erratic behavior (rapid changes in position)
        if (fabs(lamps[i].velocity) > 2.0 && fabs(lamps[i].position) > 5.0) {
            printf("   Warning: Erratic behavior detected (rapid changes in position)\n");
        }

        // Analysis 5: Check for consistent movement (constant non-zero velocity)
        if (fabs(lamps[i].velocity) > 0.1 && fabs(lamps[i].position) < 5.0) {
            printf("   Note: Consistent movement detected (constant non-zero velocity)\n");
        }
    }
}

// Function to reset the state of virtual lava lamps to their initial values
void tscl_lava_reset(clavalamp* lamps, int numLamps) {
    for (int i = 0; i < numLamps; ++i) {
        lamps[i].position = 0.0;
        lamps[i].velocity = 0.0;
    }
}

// Function to randomize the state of virtual lava lamps for variety or experimentation
void tscl_lava_randomize(clavalamp* lamps, int numLamps) {
    for (int i = 0; i < numLamps; ++i) {
        tscl_lava_capture_state(&lamps[i]);
    }
}

// Function to initialize the random number generator with a seed
void tscl_lava_seed(unsigned int seed) {
    srand(seed);
}

// Function to generate a random number
int tscl_lava_random(void) {
    return rand();
}
