/*题目描述
某公司有 n 个仓库，所有仓库保管同一种货物，每个仓库记录编号和当前库存。现有 q 条调拨指令，每条指令要求从一个仓库向另一个仓库调拨一定数量的货物。

按输入顺序处理指令。两个仓库都存在，且源仓库库存足够时，调拨成功；否则调拨失败，两个仓库的库存均保持原样。

允许源仓库和目标仓库相同，此时仍先判断库存是否足够；足够则指令成功，库存保持原样。

类型定义与函数接口
typedef struct {
    int id;
    int stock;
} Warehouse;

Warehouse *findWarehouse(Warehouse *warehouses, int n, int id);
int transferStock(Warehouse *from, Warehouse *to, int amount);
?
需要完成两个函数：

findWarehouse：按编号查找仓库。找到时返回指向原数组中该仓库的指针；找不到时返回 NULL。查找不得改变数组内容或顺序。
transferStock：使用指针修改两个仓库的库存。成功返回 1，失败返回 0。from 或 to 为 NULL 时失败；两者可能指向同一个结构体。
amount 保证为正数。仓库编号互不相同，所有库存修改只能在原结构体中进行。

输入格式
第一行两个整数 n q。

接下来 n 行，每行两个整数 id stock，表示仓库编号和初始库存。

接下来 q 行，每行三个整数 fromId toId amount，表示一条调拨指令。指令中的仓库编号可能不存在。

数据范围：1 <= n <= 1000，0 <= q <= 1000，编号在 [1, 1000000000] 范围内，初始库存和调拨数量分别满足 0 <= stock <= 1000000、1 <= amount <= 1000000。

输出格式
前 q 行依次输出各条指令的结果：成功输出 OK，失败输出 FAIL。

接下来 n 行，按照仓库输入顺序输出最终的 id stock。

样例 1
输入：

3 5
10 8
20 3
30 0
10 20 5
20 30 10
99 10 1
20 20 4
20 30 8

输出：

OK
FAIL
FAIL
OK
OK
10 3
20 0
30 8
OK
FAIL
FAIL
OK
OK
10 3
20 0
30 8*/
#include <stdio.h>

typedef struct {
    int id;
    int stock;
} Warehouse;

Warehouse *findWarehouse(Warehouse *warehouses, int n, int id);
int transferStock(Warehouse *from, Warehouse *to, int amount);

int main(void) {
    Warehouse warehouses[1000];
    int n, q;
    if (scanf("%d%d", &n, &q) != 2) return 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &warehouses[i].id, &warehouses[i].stock);
    }
    for (int i = 0; i < q; ++i) {
        int fromId, toId, amount;
        scanf("%d%d%d", &fromId, &toId, &amount);
        Warehouse *from = findWarehouse(warehouses, n, fromId);
        Warehouse *to = findWarehouse(warehouses, n, toId);
        puts(transferStock(from, to, amount) ? "OK" : "FAIL");
    }
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", warehouses[i].id, warehouses[i].stock);
    }
    return 0;
}

#include <func.h>
Warehouse *findWarehouse(Warehouse *warehouses, int n, int id){
	int t=0;
	for (int i=0;i<n;i++){
		if(warehouses[i].id==id){
			t++;
			return &warehouses[i];
		}
	}
	return NULL;
}
int transferStock(Warehouse *from, Warehouse *to, int amount){
	if (from==NULL||to==NULL){
		return 0;
	}
    else if ((from->stock)<amount){
        return 0;
    }
	else{
		from->stock-=amount;
		to->stock+=amount;
	}
    return 1;
}
