/*
题目描述
编写一个C语言程序，根据输入的空气质量指数（AQI，取值范围为 [0,500] 的整数）判断并输出对应的空气质量类别。

分级标准如下：

0≤AQI≤50: "Excellent"
50<AQI≤100: "Good"
100<AQI≤150: "Lightly polluted"
150<AQI≤200: "Moderately polluted"
200<AQI≤300: "Heavily polluted"
300<AQI≤500: "Severely polluted"
如果输入的 AQI 小于 0 或大于 500，则为无效数据，程序应输出 "Invalid input"。

提示：本题适合用 if ... else if ... 多路选择结构按区间从低到高依次判断。

输入格式
输入一个整数，代表 AQI 指数。

输出格式
一行，输出对应的空气质量类别或 "Invalid input"。
*/
#include <stdio.h>
int main(){
	int AQI;
	scanf("%d",&AQI);
	if (AQI<=50&&AQI>0)
	    {
		printf("Excellent");
	}
	else if(AQI<=100&&AQI>0)
	    {
		printf("Good");
	}
	else if(AQI<=150&&AQI>0)
	    {
		printf("Lightly polluted");
	}
	else if(AQI<=200&&AQI>0)
	    {
		printf("Moderately polluted");
	}
	else if(AQI<=300&&AQI>0)
	    {
		printf("Heavily polluted");
	}
	else if(AQI<=500&&AQI>0)
	    {
		printf("Severely polluted");
	}
	else
	    {
		printf("Invalid input");
	}
	return 0;
}
