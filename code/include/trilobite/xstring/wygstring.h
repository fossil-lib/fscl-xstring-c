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
#ifndef TSCL_WYGSTRING_H
#define TSCL_WYGSTRING_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>

typedef struct {
    char* text;
    int length;
} cwygstring;

// =================================================================
// Available functions
// =================================================================
cwygstring* tscl_wygstring_create(const char* text);
void tscl_wygstring_set_text(cwygstring* wygstring, const char* text);
const char* tscl_wygstring_get_text(const cwygstring* wygstring);
void tscl_wygstring_erase(cwygstring* wygstring);
void tscl_wygstring_append_text(cwygstring* wygstring, const char* text_to_append);
void tscl_wygstring_insert_text(cwygstring* wygstring, int position, const char* text_to_insert);
void tscl_wygstring_make_bold(cwygstring* wygstring, int start, int end);
void tscl_wygstring_make_italic(cwygstring* wygstring, int start, int end);
void tscl_wygstring_make_underlined(cwygstring* wygstring, int start, int end);
int tscl_wygstring_compare(const cwygstring* str1, const cwygstring* str2);
void tscl_wygstring_concat(cwygstring* dest, const cwygstring* src);
cwygstring* tscl_wygstring_copy(const cwygstring* wygstring);
int tscl_wygstring_length(const cwygstring* wygstring);
void tscl_wygstring_trim(cwygstring* wygstring);
void tscl_wygstring_to_lowercase(cwygstring* wygstring);
void tscl_wygstring_to_uppercase(cwygstring* wygstring);
void tscl_wygstring_replace_text(cwygstring* wygstring, int start, int end, const char* replacement);

#ifdef __cplusplus
}
#endif

#endif
