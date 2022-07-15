/*10. Write a program that inputs two floating-point values from the keyboard and then
displays their product.*/
#include <stdio.h>
int main()
{
	float x,y;
	printf("please enter two number:");
	scanf("%f %f",&x,&y);
	
	printf("\nThe product of %f and %f is %f\n",x,y,x*y);
	return 0;
}
