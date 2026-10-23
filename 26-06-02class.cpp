/*题目描述
给出下列函数，大家要用指针的形式实现：

void swap(int* p, int* q);
void print_array(int* p, int size);
void print_matrix(int** mat, int row, int col);
void swap(int* p, int* q);
void print_array(int* p, int size);
void print_matrix(int** mat, int row, int col);

其中swap是交换两个数字，print_array是打印数组，pirnt_matrix是打印矩阵。

输入格式：
第一行：两个整数（用于swap函数）
第二行：一个整数n（数组大小），接着n个整数（数组元素）,坐标从0开始
第三行：两个整数row和col（矩阵行列数），接着row×col个整数（矩阵元素），坐标从0开始
输出格式：
第一行：交换后的两个整数
第二行开始：数组元素（每个元素一行）
接着：矩阵（每行元素用空格分隔）
样例输入
10 20
5 1 2 3 4 5
3 3 1 2 3 4 5 6 7 8 9

样例输出
20 10
1
2
3
4
5
1 2 3
4 5 6
7 8 9

注意
主函数已经实现在main.c，只需要实现目标函数

大家记得在func.c里面#include "func.h"*/
#include <stdio.h>
#include <stdlib.h>

void swap(int* p, int* q);
void print_array(int* p, int size);
void print_matrix(int** mat, int row, int col);

int main(void) {
    int a, b;
    
    // 输入两个数字
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("%d %d\n", a, b);
    
    // 输入数组
    int size;
    scanf("%d", &size);
    int* c = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &c[i]);
    }
    print_array(c, size);
    
    // 输入矩阵
    int row, col;
    scanf("%d %d", &row, &col);
    int** d = (int**)malloc(sizeof(int*) * row);
    
    for(int i = 0; i < row; i++) {
        d[i] = (int*)malloc(sizeof(int) * col);
        for(int j = 0; j < col; j++) {
            scanf("%d", &d[i][j]);
        }
    }
    
    print_matrix(d, row, col);
    
    // 释放内存
    free(c);
    for(int i = 0; i < row; i++) {
        free(d[i]);
    }
    free(d);
    
    return 0;
}

void swap(int* p, int* q){
	int t=*p;
	*p=*q;
	*q=t;
}
void print_array(int* p, int size){
	for (int i=0;i<size;i++){
		printf("%d\n",*p);
		p++;
	}
}
void print_matrix(int** mat, int row, int col){
	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	} 
}
