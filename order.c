#include<stdio.h>
#include<stdlib.h>
#include "data.h"
#include "order.h"

void output(GOO_N *head)//进货单输出到文件
{
	GOO_N *p=head;
	FILE *w=fopen("orderdata.txt","a+");
	if(w==NULL)
	{
		printf("打开进货单数据文档失败！\n");
		return;
	}
	fseek(w,0,SEEK_END);
	while(p)
	{
		
		fprintf(w,"%d\n",(p->goods).type);
		fprintf(w,"%s\n",(p->goods).name);
		fprintf(w,"%d\n",(p->goods).num);
		fprintf(w,"%lf\n",(p->goods).price);
		p=p->node;
	}
	fclose(w);
	puts("进货单数据录入成功！");
	return;
}

void order(void)//进货单数据接收、录入、输出与删除
{
	int judge;
	GOO_N *head=NULL;//进货单节点头指针
	GOO_N *prev,*now;//进货单上一节点，当前节点
	int type;//录入时商品代码的中转变量
	puts("请输入商品代码：");
	while(scanf("%d",&type)!=EOF)
		{
			while(getchar()!='\n')
				continue;
			now=(GOO_N*)malloc(sizeof(GOO_N));
			if(head==NULL) head=now;//如果是第一个节点
			else prev->node=now;
			now->node=NULL;
			(now->goods).type=type;
			puts("请输入商品名称：");
			gets((now->goods).name);
			puts("请输入商品进货数量:");
			scanf("%d",&((now->goods).num));
			while(getchar()!='\n')
				continue;
			puts("请输入商品价格：");
			scanf("%lf",&(now->goods).price);
			while(getchar()!='\n')
				continue;
			puts("请输入下一个商品代码(ctrl+z停止录入)：");
			prev=now;
		}
		puts("输入1退出录入模式；输入0录入数据并退出录入模式");
		scanf("%d",&judge);
		while(getchar()!='\n')
				continue;
		if(judge==1) return;
		if(judge==0)
		{
			output(head);
			now=head;//链表删除
			while(now!=NULL)
			{
				head=now->node;
				free(now);
				now=head;
			}
		}
}