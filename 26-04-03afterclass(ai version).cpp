#include <stdio.h>
#include <string.h>
int main(){
	char s[501];
	char p[501];
	scanf("%s",s);
	scanf("%s",p);
	int l1,l2;
	int a=0;
	l1=strlen(s);
	l2=strlen(p);
	if (l2>l1){
		printf("%d",0);
	}
	else{
		for (int i=0;i<=l1-l2;i++){
			int match=1;
			for (int j=0;j<l2;j++){
				if (s[i+j]!=p[j]){
					match=0;
					break;
				}
			}
		if (match==1){
			a++;
		}
		}
	printf("%d",a);
	}
	return 0;
} 
