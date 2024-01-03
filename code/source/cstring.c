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
#include "fossil/xstring/utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create and allocate memory for a cstring
cstring fscl_string_create(const char* initial_value) {
    cstring new_string = (cstring)malloc(strlen(initial_value) + 1);
    if (new_string == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_string, initial_value);
    return new_string;
}

// Erase memory for a cstring
void fscl_string_erase(cstring str) {
    free(str);
}

// Create and allocate memory for a cstrings array
cstrings fscl_strings_create(int size) {
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
void fscl_strings_erase(cstrings strings, int size) {
    for (int i = 0; i < size; ++i) {
        fscl_string_erase(strings[i]); // Erase each cstring in the array
    }
    free(strings);
}

// Create and allocate memory for a const_cstring
const_cstring fscl_const_string_create(const char* initial_value) {
    const_cstring new_string = (const_cstring)malloc(strlen(initial_value) + 1);
    if (new_string == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy((char*)new_string, initial_value);
    return new_string;
}

// Erase memory for a const_cstring
void fscl_const_string_erase(const_cstring str) {
    free((void*)str);
}

// Create and allocate memory for a const_cstrings array
const_cstrings fscl_const_strings_create(int size) {
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
void fscl_const_strings_erase(const_cstrings strings, int size) {
    for (int i = 0; i < size; ++i) {
        fscl_const_string_erase(strings[i]); // Erase each const_cstring in the array
    }
    free(strings);
}
