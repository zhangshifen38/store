#include "datamanage.h"

void datamanage(void)
{
	int judge1,judge2;
	while(1)
	{
		puts("����1�������ݲ�ѯ���޸�");
		puts("����2��������ͳ��");
		puts("����3������������");
		scanf("%d",&judge1);getchar();
		switch(judge1)
		{
			case 1:edit1();break;
			case 2:sort();break;
		}
		puts("����1�����������ݹ�������2�˳����ݹ���");
		scanf("%d",&judge2);getchar();
		if(judge2==1) continue;
		if(judge2==2) break;
	}
	return;
}