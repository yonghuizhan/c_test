/*8. Write a program that displays the binary value of a number. For instance, if the
user enters 3, the program should display 00000011. (Hint: You will need to use the
bitwise operators.)*/
#include <stdio.h>

int main()
{
	int x,i;
	puts("Enter a positive number: ");
	
	scanf("%d",&x);
	for (i = 8;i ;i--)
	{
		printf("%d",(x>>(i-1))&1);
	}
	return 0;
}
