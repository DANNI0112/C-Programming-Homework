/*
题目描述
输入若干个年份和月份，对每一组输入，判断该年该月一共有多少天。

2 月的天数与年份是否为闰年有关。闰年的判断规则是：能被 4 整除且不能被 100 整除，或者能被 400 整除。闰年的 2 月有 29 天，平年的 2 月有 28 天。大月（1、3、5、7、8、10、12 月）有 31 天，小月（4、6、9、11 月）有 30 天。

你的任务是实现所有代码，要求：

读入 (T) 组询问，每组读入 year 和 month；
对于每组询问，若 month 不在 ([1,12]) 内，输出 Invalid month；否则输出该年该月的天数（28、29、30 或 31）。
输入格式
第一行一个整数 (T)(1≤T≤10)，表示询问组数。

接下来 (T) 行，每行两个整数 year 和 month，以空格分隔。数据范围：(1900≤year≤3000)，month 在 int 类型范围内。

输出格式
输出 (T) 行，第 (i) 行为第 (i) 组输入对应月份的天数；若月份非法，输出 Invalid month。
*/ 
#include <stdio.h>
int main(){
	int T,year,month,i;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d %d",&year,&month);
	    if(month<1||month>12)
	        printf("Invalid month\n");
	    else if(year%4==0&&year%100!=0||year%400==0)
	        if (month%2!=0&&month<=7||month%2==0&&month>7)
	            printf("31\n");
	        else if(month%2==0&&month<=7&&month!=2||month%2!=0&&month>7)
	            printf("30\n");
	        else
	            printf("29\n");
	    else 
	        if (month%2!=0&&month<=7||month%2==0&&month>7)
	            printf("31\n");
	        else if(month%2==0&&month<=7&&month!=2||month%2!=0&&month>7)
	            printf("30\n");
	        else
	            printf("28\n");
	}
    return 0;
}
