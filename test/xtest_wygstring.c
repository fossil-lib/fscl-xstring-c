/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xstring/wygstring.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(wygstring_test_create_and_get_text) {
    cwygstring* wygstring = wygstring_create("Hello, WYSIWYG!");
    TEST_ASSERT_NOT_NULL_PTR(wygstring);
    TEST_ASSERT_EQUAL_STRING("Hello, WYSIWYG!", wygstring_get_text(wygstring));
    wygstring_erase(wygstring);
}

XTEST_CASE(wygstring_test_append_text) {
    cwygstring* wygstring = wygstring_create("Hello");
    wygstring_append_text(wygstring, ", WYSIWYG!");
    TEST_ASSERT_EQUAL_STRING("Hello, WYSIWYG!", wygstring_get_text(wygstring));
    wygstring_erase(wygstring);
}

XTEST_CASE(wygstring_test_insert_text) {
    cwygstring* wygstring = wygstring_create("Hello WYSIWYG!");
    wygstring_insert_text(wygstring, 5, ", ");
    TEST_ASSERT_EQUAL_STRING("Hello, WYSIWYG!", wygstring_get_text(wygstring));
    wygstring_erase(wygstring);
}

XTEST_CASE(wygstring_test_make_bold) {
    cwygstring* wygstring = wygstring_create("Hello, WYSIWYG!");
    wygstring_make_bold(wygstring, 0, 5);
    TEST_ASSERT_EQUAL_STRING("<B>Hello</B>, WYSIWYG!", wygstring_get_text(wygstring));
    wygstring_erase(wygstring);
}

XTEST_CASE(wygstring_test_compare) {
    cwygstring* wygstring1 = wygstring_create("Hello, WYSIWYG!");
    cwygstring* wygstring2 = wygstring_create("Hello, WYSIWYG!");
    int comparison = wygstring_compare(wygstring1, wygstring2);
    TEST_ASSERT_EQUAL_INT(0, comparison);
    wygstring_erase(wygstring1);
    wygstring_erase(wygstring2);
}

XTEST_CASE(wygstring_test_concat) {
    cwygstring* wygstring1 = wygstring_create("Hello, ");
    cwygstring* wygstring2 = wygstring_create("WYSIWYG!");
    wygstring_concat(wygstring1, wygstring2);
    TEST_ASSERT_EQUAL_STRING("Hello, WYSIWYG!", wygstring_get_text(wygstring1));
    wygstring_erase(wygstring1);
    wygstring_erase(wygstring2);
}

XTEST_CASE(wygstring_test_length) {
    cwygstring* wygstring = wygstring_create("Hello, WYSIWYG!");
    int length = wygstring_length(wygstring);
    TEST_ASSERT_EQUAL_INT(14, length);
    wygstring_erase(wygstring);
}

// Test creating a cwygstring with an empty string
XTEST_CASE(wygstring_test_create_empty) {
    cwygstring* wygstring = wygstring_create("");
    TEST_ASSERT_NOT_NULL_PTR(wygstring);
    TEST_ASSERT_EQUAL_STRING("", wygstring_get_text(wygstring));
    wygstring_erase(wygstring);
}

// Test appending an empty string to a cwygstring
XTEST_CASE(wygstring_test_append_empty_text) {
    cwygstring* wygstring = wygstring_create("Hello");
    wygstring_append_text(wygstring, "");
    TEST_ASSERT_EQUAL_STRING("Hello", wygstring_get_text(wygstring));
    wygstring_erase(wygstring);
}

// Test inserting an empty string into a cwygstring
XTEST_CASE(wygstring_test_insert_empty_text) {
    cwygstring* wygstring = wygstring_create("Hello, WYSIWYG!");
    wygstring_insert_text(wygstring, 5, "");
    TEST_ASSERT_EQUAL_STRING("Hello, WYSIWYG!", wygstring_get_text(wygstring));
    wygstring_erase(wygstring);
}

// Test making a substring bold in an empty cwygstring
XTEST_CASE(wygstring_test_make_bold_empty) {
    cwygstring* wygstring = wygstring_create("");
    wygstring_make_bold(wygstring, 0, 2);
    TEST_ASSERT_EQUAL_STRING("", wygstring_get_text(wygstring));
    wygstring_erase(wygstring);
}

// Test comparing two empty cwygstrings
XTEST_CASE(wygstring_test_compare_empty) {
    cwygstring* wygstring1 = wygstring_create("");
    cwygstring* wygstring2 = wygstring_create("");
    int comparison = wygstring_compare(wygstring1, wygstring2);
    TEST_ASSERT_EQUAL_INT(0, comparison);
    wygstring_erase(wygstring1);
    wygstring_erase(wygstring2);
}

