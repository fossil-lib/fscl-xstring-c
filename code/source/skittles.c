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
#include "fossil/xstring/skittles.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Custom implementation of strdup
static cstring fscl_skittle_strdup(const cstring str) {
    size_t len = strlen(str) + 1;
    cstring new_str = malloc(len);
    if (new_str != NULL) {
        strcpy(new_str, str);
    }
    return new_str;
}

skittle fscl_skittle_create(const cstring content, const cstring color) {
    skittle s;
    s.content = fscl_skittle_strdup(content);
    strncpy(s.color, color, 14);
    s.color[14] = '\0';
    return s;
}

void fscl_skittle_print(const skittle* s) {
    printf("%s%s%s", s->color, s->content, RESET);
}

skittle fscl_skittle_concat(const skittle* s1, const skittle* s2) {
    skittle result;
    size_t len1 = strlen(s1->content);
    size_t len2 = strlen(s2->content);
    result.content = malloc(len1 + len2 + 1);
    strcpy(result.content, s1->content);
    strcat(result.content, s2->content);
    strncpy(result.color, s1->color, 14);
    result.color[14] = '\0';
    return result;
}

skittle fscl_skittle_substr(const skittle* s, int start, int length) {
    skittle result;
    size_t len = strlen(s->content);
    if (start < 0 || start >= len || length <= 0) {
        result.content = fscl_skittle_strdup("");
    } else {
        result.content = malloc(length + 1);
        strncpy(result.content, s->content + start, length);
        result.content[length] = '\0';
    }
    strncpy(result.color, s->color, 14);
    result.color[14] = '\0';
    return result;
}

int fscl_skittle_length(const skittle* s) {
    return strlen(s->content);
}

int fscl_skittle_equal(const skittle* s1, const skittle* s2) {
    return (strcmp(s1->content, s2->content) == 0) && (strcmp(s1->color, s2->color) == 0);
}

skittle fscl_skittle_reverse(const skittle* s) {
    skittle result;
    size_t len = strlen(s->content);
    result.content = malloc(len + 1);
    for (size_t i = 0; i < len; ++i) {
        result.content[i] = s->content[len - 1 - i];
    }
    result.content[len] = '\0';
    strncpy(result.color, s->color, 14);
    result.color[14] = '\0';
    return result;
}

skittle fscl_skittle_uppercase(const skittle* s) {
    skittle result;
    size_t len = strlen(s->content);
    result.content = malloc(len + 1);
    for (size_t i = 0; i < len; ++i) {
        result.content[i] = toupper(s->content[i]);
    }
    result.content[len] = '\0';
    strncpy(result.color, s->color, 14);
    result.color[14] = '\0';
    return result;
}

void fscl_skittle_erase(skittle* s) {
    free(s->content);
    s->content = NULL;
}
