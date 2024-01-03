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
cos_info fscl_platform_get_os_info(void);
carch_info fscl_platform_get_architecture_info(void);
int fscl_platform_is_little_endian(void);
int fscl_platform_is_big_endian(void);
uint16_t fscl_platform_swap_endian_16(uint16_t value);
uint32_t fscl_platform_swap_endian_32(uint32_t value);
uint64_t fscl_platform_swap_endian_64(uint64_t value);

#ifdef __cplusplus
}
#endif

#endif
