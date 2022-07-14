#include <stdio.h>
/*9. Write an if statement that determines whether someone is legally an adult (age
21), but not a senior citizen (age 65).
*/
int main(void)
{
	int age=0;

	printf("please enter your age \n");

	scanf("%d",&age);

	if ( age > 21 && age <=65)
		printf("You are adult\n");

	return 0;
}
