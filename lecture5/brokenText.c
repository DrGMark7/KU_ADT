#include <stdio.h>
#include <string.h>

#define MAX_LEN 100000

int main() {
    char input[MAX_LEN];
    char output[MAX_LEN];
    int cursorPos = 0; // to keep track of the cursor position
    int len = 0;      // to keep track of the actual length of the output string

    // Read input
    fgets(input, MAX_LEN, stdin);

    // Initialize output buffer
    memset(output, '\0', sizeof(output));
    
    // Process each character in the input
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '<') {
            cursorPos = 0; // Move cursor to the beginning
        } else if (input[i] == '>') {
            cursorPos = len; // Move cursor to the end
        } else {
            // Shift characters to the right to make room for the new character
            for (int j = len; j > cursorPos; j--) {
                output[j] = output[j-1];
            }
            // Insert the new character at the current cursor position
            output[cursorPos] = input[i];
            cursorPos++;
            len++;
        }
    }

    // Output the result
    printf("%s\n", output);

    return 0;
}