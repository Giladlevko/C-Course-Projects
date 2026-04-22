// Date: 3/27/2025
// Name: Gilad Levkowitz
// Program: sine calculator
//
// Description:
// This code will provide an out put the sine value of some number betwwen 0 and 1:

#include <stdio.h>
#include <math.h>


// This function recives a value, then calculates the sine value of that value
void calc_sine(double value){

	// calculates and prints the sine value of the recived value
	printf("The sine value of %lf is %lf\n",value,sin(value));
}

// This is the main function that asks for the value and initiates everything
int main(void){
	

	double value = 0.0; // declares the key used to store the inputed value
	printf("Enter a number between 0 and 1 (non inclusive) to get the sine output of that number:\n "); // asks for a value between 0 and 1
	scanf("%lf",&value);

	// Checks if the value is in the correct range
	if (value > 0 && value < 1){
			calc_sine(value); // calls the function that calculates the sine value
	}

	// If it is not in the correct range it tells the user
	else{
		printf("Invalid, the value must be betweeen 0 and 1 (non inclusive)\n");
	}
	return 0;
}





