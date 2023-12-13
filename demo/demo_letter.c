/*  ----------------------------------------------------------------------------
    File: demo_letter.c

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
#include <trilobite/xstring/letter.h> // lib source code
#include <stdio.h>

int main() {
    char input_str[] = "Hello, World!";
    char target_char = 'o';

    // Check if a character is a vowel or consonant
    char test_char = 'a';
    printf("%c is a vowel: %d\n", test_char, letter_is_vowel(test_char));
    test_char = 'b';
    printf("%c is a consonant: %d\n", test_char, letter_is_consonant(test_char));

    // Convert characters to lowercase and uppercase
    char lowercase_char = 'A';
    char uppercase_char = 'z';
    printf("%c to lowercase: %c\n", lowercase_char, letter_to_lowercase(lowercase_char));
    printf("%c to uppercase: %c\n", uppercase_char, letter_to_uppercase(uppercase_char));

    // Count occurrences of a character in a string
    size_t count = letter_count_in_string(input_str, target_char);
    printf("Character '%c' occurs %zu times in \"%s\"\n", target_char, count, input_str);

    // Remove all occurrences of a character from a string
    letter_remove_char(input_str, target_char);
    printf("After removing all '%c's: \"%s\"\n", target_char, input_str);

    // Toggle the case of a character
    char toggle_char = 'T';
    printf("Toggle case of '%c': %c\n", toggle_char, letter_toggle_case(toggle_char));

    // ROT13 encoding/decoding
    char rot13_char = 'N';
    printf("ROT13 of '%c': %c\n", rot13_char, letter_rot13(rot13_char));

    // Find first and last occurrences of a character in a string
    char *first_occurrence = letter_find_first(input_str, 'l');
    char *last_occurrence = letter_find_last(input_str, 'l');
    printf("First occurrence of 'l' at position %ld, Last occurrence at position %ld\n",
           (first_occurrence != NULL) ? (first_occurrence - input_str) : -1,
           (last_occurrence != NULL) ? (last_occurrence - input_str) : -1);

    // Split a string into tokens
    char **tokens;
    size_t num_tokens;
    tokens = letter_split_string(input_str, ' ', &num_tokens);
    printf("Number of tokens: %zu\n", num_tokens);
    for (size_t i = 0; i < num_tokens; i++) {
        printf("Token %zu: %s\n", i + 1, tokens[i]);
        free(tokens[i]); // Free allocated memory for each token
    } // end for
    free(tokens); // Free the token array

    // Join an array of strings using a delimiter
    const char *join_tokens[] = {"This", "is", "a", "demo"};
    char *joined_str = letter_join_strings(join_tokens, 4, ' ');
    printf("Joined string: %s\n", joined_str);
    free(joined_str); // Free the allocated memory for the joined string

    // Calculate character frequency in a string
    int char_frequency[128] = {0}; // Initialize the frequency array
    letter_char_frequency(input_str, char_frequency);
    for (int i = 0; i < 128; i++) {
        if (char_frequency[i] > 0) {
            printf("Character '%c' occurs %d times\n", (char)i, char_frequency[i]);
        } // end if
    } // end for

    return 0;
} // end of func
