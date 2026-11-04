/*
单链表按值查找

题目

按输入顺序建立一条不带头节点的普通单链表。随后进行 q 次按值查找：每次给出整数 x，输出 x 第一次出现的下标和出现总次数。下标从 0 开始；若不存在，输出 -1 0。查找操作不改变链表。

实现要求：使用 typedef 为节点结构体定义别名 Node，动态分配节点；查找时沿 next 顺序遍历；程序结束前释放全部节点。

输入格式

第一行两个整数 n、q（0≤n≤1000，1≤q≤100）。接下来 n 个整数为节点值，随后 q 个整数为各次查询值；所有值均在 [-10000,10000] 内。各整数之间由空白字符分隔。

输出格式

输出 q 行，每行两个整数“首次下标 出现次数”，用一个空格分隔。

样例输入

5 4
7 2 7 -1 7
7 2 8 -1

样例输出

0 3
1 1
-1 0
3 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int val;
    struct ListNode*next;
}Node;

Node* ListCreate(int i,Node**head,Node**tail){
    Node *np=(Node*)malloc(sizeof(Node));
    np->val=i;
    np->next=NULL;
    if((*head)==NULL){
        *head=np;
        *tail=np;
    }
    else{
        (*tail)->next=np;
        *tail=np;
    }
    return *head;//引入tail进行尾插，返回head作为头节点
}

void ListFree(Node*p){
    while(p!=NULL){
        Node*t=p->next;
        free(p);
        p=t;
    }
}

int main(){
    int n,q;
    Node* p=NULL;
    Node* tail=NULL;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
        int m=0;
        scanf("%d",&m);
        p=ListCreate(m,&p,&tail);
    }
    int num[100]={0};
    for(int i=0;i<q;i++){
        scanf("%d",&num[i]);
    }
    for(int i=0;i<q;i++){
        int tar=-1;
        int sum=0;
        int idx=-1;
        Node *curr=p;//引入curr防止p在循环中改变值
        while(curr!=NULL){
            idx++;
            if(curr->val==num[i]&&tar==-1){
                tar=idx;
                sum++;
            }
            else if(curr->val==num[i]){
                sum++;
            }
            curr=curr->next;
        }
        printf("%d %d\n",tar,sum);
    }
    ListFree(p);
    return 0;
}

