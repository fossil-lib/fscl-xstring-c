/*  ----------------------------------------------------------------------------
    File: color.c

    Description:
    This source file contains the code entry point for the Trilobite Stdlib project.
    It demonstrates the usage of various utilities and functions provided by the
    Trilobite Stdlib to enhance software development.

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
#include "trilobite/xstring/color.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ANSI escape codes for text colors
#define ANSI_COLOR_RESET   "\x1B[0m"

// Dark colors
#define ANSI_COLOR_RED_DARK     "\x1B[31;1m"
#define ANSI_COLOR_GREEN_DARK   "\x1B[32;1m"
#define ANSI_COLOR_YELLOW_DARK  "\x1B[33;1m"
#define ANSI_COLOR_BLUE_DARK    "\x1B[34;1m"
#define ANSI_COLOR_MAGENTA_DARK "\x1B[35;1m"
#define ANSI_COLOR_CYAN_DARK    "\x1B[36;1m"
#define ANSI_COLOR_WHITE_DARK   "\x1B[37;1m"

// Light colors
#define ANSI_COLOR_RED_LIGHT     "\x1B[91m"
#define ANSI_COLOR_GREEN_LIGHT   "\x1B[92m"
#define ANSI_COLOR_YELLOW_LIGHT  "\x1B[93m"
#define ANSI_COLOR_BLUE_LIGHT    "\x1B[94m"
#define ANSI_COLOR_MAGENTA_LIGHT "\x1B[95m"
#define ANSI_COLOR_CYAN_LIGHT    "\x1B[96m"
#define ANSI_COLOR_WHITE_LIGHT   "\x1B[97m"

cstring tscl_string_color_red_dark(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_RED_DARK) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_RED_DARK, str, ANSI_COLOR_RESET);
    return result;
}

cstring tscl_string_color_green_dark(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_GREEN_DARK) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_GREEN_DARK, str, ANSI_COLOR_RESET);
    return result;
}

cstring tscl_string_color_yellow_dark(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_YELLOW_DARK) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_YELLOW_DARK, str, ANSI_COLOR_RESET);
    return result;
}

cstring tscl_string_color_blue_dark(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_BLUE_DARK) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_BLUE_DARK, str, ANSI_COLOR_RESET);
    return result;
}

cstring tscl_string_color_magenta_dark(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_MAGENTA_DARK) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_MAGENTA_DARK, str, ANSI_COLOR_RESET);
    return result;
}

cstring tscl_string_color_cyan_dark(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_CYAN_DARK) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_CYAN_DARK, str, ANSI_COLOR_RESET);
    return result;
}

cstring tscl_string_color_white_dark(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_WHITE_DARK) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_WHITE_DARK, str, ANSI_COLOR_RESET);
    return result;
}

cstring tscl_string_color_red_light(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_RED_LIGHT) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_RED_LIGHT, str, ANSI_COLOR_RESET);
    return result;
}

cstring tscl_string_color_green_light(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_GREEN_LIGHT) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_GREEN_LIGHT, str, ANSI_COLOR_RESET);
    return result;
}

cstring tscl_string_color_yellow_light(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_YELLOW_LIGHT) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_YELLOW_LIGHT, str, ANSI_COLOR_RESET);
    return result;
}

cstring tscl_string_color_blue_light(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_BLUE_LIGHT) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_BLUE_LIGHT, str, ANSI_COLOR_RESET);
    return result;
}

cstring tscl_string_color_magenta_light(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_MAGENTA_LIGHT) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_MAGENTA_LIGHT, str, ANSI_COLOR_RESET);
    return result;
}

cstring tscl_string_color_cyan_light(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_CYAN_LIGHT) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_CYAN_LIGHT, str, ANSI_COLOR_RESET);
    return result;
}

cstring tscl_string_color_white_light(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_WHITE_LIGHT) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_WHITE_LIGHT, str, ANSI_COLOR_RESET);
    return result;
}
