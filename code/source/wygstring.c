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
#include "fossil/xstring/wygstring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Adjust the size as needed
enum {TAG_LENGTH = 3};

cwygstring* fscl_wygstring_create(const char* text) {
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

void fscl_wygstring_set_text(cwygstring* wygstring, const char* text) {
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

const char* fscl_wygstring_get_text(const cwygstring* wygstring) {
    return (wygstring) ? wygstring->text : NULL;
} // end of func

void fscl_wygstring_erase(cwygstring* wygstring) {
    if (wygstring) {
        free(wygstring->text);
        free(wygstring);
    }
} // end of func

void fscl_wygstring_append_text(cwygstring* wygstring, const char* text_to_append) {
    if (wygstring) {
        wygstring->text = (char*)realloc(wygstring->text, wygstring->length + strlen(text_to_append) + 1);
        
        if (wygstring->text == NULL) {
            return; // Memory allocation failed
        }

        strcat(wygstring->text, text_to_append);
        wygstring->length = strlen(wygstring->text);
    }
} // end of func

void fscl_wygstring_insert_text(cwygstring* wygstring, int position, const char* text_to_insert) {
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

void fscl_wygstring_make_formatting(cwygstring* wygstring, int start, int end, const char* tag) {
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

void fscl_wygstring_make_bold(cwygstring* wygstring, int start, int end) {
    fscl_wygstring_make_formatting(wygstring, start, end, "<b>");
} // end of func

void fscl_wygstring_make_italic(cwygstring* wygstring, int start, int end) {
    fscl_wygstring_make_formatting(wygstring, start, end, "<i>");
} // end of func

void fscl_wygstring_make_underlined(cwygstring* wygstring, int start, int end) {
    fscl_wygstring_make_formatting(wygstring, start, end, "<u>");
} // end of func

int fscl_wygstring_compare(const cwygstring* str1, const cwygstring* str2) {
    return (str1 && str2) ? strcmp(str1->text, str2->text) : -1;
} // end of func

void fscl_wygstring_concat(cwygstring* dest, const cwygstring* src) {
    if (dest && src) {
        dest->text = (char*)realloc(dest->text, dest->length + src->length + 1);
        
        if (dest->text == NULL) {
            return; // Memory allocation failed
        }

        strcat(dest->text, src->text);
        dest->length = strlen(dest->text);
    }
} // end of func

cwygstring* fscl_wygstring_copy(const cwygstring* wygstring) {
    if (wygstring) {
        return fscl_wygstring_create(wygstring->text);
    }

    return NULL;
} // end of func

int fscl_wygstring_length(const cwygstring* wygstring) {
    return (wygstring) ? wygstring->length : 0;
} // end of func

// Function to trim leading and trailing whitespace characters from a cwygstring.
void fscl_wygstring_trim(cwygstring* wygstring) {
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
void fscl_wygstring_to_lowercase(cwygstring* wygstring) {
    if (wygstring == NULL || wygstring->text == NULL) {
        return; // Invalid input
    }

    for (int i = 0; i < wygstring->length; i++) {
        wygstring->text[i] = tolower(wygstring->text[i]);
    }
} // end of func

// Function to convert the text of a cwygstring to uppercase.
void fscl_wygstring_to_uppercase(cwygstring* wygstring) {
    if (wygstring == NULL || wygstring->text == NULL) {
        return; // Invalid input
    }

    for (int i = 0; i < wygstring->length; i++) {
        wygstring->text[i] = toupper(wygstring->text[i]);
    }
} // end of func

// Function to replace a specified portion of a cwygstring text with another text.
void fscl_wygstring_replace_text(cwygstring* wygstring, int start, int end, const char* replacement) {
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
