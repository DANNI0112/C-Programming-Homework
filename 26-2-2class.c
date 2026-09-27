/*
三位数各位数字之和
从键盘输入一个三位正整数，输出它的各位数字之和。

输入
一个三位正整数 n（100 ≤ n ≤ 999）。

输出
一行，输出各位数字之和。
*/
#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",n%10+n/10%10+n/100);
	return 0;
}
