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
// Available Functions
// =================================================================

/**
 * Encrypt a message using the Caesar cipher.
 *
 * @param message The message to encrypt.
 * @param shift   The shift value for encryption.
 */
void fscl_cipher_caesar_encrypt(cipher message, int shift);

/**
 * Decrypt a message encrypted with the Caesar cipher.
 *
 * @param message The message to decrypt.
 * @param shift   The shift value for decryption.
 */
void fscl_cipher_caesar_decrypt(cipher message, int shift);

/**
 * Encrypt a message using the Atbash cipher.
 *
 * @param message The message to encrypt.
 */
void fscl_cipher_atbash_encrypt(cipher message);

/**
 * Decrypt a message encrypted with the Atbash cipher.
 *
 * @param message The message to decrypt.
 */
void fscl_cipher_atbash_decrypt(cipher message);

/**
 * Encrypt a message using the Substitution cipher with a given key.
 *
 * @param message The message to encrypt.
 * @param key     The substitution key.
 */
void fscl_cipher_substitution_encrypt(cipher message, const_cipher key);

/**
 * Decrypt a message encrypted with the Substitution cipher with a given key.
 *
 * @param message The message to decrypt.
 * @param key     The substitution key.
 */
void fscl_cipher_substitution_decrypt(cipher message, const_cipher key);

/**
 * Encrypt a message using the Haxor cipher.
 *
 * @param message The message to encrypt.
 */
void fscl_cipher_haxor_encrypt(cipher message);

/**
 * Decrypt a message encrypted with the Haxor cipher.
 *
 * @param message The message to decrypt.
 */
void fscl_cipher_haxor_decrypt(cipher message);

/**
 * Encrypt a message using the Morse code.
 *
 * @param message The message to encrypt.
 */
void fscl_cipher_morse_encrypt(cipher message);

/**
 * Decrypt a message encrypted with the Morse code.
 *
 * @param message The message to decrypt.
 */
void fscl_cipher_morse_decrypt(cipher message);

/**
 * Encrypt a message using the ROT13 cipher.
 *
 * @param message The message to encrypt.
 */
void fscl_cipher_rot13_encrypt(cipher message);

/**
 * Decrypt a message encrypted with the ROT13 cipher.
 *
 * @param message The message to decrypt.
 */
void fscl_cipher_rot13_decrypt(cipher message);

/**
 * Encrypt a message using the Playfair cipher with a given key.
 *
 * @param message    The message to encrypt.
 * @param key        The Playfair key.
 * @param encrypted  The encrypted message.
 */
void fscl_cipher_playfair_encrypt(cipher message, cipher key, cipher encrypted);

/**
 * Decrypt a message encrypted with the Playfair cipher with a given key.
 *
 * @param message    The message to decrypt.
 * @param key        The Playfair key.
 * @param decrypted  The decrypted message.
 */
void fscl_cipher_playfair_decrypt(cipher message, cipher key, cipher decrypted);

/**
 * Encrypt a message using the Rail Fence cipher with a given number of rails.
 *
 * @param message The message to encrypt.
 * @param rails   The number of rails in the Rail Fence.
 */
void fscl_cipher_rail_fence_encrypt(cipher message, int rails);

/**
 * Decrypt a message encrypted with the Rail Fence cipher with a given number of rails.
 *
 * @param message The message to decrypt.
 * @param rails   The number of rails in the Rail Fence.
 */
void fscl_cipher_rail_fence_decrypt(cipher message, int rails);

/**
 * Encrypt a message using the Vigenere cipher with a given key.
 *
 * @param message The message to encrypt.
 * @param key     The Vigenere key.
 */
void fscl_cipher_vigenere_encrypt(cipher message, const_cipher key);

/**
 * Decrypt a message encrypted with the Vigenere cipher with a given key.
 *
 * @param message The message to decrypt.
 * @param key     The Vigenere key.
 */
void fscl_cipher_vigenere_decrypt(cipher message, const_cipher key);

#ifdef __cplusplus
}
#endif

#endif
