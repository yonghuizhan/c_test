/*Write a program that searches a text file for occurrences of a user-specified target
string and then reports the line numbers where the target is found. For example, if
you search one of your C source code files for the string “printf()”, the program
should list all the lines where the printf() function is called by the program.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 128
int frequency(char *str,char *target);
void fread1(char *filename);
int main()
{
	FILE *fp;
	char filename[20];
	puts("enter a filename :");
	gets(filename);
	fread1(filename);
	return 0;
}

void fread1(char *filename)
{
	FILE *fp;
	int lines;
	char array2[MAX][1024],target[128];
	int count;
	puts("Enter a target string you want to find: ");
	gets(target);
	if ((fp = fopen(filename,"r")) == NULL)
	{
		printf("error to openting a file.\n");
		exit(-1);
	}
	printf("\n");

	for (lines =0;lines < MAX ;lines++)
	{
		fgets(array2[lines],1024*sizeof(char),fp);
		count = frequency(array2[lines],target); 
		if (count != 0 )
			printf("%d ",lines+1);
	}


	fclose(fp);

}
 int frequency(char *str,char *target)
{
	int count=0;
	int len1,len2;
	char *p;
	p = str;
	len1 = strlen(p);
	len2 = strlen(target);
	
	while( len1 > len2)
	{
		p = strstr(p,target);
		if ( p != 0 )
		{
			count++;
			p +=len2;
		}
		else 
			break;
		len1 = strlen(p);
		
	}
	return count;
		
}
