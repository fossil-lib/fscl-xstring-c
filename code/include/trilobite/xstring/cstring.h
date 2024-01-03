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
// Available functions
// =================================================================
cstring fscl_string_create(const char* initial_value);
cstrings fscl_strings_create(int size);
const_cstring fscl_const_string_create(const char* initial_value);
const_cstrings fscl_const_strings_create(int size);
void fscl_string_erase(cstring str);
void fscl_strings_erase(cstrings strings, int size);
void fscl_const_string_erase(const_cstring str);
void fscl_const_strings_erase(const_cstrings strings, int size);

#ifdef __cplusplus
}
#endif

#endif
