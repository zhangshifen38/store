#include "data.h"
#include "order.h"
#include "dataedit.h"

void edit1(void)
{
	int judge;
	while(1)
	{
		puts("按1进行商品名称查询与修改。");
		puts("按2进行商品代号查询与修改。");
		puts("按3进行商品价格查询与修改。");
		puts("按4进行固定价格区间查询。");
		int choice;
		scanf("%d",&choice);
		getchar();
		switch(choice)
		{
			case 1:nameedit();break;
			case 2:typeedit();break;
			case 3:priceedit();break;
			case 4:pricesearch();break;
		}
		puts("输入1继续数据查询与修改，输入2退出");
		scanf("%d",&judge);getchar();
		if(judge==1) continue;
		if(judge==2) break;
	}
	return;

}

void nameedit(void)//名称修改
{
	int choice;
	puts("输入1使用商品代号查询，输入2使用商品名称查询");
	scanf("%d",&choice);getchar();
	switch(choice)
	{
		case 1:nameeditbytype();break;
		case 2:nameeditbyname();break;
	}
	return;
}





void nameeditbytype(void)
{
	int type;
	char name[MAX];
	int judge;
	GOO_N *head=readdata();
	GOO_N *now=head;
	puts("请输入商品代码：") ;
	scanf("%d",&type);getchar();
	puts("请输入修改后的商品名称:");
	gets(name);
	while(1)
	{
		if(now->goods.type==type)
		{
			strcpy(now->goods.name,name);
			puts("修改成功！输入1继续修改其他商品名称，输入2退出修改。");
			scanf("%d",&judge);getchar();
			if(judge==2) break;
			if(judge==1)
			{
				now=head;
				puts("请输入商品代码：") ;
				scanf("%d",&type);getchar();
				puts("请输入修改后的商品名称：");
				gets(name);
				continue;
			} 
		}
		if(now->goods.type!=type)
		{
			now=now->node;
		}
	}
	rprint(head);
	delete(head);
	return;
}

void nameeditbyname(void)
{
	char name[MAX];//查询用名称
	char ename[MAX];//修改用名称
	int judge;
	GOO_N *head=readdata();
	GOO_N *now=head;
	puts("请输入商品名称：") ;
	gets(name);
	puts("请输入修改后的商品名称:");
	gets(ename);
	while(1)
	{
		if(strcmp((now->goods).name,name)==0)
		{
			strcpy(now->goods.name,ename);
			puts("修改成功！输入1继续修改其他商品名称，输入2退出修改。");
			scanf("%d",&judge);getchar();
			if(judge==2) break;
			if(judge==1)
			{
				now=head;
				puts("请输入商品名称：") ;
				gets(name);
				puts("请输入修改后的商品名称：");
				gets(ename);
				continue;
			} 
		}
		if(strcmp((now->goods).name,name)!=0)
		{
			now=now->node;
		}
	}
	rprint(head);
	delete(head);
	return;
}


void typeedit(void)//价格修改
{
	int choice;
	puts("输入1使用商品代号查询，输入2使用商品名称查询");
	scanf("%d",&choice);getchar();
	switch(choice)
	{
		case 1:typeeditbytype();break;
		case 2:typeeditbyname();break;
	}
	return;
}

void typeeditbytype(void)
{
	int type;//查询用代号
	int etype;//修改用代号
//	char name[MAX];
//	int num;
//	double price;
	int judge;
	GOO_N *head=readdata();
	GOO_N *now=head;
	puts("请输入商品代码：") ;
	scanf("%d",&type);getchar();
	puts("请输入修改后的商品代号:");
	scanf("%d",&etype);getchar();
	while(1)
	{
		if(now->goods.type==type)
		{
			now->goods.type=etype;
			puts("修改成功！输入1继续修改其他商品代号，输入2退出修改。");
			scanf("%d",&judge);getchar();
			if(judge==2) break;
			if(judge==1)
			{
				now=head;
				puts("请输入商品代码：") ;
				scanf("%d",&type);getchar();
				puts("请输入修改后的商品代号:");
				scanf("%d",&etype);getchar();
				continue;
			} 
		}
		if(now->goods.type!=type)
		{
			now=now->node;
		}
	}
	rprint(head);
	delete(head);
	return;
}


