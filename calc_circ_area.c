
/* this will calculate the area of a circle based on the radius!*/

#include <stdio.h>
#define PI 3.14159


int main()
{
	double area = 0.0 , radius = 0.0;
	printf("Enter Radius: ");
	scanf("%lf",&radius);
	area = PI * radius * radius;
	printf("When the Radius is %lf Meters, \nthe Area is %lf Square Meters",radius,area);
	return 0;
}

