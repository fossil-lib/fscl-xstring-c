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
#ifndef fscl_COLOR_H
#define fscl_COLOR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <fossil/xstring/cstring.h>

// =================================================================
// Available functions
// =================================================================
cstring fscl_string_color_red_dark(cstring str);
cstring fscl_string_color_green_dark(cstring str);
cstring fscl_string_color_yellow_dark(cstring str);
cstring fscl_string_color_blue_dark(cstring str);
cstring fscl_string_color_magenta_dark(cstring str);
cstring fscl_string_color_cyan_dark(cstring str);
cstring fscl_string_color_white_dark(cstring str);
cstring fscl_string_color_red_light(cstring str);
cstring fscl_string_color_green_light(cstring str);
cstring fscl_string_color_yellow_light(cstring str);
cstring fscl_string_color_blue_light(cstring str);
cstring fscl_string_color_magenta_light(cstring str);
cstring fscl_string_color_cyan_light(cstring str);
cstring fscl_string_color_white_light(cstring str);

#ifdef __cplusplus
}
#endif

#endif
