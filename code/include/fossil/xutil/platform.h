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
#ifndef FSCL_PLATFORM_H
#define FSCL_PLATFORM_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

// Structure to hold information about the operating system
typedef struct {
    char* name;
    char* version;
} cos_info;

// Structure to hold information about the CPU architecture
typedef struct {
    char* name;
    char* architecture;
} carch_info;

// =================================================================
// Avalable functions
// =================================================================

/**
 * Get information about the operating system.
 *
 * @return Information about the operating system.
 */
cos_info fscl_platform_get_os_info(void);

/**
 * Get information about the architecture.
 *
 * @return Information about the architecture.
 */
carch_info fscl_platform_get_architecture_info(void);

/**
 * Check if the platform is little-endian.
 *
 * @return 1 if the platform is little-endian, 0 otherwise.
 */
int fscl_platform_is_little_endian(void);

/**
 * Check if the platform is big-endian.
 *
 * @return 1 if the platform is big-endian, 0 otherwise.
 */
int fscl_platform_is_big_endian(void);

/**
 * Swap the endianess of a 16-bit value.
 *
 * @param value The 16-bit value to swap.
 * @return      The 16-bit value with swapped endianess.
 */
uint16_t fscl_platform_swap_endian_16(uint16_t value);

/**
 * Swap the endianess of a 32-bit value.
 *
 * @param value The 32-bit value to swap.
 * @return      The 32-bit value with swapped endianess.
 */
uint32_t fscl_platform_swap_endian_32(uint32_t value);

/**
 * Swap the endianess of a 64-bit value.
 *
 * @param value The 64-bit value to swap.
 * @return      The 64-bit value with swapped endianess.
 */
uint64_t fscl_platform_swap_endian_64(uint64_t value);

#ifdef __cplusplus
}
#endif

#endif
