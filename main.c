#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "login.h"
#include "data.h"



int main(void) {
	int adm=login();			//��¼			
	int cho=1;
	while(cho)					//�û�����0��ʱ���˳����� 
	{
		title();
		if(adm==1) 
			admin();			//����Ա��������˵� 
		cho=menu();				//�򿪲����˵� 
			
		switch(cho)
		{
			case 11:
				goods_in();
				order();
				break;
			case 12:add_cus();break;
			case 13:
				edit();
				break;
			case 1:sell();break;
			case 2:help();break;
			default:break;
		}
	}
	return 0;
}
