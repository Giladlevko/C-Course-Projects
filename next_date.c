//Date: 4/13/2026
//Name: Gilad Levkowitz
//Description: Computes and prints the next day for several given dates


#include <stdio.h>

// Declaring the month and date types
typedef enum month {JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC}month;
typedef struct date {month m ; int d;}date;

// Name: next_month
// Description: returns the following month of the input month
// Input: Current month
// Output: Next month
month next_month(month m){
	month next_month = (++m)%12; //Increment month and wrap around using modulo (DEC -> JAN)
	return next_month;
}

//Name: next_day
//Description: Returns the next calendar date after the given date
//Input: Current date
//Output: following date
date next_day(date current_date){
	current_date.d+=1;
	int days_in_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};//Array of amount of days in months (January–December)

	if (current_date.d > days_in_month[current_date.m]){
			current_date.d = 1;
			current_date.m = next_month(current_date.m);
	}
	return current_date;
}

//Name: print_date
//Description: Prints the input date
//Input: Date
//Output: None
void print_date(date d){
	//Array of month names (January–December)
	char *month_names[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	printf("%s %d\n",month_names[d.m],d.d);
}


//Name: main
//Description:
// Tests the next_day function by computing and printing
// the next date for several sample inputs:
// February 28, March 14, October 31, and December 31
//Input: None
//Output: returns 0 
int main(void){
	date next_date;
	date current_date;

	printf("The day after Febuary 28 is:\n");
	current_date.m = FEB;
	current_date.d = 28;
	next_date = next_day(current_date);
	print_date(next_date);

	printf("The day after March 14 is:\n");
	current_date.m = MAR;
	current_date.d = 14;
	next_date = next_day(current_date);
	print_date(next_date);

	
	printf("The day after October 31 is:\n");
	current_date.m = OCT;
	current_date.d = 31;
	next_date = next_day(current_date);
	print_date(next_date);

	printf("the day after December 31 is:\n");
	current_date.m = DEC;
	current_date.d = 31;
	next_date = next_day(current_date);
	print_date(next_date);


	return 0;
}
