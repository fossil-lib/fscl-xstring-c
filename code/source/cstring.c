/*  ----------------------------------------------------------------------------
    File: string.c

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
#include "trilobite/xstring/cstring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

size_t string_length(const_cstring str) {
    return (str != NULL) ? strlen(str) : 0;
} // end of func

cstring string_copy(const_cstring src) {
    if (src == NULL) {
        return NULL;
    }

    size_t len = strlen(src);
    cstring copy = (cstring)malloc(len + 1);
    if (copy == NULL) {
        return NULL; // Memory allocation failed
    }

    strncpy(copy, src, len);
    copy[len] = '\0';
    return copy;
} // end of func

cstring string_concat(const_cstring str1, const_cstring str2) {
    if (str1 == NULL || str2 == NULL) {
        return NULL;
    }

    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    cstring result = (cstring)malloc(len1 + len2 + 1);
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }

    strncpy(result, str1, len1);
    strncpy(result + len1, str2, len2);
    result[len1 + len2] = '\0';
    return result;
} // end of func

int string_compare(const_cstring str1, const_cstring str2) {
    if (str1 == NULL && str2 == NULL) {
        return 0;
    } else if (str1 == NULL || str2 == NULL) {
        return -1;
    } else {
        return strcmp(str1, str2);
    }
} // end of func

void string_erase(cstring str) {
    free(str);
} // end of func

cstring string_substr(const_cstring str, size_t start, size_t length) {
    if (str == NULL || start >= strlen(str)) {
        return NULL;
    }

    cstring substr = (cstring)malloc(length + 1);
    if (substr == NULL) {
        return NULL; // Memory allocation failed
    }

    strncpy(substr, str + start, length);
    substr[length] = '\0';
    return substr;
} // end of func

int string_find(const_cstring str, const_cstring substr) {
    if (str == NULL || substr == NULL) {
        return -1;
    }

    const_cstring result = strstr(str, substr);
    return (result != NULL) ? (int)(result - str) : -1;
} // end of func

int string_rfind(const_cstring str, const_cstring substr) {
    if (str == NULL || substr == NULL) {
        return -1;
    }

    const_cstring result = strrchr(str, substr[0]);
    return (result != NULL) ? (int)(result - str) : -1;
} // end of func

cstring* string_split(const_cstring str, const_cstring delimiter) {
    if (str == NULL || delimiter == NULL) {
        return NULL;
    }

    size_t count = 0;
    cstring str_copy = string_copy(str);
    if (str_copy == NULL) {
        return NULL; // Memory allocation failed
    }

    cstring token = strtok(str_copy, delimiter);
    while (token) {
        count++;
        token = strtok(NULL, delimiter);
    }

    cstring* result = (cstring*)malloc((count + 1) * sizeof(cstring));
    if (result == NULL) {
        free(str_copy);
        return NULL; // Memory allocation failed
    }

    size_t i = 0;
    token = strtok(str_copy, delimiter);
    while (token) {
        result[i] = string_copy(token);
        if (result[i] == NULL) {
            // Memory allocation failed, free previous allocations and return NULL
            for (size_t j = 0; j < i; j++) {
                string_erase(result[j]);
            }
            free(result);
            free(str_copy);
            return NULL;
        }
        token = strtok(NULL, delimiter);
        i++;
    }

    result[count] = NULL;
    free(str_copy);
    return result;
} // end of func

cstring string_to_upper(const_cstring str) {
    if (str == NULL) {
        return NULL;
    }

    size_t len = strlen(str);
    cstring upper = (cstring)malloc(len + 1);
    if (upper == NULL) {
        return NULL; // Memory allocation failed
    }

    for (size_t i = 0; i < len; i++) {
        upper[i] = (char)toupper((unsigned char)str[i]);
    }

    upper[len] = '\0';
    return upper;
} // end of func

cstring string_to_lower(const_cstring str) {
    if (str == NULL) {
        return NULL;
    }

    size_t len = strlen(str);
    cstring lower = (cstring)malloc(len + 1);
    if (lower == NULL) {
        return NULL; // Memory allocation failed
    }

    for (size_t i = 0; i < len; i++) {
        lower[i] = (char)tolower((unsigned char)str[i]);
    }

    lower[len] = '\0';
    return lower;
} // end of func

cstring string_trim(const_cstring str) {
    if (str == NULL) {
        return NULL;
    }

    size_t len = strlen(str);
    size_t start = 0;
    size_t end = len - 1;

    while (start < len && isspace((unsigned char)str[start])) {
        start++;
    }

    while (end > start && isspace((unsigned char)str[end])) {
        end--;
    }

    size_t trimmed_len = end - start + 1;
    cstring trimmed = (cstring)malloc(trimmed_len + 1);
    if (trimmed == NULL) {
        return NULL; // Memory allocation failed
    }

    strncpy(trimmed, str + start, trimmed_len);
    trimmed[trimmed_len] = '\0';
    return trimmed;
} // end of func

cstring string_replace(cstring str, const_cstring find, const_cstring replace) {
    if (str == NULL || find == NULL || replace == NULL) {
        return NULL;
    }

    size_t find_len = strlen(find);
    size_t replace_len = strlen(replace);
    size_t result_len = strlen(str);

    cstring result = (cstring)malloc(result_len + 1);
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }

    cstring pos = strstr(str, find);
    if (pos == NULL) {
        strcpy(result, str); // No replacement needed
        return result;
    }

    size_t offset = 0;
    while (pos) {
        size_t before_len = pos - str;
        result_len += (replace_len - find_len);

        cstring temp = (cstring)realloc(result, result_len + 1);
        if (temp == NULL) {
            free(result);
            return NULL; // Memory allocation failed
        }

        result = temp;
        strncpy(result + offset, str + offset, before_len);
        strncpy(result + offset + before_len, replace, replace_len);
        offset += before_len + replace_len;
        str = pos + find_len;
        pos = strstr(str, find);
    }

    strcpy(result + offset, str);
    return result;
} // end of func

// Function to reverse a string
cstring string_reverse(const_cstring str) {
    size_t length = strlen(str);
    cstring reversed = (cstring)malloc((length + 1) * sizeof(char));

    if (reversed == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    for (size_t i = 0; i < length; i++) {
        reversed[i] = str[length - i - 1];
    }

    reversed[length] = '\0'; // Null-terminate the reversed string

    return reversed;
} // end of func

// Function to shuffle a string
cstring string_shuffle(const_cstring str) {
    size_t length = strlen(str);
    cstring shuffled = malloc((length + 1) * sizeof(char)); // Allocate memory

    if (shuffled == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    strcpy(shuffled, str); // Copy the original string

    // Use Fisher-Yates algorithm for shuffling
    srand((unsigned int)time(NULL));
    for (size_t i = length - 1; i > 0; i--) {
        size_t j = rand() % (i + 1);
        char temp = shuffled[i];
        shuffled[i] = shuffled[j];
        shuffled[j] = temp;
    }

    return shuffled;
} // end of func

// Function to make a string silly (e.g., uppercase vowels)
cstring string_make_silly(const_cstring str) {
    size_t length = strlen(str);
    cstring silly = (cstring)malloc((length + 1) * sizeof(char));

    if (silly == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    for (size_t i = 0; i < length; i++) {
        char current_char = str[i];

        // Make vowels uppercase
        if (current_char == 'a' || current_char == 'e' || current_char == 'i' ||
            current_char == 'o' || current_char == 'u' || current_char == 'A' ||
            current_char == 'E' || current_char == 'I' || current_char == 'O' ||
            current_char == 'U') {
            silly[i] = (char)toupper(current_char);
        } else {
            silly[i] = current_char;
        }
    }

    silly[length] = '\0'; // Null-terminate the silly string

    return silly;
} // end of func

// Custom version of strdup for a string library
cstring string_strdup(const_cstring str) {
    size_t length = strlen(str);
    cstring duplicate = (cstring)malloc((length + 1) * sizeof(char));

    if (duplicate == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    strcpy(duplicate, str);

    return duplicate;
} // end of func

// Check if a string starts with a specified prefix.
int string_starts_with(const_cstring str, const_cstring prefix) {
    size_t str_len = strlen(str);
    size_t prefix_len = strlen(prefix);

    if (prefix_len > str_len) {
        return 0; // Prefix is longer than the string
    }

    return strncmp(str, prefix, prefix_len) == 0;
} // end of func

// Check if a string ends with a specified suffix.
int string_ends_with(const_cstring str, const_cstring suffix) {
    size_t str_len = strlen(str);
    size_t suffix_len = strlen(suffix);

    if (suffix_len > str_len) {
        return 0; // Suffix is longer than the string
    }

    return strncmp(str + (str_len - suffix_len), suffix, suffix_len) == 0;
} // end of func

// Pad a string with a specified character to reach a certain length.
cstring string_pad(const_cstring str, size_t length, char padding_char) {
    size_t str_len = strlen(str);

    if (length <= str_len) {
        // No padding needed, just duplicate the string
        cstring padded = (cstring)malloc((str_len + 1) * sizeof(char));

        if (padded == NULL) {
            // Handle memory allocation failure
            return NULL;
        }

        strcpy(padded, str);
        return padded;
    }

    cstring padded = (cstring)malloc((length + 1) * sizeof(char));

    if (padded == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    // Copy the original string
    strcpy(padded, str);

    // Use memset to fill the padding characters
    memset(padded + str_len, padding_char, length - str_len);

    padded[length] = '\0'; // Null-terminate the padded string

    return padded;
} // end of func

// Remove all occurrences of a specified character from a string.
cstring string_remove_char(const_cstring str, char char_to_remove) {
    size_t str_len = strlen(str);

    cstring result = (cstring)malloc((str_len + 1) * sizeof(char));

    if (result == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    size_t result_index = 0;

    // Copy characters excluding char_to_remove
    for (size_t i = 0; i < str_len; i++) {
        if (str[i] != char_to_remove) {
            result[result_index++] = str[i];
        }
    }

    result[result_index] = '\0'; // Null-terminate the result string

    return result;
} // end of func

// Count occurrences of a substring in a string.
size_t string_count_substring(cstring str, const_cstring substr) {
    size_t count = 0;
    size_t substr_len = strlen(substr);
    cstring pos = str;

    while ((pos = strstr(pos, substr)) != NULL) {
        count++;
        pos += substr_len;
    }

    return count;
} // end of func

// Reverse words in a string.
cstring string_reverse_words(const_cstring str) {
    size_t str_len = strlen(str);

    cstring reversed_words = (cstring)malloc((str_len + 1) * sizeof(char));

    if (reversed_words == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    size_t word_start = 0;
    size_t reversed_words_index = 0;

    for (size_t i = 0; i <= str_len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            for (size_t j = i - 1; j >= word_start; j--) {
                reversed_words[reversed_words_index++] = str[j];
            }

            if (str[i] == ' ') {
                reversed_words[reversed_words_index++] = ' '; // Preserve space between words
            }

            word_start = i + 1;
        }
    }

    reversed_words[str_len] = '\0'; // Null-terminate the reversed words string

    return reversed_words;
} // end of func

// Convert a string to title case.
cstring string_to_title_case(const_cstring str) {
    size_t str_len = strlen(str);

    cstring title_case = (cstring)malloc((str_len + 1) * sizeof(char));

    if (title_case == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    int make_upper = 1; // Flag to indicate if the next character should be uppercase

    for (size_t i = 0; i < str_len; i++) {
        if (make_upper && isalpha(str[i])) {
            title_case[i] = (char)toupper(str[i]);
            make_upper = 0;
        } else {
            title_case[i] = str[i];

            if (str[i] == ' ') {
                make_upper = 1;
            }
        }
    }

    title_case[str_len] = '\0'; // Null-terminate the title case string

    return title_case;
} // end of func

// Remove consecutive duplicate characters from a string.
cstring string_remove_consecutive_duplicates(const_cstring str) {
    size_t str_len = strlen(str);

    cstring without_duplicates = (cstring)malloc((str_len + 1) * sizeof(char));

    if (without_duplicates == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    size_t without_duplicates_index = 0;

    for (size_t i = 0; i < str_len; i++) {
        if (i == 0 || str[i] != str[i - 1]) {
            without_duplicates[without_duplicates_index++] = str[i];
        }
    }

    without_duplicates[without_duplicates_index] = '\0'; // Null-terminate the string without consecutive duplicates

    return without_duplicates;
} // end of func

// Replace multiple consecutive spaces with a single space.
cstring string_remove_extra_spaces(const_cstring str) {
    size_t str_len = strlen(str);

    cstring without_extra_spaces = (cstring)malloc((str_len + 1) * sizeof(char));

    if (without_extra_spaces == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    size_t without_extra_spaces_index = 0;
    int encountered_space = 0;

    for (size_t i = 0; i < str_len; i++) {
        if (str[i] == ' ') {
            if (!encountered_space) {
                without_extra_spaces[without_extra_spaces_index++] = str[i];
                encountered_space = 1;
            }
        } else {
            without_extra_spaces[without_extra_spaces_index++] = str[i];
            encountered_space = 0;
        }
    }

    without_extra_spaces[without_extra_spaces_index] = '\0'; // Null-terminate the string without extra spaces

    return without_extra_spaces;
} // end of func
