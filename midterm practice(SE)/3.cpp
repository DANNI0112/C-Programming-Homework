#include <stdio.h>

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int mid=0;
	if (a<=b){
		if(a<=c){
			if(c<=b){
				mid=c;
			}
			else{
				mid=b;
			}
		}
		else{
			mid=a;
		}
	}
	else{
		if(a>c){
			if(c<=b){
				mid=b;
			}
			else{
				mid=c;
			}
		}
		else{
			mid=a;
		}
	}
	printf("%d",mid);
	return 0;
}
