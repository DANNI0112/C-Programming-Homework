/*题目描述
输入两个不含空格的单词 a、b，把 b 拼到 a 后面，输出拼接结果和它的长度。

输入
两个字符串 a b，可以用空格或换行分隔，每个长度 1~100，不含空格。

输出
第一行：拼接后的字符串。
第二行：拼接后字符串的长度。

示例
输入：

hello world
输出：

helloworld
10*/
#include <stdio.h>
#include <string.h>
int main(){
	char a[101];
	char b[101];
	int l=0;
	scanf("%s %s",a,b);
	printf("%s\n",strcat(a,b));
	l=strlen(a);
	printf("%d",l);
	return 0;
}
