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

/**
 * Perform a bitwise AND operation between two bitwise values.
 *
 * @param a The first bitwise value.
 * @param b The second bitwise value.
 * @return  The result of the bitwise AND operation.
 */
bitwise fscl_binary_and(bitwise a, bitwise b);

/**
 * Perform a bitwise OR operation between two bitwise values.
 *
 * @param a The first bitwise value.
 * @param b The second bitwise value.
 * @return  The result of the bitwise OR operation.
 */
bitwise fscl_binary_or(bitwise a, bitwise b);

/**
 * Perform a bitwise XOR operation between two bitwise values.
 *
 * @param a The first bitwise value.
 * @param b The second bitwise value.
 * @return  The result of the bitwise XOR operation.
 */
bitwise fscl_binary_xor(bitwise a, bitwise b);

/**
 * Perform a bitwise left shift operation on a bitwise value.
 *
 * @param a      The bitwise value to be left-shifted.
 * @param shift  The number of positions to shift.
 * @return       The result of the bitwise left shift operation.
 */
bitwise fscl_binary_left_shift(bitwise a, bitwise_shift shift);

/**
 * Perform a bitwise right shift operation on a bitwise value.
 *
 * @param a      The bitwise value to be right-shifted.
 * @param shift  The number of positions to shift.
 * @return       The result of the bitwise right shift operation.
 */
bitwise fscl_binary_right_shift(bitwise a, bitwise_shift shift);

/**
 * Count the number of set bits in a bitwise value.
 *
 * @param a The bitwise value.
 * @return  The count of set bits.
 */
int fscl_binary_count_set_bits(bitwise a);

/**
 * Toggle all bits in a bitwise value (bitwise NOT operation).
 *
 * @param a The bitwise value to be toggled.
 * @return  The result of toggling all bits.
 */
bitwise fscl_binary_toggle_bits(bitwise a);

/**
 * Rotate the bits of a bitwise value to the left.
 *
 * @param a      The bitwise value to be rotated.
 * @param shift  The number of positions to rotate.
 * @return       The result of the bitwise left rotation.
 */
bitwise fscl_binary_rotate_left(bitwise a, bitwise_shift shift);

/**
 * Rotate the bits of a bitwise value to the right.
 *
 * @param a      The bitwise value to be rotated.
 * @param shift  The number of positions to rotate.
 * @return       The result of the bitwise right rotation.
 */
bitwise fscl_binary_rotate_right(bitwise a, bitwise_shift shift);

/**
 * Check if a specific bit is set in a bitwise value.
 *
 * @param a             The bitwise value.
 * @param bit_position  The position of the bit to check.
 * @return              1 if the bit is set, 0 if not.
 */
int fscl_binary_is_bit_set(bitwise a, int bit_position);

/**
 * Get the value of a specific bit in a bitwise value.
 *
 * @param a             The bitwise value.
 * @param bit_position  The position of the bit to get.
 * @return              The value of the specified bit (1 or 0).
 */
int fscl_binary_get_bit_value(bitwise a, int bit_position);

/**
 * Set a specific bit in a bitwise value to 1.
 *
 * @param a             The bitwise value.
 * @param bit_position  The position of the bit to set.
 * @return              The result after setting the specified bit.
 */
bitwise fscl_binary_set_bit(bitwise a, int bit_position);

/**
 * Clear a specific bit in a bitwise value (set it to 0).
 *
 * @param a             The bitwise value.
 * @param bit_position  The position of the bit to clear.
 * @return              The result after clearing the specified bit.
 */
bitwise fscl_binary_clear_bit(bitwise a, int bit_position);

/**
 * Update the value of a specific bit in a bitwise value.
 *
 * @param a             The bitwise value.
 * @param bit_position  The position of the bit to update.
 * @param new_value     The new value for the specified bit (1 or 0).
 * @return              The result after updating the specified bit.
 */
bitwise fscl_binary_update_bit(bitwise a, int bit_position, int new_value);

/**
 * Reverse the order of bits in a bitwise value.
 *
 * @param a The bitwise value.
 * @return  The result after reversing the bits.
 */
bitwise fscl_binary_reverse_bits(bitwise a);

