/*
题目描述
一段共有 n 级的台阶，一步可以跨 1 级、2 级或 3 级，问登上这 n 级台阶一共有多少种不同的跨法？

记跨法数为 f(n)，可以推出：

f(n)= 1,n=1
      2,n=2
      4,n=3
      f(n-1)+f(n-2)+f(n-3),n>=4

（考虑最后一步：跨 1 级来自 f(n-1)，跨 2 级来自 f(n-2)，跨 3 级来自 f(n-3)。注意 f(2)=2：1+1 与 2。）

编写一个C语言程序，用一个单独的函数实现 f(n)（递归或循环实现均可），主函数读入多组询问并调用该函数输出结果。

输入格式
第一行一个整数 T（1≤T≤10），表示询问组数。

接下来 T 行，每行一个整数 n（1≤n≤24）。

输出格式
输出 T 行，第 i 行为第 i 组询问的答案 f(n)（保证在 int 范围内）。
*/
#include <stdio.h>
int f(int n){
	if(n==1)return 1;
	else if(n==2)return 2;
	else if(n==3)return 4;
	else return f(n-1)+f(n-2)+f(n-3);
}

int main(){
	int n,T;
	int i=1;
	scanf("%d\n",&T);
	for (i;i<=T;i++)
	{
		scanf("%d",&n);
		printf("%d\n",f(n));
	}
	return 0;
}
