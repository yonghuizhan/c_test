#include <stdio.h>
/*1. Write a header for a function named do_it() that takes three type char arguments
and returns a type float to the calling program.
*/
float do_it( char a,char b,char c);
char c,d,e;
int main()
{
	printf("please enter three char\n");
	scanf("%c %c %c",&c,&d,&e);
	printf("%f\n",do_it(c,d,e));
	return 0;
}
float do_it( char a,char b, char c)
{
	float ret;
	ret=a+b+c;

	return ret;
}
