#include <stdio.h>
/*6. Rewrite the following nested if statements using a single if statement and logical
operators.
	if (x < 1)
		if ( x > 10 )
		statement;
*/
int main(void)
{
	int x;

	if ( x<1 && x>20)
		printf("%d",x);
}

