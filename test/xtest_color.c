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
#include "fossil/xstring/color.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test cases for the Caesar cipher
XTEST_CASE(test_fscl_string_color_red_dark) {
    cstring result = fscl_string_color_red_dark("Test");
    TEST_ASSERT_EQUAL_STRING("\x1B[31;1mTest\x1B[0m", result);
    free(result);
}

XTEST_CASE(test_fscl_string_color_red_light) {
    cstring result = fscl_string_color_red_light("Test");
    TEST_ASSERT_EQUAL_STRING("\x1B[91mTest\x1B[0m", result);
    free(result);
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(test_color_group) {
    XTEST_RUN_UNIT(test_fscl_string_color_red_dark);
    XTEST_RUN_UNIT(test_fscl_string_color_red_light);
} // end of function main
