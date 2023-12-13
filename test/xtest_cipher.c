/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xstring/cipher.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xmock.h>   // handy mock utilites
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test cases for the Caesar cipher
XTEST_CASE(test_caesar_encrypt) {
    char message[] = "HELLO";
    cipher_caesar_encrypt(message, 3);
    TEST_ASSERT_EQUAL_STRING("KHOOR", message);
}

XTEST_CASE(test_caesar_decrypt) {
    char message[] = "KHOOR";
    cipher_caesar_decrypt(message, 3);
    TEST_ASSERT_EQUAL_STRING("HELLO", message);
}

// Test cases for the Atbash cipher
XTEST_CASE(test_atbash_encrypt) {
    char message[] = "HELLO";
    cipher_atbash_encrypt(message);
    TEST_ASSERT_EQUAL_STRING("SVOOL", message);
}

XTEST_CASE(test_atbash_decrypt) {
    char message[] = "SVOOL";
    cipher_atbash_decrypt(message);
    TEST_ASSERT_EQUAL_STRING("HELLO", message);
}

// Test cases for the Substitution cipher
XTEST_CASE(test_substitution_encrypt) {
    char message[] = "HELLO";
    const_cipher key = "PHQGIUMEAYLNOFDXJKRCVSTZWB";
    cipher_substitution_encrypt(message, key);
    TEST_ASSERT_EQUAL_STRING("EHBBQ", message);
}

XTEST_CASE(test_substitution_decrypt) {
    char message[] = "EHBBQ";
    const_cipher key = "PHQGIUMEAYLNOFDXJKRCVSTZWB";
    cipher_substitution_decrypt(message, key);
    TEST_ASSERT_EQUAL_STRING("HELLO", message);
}

// Test cases for the Haxor cipher
XTEST_CASE(test_haxor_encrypt) {
    char message[] = "HELLO";
    cipher_haxor_encrypt(message);
    TEST_ASSERT_EQUAL_STRING("H3LLO", message);
}

XTEST_CASE(test_haxor_decrypt) {
    char message[] = "H3LLO";
    cipher_haxor_decrypt(message);
    TEST_ASSERT_EQUAL_STRING("HELLO", message);
}

// Test cases for Morse code
XTEST_CASE(test_morse_encrypt) {
    char message[] = "HELLO";
    cipher_morse_encrypt(message);
    TEST_ASSERT_EQUAL_STRING(".... .-.. .-.. ---", message);
}

XTEST_CASE(test_morse_decrypt) {
    char message[] = ".... .-.. .-.. ---";
    cipher_morse_decrypt(message);
    TEST_ASSERT_EQUAL_STRING("HELLO", message);
}

// Test cases for Rot13 cipher
XTEST_CASE(test_rot13_encrypt) {
    char message[] = "HELLO";
    cipher_rot13_encrypt(message);
    TEST_ASSERT_EQUAL_STRING("URYYB", message);
}

XTEST_CASE(test_rot13_decrypt) {
    char message[] = "URYYB";
    cipher_rot13_decrypt(message);
    TEST_ASSERT_EQUAL_STRING("HELLO", message);
}

// Test cases for Playfair cipher
XTEST_CASE(test_playfair_encrypt) {
    char message[] = "HELLO";
    cipher key = "KEYWORD";
    char encrypted[100];  // Adjust size accordingly
    cipher_playfair_encrypt(message, key, encrypted);
    TEST_ASSERT_EQUAL_STRING("RIJVS", encrypted);
}

XTEST_CASE(test_playfair_decrypt) {
    char message[] = "RIJVS";
    cipher key = "KEYWORD";
    char decrypted[100];  // Adjust size accordingly
    cipher_playfair_decrypt(message, key, decrypted);
    TEST_ASSERT_EQUAL_STRING("HELLO", decrypted);
}

// Test cases for Rail Fence cipher
XTEST_CASE(test_rail_fence_encrypt) {
    char message[] = "HELLO";
    cipher_rail_fence_encrypt(message, 2);
    TEST_ASSERT_EQUAL_STRING("HOLEL", message);
}

XTEST_CASE(test_rail_fence_decrypt) {
    char message[] = "HOLEL";
    cipher_rail_fence_decrypt(message, 2);
    TEST_ASSERT_EQUAL_STRING("HELLO", message);
}

// Test cases for Vigenere cipher
XTEST_CASE(test_vigenere_encrypt) {
    char message[] = "HELLO";
    const_cipher key = "KEY";
    cipher_vigenere_encrypt(message, key);
    TEST_ASSERT_EQUAL_STRING("RIJVS", message);
}

XTEST_CASE(test_vigenere_decrypt) {
    char message[] = "RIJVS";
    const_cipher key = "KEY";
    cipher_vigenere_decrypt(message, key);
    TEST_ASSERT_EQUAL_STRING("HELLO", message);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_cipher_group) {
    XTEST_RUN_UNIT(test_caesar_encrypt,     runner);
    XTEST_RUN_UNIT(test_caesar_decrypt,     runner);
    XTEST_RUN_UNIT(test_atbash_encrypt,     runner);
    XTEST_RUN_UNIT(test_atbash_decrypt,     runner);
    XTEST_RUN_UNIT(test_haxor_encrypt,      runner);
    XTEST_RUN_UNIT(test_haxor_decrypt,      runner);
    XTEST_RUN_UNIT(test_morse_encrypt,      runner);
    XTEST_RUN_UNIT(test_morse_decrypt,      runner);
    XTEST_RUN_UNIT(test_rot13_encrypt,      runner);
    XTEST_RUN_UNIT(test_rot13_decrypt,      runner);
    XTEST_RUN_UNIT(test_playfair_encrypt,   runner);
    XTEST_RUN_UNIT(test_playfair_decrypt,   runner);
    XTEST_RUN_UNIT(test_rail_fence_encrypt, runner);
    XTEST_RUN_UNIT(test_rail_fence_decrypt, runner);
    XTEST_RUN_UNIT(test_vigenere_encrypt,   runner);
    XTEST_RUN_UNIT(test_vigenere_decrypt,   runner);
    XTEST_RUN_UNIT(test_substitution_encrypt, runner);
    XTEST_RUN_UNIT(test_substitution_decrypt, runner);
} // end of function main
