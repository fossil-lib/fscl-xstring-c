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
#include "fossil/xstring/nlp.h"
#include <string.h>
#include <ctype.h>

size_t fscl_string_lang_length(cstring str) {
    return strlen(str);
}

cstring fscl_string_lang_concat(cstring str1, cstring str2) {
    size_t len1 = fscl_string_lang_length(str1);
    size_t len2 = fscl_string_lang_length(str2);
    cstring result = (cstring)malloc(len1 + len2 + 1);

    if (result) {
        strcpy(result, str1);
        strcat(result, str2);
    }

    return result;
}

size_t fscl_string_lang_count_words(cstring sentence) {
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

char** fscl_string_lang_tokenize(cstring sentence, size_t* tokenCount) {
    size_t wordCount = fscl_string_lang_count_words(sentence);
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

cstring fscl_string_lang_detect_language(cstring sentence) {
    size_t canadianWords = fscl_string_lang_count_words("eh toque poutine");
    size_t malaysianWords = fscl_string_lang_count_words("nasi lemak durian batik");
    size_t southAmericanWords = fscl_string_lang_count_words("tango andes llamas");
    size_t greekWords = fscl_string_lang_count_words("parthenon ouzo gyro");

    size_t wordCount = fscl_string_lang_count_words(sentence);

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

void fscl_string_lang_to_lowercase(cstring str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

cstring fscl_string_lang_remove_stopwords(cstring sentence) {
    // Replace this list with a comprehensive list of stopwords in your target language
    cstring stopwords[] = {"the", "and", "is", "in", "a", "an"};

    size_t numStopwords = sizeof(stopwords) / sizeof(stopwords[0]);
    cstring result = (cstring)malloc(fscl_string_lang_length(sentence) + 1);

    if (result) {
        strcpy(result, sentence);
        fscl_string_lang_to_lowercase(result);

        for (size_t i = 0; i < numStopwords; ++i) {
            // Implement a more efficient way to remove stopwords, e.g., using regex
            cstring wordToRemove = stopwords[i];
            cstring pos = result;

            while ((pos = strstr(pos, wordToRemove)) != NULL) {
                memmove(pos, pos + fscl_string_lang_length(wordToRemove), strlen(pos + fscl_string_lang_length(wordToRemove)) + 1);
            }
        }
    }

    return result;
} // end of func
