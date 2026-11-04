/*
单链表的两次翻转

题目

按输入顺序建立一条不带头节点的普通单链表，依次完成以下操作：

用迭代方法原地翻转链表，输出翻转后的序列。
在第 1 步得到的链表上，用递归方法再次原地翻转，输出再次翻转后的序列。
原地翻转是指改变节点之间的 next 链接，不交换节点中的数值。两次翻转均应返回或更新新的头指针。

实现要求：使用动态分配的单链表，分别编写迭代和递归翻转函数；翻转过程中不新建节点、不借助数组保存节点或数值；结束前释放全部节点。递归调用使用的函数调用栈允许使用。

输入格式

第一个整数 n（0≤n≤1000），接下来 n 个整数为节点值，范围 [-10000,10000]。n=0 时没有节点值。

输出格式

输出两行，依次对应两次翻转后的链表。每行的值用单个空格分隔；空链表每行输出 EMPTY。

样例输入

5
1 2 2 -3 5

样例输出

5 -3 2 2 1
1 2 2 -3 5
5 -3 2 2 1
1 2 2 -3 5
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* ListCreateInOrder(int n) {//注意正向读入链表（尾插）
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        struct Node* np = (struct Node*)malloc(sizeof(struct Node));
        np->val = v;
        np->next = NULL;
        if (head == NULL) {
            head = tail = np;
        } else {
            tail->next = np;
            tail = np;
        }
    }
    return head;
}

struct Node* ListTurnIter(struct Node* p) {
    struct Node* prev = NULL;
    while (p != NULL) {
        struct Node* nxt = p->next;
        p->next = prev;      
        prev = p;
        p = nxt;
    }
    return prev;             
}


struct Node* ListTurnRec(struct Node* p) {
    if (p == NULL || p->next == NULL)  
        return p;
    struct Node* newHead = ListTurnRec(p->next);
    p->next->next = p;                  
    p->next = NULL;                     
    return newHead;
}


void ListPrint(struct Node* p) {
    if (p == NULL) {
        printf("EMPTY\n");
        return;
    }
    for (struct Node* q = p; q != NULL; q = q->next)
        printf("%d ", q->val);
    printf("\n");
}


void ListFree(struct Node* p) {
    while (p != NULL) {
        struct Node* t = p->next;
        free(p);
        p = t;
    }
}

int main(void) {
    int n = 0;
    if (scanf("%d", &n) != 1) return 1;

    if (n == 0) {
        printf("EMPTY\nEMPTY\n");
        return 0;
    }

    struct Node* head = ListCreateInOrder(n);   

    head = ListTurnIter(head);
    ListPrint(head);

    head = ListTurnRec(head);
    ListPrint(head);

    ListFree(head);
    return 0;
}
