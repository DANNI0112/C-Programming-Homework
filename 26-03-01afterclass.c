/*
题目描述
输入三个整数 a, b, c，判断它们是否能构成一个三角形。若能，进一步判断是等边三角形、等腰三角形还是一般三角形。

要求：

使用逻辑运算符（&&、||）进行条件判断；
边长非正一定不是三角形；
输出结果应为以下之一：
Not a triangle（不能构成三角形）
Equilateral triangle（等边三角形）
Isosceles triangle（等腰三角形）
Scalene triangle（一般三角形）
输入格式
一行三个整数 a, b, c，用空格隔开。

输出格式
一个字符串，表示判断结果。
*/
#include <stdio.h>
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if (a>0&&b>0&&c>0&&a+b>c&&a+c>b&&b+c>a)
	{    
	if(a==b&&b==c)
	    printf("Equilateral triangle"); 
	else if(a==b||a==c||b==c)
	    printf("Isosceles triangle");
	else 
	    printf("Scalene triangle");
	}
	else 
	    printf("Not a triangle");
    return 0;
}
