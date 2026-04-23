// Date: 4/6/2026
// Name: Mr.lad
// Description:
// This program reads Elephant Seal weight data from a file,
// stores the values in an array, and calculates the average weight.

#include <stdio.h>

// Reads weights from the file into the array
// Input: weights[] (array to store values), size (number of elements), file_ptr (opened file)
// Output: fills the array with values from the file
void read_file(int weights[],int size,FILE *file_ptr){
	int index = 0;
	// Reads values from file into array 
	for (index = 0;index<size;index++){
		fscanf(file_ptr,"%d",&weights[index]);
		
	}
	
}

// Counts the number of integer values in the file
// Input: file_ptr (opened file)
// Output: returns number of values in the file 
int get_array_size(FILE *file_ptr){
	int index = 0;
	int value_holder;
	// Counts how many integers exist in the file
	while (fscanf(file_ptr,"%d",&value_holder)==1){
		index++;
	}
	printf("There are %d Elephant Seal weights in the file\n",index);
	rewind(file_ptr);// Rewinds file to begining
	return index;
}
// Calculates and prints the average of the weights array
// Input: array[] (weights), SIZE (number of elements)
// Output: prints the average weight
// Uses incremental averaging to compute the result efficiently
void calc_avg(int array[],int SIZE){
	double avg = 0.0;
	int index = 1;
	for (index = 1; index < SIZE+1; index++){
		avg += (array[index-1]-avg)/index;
	}
	printf("The Elephant Seal weight average is %lf\n",avg);
}

// Main function: opens file, determines size, reads data, and computes average
int main(){
	FILE *file_ptr = fopen("Elephant_weight_data.txt","r");
	// Checks if file failed to open
	if (file_ptr == NULL){
		printf("Error: File not found\n");
		return 1;
	}
	int size = get_array_size(file_ptr);
	int weight_array[size];
	read_file(weight_array,size,file_ptr);
	calc_avg(weight_array,size);
	fclose(file_ptr); // Closes file after use
	return 0;
}
