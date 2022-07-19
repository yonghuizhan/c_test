#include <stdio.h>
#define MAX 10
int  main ()
{
	double *ptr;
	double a[10];
	int i,j;
	for (i = 0;i < MAX; i++)
	{
		printf("enter number %d :",i);
		scanf("%lf",&a[i]);
		printf("\n");
	}
	double temp;
		for (i = 0;i < MAX; i++)
	{
		for (j = 0;j < MAX-1;j++)
		{
			if(a[j] > a [j+1])
			{
					temp =  a [j];
				a [j] = a [j+1];
				a [j+1] = temp;
			}
		}
	}
	ptr = a;
	
		for (i = 0;i < MAX; i++)
	{
		printf("%.2lf ",ptr[i]);

	}
	return 0;
	
	
}
