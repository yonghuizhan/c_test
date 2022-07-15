/*1. Write a declaration for an array that will hold 50 type long values.*/
/*2. Show a statement that assigns the value of 123.456 to the 50th element in the array*/
/*from exercise 1.*/
/*题目要求用long 来输入把 123.456 赋值给 array[50] 但是因为long int 是长整形，所以会出错，改成了 float */
#include <stdio.h>
int main ()
{
	float  array[100];
	 array[50] = 123.456;
	
	printf("%f",array[50]);
	return 0;
}

