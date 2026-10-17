/*输出参数统计最小最大与总和
本题已提供可见的 main.c。请只提交下面这个函数，不要编写 main，也不要提交 main.c。

void stat(int *a, int n, int *pmin, int *pmax, long long *psum);

main 负责读入 n 个整数并输出结果。这三个结果只能通过指针写回去：*pmin 是最小值，*pmax 是最大值，*psum 是总和。main 在调用前把这三个变量都设为 0；如果不给它们赋值，输出就是 0 0 0。

请在一次遍历中完成统计。可以用下标，也可以用指针遍历 a。不要使用全局变量，不要在 stat 中做输入输出。

输入格式： 第一行一个整数 n（1 ≤ n ≤ 100）。第二行 n 个整数，每个整数在 -1000 到 1000 之间，同行整数以空格分隔。

输出格式： 一行三个整数：最小值、最大值、总和；相邻整数间恰好一个空格，行末换行。

样例输入：

6
4 -7 9 0 3 8

样例输出：

-7 9 17*/
void stat(int *a, int n, int *pmin, int *pmax, long long *psum){
	for (int i=0;i<n;i++){
		if(a[i]<*pmin){
            *pmin=a[i];
		}
		if(a[i]>*pmax){
            *pmax=a[i];
		}
	*psum+=a[i];
	}
}
