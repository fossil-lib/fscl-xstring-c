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
#ifndef fscl_NUMBER_H
#define fscl_NUMBER_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>
#include <fossil/xstring/cstring.h>

// =================================================================
// Available functions
// =================================================================

/**
 * Convert a string representation of a number to its numeric value.
 *
 * @param number The string representation of the number.
 * @return The numeric value.
 */
int fscl_string_number_to_numeric(cstring number);

/**
 * Evaluate a string expression and return the numeric result.
 *
 * @param expression The string expression to be evaluated.
 * @return The numeric result of the expression.
 */
int fscl_string_expression_to_numeric(cstring expression);

/**
 * Convert a numeric value to its string representation.
 *
 * @param number The numeric value.
 * @return The string representation of the number.
 */
cstring fscl_string_number_from_numeric(int number);

#ifdef __cplusplus
}
#endif

#endif
