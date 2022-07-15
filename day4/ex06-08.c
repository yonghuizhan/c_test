/*8. Write a do...while statement to count from 1 to 100 by 3s.*/
#include <stdio.h>

int main()
{
	int i=1;
	do
	{
		pintf("%d ",i);
		i +=3;
	} while ( i < 100 );

	return 0;
}