/**
 * Set all bits in a bitwise value up to a specified position.
 *
 * @param a        The bitwise value.
 * @param position The position up to which bits should be set.
 * @return         The result after setting bits up to the specified position.
 */
bitwise fscl_binary_set_bits_to_position(bitwise a, int position);

/**
 * Count the number of leading zeros in a bitwise value.
 *
 * @param a The bitwise value.
 * @return  The count of leading zeros.
 */
int fscl_binary_count_leading_zeros(bitwise a);

/**
 * Count the number of trailing zeros in a bitwise value.
 *
 * @param a The bitwise value.
 * @return  The count of trailing zeros.
 */
int fscl_binary_count_trailing_zeros(bitwise a);

/**
 * Swap the values of two bitwise variables.
 *
 * @param a Pointer to the first bitwise variable.
 * @param b Pointer to the second bitwise variable.
 */
void fscl_binary_swap_values(bitwise* a, bitwise* b);

/**
 * Output the binary representation of a bitwise value.
 *
 * @param a The bitwise value.
 */
void fscl_binary_output(bitwise a);

/**
 * Display a bitmap of the binary representation of a bitwise value.
 *
 * @param a The bitwise value.
 */
void fscl_binary_bitmap(bitwise a);

/**
 * Display a bitmap of the binary representation of an 8-bit bitwise value.
 *
 * @param a The 8-bit bitwise value.
 */
void fscl_bitwise8_bitmap(bitwise8 a);

/**
 * Display a bitmap of the binary representation of a 16-bit bitwise value.
 *
 * @param a The 16-bit bitwise value.
 */
void fscl_bitwise16_bitmap(bitwise16 a);

/**
 * Display a bitmap of the binary representation of a 32-bit bitwise value.
 *
 * @param a The 32-bit bitwise value.
 */
void fscl_bitwise32_bitmap(bitwise32 a);

/**
 * Display a bitmap of the binary representation of a 64-bit bitwise value.
 *
 * @param a The 64-bit bitwise value.
 */
void fscl_bitwise64_bitmap(bitwise64 a);

/**
 * Output the binary representation of an 8-bit bitwise value.
 *
 * @param a The 8-bit bitwise value.
 */
void fscl_bitwise8_output(bitwise8 a);

/**
 * Output the binary representation of a 16-bit bitwise value.
 *
 * @param a The 16-bit bitwise value.
 */
void fscl_bitwise16_output(bitwise16 a);

/**
 * Output the binary representation of a 32-bit bitwise value.
 *
 * @param a The 32-bit bitwise value.
 */
void fscl_bitwise32_output(bitwise32 a);

/**
 * Output the binary representation of a 64-bit bitwise value.
 *
 * @param a The 64-bit bitwise value.
 */
void fscl_bitwise64_output(bitwise64 a);

/**
 * Perform a bitwise AND operation between two 8-bit bitwise values.
 *
 * @param a The first 8-bit bitwise value.
 * @param b The second 8-bit bitwise value.
 * @return  The result of the bitwise AND operation.
 */
bitwise8 fscl_binary_and8(bitwise8 a, bitwise8 b);

/**
 * Perform a bitwise OR operation between two 8-bit bitwise values.
 *
 * @param a The first 8-bit bitwise value.
 * @param b The second 8-bit bitwise value.
 * @return  The result of the bitwise OR operation.
 */
bitwise8 fscl_binary_or8(bitwise8 a, bitwise8 b);

/**
 * Perform a bitwise XOR operation between two 8-bit bitwise values.
 *
 * @param a The first 8-bit bitwise value.
 * @param b The second 8-bit bitwise value.
 * @return  The result of the bitwise XOR operation.
 */
bitwise8 fscl_binary_xor8(bitwise8 a, bitwise8 b);

/**
 * Perform a bitwise left shift operation on an 8-bit bitwise value.
 *
 * @param a      The 8-bit bitwise value to be left-shifted.
 * @param shift  The number of positions to shift.
 * @return       The result of the bitwise left shift operation.
 */
bitwise8 fscl_binary_left_shift8(bitwise8 a, bitwise_shift shift);

