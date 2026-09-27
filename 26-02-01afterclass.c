/*
华氏温度转摄氏温度
从键盘输入华氏温度 F（实数），按公式 C = 5 × (F - 32) / 9 计算摄氏温度。

输入
一个实数 F。

输出
一行，输出摄氏温度，保留 1 位小数。
*/
#include <stdio.h>
int main(){
	double F;
	scanf("%lf",&F);
	printf("%.1lf", 5*(F-32)/9);
	return 0;
}
