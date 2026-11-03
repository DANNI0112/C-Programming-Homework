#include <stdio.h>
int arr[10000]={0};

void build(){
	int arr[10000]={0};
	for(int i=0;i<10000;i++){
		arr[i]=-1;
	}
}

int push(int x){
	if (x<0||x>10000){
		return -1;
	} 
	else {
		return 0;
	}
}

int pop(int arr[],int i){
	if(arr[i]==-1||i<0){
		return -1;
	}
	else{
		arr[i]=-1;
		return 0;
	}
}

int top(int arr[],int i){
	if(arr[i]==-1||i<0){
		return -1;
	}
	else{
		return arr[i];
	}
}

int size(int i){
    return i+1;
}

int main(){
	build();
	for (int i=0;i<100;i++){
		int n=10;
		scanf("%d",&n);
		if(n==0){
			i--;//注意维护下标
		}
		if (n==1){
		    scanf("%d",&arr[i]);
		    int num=push(arr[i]);
		    if(num==-1) {
		    	i--;//注意维护下标 
		    	printf("Please check the pushed data\n");
			}
			else {
				printf("Push %d to Stack\n",arr[i]);
			}
		}
		else if(n==2){
			i--;//注意维护下标
			int num=pop(arr,i);
			if(num==0){
				i--;//注意维护下标
				printf("Pop succeed\n");
			}
			else{
				printf("No data to pop\n");
			}
		}
		else if(n==3){
			i--;//注意维护下标
			int num=top(arr,i);
			if(num==-1){
				printf("The Stack is no data\n");
			}
			else{
				printf("The Stack's top is %d\n",arr[i]);
			}
		}
		else if(n==4){
			i--;//注意维护下标
			int num=size(i);
			if(num>=0){
				printf("The Stack's size is %d\n",num);
			}
		}
		else if(n==-1){
			return 0;
		}
	}
	return 0;
}
