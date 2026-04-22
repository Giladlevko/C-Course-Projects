/* this will calculate the amount of kilometers in a marathon!*/

#include <stdio.h>

void check_input(){

	double marathon_amount = -1.0;
	int miles = 26, yards = 385;
	double kilometers;
	int invalid_input = 0;

	while (marathon_amount < 0){

		printf("\nHow many marathons have you signed up to");

		for (int i=0; i<invalid_input; i++){
			printf("!");
		}
		printf("?\n\n");

		if (scanf("%lf",&marathon_amount)!=1){
			printf("\nThat's not even a number\n\nAre you slow?\n\n");
			while (getchar() != '\n');
			marathon_amount = -1.0;
			invalid_input++;
			continue;
		}

		if (marathon_amount < 0){
			printf("\nLook at negative Nancy over here!\n\nCome on give me a real number!\n");
			invalid_input++;
			continue;
		}
		
	}

	double precise_miles = (miles+yards/1760.0) * marathon_amount;
	kilometers = precise_miles*1.609;
	printf("\n%.2f Marathons have %.2f Kilometers in them\n\n",marathon_amount,kilometers);
	printf("\nThis means you ran %.2f kilometers or %.2f miles!\n\n",kilometers,precise_miles);

	if (marathon_amount >0){
		printf("\nThat's impressive!\n");
	}

	else{
		printf("\nNot much of a runner are ya?\n");
	}

}



int main()
{
	check_input();
	return 0;
}



