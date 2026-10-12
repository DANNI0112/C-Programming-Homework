/*题目描述
输入文本串 s 和模式串 p（均不含空格），统计 p 在 s 中出现了多少次（允许重叠）。

输入
两行：第一行 s，第二行 p。长度 1~500，不含空格。

输出
一个整数：出现次数（p 比 s 长时为 0）。

示例
输入：

ababa
aba

输出：

2*/
#include <stdio.h>
#include <string.h>
int main(){
	int k1,k2,n;
	scanf("%d",&k1);
	char white[20][40]={0};
	char black[20][40]={0};
	char list[60][60]={0};
	for (int i=0;i<k1;i++){
		scanf("%s",white[i]);
	}
	scanf("%d",&k2);
	for (int j=0;j<k2;j++){
		scanf("%s",black[j]);
	}
	scanf("%d",&n);
	for (int k=0;k<n;k++){
		scanf("%s",list[k]);
    }
    for (int k=0;k<n;k++){
    	for (int i=0;i<k1;i++){
    	if (strchr(list[k],'@')==NULL||strchr(list[k],'@')-list[k]==0||strchr(list[k],'@')-list[k]==strlen(list[k])){
    		printf("Invalid\n");
    		break;
		}
    	else if (strcmp(strchr(list[k],'@')+1,white[i])==0){
    		printf("White\n");
    		break;
		}
		else if(strcmp(strchr(list[k],'@')+1,black[i])==0){
			printf("Black\n");
			break;
		}
		else if(strcmp(strchr(list[k],'.')+1,black[i])==0){
			printf("Black\n");
			break;
		}
		else {
			printf("Other\n"); 
			break;
		}
	}
	}
	return 0;
}
