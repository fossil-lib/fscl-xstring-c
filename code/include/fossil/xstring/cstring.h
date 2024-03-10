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
#ifndef fscl_STRING_H
#define fscl_STRING_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef char **cstrings;
typedef char *cstring;
typedef const char **const_cstrings;
typedef const char *const_cstring;

// =================================================================
// String and Strings Management Functions
// =================================================================

/**
 * Create a mutable string with the specified initial value.
 *
 * @param initial_value The initial value for the string.
 * @return The created mutable string.
 */
cstring fscl_string_create(const char* initial_value);

/**
 * Create an array of mutable strings with the specified size.
 *
 * @param size The size of the array.
 * @return The created array of mutable strings.
 */
cstrings fscl_strings_create(int size);

/**
 * Create an immutable string with the specified initial value.
 *
 * @param initial_value The initial value for the string.
 * @return The created immutable string.
 */
const_cstring fscl_const_string_create(const char* initial_value);

/**
 * Create an array of immutable strings with the specified size.
 *
 * @param size The size of the array.
 * @return The created array of immutable strings.
 */
const_cstrings fscl_const_strings_create(int size);

/**
 * Erase a mutable string and free its memory.
 *
 * @param str The mutable string to be erased.
 */
void fscl_string_erase(cstring str);

/**
 * Erase an array of mutable strings and free their memory.
 *
 * @param strings The array of mutable strings to be erased.
 * @param size    The size of the array.
 */
void fscl_strings_erase(cstrings strings, int size);

/**
 * Erase an immutable string (no memory deallocation as it's assumed to be a constant).
 *
 * @param str The immutable string to be erased.
 */
void fscl_const_string_erase(const_cstring str);

/**
 * Erase an array of immutable strings (no memory deallocation as they're assumed to be constants).
 *
 * @param strings The array of immutable strings to be erased.
 * @param size    The size of the array.
 */
void fscl_const_strings_erase(const_cstrings strings, int size);

#ifdef __cplusplus
}
#endif

#endif
