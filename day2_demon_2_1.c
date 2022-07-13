#include <stdio.h>
int val1,val2,val3;
int product(int x,int y);

int main(void){
	printf("please enter an number between 1 and 100\n");
	scanf("%d",&val1);
	
	printf("please enter an number between 1 and 100\n");
	scanf("%d",&val2);

	val3=product(val1,val2);
	printf("%d times %d=%d\n",val1,val2,val3);

	return 0;
}

int product(int x,int y){
	int z=0;
	z=x*y;
	return z;
}



