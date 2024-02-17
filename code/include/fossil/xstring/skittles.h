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
#ifndef fscl_SKITTLE_H
#define fscl_SKITTLE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <fossil/xstring/cstring.h>

#define RESET "\x1b[0m"
#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define BOLD "\x1b[1m"
#define UNDERLINE "\x1b[4m"

enum {
    MAX_SKITTLE_LENGTH = 15
};

typedef struct {
    char *content;
    char color[MAX_SKITTLE_LENGTH];
} skittle;

// =================================================================
// Create and erase functions
// =================================================================
skittle fscl_skittle_create(const cstring content, const cstring color);
void fscl_skittle_erase(skittle* s);

// =================================================================
// Available functions
// =================================================================
void fscl_skittle_print(const skittle* s);
skittle fscl_skittle_concat(const skittle* s1, const skittle* s2);
skittle fscl_skittle_substr(const skittle* s, int start, int length);
int fscl_skittle_length(const skittle* s);
int fscl_skittle_equal(const skittle* s1, const skittle* s2);
skittle fscl_skittle_reverse(const skittle* s);
skittle fscl_skittle_uppercase(const skittle* s);

#ifdef __cplusplus
}
#endif

#endif
