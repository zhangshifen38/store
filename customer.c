#include "customer.h"


void check_cus(void)
{
	FILE *fp;
	if((fp=fopen(".//starcus.txt","r"))==NULL)
	{
		fp=fopen(".//starcus.txt","w");
		fclose(fp);
	}
}

int choose_cus(void)
{
	int c;
	puts("请选择您要进行的操作：");
	puts("1) 添加星级客户   2) 修改客户信息");
	puts("0) 退出"); 
	scanf("%d",&c);getchar();
	return c; 
}

void change_cus(void)
{
	;
}

void create_cus(CUS_N **target)
{
	CUS_N *head=NULL;
	CUS_N *previous,*current;		
	
	current=(CUS_N*)malloc(sizeof(CUS_N));
	puts("请输入客户的名字（输入0结束输入）：");
	gets(current->customer.name);
	previous=current;
	while(previous->customer.name[0]!='0')
	{
		if(head!=NULL)
		{
			current=(CUS_N*)malloc(sizeof(CUS_N));
			puts("请输入下一位客户的名字（输入0结束输入）:");
			gets(current->customer.name);
		}
		else
		{
			head=current;
		}
		
		if(current->customer.name[0]!='0')
		{
			puts("请输入客户的星级：");
			scanf("%d",&current->customer.star);getchar();
			current->customer.cost=0;
			previous->node=current;
			previous=current;
			current->node=NULL;
		}
		else
		{
			previous=current;
		}
	}
	*target=head;
}

void write_cus(CUS_N *point)
{
	FILE *fp;
	if((fp=fopen(".//starcus.txt","a+"))==NULL)
	{
		printf("导入星级客户异常！\n");
	}
	else
	{
		fseek(fp,0,SEEK_END); 
		while(point!=NULL)
		{
		 	fprintf(fp,"%s %d %lf\n",
		 		point->customer.name,point->customer.star,point->customer.cost);
		 	point=point->node;
		}
		puts("保存星级客户数据成功！");
	}
	fclose(fp);
}

void destroy_cus(CUS_N *target)
{
	CUS_N *current=target;
	while(current!=NULL)
	{
		target=current->node;
		free(current);
		current=target;
	}
}

void entering(void)
{
	
	check_cus();
	
	int cho;
	CUS_N *cus=NULL;
	
	while((cho=choose_cus())!=0)
	{
		if(cho==1)
		{
			create_cus(&cus);
			
			
		}
		else if(cho==2)
		{
			 
			change_cus();
		}
	} 
	write_cus(cus);
	destroy_cus(cus);
}
