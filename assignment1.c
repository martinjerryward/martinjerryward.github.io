#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 200

int main() {
    char input[MAX_INPUT_SIZE];
    char *token;
    FILE *outputFile;

    // Step 1: Prompt the user to enter a sentence with correct formatting
    printf("Please Enter Your Sentence: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Step 2: Split the sentence into words using strtok
    token = strtok(input, " \n");

    // Step 3: Open file for writing
    outputFile = fopen("Output.txt", "w");

    // Step 4: Loop through each word
    while (token != NULL) {
        printf("%s\n", token);      // Display word on screen
        fprintf(outputFile, "%s\n", token);  // Write word to file
        token = strtok(NULL, " \n");
    }

    // Add a newline after the last word in the file to avoid the prompt and last word being on the same line
    fprintf(outputFile, "\n");

    // Close the file
    fclose(outputFile);

    return 0;
}
