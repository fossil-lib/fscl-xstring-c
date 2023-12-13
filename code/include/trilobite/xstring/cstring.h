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
#ifndef TSCL_STRING_H
#define TSCL_STRING_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>

typedef char *cstring;
typedef const char *const_cstring;

/**
 * @brief Get the length of a string.
 *
 * This function calculates and returns the length of the input string.
 *
 * @param str The input string.
 * @return The length of the input string.
 */
size_t string_length(const_cstring str);

/**
 * @brief Copy a string.
 *
 * This function creates a copy of the input string and returns it.
 *
 * @param src The source string to be copied.
 * @return A dynamically allocated copy of the source string.
 */
cstring string_copy(const_cstring src);

/**
 * @brief Concatenate two strings.
 *
 * This function concatenates two input strings and returns the result.
 *
 * @param str1 The first string.
 * @param str2 The second string.
 * @return A dynamically allocated string containing the concatenation of str1 and str2.
 */
cstring string_concat(const_cstring str1, const_cstring str2);

/**
 * @brief Compare two strings.
 *
 * This function compares two input strings lexicographically.
 *
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @return An integer less than, equal to, or greater than zero if str1 is found to be less than, equal to, or greater than str2, respectively.
 */
int string_compare(const_cstring str1, const_cstring str2);

/**
 * @brief Free dynamically allocated string memory.
 *
 * This function frees the memory allocated for a dynamically allocated string.
 *
 * @param str The string whose memory needs to be freed.
 */
void string_erase(cstring str);

/**
 * @brief Extract a substring from a string.
 *
 * This function extracts a substring from the input string, starting at the specified position and of the specified length.
 *
 * @param str The input string.
 * @param start The starting position of the substring.
 * @param length The length of the substring to extract.
 * @return A dynamically allocated substring.
 */
cstring string_substr(const_cstring str, size_t start, size_t length);

/**
 * @brief Find the first occurrence of a substring in a string.
 *
 * This function searches for the first occurrence of the specified substring within the input string.
 *
 * @param str The input string.
 * @param substr The substring to search for.
 * @return The index of the first occurrence of the substring, or -1 if not found.
 */
int string_find(const_cstring str, const_cstring substr);

/**
 * @brief Find the last occurrence of a substring in a string.
 *
 * This function searches for the last occurrence of the specified substring within the input string.
 *
 * @param str The input string.
 * @param substr The substring to search for.
 * @return The index of the last occurrence of the substring, or -1 if not found.
 */
int string_rfind(const_cstring str, const_cstring substr);

/**
 * @brief Split a string into an array of substrings.
 *
 * This function splits the input string into an array of substrings based on the specified delimiter.
 *
 * @param str The input string to split.
 * @param delimiter The delimiter used for splitting.
 * @return An array of dynamically allocated substrings.
 */
cstring *string_split(const_cstring str, const_cstring delimiter);

/**
 * @brief Convert a string to uppercase.
 *
 * This function converts all characters in the input string to uppercase.
 *
 * @param str The input string to convert.
 * @return A dynamically allocated string in uppercase.
 */
cstring string_to_upper(const_cstring str);

/**
 * @brief Convert a string to lowercase.
 *
 * This function converts all characters in the input string to lowercase.
 *
 * @param str The input string to convert.
 * @return A dynamically allocated string in lowercase.
 */
cstring string_to_lower(const_cstring str);

/**
 * @brief Remove leading and trailing whitespace characters from a string.
 *
 * This function trims leading and trailing whitespace characters from the input string.
 *
 * @param str The input string to trim.
 * @return A dynamically allocated trimmed string.
 */
cstring string_trim(const_cstring str);

/**
 * @brief Reverse a string.
 *
 * This function reverses the characters in the input string.
 *
 * @param str The input string to reverse.
 * @return A dynamically allocated reversed string.
 */
cstring string_reverse(const_cstring str);

