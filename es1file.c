#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    FILE *file;
    char filename[100];
    char ch;

    // Get the file name from the user
    printf("\nEnter the name of the file to read (remember the .txt): ");
    scanf("%s", filename);

    // Open the file in read mode
    file = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Could not open the file %s.\n", filename);
        return 1; // Return an error code
    }

    // Read and print the contents of the file character by character
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    // Close the file
    printf("\n");
    fclose(file);

    return 0; // Return success
}
