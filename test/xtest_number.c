/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xstring/number.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test cases for the Caesar cipher
XTEST_CASE(test_tscl_string_number_to_numeric) {
    TEST_ASSERT_EQUAL(3, tscl_string_number_to_numeric("three"));
    TEST_ASSERT_EQUAL(20, tscl_string_number_to_numeric("twenty"));
    // Add more test cases for other numbers
}

XTEST_CASE(test_tscl_string_expression_to_numeric) {
    TEST_ASSERT_EQUAL(14, tscl_string_expression_to_numeric("two plus three times four"));
    TEST_ASSERT_EQUAL(6, tscl_string_expression_to_numeric("two times three"));
    TEST_ASSERT_EQUAL(5, tscl_string_expression_to_numeric("ten divided by two"));
    // Add more test cases for other expressions
}

XTEST_CASE(test_tscl_string_number_from_numeric) {
    TEST_ASSERT_EQUAL_STRING("fourteen", tscl_string_number_from_numeric(14));
    TEST_ASSERT_EQUAL_STRING("six", tscl_string_number_from_numeric(6));
    // Add more test cases for other numbers
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_number_group) {
    XTEST_RUN_UNIT(test_tscl_string_expression_to_numeric, runner);
    XTEST_RUN_UNIT(test_tscl_string_number_to_numeric,     runner);
    XTEST_RUN_UNIT(test_tscl_string_number_from_numeric,   runner);
} // end of function main
