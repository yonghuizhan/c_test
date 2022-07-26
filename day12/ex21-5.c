/*5. Write a program that takes two filenames as command-line parameters. The pro␂gram should copy the first file into the second file. (See Day 16, “Using Disk
Files,” if you need help working with files.)*/
#include <stdio.h>
#include <stdlib.h>
void filename_copy(char * file1,char *file2);
int main()
{
	char file1[20],file2[20];
	puts("Enter the source filename :");
	gets(file1);
	puts("\nEnter the destnation filename :\n");
	gets(file2);
	
	filename_copy(file1,file2);
	
	return 0;
	
}

void filename_copy(char *file1,char *file2)
{
	FILE *fp1;
	FILE *fp2; 
	if ( (fp1 = fopen(file1,"rb") ) == NULL)
	{
		puts("Error opening source file.\n");
		exit(1);
	}
	if ( (fp2 = fopen(file2,"wb") ) == NULL)
	
	{
		puts("Error opening destination file.\n");
		exit(1);
	}
	char ch;
	
	while((!feof(fp1)))
	{
		fread(&ch,1,1,fp1);
		fwrite(&ch,1,1,fp2);
	}
	fclose(fp1);
	fclose(fp2);
	
}
