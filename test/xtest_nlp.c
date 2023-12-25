/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xstring/nlp.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test cases for the Caesar cipher
XTEST_CASE(test_tscl_string_lang_count_words) {
    // Test for tscl_string_lang_count_words function

    TEST_ASSERT_EQUAL(4, tscl_string_lang_count_words("This is a test"));  // Replace with your language-specific test cases
    TEST_ASSERT_EQUAL(3, tscl_string_lang_count_words("Hola, qué tal?"));
    // Add more test cases as needed
}

XTEST_CASE(test_tscl_string_lang_tokenize) {
    // Test for tscl_string_lang_tokenize function

    size_t tokenCount;
    char** tokens = tscl_string_lang_tokenize("This is another test.", &tokenCount);
    
    TEST_ASSERT_EQUAL(4, tokenCount);
    TEST_ASSERT_EQUAL_STRING("This", tokens[0]);
    TEST_ASSERT_EQUAL_STRING("is", tokens[1]);
    // Add more assertions for token values and count
    free(tokens);
}

XTEST_CASE(test_tscl_string_lang_detect_language) {
    // Test for tscl_string_lang_detect_language function

    TEST_ASSERT_EQUAL_STRING("English", tscl_string_lang_detect_language("This is an English sentence."));
    TEST_ASSERT_EQUAL_STRING("Spanish", tscl_string_lang_detect_language("Esto es una oración en español."));
    // Add more test cases for other supported languages
}

XTEST_CASE(test_tscl_string_lang_remove_stopwords) {
    // Test for tscl_string_lang_remove_stopwords function

    cstring sentence = "This is a test sentence.";
    cstring result = tscl_string_lang_remove_stopwords(sentence);

    TEST_ASSERT_EQUAL_STRING("test sentence.", result);
    free(result);
    // Add more test cases as needed
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_cipher_group) {
    XTEST_RUN_UNIT(test_tscl_string_lang_count_words,      runner);
    XTEST_RUN_UNIT(test_tscl_string_lang_tokenize,         runner);
    XTEST_RUN_UNIT(test_tscl_string_lang_detect_language,  runner);
    XTEST_RUN_UNIT(test_tscl_string_lang_remove_stopwords, runner);
} // end of function main
