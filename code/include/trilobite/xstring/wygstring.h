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
#ifndef TSCL_WYGSTRING_H
#define TSCL_WYGSTRING_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>

typedef struct {
    char* text;
    int length;
} cwygstring;

/**
 * @brief Creates a new cwygstring and initializes it with the provided text.
 *
 * @param text The initial text for the cwygstring.
 * @return A pointer to the newly created cwygstring, or NULL if memory allocation fails.
 */
cwygstring* wygstring_create(const char* text);

/**
 * @brief Sets the text of a cwygstring to the specified value.
 *
 * @param wygstring The cwygstring to update.
 * @param text The new text to set for the cwygstring.
 */
void wygstring_set_text(cwygstring* wygstring, const char* text);

/**
 * @brief Retrieves the text content of a cwygstring.
 *
 * @param wygstring The cwygstring to retrieve text from.
 * @return A pointer to the text content of the cwygstring.
 */
const char* wygstring_get_text(const cwygstring* wygstring);

/**
 * @brief Frees the memory associated with a cwygstring.
 *
 * @param wygstring The cwygstring to be deallocated.
 */
void wygstring_erase(cwygstring* wygstring);

/**
 * @brief Appends the specified text to the end of a cwygstring.
 *
 * @param wygstring The cwygstring to which text will be appended.
 * @param text_to_append The text to append.
 */
void wygstring_append_text(cwygstring* wygstring, const char* text_to_append);

/**
 * @brief Inserts the provided text at the specified position within a cwygstring.
 *
 * @param wygstring The cwygstring to which text will be inserted.
 * @param position The position at which the text will be inserted.
 * @param text_to_insert The text to insert.
 */
void wygstring_insert_text(cwygstring* wygstring, int position, const char* text_to_insert);

/**
 * @brief Makes a specified portion of a cwygstring text bold.
 *
 * @param wygstring The cwygstring to modify.
 * @param start The start position of the text to be made bold.
 * @param end The end position of the text to be made bold.
 */
void wygstring_make_bold(cwygstring* wygstring, int start, int end);

/**
 * @brief Makes a specified portion of a cwygstring text italic.
 *
 * @param wygstring The cwygstring to modify.
 * @param start The start position of the text to be made italic.
 * @param end The end position of the text to be made italic.
 */
void wygstring_make_italic(cwygstring* wygstring, int start, int end);

/**
 * @brief Makes a specified portion of a cwygstring text underlined.
 *
 * @param wygstring The cwygstring to modify.
 * @param start The start position of the text to be underlined.
 * @param end The end position of the text to be underlined.
 */
void wygstring_make_underlined(cwygstring* wygstring, int start, int end);

/**
 * @brief Compares two cwygstring objects for equality.
 *
 * @param str1 The first cwygstring to compare.
 * @param str2 The second cwygstring to compare.
 * @return 0 if the strings are equal; a positive value if str1 is greater; a negative value if str1 is smaller.
 */
int wygstring_compare(const cwygstring* str1, const cwygstring* str2);

/**
 * @brief Concatenates the content of the source cwygstring to the destination cwygstring.
 *
 * @param dest The destination cwygstring to which content will be appended.
 * @param src The source cwygstring whose content will be appended to dest.
 */
void wygstring_concat(cwygstring* dest, const cwygstring* src);

/**
 * @brief Creates a new cwygstring by copying the content of an existing cwygstring.
 *
 * @param wygstring The cwygstring to be copied.
 * @return A new cwygstring with the same content as the input, or NULL if memory allocation fails.
 */
cwygstring* wygstring_copy(const cwygstring* wygstring);

/**
 * @brief Returns the length of a cwygstring.
 *
 * @param wygstring The cwygstring for which the length is requested.
 * @return The length (number of characters) of the cwygstring.
 */
int wygstring_length(const cwygstring* wygstring);

/**
 * @brief Trims leading and trailing whitespace characters from a cwygstring.
 *
 * @param wygstring The cwygstring to be trimmed.
 */
void wygstring_trim(cwygstring* wygstring);

/**
 * @brief Converts the text of a cwygstring to lowercase.
 *
 * @param wygstring The cwygstring to convert.
 */
void wygstring_to_lowercase(cwygstring* wygstring);

/**
 * @brief Converts the text of a cwygstring to uppercase.
 *
 * @param wygstring The cwygstring to convert.
 */
void wygstring_to_uppercase(cwygstring* wygstring);

/**
 * @brief Replaces a specified portion of a cwygstring text with another text.
 *
 * @param wygstring The cwygstring to modify.
 * @param start The start position of the text to replace.
 * @param end The end position of the text to replace.
 * @param replacement The text to replace with.
 */
void wygstring_replace_text(cwygstring* wygstring, int start, int end, const char* replacement);

#ifdef __cplusplus
}
#endif

#endif
