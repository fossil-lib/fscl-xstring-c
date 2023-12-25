/*  ----------------------------------------------------------------------------
    File: string.c

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
#include "trilobite/xstring/utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create and allocate memory for a cstring
cstring tscl_string_create(const char* initial_value) {
    cstring new_string = (cstring)malloc(strlen(initial_value) + 1);
    if (new_string == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_string, initial_value);
    return new_string;
}

// Erase memory for a cstring
void tscl_string_erase(cstring str) {
    free(str);
}

// Create and allocate memory for a cstrings array
cstrings tscl_strings_create(int size) {
    cstrings new_strings = (cstrings)malloc(size * sizeof(cstring));
    if (new_strings == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; ++i) {
        new_strings[i] = NULL; // Initialize each string pointer to NULL
    }
    return new_strings;
}

// Erase memory for a cstrings array
void tscl_strings_erase(cstrings strings, int size) {
    for (int i = 0; i < size; ++i) {
        tscl_string_erase(strings[i]); // Erase each cstring in the array
    }
    free(strings);
}

// Create and allocate memory for a const_cstring
const_cstring tscl_const_string_create(const char* initial_value) {
    const_cstring new_string = (const_cstring)malloc(strlen(initial_value) + 1);
    if (new_string == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy((char*)new_string, initial_value);
    return new_string;
}

// Erase memory for a const_cstring
void tscl_const_string_erase(const_cstring str) {
    free((void*)str);
}

// Create and allocate memory for a const_cstrings array
const_cstrings tscl_const_strings_create(int size) {
    const_cstrings new_strings = (const_cstrings)malloc(size * sizeof(const_cstring));
    if (new_strings == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; ++i) {
        new_strings[i] = NULL; // Initialize each const_cstring pointer to NULL
    }
    return new_strings;
}

// Erase memory for a const_cstrings array
void tscl_const_strings_erase(const_cstrings strings, int size) {
    for (int i = 0; i < size; ++i) {
        tscl_const_string_erase(strings[i]); // Erase each const_cstring in the array
    }
    free(strings);
}
