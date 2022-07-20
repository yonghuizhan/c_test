#include <stdio.h>
#include <stdlib.h>
#define MAX 111
int main()
{
	FILE *fp;
	char filename[10];

	char c;
	
	printf("enter a file name: ");
	gets(filename);
	
	if  ( (fp = fopen(filename,"r"))== NULL)
	{
		printf("error opeming file");
		exit(-1);
	}
	

	while ( !feof(fp) )
	 {
	 	c = getc(fp);
	 	printf("%c",c);
	 }
	 
	 fclose(fp);
	 return 0;
	
 } 
