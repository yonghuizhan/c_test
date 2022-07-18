/*5. Can a program have a global and a local variable with the same name? Write a pro␂gram that uses a global and a local variable with the same name to prove your
answer.*/
#include <stdio.h> 
void printf1(void);
const int j=99;
int main()
 {
 	register int i=0;
 	
 	 
 	int j=88;
 	printf1();
 	printf("\n%d",j);
 	return 0; 
 	
 }

void printf1(void)
{
	printf("%d",j);
}