// Test concatenating an empty cwygstring with a non-empty one
XTEST_CASE(wygstring_test_concat_empty) {
    cwygstring* wygstring1 = wygstring_create("");
    cwygstring* wygstring2 = wygstring_create("WYSIWYG!");
    wygstring_concat(wygstring1, wygstring2);
    TEST_ASSERT_EQUAL_STRING("WYSIWYG!", wygstring_get_text(wygstring1));
    wygstring_erase(wygstring1);
    wygstring_erase(wygstring2);
}

// Test getting the length of an empty cwygstring
XTEST_CASE(wygstring_test_length_empty) {
    cwygstring* wygstring = wygstring_create("");
    int length = wygstring_length(wygstring);
    TEST_ASSERT_EQUAL_INT(0, length);
    wygstring_erase(wygstring);
}

// Test making the entire string bold
XTEST_CASE(wygstring_test_make_bold_full) {
    cwygstring* wygstring = wygstring_create("Hello, WYSIWYG!");
    wygstring_make_bold(wygstring, 0, 14);
    TEST_ASSERT_EQUAL_STRING("<B>Hello, WYSIWYG!</B>", wygstring_get_text(wygstring));
    wygstring_erase(wygstring);
}

// Test setting text to an empty cwygstring
XTEST_CASE(wygstring_test_set_text_empty) {
    cwygstring* wygstring = wygstring_create("");
    wygstring_set_text(wygstring, "New Text");
    TEST_ASSERT_EQUAL_STRING("New Text", wygstring_get_text(wygstring));
    wygstring_erase(wygstring);
}

// Test appending text to an empty cwygstring
XTEST_CASE(wygstring_test_append_text_empty) {
    cwygstring* wygstring = wygstring_create("");
    wygstring_append_text(wygstring, "Appended Text");
    TEST_ASSERT_EQUAL_STRING("Appended Text", wygstring_get_text(wygstring));
    wygstring_erase(wygstring);
}

// Test inserting text at the beginning of a cwygstring
XTEST_CASE(wygstring_test_insert_text_beginning) {
    cwygstring* wygstring = wygstring_create("WYSIWYG!");
    wygstring_insert_text(wygstring, 0, "Hello, ");
    TEST_ASSERT_EQUAL_STRING("Hello, WYSIWYG!", wygstring_get_text(wygstring));
    wygstring_erase(wygstring);
}

// Test making the entire text italic
XTEST_CASE(wygstring_test_make_italic_full) {
    cwygstring* wygstring = wygstring_create("Hello, WYSIWYG!");
    wygstring_make_italic(wygstring, 0, 14);
    TEST_ASSERT_EQUAL_STRING("<I>Hello, WYSIWYG!</I>", wygstring_get_text(wygstring));
    wygstring_erase(wygstring);
}

// Test making a substring underlined at the end of a cwygstring
XTEST_CASE(wygstring_test_make_underlined_end) {
    cwygstring* wygstring = wygstring_create("Hello, WYSIWYG!");
    wygstring_make_underlined(wygstring, 7, 14);
    TEST_ASSERT_EQUAL_STRING("Hello, <u>WYSIWYG!</u>", wygstring_get_text(wygstring));
    wygstring_erase(wygstring);
}

// Test concatenating two empty cwygstrings
XTEST_CASE(wygstring_test_concat_empty_empty) {
    cwygstring* wygstring1 = wygstring_create("");
    cwygstring* wygstring2 = wygstring_create("");
    wygstring_concat(wygstring1, wygstring2);
    TEST_ASSERT_EQUAL_STRING("", wygstring_get_text(wygstring1));
    wygstring_erase(wygstring1);
    wygstring_erase(wygstring2);
}

// Test copying the content of an empty cwygstring
XTEST_CASE(wygstring_test_copy_empty) {
    cwygstring* wygstring = wygstring_create("");
    cwygstring* copy = wygstring_copy(wygstring);
    TEST_ASSERT_NOT_NULL_PTR(copy);
    TEST_ASSERT_EQUAL_STRING("", wygstring_get_text(copy));
    wygstring_erase(wygstring);
    wygstring_erase(copy);
}

// Test getting the length of a cwygstring with special characters
XTEST_CASE(wygstring_test_length_special_characters) {
    cwygstring* wygstring = wygstring_create("Hello, &lt;WYSIWYG&gt;!");
    int length = wygstring_length(wygstring);
    TEST_ASSERT_EQUAL_INT(20, length);
    wygstring_erase(wygstring);
}

