/*
 * Name: Martin Ward
 * Banner ID: B00910313
 * Date: Thursday, Sept 26, 2024
 *
 * Assignment: 1
 * Professor: Qiang Ye
 * Marker: Kamran Awaisi
 * School: Dalhousie University
 *
 * Description:
 * This program prompts the user to enter a sentence. The sentence is then split into individual words,
 * which are displayed on the screen and written to a file named "Output.txt".
 *
 * Steps:
 * 1. Prompt the user for a sentence and read the input.
 * 2. Tokenize the input sentence into words.
 * 3. Display each word on the screen.
 * 4. Write each word to a new line in the output file "Output.txt".
 *
 */

// Included libraries
#include <stdio.h>
#include <string.h>

// Declare constants
#define MAX_INPUT_SIZE 200

// Prototypes
void getInput(char input[]);
void writeWordsToFile(char *token, FILE *outputFile);
FILE *openFile(const char *filename);

int main() {
    // Variable initialization and declaration
    char input[MAX_INPUT_SIZE];
    char *token;
    FILE *outputFile;

    // Step 1: Get user input
    getInput(input);

    // Step 2: Tokenize the input
    token = strtok(input, " \n");

    // Step 3: Open the file with a custom filename
    outputFile = openFile("Output.txt");
    if (outputFile == NULL) {
        return 1;  // Return if file cannot be opened
    }

    // Step 4: Write words to file and display them on the screen
    writeWordsToFile(token, outputFile);

    // Step 5: Close the file
    fclose(outputFile);

    return 0;
}

// Prompt the user for input
void getInput(char input[]) {
    printf("Please Enter Your Sentence: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
}

// Write words to screen & output file
void writeWordsToFile(char *token, FILE *outputFile) {
    while (token != NULL) {
        printf("%s\n", token);             // Display word on screen
        fprintf(outputFile, "%s", token);  // Write word to file

        token = strtok(NULL, " \n");       // Get the next token

        if (token != NULL) {
            fprintf(outputFile, "\n");     // Add newline if there are more tokens
        }
    }
}

// Function to open the file for writing with a given filename
FILE *openFile(const char *filename) {
    FILE *file = fopen(filename, "w");  // Open the file in write mode
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);  // Print error message with filename
        return NULL;
    }
    return file;  // Return the file pointer if successful
}
