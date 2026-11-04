/*
共用体数值记录

题目

有 n 条数值记录，每条保存一个整数或一个实数。先按输入顺序将全部记录保存到结构体数组，再遍历该数组，分别统计整数记录和实数记录的条数与数值总和。

请使用以下类型定义：

typedef union {
    int i;
    double d;
} Number;
typedef struct {
    char type;
    Number value;
} Record;
?
type 为 I 时只向 value.i 写入整数并从该成员读取；为 D 时只向 value.d 写入实数并从该成员读取。一个共用体在同一时刻保存对应类型的一个数值。

输入格式

第一行 n（1≤n≤1000）。随后 n 行，每行是 I x 或 D y。x 为 [-10000,10000] 内的整数；y 为同范围内的小数，输入恰有两位小数，且为 0.25 的整数倍（例如 -1.25、0.00、2.50），允许为负数。

输出格式

固定输出两行：

INT 整数条数 整数总和
DOUBLE 实数条数 实数总和

实数总和保留两位小数；某类没有记录时，该类条数为 0，总和分别输出 0 或 0.00。若实数总和为零，输出 0.00。

样例输入

5
I 3
D 1.25
I -2
D 2.50
D -0.75

样例输出

INT 2 1
DOUBLE 3 3.00


*/
#include <stdio.h>
#include <stdlib.h>

typedef union {
    int i;
    double d;
} Number;

typedef struct {
    char type;
    Number value;
} Record;

int main(){
    int n=0;
    scanf("%d",&n);
    Record list[1000]={0};
    int total1=0;
    double total2=0;
    int sum1=0;
    int sum2=0;
    for (int i=0;i<n;i++){
        scanf(" %c",&list[i].type);//注意空格，%c无法自动跳过空格
        if(list[i].type=='I'){
            scanf("%d",&list[i].value.i);
            total1+=list[i].value.i;
            sum1++;
        }
        else{
            scanf("%lf",&list[i].value.d);
            total2+=list[i].value.d;
            sum2++;
        }
    }
    printf("INT %d %d\nDOUBLE %d %.2lf",sum1,total1,sum2,total2);
    return 0;
}
