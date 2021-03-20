#include "datamanage.h"

void datamanage(void)
{
	int judge1,judge2;
	while(1)
	{
		puts("输入1进行数据查询与修改");
		puts("输入2进行数据统计");
		puts("输入3进行数据排序");
		scanf("%d",&judge1);getchar();
		switch(judge1)
		{
			case 1:edit1();break;
			case 2:sort();break;
		}
		puts("输入1继续进行数据管理，输入2退出数据管理");
		scanf("%d",&judge2);getchar();
		if(judge2==1) continue;
		if(judge2==2) break;
	}
	return;
}