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
#ifndef FSCL_BITWISE_H
#define FSCL_BITWISE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

// Define a bitewise shift type
typedef int bitwise_shift;

// Define a 32-bit bitwise type
typedef uint32_t bitwise;

// Define 8-bit binary type
typedef uint8_t bitwise8;

// Define 16-bit binary type
typedef uint16_t bitwise16;

// Define 32-bit binary type
typedef uint32_t bitwise32;

// Define 64-bit binary type
typedef uint64_t bitwise64;

// =================================================================
// Available functions
// =================================================================
bitwise fscl_binary_and(bitwise a, bitwise b);
bitwise fscl_binary_or(bitwise a, bitwise b);
bitwise fscl_binary_xor(bitwise a, bitwise b);
bitwise fscl_binary_left_shift(bitwise a, bitwise_shift shift);
bitwise fscl_binary_right_shift(bitwise a, bitwise_shift shift);
int fscl_binary_count_set_bits(bitwise a);
bitwise fscl_binary_toggle_bits(bitwise a);
bitwise fscl_binary_rotate_left(bitwise a, bitwise_shift shift);
bitwise fscl_binary_rotate_right(bitwise a, bitwise_shift shift);
int fscl_binary_is_bit_set(bitwise a, int bit_position);
int fscl_binary_get_bit_value(bitwise a, int bit_position);
bitwise fscl_binary_set_bit(bitwise a, int bit_position);
bitwise fscl_binary_clear_bit(bitwise a, int bit_position);
bitwise fscl_binary_update_bit(bitwise a, int bit_position, int new_value);
bitwise fscl_binary_reverse_bits(bitwise a);
bitwise fscl_binary_set_bits_to_position(bitwise a, int position);
int fscl_binary_count_leading_zeros(bitwise a);
int fscl_binary_count_trailing_zeros(bitwise a);
void fscl_binary_swap_values(bitwise* a, bitwise* b);
void fscl_binary_output(bitwise a);
void fscl_binary_bitmap(bitwise a);
void fscl_bitwise8_bitmap(bitwise8 a);
void fscl_bitwise16_bitmap(bitwise16 a);
void fscl_bitwise32_bitmap(bitwise32 a);
void fscl_bitwise64_bitmap(bitwise64 a);
void fscl_bitwise8_output(bitwise8 a);
void fscl_bitwise16_output(bitwise16 a);
void fscl_bitwise32_output(bitwise32 a);
void fscl_bitwise64_output(bitwise64 a);
bitwise8 fscl_binary_and8(bitwise8 a, bitwise8 b);
bitwise8 fscl_binary_or8(bitwise8 a, bitwise8 b);
bitwise8 fscl_binary_xor8(bitwise8 a, bitwise8 b);
bitwise8 fscl_binary_left_shift8(bitwise8 a, bitwise_shift shift);
bitwise8 fscl_binary_right_shift8(bitwise8 a, bitwise_shift shift);
int fscl_binary_count_set_bits8(bitwise8 a);
bitwise8 fscl_binary_toggle_bits8(bitwise8 a);
bitwise8 fscl_binary_rotate_left8(bitwise8 a, bitwise_shift shift);
bitwise8 fscl_binary_rotate_right8(bitwise8 a, bitwise_shift shift);
int fscl_binary_is_bit_set8(bitwise8 a, int bit_position);
int fscl_binary_get_bit_value8(bitwise8 a, int bit_position);
bitwise8 fscl_binary_set_bit8(bitwise8 a, int bit_position);
bitwise8 fscl_binary_clear_bit8(bitwise8 a, int bit_position);
bitwise8 fscl_binary_update_bit8(bitwise8 a, int bit_position, int new_value);
bitwise16 fscl_binary_and16(bitwise16 a, bitwise16 b);
bitwise16 fscl_binary_or16(bitwise16 a, bitwise16 b);
bitwise16 fscl_binary_xor16(bitwise16 a, bitwise16 b);
bitwise16 fscl_binary_left_shift16(bitwise16 a, bitwise_shift shift);
bitwise16 fscl_binary_right_shift16(bitwise16 a, bitwise_shift shift);
int fscl_binary_count_set_bits16(bitwise16 a);
bitwise16 fscl_binary_toggle_bits16(bitwise16 a);
bitwise16 fscl_binary_rotate_left16(bitwise16 a, bitwise_shift shift);
bitwise16 fscl_binary_rotate_right16(bitwise16 a, bitwise_shift shift);
int fscl_binary_is_bit_set16(bitwise16 a, int bit_position);
int fscl_binary_get_bit_value16(bitwise16 a, int bit_position);
bitwise16 fscl_binary_set_bit16(bitwise16 a, int bit_position);
bitwise16 fscl_binary_clear_bit16(bitwise16 a, int bit_position);
bitwise16 fscl_binary_update_bit16(bitwise16 a, int bit_position, int new_value);
bitwise32 fscl_binary_and32(bitwise32 a, bitwise32 b);
bitwise32 fscl_binary_or32(bitwise32 a, bitwise32 b);
bitwise32 fscl_binary_xor32(bitwise32 a, bitwise32 b);
bitwise32 fscl_binary_left_shift32(bitwise32 a, bitwise_shift shift);
bitwise32 fscl_binary_right_shift32(bitwise32 a, bitwise_shift shift);
int fscl_binary_count_set_bits32(bitwise32 a);
bitwise32 fscl_binary_toggle_bits32(bitwise32 a);
bitwise32 fscl_binary_rotate_left32(bitwise32 a, bitwise_shift shift);
bitwise32 fscl_binary_rotate_right32(bitwise32 a, bitwise_shift shift);
int fscl_binary_is_bit_set32(bitwise32 a, int bit_position);
int fscl_binary_get_bit_value32(bitwise32 a, int bit_position);
bitwise32 fscl_binary_set_bit32(bitwise32 a, int bit_position);
bitwise32 fscl_binary_clear_bit32(bitwise32 a, int bit_position);
bitwise32 fscl_binary_update_bit32(bitwise32 a, int bit_position, int new_value);
bitwise64 fscl_binary_and64(bitwise64 a, bitwise64 b);
bitwise64 fscl_binary_or64(bitwise64 a, bitwise64 b);
bitwise64 fscl_binary_xor64(bitwise64 a, bitwise64 b);
bitwise64 fscl_binary_left_shift64(bitwise64 a, bitwise_shift shift);
bitwise64 fscl_binary_right_shift64(bitwise64 a, bitwise_shift shift);
int fscl_binary_count_set_bits64(bitwise64 a);
bitwise64 fscl_binary_toggle_bits64(bitwise64 a);
bitwise64 fscl_binary_rotate_left64(bitwise64 a, bitwise_shift shift);
bitwise64 fscl_binary_rotate_right64(bitwise64 a, bitwise_shift shift);
int fscl_binary_is_bit_set64(bitwise64 a, int bit_position);
int fscl_binary_get_bit_value64(bitwise64 a, int bit_position);
bitwise64 fscl_binary_set_bit64(bitwise64 a, int bit_position);
bitwise64 fscl_binary_clear_bit64(bitwise64 a, int bit_position);
bitwise64 fscl_binary_update_bit64(bitwise64 a, int bit_position, int new_value);

#ifdef __cplusplus
}
#endif

#endif
