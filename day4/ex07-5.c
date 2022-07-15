/*5. Modify exercise 4 so that it returns values until the number 99 is entered, or until
six even values have been entered. Store the numbers in an array. (Hint: You need a
loop.)*/
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
	
        for ( ctr = 0 ; ctr < 6 ;ctr++)
	{
		printf("%d ",a[ctr]);
	}


        return 0;
}

