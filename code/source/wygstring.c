/*  ----------------------------------------------------------------------------
    File: wygstring.c

    Description:
    This source file contains the code entry point for the Trilobite Stdlib project.
    It demonstrates the usage of various utilities and functions provided by the
    Trilobite Stdlib to enhance software development.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.home.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
*/
#include "trilobite/xstring/wygstring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Adjust the size as needed
enum {TAG_LENGTH = 3};

cwygstring* wygstring_create(const char* text) {
    if (text == NULL) {
        return NULL;
    }

    cwygstring* wygstring = (cwygstring*)malloc(sizeof(cwygstring));
    if (wygstring) {
        wygstring->text = (char*)malloc(strlen(text) + 1);
        
        if (wygstring->text == NULL) {
            free(wygstring);
            return NULL;
        }

        strcpy(wygstring->text, text);
        wygstring->length = strlen(wygstring->text);
        return wygstring;
    }

    return NULL;
} // end of func

void wygstring_set_text(cwygstring* wygstring, const char* text) {
    if (wygstring) {
        free(wygstring->text);
        wygstring->text = (char*)malloc(strlen(text) + 1);
        
        if (wygstring->text == NULL) {
            return; // Memory allocation failed
        }

        strcpy(wygstring->text, text);
        wygstring->length = strlen(text);
    }
} // end of func

const char* wygstring_get_text(const cwygstring* wygstring) {
    return (wygstring) ? wygstring->text : NULL;
} // end of func

void wygstring_erase(cwygstring* wygstring) {
    if (wygstring) {
        free(wygstring->text);
        free(wygstring);
    }
} // end of func

void wygstring_append_text(cwygstring* wygstring, const char* text_to_append) {
    if (wygstring) {
        wygstring->text = (char*)realloc(wygstring->text, wygstring->length + strlen(text_to_append) + 1);
        
        if (wygstring->text == NULL) {
            return; // Memory allocation failed
        }

        strcat(wygstring->text, text_to_append);
        wygstring->length = strlen(wygstring->text);
    }
} // end of func

void wygstring_insert_text(cwygstring* wygstring, int position, const char* text_to_insert) {
    if (wygstring) {
        if (position >= 0 && position <= wygstring->length) {
            wygstring->text = (char*)realloc(wygstring->text, wygstring->length + strlen(text_to_insert) + 1);
            
            if (wygstring->text == NULL) {
                return; // Memory allocation failed
            }

            memmove(wygstring->text + position + strlen(text_to_insert), wygstring->text + position, wygstring->length - position + 1);
            memcpy(wygstring->text + position, text_to_insert, strlen(text_to_insert));
            wygstring->length = strlen(wygstring->text);
        }
    }
} // end of func

void wygstring_make_formatting(cwygstring* wygstring, int start, int end, const char* tag) {
    if (wygstring && start >= 0 && end >= start && end <= wygstring->length) {
        char* newText = (char*)realloc(wygstring->text, wygstring->length + 2 * TAG_LENGTH + 1);
        
        if (newText == NULL) {
            // Memory allocation failed
            return;
        }

        // Update the pointer only if realloc was successful
        wygstring->text = newText;

        // Move existing content to make space for the tag
        memmove(wygstring->text + start + TAG_LENGTH, wygstring->text + start, end - start);

        // Insert the tag
        strncpy(wygstring->text + start, tag, TAG_LENGTH);

        // Append the tag at the end of the inserted content
        strncpy(wygstring->text + end + TAG_LENGTH, tag, TAG_LENGTH);

        // Update the length
        wygstring->length = strlen(wygstring->text);
    }
} // end of func

void wygstring_make_bold(cwygstring* wygstring, int start, int end) {
    wygstring_make_formatting(wygstring, start, end, "<b>");
} // end of func

void wygstring_make_italic(cwygstring* wygstring, int start, int end) {
    wygstring_make_formatting(wygstring, start, end, "<i>");
} // end of func

void wygstring_make_underlined(cwygstring* wygstring, int start, int end) {
    wygstring_make_formatting(wygstring, start, end, "<u>");
} // end of func

int wygstring_compare(const cwygstring* str1, const cwygstring* str2) {
    return (str1 && str2) ? strcmp(str1->text, str2->text) : -1;
} // end of func

void wygstring_concat(cwygstring* dest, const cwygstring* src) {
    if (dest && src) {
        dest->text = (char*)realloc(dest->text, dest->length + src->length + 1);
        
        if (dest->text == NULL) {
            return; // Memory allocation failed
        }

        strcat(dest->text, src->text);
        dest->length = strlen(dest->text);
    }
} // end of func

cwygstring* wygstring_copy(const cwygstring* wygstring) {
    if (wygstring) {
        return wygstring_create(wygstring->text);
    }

    return NULL;
} // end of func

int wygstring_length(const cwygstring* wygstring) {
    return (wygstring) ? wygstring->length : 0;
} // end of func

// Function to trim leading and trailing whitespace characters from a cwygstring.
void wygstring_trim(cwygstring* wygstring) {
    if (wygstring == NULL || wygstring->text == NULL) {
        return; // Invalid input
    }

    // Trim leading whitespace
    int start = 0;
    while (isspace(wygstring->text[start])) {
        start++;
    }

    // Trim trailing whitespace
    int end = wygstring->length - 1;
    while (end >= start && isspace(wygstring->text[end])) {
        end--;
    }

    // Update the text and length
    if (start > 0 || end < wygstring->length - 1) {
        memmove(wygstring->text, wygstring->text + start, end - start + 1);
        wygstring->text[end - start + 1] = '\0';
        wygstring->length = end - start + 1;
    }
} // end of func

// Function to convert the text of a cwygstring to lowercase.
void wygstring_to_lowercase(cwygstring* wygstring) {
    if (wygstring == NULL || wygstring->text == NULL) {
        return; // Invalid input
    }

    for (int i = 0; i < wygstring->length; i++) {
        wygstring->text[i] = tolower(wygstring->text[i]);
    }
} // end of func

// Function to convert the text of a cwygstring to uppercase.
void wygstring_to_uppercase(cwygstring* wygstring) {
    if (wygstring == NULL || wygstring->text == NULL) {
        return; // Invalid input
    }

    for (int i = 0; i < wygstring->length; i++) {
        wygstring->text[i] = toupper(wygstring->text[i]);
    }
} // end of func

// Function to replace a specified portion of a cwygstring text with another text.
void wygstring_replace_text(cwygstring* wygstring, int start, int end, const char* replacement) {
    if (wygstring == NULL || wygstring->text == NULL || replacement == NULL) {
        return; // Invalid input
    }

    int replacement_length = strlen(replacement);
    int new_length = wygstring->length - (end - start + 1) + replacement_length;

    // Allocate memory for the new text
    char* new_text = (char*)malloc((new_length + 1) * sizeof(char));
    if (new_text == NULL) {
        return; // Memory allocation failed
    }

    // Copy the text before the replacement
    strncpy(new_text, wygstring->text, start);

    // Copy the replacement text
    strcpy(new_text + start, replacement);

    // Copy the text after the replacement
    strcpy(new_text + start + replacement_length, wygstring->text + end + 1);

    // Update the cwygstring
    free(wygstring->text);
    wygstring->text = new_text;
    wygstring->length = new_length;
} // end of func
