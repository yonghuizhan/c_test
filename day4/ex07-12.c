#include <stdio.h>
int main()
{
	int a[6];
	int i=0,j=0,count=0;
	printf("please enter an integer:");
	scanf("%d",&i);
	for ( j = 0;j < 6;j++)
	{
		if ( i == 0 )
			break;
		else 
		{
			a[j] = i;
			count++;
		}
		printf("\nplease enter an integer:");
		scanf("%d",&i);
	}
	int max=a[0];
	int min=a[0];
	for (i= 0;i < count; i++)
	{
		if( max < a[i])
		max = a[i];
		if(min > a[i])
		min = a[i];
	}
	printf("\nThe bigest value is %d ,the samllest value is %d.",max,min);
	return 0;

}
