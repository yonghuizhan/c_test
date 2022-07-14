#include <stdio.h>
/*3. Change Listing 4.1 to count upward instead of downward.*/
int a,b;

int main(void)
{
	a=b=5;
	
	printf("\nPost pre");
	printf("\n%d %d",a++,++b);
	printf("\n%d %d",a++,++b);
	printf("\n%d %d",a++,++b);
	printf("\n%d %d",a++,++b);
	printf("\n%d %d\n",a++,++b);
	
	return 0;
}
