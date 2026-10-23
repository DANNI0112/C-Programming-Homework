/*题目描述
同一个排序函数需要支持两种规则：

模式 1：按整数数值升序排列。
模式 2：先按绝对值升序排列，绝对值相同时按数值升序排列。
例如，模式 2 下，-2 排在 2 前面，2 排在 -3 前面。

函数接口
int compareValue(int a, int b);
int compareAbsolute(int a, int b);
void sortBy(int *nums, int n, int (*compare)(int, int));

比较函数约定：a 应排在 b 前面时返回负数；顺序等价时返回 0；a 应排在 b 后面时返回正数。

compareValue 实现模式 1，compareAbsolute 实现模式 2。sortBy 接收有效的比较函数指针，在原数组中完成排序；所有元素之间的排序比较都必须调用 compare。排序函数应适用于任意满足上述约定的比较函数。

输入格式
第一行两个整数 n mode。

第二行包含 n 个整数。

数据范围：0 <= n <= 1000，mode 为 1 或 2，数组元素在 [-1000000000, 1000000000] 范围内。

输出格式
输出排序后的数组，整数之间用一个空格分隔。空数组输出 EMPTY。

样例
输入：

6 1
4 -2 4 0 -7 3

输出：

-7 -2 0 3 4 4
-7 -2 0 3 4 4*/
#include <stdio.h>

int compareValue(int a, int b);
int compareAbsolute(int a, int b);
void sortBy(int *nums, int n, int (*compare)(int, int));

int main(void) {
    int nums[1000];
    int n, mode;
    if (scanf("%d%d", &n, &mode) != 2) return 0;
    for (int i = 0; i < n; ++i) scanf("%d", &nums[i]);

    int (*compare)(int, int) = mode == 1 ? compareValue : compareAbsolute;
    sortBy(nums, n, compare);

    if (n == 0) {
        puts("EMPTY");
    } else {
        for (int i = 0; i < n; ++i) {
            if (i != 0) putchar(' ');
            printf("%d", nums[i]);
        }
        putchar('\n');
    }
    return 0;
}

int compareValue(int a, int b){
	if(a==b){
		return 0;
	}
	else if(a<b){
		return -1;
	}
	else {
		return 1;
	}
}

int compareAbsolute(int a, int b){
    if (a==b){
   	    return 0;
    }
    else if(a==-b){
    	if(a<0){
    		return -1;
		}
		else{
			return 1;
		}
	}
    else if(a>=0&&b>=0){
   	    if(a<b){
		    return -1;
	    }
	    else {
	    	return 1;
		}
    }
    else if(a<=0&&b<=0){
   	    if (a<b){
   	    	return 1;
		}
		else {
			return -1;
		}
    }
    else if(a>=0&&b<=0){
		if(a<(-b)){
			return -1;
		} 
		else{
			return 1;
		}
   }
   else {
      	if((-a)<b){
   		    return -1;
	    }
	    else{
	    	return 1;
	    }
   }	
}

void sortBy(int *nums, int n, int (*compare)(int, int)){
    for (int i = 1; i < n; i++){
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && compare(nums[j], key) > 0){
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}//注意超时问题


