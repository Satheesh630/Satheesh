#include <stdio.h>
#include <string.h>
#include <ctype.h>

void findSmallestWord(const char *str, char *smallestWord) {
    int minLen = 1000; // Set to a high value initially
    int currentLen = 0;
    char currentWord[100];
    int j = 0;

    for (int i = 0; ; i++) {
        if (isspace(str[i]) || str[i] == '\0') {
            // End of a word
            if (currentLen > 0 && currentLen < minLen) {
                minLen = currentLen;
                currentWord[j] = '\0'; // Null-terminate the current word
                strcpy(smallestWord, currentWord); // Copy to smallestWord
            }
            currentLen = 0;
            j = 0; // Reset index for the next word

            // If it's the end of the string, break the loop
            if (str[i] == '\0') {
                break;
            }
        } else {
            // Part of a word
            currentWord[j++] = str[i];
            currentLen++;
        }
    }
}

int main() {
    char str[1000];
    char smallestWord[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Read the input string including spaces

    // Remove the newline character at the end, if present
    str[strcspn(str, "\n")] = '\0';

    findSmallestWord(str, smallestWord);

    printf("The smallest word is: \"%s\"\n", smallestWord);

    return 0;
}

