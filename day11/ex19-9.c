/*9. ON YOUR OWN: Modify the program in exercise 8 so that if the user enters
QUIT, the program stops accepting input and sorts the entered values.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
int comp_names(const void *s1,const void *s2);
int main()
{
	char *names[MAX],*key,**key1,buf[80],*ptr;
	char a[5]="QUIT";
	int count;
	int x;
	printf("Enter %d name .press Enter after each.Enter QUIT to quit.\n",MAX);
	for (count =0;count < MAX;count++)
	{
		printf("\nEmter %d name :",count+1);
		gets(buf);
		if ( !strcmp(buf,a))
			break;
		names[count] = (char*)malloc(strlen(buf)+1);
		strcpy(names[count],buf);
	}
	x = count;
	qsort(names,x,sizeof(names[0]),comp_names);

	for (x =0;x < count;x++)
	{
		printf("\n %d name is %s",x,names[x]);
		
	}
	return 0;	
}

int comp_names(const void *s1,const void *s2)
{
	return (strcmp(*(char**)s1,*(char**)s2));
}
