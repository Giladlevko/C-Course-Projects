// Date:3/31/2026
// Name: Gilad Levkowitz
// Description:
// This program prints a table of sine and cosine values
// for values between 0 and 1 (inclusive) with an increment of 0.1. 

#include <stdio.h>
#include <math.h>


// Function: calc_cos_and_sin
// Prints the value, sine, and cosine of the given input.
// value: a double representing the input angle in radians
// returns: nothing

void calc_cos_and_sin(double value){
	
	printf("%-10.4lf %-10.4lf %-10.4lf\n",value, sin(value), cos(value)); // Prints value, sin and cos
	
}


// Function: print_table
// Loops from start to end using a given step (angles in radians)
// and prints sine and cosine values for each step
void print_table(double start_value, double end_value,double increment){
	for(double value = start_value; value<=end_value; value +=increment){
		calc_cos_and_sin(value);
	}

}

int main(void){
	// Main function: Prints a table of sine and cosine values
	printf("%-10s %-10s %-10s\n", "value","sin(value)","cos(value)"); // Makes a header for the table
	
	// Print table with a start value of 0.0 and an end value of 1.0 with a step of 1 
	print_table(0.0,1.0,0.1);

	return 0;
}

