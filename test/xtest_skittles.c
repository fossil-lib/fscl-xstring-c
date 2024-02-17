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
#include "fossil/xstring/skittles.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

XTEST_CASE(test_skittle_concatenation) {
    skittle red_skittle = fscl_skittle_create("Hello", RED);
    skittle green_skittle = fscl_skittle_create(" World", GREEN);

    skittle concatenated_skittle = fscl_skittle_concat(&red_skittle, &green_skittle);

    TEST_ASSERT_EQUAL_CSTRING("Hello World", concatenated_skittle.content);
    TEST_ASSERT_EQUAL_CSTRING(RED, concatenated_skittle.color);
}

XTEST_CASE(test_skittle_substring) {
    skittle original_skittle = fscl_skittle_create("Hello World", YELLOW);

    skittle substring_skittle = fscl_skittle_substr(&original_skittle, 6, 5);

    TEST_ASSERT_EQUAL_CSTRING("World", substring_skittle.content);
    TEST_ASSERT_EQUAL_CSTRING(YELLOW, substring_skittle.color);
}

XTEST_CASE(test_skittle_reverse) {
    skittle original_skittle = fscl_skittle_create("abcdef", CYAN);

    skittle reversed_skittle = fscl_skittle_reverse(&original_skittle);

    TEST_ASSERT_EQUAL_CSTRING("fedcba", reversed_skittle.content);
    TEST_ASSERT_EQUAL_CSTRING(CYAN, reversed_skittle.color);
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(test_color_group) {
    XTEST_RUN_UNIT(test_skittle_concatenation);
    XTEST_RUN_UNIT(test_skittle_substring);
    XTEST_RUN_UNIT(test_skittle_reverse);
} // end of function main
