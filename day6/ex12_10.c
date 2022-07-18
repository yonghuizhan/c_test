/*10. BUG BUSTER: Will the preceding program run? If not, what’s the problem?
Rewrite it so that it is correct.*/
//#include <stdio.h>
//void print_letter2(void); 
//int ctr;
//char letter1 = 'X';
//char letter2 = '=';
//int main( void )
//{
//	for( ctr = 0; ctr < 10; ctr++ )
//	{
//		printf( "%c", letter1 );
//		print_letter2();
//	}
//	return 0;
//}
//void print_letter2(void)
//{
//	for( ctr = 0; ctr < 2; ctr++ )
//	printf( "%c", letter2 );
//}

/*上面这个程序因为在print_letter2中会把全局变量初始化为2，导致返回main()函数的时候ctr 的值不断被重置为2，循环无法结束*/
#include <stdio.h>
void print_letter2(void); /* function prototype */
int main( void )
{
	int ctr;
	char letter1 = 'X';
	for( ctr = 0; ctr < 10; ctr++ )
	{
		printf( "%c", letter1 );
		print_letter2();
	}
	return 0;
}
void print_letter2(void)
{
	int ctr;
	char letter2 = '=';
	for( ctr = 0; ctr < 2; ctr++ )
	printf( "%c", letter2 );
}
