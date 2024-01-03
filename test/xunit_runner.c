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
#include <fossil/xtest.h>

//
// XUNIT-GROUP: list of test groups for the runner
//
XTEST_EXTERN_POOL(test_letter_group   );
XTEST_EXTERN_POOL(test_string_group   );
XTEST_EXTERN_POOL(test_fscl_wygstring_group);
XTEST_EXTERN_POOL(test_fscl_cipher_group   );
XTEST_EXTERN_POOL(test_number_group   );
XTEST_EXTERN_POOL(test_color_group   );
XTEST_EXTERN_POOL(test_nlp_group      );

//
// XUNIT-TEST RUNNER
//
int main(int argc, char **argv) {
    XTEST_CREATE(argc, argv);

    XTEST_IMPORT_POOL(test_fscl_wygstring_group);
    XTEST_IMPORT_POOL(test_fscl_cipher_group);
    XTEST_IMPORT_POOL(test_string_group);
    XTEST_IMPORT_POOL(test_letter_group);
    XTEST_IMPORT_POOL(test_number_group);
    XTEST_IMPORT_POOL(test_color_group);
    XTEST_IMPORT_POOL(test_nlp_group);

    return XTEST_ERASE();
} // end of func
