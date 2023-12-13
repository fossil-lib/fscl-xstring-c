/*
   This C header file is part of the Trilobite Stdlib, a collection of utility functions and
   standard data structures for enhancing software development projects. Feel free to use
   and modify these utilities to streamline your software development process.

   Project: Trilobite Stdlib
   Author: Michael Gene Brockus (Dreamer)
   Email: michaelbrockus@gmail.com
   Website: [Trilobite Coder Blog](https://trilobite.home.blog)

   Trilobite Stdlib is designed to provide a robust set of functionalities that can be
   incorporated into various projects. The utilities included in this library aim to optimize
   and standardize common operations, ensuring efficient and reliable code.

   This header file is a part of a broader initiative to support developers in creating secure,
   efficient, and scalable software. Contributions, suggestions, and feedback are welcomed,
   as we strive to continuously improve and expand the capabilities of Trilobite Stdlib.

   License: Apache License 2.0
   SPDX Identifier: Apache-2.0

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software distributed under the License
   is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
   or implied. See the License for the specific language governing permissions and limitations
   under the License.

   The above copyright notice and this permission notice shall be included in all copies or
   substantial portions of the Software.

   Please review the full text of the Apache License 2.0 for the complete terms and conditions.

   (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
*/
#ifndef TSCL_CIPHER_H
#define TSCL_CIPHER_H

#ifdef __cplusplus
extern "C"
{
#endif

// Define the cipher and const_cipher typedefs
typedef char *cipher;
typedef const char *const_cipher;

/**
 * @brief Encrypts a message using a Caesar cipher.
 *
 * @param message The message to be encrypted.
 * @param shift The shift value for the Caesar cipher.
 */
void cipher_caesar_encrypt(cipher message, int shift);

/**
 * @brief Decrypts a message encrypted with a Caesar cipher.
 *
 * @param message The encrypted message.
 * @param shift The shift value used for encryption.
 */
void cipher_caesar_decrypt(cipher message, int shift);

/**
 * @brief Encrypts a message using an Atbash cipher.
 *
 * @param message The message to be encrypted.
 */
void cipher_atbash_encrypt(cipher message);

/**
 * @brief Decrypts a message encrypted with an Atbash cipher.
 *
 * @param message The encrypted message.
 */
void cipher_atbash_decrypt(cipher message);

/**
 * @brief Encrypts a message using a Substitution cipher.
 *
 * @param message The message to be encrypted.
 * @param key The substitution key.
 */
void cipher_substitution_encrypt(cipher message, const_cipher key);

/**
 * @brief Decrypts a message encrypted with a Substitution cipher.
 *
 * @param message The encrypted message.
 * @param key The substitution key.
 */
void cipher_substitution_decrypt(cipher message, const_cipher key);

/**
 * @brief Encrypts a message using a Haxor cipher.
 *
 * @param message The message to be encrypted.
 */
void cipher_haxor_encrypt(cipher message);

/**
 * @brief Decrypts a message encrypted with a Haxor cipher.
 *
 * @param message The encrypted message.
 */
void cipher_haxor_decrypt(cipher message);

/**
 * @brief Converts a message to Morse code.
 *
 * @param message The message to be converted.
 */
void cipher_morse_encrypt(cipher message);

/**
 * @brief Converts Morse code to a readable message.
 *
 * @param message The Morse code to be decrypted.
 */
void cipher_morse_decrypt(cipher message);

/**
 * @brief Encrypts a message using a Rot13 cipher.
 *
 * @param message The message to be encrypted.
 */
void cipher_rot13_encrypt(cipher message);

/**
 * @brief Decrypts a message encrypted with a Rot13 cipher.
 *
 * @param message The encrypted message.
 */
void cipher_rot13_decrypt(cipher message);

/**
 * @brief Encrypts a message using a Playfair cipher.
 *
 * @param message The message to be encrypted.
 * @param key The key for the Playfair cipher.
 * @param encrypted The encrypted message (output parameter).
 */
void cipher_playfair_encrypt(cipher message, cipher key, cipher encrypted);

/**
 * @brief Decrypts a message encrypted with a Playfair cipher.
 *
 * @param message The encrypted message.
 * @param key The key for the Playfair cipher.
 * @param decrypted The decrypted message (output parameter).
 */
void cipher_playfair_decrypt(cipher message, cipher key, cipher decrypted);

/**
 * @brief Encrypts a message using a Rail Fence cipher.
 *
 * @param message The message to be encrypted.
 * @param rails The number of rails for the Rail Fence cipher.
 */
void cipher_rail_fence_encrypt(cipher message, int rails);

/**
 * @brief Decrypts a message encrypted with a Rail Fence cipher.
 *
 * @param message The encrypted message.
 * @param rails The number of rails used for encryption.
 */
void cipher_rail_fence_decrypt(cipher message, int rails);

/**
 * @brief Encrypts a message using a Vigenère cipher.
 *
 * @param message The message to be encrypted.
 * @param key The key for the Vigenère cipher.
 */
void cipher_vigenere_encrypt(cipher message, const_cipher key);

/**
 * @brief Decrypts a message encrypted with a Vigenère cipher.
 *
 * @param message The encrypted message.
 * @param key The key for the Vigenère cipher.
 */
void cipher_vigenere_decrypt(cipher message, const_cipher key);

#ifdef __cplusplus
}
#endif

#endif
