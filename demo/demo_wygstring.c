/*  ----------------------------------------------------------------------------
    File: demo_wygstring.c

    Description:
    This demo file serves as a showcase of the Trilobite Stdlib in action. It provides
    example code snippets and usage scenarios to help users understand how to leverage
    the library's features and functions in their own projects.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.home.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
*/
#include <trilobite/xstring/wygstring.h> // lib source code
#include <stdio.h>

int main() {
    cwygstring* wygstring = wygstring_create("Hello, WYSIWYG!");

    if (wygstring) {
        printf("Initial Text: %s\n", wygstring_get_text(wygstring));

        wygstring_append_text(wygstring, " Appended Text.");
        printf("After Appending: %s\n", wygstring_get_text(wygstring));

        wygstring_insert_text(wygstring, 6, " Inserted");
        printf("After Insertion: %s\n", wygstring_get_text(wygstring));

        wygstring_make_bold(wygstring, 0, 5);
        printf("After Making Bold: %s\n", wygstring_get_text(wygstring));

        wygstring_make_italic(wygstring, 0, 5);
        printf("After Making Italic: %s\n", wygstring_get_text(wygstring));

        wygstring_make_underlined(wygstring, 0, 5);
        printf("After Making Underlined: %s\n", wygstring_get_text(wygstring));

        cwygstring* wygstring2 = wygstring_create("Hello, WYSIWYG!");
        int comparison = wygstring_compare(wygstring, wygstring2);
        if (comparison == 0) {
            printf("Strings are equal.\n");
        } else {
            printf("Strings are not equal.\n");
        } // end if else
        wygstring_erase(wygstring2);

        cwygstring* concatenated = wygstring_copy(wygstring);
        wygstring_append_text(concatenated, " Additional Text");
        printf("Concatenated Text: %s\n", wygstring_get_text(concatenated));
        wygstring_erase(concatenated);

        int length = wygstring_length(wygstring);
        printf("Length of Text: %d\n", length);

        wygstring_erase(wygstring);
    } // end of concaten

    return 0;
} // end of func
