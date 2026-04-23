// IF THIS IS NOT EMPTY THIS IS A WORK OF ANOTHER 
// FOR MY COURSE I NEED TO REVIEW OTHERS' CODE. 
// I USE THIS FILE TO CHECK, 
// AND PASTE / DELETE THEIR CODE
//
//################################################################################################################################################################################################################
//################################################################################################################################################################################################################


#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *infile, *outfile;
    int *data;
    int count, i, max;
    double sum = 0.0, average;

    // Open the input file
    infile = fopen("input.txt", "r");
    if (infile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read the first integer (number of elements)
    if (fscanf(infile, "%d", &count) != 1 || count <= 0) {
        printf("Invalid or missing count in input file.\n");
        fclose(infile);
        return 1;
    }

    // Allocate memory for data array
    data = (int *)malloc(count * sizeof(int));
    if (data == NULL) {
        printf("Memory allocation failed.\n");
        fclose(infile);
        return 1;
    }

    // Read the rest of the integers into the array
    for (i = 0; i < count; i++) {
        if (fscanf(infile, "%d", &data[i]) != 1) {
            printf("Error reading value %d from file.\n", i + 1);
            free(data);
            fclose(infile);
            return 1;
        }
        sum += data[i];
    }
    fclose(infile);

    // Calculate average
    average = sum / count;

    // Find max
    max = data[0];
    for (i = 1; i < count; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }

    // Print results to screen
    printf("Number of values: %d\n", count);
    printf("Values: ");
    for (i = 0; i < count; i++) {
        printf("%d ", data[i]);
    }
    printf("\nAverage: %.2f\n", average);
    printf("Maximum: %d\n", max);

    // Write results to output file
    outfile = fopen("answer-hw3.txt", "w");
    if (outfile == NULL) {
        printf("Error creating output file.\n");
        free(data);
        return 1;
    }

    fprintf(outfile, "Number of values: %d\n", count);
    fprintf(outfile, "Values: ");
    for (i = 0; i < count; i++) {
        fprintf(outfile, "%d ", data[i]);
    }
    fprintf(outfile, "\nAverage: %.2f\n", average);
    fprintf(outfile, "Maximum: %d\n", max);

    fclose(outfile);
    free(data);
    return 0;
}
