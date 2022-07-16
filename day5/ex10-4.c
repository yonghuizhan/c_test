/*4. Write code that allocates space for an 80-character string and then inputs a string
from the keyboard and stores it in the allocated space.*/
#include <stdio.h>
char input[80];
int main()
{
	printf("enter an string less than 80 values : ");
	gets(input);
	
	printf("The string you inputed is :%s\n",input);
	return 0;

}
