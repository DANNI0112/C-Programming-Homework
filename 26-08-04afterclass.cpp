/*枚举交通灯状态机

题目

使用 typedef enum { RED = 0, GREEN, YELLOW } Light 表示交通灯状态。初始状态由输入给出。每次执行一条命令后输出当前状态的数值和名称。

NEXT：按 RED → GREEN → YELLOW → RED 切换一次。
RESET：直接变为 RED。
SHOW：保持状态不变。
注意：本题特意规定枚举顺序为 RED、GREEN、YELLOW，应按本题定义作答。实现中必须使用上述枚举类型。
输入格式

第一行 s 和 q，s为0、1、2之一（依次对应RED、GREEN、YELLOW），1≤q≤1000。随后 q 行，每行一条 NEXT、RESET 或 SHOW 命令。

输出格式

输出 q 行，每行“枚举值 状态名称”，如 1 GREEN。

样例输入

0 5
SHOW
NEXT
NEXT
NEXT
RESET

样例输出

0 RED
1 GREEN
2 YELLOW
0 RED
0 RED
0 RED
1 GREEN
2 YELLOW
0 RED
0 RED
*/
#include <stdio.h>

int main(){
    typedef enum { RED = 0, GREEN, YELLOW } Light;
    int s=0;
    int q=0;
    char t[1000][10]={0};
    scanf("%d%d",&s,&q);
    Light current = (Light)s;
    for(int i=0;i<q;i++){
        scanf("%s",t[i]);
        if(t[i][0]=='N'){
           current++;
           if(current>2){
            current=0;
           }
           if(current == RED){
                printf("%d RED\n",current);
            }
            else if(current == GREEN){
                printf("%d GREEN\n",current);
            }
            else{
                printf("%d YELLOW\n",current);
            }
        }
        else if(t[i][0]=='R'){
            current=0;
            printf("%d RED\n",current);
        }
        else{
            if(current == RED){
                printf("%d RED\n",current);
            }
            else if(current == GREEN){
                printf("%d GREEN\n",current);
            }
            else{
                printf("%d YELLOW\n",current);
            }
        }
    }
    return 0;
}
