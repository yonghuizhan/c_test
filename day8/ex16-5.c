#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 111
void fprint1(char *filename);
void fread1(char *filename); 
int main()
{
	FILE *fp;
	char filename[20];
	puts("enter a filename");
	gets(filename);
	fprint1(filename);
	fread1(filename);
	return 0;
} 
void fprint1(char *filename)
{
	int lines;
	FILE *fp;
	char *array1[MAX];
	for (lines = 0;lines < MAX;lines++)
	{
		array1[lines] = "AAA\n";
	}
	if ((fp = fopen(filename,"w")) == NULL)
	{
		printf("error to openting a file.");
		exit(-1);
	}
	for (lines = 0;lines < MAX;lines++)
	{
		fprintf(fp,"%s",array1[lines]);
	}
	fclose(fp);
	 
 } 
 void fread1(char *filename)
 {
 	FILE *fp;
 	int lines;
 	char array2[81];
 	if ((fp = fopen(filename,"r")) == NULL)
	{
		printf("error to openting a file.\n");
		exit(-1);
	}
//	for (lines = 0;lines < MAX;lines++)
//	{
//		fgets(array2[lines],4*sizeof(char),fp);
//	
//	}
//		for (lines = 0;lines < MAX;lines++)
//	{
//		printf("%s",array2[lines]);
//	
//	}
	for (lines =0;lines < MAX ;lines++)
	{
		fgets(array2,4*sizeof(char),fp);
		printf("%s",array2); 
	}
	
	

	fclose(fp);
	
 }
