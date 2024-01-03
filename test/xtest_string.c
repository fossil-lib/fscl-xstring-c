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
#include "fossil/xstring/cstring.h"
#include "fossil/xstring/utility.h"

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(fscl_string_let_fscl_string_length) {
    const_cstring str1 = "Hello";
    const_cstring str2 = NULL;

    TEST_ASSERT_EQUAL_INT(5, fscl_string_length(str1));
    TEST_ASSERT_EQUAL_INT(0, fscl_string_length(str2));
}

XTEST_CASE(fscl_string_let_fscl_string_copy) {
    const_cstring src = "CopyTest";

    cstring copy = fscl_string_copy(src);
    TEST_ASSERT_NOT_CNULLPTR(copy);
    TEST_ASSERT_EQUAL_STRING(src, copy);

    fscl_string_erase(copy);
}

XTEST_CASE(fscl_string_let_fscl_string_concat) {
    const_cstring str1 = "Hello, ";
    const_cstring str2 = "World!";
    cstring result = fscl_string_concat(str1, str2);

    TEST_ASSERT_NOT_CNULLPTR(result);
    TEST_ASSERT_EQUAL_STRING("Hello, World!", result);

    fscl_string_erase(result);
}

XTEST_CASE(fscl_string_let_fscl_string_compare) {
    const_cstring str1 = "Hello";
    const_cstring str2 = "World";
    const_cstring str3 = "Hello";

    TEST_ASSERT_EQUAL_INT(-1, fscl_string_compare(str1, str2));
    TEST_ASSERT_EQUAL_INT(1, fscl_string_compare(str2, str1));
    TEST_ASSERT_EQUAL_INT(0, fscl_string_compare(str1, str3));
}

// Test copying a non-empty string
XTEST_CASE(fscl_string_copy_non_empty) {
    const_cstring src = "Test123";
    cstring copy = fscl_string_copy(src);
    TEST_ASSERT_NOT_CNULLPTR(copy);
    TEST_ASSERT_EQUAL_STRING(src, copy);
    fscl_string_erase(copy);
}

// Test copying an empty string
XTEST_CASE(fscl_string_copy_empty) {
    const_cstring src = "";
    cstring copy = fscl_string_copy(src);
    TEST_ASSERT_NOT_CNULLPTR(copy);
    TEST_ASSERT_EQUAL_STRING(src, copy);
    fscl_string_erase(copy);
}

// Test copying a NULL string
XTEST_CASE(fscl_string_copy_null) {
    const_cstring src = NULL;
    cstring copy = fscl_string_copy(src);
    TEST_ASSERT_CNULLPTR(copy);
}

// Test concatenating with an empty string
XTEST_CASE(fscl_string_concat_with_empty) {
    const_cstring str1 = "Hello";
    const_cstring str2 = "";
    cstring result = fscl_string_concat(str1, str2);
    TEST_ASSERT_NOT_CNULLPTR(result);
    TEST_ASSERT_EQUAL_STRING("Hello", result);
    fscl_string_erase(result);
}

// Test concatenating with a NULL string
XTEST_CASE(fscl_string_concat_with_null) {
    const_cstring str1 = "Hello";
    const_cstring str2 = NULL;
    cstring result = fscl_string_concat(str1, str2);
    TEST_ASSERT_NOT_CNULLPTR(result);
    TEST_ASSERT_EQUAL_STRING("Hello", result);
    fscl_string_erase(result);
}

// Test concatenating two empty strings
XTEST_CASE(fscl_string_concat_two_empty) {
    const_cstring str1 = "";
    const_cstring str2 = "";
    cstring result = fscl_string_concat(str1, str2);
    TEST_ASSERT_NOT_CNULLPTR(result);
    TEST_ASSERT_EQUAL_STRING("", result);
    fscl_string_erase(result);
}

