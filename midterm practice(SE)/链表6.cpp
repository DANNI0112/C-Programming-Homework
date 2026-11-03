#include <stdio.h>
#include <stdlib.h>

struct Node{
	int val;
	struct Node*next; 
};

struct Node* build(){
    struct Node*p=(struct Node*)malloc(sizeof(struct Node));
    p->val = -1;//需要对p初始化，但是注意不要把这个节点计入栈 
    p->next = NULL;
    return p;
} 

int push(int i,struct Node**p){
	if(i>10000||i<0){
		return -1;
	}
	else {
		struct Node*np=(struct Node*)malloc(sizeof(struct Node));
    	np->val=i;
    	np->next=NULL;
		if(*p==NULL){
	    	*p=np;
    	}
	    else{
		    np->next=*p;
	    	*p=np;
	    }
	    return 0;
	}
}

int pop(struct Node**p){
	if(*p!=NULL&&(*p)->val!=-1){//把p排除 
		struct Node*t=(*p)->next;
		free(*p);
		*p=t;
		return 0;
	}
	else{
		return -1;
	}
}

int top(struct Node*p){
	if(p!=NULL&&p->val!=-1){//把p排除 
		return p->val;
	} 
	else{
		return -1;
	}
}

int size(struct Node*p){
	if (p==NULL){
		return 0;
	} 
	else{
		int num=0;
		while(p!=NULL){
			num++;
			p=p->next;
		}
		num--;//把p排除 
		return num; 
	}
}

int main(){
	struct Node*p=NULL;//注意定义p的位置，不要放在循环内以免每次重新置空 
	for(int i=0;i<100;i++){
		int n;
		scanf("%d",&n);
		if(n==0){
			p=build(); 
		}
		else if(n==1){
			int num=-1;
			int target=1;
			scanf("%d",&num);
			target=push(num,&p);
			if(target==0){
				printf("Push %d to Stack\n",num);
			}
			else {
				printf("Please check the pushed data\n");
			}
		}
		else if(n==2){
			int target=1;
			target=pop(&p);
			if(target==0){
				printf("Pop succeed\n");
			}
			else {
				printf("No data to pop\n");
			}
		}
		else if(n==3){
			int target=1;
			target=top(p);
			if(target==-1){
				printf("The Stack is no data\n");
			}
			else{
				printf("The Stack's top is %d\n",target);
			}
		}
		else if(n==4){
			int target=-1;
			target=size(p);
			printf("The Stack's size is %d\n",target);
		}
		else if(n==-1){
			return 0;
		}
	}
}