/**
 * Perform a bitwise right shift operation on an 8-bit bitwise value.
 *
 * @param a      The 8-bit bitwise value to be right-shifted.
 * @param shift  The number of positions to shift.
 * @return       The result of the bitwise right shift operation.
 */
bitwise8 fscl_binary_right_shift8(bitwise8 a, bitwise_shift shift);

/**
 * Count the number of set bits in an 8-bit bitwise value.
 *
 * @param a The 8-bit bitwise value.
 * @return  The count of set bits.
 */
int fscl_binary_count_set_bits8(bitwise8 a);

/**
 * Toggle all bits in an 8-bit bitwise value (bitwise NOT operation).
 *
 * @param a The 8-bit bitwise value to be toggled.
 * @return  The result of toggling all bits.
 */
bitwise8 fscl_binary_toggle_bits8(bitwise8 a);

/**
 * Rotate the bits of an 8-bit bitwise value to the left.
 *
 * @param a      The 8-bit bitwise value to be rotated.
 * @param shift  The number of positions to rotate.
 * @return       The result of the bitwise left rotation.
 */
bitwise8 fscl_binary_rotate_left8(bitwise8 a, bitwise_shift shift);

/**
 * Rotate the bits of an 8-bit bitwise value to the right.
 *
 * @param a      The 8-bit bitwise value to be rotated.
 * @param shift  The number of positions to rotate.
 * @return       The result of the bitwise right rotation.
 */
bitwise8 fscl_binary_rotate_right8(bitwise8 a, bitwise_shift shift);

/**
 * Check if a specific bit is set in an 8-bit bitwise value.
 *
 * @param a             The 8-bit bitwise value.
 * @param bit_position  The position of the bit to check.
 * @return              1 if the bit is set, 0 if not.
 */
int fscl_binary_is_bit_set8(bitwise8 a, int bit_position);

/**
 * Get the value of a specific bit in an 8-bit bitwise value.
 *
 * @param a             The 8-bit bitwise value.
 * @param bit_position  The position of the bit to get.
 * @return              The value of the specified bit (1 or 0).
 */
int fscl_binary_get_bit_value8(bitwise8 a, int bit_position);

/**
 * Set a specific bit in an 8-bit bitwise value to 1.
 *
 * @param a             The 8-bit bitwise value.
 * @param bit_position  The position of the bit to set.
 * @return              The result after setting the specified bit.
 */
bitwise8 fscl_binary_set_bit8(bitwise8 a, int bit_position);

/**
 * Clear a specific bit in an 8-bit bitwise value (set it to 0).
 *
 * @param a             The 8-bit bitwise value.
 * @param bit_position  The position of the bit to clear.
 * @return              The result after clearing the specified bit.
 */
bitwise8 fscl_binary_clear_bit8(bitwise8 a, int bit_position);

/**
 * Update the value of a specific bit in an 8-bit bitwise value.
 *
 * @param a             The 8-bit bitwise value.
 * @param bit_position  The position of the bit to update.
 * @param new_value     The new value for the specified bit (1 or 0).
 * @return              The result after updating the specified bit.
 */
bitwise8 fscl_binary_update_bit8(bitwise8 a, int bit_position, int new_value);

/**
 * Perform a bitwise AND operation between two 16-bit bitwise values.
 *
 * @param a The first 16-bit bitwise value.
 * @param b The second 16-bit bitwise value.
 * @return  The result of the bitwise AND operation.
 */
bitwise16 fscl_binary_and16(bitwise16 a, bitwise16 b);

/**
 * Perform a bitwise OR operation between two 16-bit bitwise values.
 *
 * @param a The first 16-bit bitwise value.
 * @param b The second 16-bit bitwise value.
 * @return  The result of the bitwise OR operation.
 */
bitwise16 fscl_binary_or16(bitwise16 a, bitwise16 b);

/**
 * Perform a bitwise XOR operation between two 16-bit bitwise values.
 *
 * @param a The first 16-bit bitwise value.
 * @param b The second 16-bit bitwise value.
 * @return  The result of the bitwise XOR operation.
 */
bitwise16 fscl_binary_xor16(bitwise16 a, bitwise16 b);

