/*  ----------------------------------------------------------------------------
    File: cipher.c

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
#include "trilobite/xstring/cipher.h"
#include <ctype.h>
#include <string.h>

// Define Morse code mappings
const char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
                            "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                            "..-", "...-", ".--", "-..-", "-.--", "--.."};

void tscl_cipher_caesar_encrypt(cipher message, int shift) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            message[i] = (message[i] - base + shift) % 26 + base;
        }
    }
} // end of func

void tscl_cipher_caesar_decrypt(cipher message, int shift) {
    tscl_cipher_caesar_encrypt(message, -shift);
} // end of func

void tscl_cipher_atbash_encrypt(cipher message) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            message[i] = 'Z' - (message[i] - base);
        }
    }
} // end of func

void tscl_cipher_atbash_decrypt(cipher message) {
    tscl_cipher_atbash_encrypt(message);
} // end of func

void tscl_cipher_substitution_encrypt(cipher message, const_cipher key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            message[i] = key[message[i] - base];
        }
    }
} // end of func

void tscl_cipher_substitution_decrypt(cipher message, const_cipher key) {
    char decrypt_key[26];

    // Create the decryption key by reversing the original key
    for (int i = 0; i < 26; ++i) {
        decrypt_key[key[i] - 'A'] = 'A' + i;
    }

    tscl_cipher_substitution_encrypt(message, decrypt_key);
} // end of func

void tscl_cipher_haxor_encrypt(cipher message) {
    for (int i = 0; message[i] != '\0'; ++i) {
        switch (message[i]) {
            case 'a':
            case 'A':
                message[i] = '4';
                break;
            case 'e':
            case 'E':
                message[i] = '3';
                break;
            case 'i':
            case 'I':
                message[i] = '1';
                break;
            case 'o':
            case 'O':
                message[i] = '0';
                break;
            case 's':
            case 'S':
                message[i] = '5';
                break;
            case 't':
            case 'T':
                message[i] = '7';
                break;
        }
    }
} // end of func

void tscl_cipher_haxor_decrypt(cipher message) {
    // The Haxor cipher is symmetric, decryption is the same as encryption
    tscl_cipher_haxor_encrypt(message);
} // end of func

void tscl_cipher_morse_encrypt(cipher message) {
    char result[1000];  // Adjust the size accordingly

    for (int i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            int index = toupper(message[i]) - 'A';
            strcat(result, morse_code[index]);
            strcat(result, " ");  // Add space between Morse code letters
        } else if (message[i] == ' ') {
            strcat(result, "/ ");  // Add slash to represent space in Morse code
        }
    }

    strcpy(message, result);
} // end of func

void tscl_cipher_morse_decrypt(cipher message) {
    char *token;
    char result[1000];  // Adjust the size accordingly

    token = strtok(message, " ");
    while (token != NULL) {
        for (int i = 0; i < 26; ++i) {
            if (strcmp(token, morse_code[i]) == 0) {
                result[strlen(result)] = 'A' + i;
                break;
            }
        }

        if (strcmp(token, "/") == 0) {
            result[strlen(result)] = ' ';  // Add space for slash
        }

        token = strtok(NULL, " ");
    }

    strcpy(message, result);
} // end of func

void tscl_cipher_vigenere_encrypt(cipher message, const_cipher key) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);

    for (int i = 0, j = 0; i < messageLen; ++i) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            char keyChar = toupper(key[j % keyLen]);

            message[i] = (message[i] - base + keyChar - 'A') % 26 + base;
            ++j;
        }
    }
}

void tscl_cipher_vigenere_decrypt(cipher message, const_cipher key) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);

    for (int i = 0, j = 0; i < messageLen; ++i) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            char keyChar = toupper(key[j % keyLen]);

            message[i] = (message[i] - base - (keyChar - 'A') + 26) % 26 + base;
            ++j;
        }
    }
}

void tscl_cipher_rail_fence_encrypt(cipher message, int rails) {
    int messageLen = strlen(message);
    char encrypted[1000]; // Adjust the size accordingly

    int index = 0;
    for (int i = 0; i < rails; ++i) {
        for (int j = i; j < messageLen; j += rails) {
            encrypted[index++] = message[j];
        }
    }

    encrypted[index] = '\0';
    strcpy(message, encrypted);
}

void tscl_cipher_rail_fence_decrypt(cipher message, int rails) {
    int messageLen = strlen(message);
    char decrypted[1000]; // Adjust the size accordingly

    int index = 0;
    for (int i = 0; i < rails; ++i) {
        for (int j = i; j < messageLen; j += rails) {
            decrypted[j] = message[index++];
        }
    }

    decrypted[messageLen] = '\0';
    strcpy(message, decrypted);
}

void tscl_cipher_rot13_encrypt(cipher message) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            message[i] = (message[i] - base + 13) % 26 + base;
        }
    }
}

void tscl_cipher_rot13_decrypt(cipher message) {
    // The Rot13 cipher is symmetric, decryption is the same as encryption
    tscl_cipher_rot13_encrypt(message);
}

enum {SIZE = 5};

void prepare_playfair_key(cipher key, char keyTable[SIZE][SIZE]) {
    char* temp = key;
    int i, j;
    int is_present[26] = {0};

    // Fill in the key table with unique letters from the key
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            while (is_present[*temp - 'A'] || *temp == 'J') {
                if (*temp == 'J') {
                    is_present['I' - 'A'] = 1;
                } else {
                    is_present[*temp - 'A'] = 1;
                }
                temp++;
            }
            keyTable[i][j] = *temp;
            is_present[*temp - 'A'] = 1;
            temp++;
        }
    }
}

void get_playfair_pos(char keyTable[SIZE][SIZE], char ch, int* row, int* col) {
    if (ch == 'J') {
        ch = 'I';
    }

    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (keyTable[*row][*col] == ch) {
                return;
            }
        }
    }
}

void tscl_cipher_playfair_encrypt(cipher message, cipher key, cipher encrypted) {
    char keyTable[SIZE][SIZE];
    prepare_playfair_key(key, keyTable);

    int i, len = strlen(message);
    int row1, col1, row2, col2;
    int index = 0;

    for (i = 0; i < len; i += 2) {
        get_playfair_pos(keyTable, message[i], &row1, &col1);
        get_playfair_pos(keyTable, message[i + 1], &row2, &col2);

        if (row1 == row2) {
            encrypted[index++] = keyTable[row1][(col1 + 1) % SIZE];
            encrypted[index++] = keyTable[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            encrypted[index++] = keyTable[(row1 + 1) % SIZE][col1];
            encrypted[index++] = keyTable[(row2 + 1) % SIZE][col2];
        } else {
            encrypted[index++] = keyTable[row1][col2];
            encrypted[index++] = keyTable[row2][col1];
        }
    }

    encrypted[index] = '\0';
}

void tscl_cipher_playfair_decrypt(cipher message, cipher key, cipher decrypted) {
    char keyTable[SIZE][SIZE];
    prepare_playfair_key(key, keyTable);

    int i, len = strlen(message);
    int row1, col1, row2, col2;
    int index = 0;

    for (i = 0; i < len; i += 2) {
        get_playfair_pos(keyTable, message[i], &row1, &col1);
        get_playfair_pos(keyTable, message[i + 1], &row2, &col2);

        if (row1 == row2) {
            decrypted[index++] = keyTable[row1][(col1 - 1 + SIZE) % SIZE];
            decrypted[index++] = keyTable[row2][(col2 - 1 + SIZE) % SIZE];
        } else if (col1 == col2) {
            decrypted[index++] = keyTable[(row1 - 1 + SIZE) % SIZE][col1];
            decrypted[index++] = keyTable[(row2 - 1 + SIZE) % SIZE][col2];
        } else {
            decrypted[index++] = keyTable[row1][col2];
            decrypted[index++] = keyTable[row2][col1];
        }
    }

    decrypted[index] = '\0';
}