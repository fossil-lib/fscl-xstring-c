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
#include "fossil/xstring/wygstring.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(fscl_wygstring_test_create_and_get_text) {
    cwygstring* wygstring = fscl_wygstring_create("Hello, WYSIWYG!");
    TEST_ASSERT_NOT_CNULLPTR(wygstring);
    TEST_ASSERT_EQUAL_STRING("Hello, WYSIWYG!", fscl_wygstring_get_text(wygstring));
    fscl_wygstring_erase(wygstring);
}

XTEST_CASE(fscl_wygstring_test_append_text) {
    cwygstring* wygstring = fscl_wygstring_create("Hello");
    fscl_wygstring_append_text(wygstring, ", WYSIWYG!");
    TEST_ASSERT_EQUAL_STRING("Hello, WYSIWYG!", fscl_wygstring_get_text(wygstring));
    fscl_wygstring_erase(wygstring);
}

XTEST_CASE(fscl_wygstring_test_insert_text) {
    cwygstring* wygstring = fscl_wygstring_create("Hello WYSIWYG!");
    fscl_wygstring_insert_text(wygstring, 5, ", ");
    TEST_ASSERT_EQUAL_STRING("Hello, WYSIWYG!", fscl_wygstring_get_text(wygstring));
    fscl_wygstring_erase(wygstring);
}

XTEST_CASE(fscl_wygstring_test_make_bold) {
    cwygstring* wygstring = fscl_wygstring_create("Hello, WYSIWYG!");
    fscl_wygstring_make_bold(wygstring, 0, 5);
    TEST_ASSERT_EQUAL_STRING("<B>Hello</B>, WYSIWYG!", fscl_wygstring_get_text(wygstring));
    fscl_wygstring_erase(wygstring);
}

XTEST_CASE(fscl_wygstring_test_compare) {
    cwygstring* wygstring1 = fscl_wygstring_create("Hello, WYSIWYG!");
    cwygstring* wygstring2 = fscl_wygstring_create("Hello, WYSIWYG!");
    int comparison = fscl_wygstring_compare(wygstring1, wygstring2);
    TEST_ASSERT_EQUAL_INT(0, comparison);
    fscl_wygstring_erase(wygstring1);
    fscl_wygstring_erase(wygstring2);
}

XTEST_CASE(fscl_wygstring_test_concat) {
    cwygstring* wygstring1 = fscl_wygstring_create("Hello, ");
    cwygstring* wygstring2 = fscl_wygstring_create("WYSIWYG!");
    fscl_wygstring_concat(wygstring1, wygstring2);
    TEST_ASSERT_EQUAL_STRING("Hello, WYSIWYG!", fscl_wygstring_get_text(wygstring1));
    fscl_wygstring_erase(wygstring1);
    fscl_wygstring_erase(wygstring2);
}

XTEST_CASE(fscl_wygstring_test_length) {
    cwygstring* wygstring = fscl_wygstring_create("Hello, WYSIWYG!");
    int length = fscl_wygstring_length(wygstring);
    TEST_ASSERT_EQUAL_INT(14, length);
    fscl_wygstring_erase(wygstring);
}

// Test creating a cwygstring with an empty string
XTEST_CASE(fscl_wygstring_test_create_empty) {
    cwygstring* wygstring = fscl_wygstring_create("");
    TEST_ASSERT_NOT_CNULLPTR(wygstring);
    TEST_ASSERT_EQUAL_STRING("", fscl_wygstring_get_text(wygstring));
    fscl_wygstring_erase(wygstring);
}

// Test appending an empty string to a cwygstring
XTEST_CASE(fscl_wygstring_test_append_empty_text) {
    cwygstring* wygstring = fscl_wygstring_create("Hello");
    fscl_wygstring_append_text(wygstring, "");
    TEST_ASSERT_EQUAL_STRING("Hello", fscl_wygstring_get_text(wygstring));
    fscl_wygstring_erase(wygstring);
}

// Test inserting an empty string into a cwygstring
XTEST_CASE(fscl_wygstring_test_insert_empty_text) {
    cwygstring* wygstring = fscl_wygstring_create("Hello, WYSIWYG!");
    fscl_wygstring_insert_text(wygstring, 5, "");
    TEST_ASSERT_EQUAL_STRING("Hello, WYSIWYG!", fscl_wygstring_get_text(wygstring));
    fscl_wygstring_erase(wygstring);
}

// Test making a substring bold in an empty cwygstring
XTEST_CASE(fscl_wygstring_test_make_bold_empty) {
    cwygstring* wygstring = fscl_wygstring_create("");
    fscl_wygstring_make_bold(wygstring, 0, 2);
    TEST_ASSERT_EQUAL_STRING("", fscl_wygstring_get_text(wygstring));
    fscl_wygstring_erase(wygstring);
}

