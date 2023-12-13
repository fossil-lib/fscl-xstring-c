/*  ----------------------------------------------------------------------------
    File: demo_string.c

    Description:
    This demo file serves as a showcase of the Trilobite Stdlib in action. It provides
    example code snippets and usage scenarios to help users understand how to leverage
    the library's features and functions in their own projects.

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
#include <trilobite/xstring/cstring.h> // lib source code
#include <stdio.h>

int main() {
    const_cstring str1 = "Hello, ";
    const_cstring str2 = "World!";
    const_cstring longStr = "   This is a long string with spaces   ";
    const_cstring substring = "is";
    const_cstring delimiter = " ";

    // Length of a string
    size_t len1 = string_length(str1);
    printf("Length of str1: %zu\n", len1);

    // Copy a string
    cstring copy = string_copy(str2);
    printf("Copy of str2: %s\n", copy);
    string_erase(copy);

    // Concatenate two strings
    cstring concatenated = string_concat(str1, str2);
    printf("Concatenated string: %s\n", concatenated);
    string_erase(concatenated);

    // Compare two strings
    int cmp = string_compare(str1, str2);
    if (cmp < 0) {
        printf("str1 is less than str2\n");
    } else if (cmp > 0) {
        printf("str1 is greater than str2\n");
    } else {
        printf("str1 is equal to str2\n");
    }

    // Extract a substring
    cstring sub = string_substr(str1, 0, 5);
    printf("Substring of str1: %s\n", sub);
    string_erase(sub);

    // Find the first occurrence of a substring
    int firstOccurrence = string_find(longStr, substring);
    printf("First occurrence of '%s' in '%s' at index %d\n", substring, longStr, firstOccurrence);

    // Find the last occurrence of a substring
    int lastOccurrence = string_rfind(longStr, substring);
    printf("Last occurrence of '%s' in '%s' at index %d\n", substring, longStr, lastOccurrence);

    // Split a string
    char **tokens = string_split(longStr, delimiter);
    printf("Split string '%s' using '%s' as delimiter:\n", longStr, delimiter);
    for (int i = 0; tokens[i] != NULL; i++) {
        printf("Token %d: %s\n", i, tokens[i]);
        string_erase(tokens[i]);
    }
    free(tokens);

    // Convert a string to uppercase
    cstring upper = string_to_upper(str1);
    printf("Uppercase of str1: %s\n", upper);
    string_erase(upper);

    // Convert a string to lowercase
    cstring lower = string_to_lower(str1);
    printf("Lowercase of str1: %s\n", lower);
    string_erase(lower);

    // Trim a string
    cstring trimmed = string_trim(longStr);
    printf("Trimmed string: '%s'\n", trimmed);
    string_erase(trimmed);

    // Reverse a string
    cstring reversed = string_reverse(str1);
    printf("Reversed str1: %s\n", reversed);
    string_erase(reversed);

    // Replace all occurrences of a substring
    cstring replaced = string_replace(longStr, " ", "_");
    printf("String with spaces replaced: %s\n", replaced);
    string_erase(replaced);

    return 0;
} // end of func