/**
 * @brief Replace all occurrences of a substring with another substring.
 *
 * This function replaces all occurrences of the specified substring with another substring within the input string.
 *
 * @param str The input string.
 * @param find The substring to find and replace.
 * @param replace The substring to replace 'find' with.
 * @return A dynamically allocated string with replacements made.
 */
cstring string_replace(cstring str, const_cstring find, const_cstring replace);

/**
 * @brief Shuffle the characters in a string.
 *
 * This function shuffles the characters in the input string.
 *
 * @param str The input string to shuffle.
 * @return A dynamically allocated shuffled string.
 */
cstring string_shuffle(const_cstring str);

/**
 * @brief Make a string silly by converting vowels to uppercase.
 *
 * This function converts vowels in the input string to uppercase, making it "silly."
 *
 * @param str The input string to make silly.
 * @return A dynamically allocated silly string.
 */
cstring string_make_silly(const_cstring str);

/**
 * @brief Duplicate a string.
 *
 * This function creates a duplicate of the input string using dynamic memory allocation.
 *
 * @param str The input string to be duplicated.
 * @return A dynamically allocated copy of the input string.
 *
 * @note The caller is responsible for freeing the memory allocated for the duplicated string
 *       using free() when it is no longer needed to prevent memory leaks.
 */
cstring string_strdup(const_cstring str);

/**
 * @brief Check if a string starts with a specified prefix.
 *
 * This function checks if the input string starts with the specified prefix.
 *
 * @param str The input string.
 * @param prefix The prefix to check.
 * @return 1 if the string starts with the prefix, 0 otherwise.
 */
int string_starts_with(const_cstring str, const_cstring prefix);

/**
 * @brief Check if a string ends with a specified suffix.
 *
 * This function checks if the input string ends with the specified suffix.
 *
 * @param str The input string.
 * @param suffix The suffix to check.
 * @return 1 if the string ends with the suffix, 0 otherwise.
 */
int string_ends_with(const_cstring str, const_cstring suffix);

/**
 * @brief Pad a string with a specified character to reach a certain length.
 *
 * This function pads the input string with a specified character to achieve a minimum length.
 *
 * @param str The input string.
 * @param length The target length of the padded string.
 * @param padding_char The character used for padding.
 * @return A dynamically allocated padded string.
 */
cstring string_pad(const_cstring str, size_t length, char padding_char);

/**
 * @brief Remove all occurrences of a specified character from a string.
 *
 * This function removes all occurrences of a specified character from the input string.
 *
 * @param str The input string.
 * @param char_to_remove The character to remove.
 * @return A dynamically allocated string with specified characters removed.
 */
cstring string_remove_char(const_cstring str, char char_to_remove);

/**
 * @brief Count occurrences of a substring in a string.
 *
 * This function counts the number of occurrences of a specified substring in the input string.
 *
 * @param str The input string.
 * @param substr The substring to count.
 * @return The number of occurrences of the substring.
 */
size_t string_count_substring(cstring str, const_cstring substr);

/**
 * @brief Reverse words in a string.
 *
 * This function reverses the order of words in the input string.
 *
 * @param str The input string.
 * @return A dynamically allocated string with reversed words.
 */
cstring string_reverse_words(const_cstring str);

/**
 * @brief Convert a string to title case.
 *
 * This function converts the first character of each word in the input string to uppercase.
 *
 * @param str The input string.
 * @return A dynamically allocated string in title case.
 */
cstring string_to_title_case(const_cstring str);

/**
 * @brief Remove consecutive duplicate characters from a string.
 *
 * This function removes consecutive duplicate characters from the input string.
 *
 * @param str The input string.
 * @return A dynamically allocated string with consecutive duplicates removed.
 */
cstring string_remove_consecutive_duplicates(const_cstring str);

/**
 * @brief Replace multiple consecutive spaces with a single space.
 *
 * This function replaces multiple consecutive spaces in the input string with a single space.
 *
 * @param str The input string.
 * @return A dynamically allocated string with consecutive spaces replaced.
 */
cstring string_remove_extra_spaces(const_cstring str);

#ifdef __cplusplus
}
#endif

#endif
