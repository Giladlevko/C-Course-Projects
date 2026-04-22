#include <stdio.h>

void sawp(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}



void print_array(int size, int data[],char *str){
	int i;
	printf("%s",str);

	for (i = 0; i < size; i++){
		printf("%d\t", data[i]);
	}
}


void bubble_sort(int data[], int size){
	int i,j;
	int go_on;
	

	for (i = 0; (i < size) ; i++){
		go_on = 0;
		print_array(size,data,"\ninside bubble\n");
		printf("i = %d\n", i);
		for (j = size - 1; j>i; j--){
			if (data[j-1] > data[j]){
				sawp(&data[j-1],&data[j]);
				go_on = 1;
			}
		}
		if (go_on == 0){
		return;
		}
	}		
}



void enter_nums(int num_array[],int size){
	printf("Enter your grades please:\n");
	
	for (int i=0; i< size; i++){
		scanf("%d",&num_array[i]);
	}
	
}



void calc_average(int grades[],int size){
	double avg;
	for (int i=1; i<=size; i++){
		avg += (grades[i-1] - avg)/(i*1.0);
	}
	printf("\n\nHmmm...\nIt seems like your average is %lf unfortunately we are not capable of enrolling you to our institute this year...\n\nAnyway, that will be 70 Dollars",avg); 
}
	


int main(void){

	int SIZE = 5;
	printf("How many courses have you taken?\n");
	scanf("%d",&SIZE);
	int grades[SIZE];
	enter_nums(grades,SIZE);

	print_array(SIZE, grades, "My grades\n");
	printf("\n\n");
	bubble_sort(grades,SIZE);
	print_array(SIZE, grades, "My sorted grades\n");
	calc_average(grades,SIZE);
	printf("\n\n");
}

	