// Test comparing two empty cwygstrings
XTEST_CASE(fscl_wygstring_test_compare_empty) {
    cwygstring* wygstring1 = fscl_wygstring_create("");
    cwygstring* wygstring2 = fscl_wygstring_create("");
    int comparison = fscl_wygstring_compare(wygstring1, wygstring2);
    TEST_ASSERT_EQUAL_INT(0, comparison);
    fscl_wygstring_erase(wygstring1);
    fscl_wygstring_erase(wygstring2);
}

// Test concatenating an empty cwygstring with a non-empty one
XTEST_CASE(fscl_wygstring_test_concat_empty) {
    cwygstring* wygstring1 = fscl_wygstring_create("");
    cwygstring* wygstring2 = fscl_wygstring_create("WYSIWYG!");
    fscl_wygstring_concat(wygstring1, wygstring2);
    TEST_ASSERT_EQUAL_STRING("WYSIWYG!", fscl_wygstring_get_text(wygstring1));
    fscl_wygstring_erase(wygstring1);
    fscl_wygstring_erase(wygstring2);
}

// Test getting the length of an empty cwygstring
XTEST_CASE(fscl_wygstring_test_length_empty) {
    cwygstring* wygstring = fscl_wygstring_create("");
    int length = fscl_wygstring_length(wygstring);
    TEST_ASSERT_EQUAL_INT(0, length);
    fscl_wygstring_erase(wygstring);
}

// Test making the entire string bold
XTEST_CASE(fscl_wygstring_test_make_bold_full) {
    cwygstring* wygstring = fscl_wygstring_create("Hello, WYSIWYG!");
    fscl_wygstring_make_bold(wygstring, 0, 14);
    TEST_ASSERT_EQUAL_STRING("<B>Hello, WYSIWYG!</B>", fscl_wygstring_get_text(wygstring));
    fscl_wygstring_erase(wygstring);
}

// Test setting text to an empty cwygstring
XTEST_CASE(fscl_wygstring_test_set_text_empty) {
    cwygstring* wygstring = fscl_wygstring_create("");
    fscl_wygstring_set_text(wygstring, "New Text");
    TEST_ASSERT_EQUAL_STRING("New Text", fscl_wygstring_get_text(wygstring));
    fscl_wygstring_erase(wygstring);
}

// Test appending text to an empty cwygstring
XTEST_CASE(fscl_wygstring_test_append_text_empty) {
    cwygstring* wygstring = fscl_wygstring_create("");
    fscl_wygstring_append_text(wygstring, "Appended Text");
    TEST_ASSERT_EQUAL_STRING("Appended Text", fscl_wygstring_get_text(wygstring));
    fscl_wygstring_erase(wygstring);
}

// Test inserting text at the beginning of a cwygstring
XTEST_CASE(fscl_wygstring_test_insert_text_beginning) {
    cwygstring* wygstring = fscl_wygstring_create("WYSIWYG!");
    fscl_wygstring_insert_text(wygstring, 0, "Hello, ");
    TEST_ASSERT_EQUAL_STRING("Hello, WYSIWYG!", fscl_wygstring_get_text(wygstring));
    fscl_wygstring_erase(wygstring);
}

// Test making the entire text italic
XTEST_CASE(fscl_wygstring_test_make_italic_full) {
    cwygstring* wygstring = fscl_wygstring_create("Hello, WYSIWYG!");
    fscl_wygstring_make_italic(wygstring, 0, 14);
    TEST_ASSERT_EQUAL_STRING("<I>Hello, WYSIWYG!</I>", fscl_wygstring_get_text(wygstring));
    fscl_wygstring_erase(wygstring);
}

// Test making a substring underlined at the end of a cwygstring
XTEST_CASE(fscl_wygstring_test_make_underlined_end) {
    cwygstring* wygstring = fscl_wygstring_create("Hello, WYSIWYG!");
    fscl_wygstring_make_underlined(wygstring, 7, 14);
    TEST_ASSERT_EQUAL_STRING("Hello, <u>WYSIWYG!</u>", fscl_wygstring_get_text(wygstring));
    fscl_wygstring_erase(wygstring);
}

// Test concatenating two empty cwygstrings
XTEST_CASE(fscl_wygstring_test_concat_empty_empty) {
    cwygstring* wygstring1 = fscl_wygstring_create("");
    cwygstring* wygstring2 = fscl_wygstring_create("");
    fscl_wygstring_concat(wygstring1, wygstring2);
    TEST_ASSERT_EQUAL_STRING("", fscl_wygstring_get_text(wygstring1));
    fscl_wygstring_erase(wygstring1);
    fscl_wygstring_erase(wygstring2);
}

// Test copying the content of an empty cwygstring
XTEST_CASE(fscl_wygstring_test_copy_empty) {
    cwygstring* wygstring = fscl_wygstring_create("");
    cwygstring* copy = fscl_wygstring_copy(wygstring);
    TEST_ASSERT_NOT_CNULLPTR(copy);
    TEST_ASSERT_EQUAL_STRING("", fscl_wygstring_get_text(copy));
    fscl_wygstring_erase(wygstring);
    fscl_wygstring_erase(copy);
}

