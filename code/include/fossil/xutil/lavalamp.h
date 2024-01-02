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
clavalamp* fscl_lava_create(int numLamps);
void fscl_lava_erase(clavalamp* lamps);
void fscl_lava_capture_state(clavalamp* lamp);
void fscl_lava_combine_states(clavalamp* lamps, int numLamps, char* combinedState);
unsigned int fscl_lava_hash_combined_state(const char* combinedState, int length);
void fscl_lava_print_state(const clavalamp* lamp);
void fscl_lava_visualize(const clavalamp* lamps, int numLamps);
void fscl_lava_analyze(const clavalamp* lamps, int numLamps);
void fscl_lava_reset(clavalamp* lamps, int numLamps);
void fscl_lava_randomize(clavalamp* lamps, int numLamps);
void fscl_lava_seed(unsigned int seed);
int fscl_lava_random(void);


#ifdef __cplusplus
}
#endif

#endif
