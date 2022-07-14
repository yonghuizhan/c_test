#include <stdio.h>
int f,x;
int factorial( int a );
/*在这个递归函数的练习过程中，一开始遗忘了递归调用的时候a要减1，a也没有做累乘计算，导致函数没有输出结果*/
int main()
{
	printf("plesee enter an number less than 13\n ");
	scanf("%d",&x);

	f = factorial( x );
	printf("%d factorial equals %d\n",x,f);
	return 0;

}

int factorial( int a )
{
	if (  a==1 )
		return 1;
	else 
	{
		a *= factorial( a-1 );
		return a;
	}
}

