/*2. Write a header for a function named print_a_number() that takes a single type
int argument and doesn’t return anything to the calling program.
*/
#include <stdio.h>
void print_a_number(int a);
int main()
{
	printf("please enter an number:\n");
	
	int num=0;
	scanf("%d",&num);

	print_a_number(num);

	return 0;

}

void print_a_number(int a)
{
	printf("the number you input is %d\n ",a);

}

