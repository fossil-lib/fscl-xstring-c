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

// =================================================================
// Available functions
// =================================================================
void tscl_cipher_caesar_encrypt(cipher message, int shift);
void tscl_cipher_caesar_decrypt(cipher message, int shift);
void tscl_cipher_atbash_encrypt(cipher message);
void tscl_cipher_atbash_decrypt(cipher message);
void tscl_cipher_substitution_encrypt(cipher message, const_cipher key);
void tscl_cipher_substitution_decrypt(cipher message, const_cipher key);
void tscl_cipher_haxor_encrypt(cipher message);
void tscl_cipher_haxor_decrypt(cipher message);
void tscl_cipher_morse_encrypt(cipher message);
void tscl_cipher_morse_decrypt(cipher message);
void tscl_cipher_rot13_encrypt(cipher message);
void tscl_cipher_rot13_decrypt(cipher message);
void tscl_cipher_playfair_encrypt(cipher message, cipher key, cipher encrypted);
void tscl_cipher_playfair_decrypt(cipher message, cipher key, cipher decrypted);
void tscl_cipher_rail_fence_encrypt(cipher message, int rails);
void tscl_cipher_rail_fence_decrypt(cipher message, int rails);
void tscl_cipher_vigenere_encrypt(cipher message, const_cipher key);
void tscl_cipher_vigenere_decrypt(cipher message, const_cipher key);

#ifdef __cplusplus
}
#endif

#endif
