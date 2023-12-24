/*  ----------------------------------------------------------------------------
    File: sortable.c

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
#include "trilobite/xutil/sortable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Utility function to swap two tscl_sortable values
void tscl_sortable_swap(csortable *a, csortable *b) {
    csortable temp = *a;
    *a = *b;
    *b = temp;
}

// Function to compare two csortable values
int tscl_sortable_compare(const csortable *a, const csortable *b) {
    // Implement your comparison logic based on the data type
    if (a->integer < b->integer) return -1;
    if (a->integer > b->integer) return 1;
    return 0;
}

// Function to perform insertion sort on an array of csortable values
void tscl_sortable_insertion_sort(csortable *arr, int size) {
    int i, j;
    csortable key;

    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        // Compare and move elements greater than key
        while (j >= 0 && tscl_sortable_compare(&arr[j], &key) > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

// Function to perform quicksort on an array of csortable values
void tscl_sortable_quicksort(csortable *arr, int low, int high) {
    if (low < high) {
        int pi = tscl_sortable_quicksort_partition(arr, low, high);
        tscl_sortable_quicksort(arr, low, pi - 1);
        tscl_sortable_quicksort(arr, pi + 1, high);
    }
}

// Utility function for quicksort to partition the array
int tscl_sortable_quicksort_partition(csortable *arr, int low, int high) {
    csortable pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (tscl_sortable_compare(&arr[j], &pivot) <= 0) {
            i++;
            tscl_sortable_swap(&arr[i], &arr[j]);
        }
    }

    tscl_sortable_swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to perform bubblesort on an array of csortable values
void tscl_sortable_bubblesort(csortable *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (tscl_sortable_compare(&arr[j], &arr[j + 1]) > 0) {
                tscl_sortable_swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Utility function for merge sort to merge two subarrays
void tscl_sortable_merge(csortable *arr, int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Create temporary arrays
    csortable *left = (csortable *)malloc(n1 * sizeof(csortable));
    csortable *right = (csortable *)malloc(n2 * sizeof(csortable));

    // Copy data to temporary arrays left[] and right[]
    for (i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[low..high]
    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2) {
        if (tscl_sortable_compare(&left[i], &right[j]) <= 0) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[], if there are any
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[], if there are any
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }

    // Free temporary arrays
    free(left);
    free(right);
}

// Function to perform merge sort on an array of csortable values
void tscl_sortable_merge_sort(csortable *arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        tscl_sortable_merge_sort(arr, low, mid);
        tscl_sortable_merge_sort(arr, mid + 1, high);
        tscl_sortable_merge(arr, low, mid, high);
    }
}

// Function to perform selection sort on an array of csortable values
void tscl_sortable_selection_sort(csortable *arr, int size) {
    int i, j, min_index;
    for (i = 0; i < size - 1; i++) {
        min_index = i;
        for (j = i + 1; j < size; j++) {
            if (tscl_sortable_compare(&arr[j], &arr[min_index]) < 0) {
                min_index = j;
            }
        }
        tscl_sortable_swap(&arr[min_index], &arr[i]);
    }
}

// Function to determine the appropriate sorting algorithm based on the size
void tscl_sortable_auto(csortable *arr, int size) {
    if (size < 10) {
        tscl_sortable_insertion_sort(arr, size);
    } else if (size < 100) {
        tscl_sortable_selection_sort(arr, size);
    } else if (size < 1000) {
        tscl_sortable_quicksort(arr, 0, size - 1);
    } else {
        tscl_sortable_merge_sort(arr, 0, size - 1);
    }
}

// Function to print the array to the console
void tscl_sortable_console_out(const csortable *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i].integer) {
            printf("%d ", arr[i].integer);
        } else {
            printf("%s ", arr[i].cstring);
        }
    }
    printf("\n");
}
