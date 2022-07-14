/*
11. Write a recursive function to take the value 3 to the power of another number. For
example, if 4 is passed, the function will return 81.
*/
/*第一个是我的错误代码，本代码在算幂次的运算函数 power_of_3中出现了一个错误，忽略了递归会把控制返回在调用的位置，同时作为记录运算结果的t又会被返回一次，多做了一次乘法运算，导致我在输入4的时候得到了8次方的运算结果，所以在递归调用中尽可能的直接return 调用函数，不要返回一些其它值，像我这种不熟练递归的容易忽略控制权也会返回，导致出bug。同时我觉得也得减少全局变量在递归函数中的使用，因为在递归过程中容易搞混乱变量的变化*/
/*这个是我的错误代码*/
/*
#include <stdio.h>
int t=3;
int power;
int power_of_3(int power);
int main ()
{
	int a;
	printf("enter an number\n");

	scanf("%d",&power);
	a = power_of_3(power);
	printf("%d",a);
	return 0;

}

int power_of_3(int power)
{
	if( power == 1 )
	{
		return 3;
	}
	else if ( power > 0)
	{
		t = t*power_of_3(power-1);
		return t;/错误的地方
	}
}
*/
#include <stdio.h>
int three_powered(int power );
int main()
{
	int x;
	printf("please enter an number \n");
	scanf("%d",&x);
	
	printf("3 to the power of %x is %d\n",x,three_powered(x));
	
	return 0;
}

int three_powered(int power)
{
	if ( power < 1)
	return(1);
	else
	{
		return(3*three_powered(power-1));
	}
}
