#include <stdio.h>

int main(void){
	int a = 5;
	int c = 2;
	int b = ++a + ((c++));
	printf("a = %d and b = %d and c = %d\n",a,b,c);
	printf("on my system an int is %lu bytes\n",sizeof(int));
	printf("on my system a char is %lu bytes\n",sizeof(char));
	printf("on my system a float is %lu bytes\n",sizeof(float));
	printf("on my system an unsigned int is %lu bytes\n",sizeof(unsigned));
	printf("on my system a double is %lu bytes\n",sizeof(double));
	printf("on my system a long double is %lu bytes\n",sizeof(long double));
	printf("on my system a long int is %lu bytes\n",sizeof(long int));
	return 0;
}
	
