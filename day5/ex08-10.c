#include <stdio.h>
int main()
{
	int array[10];
	int clone[10];
	int i;
	for ( i = 0 ; i < 10; i++)
	{
		array[i] = i  ;
		clone[i] = array[i] + 10;
		 printf("\nclone[%d] =%d  ",i,clone[i]);
	}
	printf("\n");
	return 0;
}

