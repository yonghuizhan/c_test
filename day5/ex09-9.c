#include <stdio.h>
#define MAX 10
void addarrays( int a[] ,int b[],int length_a,int length_b );
int array_1[MAX];
int array_2[MAX];
int total[MAX];
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

	addarrays(array_1,array_2,MAX,MAX);

	return 0;
}
void addarrays(int a[], int b[], int length_a, int length_b )
{
	int i;
	for ( i = 0; i < length_a && i < length_b; i++)
	{
		total[i] = a[i] + b[i];
		printf("\narray_1[%d] + array_2[%d] = %d ",i,i,total[i]);
	}
	printf("\n");
}	