/**
 * Perform a bitwise left shift operation on a 16-bit bitwise value.
 *
 * @param a      The 16-bit bitwise value to be left-shifted.
 * @param shift  The number of positions to shift.
 * @return       The result of the bitwise left shift operation.
 */
bitwise16 fscl_binary_left_shift16(bitwise16 a, bitwise_shift shift);

/**
 * Perform a bitwise right shift operation on a 16-bit bitwise value.
 *
 * @param a      The 16-bit bitwise value to be right-shifted.
 * @param shift  The number of positions to shift.
 * @return       The result of the bitwise right shift operation.
 */
bitwise16 fscl_binary_right_shift16(bitwise16 a, bitwise_shift shift);

/**
 * Count the number of set bits in a 16-bit bitwise value.
 *
 * @param a The 16-bit bitwise value.
 * @return  The count of set bits.
 */
int fscl_binary_count_set_bits16(bitwise16 a);

/**
 * Toggle all bits in a 16-bit bitwise value (bitwise NOT operation).
 *
 * @param a The 16-bit bitwise value to be toggled.
 * @return  The result of toggling all bits.
 */
bitwise16 fscl_binary_toggle_bits16(bitwise16 a);

/**
 * Rotate the bits of a 16-bit bitwise value to the left.
 *
 * @param a      The 16-bit bitwise value to be rotated.
 * @param shift  The number of positions to rotate.
 * @return       The result of the bitwise left rotation.
 */
bitwise16 fscl_binary_rotate_left16(bitwise16 a, bitwise_shift shift);

/**
 * Rotate the bits of a 16-bit bitwise value to the right.
 *
 * @param a      The 16-bit bitwise value to be rotated.
 * @param shift  The number of positions to rotate.
 * @return       The result of the bitwise right rotation.
 */
bitwise16 fscl_binary_rotate_right16(bitwise16 a, bitwise_shift shift);

/**
 * Check if a specific bit is set in a 16-bit bitwise value.
 *
 * @param a             The 16-bit bitwise value.
 * @param bit_position  The position of the bit to check.
 * @return              1 if the bit is set, 0 if not.
 */
int fscl_binary_is_bit_set16(bitwise16 a, int bit_position);

/**
 * Get the value of a specific bit in a 16-bit bitwise value.
 *
 * @param a             The 16-bit bitwise value.
 * @param bit_position  The position of the bit to get.
 * @return              The value of the specified bit (1 or 0).
 */
int fscl_binary_get_bit_value16(bitwise16 a, int bit_position);

/**
 * Set a specific bit in a 16-bit bitwise value to 1.
 *
 * @param a             The 16-bit bitwise value.
 * @param bit_position  The position of the bit to set.
 * @return              The result after setting the specified bit.
 */
bitwise16 fscl_binary_set_bit16(bitwise16 a, int bit_position);

/**
 * Clear a specific bit in a 16-bit bitwise value (set it to 0).
 *
 * @param a             The 16-bit bitwise value.
 * @param bit_position  The position of the bit to clear.
 * @return              The result after clearing the specified bit.
 */
bitwise16 fscl_binary_clear_bit16(bitwise16 a, int bit_position);

/**
 * Update the value of a specific bit in a 16-bit bitwise value.
 *
 * @param a             The 16-bit bitwise value.
 * @param bit_position  The position of the bit to update.
 * @param new_value     The new value for the specified bit (1 or 0).
 * @return              The result after updating the specified bit.
 */
bitwise16 fscl_binary_update_bit16(bitwise16 a, int bit_position, int new_value);

/**
 * Perform a bitwise AND operation between two 32-bit bitwise values.
 *
 * @param a The first 32-bit bitwise value.
 * @param b The second 32-bit bitwise value.
 * @return  The result of the bitwise AND operation.
 */
bitwise32 fscl_binary_and32(bitwise32 a, bitwise32 b);

/**
 * Perform a bitwise OR operation between two 32-bit bitwise values.
 *
 * @param a The first 32-bit bitwise value.
 * @param b The second 32-bit bitwise value.
 * @return  The result of the bitwise OR operation.
 */
bitwise32 fscl_binary_or32(bitwise32 a, bitwise32 b);

