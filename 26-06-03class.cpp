/*题目描述
主函数中已有一个成绩数组。请使用一个结构体保存学号、课程数量，以及指向该成绩数组的指针，并通过结构体中的指针成员读取和统计成绩。

最后输出成绩单、总分和及格门数，成绩大于等于 60 为及格。数组由主函数定义，整个过程只使用已有数组和结构体变量。

函数接口
void initTranscript(Transcript *transcript, int id, int count, int *scores);
void getStatistics(const Transcript *transcript, int *total, int *passed);

需要完成两个函数：

initTranscript：保存学号和课程数量；课程数量大于 0 时，将指针成员关联到传入的数组；课程数量为 0 时，将指针成员设为 NULL。
getStatistics：计算所有课程的总分和及格门数，分别写入 *total、*passed。
输入格式
第一行两个整数 id n，分别表示学号和课程数量。

第二行包含 n 个整数，表示各门课程的成绩。

数据范围：1 <= id <= 10000，0 <= n <= 1000，成绩在 [0, 100] 范围内。

输出格式
输出两行：

第一行依次输出学号、课程数量和所有成绩。课程数量为 0 时，该行只输出学号和 0。
第二行输出总分和及格门数。
样例
输入：

1001 4
80 90 70 60

输出：

1001 4 80 90 70 60
300 4

注意
主函数已经实现在main.c，只需要实现目标函数

大家记得在student.c里面#include "student.h"*/
#include <stdio.h>

typedef struct {
    int id;
    int count;
    int *scores;
} Transcript;

void initTranscript(Transcript *transcript, int id, int count, int *scores);
void getStatistics(const Transcript *transcript, int *total, int *passed);

int main(void) {
    int scores[1000];
    int id, n;
    if (scanf("%d%d", &id, &n) != 2) return 0;
    for (int i = 0; i < n; ++i) scanf("%d", &scores[i]);

    Transcript transcript;
    initTranscript(&transcript, id, n, scores);
    int total, passed;
    getStatistics(&transcript, &total, &passed);
    printf("%d %d", transcript.id, transcript.count);
    for (int i = 0; i < transcript.count; ++i) {
        printf(" %d", transcript.scores[i]);
    }
    printf("\n%d %d\n", total, passed);
    return 0;
}

void initTranscript(Transcript *transcript, int id, int count, int *scores){
	transcript->id=id;
	transcript->count=count;
    if(count>0){
        for (int i=0;i<count;i++){
			transcript->scores=scores;
		}
    }
	else if(count==0){
		transcript=NULL;
	}
}

void getStatistics(const Transcript *transcript, int *total, int *passed){
    *total=0;
    int n=transcript->count;
    int*p=transcript->scores;
	for(int i=0;i<n;i++){
		*total+=*(p+i);
		if(*(p+i)>=60){
			*passed=*passed+1;
		}
	}
}


