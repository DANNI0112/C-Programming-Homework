/*题目描述
给出域名白名单和黑名单，对每个邮箱按域名分类。先判断邮箱格式，再看 @ 后面的域名在哪个名单中。

输入
第一行：整数 k1（1 ≤ k1 ≤ 10），白名单域名个数。
后面 k1 行：白名单域名，每行一个，长度 1~30，只含字母、数字、点和连字符，不含空格。
下一行：整数 k2（1 ≤ k2 ≤ 10），黑名单域名个数。
后面 k2 行：黑名单域名，格式同上。
下一行：整数 n（1 ≤ n ≤ 50），待检查邮箱个数。
后面 n 行：待检查邮箱，每行一个，长度 1~50，不含空格。
输出
n 行，对每个邮箱输出一个分类（区分大小写）：

Invalid：@ 的个数不是 1 个，或 @ 在开头或结尾；
否则取 @ 后面的域名 d：
d 与白名单中某一项完全相同 → 输出 White（白名单优先）；
d 与白名单都不相同，再看黑名单：若 d 与某条黑名单相同，或 d 以 "." + 该条黑名单结尾（即它是该黑名单的子域名）→ 输出 Black；
都不满足 → 输出 Other。
例如黑名单中有 spam.com，则 spam.com 和 mail.spam.com 都算 Black，
但 notspam.com 和 spam.com.evil.com 不算。

示例
输入：

2
school.edu.cn
lab.school.edu.cn
1
spam.com
4
alice@school.edu.cn
bob@spam.com
carol@mail.com
bademail

输出：

White
Black
Other
Invalid
White
Black
Other
Invalid*/
#include <stdio.h>
#include <string.h>
int main(){
	int k1,k2,n;
	scanf("%d",&k1);
	char white[20][40]={0};
	char black[20][40]={0};
	char list[60]={0};
	for (int i=0;i<k1;i++){
		scanf("%s",white[i]);
	}
	scanf("%d",&k2);
	for (int j=0;j<k2;j++){
		scanf("%s",black[j]);
	}
	scanf("%d",&n);
	for (int k=0;k<n;k++){
		scanf("%s",list);
		char *first=strchr(list,'@');
	    char *last=strrchr(list,'@');
	    if (first==NULL||first!=last||first==list||*(first+1)=='\0'){
	    	printf("Invalid\n");
			continue; 
		}
		int place=first-list;
		char domain[40];
		int n=0;
		for (int k=place+1;list[k]!='\0';k++){
			domain[n]=list[k];
			n++;
		}
		domain[n]='\0';
		int is_white=0;
		for (int a=0;a<k1;a++){
			if (strcmp(domain,white[a])==0){
			    is_white=1;
			    break;
			}
	    }
	    if (is_white){
	    	printf("White\n");
	    	continue;
		}
		int is_black=0;
		for(int b=0;b<k2;b++){
			if (strcmp(domain, black[b]) == 0) {
                is_black = 1;
                break;
		}
		int len_domain = strlen(domain);
        int len_black = strlen(black[b]);
			if (len_domain > len_black) {
                int start_pos = len_domain - len_black - 1;
                if (domain[start_pos] == '.' && strcmp(domain + start_pos + 1, black[b]) == 0) {
                    is_black = 1;
                    break;
                }
            }
        }
        if (is_black) {
            printf("Black\n");
            continue;
        }
        printf("Other\n");
    }
	return 0;
}
