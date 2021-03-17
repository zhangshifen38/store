#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "login.h"
#include "data.h"
#include "order.h"
#include "dataedit.h"
#include "customer.h"



int main(void) {
	int adm=login();			//登录			
	int cho=1;
	while(cho)					//用户输入0的时候退出程序 
	{
		title();
		if(adm==1) 
			admin();			//管理员特殊操作菜单 
		cho=menu();				//打开操作菜单 
			
		switch(cho)
		{
			case 11:
				goods_in();
				order();
				break;
			case 12:
				add_cus();
				entering();
				break;
			case 13:
				data();
				edit();
				break;
			case 14:
				
				break;
			case 1:sell();break;
			case 2:
				help(adm);
				break;
			default:break;
		}
	}
	return 0;
}
