/*7. Write a function that receives two numbers as arguments and returns the value of
their product.
*/
#include <stdio.h>

int product(int a,int b);
int main()
{	
	int x=0;
	int y=0;
	int answer=0;
	printf("please enter two number.\n");
	scanf("%d %d",&x,&y);
	
	answer=product(x,y);
	printf("%d",answer);

	return 0;
}

int product(int a,int b)
{
	return(a*b);

}
