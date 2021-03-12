//展示各种界面 
#include <string.h>
#include "ui.h"

void title(void)
{
	puts("********************************");
	puts("*                              *");
	puts("*     小型商品信息管理系统     *");
	puts("*                              *");
	puts("********************************");
	putchar('\n');
}

void admin(void)
{
	puts("********************************");
	puts("*        管理员操作菜单        *");
	puts("*        11) 录入进货单        *");
	puts("*        12) 星级客户管理      *");
	puts("*        13) 数据管理          *");
}

int menu(void)
{
	puts("********************************");
	puts("*        1) 售货模式           *");
	puts("*        2) 帮助               *");
	puts("*        0) 退出程序           *");
	puts("********************************");
	putchar('\n');
	puts("请输入进行的操作序号："); 
	int cus;
	scanf("%d",&cus);
	return cus;
}

int login(void)		//还没写完 
{
	int p;
	p=1;
	return p;
}

void goods_in(void){
	
}
