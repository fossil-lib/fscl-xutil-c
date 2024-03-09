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
#ifndef FSCL_LAVALAMP_H
#define FSCL_LAVALAMP_H

#ifdef __cplusplus
extern "C"
{
#endif

// Simulate the virtual lava lamp state
typedef struct {
    double position;
    double velocity;
} clavalamp;

// =================================================================
// Avalable functions
// =================================================================

/**
 * Create an array of lava lamps with the specified number of lamps.
 *
 * @param numLamps The number of lava lamps to create.
 * @return         Pointer to the created array of lava lamps.
 */
clavalamp* fscl_lava_create(int numLamps);

/**
 * Erase an array of lava lamps.
 *
 * @param lamps Pointer to the array of lava lamps to be erased.
 */
void fscl_lava_erase(clavalamp* lamps);

/**
 * Capture the state of a lava lamp.
 *
 * @param lamp Pointer to the lava lamp to capture the state.
 */
void fscl_lava_capture_state(clavalamp* lamp);

/**
 * Combine the states of multiple lava lamps into a single string.
 *
 * @param lamps         Pointer to the array of lava lamps.
 * @param numLamps      The number of lava lamps.
 * @param combinedState Buffer to store the combined state string.
 */
void fscl_lava_combine_states(clavalamp* lamps, int numLamps, char* combinedState);

/**
 * Hash the combined state string of lava lamps.
 *
 * @param combinedState The combined state string to hash.
 * @param length        The length of the combined state string.
 * @return              The hash value of the combined state.
 */
unsigned int fscl_lava_hash_combined_state(const char* combinedState, int length);

/**
 * Print the current state of a lava lamp.
 *
 * @param lamp Pointer to the lava lamp to print the state.
 */
void fscl_lava_print_state(const clavalamp* lamp);

/**
 * Visualize the states of multiple lava lamps.
 *
 * @param lamps    Pointer to the array of lava lamps.
 * @param numLamps The number of lava lamps.
 */
void fscl_lava_visualize(const clavalamp* lamps, int numLamps);

/**
 * Analyze the states of multiple lava lamps.
 *
 * @param lamps    Pointer to the array of lava lamps.
 * @param numLamps The number of lava lamps.
 */
void fscl_lava_analyze(const clavalamp* lamps, int numLamps);

/**
 * Reset the states of multiple lava lamps.
 *
 * @param lamps    Pointer to the array of lava lamps.
 * @param numLamps The number of lava lamps.
 */
void fscl_lava_reset(clavalamp* lamps, int numLamps);

/**
 * Randomize the states of multiple lava lamps.
 *
 * @param lamps    Pointer to the array of lava lamps.
 * @param numLamps The number of lava lamps.
 */
void fscl_lava_randomize(clavalamp* lamps, int numLamps);

/**
 * Seed the random number generator for lava lamps.
 *
 * @param seed The seed value for the random number generator.
 */
void fscl_lava_seed(unsigned int seed);

/**
 * Generate a random number for lava lamps.
 *
 * @return The generated random number.
 */
int fscl_lava_random(void);

#ifdef __cplusplus
}
#endif

#endif
