#include <stdio.h>


enum day {sun,mon,tue,wed,thu,fri,sat};
typedef enum day day;

void print_day(day d){
	switch(d){
		case sun: printf("Sunday\n");break;
		case mon: printf("Monday\n");break;
		case tue: printf("Tuesday\n");break;
		case wed: printf("Wednesday\n");break;
		case thu: printf("Thursday\n");break;
		case fri: printf("Friday\n");break;
		case sat: printf("Saturday\n");break;
		default: printf("%d is an error!!\n");
	}
}

day next_day(day d){
	return (d + 1 % 7);
}

day yestrdy( day d ){
	return (((d-1)%7 + 7) % 7);
}

int main(){
	day today = fri;
	printf("Today is: ");
	print_day(today);
	printf("Tomorrow will be: ");
	print_day(next_day(today));
	printf("Yesterday was: ");
	print_day(yestrdy(today));
	return 0;
}
	



