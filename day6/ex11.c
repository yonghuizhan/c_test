/*这些是ex11的练习，是一些比较简单的结构初始化内容*/
#include <stdio.h>
struct time{
	int time1;
	int time2;
	int time3;
};

struct data{
//	int time4;
//	float f;
	 char chr[21];
};

typedef struct {
	char address1;
	char address2;
	char city;
	char statc;
	char zip;
}RECORD;

RECORD myaddress;
struct data info;
struct data *p_data;

int main()
{
//	p_data = &info;
//	info.time4 = 100;
//	printf("%d ",info.time4);
//	p_data->f = 5.5;
//	printf("\n%.2f ",info.f);
	
	return 0;
}
