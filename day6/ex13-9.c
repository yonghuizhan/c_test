/*9. ON YOUR OWN: Write a program that provides a menu with five options. The
fifth option should quit the program. Each of the other options should execute a
system command using the system() function.*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf("enter 1 to open mspaint");
	printf("\nenter 2 to open calc");
	printf("\nenter 3 to open notepad\n");
	
	int a=0;
	scanf("%d",&a);
	switch(a)
	{
		case 1:system( "mspaint");
			break;
		case 2:system("calc");
			break;
		case 3:system ("notepad");
			break;
		default:
			break;
	}
//	system(chr);
	return 0;
//	23	9	D:\Dvc_Cpp\test\ex13-9.c	[Warning] passing argument 1 of 'system' makes pointer from integer without a cast
//14	15	D:\Dvc_Cpp\test\ex13-9.c	[Warning] assignment makes integer from pointer without a cast
//D:\Dvc_Cpp\test\collect2.exe	[Error] ld returned 1 exit status
//写错了main...... 
}