// Test comparing with an empty string
XTEST_CASE(fscl_string_compare_with_empty) {
    const_cstring str1 = "Hello";
    const_cstring str2 = "";
    TEST_ASSERT_EQUAL_INT(1, fscl_string_compare(str1, str2));
}

// Test comparing with a NULL string
XTEST_CASE(fscl_string_compare_with_null) {
    const_cstring str1 = "Hello";
    const_cstring str2 = NULL;
    TEST_ASSERT_EQUAL_INT(1, fscl_string_compare(str1, str2));
}

// Test comparing two empty strings
XTEST_CASE(fscl_string_compare_two_empty) {
    const_cstring str1 = "";
    const_cstring str2 = "";
    TEST_ASSERT_EQUAL_INT(0, fscl_string_compare(str1, str2));
}

// Test extracting a substring from a non-empty string
XTEST_CASE(fscl_string_substr_non_empty) {
    const_cstring str = "Hello, World!";
    cstring substr = fscl_string_substr(str, 7, 5);
    TEST_ASSERT_NOT_CNULLPTR(substr);
    TEST_ASSERT_EQUAL_STRING("World", substr);
    fscl_string_erase(substr);
}

// Test extracting a substring from an empty string
XTEST_CASE(fscl_string_substr_empty) {
    const_cstring str = "";
    cstring substr = fscl_string_substr(str, 0, 3);
    TEST_ASSERT_NOT_CNULLPTR(substr);
    TEST_ASSERT_EQUAL_STRING("", substr);
    fscl_string_erase(substr);
}

// Test finding the first occurrence of a substring in a non-empty string
XTEST_CASE(fscl_string_find_first_occurrence) {
    const_cstring str = "Hello, World!";
    const_cstring substr = "World";
    int index = fscl_string_find(str, substr);
    TEST_ASSERT_EQUAL_INT(7, index);
}

// Test finding the first occurrence of a substring in an empty string
XTEST_CASE(fscl_string_find_first_occurrence_empty) {
    const_cstring str = "";
    const_cstring substr = "World";
    int index = fscl_string_find(str, substr);
    TEST_ASSERT_EQUAL_INT(-1, index);
}

// Test finding the last occurrence of a substring in a non-empty string
XTEST_CASE(fscl_string_rfind_last_occurrence) {
    const_cstring str = "Hello, World, World!";
    const_cstring substr = "World";
    int index = fscl_string_rfind(str, substr);
    TEST_ASSERT_EQUAL_INT(13, index);
}

// Test finding the last occurrence of a substring in an empty string
XTEST_CASE(fscl_string_rfind_last_occurrence_empty) {
    const_cstring str = "";
    const_cstring substr = "World";
    int index = fscl_string_rfind(str, substr);
    TEST_ASSERT_EQUAL_INT(-1, index);
}

// Test splitting a non-empty string with a valid delimiter
XTEST_CASE(fscl_string_split_non_empty_valid_delimiter) {
    const_cstring str = "apple,orange,banana";
    const_cstring delimiter = ",";
    cstring *result = fscl_string_split(str, delimiter);
    TEST_ASSERT_NOT_CNULLPTR(result);
    TEST_ASSERT_EQUAL_STRING("apple", result[0]);
    TEST_ASSERT_EQUAL_STRING("orange", result[1]);
    TEST_ASSERT_EQUAL_STRING("banana", result[2]);
    TEST_ASSERT_CNULLPTR(result[3]);  // Ensure the last element is NULL
    // Free the allocated memory
    for (int i = 0; result[i] != NULL; ++i) {
        fscl_string_erase(result[i]);
    }
    free(result);
}

