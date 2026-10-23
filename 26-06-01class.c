/*题目描述
输入一个非负整数 a 和一个正整数 b，请编写函数，一次计算 a 除以 b 的整数商和余数，并通过两个指针参数将结果写入主函数中的变量。

例如，17 除以 5，商为 3，余数为 2。

函数接口

void divmod(int a, int b, int *quotient, int *remainder);

a、b 是待计算的两个整数。quotient、remainder 分别指向主函数中两个不同的有效整数变量，用于接收商和余数。

输入格式：
一行两个整数 a b，满足 0 <= a <= 1000000000、1 <= b <= 1000000000。

输出格式：
一行两个整数，依次为商和余数，整数之间用一个空格分隔。

样例输入
17 5

样例输出
3 2

注意
主函数已经实现在main.c，只需要实现目标函数

大家记得在func.c里面#include "func.h"*/
#include <stdio.h>
void divmod(int a, int b, int *quotient, int *remainder);

int main(void) {
    int a, b;
    if (scanf("%d%d", &a, &b) != 2) return 0;
    int quotient = -1, remainder = -1;
    divmod(a, b, &quotient, &remainder);
    printf("%d %d\n", quotient, remainder);
    return 0;
}

void divmod(int a, int b, int *quotient, int *remainder){
    *quotient=a/b;
    *remainder=a%b;
}
