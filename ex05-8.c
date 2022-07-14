/*8. Write a function that receives two numbers as arguments. The function should
divide the first number by the second. Don’t divide by the second number if it’s
zero. (Hint: Use an if statement.)
*/
#include <stdio.h>

double divide(double x,double y);

int main()
{
	double a,b;
	printf("please enter two number.\n");
	scanf("%lf %lf",&a,&b);
	
	if( b==0 )
		printf("The second number can't be 0\n");
	else
		printf("%lf divide %lf is %lf\n",a,b,divide(a,b));

	return 0;

}

double divide(double a,double b)
{
	double answer;
	answer=a/b;
	return answer;

}


