/*10 BUG BUSTER: What is wrong with the following code fragment? (MAXVALUES is not the problem!)*/
#include <stdio.h>
int main()
{
	for (counter = 1; counter < MAXVALUES; counter++);//多了一个分号
		printf(“\nCounter = %d”, counter );
}
	
