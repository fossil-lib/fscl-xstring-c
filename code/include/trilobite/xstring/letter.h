/*
   This C header file is part of the Trilobite Stdlib, a collection of utility functions and
   standard data structures for enhancing software development projects. Feel free to use
   and modify these utilities to streamline your software development process.

   Project: Trilobite Stdlib
   Author: Michael Gene Brockus (Dreamer)
   Email: michaelbrockus@gmail.com
   Website: [Trilobite Coder Blog](https://trilobite.home.blog)

   Trilobite Stdlib is designed to provide a robust set of functionalities that can be
   incorporated into various projects. The utilities included in this library aim to optimize
   and standardize common operations, ensuring efficient and reliable code.

   This header file is a part of a broader initiative to support developers in creating secure,
   efficient, and scalable software. Contributions, suggestions, and feedback are welcomed,
   as we strive to continuously improve and expand the capabilities of Trilobite Stdlib.

   License: Apache License 2.0
   SPDX Identifier: Apache-2.0

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software distributed under the License
   is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
   or implied. See the License for the specific language governing permissions and limitations
   under the License.

   The above copyright notice and this permission notice shall be included in all copies or
   substantial portions of the Software.

   Please review the full text of the Apache License 2.0 for the complete terms and conditions.

   (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
*/
#ifndef TSCL_LETTER_H
#define TSCL_LETTER_H

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
int tscl_letter_is_vowel(letter c);
int tscl_letter_is_consonant(letter c);
letter tscl_letter_to_lowercase(letter c);
letter tscl_letter_to_uppercase(letter c);
size_t tscl_letter_count_in_string(const_letter *str, letter target);
int tscl_letter_is_digit(letter c);
int tscl_letter_is_alnum(letter c);
int tscl_letter_is_alpha(letter c);
letter tscl_letter_toggle_case(letter c);
letter tscl_letter_rot13(letter c);
void tscl_letter_remove_char(letter *str, letter target);
void tscl_letter_replace_char(letter *str, letter target, letter replacement);
void tscl_letter_trim_whitespace(letter *str);
void tscl_letter_reverse_string(letter *str);
letter *tscl_letter_find_first(letter *str, letter target);
letter *tscl_letter_find_last(letter *str, letter target);
letter **tscl_letter_split_string(const_letter *str, letter delimiter, size_t *num_tokens);
letter *tscl_letter_join_strings(const letter **tokens, size_t num_tokens, letter delimiter);
void tscl_letter_char_frequency(const_letter *str, int *frequency);
int tscl_letter_is_punctuation(letter c);
int tscl_letter_is_whitespace(letter c);
void tscl_letter_remove_punctuation(letter *str);
void tscl_letter_remove_whitespace(letter *str);
void tscl_letter_replace_whitespace(letter *str, letter replacement);
void tscl_letter_remove_consecutive_duplicates(letter *str);
void tscl_letter_capitalize_words(letter *str);
int tscl_letter_is_printable(letter c);
int tscl_letter_to_ascii(letter c);
letter tscl_letter_ascii_to_letter(ascii ascii_value);
void tscl_letter_shift_string(letter *str, int shift_amount);

#ifdef __cplusplus
}
#endif

#endif
