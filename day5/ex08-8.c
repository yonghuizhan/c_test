#include <stdio.h>
#include <stdlib.h>
int a,b,c;
int array[10][10][10];
int total=0;
int main()
{
	for ( a=0 ; a<10 ;a++)
	{	for ( b=0 ; b<10 ;b++)
		{
			for ( c=0 ; c<10 ;c++)
			{	
				array[a][b][c] = rand()%100;
				total += array[a][b][c];
			}
		}
	}
	total /= 1000;
        for ( a=0 ; a<10 ;a++)
        {       for ( b=0 ; b<10 ;b++)
                {
                        for ( c=0 ; c<10 ;c++)
                        {
                                printf("\t%d ",array[a][b][c]);
                        }
                }
		printf("\n");
        }

	return 0;
}
		
