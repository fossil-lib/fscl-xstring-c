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

/**
 * Get the length of a string.
 *
 * @param str The input string.
 * @return The length of the string.
 */
size_t fscl_string_length(const_cstring str);

/**
 * Create a copy of a string.
 *
 * @param src The source string to copy.
 * @return The copied string.
 */
cstring fscl_string_copy(const_cstring src);

/**
 * Concatenate two strings.
 *
 * @param str1 The first string.
 * @param str2 The second string.
 * @return The concatenated string.
 */
cstring fscl_string_concat(const_cstring str1, const_cstring str2);

/**
 * Compare two strings.
 *
 * @param str1 The first string.
 * @param str2 The second string.
 * @return 0 if equal, < 0 if str1 < str2, > 0 if str1 > str2.
 */
int fscl_string_compare(const_cstring str1, const_cstring str2);

/**
 * Get a substring from a string.
 *
 * @param str    The source string.
 * @param start  The starting index of the substring.
 * @param length The length of the substring.
 * @return The substring.
 */
cstring fscl_string_substr(const_cstring str, size_t start, size_t length);

/**
 * Find the first occurrence of a substring in a string.
 *
 * @param str    The source string.
 * @param substr The substring to find.
 * @return The index of the first occurrence or -1 if not found.
 */
int fscl_string_find(const_cstring str, const_cstring substr);

/**
 * Find the last occurrence of a substring in a string.
 *
 * @param str    The source string.
 * @param substr The substring to find.
 * @return The index of the last occurrence or -1 if not found.
 */
int fscl_string_rfind(const_cstring str, const_cstring substr);

/**
 * Split a string into an array of substrings based on a delimiter.
 *
 * @param str       The source string.
 * @param delimiter The delimiter for splitting.
 * @return An array of substrings.
 */
cstring *fscl_string_split(const_cstring str, const_cstring delimiter);

/**
 * Convert a string to uppercase.
 *
 * @param str The input string.
 * @return The string in uppercase.
 */
cstring fscl_string_to_upper(const_cstring str);

/**
 * Convert a string to lowercase.
 *
 * @param str The input string.
 * @return The string in lowercase.
 */
cstring fscl_string_to_lower(const_cstring str);

/**
 * Trim leading and trailing whitespaces from a string.
 *
 * @param str The input string.
 * @return The trimmed string.
 */
cstring fscl_string_trim(const_cstring str);

/**
 * Reverse a string.
 *
 * @param str The input string.
 * @return The reversed string.
 */
cstring fscl_string_reverse(const_cstring str);

/**
 * Replace occurrences of a substring with another string.
 *
 * @param str     The source string.
 * @param find    The substring to find.
 * @param replace The replacement string.
 * @return The modified string.
 */
cstring fscl_string_replace(cstring str, const_cstring find, const_cstring replace);

/**
 * Shuffle the characters in a string randomly.
 *
 * @param str The input string.
 * @return The shuffled string.
 */
cstring fscl_string_shuffle(const_cstring str);

/**
 * Make a silly version of a string by replacing characters randomly.
 *
 * @param str The input string.
 * @return The silly version of the string.
 */
cstring fscl_string_make_silly(const_cstring str);

/**
 * Duplicate a string using dynamic memory allocation.
 *
 * @param str The input string.
 * @return The duplicated string.
 */
cstring fscl_string_strdup(const_cstring str);

/**
 * Check if a string starts with a given prefix.
 *
 * @param str    The input string.
 * @param prefix The prefix to check.
 * @return 1 if the string starts with the prefix, 0 otherwise.
 */
int fscl_string_starts_with(const_cstring str, const_cstring prefix);

/**
 * Check if a string ends with a given suffix.
 *
 * @param str    The input string.
 * @param suffix The suffix to check.
 * @return 1 if the string ends with the suffix, 0 otherwise.
 */
int fscl_string_ends_with(const_cstring str, const_cstring suffix);

/**
 * Pad a string to a specified length with a given padding character.
 *
 * @param str           The input string.
 * @param length        The desired length of the padded string.
 * @param padding_char  The character used for padding.
 * @return The padded string.
 */
cstring fscl_string_pad(const_cstring str, size_t length, char padding_char);

/**
 * Remove a specific character from a string.
 *
 * @param str             The input string.
 * @param char_to_remove The character to be removed.
 * @return The modified string.
 */
cstring fscl_string_remove_char(const_cstring str, char char_to_remove);

/**
 * Count occurrences of a substring in a string.
 *
 * @param str    The source string.
 * @param substr The substring to count.
 * @return The number of occurrences.
 */
size_t fscl_string_count_substring(cstring str, const_cstring substr);

/**
 * Reverse the order of words in a string.
 *
 * @param str The input string.
 * @return The string with reversed words.
 */
cstring fscl_string_reverse_words(const_cstring str);

/**
 * Convert a string to title case (capitalize the first letter of each word).
 *
 * @param str The input string.
 * @return The string in title case.
 */
cstring fscl_string_to_title_case(const_cstring str);

/**
 * Remove consecutive duplicate characters from a string.
 *
 * @param str The input string.
 * @return The string with consecutive duplicates removed.
 */
cstring fscl_string_remove_consecutive_duplicates(const_cstring str);

/**
 * Remove extra spaces from a string, leaving only single spaces between words.
 *
 * @param str The input string.
 * @return The string with extra spaces removed.
 */
cstring fscl_string_remove_extra_spaces(const_cstring str);

#ifdef __cplusplus
}
#endif

#endif
