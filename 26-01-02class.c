/*
两数之和
读入两个整数 a 和 b，输出它们的和。

输入
一行，两个整数 a 和 b，以空格分隔。

用以下代码接收 a 和 b 这两个整数的值。

scanf("%d %d", &a, &b);

输出
输出一个整数，表示 a+b。
*/
#include <stdio.h> 
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d",a+b);
	return 0;
}
