/*6. Turn exercise 5 into an executable program. Add a function that prints the values,
separated by tabs, in the array on a single line. (Print only the values that were
entered into the array.)*/
#include <stdio.h>
int main()
{
        int i = 1,ctr= 0;
	int a[6];
        puts("please enter an even value:");
        scanf("%d",&i);
        while( i != 99 && ctr < 6 )
        {
		if ( i%2 == 0)
		{
			a[ctr] = i ;
			ctr++;
		}
                // printf("\n% d is not an even value ,please enter an even value :",i);
                 scanf("%d", &i );
        }
        for ( i = 0 ; i < ctr ;i++)
	{
		printf("%d\t ",a[i]);
	}


        return 0;
}