/**
 * Perform a bitwise XOR operation between two 32-bit bitwise values.
 *
 * @param a The first 32-bit bitwise value.
 * @param b The second 32-bit bitwise value.
 * @return  The result of the bitwise XOR operation.
 */
bitwise32 fscl_binary_xor32(bitwise32 a, bitwise32 b);

/**
 * Perform a bitwise left shift operation on a 32-bit bitwise value.
 *
 * @param a      The 32-bit bitwise value to be left-shifted.
 * @param shift  The number of positions to shift.
 * @return       The result of the bitwise left shift operation.
 */
bitwise32 fscl_binary_left_shift32(bitwise32 a, bitwise_shift shift);

/**
 * Perform a bitwise right shift operation on a 32-bit bitwise value.
 *
 * @param a      The 32-bit bitwise value to be right-shifted.
 * @param shift  The number of positions to shift.
 * @return       The result of the bitwise right shift operation.
 */
bitwise32 fscl_binary_right_shift32(bitwise32 a, bitwise_shift shift);

/**
 * Count the number of set bits in a 32-bit bitwise value.
 *
 * @param a The 32-bit bitwise value.
 * @return  The count of set bits.
 */
int fscl_binary_count_set_bits32(bitwise32 a);

/**
 * Toggle all bits in a 32-bit bitwise value (bitwise NOT operation).
 *
 * @param a The 32-bit bitwise value to be toggled.
 * @return  The result of toggling all bits.
 */
bitwise32 fscl_binary_toggle_bits32(bitwise32 a);

/**
 * Rotate the bits of a 32-bit bitwise value to the left.
 *
 * @param a      The 32-bit bitwise value to be rotated.
 * @param shift  The number of positions to rotate.
 * @return       The result of the bitwise left rotation.
 */
bitwise32 fscl_binary_rotate_left32(bitwise32 a, bitwise_shift shift);

/**
 * Rotate the bits of a 32-bit bitwise value to the right.
 *
 * @param a      The 32-bit bitwise value to be rotated.
 * @param shift  The number of positions to rotate.
 * @return       The result of the bitwise right rotation.
 */
bitwise32 fscl_binary_rotate_right32(bitwise32 a, bitwise_shift shift);

/**
 * Check if a specific bit is set in a 32-bit bitwise value.
 *
 * @param a             The 32-bit bitwise value.
 * @param bit_position  The position of the bit to check.
 * @return              1 if the bit is set, 0 if not.
 */
int fscl_binary_is_bit_set32(bitwise32 a, int bit_position);

/**
 * Get the value of a specific bit in a 32-bit bitwise value.
 *
 * @param a             The 32-bit bitwise value.
 * @param bit_position  The position of the bit to get.
 * @return              The value of the specified bit (1 or 0).
 */
int fscl_binary_get_bit_value32(bitwise32 a, int bit_position);

/**
 * Set a specific bit in a 32-bit bitwise value to 1.
 *
 * @param a             The 32-bit bitwise value.
 * @param bit_position  The position of the bit to set.
 * @return              The result after setting the specified bit.
 */
bitwise32 fscl_binary_set_bit32(bitwise32 a, int bit_position);

/**
 * Clear a specific bit in a 32-bit bitwise value (set it to 0).
 *
 * @param a             The 32-bit bitwise value.
 * @param bit_position  The position of the bit to clear.
 * @return              The result after clearing the specified bit.
 */
bitwise32 fscl_binary_clear_bit32(bitwise32 a, int bit_position);

/**
 * Update the value of a specific bit in a 32-bit bitwise value.
 *
 * @param a             The 32-bit bitwise value.
 * @param bit_position  The position of the bit to update.
 * @param new_value     The new value for the specified bit (1 or 0).
 * @return              The result after updating the specified bit.
 */
bitwise32 fscl_binary_update_bit32(bitwise32 a, int bit_position, int new_value);

/**
 * Perform a bitwise AND operation between two 64-bit bitwise values.
 *
 * @param a The first 64-bit bitwise value.
 * @param b The second 64-bit bitwise value.
 * @return  The result of the bitwise AND operation.
 */
bitwise64 fscl_binary_and64(bitwise64 a, bitwise64 b);

