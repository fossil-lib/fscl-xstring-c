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
#ifndef fscl_UTIL_H
#define fscl_UTIL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>
#include <fossil/xstring/cstring.h>

// =================================================================
// Available functions
// =================================================================
size_t fscl_string_length(const_cstring str);
cstring fscl_string_copy(const_cstring src);
cstring fscl_string_concat(const_cstring str1, const_cstring str2);
int fscl_string_compare(const_cstring str1, const_cstring str2);
cstring fscl_string_substr(const_cstring str, size_t start, size_t length);
int fscl_string_find(const_cstring str, const_cstring substr);
int fscl_string_rfind(const_cstring str, const_cstring substr);
cstring *fscl_string_split(const_cstring str, const_cstring delimiter);
cstring fscl_string_to_upper(const_cstring str);
cstring fscl_string_to_lower(const_cstring str);
cstring fscl_string_trim(const_cstring str);
cstring fscl_string_reverse(const_cstring str);
cstring fscl_string_replace(cstring str, const_cstring find, const_cstring replace);
cstring fscl_string_shuffle(const_cstring str);
cstring fscl_string_make_silly(const_cstring str);
cstring fscl_string_strdup(const_cstring str);
int fscl_string_starts_with(const_cstring str, const_cstring prefix);
int fscl_string_ends_with(const_cstring str, const_cstring suffix);
cstring fscl_string_pad(const_cstring str, size_t length, char padding_char);
cstring fscl_string_remove_char(const_cstring str, char char_to_remove);
size_t fscl_string_count_substring(cstring str, const_cstring substr);
cstring fscl_string_reverse_words(const_cstring str);
cstring fscl_string_to_title_case(const_cstring str);
cstring fscl_string_remove_consecutive_duplicates(const_cstring str);
cstring fscl_string_remove_extra_spaces(const_cstring str);

#ifdef __cplusplus
}
#endif

#endif
