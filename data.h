#ifndef DATA_H
#define DATA_H

#define ENTER putchar('\n');
#define MAX 200

typedef struct User{
	int adm;			//用户标识符
	char name[MAX];		//用户名 
	char pwd[17];		//密码 
}USER;
//用户结构体

typedef struct User_Node{
	USER user;			//用户结构体主体 
	struct User_Node *node;	//结构体指针 
}USER_N; 

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

#endif
