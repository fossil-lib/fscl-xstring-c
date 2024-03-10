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
int/**
 * Check if a given letter is a vowel.
 *
 * @param c The letter to check.
 * @return 1 if it's a vowel, 0 otherwise.
 */
int fscl_letter_is_vowel(letter c);

/**
 * Check if a given letter is a consonant.
 *
 * @param c The letter to check.
 * @return 1 if it's a consonant, 0 otherwise.
 */
int fscl_letter_is_consonant(letter c);

/**
 * Convert a letter to its lowercase equivalent.
 *
 * @param c The letter to convert.
 * @return The lowercase equivalent.
 */
letter fscl_letter_to_lowercase(letter c);

/**
 * Convert a letter to its uppercase equivalent.
 *
 * @param c The letter to convert.
 * @return The uppercase equivalent.
 */
letter fscl_letter_to_uppercase(letter c);

/**
 * Count occurrences of a specific letter in a string.
 *
 * @param str The string to search.
 * @param target The letter to count.
 * @return The count of occurrences.
 */
size_t fscl_letter_count_in_string(const_letter *str, letter target);

/**
 * Check if a letter is a digit (0-9).
 *
 * @param c The letter to check.
 * @return 1 if it's a digit, 0 otherwise.
 */
int fscl_letter_is_digit(letter c);

/**
 * Check if a letter is alphanumeric.
 *
 * @param c The letter to check.
 * @return 1 if it's alphanumeric, 0 otherwise.
 */
int fscl_letter_is_alnum(letter c);

/**
 * Check if a letter is alphabetic.
 *
 * @param c The letter to check.
 * @return 1 if it's alphabetic, 0 otherwise.
 */
int fscl_letter_is_alpha(letter c);

/**
 * Toggle the case of a letter.
 *
 * @param c The letter to toggle.
 * @return The letter with its case toggled.
 */
letter fscl_letter_toggle_case(letter c);

/**
 * Apply ROT13 encryption to a letter.
 *
 * @param c The letter to encrypt.
 * @return The ROT13 encrypted letter.
 */
letter fscl_letter_rot13(letter c);

/**
 * Remove a specific letter from a string.
 *
 * @param str The string to modify.
 * @param target The letter to remove.
 */
void fscl_letter_remove_char(letter *str, letter target);

/**
 * Replace a specific letter with another in a string.
 *
 * @param str The string to modify.
 * @param target The letter to replace.
 * @param replacement The letter to replace with.
 */
void fscl_letter_replace_char(letter *str, letter target, letter replacement);

/**
 * Trim whitespace from the beginning and end of a string.
 *
 * @param str The string to trim.
 */
void fscl_letter_trim_whitespace(letter *str);

/**
 * Reverse a string of letters.
 *
 * @param str The string to reverse.
 */
void fscl_letter_reverse_string(letter *str);

/**
 * Find the first occurrence of a specific letter in a string.
 *
 * @param str The string to search.
 * @param target The letter to find.
 * @return A pointer to the first occurrence or NULL if not found.
 */
letter *fscl_letter_find_first(letter *str, letter target);

/**
 * Find the last occurrence of a specific letter in a string.
 *
 * @param str The string to search.
 * @param target The letter to find.
 * @return A pointer to the last occurrence or NULL if not found.
 */
letter *fscl_letter_find_last(letter *str, letter target);

/**
 * Split a string into an array of strings using a specific delimiter.
 *
 * @param str The string to split.
 * @param delimiter The letter used as a delimiter.
 * @param num_tokens A pointer to store the number of tokens.
 * @return An array of strings (tokens).
 */
letter **fscl_letter_split_string(const_letter *str, letter delimiter, size_t *num_tokens);

/**
 * Join an array of strings into a single string using a specific delimiter.
 *
 * @param tokens An array of strings to join.
 * @param num_tokens The number of tokens in the array.
 * @param delimiter The letter used as a delimiter.
 * @return The joined string.
 */
letter *fscl_letter_join_strings(const letter **tokens, size_t num_tokens, letter delimiter);

/**
 * Calculate the frequency of each letter in a string.
 *
 * @param str The string to analyze.
 * @param frequency An array to store the frequency of each letter (indexed by ASCII values).
 */
void fscl_letter_char_frequency(const_letter *str, int *frequency);

/**
 * Check if a letter is a punctuation character.
 *
 * @param c The letter to check.
 * @return 1 if it's a punctuation character, 0 otherwise.
 */
int fscl_letter_is_punctuation(letter c);

/**
 * Check if a letter is a whitespace character.
 *
 * @param c The letter to check.
 * @return 1 if it's a whitespace character, 0 otherwise.
 */
int fscl_letter_is_whitespace(letter c);

/**
 * Remove all punctuation characters from a string.
 *
 * @param str The string to modify.
 */
void fscl_letter_remove_punctuation(letter *str);

/**
 * Remove all whitespace characters from a string.
 *
 * @param str The string to modify.
 */
void fscl_letter_remove_whitespace(letter *str);

/**
 * Replace all whitespace characters in a string with a specified replacement.
 *
 * @param str The string to modify.
 * @param replacement The letter to replace whitespace characters with.
 */
void fscl_letter_replace_whitespace(letter *str, letter replacement);

/**
 * Remove consecutive duplicate letters in a string.
 *
 * @param str The string to modify.
 */
void fscl_letter_remove_consecutive_duplicates(letter *str);

/**
 * Capitalize the first letter of each word in a string.
 *
 * @param str The string to modify.
 */
void fscl_letter_capitalize_words(letter *str);

/**
 * Check if a letter is a printable ASCII character.
 *
 * @param c The letter to check.
 * @return 1 if it's printable, 0 otherwise.
 */
int fscl_letter_is_printable(letter c);

/**
 * Convert a letter to its ASCII value.
 *
 * @param c The letter to convert.
 * @return The ASCII value of the letter.
 */
int fscl_letter_to_ascii(letter c);

/**
 * Convert an ASCII value to a letter.
 *
 * @param ascii_value The ASCII value to convert.
 * @return The corresponding letter.
 */
letter fscl_letter_ascii_to_letter(ascii ascii_value);

/**
 * Shift the characters in a string by a specified amount in ASCII values.
 *
 * @param str The string to modify.
 * @param shift_amount The amount to shift the characters.
 */
void fscl_letter_shift_string(letter *str, int shift_amount);

#ifdef __cplusplus
}
#endif

#endif
