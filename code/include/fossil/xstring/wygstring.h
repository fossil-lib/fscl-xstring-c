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
/**
 * Create a cwygstring with the given text.
 *
 * @param text The initial text for the wygstring.
 * @return A pointer to the created cwygstring.
 */
cwygstring* fscl_wygstring_create(const char* text);

/**
 * Set the text of a cwygstring.
 *
 * @param wygstring The cwygstring to modify.
 * @param text The new text for the wygstring.
 */
void fscl_wygstring_set_text(cwygstring* wygstring, const char* text);

/**
 * Get the text of a cwygstring.
 *
 * @param wygstring The cwygstring to read.
 * @return The text of the wygstring.
 */
const char* fscl_wygstring_get_text(const cwygstring* wygstring);

/**
 * Erase a cwygstring and free its resources.
 *
 * @param wygstring The cwygstring to erase.
 */
void fscl_wygstring_erase(cwygstring* wygstring);

/**
 * Append text to the end of a cwygstring.
 *
 * @param wygstring The cwygstring to modify.
 * @param text_to_append The text to append.
 */
void fscl_wygstring_append_text(cwygstring* wygstring, const char* text_to_append);

/**
 * Insert text at the specified position in a cwygstring.
 *
 * @param wygstring The cwygstring to modify.
 * @param position The position to insert the text.
 * @param text_to_insert The text to insert.
 */
void fscl_wygstring_insert_text(cwygstring* wygstring, int position, const char* text_to_insert);

/**
 * Make a portion of the text in a cwygstring bold.
 *
 * @param wygstring The cwygstring to modify.
 * @param start The starting position of the text to make bold.
 * @param end The ending position of the text to make bold.
 */
void fscl_wygstring_make_bold(cwygstring* wygstring, int start, int end);

/**
 * Make a portion of the text in a cwygstring italic.
 *
 * @param wygstring The cwygstring to modify.
 * @param start The starting position of the text to make italic.
 * @param end The ending position of the text to make italic.
 */
void fscl_wygstring_make_italic(cwygstring* wygstring, int start, int end);

/**
 * Make a portion of the text in a cwygstring underlined.
 *
 * @param wygstring The cwygstring to modify.
 * @param start The starting position of the text to make underlined.
 * @param end The ending position of the text to make underlined.
 */
void fscl_wygstring_make_underlined(cwygstring* wygstring, int start, int end);

/**
 * Compare two cwygstrings.
 *
 * @param str1 The first cwygstring for comparison.
 * @param str2 The second cwygstring for comparison.
 * @return An integer less than, equal to, or greater than zero if str1 is found, respectively, to be less than,
 *         to match, or be greater than str2.
 */
int fscl_wygstring_compare(const cwygstring* str1, const cwygstring* str2);

/**
 * Concatenate the content of one cwygstring to another.
 *
 * @param dest The destination cwygstring.
 * @param src The source cwygstring to concatenate.
 */
void fscl_wygstring_concat(cwygstring* dest, const cwygstring* src);

/**
 * Create a copy of a cwygstring.
 *
 * @param wygstring The cwygstring to copy.
 * @return A new cwygstring with the same content as the original.
 */
cwygstring* fscl_wygstring_copy(const cwygstring* wygstring);

/**
 * Get the length of a cwygstring.
 *
 * @param wygstring The cwygstring to measure.
 * @return The length of the cwygstring.
 */
int fscl_wygstring_length(const cwygstring* wygstring);

/**
 * Trim whitespace from the beginning and end of a cwygstring.
 *
 * @param wygstring The cwygstring to modify.
 */
void fscl_wygstring_trim(cwygstring* wygstring);

/**
 * Convert all characters in a cwygstring to lowercase.
 *
 * @param wygstring The cwygstring to modify.
 */
void fscl_wygstring_to_lowercase(cwygstring* wygstring);

/**
 * Convert all characters in a cwygstring to uppercase.
 *
 * @param wygstring The cwygstring to modify.
 */
void fscl_wygstring_to_uppercase(cwygstring* wygstring);

/**
 * Replace a portion of the text in a cwygstring with new text.
 *
 * @param wygstring The cwygstring to modify.
 * @param start The starting position of the text to replace.
 * @param end The ending position of the text to replace.
 * @param replacement The new text to insert.
 */
void fscl_wygstring_replace_text(cwygstring* wygstring, int start, int end, const char* replacement);

#ifdef __cplusplus
}
#endif

#endif
