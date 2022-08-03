#include <stdio.h>
#define GET_BYTE(value, index) (((value) & (1 << ((index) -1))) != 0)
//将指定位，置为1
#define SET_BYTE(value, index) ((value) |= (1 << ((index) -1)))
//将指定位，置为0
#define CLR_BYTE(value, index) ((value) &= (~(1 << ((index) -1))))


#define GET_BYTE(vbyte, index) (((vbyte) & (1 << ((index) ^ 7))) != 0)
//index位置1
#define SET_BYTE(vbyte, index) ((vbyte) |= (1 << ((index) ^ 7)))
//index位置0
#define CLR_BYTE(vbyte, index) ((vbyte) &= (~(1 << ((index) ^ 7))))

int main(){
	int x=3L;
	// x+1;
	// printf("%d\n",x);
	// printf("hello,world\n");
	//SET_BYTE(x,3);
	printf("%d\n",x);
	return 0;
}

