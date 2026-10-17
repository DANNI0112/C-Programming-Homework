/*两数按序输出
输入两个整数 a 和 b。main 已提供：令 pa、pb 分别指向二者，调用 order 后按从小到大输出。

只实现下面的函数。不要改 main，不要使用 scanf 或 printf。

void order(int *pa, int *pb);

若 *pa 大于 *pb，通过指针交换，使返回后 *pa 小于等于 *pb。必须解引用，不要按值传递或调用排序函数。

输入格式： 一行两个整数 a b，均在 -1000 到 1000 之间。

输出格式： 一行两个整数，小的在前，大的在后，中间用一个空格分隔，行末换行。

样例输入：

7 -3
样例输出：

-3 7*/
#include <stdio.h>
void order (int *pa,int *pb){
	if (*pa>*pb){
		int t=*pa;
		*pa=*pb;
		*pb=t;
	}
}
