/*题目描述
对一张灰度图做一次“有效”卷积（无填充）。把卷积核放在图像左上角，按步长向右、向下滑动，每停一次就把核与盖住的图像区域对应相乘再求和，得到一个输出值。

输出尺寸与单次结果由下式决定：

OH = (H - KH) / SH + 1
OW = (W - KW) / SW + 1
核心公式：sum += img[i * SH + u][j * SW + v] * ker[u][v];

其中 i = 0..OH-1，j = 0..OW-1。

输入
第一行：两个整数 H W（1 ≤ H, W ≤ 20），图像的行数和列数。
后面 H 行：图像矩阵，每行 W 个整数（绝对值 ≤ 20）。
下一行：两个整数 KH KW（1 ≤ KH ≤ H，1 ≤ KW ≤ W），卷积核的行数和列数。
后面 KH 行：卷积核矩阵，每行 KW 个整数（绝对值 ≤ 5）。
最后一行：两个整数 SH SW（1 ≤ SH, SW ≤ 3），行方向和列方向的步长。
保证 (H - KH) 能被 SH 整除，(W - KW) 能被 SW 整除。
输出
OH 行，每行 OW 个整数，相邻两数用一个空格分隔：卷积结果矩阵。

示例 1
输入：

3 3
1 2 3
4 5 6
7 8 9
2 2
1 0
0 -1
1 1

输出：

-4 -4
-4 -4

示例 2
输入：

4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
2 2
1 1
1 1
2 2

输出：

14 22
46 54

提示
示例 1 中 OUT[0][0] = 1*1 + 2*0 + 4*0 + 5*(-1) = -4。
示例 2 步长为 2，核为全 1，每个输出就是对应 2x2 图像块的元素之和。*/
#include <stdio.h>
int main(){
	int H,W;
	scanf("%d%d",&H,&W);
	int mat1[20][20]={0};
	int mat2[20][20]={0};
	int mat3[20][20]={0};
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			scanf("%d",&mat1[i][j]);
		}
	}
	int KH,KW;
	scanf("%d%d",&KH,&KW);
	for(int u=0;u<KH;u++){
		for(int v=0;v<KW;v++){
			scanf("%d",&mat2[u][v]);
		}
    }
	int SH,SW;
	scanf("%d%d",&SH,&SW);
	int OH,OW;
	OH = (H - KH) / SH + 1;
    OW = (W - KW) / SW + 1;
    for (int i=0;i<OH;i++){
    	for (int j=0;j<OW;j++){
    		int sum=0;
    		for (int u=0;u<KH;u++){
    			for(int v=0;v<KW;v++){
    				sum += mat1[i*SH+u][j*SW+v]*mat2[u][v];
				}
			}
    	mat3[i][j]=sum;	
    	if (j<OW-1){
    		printf("%d ",mat3[i][j]);
		}
        else {
        	printf("%d\n",mat3[i][j]);
		}
		}
	} 
	return 0;
}

