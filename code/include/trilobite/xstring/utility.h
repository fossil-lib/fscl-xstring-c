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
#ifndef TSCL_UTIL_H
#define TSCL_UTIL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>
#include <xstring/cstring.h>

// =================================================================
// Available functions
// =================================================================
size_t tscl_string_length(const_cstring str);
cstring tscl_string_copy(const_cstring src);
cstring tscl_string_concat(const_cstring str1, const_cstring str2);
int tscl_string_compare(const_cstring str1, const_cstring str2);
cstring tscl_string_substr(const_cstring str, size_t start, size_t length);
int tscl_string_find(const_cstring str, const_cstring substr);
int tscl_string_rfind(const_cstring str, const_cstring substr);
cstring *tscl_string_split(const_cstring str, const_cstring delimiter);
cstring tscl_string_to_upper(const_cstring str);
cstring tscl_string_to_lower(const_cstring str);
cstring tscl_string_trim(const_cstring str);
cstring tscl_string_reverse(const_cstring str);
cstring tscl_string_replace(cstring str, const_cstring find, const_cstring replace);
cstring tscl_string_shuffle(const_cstring str);
cstring tscl_string_make_silly(const_cstring str);
cstring tscl_string_strdup(const_cstring str);
int tscl_string_starts_with(const_cstring str, const_cstring prefix);
int tscl_string_ends_with(const_cstring str, const_cstring suffix);
cstring tscl_string_pad(const_cstring str, size_t length, char padding_char);
cstring tscl_string_remove_char(const_cstring str, char char_to_remove);
size_t tscl_string_count_substring(cstring str, const_cstring substr);
cstring tscl_string_reverse_words(const_cstring str);
cstring tscl_string_to_title_case(const_cstring str);
cstring tscl_string_remove_consecutive_duplicates(const_cstring str);
cstring tscl_string_remove_extra_spaces(const_cstring str);

#ifdef __cplusplus
}
#endif

#endif
