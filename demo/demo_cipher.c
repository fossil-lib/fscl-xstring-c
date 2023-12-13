/*  ----------------------------------------------------------------------------
    File: demo_cipher.c

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
#include <trilobite/xstring/cipher.h> // lib source code
#include <stdio.h>
#include <string.h>

// Define the maximum size of the message
#define MAX_SIZE 1000

void displayMenu() {
    printf("\nChoose a cipher:\n");
    printf("1. Caesar Cipher\n");
    printf("2. Atbash Cipher\n");
    printf("3. Substitution Cipher\n");
    printf("4. Haxor Cipher\n");
    printf("5. Morse Code\n");
    printf("6. Rot13 Cipher\n");
    printf("7. Playfair Cipher\n");
    printf("8. Rail Fence Cipher\n");
    printf("9. Vigenere Cipher\n");
    printf("\nEnter 0 to exit.\n");
}

void getUserInput(char *input, int size) {
    while (getchar() != '\n');  // Clear input buffer
    fgets(input, size, stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove newline character
}

void processCipherChoice(int choice, cipher message, const_cipher key) {
    switch (choice) {
        case 1:
            printf("\nCaesar Cipher - Encryption:\n");
            cipher_caesar_encrypt(message, 3);
            break;
        case 2:
            printf("\nAtbash Cipher - Encryption:\n");
            cipher_atbash_encrypt(message);
            break;
        case 3:
            printf("\nSubstitution Cipher - Encryption:\n");
            cipher_substitution_encrypt(message, key);
            break;
        case 4:
            printf("\nHaxor Cipher - Encryption:\n");
            cipher_haxor_encrypt(message);
            break;
        case 5:
            printf("\nMorse Code - Encryption:\n");
            cipher_morse_encrypt(message);
            break;
        case 6:
            printf("\nRot13 Cipher - Encryption:\n");
            cipher_rot13_encrypt(message);
            break;
        case 7:
            printf("\nPlayfair Cipher - Encryption:\n");
            {
                cipher encryptedMessage[MAX_SIZE];
                cipher_playfair_encrypt(message, key, encryptedMessage);
                printf("Encrypted Message: %s\n", encryptedMessage);
            }
            break;
        case 8:
            printf("\nRail Fence Cipher - Encryption:\n");
            cipher_rail_fence_encrypt(message, 2);
            break;
        case 9:
            printf("\nVigenere Cipher - Encryption:\n");
            cipher_vigenere_encrypt(message, key);
            break;
        case 0:
            printf("\nExiting the program.\n");
            break;
        default:
            printf("\nInvalid choice.\n");
            break;
    }
}

int main() {
    char message[MAX_SIZE];
    char key[MAX_SIZE];
    int choice;

    printf("Enter the message to encrypt or decrypt: ");
    getUserInput(message, MAX_SIZE);

    printf("Enter the key (if applicable): ");
    getUserInput(key, MAX_SIZE);

    displayMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    processCipherChoice(choice, message, key);

    return 0;
} // end of func
