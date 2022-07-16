#include <stdio.h>
#define MAX 80
void copychar(char orig[],char newone[]);
char chr_1[MAX];
char chr_2[MAX];
int ctr;
int main()
{
	printf("enter the first  string :");
	gets(chr_1);
	printf("enter the second  string :");
	gets(chr_2);
	int i;
	for ( ctr=0; ctr < MAX-1 ; ctr++  )
	{
		printf("chr_1[%d] = %d,chr_2[%d] = %d\n",i,chr_1[i],i,chr_2[i]);
	}
	copychar(chr_1,chr_2);
	for ( ctr=0; ctr < MAX-1 ; ctr++  )
        {       
                printf("chr_1[%d] = %d",i,chr_1[i] );
        }

	return 0;
}
void copychar( char orig[], char newone[])
{
	ctr = 0;
	for ( ctr; ctr < MAX-1; ctr++)
	{
		orig[ctr] = newone[ctr];
	}
}




