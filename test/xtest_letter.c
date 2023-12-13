/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xstring/letter.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
// Test case for letter_is_vowel
XTEST_CASE(letter_let_letter_is_vowel) {
    TEST_ASSERT_EQUAL_INT(1, letter_is_vowel('a'));
    TEST_ASSERT_EQUAL_INT(1, letter_is_vowel('A'));
    TEST_ASSERT_EQUAL_INT(0, letter_is_vowel('b'));
    TEST_ASSERT_EQUAL_INT(0, letter_is_vowel('Z')); // Additional test
}

// Test case for letter_to_lowercase
XTEST_CASE(letter_let_letter_to_lowercase) {
    TEST_ASSERT_EQUAL_CHAR('a', letter_to_lowercase('A'));
    TEST_ASSERT_EQUAL_CHAR('z', letter_to_lowercase('Z'));
    TEST_ASSERT_EQUAL_CHAR('3', letter_to_lowercase('3'));
    TEST_ASSERT_EQUAL_CHAR('a', letter_to_lowercase('a')); // Additional test
}

// Test case for letter_to_uppercase
XTEST_CASE(letter_let_letter_to_uppercase) {
    TEST_ASSERT_EQUAL_CHAR('A', letter_to_uppercase('a'));
    TEST_ASSERT_EQUAL_CHAR('Z', letter_to_uppercase('z'));
    TEST_ASSERT_EQUAL_CHAR('3', letter_to_uppercase('3'));
    TEST_ASSERT_EQUAL_CHAR('A', letter_to_uppercase('A')); // Additional test
}

// Test case for letter_count_in_string
XTEST_CASE(letter_let_letter_count_in_string) {
    char str[] = "hello, world!";
    TEST_ASSERT_EQUAL_INT(3, letter_count_in_string(str, 'l'));
    TEST_ASSERT_EQUAL_INT(0, letter_count_in_string(str, 'z'));
    TEST_ASSERT_EQUAL_INT(2, letter_count_in_string(str, 'o')); // Additional test
}

// Test case for letter_is_alpha
XTEST_CASE(letter_let_letter_is_alpha) {
    TEST_ASSERT_EQUAL_INT(1, letter_is_alpha('a'));
    TEST_ASSERT_EQUAL_INT(1, letter_is_alpha('A'));
    TEST_ASSERT_EQUAL_INT(1, letter_is_alpha('z'));
    TEST_ASSERT_EQUAL_INT(1, letter_is_alpha('Z'));
    TEST_ASSERT_EQUAL_INT(0, letter_is_alpha('0'));
    TEST_ASSERT_EQUAL_INT(0, letter_is_alpha(',')); // Additional test
}

XTEST_CASE(letter_let_letter_is_vowel_additional) {
    TEST_ASSERT_EQUAL_INT(0, letter_is_vowel('b'));
    TEST_ASSERT_EQUAL_INT(0, letter_is_vowel('B'));
    TEST_ASSERT_EQUAL_INT(1, letter_is_vowel('e'));
    TEST_ASSERT_EQUAL_INT(1, letter_is_vowel('E'));
    TEST_ASSERT_EQUAL_INT(0, letter_is_vowel('1'));
    TEST_ASSERT_EQUAL_INT(0, letter_is_vowel(','));
}

XTEST_CASE(letter_let_letter_to_lowercase_additional) {
    TEST_ASSERT_EQUAL_CHAR('A', letter_to_lowercase('A'));
    TEST_ASSERT_EQUAL_CHAR('z', letter_to_lowercase('Z'));
    TEST_ASSERT_EQUAL_CHAR('3', letter_to_lowercase('3'));
    TEST_ASSERT_EQUAL_CHAR('@', letter_to_lowercase('@'));
}

XTEST_CASE(letter_let_letter_to_uppercase_additional) {
    TEST_ASSERT_EQUAL_CHAR('a', letter_to_uppercase('a'));
    TEST_ASSERT_EQUAL_CHAR('Z', letter_to_uppercase('z'));
    TEST_ASSERT_EQUAL_CHAR('3', letter_to_uppercase('3'));
    TEST_ASSERT_EQUAL_CHAR('@', letter_to_uppercase('@'));
}

