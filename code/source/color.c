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
#include "fossil/xstring/color.h"
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

cstring fscl_string_color_red_dark(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_RED_DARK) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_RED_DARK, str, ANSI_COLOR_RESET);
    return result;
}

cstring fscl_string_color_green_dark(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_GREEN_DARK) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_GREEN_DARK, str, ANSI_COLOR_RESET);
    return result;
}

cstring fscl_string_color_yellow_dark(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_YELLOW_DARK) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_YELLOW_DARK, str, ANSI_COLOR_RESET);
    return result;
}

cstring fscl_string_color_blue_dark(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_BLUE_DARK) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_BLUE_DARK, str, ANSI_COLOR_RESET);
    return result;
}

cstring fscl_string_color_magenta_dark(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_MAGENTA_DARK) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_MAGENTA_DARK, str, ANSI_COLOR_RESET);
    return result;
}

cstring fscl_string_color_cyan_dark(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_CYAN_DARK) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_CYAN_DARK, str, ANSI_COLOR_RESET);
    return result;
}

cstring fscl_string_color_white_dark(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_WHITE_DARK) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_WHITE_DARK, str, ANSI_COLOR_RESET);
    return result;
}

cstring fscl_string_color_red_light(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_RED_LIGHT) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_RED_LIGHT, str, ANSI_COLOR_RESET);
    return result;
}

cstring fscl_string_color_green_light(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_GREEN_LIGHT) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_GREEN_LIGHT, str, ANSI_COLOR_RESET);
    return result;
}

cstring fscl_string_color_yellow_light(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_YELLOW_LIGHT) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_YELLOW_LIGHT, str, ANSI_COLOR_RESET);
    return result;
}

cstring fscl_string_color_blue_light(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_BLUE_LIGHT) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_BLUE_LIGHT, str, ANSI_COLOR_RESET);
    return result;
}

cstring fscl_string_color_magenta_light(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_MAGENTA_LIGHT) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_MAGENTA_LIGHT, str, ANSI_COLOR_RESET);
    return result;
}

cstring fscl_string_color_cyan_light(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_CYAN_LIGHT) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_CYAN_LIGHT, str, ANSI_COLOR_RESET);
    return result;
}

cstring fscl_string_color_white_light(cstring str) {
    cstring result = (cstring)malloc(strlen(str) + strlen(ANSI_COLOR_WHITE_LIGHT) + strlen(ANSI_COLOR_RESET) + 1);
    sprintf(result, "%s%s%s", ANSI_COLOR_WHITE_LIGHT, str, ANSI_COLOR_RESET);
    return result;
}
