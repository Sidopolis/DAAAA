#include <stdio.h>

void decToBin(FILE *inFile, FILE *outFile, int n, int count)
{
    int decimal;
    if (fscanf(inFile, "%d", &decimal) != 1 || count >= n)
        return;
    decToBin(inFile, outFile, n, count + 1);
    int binary[32];
    int i = 0;
    while (decimal > 0)
    {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        fprintf(outFile, "%d",binary[j]);
    }
    fprintf(outFile, "\n");
}

int main()
{
    FILE *inputFile, *outputFile;
    int n;
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        printf("Error opening the input file.\n");
        return 1;
    }
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        printf("Error opening the output file.\n");
        fclose(inputFile);
        return 1;
    }
    printf("Enter the value of 'n' to convert the number present in input File: ");
    scanf("%d", &n);
    decToBin(inputFile, outputFile, n, 0);
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
