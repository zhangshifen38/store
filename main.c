#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"

#define MAX 200

typedef struct Goods{
	char type[MAX];		//商品种类 
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
//		login();			//登录
	
		int cho=1;
		while(cho)			//用户输入0的时候退出程序 
		{
			cho=menu();		//打开操作菜单 
/*			switch(cho)
			{
				case 1:goods_in();break;
				case 2:add_cus();break;
				case 3:sell();break;
				default:break;
			}
*/
		}
	}
	system("pause");
	return 0;
}
