/*10. BUG BUSTER: Fix the following program so that it runs correctly:
 a program with problems... 
#include <stdio.h>
int x= 1:
int main( void )
{
if( x = 1);
printf(“ x equals 1” );
otherwise
printf(“ x does not equal 1”);
return 0;
}
*/
#include <stdio.h>
int x= 1;
int main( void )
{
	if( x == 1)
	printf(" x equals 1\n" );
	else
	printf(" x does not equal 1\n");
	return 0;
}

