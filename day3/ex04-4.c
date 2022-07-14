#include <stdio.h>
/*4. Write an if statement that assigns the value of x to the variable y only if x is
between 1 and 20. Leave y unchanged if x is not in that range.
*/
int main(void)
{
	int x=0,y=0;

	printf("plesse enter two numbers \n");
	scanf("%d %d",&x,&y);

	if ( x>=1 && x<=20)
	{
		y=x;
	}
	
	printf("%d %d",x,y);

	return 0;
}

