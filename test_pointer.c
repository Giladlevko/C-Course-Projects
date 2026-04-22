#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main(void){
	double test_value = 90 * (PI/180);
	double *ptr_value = &test_value;
	double **ptr_ptr_value = &ptr_value;
	printf("pointer is located at %p or %lu and is %lf\npointer to pointer is located at %p or at %lu\n",ptr_value,ptr_value,*ptr_value,ptr_ptr_value,ptr_ptr_value);
	printf("the sine value of %lf or %lf is %lf or %lf\n",test_value,*ptr_value,sin(test_value),sin(*ptr_value));

}

