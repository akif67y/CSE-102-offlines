#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str = NULL;
    int size = 0;       // Current size of allocated memory
    int ch;             // Temporary variable to store character input
    int len = 0;        // Number of characters read

    printf("Enter a string (Press Enter to finish): ");

    while ((ch = getchar()) != '\n' && ch != EOF) {
        // Reallocate memory to hold the new character
        char *temp = realloc(str, (len + 1) * sizeof(char));
        if (temp == NULL) {
            printf("Memory allocation failed\n");
            free(str); // Free memory before exiting
            return 1;
        }
        str = temp;
        str[len++] = (char)ch; // Store the character
    }

    // Add null terminator to make it a valid string
    char *temp = realloc(str, (len + 1) * sizeof(char));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        free(str);
        return 1;
    }
    str = temp;
    str[len] = '\0';

    printf("You entered: %s\n", str);

    free(str); // Free allocated memory
    return 0;
}
