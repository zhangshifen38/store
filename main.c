#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "login.h"
#include "data.h"
#include "order.h"
#include "dataedit.h"
#include "customer.h"
#include "edit.h"



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
			case 11:			//¼������� 
				goods_in();
				order();
				break;
			case 12:			//�Ǽ��ͻ����� 
				add_cus();
				entering();
				break;
			case 13:			//���ݹ��� 
				data();
				edit1();
				break;
			case 14:			//��¼�˻����� 
				users();
				account();
				break;
			case 1:
				sell();			//�ۻ�ģʽ 
				break;
			case 2:				//���� 
				help(adm);
				break;
			default:break;
		}
	}
	return 0;
}
