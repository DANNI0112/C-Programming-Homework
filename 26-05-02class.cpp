/*指针双向遍历
输入长度为 n 的整数数组。main 已提供：读入数组，令 begin 指向首元素、end 指向尾后位置，调用 traverse 后输出正序和逆序。

只实现下面的函数。不要改 main，不要包含头文件，不要使用 scanf 或 printf。

void traverse(int *begin, int *end, int *forward, int *backward);

用指针将 [begin, end) 依次写入 forward，再逆序写入 backward。请用 ++、--、加法或比较访问元素，不要用下标，不要解引用 end 和范围外的指针。

输入格式： 第一行一个整数 n（1 ≤ n ≤ 10）。第二行 n 个整数，每个整数在 -100 到 100 之间。

输出格式： 两行，每行 n 个整数。第一行是输入顺序，第二行是逆序；同行相邻整数间恰好一个空格，行末换行。

样例输入：

5
3 -1 8 0 6

样例输出：

3 -1 8 0 6
6 0 8 -1 3
3 -1 8 0 6
6 0 8 -1 3*/
#include <stdio.h>
void traverse(int *begin, int *end, int *forward, int *backward){
    int *p=NULL;
	for (p=begin;p!=end;p++){
		*forward=*p;
		forward++;
	}
	int *q=NULL;
	for(q=end-1;q!=begin-1;q--){//注意区间开闭
		*backward=*q;
		backward++;
	}
}
