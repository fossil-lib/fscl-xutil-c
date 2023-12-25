/*  ----------------------------------------------------------------------------
    File: bitwise.c

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
#include "trilobite/xutil/bitwise.h"
#include <stdio.h>

bitwise tscl_binary_reverse_bits(bitwise a) {
    int i, j;
    bitwise result = 0;

    for (i = 0, j = 31; i < 32; ++i, --j) {
        result |= ((a >> i) & 1) << j;
    }

    return result;
} // end of func

bitwise tscl_binary_set_bits_to_position(bitwise a, int position) {
    if (position < 0 || position >= 32) {
        return 0;
    }

    return (1u << (position + 1)) - 1;
} // end of func

int tscl_binary_count_leading_zeros(bitwise a) {
    int count = 0;

    while ((a & 0x80000000u) == 0) {
        ++count;
        a <<= 1;
    }

    return count;
} // end of func

int tscl_binary_count_trailing_zeros(bitwise a) {
    int count = 0;

    while ((a & 1u) == 0) {
        ++count;
        a >>= 1;
    }

    return count;
} // end of func

void tscl_binary_swap_values(bitwise* a, bitwise* b) {
    if (a != b) {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
} // end of func

void tscl_binary_bitmap(bitwise a) {
    for (int i = 31; i >= 0; --i) {
        printf("%d ", '0' + ((a >> i) & 1));
    }
    printf("\n");
} // end of func

void tscl_bitwise8_bitmap(bitwise8 a) {
    for (int i = 7; i >= 0; --i) {
        printf("%d ", '0' + ((a >> i) & 1));
    }
    printf("\n");
} // end of func

void tscl_bitwise16_bitmap(bitwise16 a) {
    for (int i = 15; i >= 0; --i) {
        printf("%d ", '0' + ((a >> i) & 1));
    }
    printf("\n");
} // end of func

void tscl_bitwise32_bitmap(bitwise32 a) {
    for (int i = 31; i >= 0; --i) {
        printf("%d ", '0' + ((a >> i) & 1));
    }
    printf("\n");
} // end of func

void tscl_bitwise64_bitmap(bitwise64 a) {
    for (int i = 63; i >= 0; --i) {
        printf("%llu ", '0' + (unsigned long long int)((a >> i) & 1));
    }
    printf("\n");
} // end of func

// Output the binary representation of a 32-bit binary number.
void tscl_binary_output(bitwise a) {
    for (int i = 31; i >= 0; --i) {
        putchar('0' + ((a >> i) & 1));
    }
    putchar('\n');
} // end of func

// Output the binary representation of an 8-bit binary number.
void tscl_bitwise8_output(bitwise8 a) {
    for (int i = 7; i >= 0; --i) {
        putchar('0' + ((a >> i) & 1));
    }
    putchar('\n');
} // end of func

// Output the binary representation of a 16-bit binary number.
void tscl_bitwise16_output(bitwise16 a) {
    for (int i = 15; i >= 0; --i) {
        putchar('0' + ((a >> i) & 1));
    }
    putchar('\n');
} // end of func

// Output the binary representation of a 32-bit binary number.
void tscl_bitwise32_output(bitwise32 a) {
    for (int i = 31; i >= 0; --i) {
        putchar('0' + ((a >> i) & 1));
    }
    putchar('\n');
} // end of func

// Output the binary representation of a 64-bit binary number.
void tscl_bitwise64_output(bitwise64 a) {
    for (int i = 63; i >= 0; --i) {
        putchar('0' + ((a >> i) & 1));
    }
    putchar('\n');
} // end of func

// Binary operations for bitwise8
bitwise8 tscl_binary_and8(bitwise8 a, bitwise8 b) {
    return a & b;
} // end of func

bitwise8 tscl_binary_or8(bitwise8 a, bitwise8 b) {
    return a | b;
} // end of func

bitwise8 tscl_binary_xor8(bitwise8 a, bitwise8 b) {
    return a ^ b;
} // end of func

bitwise8 tscl_binary_left_shift8(bitwise8 a, bitwise_shift shift) {
    return a << shift;
} // end of func

bitwise8 tscl_binary_right_shift8(bitwise8 a, bitwise_shift shift) {
    return a >> shift;
} // end of func

int tscl_binary_count_set_bits8(bitwise8 a) {
    return __builtin_popcount(a);
} // end of func

bitwise8 tscl_binary_toggle_bits8(bitwise8 a) {
    return ~a;
} // end of func

bitwise8 tscl_binary_rotate_left8(bitwise8 a, bitwise_shift shift) {
    return (a << shift) | (a >> (8 - shift));
} // end of func

bitwise8 tscl_binary_rotate_right8(bitwise8 a, bitwise_shift shift) {
    return (a >> shift) | (a << (8 - shift));
} // end of func

int tscl_binary_is_bit_set8(bitwise8 a, int bit_position) {
    return (a & (1 << bit_position)) != 0;
} // end of func

int tscl_binary_get_bit_value8(bitwise8 a, int bit_position) {
    return (a >> bit_position) & 1;
} // end of func

bitwise8 tscl_binary_set_bit8(bitwise8 a, int bit_position) {
    return a | (1 << bit_position);
} // end of func

bitwise8 tscl_binary_clear_bit8(bitwise8 a, int bit_position) {
    return a & ~(1 << bit_position);
} // end of func

bitwise8 tscl_binary_update_bit8(bitwise8 a, int bit_position, int new_value) {
    return (a & ~(1 << bit_position)) | (new_value << bit_position);
} // end of func

// Binary operations for bitwise16
bitwise16 tscl_binary_and16(bitwise16 a, bitwise16 b) {
    return a & b;
} // end of func

bitwise16 tscl_binary_or16(bitwise16 a, bitwise16 b) {
    return a | b;
} // end of func

bitwise16 tscl_binary_xor16(bitwise16 a, bitwise16 b) {
    return a ^ b;
} // end of func

bitwise16 tscl_binary_left_shift16(bitwise16 a, bitwise_shift shift) {
    return a << shift;
} // end of func

bitwise16 tscl_binary_right_shift16(bitwise16 a, bitwise_shift shift) {
    return a >> shift;
} // end of func

int tscl_binary_count_set_bits16(bitwise16 a) {
    return __builtin_popcount(a);
} // end of func

bitwise16 tscl_binary_toggle_bits16(bitwise16 a) {
    return ~a;
} // end of func

bitwise16 tscl_binary_rotate_left16(bitwise16 a, bitwise_shift shift) {
    return (a << shift) | (a >> (16 - shift));
} // end of func

bitwise16 tscl_binary_rotate_right16(bitwise16 a, bitwise_shift shift) {
    return (a >> shift) | (a << (16 - shift));
} // end of func

int tscl_binary_is_bit_set16(bitwise16 a, int bit_position) {
    return (a & (1 << bit_position)) != 0;
} // end of func

int tscl_binary_get_bit_value16(bitwise16 a, int bit_position) {
    return (a >> bit_position) & 1;
} // end of func

bitwise16 tscl_binary_set_bit16(bitwise16 a, int bit_position) {
    return a | (1 << bit_position);
} // end of func

bitwise16 tscl_binary_clear_bit16(bitwise16 a, int bit_position) {
    return a & ~(1 << bit_position);
} // end of func

bitwise16 tscl_binary_update_bit16(bitwise16 a, int bit_position, int new_value) {
    return (a & ~(1 << bit_position)) | (new_value << bit_position);
} // end of func

// Binary operations for bitwise32
bitwise32 tscl_binary_and32(bitwise32 a, bitwise32 b) {
    return a & b;
} // end of func

bitwise32 tscl_binary_or32(bitwise32 a, bitwise32 b) {
    return a | b;
} // end of func

bitwise32 tscl_binary_xor32(bitwise32 a, bitwise32 b) {
    return a ^ b;
} // end of func

bitwise32 tscl_binary_left_shift32(bitwise32 a, bitwise_shift shift) {
    return a << shift;
} // end of func

bitwise32 tscl_binary_right_shift32(bitwise32 a, bitwise_shift shift) {
    return a >> shift;
} // end of func

int tscl_binary_count_set_bits32(bitwise32 a) {
    return __builtin_popcountl(a);
} // end of func

bitwise32 tscl_binary_toggle_bits32(bitwise32 a) {
    return ~a;
} // end of func

bitwise32 tscl_binary_rotate_left32(bitwise32 a, bitwise_shift shift) {
    return (a << shift) | (a >> (32 - shift));
} // end of func

bitwise32 tscl_binary_rotate_right32(bitwise32 a, bitwise_shift shift) {
    return (a >> shift) | (a << (32 - shift));
} // end of func

int tscl_binary_is_bit_set32(bitwise32 a, int bit_position) {
    return (a & (1U << bit_position)) != 0;
} // end of func

int tscl_binary_get_bit_value32(bitwise32 a, int bit_position) {
    return (a >> bit_position) & 1;
} // end of func

bitwise32 tscl_binary_set_bit32(bitwise32 a, int bit_position) {
    return a | (1U << bit_position);
} // end of func

bitwise32 tscl_binary_clear_bit32(bitwise32 a, int bit_position) {
    return a & ~(1U << bit_position);
} // end of func

bitwise32 tscl_binary_update_bit32(bitwise32 a, int bit_position, int new_value) {
    return (a & ~(1U << bit_position)) | (new_value << bit_position);
} // end of func

// Binary operations for bitwise64
bitwise64 tscl_binary_and64(bitwise64 a, bitwise64 b) {
    return a & b;
} // end of func

bitwise64 tscl_binary_or64(bitwise64 a, bitwise64 b) {
    return a | b;
} // end of func

bitwise64 tscl_binary_xor64(bitwise64 a, bitwise64 b) {
    return a ^ b;
} // end of func

bitwise64 tscl_binary_left_shift64(bitwise64 a, bitwise_shift shift) {
    return a << shift;
} // end of func

bitwise64 tscl_binary_right_shift64(bitwise64 a, bitwise_shift shift) {
    return a >> shift;
} // end of func

int tscl_binary_count_set_bits64(bitwise64 a) {
    return __builtin_popcountll(a);
} // end of func

bitwise64 tscl_binary_toggle_bits64(bitwise64 a) {
    return ~a;
} // end of func

bitwise64 tscl_binary_rotate_left64(bitwise64 a, bitwise_shift shift) {
    return (a << shift) | (a >> (64 - shift));
} // end of func

bitwise64 tscl_binary_rotate_right64(bitwise64 a, bitwise_shift shift) {
    return (a >> shift) | (a << (64 - shift));
} // end of func

int tscl_binary_is_bit_set64(bitwise64 a, int bit_position){
    return (a & (1ULL << bit_position)) != 0;
} // end of func

int tscl_binary_get_bit_value64(bitwise64 a, int bit_position) {
    return (a >> bit_position) & 1;
}

bitwise64 tscl_binary_set_bit64(bitwise64 a, int bit_position) {
    return a | (1ULL << bit_position);
}  // end of func

bitwise64 tscl_binary_clear_bit64(bitwise64 a, int bit_position) {
    return a & ~(1ULL << bit_position);
} // end of func

bitwise64 tscl_binary_update_bit64(bitwise64 a, int bit_position, int new_value) {
    return (a & ~(1ULL << bit_position)) | (new_value << bit_position);
} // end of func

// Bitwise AND operation
bitwise tscl_binary_and(bitwise a, bitwise b) {
    return a & b;
} // end of func

// Bitwise OR operation
bitwise tscl_binary_or(bitwise a, bitwise b) {
    return a | b;
} // end of func

// Bitwise XOR operation
bitwise tscl_binary_xor(bitwise a, bitwise b) {
    return a ^ b;
} // end of func

// Left shift operation
bitwise tscl_binary_left_shift(bitwise a, bitwise_shift shift) {
    return a << shift;
} // end of func

// Right shift operation
bitwise tscl_binary_right_shift(bitwise a, bitwise_shift shift) {
    return a >> shift;
} // end of func

// Count the number of set bits (1s) in a binary number
int tscl_binary_count_set_bits(bitwise a) {
    int count = 0;
    while (a) {
        count += a & 1;
        a >>= 1;
    } // end while
    return count;
} // end of func

// Toggle (invert) all bits in a binary number
bitwise tscl_binary_toggle_bits(bitwise a) {
    return ~a;
} // end of func

// Rotate left (circular left shift) operation
bitwise tscl_binary_rotate_left(bitwise a, bitwise_shift shift) {
    return (a << shift) | (a >> (32 - shift));
} // end of func

// Rotate right (circular right shift) operation
bitwise tscl_binary_rotate_right(bitwise a, bitwise_shift shift) {
    return (a >> shift) | (a << (32 - shift));
} // end of func

// Check if a specific bit is set in a binary number
int tscl_binary_is_bit_set(bitwise a, int bit_position) {
    return (a & (1u << bit_position)) != 0;
} // end of func

int tscl_binary_get_bit_value(bitwise a, int bit_position) {
    return (a >> bit_position) & 1;
} // end of func

bitwise tscl_binary_set_bit(bitwise a, int bit_position) {
    return a | (1u << bit_position);
} // end of func

bitwise tscl_binary_clear_bit(bitwise a, int bit_position) {
    return a & ~(1u << bit_position);
} // end of func

bitwise tscl_binary_update_bit(bitwise a, int bit_position, int new_value) {
    return (a & ~(1u << bit_position)) | (new_value << bit_position);
} // end of func
