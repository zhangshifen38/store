#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"

#define MAX 200

typedef struct Goods{
	int type;			//商品代码 
	char name[MAX];		//商品名称 
	int num;			//商品进货数量 
	double price;		//商品价格
	int time;			//进货时间
	int sold;			//商品销量 
}GOO;
//商品结构体 

typedef struct Goods_Node{
	GOO goods;			//商品结构体主体 
	struct Goods_Node *node;	//结构体指针 
}GOO_N;
//商品链表结点结构体 

typedef struct Customer{
	char name[MAX];		//顾客姓名 
	int star;			//顾客星级 
	double cost;		//消费额 
}CUS;
//顾客信息结构体 

typedef struct Customer_Node{
	CUS customer;		//顾客结构体主体 
	struct Customer_Node *node;//结构体指针 
}CUS_N;
//顾客信息链表结点结构体 

int main(void) {
	
	FILE *user;
	if(user=fopen(".//users.txt","r")==NULL)		//打开用户信息配置文件 
		printf("初始化错误，请检查！");
	else
	{
		int adm=login();			//登录			
	
		int cho=1;
		while(cho)			//用户输入0的时候退出程序 
		{
			title();
			if(adm) admin();	//管理员特殊操作菜单 
			
			cho=menu();		//打开操作菜单 

		}
	}
	return 0;
}
