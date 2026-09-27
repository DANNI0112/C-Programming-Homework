/*位运算练习
从键盘输入一个正整数 n，分别输出下列表达式的值：

n & 1
n | 1
n ^ 1
n << 2
n >> 1

输入
一个正整数 n（1 ≤ n ≤ 10000）。

输出
共五行，依次输出 n & 1、n | 1、n ^ 1、n << 2、n >> 1 的值，每行一个。
*/
#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n%d\n%d\n%d\n%d\n",n & 1,n | 1,n ^ 1,n << 2,n >> 1);
}
