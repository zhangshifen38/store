#include "edit.h"

void edit(void)
{
	GOO_N *now,*head;
	head=inputfromfile();
	puts("从文件读入数据成功！");
	now=head;
	while(now->node!=NULL)
	{
		printf("%d %s %d %lf %s\n",now->goods.type,now->goods.name,now->goods.num,now->goods.price,now->goods.time);
		now=now->node;
	}
	return;
} 

GOO_N * inputfromfile(void)
{
	FILE *input=fopen("orderdata.txt","r");
	GOO_N *head=NULL,*prev,*now;
	int type;//录入时商品代码的中转变量
	while(1)
	{
		now=(GOO_N*)malloc(sizeof(GOO_N));
		if(head==NULL) head=now;//如果是第一个节点
		else prev->node=now;
		now->node=NULL;
		if(fscanf(input,"%d %s %d %lf %s",&now->goods.type,now->goods.name,&now->goods.num,&now->goods.price,now->goods.time)==EOF)
		break;
		prev=now;
	}
	fclose(input);
	return head;	
}