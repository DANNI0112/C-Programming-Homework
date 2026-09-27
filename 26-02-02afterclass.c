/*
秒数转换
从键盘输入一个非负整数表示的总秒数，将其转换为“时、分、秒”的形式并输出。

输入
一个非负整数 total（0 ≤ total ≤ 100000）。

输出
一行，格式为 时:分:秒，无前导零。
*/
#include <stdio.h>
int main(){
	int total;
	scanf("%d",&total);
	printf("%d:%d:%d",total/3600,total/60%60,total%60);
	return 0;
}