// Test getting the length of a cwygstring with special characters
XTEST_CASE(fscl_wygstring_test_length_special_characters) {
    cwygstring* wygstring = fscl_wygstring_create("Hello, &lt;WYSIWYG&gt;!");
    int length = fscl_wygstring_length(wygstring);
    TEST_ASSERT_EQUAL_INT(20, length);
    fscl_wygstring_erase(wygstring);
}

XTEST_CASE(test_create_and_get_text) {
    const char* initial_text = "Hello, World!";
    cwygstring* wygstring = fscl_wygstring_create(initial_text);

    TEST_ASSERT_NOT_CNULLPTR(wygstring);
    TEST_ASSERT_EQUAL_STRING(initial_text, fscl_wygstring_get_text(wygstring));

    fscl_wygstring_erase(wygstring);
}

XTEST_CASE(test_trim_whitespace) {
    const char* original_text = "  \t Trim Me!   \t  ";
    cwygstring* wygstring = fscl_wygstring_create(original_text);

    TEST_ASSERT_NOT_CNULLPTR(wygstring);
    TEST_ASSERT_EQUAL_STRING("Trim Me!", fscl_wygstring_get_text(wygstring));

    fscl_wygstring_erase(wygstring);
}

XTEST_CASE(test_lowercase_conversion) {
    const char* original_text = "Convert Me To Lowercase";
    cwygstring* wygstring = fscl_wygstring_create(original_text);

    TEST_ASSERT_NOT_CNULLPTR(wygstring);
    fscl_wygstring_to_lowercase(wygstring);
    TEST_ASSERT_EQUAL_STRING("convert me to lowercase", fscl_wygstring_get_text(wygstring));

    fscl_wygstring_erase(wygstring);
}

XTEST_CASE(test_uppercase_conversion) {
    const char* original_text = "Convert Me To Uppercase";
    cwygstring* wygstring = fscl_wygstring_create(original_text);

    TEST_ASSERT_NOT_CNULLPTR(wygstring);
    fscl_wygstring_to_uppercase(wygstring);
    TEST_ASSERT_EQUAL_STRING("CONVERT ME TO UPPERCASE", fscl_wygstring_get_text(wygstring));

    fscl_wygstring_erase(wygstring);
}

XTEST_CASE(test_replace_text) {
    const char* original_text = "Replace Me";
    cwygstring* wygstring = fscl_wygstring_create(original_text);

    TEST_ASSERT_NOT_CNULLPTR(wygstring);
    fscl_wygstring_replace_text(wygstring, 0, 6, "Insert");
    TEST_ASSERT_EQUAL_STRING("Insert Me", fscl_wygstring_get_text(wygstring));

    fscl_wygstring_erase(wygstring);
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(test_fscl_wygstring_group) {
    XTEST_RUN_UNIT(test_create_and_get_text);
    XTEST_RUN_UNIT(test_trim_whitespace);
    XTEST_RUN_UNIT(test_lowercase_conversion);
    XTEST_RUN_UNIT(test_uppercase_conversion);
    XTEST_RUN_UNIT(test_replace_text);
    XTEST_RUN_UNIT(fscl_wygstring_test_create_and_get_text);
    XTEST_RUN_UNIT(fscl_wygstring_test_append_text);
    XTEST_RUN_UNIT(fscl_wygstring_test_insert_text);
    XTEST_RUN_UNIT(fscl_wygstring_test_make_bold);
    XTEST_RUN_UNIT(fscl_wygstring_test_compare);
    XTEST_RUN_UNIT(fscl_wygstring_test_concat);
    XTEST_RUN_UNIT(fscl_wygstring_test_length);
    XTEST_RUN_UNIT(fscl_wygstring_test_create_empty);
    XTEST_RUN_UNIT(fscl_wygstring_test_append_empty_text);
    XTEST_RUN_UNIT(fscl_wygstring_test_insert_empty_text);
    XTEST_RUN_UNIT(fscl_wygstring_test_make_bold_empty);
    XTEST_RUN_UNIT(fscl_wygstring_test_compare_empty);
    XTEST_RUN_UNIT(fscl_wygstring_test_concat_empty);
    XTEST_RUN_UNIT(fscl_wygstring_test_length_empty);
    XTEST_RUN_UNIT(fscl_wygstring_test_make_bold_full);
    XTEST_RUN_UNIT(fscl_wygstring_test_set_text_empty);
    XTEST_RUN_UNIT(fscl_wygstring_test_append_text_empty);
    XTEST_RUN_UNIT(fscl_wygstring_test_insert_text_beginning);
    XTEST_RUN_UNIT(fscl_wygstring_test_make_italic_full);
    XTEST_RUN_UNIT(fscl_wygstring_test_make_underlined_end);
    XTEST_RUN_UNIT(fscl_wygstring_test_concat_empty_empty);
    XTEST_RUN_UNIT(fscl_wygstring_test_copy_empty);
    XTEST_RUN_UNIT(fscl_wygstring_test_length_special_characters);
} // end of function main
