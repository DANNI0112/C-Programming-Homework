/*题目描述
输入一个不含空格的字符串，输出它的长度和逆序结果。

输入
一个字符串 str，长度 1~100，不含空格。

输出
第一行：字符串的长度。
第二行：逆序后的字符串。

示例
输入：
hello
输出：
5
olleh*/
#include <stdio.h>
#include <string.h>
int main(){
	char str[101];
	int l;
	scanf("%s",str);
	l=strlen(str);
	printf("%d\n",l);
	for (int i=l-1;i>=0;i--){
		printf("%c",str[i]);
	}
	return 0;
}
