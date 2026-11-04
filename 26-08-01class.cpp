/* 
单链表命令处理器

题目

维护一条初始为空的单链表，处理以下命令。下标从0开始。

I p x：在位置 p 插入值 x；合法范围为0≤p≤当前长度，p等于长度表示尾插。
D p：删除位置 p 的节点；合法范围为0≤p<当前长度。
G p：查询位置 p 的值；合法范围同删除。
L：查询当前长度。
I、D 成功时不输出；任何含非法位置的命令输出 ERROR，且链表保持不变。G 合法时输出该值，L 输出长度。所有命令完成后输出整条链表。
实现要求：使用动态分配的单链表；插入、删除函数通过 Node ** 修改相应链接；程序结束前释放所有节点。
输入格式

第一行 q（1≤q≤1000），接下来 q 行为命令。位置参数 -1≤p≤1001；数据 -10000≤x≤10000。

输出格式

依命令产生查询结果或 ERROR，每个结果独占一行。最后另起一行输出链表各值，以单个空格分隔；空链表输出 EMPTY。

样例输入

8
I 0 10
I 1 20
I 1 15
G 1
D 0
L
G 2
I 0 5

样例输出

15
2
ERROR
5 15 20
15
2
ERROR
5 15 20
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int val;
	struct Node*next;
}; 

void ListFree(struct Node*p){
	while(p!=NULL){
		struct Node*t=p->next;
		free(p);
		p=t;
	}
}

int L(struct Node*p){
	int len=0;
	while(p!=NULL){
		len++;
		p=p->next; 
	}
	return len;
}

int I(int num1,int num2,struct Node**p){
	if(num1<0||num1>L(*p)){
		return -1;
	}
	else{
		struct Node*np=(struct Node*)malloc(sizeof(struct Node));
    	np->val=num2;
    	np->next=NULL;
    	if(num1==0){//注意单独讨论头插的情况 
    		np->next=*p;
            *p=np;
		}
		else{
			struct Node*curr=*p;
	     	while(num1>1){//越界维护 
			    num1--;
		    	curr=curr->next;
	    	}
	    	struct Node*t=curr->next;
	    	curr->next=np;
	    	np->next=t;
		}
		return 0;
	}
}

int D(int i,struct Node**p){
	if(i<0||i>=L(*p)||(*p)==NULL){
		return -1;
	}
	else{
		if(i==0){
			struct Node*t=(*p)->next;
			free(*p);
			*p=t;
		}
		else{
			struct Node*curr=*p; 
		    struct Node*prev=curr;
	    	curr=curr->next;
	    	i--;
	    	while(i>0&&curr!=NULL){
		    	i--;
		    	curr=curr->next;
		    	prev=prev->next;
	    	}
	    	struct Node*t=curr->next;
	    	free(curr);
	    	prev->next=t;
		}
		return 0;
	}
}

int G(int i,struct Node*p){
	if(i<0||i>=L(p)){
		return -1;
	}
	else{
		struct Node*curr=p;
		while(i>0){
			i--;
			curr=curr->next;
		}
		return curr->val;
	}
}

int main(){
	int q=0;
	scanf("%d",&q);
	struct Node*p=NULL;
	for (int i=0;i<q;i++){
		char t='0';
		scanf(" %c",&t);//注意空格，用空格来跳过前面的空白字符（%c无法自动跳过） 
		if(t=='I'){
			int num1=0,num2=0;
			int tar=1;
			scanf("%d%d",&num1,&num2);
			tar=I(num1,num2,&p);
			if(tar==-1){
				printf("ERROR\n");
			}
		}
		else if(t=='D'){
			int num=0;
			int tar=1;
			scanf("%d",&num);
			tar=D(num,&p);
			if(tar==-1){
				printf("ERROR\n");
			}
		}
		else if(t=='G'){
			int num=0;
			int tar=1;
			scanf("%d",&num);
			tar=G(num,p);
			if(tar==-1){
				printf("ERROR\n");
			}
			else{
				printf("%d\n",tar);
			}
		}
		else if(t=='L'){
			printf("%d\n",L(p));
		}
	}
	if(p==NULL){
		printf("EMPTY\n");
	}
	else{
		while(p!=NULL){
			printf("%d ",p->val);
			p=p->next; 
		} 
	}
	ListFree(p);
	return 0;