void typeeditbyname(void)
{
	int type;
	char name[MAX];//查询用名称
	int judge;
	GOO_N *head=readdata();
	GOO_N *now=head;
	puts("请输入商品名称：") ;
	gets(name);
	puts("请输入修改后的商品代号:");
	scanf("%d",&type);getchar();
	while(1)
	{
		if(strcmp((now->goods).name,name)==0)
		{
			now->goods.type=type;
			puts("修改成功！输入1继续修改其他商品代号，输入2退出修改。");
			scanf("%d",&judge);getchar();
			if(judge==2) break;
			if(judge==1)
			{
				now=head;
				puts("请输入商品名称：") ;
				gets(name);
				puts("请输入修改后的商品代号:");
				scanf("%d",&type);getchar();
				continue;
			} 
		}
		if(strcmp((now->goods).name,name)!=0)
		{
			now=now->node;
		}
	}
	rprint(head);
	delete(head);
	return;
}
void priceedit(void)//价格编辑
{
	int choice;
	puts("输入1使用商品代号查询，输入2使用商品名称查询");
	scanf("%d",&choice);getchar();
	switch(choice)
	{
		case 1:priceeditbytype();break;
		case 2:priceeditbyname();break;
	}
	return;
}
void priceeditbytype(void)
{
	int type;
	double price;
	int judge;
	GOO_N *head=readdata();
	GOO_N *now=head;
	puts("请输入商品代码：") ;
	scanf("%d",&type);getchar();
	puts("请输入修改后的商品价格:");
	scanf("%lf",&price);getchar();
	while(1)
	{
		if(now->goods.type==type)
		{
			(now->goods).price=price;
			puts("修改成功！输入1继续修改其他商品价格，输入2退出修改。");
			scanf("%d",&judge);getchar();
			if(judge==2) break;
			if(judge==1)
			{
				now=head;
				puts("请输入商品代码：") ;
				scanf("%d",&type);getchar();
				puts("请输入修改后的商品价格：");
				scanf("%lf",&price);getchar();
				continue;
			} 
		}
		if(now->goods.type!=type)
		{
			now=now->node;
		}
	}
	rprint(head);
	delete(head);
	return;
}

void priceeditbyname(void)
{
	char name[MAX];
	double price;
	int judge;
	GOO_N *head=readdata();
	GOO_N *now=head;
	puts("请输入商品名称：") ;
	gets(name);
	puts("请输入修改后的商品价格：");
	scanf("%lf",&price);getchar();
	while(1)
	{
		if(strcmp((now->goods).name,name)==0)
		{
			(now->goods).price=price;
			puts("修改成功！输入1继续修改其他商品价格，输入2退出修改。");
			scanf("%d",&judge);getchar();
			if(judge==2) break;
			if(judge==1)
			{
				now=head;
				puts("请输入商品名称：") ;
				gets(name);
				puts("请输入修改后的商品价格：");
				scanf("%lf",&price);getchar();
				continue;
			} 
		}
		if(strcmp((now->goods).name,name)!=0)
		{
			now=now->node;
		}
	}
	rprint(head);
	delete(head);
	return;
}

void pricesearch(void)
{
	double priceleast;//最低价格
	double pricemost;//最高价格
	GOO_N *head=readdata();
	GOO_N *now=head;
	puts("请输入最低价格：");
	scanf("%lf",&priceleast);getchar();
	puts("请输入最高价格：");
	scanf("%lf",&pricemost);getchar();
	while(now!=NULL)
	{
		if((now->goods.price>=priceleast)&&(now->goods.price<=pricemost))
		{
			printf("%d %s %d %lf %s\n",now->goods.type,now->goods.name,now->goods.sold,now->goods.price,now->goods.time);
		}
		now=now->node;
	}
	delete(head);
	return;
}





GOO_N * readdata(void)//将数据读入链表并返回头指针
{
	int type;
	char name[MAX];
	int num;
	double price;
	char time[MAX];
	int sold;
	FILE *edit=fopen("orderdata.txt","r+");
	GOO_N *head=NULL,*prev,*now;	
	while(fscanf(edit,"%d %s %d %lf %s %d",&type,name,&num,&price,time,&sold)!=EOF)
	{
		now=(GOO_N*)malloc(sizeof(GOO_N));
		if(head==NULL) head=now;
		else prev->node=now;
		now->node=NULL;
		(now->goods).type=type;
		strcpy((now->goods).name,name);
		(now->goods).num=num;
		(now->goods).price=price;
		strcpy(now->goods.time,time);
		now->goods.sold=sold;
		prev=now;
	}//将数据读入链表
	fclose(edit);
	return head;
}



void delete (GOO_N *head)//删除链表
{
	GOO_N *now=head;
	while(now!=NULL)
	{
		head=now->node;
		free(now);
		now=head;
	}
	return;
}



void rprint(GOO_N *head)//重新打印数据
{
	FILE *output=fopen("orderdata.txt","w");
	GOO_N *now=head;
	GOO_N *judgetotheend=head;//判断是否到达最后一个节点
	while(judgetotheend!=NULL)
	{
		fprintf(output,"%d ",(now->goods).type);
		fprintf(output,"%s ",(now->goods).name);
		fprintf(output,"%d ",(now->goods).num);
		fprintf(output,"%lf ",(now->goods).price);
		fprintf(output,"%s ",now->goods.time);
		fprintf(output,"%d\n",now->goods.sold);
		judgetotheend=judgetotheend->node;
		now=now->node;
	}
	fclose(output);
	return;
}
