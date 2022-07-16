#include <stdio.h>
#define MAX 10
int sumarrays( int a[] ,int b[],int length_a,int length_b );
int array_1[MAX];
int array_2[MAX];
int total = 0;
int main()
{
	printf("please enter ten interger values :\n");
	int i;

	for ( i = 0; i < MAX; i++)
	{
		printf("enter number %d :",i);
		scanf("%d",&array_1[i] );
	}
	printf("\nplease enter ten interger values :");

	for ( i = 0; i < MAX; i++)
        {
		printf("enter number %d :",i);
                scanf("%d",&array_2[i] );
        }

	printf("\nThe sum of array_1 and array_2 is %d",sumarrays( array_1, array_2, MAX, MAX ));

	return 0;
}
int sumarrays(int a[], int b[], int length_a, int length_b )
{
	int i;
	for ( i = 0; i < length_a && i < length_b; i++)
	{
		total += a[i] + b[i];
	}
	return total;
}	