/**
 * Perform a bitwise OR operation between two 64-bit bitwise values.
 *
 * @param a The first 64-bit bitwise value.
 * @param b The second 64-bit bitwise value.
 * @return  The result of the bitwise OR operation.
 */
bitwise64 fscl_binary_or64(bitwise64 a, bitwise64 b);

/**
 * Perform a bitwise XOR operation between two 64-bit bitwise values.
 *
 * @param a The first 64-bit bitwise value.
 * @param b The second 64-bit bitwise value.
 * @return  The result of the bitwise XOR operation.
 */
bitwise64 fscl_binary_xor64(bitwise64 a, bitwise64 b);

/**
 * Perform a bitwise left shift operation on a 64-bit bitwise value.
 *
 * @param a      The 64-bit bitwise value to be left-shifted.
 * @param shift  The number of positions to shift.
 * @return       The result of the bitwise left shift operation.
 */
bitwise64 fscl_binary_left_shift64(bitwise64 a, bitwise_shift shift);

/**
 * Perform a bitwise right shift operation on a 64-bit bitwise value.
 *
 * @param a      The 64-bit bitwise value to be right-shifted.
 * @param shift  The number of positions to shift.
 * @return       The result of the bitwise right shift operation.
 */
bitwise64 fscl_binary_right_shift64(bitwise64 a, bitwise_shift shift);

/**
 * Count the number of set bits in a 64-bit bitwise value.
 *
 * @param a The 64-bit bitwise value.
 * @return  The count of set bits.
 */
int fscl_binary_count_set_bits64(bitwise64 a);

/**
 * Toggle all bits in a 64-bit bitwise value (bitwise NOT operation).
 *
 * @param a The 64-bit bitwise value to be toggled.
 * @return  The result of toggling all bits.
 */
bitwise64 fscl_binary_toggle_bits64(bitwise64 a);

/**
 * Rotate the bits of a 64-bit bitwise value to the left.
 *
 * @param a      The 64-bit bitwise value to be rotated.
 * @param shift  The number of positions to rotate.
 * @return       The result of the bitwise left rotation.
 */
bitwise64 fscl_binary_rotate_left64(bitwise64 a, bitwise_shift shift);

/**
 * Rotate the bits of a 64-bit bitwise value to the right.
 *
 * @param a      The 64-bit bitwise value to be rotated.
 * @param shift  The number of positions to rotate.
 * @return       The result of the bitwise right rotation.
 */
bitwise64 fscl_binary_rotate_right64(bitwise64 a, bitwise_shift shift);

/**
 * Check if a specific bit is set in a 64-bit bitwise value.
 *
 * @param a             The 64-bit bitwise value.
 * @param bit_position  The position of the bit to check.
 * @return              1 if the bit is set, 0 if not.
 */
int fscl_binary_is_bit_set64(bitwise64 a, int bit_position);

/**
 * Get the value of a specific bit in a 64-bit bitwise value.
 *
 * @param a             The 64-bit bitwise value.
 * @param bit_position  The position of the bit to get.
 * @return              The value of the specified bit (1 or 0).
 */
int fscl_binary_get_bit_value64(bitwise64 a, int bit_position);

/**
 * Set a specific bit in a 64-bit bitwise value to 1.
 *
 * @param a             The 64-bit bitwise value.
 * @param bit_position  The position of the bit to set.
 * @return              The result after setting the specified bit.
 */
bitwise64 fscl_binary_set_bit64(bitwise64 a, int bit_position);

/**
 * Clear a specific bit in a 64-bit bitwise value (set it to 0).
 *
 * @param a             The 64-bit bitwise value.
 * @param bit_position  The position of the bit to clear.
 * @return              The result after clearing the specified bit.
 */
bitwise64 fscl_binary_clear_bit64(bitwise64 a, int bit_position);

/**
 * Update the value of a specific bit in a 64-bit bitwise value.
 *
 * @param a             The 64-bit bitwise value.
 * @param bit_position  The position of the bit to update.
 * @param new_value     The new value for the specified bit (1 or 0).
 * @return              The result after updating the specified bit.
 */
bitwise64 fscl_binary_update_bit64(bitwise64 a, int bit_position, int new_value);

#ifdef __cplusplus
}
#endif

#endif