XTEST_CASE(letter_let_letter_count_in_string_additional) {
    char str[] = "hello, world!";
    TEST_ASSERT_EQUAL_INT(3, letter_count_in_string(str, 'l'));
    TEST_ASSERT_EQUAL_INT(0, letter_count_in_string(str, 'z'));
    TEST_ASSERT_EQUAL_INT(1, letter_count_in_string(str, 'o'));
    TEST_ASSERT_EQUAL_INT(2, letter_count_in_string(str, 'o'));
    TEST_ASSERT_EQUAL_INT(0, letter_count_in_string(str, '0'));
    TEST_ASSERT_EQUAL_INT(0, letter_count_in_string(str, ','));
}

XTEST_CASE(letter_let_letter_is_alpha_additional) {
    TEST_ASSERT_EQUAL_INT(1, letter_is_alpha('a'));
    TEST_ASSERT_EQUAL_INT(1, letter_is_alpha('A'));
    TEST_ASSERT_EQUAL_INT(1, letter_is_alpha('z'));
    TEST_ASSERT_EQUAL_INT(1, letter_is_alpha('Z'));
    TEST_ASSERT_EQUAL_INT(0, letter_is_alpha('0'));
    TEST_ASSERT_EQUAL_INT(0, letter_is_alpha(','));
    TEST_ASSERT_EQUAL_INT(0, letter_is_alpha('@'));
}

// Test cases for letter_is_punctuation
XTEST_CASE(test_is_punctuation) {
    TEST_ASSERT_EQUAL_INT(1, letter_is_punctuation('!'));
    TEST_ASSERT_EQUAL_INT(1, letter_is_punctuation(','));
    TEST_ASSERT_EQUAL_INT(1, letter_is_punctuation('.'));
    TEST_ASSERT_EQUAL_INT(1, letter_is_punctuation('?'));
    TEST_ASSERT_EQUAL_INT(0, letter_is_punctuation('A'));
    TEST_ASSERT_EQUAL_INT(0, letter_is_punctuation(' '));
}

// Test cases for letter_is_whitespace
XTEST_CASE(test_is_whitespace) {
    TEST_ASSERT_EQUAL_INT(1, letter_is_whitespace(' '));
    TEST_ASSERT_EQUAL_INT(1, letter_is_whitespace('\t'));
    TEST_ASSERT_EQUAL_INT(1, letter_is_whitespace('\n'));
    TEST_ASSERT_EQUAL_INT(1, letter_is_whitespace('\r'));
    TEST_ASSERT_EQUAL_INT(0, letter_is_whitespace('A'));
    TEST_ASSERT_EQUAL_INT(0, letter_is_whitespace('!'));
}

// Test cases for letter_remove_punctuation
XTEST_CASE(test_remove_punctuation) {
    letter str1[] = "Hello, World!";
    letter_remove_punctuation(str1);
    TEST_ASSERT_EQUAL_STRING("Hello World", str1);

    letter str2[] = "Keep, This, Punctuation!   ";
    letter_remove_punctuation(str2);
    TEST_ASSERT_EQUAL_STRING("Keep This Punctuation   ", str2);

    letter str3[] = "!@#$%^&*()";
    letter_remove_punctuation(str3);
    TEST_ASSERT_EQUAL_STRING("", str3);
}

// Test cases for letter_remove_whitespace
XTEST_CASE(test_remove_whitespace) {
    letter str1[] = " Hello  World ";
    letter_remove_whitespace(str1);
    TEST_ASSERT_EQUAL_STRING("HelloWorld", str1);

    letter str2[] = "\tRemove\tTabs\n";
    letter_remove_whitespace(str2);
    TEST_ASSERT_EQUAL_STRING("RemoveTabs", str2);

    letter str3[] = "  \r\f  ";
    letter_remove_whitespace(str3);
    TEST_ASSERT_EQUAL_STRING("", str3);
}

// Test cases for letter_replace_whitespace
XTEST_CASE(test_replace_whitespace) {
    letter str1[] = "Replace Spaces";
    letter_replace_whitespace(str1, '_');
    TEST_ASSERT_EQUAL_STRING("Replace_Spaces", str1);

    letter str2[] = "KeepTabs\tSeparateLines\n";
    letter_replace_whitespace(str2, '_');
    TEST_ASSERT_EQUAL_STRING("KeepTabs_SeparateLines_", str2);
}

// Test cases for letter_remove_consecutive_duplicates
XTEST_CASE(test_remove_consecutive_duplicates) {
    letter str1[] = "aaabbbccc";
    letter_remove_consecutive_duplicates(str1);
    TEST_ASSERT_EQUAL_STRING("abc", str1);

    letter str2[] = "1223334444";
    letter_remove_consecutive_duplicates(str2);
    TEST_ASSERT_EQUAL_STRING("1234", str2);

    letter str3[] = "aabbcc";
    letter_remove_consecutive_duplicates(str3);
    TEST_ASSERT_EQUAL_STRING("abc", str3);
}

