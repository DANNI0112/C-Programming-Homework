/*题目描述
给定一个整数数组，找出其中最长的连续上升段。段内元素必须在原数组中相邻，且后一项严格大于前一项；单个元素也构成长度为 1 的上升段。

如果存在多个长度相同的最长上升段，选择开始位置最靠前的一段。请返回指向该段首元素的指针，并通过输出参数传出段的长度。

函数接口
const int *longestIncreasingRun(const int *nums, int n, int *length);

n > 0 时，返回值必须指向原数组中的元素，并将段长度写入 *length。
n == 0 时，返回 NULL，并令 *length = 0。此时 nums 也允许为 NULL，函数不得访问数组元素。
输入格式
第一行一个整数 n。当 n > 0 时，第二行包含 n 个整数。

数据范围：0 <= n <= 1000，数组元素在 [-10000, 10000] 范围内。

输出格式
第一行输出所选段的开始下标和长度，下标从 0 开始。

第二行输出该段的所有元素，整数之间用一个空格分隔。

空数组统一输出两行：第一行为 -1 0，第二行为 EMPTY。

样例
输入：

10
3 1 2 4 0 5 6 7 2 3

输出：

4 4
0 5 6 7
4 4
0 5 6 7*/
#include <stdio.h>

const int *longestIncreasingRun(const int *nums, int n, int *length);

int main(void) {
    int nums[1000];
    int n;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; ++i) scanf("%d", &nums[i]);

    int length;
    const int *start = longestIncreasingRun(n == 0 ? NULL : nums, n, &length);
    if (start == NULL) {
        printf("-1 %d\nEMPTY\n", length);
    } else {
        printf("%d %d\n", (int)(start - nums), length);
        for (int i = 0; i < length; ++i) {
            if (i != 0) putchar(' ');
            printf("%d", *(start + i));
        }
        putchar('\n');
    }
    return 0;
}

const int *longestIncreasingRun(const int *nums, int n, int *length){
	if (n<=0||nums==NULL) {
        *length=0;
        return NULL;
    }
    int bestStart=0, bestLen=1;  
    int curStart=0, curLen=1;   
    for (int i=1; i<n; ++i) {
        if (nums[i]>nums[i-1]) {
            curLen++;                 
        } 
		else {
        curStart=i;            
        curLen=1;
        }
        if (curLen>bestLen) {       
            bestLen=curLen;
            bestStart=curStart;
        }
    }
    *length=bestLen;  
    return nums+bestStart;
}//注意考虑覆盖问题，可以多设几个临时变量，防止取值混乱
