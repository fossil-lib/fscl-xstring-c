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
#ifndef fscl_LETTER_H
#define fscl_LETTER_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>

typedef int ascii;
typedef char letter;
typedef const char const_letter;

// =================================================================
// Available functions
// =================================================================
int fscl_letter_is_vowel(letter c);
int fscl_letter_is_consonant(letter c);
letter fscl_letter_to_lowercase(letter c);
letter fscl_letter_to_uppercase(letter c);
size_t fscl_letter_count_in_string(const_letter *str, letter target);
int fscl_letter_is_digit(letter c);
int fscl_letter_is_alnum(letter c);
int fscl_letter_is_alpha(letter c);
letter fscl_letter_toggle_case(letter c);
letter fscl_letter_rot13(letter c);
void fscl_letter_remove_char(letter *str, letter target);
void fscl_letter_replace_char(letter *str, letter target, letter replacement);
void fscl_letter_trim_whitespace(letter *str);
void fscl_letter_reverse_string(letter *str);
letter *fscl_letter_find_first(letter *str, letter target);
letter *fscl_letter_find_last(letter *str, letter target);
letter **fscl_letter_split_string(const_letter *str, letter delimiter, size_t *num_tokens);
letter *fscl_letter_join_strings(const letter **tokens, size_t num_tokens, letter delimiter);
void fscl_letter_char_frequency(const_letter *str, int *frequency);
int fscl_letter_is_punctuation(letter c);
int fscl_letter_is_whitespace(letter c);
void fscl_letter_remove_punctuation(letter *str);
void fscl_letter_remove_whitespace(letter *str);
void fscl_letter_replace_whitespace(letter *str, letter replacement);
void fscl_letter_remove_consecutive_duplicates(letter *str);
void fscl_letter_capitalize_words(letter *str);
int fscl_letter_is_printable(letter c);
int fscl_letter_to_ascii(letter c);
letter fscl_letter_ascii_to_letter(ascii ascii_value);
void fscl_letter_shift_string(letter *str, int shift_amount);

#ifdef __cplusplus
}
#endif

#endif
