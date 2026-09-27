/*
题目描述
素数（质数）是大于 1 且只能被 1 和自身整除的整数。

编写一个C语言程序，读入一个闭区间 [m,n]，统计其中素数的个数，并输出该区间内最大的素数。

提示：外层循环枚举区间内每个数 x；内层循环用试除法判断素数——让除数 d 从 2 开始，满足 d×d≤x 时继续，一旦 x%d==0 即可用 break 提前判定不是素数。

输入格式
一行，包含两个整数 m 和 n，以空格分隔。数据范围：2≤m≤n≤100000。

输出格式
两行：

第一行：区间内素数的个数；
第二行：区间内最大的素数；若区间内不存在素数，输出 0。
*/
#include <stdio.h>
int main(){
    int m,n,x,d;
    int num=0;
    int max=0;
    scanf("%d %d",&m,&n);
    for (x=m;x<=n;x++)
    {
        if(x<2) continue;
        int d=2;
	restart:
        if (d<x)
        {
			if (x%d==0)
				continue;
            else 
            {
				d++;
                goto restart;
            }
        }
        else
        {
            num++;
            if (x>=max)
                max=x;
        }
    }
	printf("%d\n%d",num,max);
    return 0;
}
