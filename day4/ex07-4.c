#include <stdio.h>
int main()
{
	int i=1;
	puts("please enter an even value:");
	scanf("%d",&i);
	while( i%2 !=0 )
	{
		 printf("\n% d is not an even value ,please enter an even value :",i);
	 	 scanf("%d", &i );
	}
	
       	printf("\n%d is an enen value\n",i);
	

	return 0;
}
