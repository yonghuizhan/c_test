/*. ON YOUR OWN: Write a program that works like a calculator. The program
should allow for addition, subtraction, multiplication, and division.*/
#include <stdio.h>
int main()
{
	double x;
	double y;
	char chr;
	double answer=0;
	printf("enter a formula that you want to calculate: ");
	scanf("%lf %c %lf",&x,&chr,&y);
	
	switch (chr)
	{
		case '+':answer = x+y;
			break;
		case '-':answer = x-y;
			break;
		case '*':answer = x*y;
			break;
		case '/':answer = x/y;
			break;
		default:
		break;
	}
	printf("%.2lf %c %.2lf = %.2lf",x,chr,y,answer);
	return 0;
}
