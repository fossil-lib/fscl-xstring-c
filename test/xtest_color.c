/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xstring/color.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test cases for the Caesar cipher
XTEST_CASE(test_tscl_string_color_red_dark) {
    cstring result = tscl_string_color_red_dark("Test");
    TEST_ASSERT_EQUAL_STRING("\x1B[31;1mTest\x1B[0m", result);
    free(result);
}

XTEST_CASE(test_tscl_string_color_red_light) {
    cstring result = tscl_string_color_red_light("Test");
    TEST_ASSERT_EQUAL_STRING("\x1B[91mTest\x1B[0m", result);
    free(result);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_number_group) {
    XTEST_RUN_UNIT(test_tscl_string_color_red_dark,  runner);
    XTEST_RUN_UNIT(test_tscl_string_color_red_light, runner);
} // end of function main
