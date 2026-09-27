/*
圆的面积与周长
从键盘输入圆的半径 r（实数），计算并输出圆的面积和周长，结果均保留 2 位小数，其中圆周率取 3.14159。

输入
一个实数 r（r > 0）。

输出
共两行：第一行输出面积，第二行输出周长，均保留 2 位小数。
*/
#include <stdio.h>
int main(){
	double pi=3.14159;
	double r;
	scanf("%lf",&r);
	printf("%.2lf\n%.2lf",pi*r*r,2*pi*r);
	return 0;
}
