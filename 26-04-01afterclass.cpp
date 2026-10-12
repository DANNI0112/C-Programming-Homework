/*题目描述
输入一个 m 行 n 列的整数矩阵，输出每一行的最大值。

输入
第一行：两个整数 m n（1 ≤ m, n ≤ 20）。
后面 m 行：每行 n 个整数（绝对值 ≤ 1000），相邻两数用空格分隔。

输出
m 行，每行一个整数：第 i 行的最大值。

示例
输入：

2 3
1 5 3
-2 -8 0

输出：

5
0
5
0
*/
#include <stdio.h>
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	int mat[20][20]={0};
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
		}
    }
	for (int i=0;i<m;i++){
		int max=mat[i][0];
		for (int j=1;j<n;j++){
			if (mat[i][j]>=max){
			max=mat[i][j];
		   }
	    }
		printf("%d\n",max);
	}
	return 0;
}
