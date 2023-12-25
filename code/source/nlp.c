/*  ----------------------------------------------------------------------------
    File: nlp.c

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
#include "trilobite/xstring/nlp.h"
#include <string.h>
#include <ctype.h>

size_t tscl_string_lang_length(cstring str) {
    return strlen(str);
}

cstring tscl_string_lang_concat(cstring str1, cstring str2) {
    size_t len1 = tscl_string_lang_length(str1);
    size_t len2 = tscl_string_lang_length(str2);
    cstring result = (cstring)malloc(len1 + len2 + 1);

    if (result) {
        strcpy(result, str1);
        strcat(result, str2);
    }

    return result;
}

size_t tscl_string_lang_count_words(cstring sentence) {
    size_t count = 0;
    int inWord = 0;

    while (*sentence) {
        if (isspace((unsigned char)*sentence) || ispunct((unsigned char)*sentence)) {
            inWord = 0;
        } else {
            if (!inWord) {
                count++;
                inWord = 1;
            }
        }
        sentence++;
    }

    return count;
}

char** tscl_string_lang_tokenize(cstring sentence, size_t* tokenCount) {
    size_t wordCount = tscl_string_lang_count_words(sentence);
    char** tokens = (char**)malloc(wordCount * sizeof(char*));
    *tokenCount = wordCount;

    if (tokens) {
        char* token = strtok(sentence, " ,.!?"); // Added punctuation to the delimiters
        size_t i = 0;

        while (token != NULL) {
            tokens[i++] = token;
            token = strtok(NULL, " ,.!?");
        }
    }

    return tokens;
}

cstring tscl_string_lang_detect_language(cstring sentence) {
    size_t canadianWords = tscl_string_lang_count_words("eh toque poutine");
    size_t malaysianWords = tscl_string_lang_count_words("nasi lemak durian batik");
    size_t southAmericanWords = tscl_string_lang_count_words("tango andes llamas");
    size_t greekWords = tscl_string_lang_count_words("parthenon ouzo gyro");

    size_t wordCount = tscl_string_lang_count_words(sentence);

    if (wordCount >= canadianWords) {
        return "Canadian English";
    } else if (wordCount >= malaysianWords) {
        return "Malaysian Malay";
    } else if (wordCount >= southAmericanWords) {
        return "South American Spanish";
    } else if (wordCount >= greekWords) {
        return "Greek";
    } else {
        return "Unknown";
    }
}

void tscl_string_lang_to_lowercase(cstring str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

cstring tscl_string_lang_remove_stopwords(cstring sentence) {
    // Replace this list with a comprehensive list of stopwords in your target language
    cstring stopwords[] = {"the", "and", "is", "in", "a", "an"};

    size_t numStopwords = sizeof(stopwords) / sizeof(stopwords[0]);
    cstring result = (cstring)malloc(tscl_string_lang_length(sentence) + 1);

    if (result) {
        strcpy(result, sentence);
        tscl_string_lang_to_lowercase(result);

        for (size_t i = 0; i < numStopwords; ++i) {
            // Implement a more efficient way to remove stopwords, e.g., using regex
            cstring wordToRemove = stopwords[i];
            cstring pos = result;

            while ((pos = strstr(pos, wordToRemove)) != NULL) {
                memmove(pos, pos + tscl_string_lang_length(wordToRemove), strlen(pos + tscl_string_lang_length(wordToRemove)) + 1);
            }
        }
    }

    return result;
} // end of func
