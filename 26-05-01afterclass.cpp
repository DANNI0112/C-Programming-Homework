/*矩阵行列求和
输入 3 行 4 列的整数矩阵，求出每行的和与每列的和。

main 已读入矩阵：p 指向第一行，p[i][j] 就是第 i 行第 j 列。函数返回后，main 先输出 row 的 3 个行和，再输出 col 的 4 个列和。

row[i]：第i行的和。

col[j]：第j列的和。

只实现下面的函数。不要改 main，不要使用 scanf 或 printf。

void sum_matrix(int (*p)[4], int *row, int *col);

输入格式： 共 3 行，每行 4 个整数；每个整数在 -100 到 100 之间。

输出格式： 第一行输出 3 个行和，第二行输出 4 个列和；同行相邻整数间恰好一个空格，行末换行。

样例输入：

1 2 3 4
5 6 7 8
9 10 11 12

样例输出：

10 26 42
15 18 21 24*/
#include <stdio.h>
void sum_matrix(int (*p)[4], int *row, int *col){
	for(int i=0;i<3;i++){
		row[i]=0;
	}
	for (int j=0;j<4;j++){
		col[j]=0;//注意局部变量初始化，不要直接初始化p[i][j]，这样相当于直接清零了所有输入值，应该在对col和row操作前对它们初始化
	}
	for(int i=0;i<3;i++){
		for (int j=0;j<4;j++){
			row[i]+=p[i][j];
		}
	}
	for(int j=0;j<4;j++){
		for (int i=0;i<3;i++){
			col[j]+=p[i][j];//也可以和上一组循环写在一起
		}
	}
}