// Test splitting a non-empty string with an invalid delimiter
XTEST_CASE(fscl_string_split_non_empty_invalid_delimiter) {
    const_cstring str = "apple,orange,banana";
    const_cstring delimiter = ";";
    cstring *result = fscl_string_split(str, delimiter);
    TEST_ASSERT_NOT_CNULLPTR(result);
    TEST_ASSERT_EQUAL_STRING("apple,orange,banana", result[0]);  // Should be one element
    TEST_ASSERT_CNULLPTR(result[1]);  // Ensure the last element is NULL
    // Free the allocated memory
    for (int i = 0; result[i] != NULL; ++i) {
        fscl_string_erase(result[i]);
    }
    free(result);
}

XTEST_CASE(test_fscl_string_shuffle) {
    const_cstring original = "abcdef";
    cstring shuffled = fscl_string_shuffle(original);
    // Ensure the shuffled string has the same length as the original
    TEST_ASSERT_EQUAL(strlen(original), strlen(shuffled));
    // Ensure the shuffled string is not the same as the original (a basic check for randomness)
    TEST_ASSERT_NOT_EQUAL_STRING(original, shuffled);

    // Clean up
    free(shuffled);
}

XTEST_CASE(test_fscl_string_make_silly) {
    const_cstring original = "hello world";
    cstring silly = fscl_string_make_silly(original);
    // Ensure the silly string has the same length as the original
    TEST_ASSERT_EQUAL(strlen(original), strlen(silly));
    // Ensure vowels in the silly string are uppercase
    for (size_t i = 0; i < strlen(silly); i++) {
        if (strchr("aeiouAEIOU", silly[i]) != NULL) {
            TEST_ASSERT_TRUE(isupper(silly[i]));
        }
    }

    // Clean up
    free(silly);
}

XTEST_CASE(test_fscl_string_reverse_words) {
    const_cstring original = "Hello World";
    cstring reversed_words = fscl_string_reverse_words(original);
    // Ensure the reversed words string has the same length as the original
    TEST_ASSERT_EQUAL(strlen(original), strlen(reversed_words));
    // Ensure the reversed words string has reversed word order
    TEST_ASSERT_EQUAL_STRING("World Hello", reversed_words);

    // Clean up
    free(reversed_words);
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(test_string_group) {
    XTEST_RUN_UNIT(fscl_string_let_fscl_string_compare);
    XTEST_RUN_UNIT(fscl_string_let_fscl_string_concat);
    XTEST_RUN_UNIT(fscl_string_let_fscl_string_copy);
    XTEST_RUN_UNIT(fscl_string_let_fscl_string_length);
    XTEST_RUN_UNIT(fscl_string_copy_non_empty);
    XTEST_RUN_UNIT(fscl_string_copy_empty);
    XTEST_RUN_UNIT(fscl_string_copy_null);
    XTEST_RUN_UNIT(fscl_string_concat_with_empty);
    XTEST_RUN_UNIT(fscl_string_concat_with_null);
    XTEST_RUN_UNIT(fscl_string_concat_two_empty);
    XTEST_RUN_UNIT(fscl_string_compare_with_empty);
    XTEST_RUN_UNIT(fscl_string_compare_with_null);
    XTEST_RUN_UNIT(fscl_string_compare_two_empty);
    XTEST_RUN_UNIT(fscl_string_substr_non_empty);
    XTEST_RUN_UNIT(fscl_string_substr_empty);
    XTEST_RUN_UNIT(test_fscl_string_shuffle);
    XTEST_RUN_UNIT(test_fscl_string_make_silly);
    XTEST_RUN_UNIT(test_fscl_string_reverse_words);
    XTEST_RUN_UNIT(fscl_string_find_first_occurrence);
    XTEST_RUN_UNIT(fscl_string_find_first_occurrence_empty);
    XTEST_RUN_UNIT(fscl_string_rfind_last_occurrence);
    XTEST_RUN_UNIT(fscl_string_rfind_last_occurrence_empty);
    XTEST_RUN_UNIT(fscl_string_split_non_empty_valid_delimiter);
    XTEST_RUN_UNIT(fscl_string_split_non_empty_invalid_delimiter);
} // end of function main