XTEST_CASE(test_create_and_get_text) {
    const char* initial_text = "Hello, World!";
    cwygstring* wygstring = wygstring_create(initial_text);

    TEST_ASSERT_NOT_NULL_PTR(wygstring);
    TEST_ASSERT_EQUAL_STRING(initial_text, wygstring_get_text(wygstring));

    wygstring_erase(wygstring);
}

XTEST_CASE(test_trim_whitespace) {
    const char* original_text = "  \t Trim Me!   \t  ";
    cwygstring* wygstring = wygstring_create(original_text);

    TEST_ASSERT_NOT_NULL_PTR(wygstring);
    TEST_ASSERT_EQUAL_STRING("Trim Me!", wygstring_get_text(wygstring));

    wygstring_erase(wygstring);
}

XTEST_CASE(test_lowercase_conversion) {
    const char* original_text = "Convert Me To Lowercase";
    cwygstring* wygstring = wygstring_create(original_text);

    TEST_ASSERT_NOT_NULL_PTR(wygstring);
    wygstring_to_lowercase(wygstring);
    TEST_ASSERT_EQUAL_STRING("convert me to lowercase", wygstring_get_text(wygstring));

    wygstring_erase(wygstring);
}

XTEST_CASE(test_uppercase_conversion) {
    const char* original_text = "Convert Me To Uppercase";
    cwygstring* wygstring = wygstring_create(original_text);

    TEST_ASSERT_NOT_NULL_PTR(wygstring);
    wygstring_to_uppercase(wygstring);
    TEST_ASSERT_EQUAL_STRING("CONVERT ME TO UPPERCASE", wygstring_get_text(wygstring));

    wygstring_erase(wygstring);
}

XTEST_CASE(test_replace_text) {
    const char* original_text = "Replace Me";
    cwygstring* wygstring = wygstring_create(original_text);

    TEST_ASSERT_NOT_NULL_PTR(wygstring);
    wygstring_replace_text(wygstring, 0, 6, "Insert");
    TEST_ASSERT_EQUAL_STRING("Insert Me", wygstring_get_text(wygstring));

    wygstring_erase(wygstring);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_wygstring_group) {
    XTEST_RUN_UNIT(test_create_and_get_text,  runner);
    XTEST_RUN_UNIT(test_trim_whitespace,      runner);
    XTEST_RUN_UNIT(test_lowercase_conversion, runner);
    XTEST_RUN_UNIT(test_uppercase_conversion, runner);
    XTEST_RUN_UNIT(test_replace_text,         runner);
    XTEST_RUN_UNIT(wygstring_test_create_and_get_text, runner);
    XTEST_RUN_UNIT(wygstring_test_append_text,         runner);
    XTEST_RUN_UNIT(wygstring_test_insert_text,         runner);
    XTEST_RUN_UNIT(wygstring_test_make_bold,           runner);
    XTEST_RUN_UNIT(wygstring_test_compare,             runner);
    XTEST_RUN_UNIT(wygstring_test_concat,              runner);
    XTEST_RUN_UNIT(wygstring_test_length,              runner);
    XTEST_RUN_UNIT(wygstring_test_create_empty,        runner);
    XTEST_RUN_UNIT(wygstring_test_append_empty_text,   runner);
    XTEST_RUN_UNIT(wygstring_test_insert_empty_text,   runner);
    XTEST_RUN_UNIT(wygstring_test_make_bold_empty,     runner);
    XTEST_RUN_UNIT(wygstring_test_compare_empty,       runner);
    XTEST_RUN_UNIT(wygstring_test_concat_empty,        runner);
    XTEST_RUN_UNIT(wygstring_test_length_empty,        runner);
    XTEST_RUN_UNIT(wygstring_test_make_bold_full,      runner);
    XTEST_RUN_UNIT(wygstring_test_set_text_empty,      runner);
    XTEST_RUN_UNIT(wygstring_test_append_text_empty,   runner);
    XTEST_RUN_UNIT(wygstring_test_insert_text_beginning,     runner);
    XTEST_RUN_UNIT(wygstring_test_make_italic_full,          runner);
    XTEST_RUN_UNIT(wygstring_test_make_underlined_end,       runner);
    XTEST_RUN_UNIT(wygstring_test_concat_empty_empty,        runner);
    XTEST_RUN_UNIT(wygstring_test_copy_empty,                runner);
    XTEST_RUN_UNIT(wygstring_test_length_special_characters, runner);
} // end of function main
