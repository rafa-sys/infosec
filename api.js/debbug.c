#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char input[100];
    printf("Enter input: ");
    scanf("%s", input);
    // check if input is longer than 50 characters
    if (strlen(input) > 50) {
        printf("Input too long!\n");
        exit(1);
    }
    // Check if input contains any non-alphanumeric characters
    for (int i = 0; i < strlen(input); i++) {
        if (!isalnum(input[i])) {
            printf("Invalid input!\n");
            exit(1);
        }
    }
    // process input
    printf("Valid input: %s\n", input);
    return 0;
}
