/*
题目描述
读入 n（1≤n≤1000）个整数，求它们的和与均值。

提示：用 for 或 while 循环依次读入并累加；计算均值时注意整数除法会截断小数，需要转换为浮点数。

输入格式
输入第一行是一个整数 n，表示有 n 个整数。

第 2～n+1 行每行包含 1 个整数。每个整数的绝对值均不超过 10000。

输出格式
输出一行，先输出和，再输出平均值（保留到小数点后 5 位），两个数间用单个空格分隔。
*/
#include <stdio.h>
int main(){
    int n,num,i;
    int add=0;
    double aver=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        add+=num;
        aver=(double)add/n;
	}
	printf("%d %.5lf",add,aver);
    return 0;
}
