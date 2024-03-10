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
// Skittle Management Functions
// =================================================================

/**
 * Create a skittle with the specified content and color.
 *
 * @param content The content of the skittle.
 * @param color   The color of the skittle.
 * @return The created skittle.
 */
skittle fscl_skittle_create(const cstring content, const cstring color);

/**
 * Erase a skittle and free its memory.
 *
 * @param s The skittle to be erased.
 */
void fscl_skittle_erase(skittle* s);

/**
 * Print the content and color of a skittle.
 *
 * @param s The skittle to be printed.
 */
void fscl_skittle_print(const skittle* s);

/**
 * Concatenate two skittles.
 *
 * @param s1 The first skittle.
 * @param s2 The second skittle.
 * @return The concatenated skittle.
 */
skittle fscl_skittle_concat(const skittle* s1, const skittle* s2);

/**
 * Extract a substring from a skittle.
 *
 * @param s      The skittle.
 * @param start  The starting index of the substring.
 * @param length The length of the substring.
 * @return The substring of the skittle.
 */
skittle fscl_skittle_substr(const skittle* s, int start, int length);

/**
 * Get the length of the content in a skittle.
 *
 * @param s The skittle.
 * @return The length of the skittle's content.
 */
int fscl_skittle_length(const skittle* s);

/**
 * Check if two skittles are equal.
 *
 * @param s1 The first skittle.
 * @param s2 The second skittle.
 * @return 1 if equal, 0 otherwise.
 */
int fscl_skittle_equal(const skittle* s1, const skittle* s2);

/**
 * Reverse the content of a skittle.
 *
 * @param s The skittle to be reversed.
 * @return The reversed skittle.
 */
skittle fscl_skittle_reverse(const skittle* s);

/**
 * Convert the content of a skittle to uppercase.
 *
 * @param s The skittle.
 * @return The skittle with uppercase content.
 */
skittle fscl_skittle_uppercase(const skittle* s);

#ifdef __cplusplus
}
#endif

#endif
