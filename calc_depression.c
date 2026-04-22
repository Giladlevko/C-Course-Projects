#include <stdio.h>

int main(void){

	char days[7][10] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	int depression_value = 0;
	int original_input = 0;

	printf("**You have arrived to your doctor for a yearly mental check-up required by your job's very liked HR**\n\n"); 
	printf("Honest Doctor Joe:\n How strong is your depression from 1-7\n");

	scanf("%d",&depression_value);
	original_input = depression_value;

	if (depression_value > 7){
		printf("I will take that as''fully'' as in 7/7\n");
		original_input = 7;
		depression_value = 7;
	}

	if (depression_value<1){
		printf("Are you sure?\nMaybe Just in case I'll mark it for you as 1, ok?\n Great.\n");
		original_input = 1;
		depression_value = 1;
	}

	printf("Alright so you said %d out of 7.\n That means you should take this pill every\n\n",depression_value);

	while (depression_value > 0){
		printf(days[depression_value-1]);
		printf("\n\n");
		depression_value-- ;
		}

	printf("Also do not worry, this pill is very very safe\nIt is recommended by the FDA and they are very trusted of course\n");
	printf("I am here for you, and if there is anything you need tell me.\n\n");
	printf("Alrighty that will be all for to-\n\nSilly me how could I forget,\n %d pills every week comes to %d$\n\nYou can pay at the counter, good bye now.",original_input,1000*original_input);
	return 0;
	}


