#include <stdio.h>
#include <stdlib.h>

int main() {
    char inputName[100];
    char outputName[100];
    FILE *inFile;
    FILE *outFile;
    int ch;

    printf("Enter input file name: ");
    scanf("%99s", inputName);

    inFile = fopen(inputName, "r");
    if (inFile == NULL) {
        printf("Cannot open file %s for reading.\n", inputName);
        return 1;
    }

    printf("Enter output file name: ");
    scanf("%99s", outputName);

    outFile = fopen(outputName, "w");
    if (outFile == NULL) {
        printf("Cannot create or open file %s for writing.\n", outputName);
        fclose(inFile);
        return 2;
    }

    while ((ch = fgetc(inFile)) != EOF) {
        fputc(ch, outFile);
    }

    printf("Contents copied from %s to %s successfully.\n", inputName, outputName);

    fclose(inFile);
    fclose(outFile);

    return 0;
}
