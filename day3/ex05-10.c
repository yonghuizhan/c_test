/*Write a program that uses a function to find the average of five type float values
entered by the user.
*/
#include <stdio.h>
float average_5(float a1,float a2,float a3,float a4,float a5);
int main()
{
	float a1,a2,a3,a4,a5;
	printf("please enter five float values  that you want to find the average of them\n ");
	scanf("%f %f %f %f %f",&a1,&a2,&a3,&a4,&a5);
	
	printf("The average of five float values is %f\n",average_5(a1,a2,a3,a4,a5));
	/*在这里不小心把float 加在了函数average_5()的前面，出现了报错*/
	return 0;
}
float average_5(float a1,float a2,float a3,float a4,float a5)
{
	float average=0;
	average=a1+a2+a3+a4+a5;
	average = average/5;
	return average;
}


