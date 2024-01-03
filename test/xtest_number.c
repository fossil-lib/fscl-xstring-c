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
#include "fossil/xstring/number.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test cases for the Caesar cipher
XTEST_CASE(test_fscl_string_number_to_numeric) {
    TEST_ASSERT_EQUAL(3, fscl_string_number_to_numeric("three"));
    TEST_ASSERT_EQUAL(20, fscl_string_number_to_numeric("twenty"));
    // Add more test cases for other numbers
}

XTEST_CASE(test_fscl_string_expression_to_numeric) {
    TEST_ASSERT_EQUAL(14, fscl_string_expression_to_numeric("two plus three times four"));
    TEST_ASSERT_EQUAL(6, fscl_string_expression_to_numeric("two times three"));
    TEST_ASSERT_EQUAL(5, fscl_string_expression_to_numeric("ten divided by two"));
    // Add more test cases for other expressions
}

XTEST_CASE(test_fscl_string_number_from_numeric) {
    TEST_ASSERT_EQUAL_STRING("fourteen", fscl_string_number_from_numeric(14));
    TEST_ASSERT_EQUAL_STRING("six", fscl_string_number_from_numeric(6));
    // Add more test cases for other numbers
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(test_number_group) {
    XTEST_RUN_UNIT(test_fscl_string_expression_to_numeric);
    XTEST_RUN_UNIT(test_fscl_string_number_to_numeric);
    XTEST_RUN_UNIT(test_fscl_string_number_from_numeric);
} // end of function main
