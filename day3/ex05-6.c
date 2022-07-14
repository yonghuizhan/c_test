/*6. Rewrite Listing 5.4 so that it needs only one return statement in the larger_of()
function
*/
#include <stdio.h>
int x,y,z;
int larger_of(int a,int b);
int main()
{
	puts("Enter two difference interger values.\n");
	scanf("%d %d",&x,&y);
	
	z=larger_of( x,y );
	
	printf("The larger value is %d.\n",z);
	
	return 0;
	
} 

int larger_of(int a, int b)
{
	int c=0;
	if (a>b)
		c=a;
	else
		c=b;
	return c;
}
