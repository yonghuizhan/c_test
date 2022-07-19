#include <stdio.h>
#define MAX 12
void printf1(char (*ptr)[MAX]);
//int main()
//{
//	char a[MAX][MAX];
//	char (*ptr)[MAX];
//	int i,count;
//	for (i = 0; i < MAX; i++)
//		for (count =0;count < MAX;count++)
//			a[i][count]='X';
//	ptr = a;
//	for (i = 0; i < MAX; i++)
//	{
//		for (count =0;count < MAX;count++)
//				printf("\t%c",ptr[i][count]);
//			printf("\n");
//	}
//
//	return 0;
//}
/*************************/
/*用下面这个代码执行不知道是哪里的内存出错了，最后两行打印出来会出现正方形，还打印不全符号'X'*/
/*************************/
int main()
{
	char a[MAX][MAX];
	char (*ptr)[MAX];
	int i,count;
	for (i = 0; i < MAX; i++)
		for (count =0;count < MAX;count++)
			a[i][count]='X';
			
	ptr = a;

	for (count = 0; count < MAX; count++)
 		printf1(ptr++);
	return 0;
}
void printf1(char (*ptr)[MAX])
 {

	 int *p;
	 int count;
	 p = (int *)ptr;
	 for (count = 0; count < MAX; count++)
	 	printf("\t%c", *p++);
	 printf("\n");
 }
