#include <stdio.h>
/*
 2. Rewrite the code in exercise 1 to be more readable.
 */
int x,y;
int main()
{
	printf("\nEnter two numbers\n");
	scanf("%d %d",&x,&y);
	printf("\n\n%d is bigger",(x>y)?x:y);
	return 0;
}
