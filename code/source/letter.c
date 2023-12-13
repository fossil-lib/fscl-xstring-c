/*  ----------------------------------------------------------------------------
    File: letter.c

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
#include "trilobite/xstring/letter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int letter_is_vowel(letter c) {
    c = tolower(c);  // Convert to lowercase for case-insensitivity
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
        default:
            return 0;
    }
} // end of func

int letter_is_consonant(letter c) {
    return isalpha(c) && !letter_is_vowel(c);
} // end of func

letter letter_to_lowercase(letter c) {
    return tolower(c);
} // end of func

letter letter_to_uppercase(letter c) {
    return toupper(c);
} // end of func

size_t letter_count_in_string(const_letter *str, letter target) {
    size_t count = 0;
    while (*str) {
        if (*str == target) {
            count++;
        }
        str++;
    }
    return count;
} // end of func

int letter_is_digit(letter c) {
    return isdigit(c);
} // end of func

int letter_is_alnum(letter c) {
    return isalnum(c);
} // end of func

int letter_is_alpha(letter c) {
    return isalpha(c);
} // end of func

letter letter_toggle_case(letter c) {
    return islower(c) ? toupper(c) : tolower(c);
} // end of func

letter letter_rot13(letter c) {
    if (isalpha(c)) {
        letter base = islower(c) ? 'a' : 'A';
        return (c - base + 13) % 26 + base;
    }
    return c;
} // end of func

void letter_remove_char(letter *str, letter target) {
    if (str == NULL)
        return;

    letter *dest = str;

    while (*str) {
        if (*str != target)
            *dest++ = *str;
        str++;
    }
    *dest = '\0';
} // end of func

void letter_replace_char(letter *str, letter target, letter replacement) {
    if (str == NULL)
        return;

    while (*str) {
        if (*str == target) {
            *str = replacement;
        }
        str++;
    }
} // end of func

void letter_trim_whitespace(letter *str) {
    if (str == NULL)
        return;

    // Trim leading whitespace
    while (isspace(*str)) {
        str++;
    }

    if (*str == '\0') {
        *str = '\0';
        return;
    }

    // Trim trailing whitespace
    letter *end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        end--;
    }

    // Null-terminate the trimmed string
    *(end + 1) = '\0';
} // end of func

void letter_reverse_string(letter *str) {
    if (str == NULL)
        return;

    size_t len = strlen(str);
    if (len <= 1)
        return;

    letter *start = str;
    letter *end = str + len - 1;

    while (start < end) {
        letter temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
} // end of func

letter *letter_find_first(letter *str, letter target) {
    while (*str != '\0') {
        if (*str == target) {
            return str;
        }
        str++;
    }
    return NULL;
} // end of func

letter *letter_find_last(letter *str, letter target) {
    letter *last_occurrence = NULL;
    while (*str != '\0') {
        if (*str == target) {
            last_occurrence = str;
        }
        str++;
    }
    return last_occurrence;
} // end of func

letter **letter_split_string(const_letter *str, letter delimiter, size_t *num_tokens) {
    if (str == NULL)
        return NULL;

    size_t length = strlen(str);

    // Count the number of tokens
    size_t token_count = 1;  // At least one token
    for (size_t i = 0; i < length; i++) {
        if (str[i] == delimiter)
            token_count++;
    }

    // Allocate memory for the token array
    letter **tokens = (letter **)malloc(token_count * sizeof(letter *));
    if (tokens == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    size_t token_index = 0;
    const letter *start = str;
    for (size_t i = 0; i < length; i++) {
        if (str[i] == delimiter) {
            size_t token_length = (size_t)(str + i - start);
            tokens[token_index] = (letter *)malloc((token_length + 1) * sizeof(letter));
            if (tokens[token_index] == NULL) {
                perror("Memory allocation failed");
                exit(EXIT_FAILURE);
            }
            strncpy(tokens[token_index], start, token_length);
            tokens[token_index][token_length] = '\0';
            start = str + i + 1;
            token_index++;
        }
    }

    // Handle the last token
    size_t last_token_length = (size_t)(str + length - start);
    tokens[token_index] = (letter *)malloc((last_token_length + 1) * sizeof(letter));
    if (tokens[token_index] == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    strncpy(tokens[token_index], start, last_token_length);
    tokens[token_index][last_token_length] = '\0';

    *num_tokens = token_count;
    return tokens;
} // end of func

letter *letter_join_strings(const letter **tokens, size_t num_tokens, letter delimiter) {
    if (tokens == NULL || num_tokens == 0)
        return NULL;

    size_t total_length = 0;
    for (size_t i = 0; i < num_tokens; i++) {
        total_length += strlen(tokens[i]);
    }
    total_length += num_tokens - 1; // Account for delimiters

    letter *result = (letter *)malloc((total_length + 1) * sizeof(letter));
    if (result == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    letter *current = result;
    for (size_t i = 0; i < num_tokens; i++) {
        size_t token_length = strlen(tokens[i]);
        strcpy(current, tokens[i]);
        current += token_length;
        if (i < num_tokens - 1) {
            *current = delimiter;
            current++;
        }
    }

    *current = '\0';
    return result;
} // end of func

void letter_char_frequency(const_letter *str, int *frequency) {
    if (str == NULL || frequency == NULL)
        return;

    for (size_t i = 0; i < 128; i++) {
        frequency[i] = 0;
    }

    while (*str != '\0') {
        frequency[(int)(*str)]++;
        str++;
    }
} // end of func

// Function to check if a character is a punctuation mark
int letter_is_punctuation(letter c) {
    return (c == '!' || c == '"' || c == '#' || c == '$' || c == '%' || c == '&' ||
            c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',' ||
            c == '-' || c == '.' || c == '/' || c == ':' || c == ';' || c == '<' ||
            c == '=' || c == '>' || c == '?' || c == '@' || c == '[' || c == '\\' ||
            c == ']' || c == '^' || c == '_' || c == '`' || c == '{' || c == '|' ||
            c == '}' || c == '~');
} // end of func

// Function to check if a character is a whitespace character
int letter_is_whitespace(letter c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v');
} // end of func

// Function to remove all occurrences of punctuation marks from a string
void letter_remove_punctuation(letter *str) {
    if (str == NULL) {
        return;
    }

    size_t len = strlen(str);
    size_t write_index = 0;

    for (size_t read_index = 0; read_index < len; ++read_index) {
        if (!letter_is_punctuation(str[read_index])) {
            str[write_index++] = str[read_index];
        }
    }

    str[write_index] = '\0';
} // end of func

// Function to remove all occurrences of whitespace characters from a string
void letter_remove_whitespace(letter *str) {
    if (str == NULL) {
        return;
    }

    size_t len = strlen(str);
    size_t write_index = 0;

    for (size_t read_index = 0; read_index < len; ++read_index) {
        if (!letter_is_whitespace(str[read_index])) {
            str[write_index++] = str[read_index];
        }
    }

    str[write_index] = '\0';
} // end of func

// Function to replace all occurrences of whitespace characters with a specified character in a string
void letter_replace_whitespace(letter *str, letter replacement) {
    if (str == NULL) {
        return;
    }

    size_t len = strlen(str);

    for (size_t index = 0; index < len; ++index) {
        if (letter_is_whitespace(str[index])) {
            str[index] = replacement;
        }
    }
} // end of func

// Function to remove consecutive duplicate characters from a string
void letter_remove_consecutive_duplicates(letter *str) {
    if (str == NULL) {
        return;
    }

    size_t len = strlen(str);
    size_t write_index = 0;

    for (size_t read_index = 0; read_index < len; ++read_index) {
        if (read_index == 0 || str[read_index] != str[read_index - 1]) {
            str[write_index++] = str[read_index];
        }
    }

    str[write_index] = '\0';
} // end of func

// Function to capitalize the first letter of each word in a string
void letter_capitalize_words(letter *str) {
    if (str == NULL) {
        return;
    }

    size_t len = strlen(str);
    int capitalize_next = 1; // Flag to indicate whether the next character should be capitalized

    for (size_t index = 0; index < len; ++index) {
        if (letter_is_alpha(str[index])) {
            if (capitalize_next) {
                str[index] = letter_to_uppercase(str[index]);
                capitalize_next = 0;
            } else {
                str[index] = letter_to_lowercase(str[index]);
            }
        } else {
            capitalize_next = 1;
        }
    }
} // end of func

// Function to check if a character is a printable ASCII character
int letter_is_printable(letter c) {
    return (c >= 32 && c <= 126);
} // end of func

// Function to convert a character to its ASCII value
int letter_to_ascii(letter c) {
    return (int)c;
} // end of func

// Function to convert an ASCII value to a character
letter letter_ascii_to_letter(ascii ascii_value) {
    return (letter)ascii_value;
} // end of func

// Function to shift the characters in a string by a specified amount
void letter_shift_string(letter *str, int shift_amount) {
    if (str == NULL) {
        return;
    }

    size_t len = strlen(str);

    for (size_t index = 0; index < len; ++index) {
        str[index] = letter_ascii_to_letter(letter_to_ascii(str[index]) + shift_amount);
    }
} // end of func
