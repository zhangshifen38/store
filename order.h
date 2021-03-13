#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Goods {
	char type[MAX];		//商品种类
	char name[MAX];		//商品名称
	int num;			//商品进货数量
	double price;		//商品价格
	int time;			//进货时间
	int sold;			//商品销量
} GOO;
//商品结构体主体

typedef struct Goods_Node {
	GOO goods;			//商品结构体主体
	struct Goods_Node *next;	//结构体指针
} GOO_N;

typedef GOO_N * List;
//商品链表结点结构体

void initializeorder(List *plist);//初始化链表
void add(GOO goods,List *plist);//在链表末尾添加项
void delete(List *plist);//删除链表