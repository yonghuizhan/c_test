#include <stdio.h>
int x,y;
int main(){
	for( x=0; x < 10 ;x++,printf("\n"))
		for( y=0; y<10;y++)
			printf("%c",1);
	return 0;
}
/*书里面说第六题是打印出来一个10*10的笑脸方阵，但是我在devc++上打印出来的是10行长方形，每一行
被分割成了19个小长方形。我在ubuntu上什么都看不见，只有10行空白
*/


