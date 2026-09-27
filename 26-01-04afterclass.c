/*
三个整数求和
读入三个整数并输出它们的和。

输入
一行，三个整数 a、b、c。

以下代码接收这三个整数的值。

scanf("%d %d %d", &a, &b, &c)

输出
输出 a+b+c。
*/
#include <stdio.h> 
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	printf("%d",a+b+c);
	return 0;
}
