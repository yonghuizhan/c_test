#include <stdio.h>
#include <string.h>
/*在这个代码中，用get会出现报错，因为get（）不确定输入的字符串的大小，容易发生越界和内存溢出，系统提示使用fget(),但是在这个代码中报错不影响运行*/
int main(void){
	char buffer[256];

	printf("Enter your name and press <Enter>:\n");
	fgets( buffer );

	printf("\nYour name has %d characters and spaces!",strlen( buffer ));

	return 0;
}
