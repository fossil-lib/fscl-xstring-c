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

/**
 * @brief Check if a character is a vowel.
 *
 * @param c The character to check.
 *
 * @return 1 if the character is a vowel, 0 otherwise.
 */
int letter_is_vowel(letter c);

/**
 * @brief Check if a character is a consonant.
 *
 * @param c The character to check.
 *
 * @return 1 if the character is a consonant, 0 otherwise.
 */
int letter_is_consonant(letter c);

/**
 * @brief Convert a character to lowercase.
 *
 * @param c The character to convert.
 *
 * @return The lowercase version of the character.
 */
letter letter_to_lowercase(letter c);

/**
 * @brief Convert a character to uppercase.
 *
 * @param c The character to convert.
 *
 * @return The uppercase version of the character.
 */
letter letter_to_uppercase(letter c);

/**
 * @brief Count the occurrences of a character in a string.
 *
 * @param str The input string.
 * @param target The character to count.
 *
 * @return The number of occurrences of the character in the string.
 */
size_t letter_count_in_string(const_letter *str, letter target);

/**
 * @brief Check if a character is a digit.
 *
 * @param c The character to check.
 *
 * @return 1 if the character is a digit, 0 otherwise.
 */
int letter_is_digit(letter c);

/**
 * @brief Check if a character is alphanumeric.
 *
 * @param c The character to check.
 *
 * @return 1 if the character is alphanumeric, 0 otherwise.
 */
int letter_is_alnum(letter c);

/**
 * @brief Check if a character is an alphabetic character (a-z or A-Z).
 *
 * @param c The character to check.
 *
 * @return 1 if the character is alphabetic, 0 otherwise.
 */
int letter_is_alpha(letter c);

/**
 * @brief Toggle the case of a character.
 *
 * @param c The character to toggle.
 *
 * @return The character with its case toggled.
 */
letter letter_toggle_case(letter c);

/**
 * @brief Perform ROT13 encoding/decoding on a character.
 *
 * @param c The character to encode/decode.
 *
 * @return The ROT13 encoded/decoded character.
 */
letter letter_rot13(letter c);

/**
 * @brief Remove all occurrences of a character from a string.
 *
 * @param str The input string (modified in-place).
 * @param target The character to remove.
 */
void letter_remove_char(letter *str, letter target);

/**
 * @brief Replace all occurrences of a character with another character in a string.
 *
 * @param str The input string (modified in-place).
 * @param target The character to replace.
 * @param replacement The character to replace with.
 */
void letter_replace_char(letter *str, letter target, letter replacement);

/**
 * @brief Trim leading and trailing whitespace characters from a string.
 *
 * @param str The input string (modified in-place).
 */
void letter_trim_whitespace(letter *str);

/**
 * @brief Reverse a string in-place.
 *
 * @param str The input string (modified in-place).
 */
void letter_reverse_string(letter *str);

/**
 * @brief Find the first occurrence of a character in a string.
 *
 * @param str The input string.
 * @param target The character to find.
 *
 * @return A pointer to the first occurrence of the character in the string, or NULL if not found.
 */
letter *letter_find_first(letter *str, letter target);

/**
 * @brief Find the last occurrence of a character in a string.
 *
 * @param str The input string.
 * @param target The character to find.
 *
 * @return A pointer to the last occurrence of the character in the string, or NULL if not found.
 */
letter *letter_find_last(letter *str, letter target);

/**
 * @brief Split a string into an array of substrings based on a delimiter character.
 *
 * @param str The input string to split.
 * @param delimiter The delimiter character.
 * @param num_tokens Pointer to a variable to store the number of tokens found.
 *
 * @return An array of strings (tokens) created by splitting the input string. 
 *         Remember to free the allocated memory when done.
 */
letter **letter_split_string(const_letter *str, letter delimiter, size_t *num_tokens);

/**
 * @brief Join an array of strings into a single string using a delimiter character.
 *
 * @param tokens An array of strings to join.
 * @param num_tokens The number of tokens in the array.
 * @param delimiter The delimiter character to insert between tokens.
 *
 * @return A newly allocated string that is the result of joining the input strings.
 *         Remember to free the allocated memory when done.
 */
letter *letter_join_strings(const letter **tokens, size_t num_tokens, letter delimiter);

/**
 * @brief Calculate the frequency of each character in a string.
 *
 * @param str The input string.
 * @param frequency An array to store the frequency of each character (indexed by ASCII value).
 *                 The array should be at least 128 elements long.
 */
void letter_char_frequency(const_letter *str, int *frequency);

/**
 * @brief Check if a character is a punctuation mark.
 *
 * @param c The character to check.
 *
 * @return 1 if the character is a punctuation mark, 0 otherwise.
 */
int letter_is_punctuation(letter c);

/**
 * @brief Check if a character is a whitespace character.
 *
 * @param c The character to check.
 *
 * @return 1 if the character is a whitespace character, 0 otherwise.
 */
int letter_is_whitespace(letter c);

/**
 * @brief Remove all occurrences of punctuation marks from a string.
 *
 * @param str The input string (modified in-place).
 */
void letter_remove_punctuation(letter *str);

/**
 * @brief Remove all occurrences of whitespace characters from a string.
 *
 * @param str The input string (modified in-place).
 */
void letter_remove_whitespace(letter *str);

/**
 * @brief Replace all occurrences of whitespace characters with a specified character in a string.
 *
 * @param str The input string (modified in-place).
 * @param replacement The character to replace whitespace with.
 */
void letter_replace_whitespace(letter *str, letter replacement);

/**
 * @brief Remove consecutive duplicate characters from a string.
 *
 * @param str The input string (modified in-place).
 */
void letter_remove_consecutive_duplicates(letter *str);

/**
 * @brief Capitalize the first letter of each word in a string.
 *
 * @param str The input string (modified in-place).
 */
void letter_capitalize_words(letter *str);

/**
 * @brief Check if a character is a printable ASCII character.
 *
 * @param c The character to check.
 *
 * @return 1 if the character is a printable ASCII character, 0 otherwise.
 */
int letter_is_printable(letter c);

/**
 * @brief Convert a character to its ASCII value.
 *
 * @param c The character to convert.
 *
 * @return The ASCII value of the character.
 */
int letter_to_ascii(letter c);

/**
 * @brief Convert an ASCII value to a character.
 *
 * @param ascii_value The ASCII value to convert.
 *
 * @return The character corresponding to the ASCII value.
 */
letter letter_ascii_to_letter(ascii ascii_value);

/**
 * @brief Shift the characters in a string by a specified amount.
 *
 * @param str The input string (modified in-place).
 * @param shift_amount The amount to shift the characters.
 */
void letter_shift_string(letter *str, int shift_amount);

#ifdef __cplusplus
}
#endif

#endif
