/*6. Write a function that (a) is passed a variable number of strings as arguments, (b)
concatenates the strings, in order, into one longer string, and (c) returns a pointer to
the new string to the calling program.*/
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#define MAX 200
char *addchar(char *str,int num,...);

int main(void)
{
	int num;

	char s1[] = "apple";
	char s2[] = "banana";
	char s3[] = "cat";
	char s4[] = "dog";
	char s5[] = "egg";
	char *str;
	str = (char *)malloc(MAX*sizeof(char));
	memset(str, 0, MAX*sizeof(char));
	str = addchar(str,5,s1,s2,s3,s4,s5);
	
	printf("%s",str);
	
	return 0;
}

char *addchar(char* str,int num,...)
{
	va_list arg_ptr;
	int count;
	va_start(arg_ptr,num);
//	char *str;
//	str = (char*)malloc(MAX*sizeof(char));
	for (count =0;count<5;count++)
	{
//		str = strcat(str,va_arg(arg_ptr,char *));
		printf("%s", va_arg(arg_ptr,char *));
	}
	va_end(arg_ptr);
	return str;
}
