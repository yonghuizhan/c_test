#include <stdio.h>
#include <stdlib.h>
int main()
{
	int array[5][4];
	int i,j;
	for ( i = 0; i < 5;i++)
	{	
		for (j = 0;j < 4;j++)
		{
			array[i][j]=rand();
		}
	}
	 for ( i = 0; i < 5;i++)
        {
                for (j = 0;j < 4;j++)
                {
                       printf("\t%d " ,array[i][j]=rand());
                }
		printf("\n");
 	}
	 return 0;
}
