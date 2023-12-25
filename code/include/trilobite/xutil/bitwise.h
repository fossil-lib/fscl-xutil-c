/*
   This C header file is part of the Trilobite Stdlib, a collection of utility functions and
   standard data structures for enhancing software development projects. Feel free to use
   and modify these utilities to streamline your software development process.

   Project: Trilobite Stdlib
   Author: Michael Gene Brockus (Dreamer)
   Email: michaelbrockus@gmail.com
   Website: [Trilobite Coder Blog](https://trilobite.home.blog)

   Trilobite Stdlib is designed to provide a robust set of functionalities that can be
   incorporated into various projects. The utilities included in this library aim to optimize
   and standardize common operations, ensuring efficient and reliable code.

   This header file is a part of a broader initiative to support developers in creating secure,
   efficient, and scalable software. Contributions, suggestions, and feedback are welcomed,
   as we strive to continuously improve and expand the capabilities of Trilobite Stdlib.

   License: Apache License 2.0
   SPDX Identifier: Apache-2.0

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software distributed under the License
   is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
   or implied. See the License for the specific language governing permissions and limitations
   under the License.

   The above copyright notice and this permission notice shall be included in all copies or
   substantial portions of the Software.

   Please review the full text of the Apache License 2.0 for the complete terms and conditions.

   (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
*/
#ifndef TSCL_BITWISE_H
#define TSCL_BITWISE_H

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
bitwise tscl_binary_and(bitwise a, bitwise b);
bitwise tscl_binary_or(bitwise a, bitwise b);
bitwise tscl_binary_xor(bitwise a, bitwise b);
bitwise tscl_binary_left_shift(bitwise a, bitwise_shift shift);
bitwise tscl_binary_right_shift(bitwise a, bitwise_shift shift);
int tscl_binary_count_set_bits(bitwise a);
bitwise tscl_binary_toggle_bits(bitwise a);
bitwise tscl_binary_rotate_left(bitwise a, bitwise_shift shift);
bitwise tscl_binary_rotate_right(bitwise a, bitwise_shift shift);
int tscl_binary_is_bit_set(bitwise a, int bit_position);
int tscl_binary_get_bit_value(bitwise a, int bit_position);
bitwise tscl_binary_set_bit(bitwise a, int bit_position);
bitwise tscl_binary_clear_bit(bitwise a, int bit_position);
bitwise tscl_binary_update_bit(bitwise a, int bit_position, int new_value);
bitwise tscl_binary_reverse_bits(bitwise a);
bitwise tscl_binary_set_bits_to_position(bitwise a, int position);
int tscl_binary_count_leading_zeros(bitwise a);
int tscl_binary_count_trailing_zeros(bitwise a);
void tscl_binary_swap_values(bitwise* a, bitwise* b);
void tscl_binary_output(bitwise a);
void tscl_binary_bitmap(bitwise a);
void tscl_bitwise8_bitmap(bitwise8 a);
void tscl_bitwise16_bitmap(bitwise16 a);
void tscl_bitwise32_bitmap(bitwise32 a);
void tscl_bitwise64_bitmap(bitwise64 a);
void tscl_bitwise8_output(bitwise8 a);
void tscl_bitwise16_output(bitwise16 a);
void tscl_bitwise32_output(bitwise32 a);
void tscl_bitwise64_output(bitwise64 a);
bitwise8 tscl_binary_and8(bitwise8 a, bitwise8 b);
bitwise8 tscl_binary_or8(bitwise8 a, bitwise8 b);
bitwise8 tscl_binary_xor8(bitwise8 a, bitwise8 b);
bitwise8 tscl_binary_left_shift8(bitwise8 a, bitwise_shift shift);
bitwise8 tscl_binary_right_shift8(bitwise8 a, bitwise_shift shift);
int tscl_binary_count_set_bits8(bitwise8 a);
bitwise8 tscl_binary_toggle_bits8(bitwise8 a);
bitwise8 tscl_binary_rotate_left8(bitwise8 a, bitwise_shift shift);
bitwise8 tscl_binary_rotate_right8(bitwise8 a, bitwise_shift shift);
int tscl_binary_is_bit_set8(bitwise8 a, int bit_position);
int tscl_binary_get_bit_value8(bitwise8 a, int bit_position);
bitwise8 tscl_binary_set_bit8(bitwise8 a, int bit_position);
bitwise8 tscl_binary_clear_bit8(bitwise8 a, int bit_position);
bitwise8 tscl_binary_update_bit8(bitwise8 a, int bit_position, int new_value);
bitwise16 tscl_binary_and16(bitwise16 a, bitwise16 b);
bitwise16 tscl_binary_or16(bitwise16 a, bitwise16 b);
bitwise16 tscl_binary_xor16(bitwise16 a, bitwise16 b);
bitwise16 tscl_binary_left_shift16(bitwise16 a, bitwise_shift shift);
bitwise16 tscl_binary_right_shift16(bitwise16 a, bitwise_shift shift);
int tscl_binary_count_set_bits16(bitwise16 a);
bitwise16 tscl_binary_toggle_bits16(bitwise16 a);
bitwise16 tscl_binary_rotate_left16(bitwise16 a, bitwise_shift shift);
bitwise16 tscl_binary_rotate_right16(bitwise16 a, bitwise_shift shift);
int tscl_binary_is_bit_set16(bitwise16 a, int bit_position);
int tscl_binary_get_bit_value16(bitwise16 a, int bit_position);
bitwise16 tscl_binary_set_bit16(bitwise16 a, int bit_position);
bitwise16 tscl_binary_clear_bit16(bitwise16 a, int bit_position);
bitwise16 tscl_binary_update_bit16(bitwise16 a, int bit_position, int new_value);
bitwise32 tscl_binary_and32(bitwise32 a, bitwise32 b);
bitwise32 tscl_binary_or32(bitwise32 a, bitwise32 b);
bitwise32 tscl_binary_xor32(bitwise32 a, bitwise32 b);
bitwise32 tscl_binary_left_shift32(bitwise32 a, bitwise_shift shift);
bitwise32 tscl_binary_right_shift32(bitwise32 a, bitwise_shift shift);
int tscl_binary_count_set_bits32(bitwise32 a);
bitwise32 tscl_binary_toggle_bits32(bitwise32 a);
bitwise32 tscl_binary_rotate_left32(bitwise32 a, bitwise_shift shift);
bitwise32 tscl_binary_rotate_right32(bitwise32 a, bitwise_shift shift);
int tscl_binary_is_bit_set32(bitwise32 a, int bit_position);
int tscl_binary_get_bit_value32(bitwise32 a, int bit_position);
bitwise32 tscl_binary_set_bit32(bitwise32 a, int bit_position);
bitwise32 tscl_binary_clear_bit32(bitwise32 a, int bit_position);
bitwise32 tscl_binary_update_bit32(bitwise32 a, int bit_position, int new_value);
bitwise64 tscl_binary_and64(bitwise64 a, bitwise64 b);
bitwise64 tscl_binary_or64(bitwise64 a, bitwise64 b);
bitwise64 tscl_binary_xor64(bitwise64 a, bitwise64 b);
bitwise64 tscl_binary_left_shift64(bitwise64 a, bitwise_shift shift);
bitwise64 tscl_binary_right_shift64(bitwise64 a, bitwise_shift shift);
int tscl_binary_count_set_bits64(bitwise64 a);
bitwise64 tscl_binary_toggle_bits64(bitwise64 a);
bitwise64 tscl_binary_rotate_left64(bitwise64 a, bitwise_shift shift);
bitwise64 tscl_binary_rotate_right64(bitwise64 a, bitwise_shift shift);
int tscl_binary_is_bit_set64(bitwise64 a, int bit_position);
int tscl_binary_get_bit_value64(bitwise64 a, int bit_position);
bitwise64 tscl_binary_set_bit64(bitwise64 a, int bit_position);
bitwise64 tscl_binary_clear_bit64(bitwise64 a, int bit_position);
bitwise64 tscl_binary_update_bit64(bitwise64 a, int bit_position, int new_value);

#ifdef __cplusplus
}
#endif

#endif
