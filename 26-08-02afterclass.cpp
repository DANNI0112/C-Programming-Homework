/*
循环链表轮值记录

题目

n 名同学按输入顺序围成一圈，编号互不相同。使用循环单链表保存他们，尾节点的 next 指向首节点。从下标 s 对应的同学开始记录，共记录 k 次：每次先输出当前同学的编号，然后沿 next 前进一步。下标从0开始。
实现要求：实际建立循环单链表，使用指针前进。释放时应先断开环，再释放全部节点。

输入格式

第一行 n、s、k（1≤n≤1000，0≤s<n，1≤k≤2000）；接下来 n 个互不相同的编号，范围[1,10000]。

输出格式

输出一行 k 个编号，以单个空格分隔。

样例输入

3 1 7
11 22 33
样例输出

22 33 11 22 33 11 22
22 33 11 22 33 11 22
*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node*next;
};

struct Node* ListCreate(int arr[],int n){
    if(n==0){
        return NULL;
    }
    else{
        struct Node*head=(struct Node*)malloc(sizeof(struct Node));
        head->val=arr[0];
        head->next=head;
        struct Node* tail=head;
        for(int i=1;i<n;i++){
            struct Node*p=(struct Node*)malloc(sizeof(struct Node));
            p->val=arr[i];
            p->next=head;
            tail->next=p;
            tail=p;
        }
        return head;
    }
}

int main(){
    int n=0,s=0,k=0;
    scanf("%d%d%d",&n,&s,&k);
    int arr[10000]={0};
    struct Node*head=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    head=ListCreate(arr,n);
    while(s>0){
        head=head->next;
        s--;
    }
    while(k>0){
        printf("%d ",head->val);
        head=head->next;
        k--;
    }

    return 0;
}
