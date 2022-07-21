/*8. Write a function that determines the number of times one string occurs within
another.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_char(char *ch1,char *ch2);
int main()
{
	char chr1[1024],chr2[128];
	int count;
	puts("Enter the first string:");
	gets(chr1);
	
	puts("\nEnter the second string:");
	gets(chr2);
	

	count = count_char(chr1,chr2);
	printf("The number of times string 1 appears in string 2 is %d times",count);
	
	return 0;
}

int count_char(char *ch1,char *ch2)
{
	int count=0;
	int len1,len2;
	char *p;
	p = ch1;
	len1 = strlen(p);
	len2 = strlen(ch2);
	
	while( len1 > len2)
	{
		p = strstr(p,ch2);
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
		
	
	
	
	 

