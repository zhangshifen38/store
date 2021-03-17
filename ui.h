#ifndef UI_H
#define UI_H

#include<string.h>
#include<stdio.h>
#include"data.h"
#include<stdlib.h> 

void title(void);		//标题

void admin(void);		//管理员菜单 

int menu(void);			//主菜单

void goods_in(void);	//读入商品

void add_cus(void);		//客户管理 

void data(void);		//数据管理 

void users(void);		//登录用户管理 

void sell(void);		//售卖模式 

void help(int adm);		//帮助文档 


#endif
