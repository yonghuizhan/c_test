/*9. Write a function that calls the functions in exercises 7 and 8.
*/
#include <stdio.h>
double product(double a,double b);
double divide(double x,double y);
int main()
{
	
	double a1,b1;
	printf("please enter two number\n");
	scanf("%lf %lf",&a1,&b1);
	
	printf("%lf product %lf = %lf\n",a1,b1,product(a1,b1));
	
	if( b1==0 )
		printf("If you wan to do divison.The second number can't be 0\n");
	else
		printf("%lf divide %lf is %lf\n",a1,b1,divide(a1,b1));

	
}
double product(double a,double b)
{
	return(a*b);

}
double divide(double x,double y)
{
	double answer;
	answer=x/y;
	return answer;

}

