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
#ifndef fscl_CIPHER_H
#define fscl_CIPHER_H

#ifdef __cplusplus
extern "C"
{
#endif

// Define the cipher and const_cipher typedefs
typedef char *cipher;
typedef const char *const_cipher;

// =================================================================
// Available functions
// =================================================================
void fscl_cipher_caesar_encrypt(cipher message, int shift);
void fscl_cipher_caesar_decrypt(cipher message, int shift);
void fscl_cipher_atbash_encrypt(cipher message);
void fscl_cipher_atbash_decrypt(cipher message);
void fscl_cipher_substitution_encrypt(cipher message, const_cipher key);
void fscl_cipher_substitution_decrypt(cipher message, const_cipher key);
void fscl_cipher_haxor_encrypt(cipher message);
void fscl_cipher_haxor_decrypt(cipher message);
void fscl_cipher_morse_encrypt(cipher message);
void fscl_cipher_morse_decrypt(cipher message);
void fscl_cipher_rot13_encrypt(cipher message);
void fscl_cipher_rot13_decrypt(cipher message);
void fscl_cipher_playfair_encrypt(cipher message, cipher key, cipher encrypted);
void fscl_cipher_playfair_decrypt(cipher message, cipher key, cipher decrypted);
void fscl_cipher_rail_fence_encrypt(cipher message, int rails);
void fscl_cipher_rail_fence_decrypt(cipher message, int rails);
void fscl_cipher_vigenere_encrypt(cipher message, const_cipher key);
void fscl_cipher_vigenere_decrypt(cipher message, const_cipher key);

#ifdef __cplusplus
}
#endif

#endif
