/*回调函数求最大或最小
本题已提供可见的 main.c。larger 和 smaller 已经写在 main.c 里。请只提交 reduce，不要编写 main，不要再定义 larger 或 smaller，也不要提交 main.c。

int reduce(int *a, int n, int (*select)(int, int));

main 读入模式 m 后，会把函数地址传进来：m 为 1 时传入 larger，m 为 0 时传入 smaller。reduce 从 a[0] 出发，对后面的每个元素调用 (*select)(result, a[i]) 或 select(result, a[i])，用返回值更新 result，最后返回它。

选大还是选小完全由这个函数指针决定。reduce 看不到 m，自己写 if 比较无法同时满足两种模式。写法可参考课件里的 max_min。

输入格式： 第一行两个整数 n m（1 ≤ n ≤ 100，m 为 0 或 1）。第二行 n 个整数，每个整数在 -1000 到 1000 之间，同行整数以空格分隔。

输出格式： 一行一个整数，即选出的最大值（m = 1）或最小值（m = 0），行末换行。

样例输入：

6 1
4 -7 9 0 3 8

样例输出：

9
9

另一组样例： 输入 6 0 与同样数据时，输出 -7。*/
#include <assert.h>//注意头文件引入
int reduce(int *a, int n, int (*select)(int, int)){//select是形参（函数指针名）
/*比如说主函数里面有调用函数的句子：
reduce(arr,n,larger);
那么就把larger函数的地址传给了select */
    assert(a&&n>1);//确保a不是空指针且n>1
	int t=*a++;//指针后移，先执行对t的初始化再++
	for (int i=1;i<n;i++){
		t=(*select)(t,*a++);
	}	
	return t;
}

