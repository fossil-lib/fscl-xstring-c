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
#ifndef fscl_NLP_H
#define fscl_NLP_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>
#include <fossil/xstring/cstring.h>

// =================================================================
// Available functions
// =================================================================
size_t fscl_string_lang_length(cstring str);
cstring fscl_string_lang_concat(cstring str1, cstring str2);
size_t fscl_string_lang_count_words(cstring sentence);
char** fscl_string_lang_tokenize(cstring sentence, size_t* tokenCount);
cstring fscl_string_lang_detect_language(cstring sentence);
void fscl_string_lang_to_lowercase(cstring str);
cstring fscl_string_lang_remove_stopwords(cstring sentence);

#ifdef __cplusplus
}
#endif

#endif
