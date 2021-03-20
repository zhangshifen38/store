#include<stdio.h>
#include<stdlib.h>
#include "data.h"
#include "order.h"
#include<string.h>


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
		fprintf(w,"%d ",(p->goods).type);
		fprintf(w,"%s ",(p->goods).name);
		fprintf(w,"%d ",(p->goods).num);
		fprintf(w,"%lf ",(p->goods).price);
		fprintf(w,"%s ",(p->goods).time);
		fprintf(w,"%d\n",p->goods.sold);
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
			timeinput(now->goods.time);
			now->goods.sold=0;
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

void timeinput(char time1[])
{
	time_t cur;
	struct tm *tm_cur;//时间前置声明
	char year[MAX],month[MAX],day[MAX],hour[MAX],min[MAX],sec[MAX];//年月日小时分钟秒临时字符串
	char mid[MAX];//中转数组
	time(&cur) ;
			tm_cur = localtime(&cur);//获取时间
			itoa(tm_cur->tm_year+1900,year,10);
			itoa(tm_cur->tm_mon+1,month,10);
			itoa(tm_cur->tm_mday,day,10);
			itoa(tm_cur->tm_hour,hour,10);
			itoa(tm_cur->tm_min,min,10);
			itoa(tm_cur->tm_sec,sec,10);//将时间存入临时数组
			strcpy(time1,year);
			memset(mid,'\0',sizeof mid);
			if(tm_cur->tm_mon+1<10)
			{
				mid[0]='0';
				strcat(mid,month);
				strcpy(month,mid);
				strcat(time1,month);
				memset(mid,'\0',sizeof mid);
			}
			else  strcat(time1,month);
			if(tm_cur->tm_mday<10)
			{
				mid[0]='0';
				strcat(mid,day);
				strcpy(day,mid);
				strcat(time1,day);
				memset(mid,'\0',sizeof mid);
			}
			else strcat(time1,day);
			strcat(time1,"_");
			if(tm_cur->tm_hour<10)
			{
				mid[0]='0';
				strcat(mid,hour);
				strcpy(hour,mid);
				strcat(time1,hour);
				strcat(time1,":");
				memset(mid,'\0',sizeof mid);
			}
			else 
			{
				strcat(time1,hour);
				strcat(time1,":");
			}
			
			if(tm_cur->tm_min<10)
			{
				mid[0]='0';
				strcat(mid,min);
				strcpy(min,mid);
				strcat(time1,min);
				strcat(time1,":");
				memset(mid,'\0',sizeof mid);
			}
			else 
			{
				strcat(time1,min);
				strcat(time1,":");
			}
			
			if(tm_cur->tm_sec<10)
			{
				mid[0]='0';
				strcat(mid,sec);
				strcpy(sec,mid);
				strcat(time1,sec);
				memset(mid,'\0',sizeof mid);
			}
			else strcat(time1,sec);
			return;
}

