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
#ifndef fscl_WYGSTRING_H
#define fscl_WYGSTRING_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>

typedef struct {
    char* text;
    int length;
} cwygstring;

// =================================================================
// Available functions
// =================================================================
cwygstring* fscl_wygstring_create(const char* text);
void fscl_wygstring_set_text(cwygstring* wygstring, const char* text);
const char* fscl_wygstring_get_text(const cwygstring* wygstring);
void fscl_wygstring_erase(cwygstring* wygstring);
void fscl_wygstring_append_text(cwygstring* wygstring, const char* text_to_append);
void fscl_wygstring_insert_text(cwygstring* wygstring, int position, const char* text_to_insert);
void fscl_wygstring_make_bold(cwygstring* wygstring, int start, int end);
void fscl_wygstring_make_italic(cwygstring* wygstring, int start, int end);
void fscl_wygstring_make_underlined(cwygstring* wygstring, int start, int end);
int fscl_wygstring_compare(const cwygstring* str1, const cwygstring* str2);
void fscl_wygstring_concat(cwygstring* dest, const cwygstring* src);
cwygstring* fscl_wygstring_copy(const cwygstring* wygstring);
int fscl_wygstring_length(const cwygstring* wygstring);
void fscl_wygstring_trim(cwygstring* wygstring);
void fscl_wygstring_to_lowercase(cwygstring* wygstring);
void fscl_wygstring_to_uppercase(cwygstring* wygstring);
void fscl_wygstring_replace_text(cwygstring* wygstring, int start, int end, const char* replacement);

#ifdef __cplusplus
}
#endif

#endif
