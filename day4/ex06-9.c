/*9. BUG BUSTER: What is wrong with the following code fragment?
record = 0;
while (record < 100)
{
printf( “\nRecord %d “, record );
printf( “\nGetting next number...” );
}
*/
#include <stdio.h>

int main()
{
	int record =0;
	while ( record < 100 )
	{
		printf("\nRecord %d ",record );
		printf("\nGetting next numbenr...");
		scanf("%d",&record);//原代码没有设置 record 的输入或者变化条件， record 的值会一直是 0 ，导致代码 while 无法终止。
	}
	
	return 0;
}

