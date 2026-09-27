/*两数交换与算术运算
从键盘输入两个正整数 a 和 b，依次完成：

先输出 a、b 的和、差、积、整数商和余数；
再输出 a 除以 b 的浮点商（保留 2 位小数）；
最后借助第三个变量交换 a、b 的值，输出交换后的 a、b。
输入
两个正整数 a 和 b（1 ≤ a, b ≤ 1000），用空格分隔。

输出
共三行：

第一行依次输出和、差、积、整数商、余数，用空格分隔；
第二行输出浮点商，保留 2 位小数；
第三行输出交换后的 a、b，用空格分隔。
*/
#include <stdio.h>
int main(){
	int a,b,c;
	scanf("%d %d",&a,&b);
	printf("%d %d %d %d %d\n",a+b,a-b,a*b,a/b,a%b);
	printf("%.2lf\n",(double)a/b);
	printf("%d",c=b);
	printf(" %d",c=a);
	return 0;
}