// Test cases for letter_capitalize_words
XTEST_CASE(test_capitalize_words) {
    letter str1[] = "hello world";
    letter_capitalize_words(str1);
    TEST_ASSERT_EQUAL_STRING("Hello World", str1);

    letter str2[] = "all CAPS";
    letter_capitalize_words(str2);
    TEST_ASSERT_EQUAL_STRING("All CAPS", str2);

    letter str3[] = "the Quick Brown FOX";
    letter_capitalize_words(str3);
    TEST_ASSERT_EQUAL_STRING("The Quick Brown FOX", str3);
}

// Test cases for letter_is_printable
XTEST_CASE(test_is_printable) {
    TEST_ASSERT_EQUAL_INT(1, letter_is_printable('A'));
    TEST_ASSERT_EQUAL_INT(1, letter_is_printable(' '));
    TEST_ASSERT_EQUAL_INT(1, letter_is_printable('~'));
    TEST_ASSERT_EQUAL_INT(0, letter_is_printable('\t'));
    TEST_ASSERT_EQUAL_INT(0, letter_is_printable('\n'));
}

// Test cases for letter_to_ascii
XTEST_CASE(test_to_ascii) {
    TEST_ASSERT_EQUAL_INT('A', letter_to_ascii('A'));
    TEST_ASSERT_EQUAL_INT(' ', letter_to_ascii(' '));
    TEST_ASSERT_EQUAL_INT('~', letter_to_ascii('~'));
}

// Test cases for letter_ascii_to_letter
XTEST_CASE(test_ascii_to_letter) {
    TEST_ASSERT_EQUAL_INT('A', letter_ascii_to_letter('A'));
    TEST_ASSERT_EQUAL_INT(' ', letter_ascii_to_letter(' '));
    TEST_ASSERT_EQUAL_INT('~', letter_ascii_to_letter('~'));
}

// Test cases for letter_shift_string
XTEST_CASE(test_shift_string) {
    letter str1[] = "Hello";
    letter_shift_string(str1, 1);
    TEST_ASSERT_EQUAL_STRING("Ifmmp", str1);

    letter str2[] = "Rotate by 5";
    letter_shift_string(str2, -5);
    TEST_ASSERT_EQUAL_STRING("Mjyjyd yn 5", str2);

    letter str3[] = "1234";
    letter_shift_string(str3, 3);
    TEST_ASSERT_EQUAL_STRING("4567", str3);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_letter_group) {
    XTEST_RUN_UNIT(letter_let_letter_count_in_string, runner);
    XTEST_RUN_UNIT(letter_let_letter_is_vowel,        runner);
    XTEST_RUN_UNIT(letter_let_letter_to_lowercase,    runner);
    XTEST_RUN_UNIT(letter_let_letter_to_uppercase,    runner);
    XTEST_RUN_UNIT(letter_let_letter_is_alpha,        runner);
    XTEST_RUN_UNIT(test_is_punctuation,                runner);
    XTEST_RUN_UNIT(test_is_whitespace,                 runner);
    XTEST_RUN_UNIT(test_remove_punctuation,            runner);
    XTEST_RUN_UNIT(test_remove_whitespace,             runner);
    XTEST_RUN_UNIT(test_replace_whitespace,            runner);
    XTEST_RUN_UNIT(test_remove_consecutive_duplicates, runner);
    XTEST_RUN_UNIT(test_capitalize_words,              runner);
    XTEST_RUN_UNIT(test_is_printable,                  runner);
    XTEST_RUN_UNIT(test_to_ascii,                      runner);
    XTEST_RUN_UNIT(test_ascii_to_letter,               runner);
    XTEST_RUN_UNIT(test_shift_string,                  runner);
    XTEST_RUN_UNIT(letter_let_letter_is_vowel_additional,        runner);
    XTEST_RUN_UNIT(letter_let_letter_to_lowercase_additional,    runner);
    XTEST_RUN_UNIT(letter_let_letter_to_uppercase_additional,    runner);
    XTEST_RUN_UNIT(letter_let_letter_count_in_string_additional, runner);
    XTEST_RUN_UNIT(letter_let_letter_is_alpha_additional,        runner);
} // end of function main
