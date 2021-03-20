#include "sort.h"

void sort(void)
{
	int judge1,judge2;
	while(1)
	{
		puts("输入1对某时段商品售卖额进行排序");
		puts("输入2对价格区间商品进行排序（价格从高到低）");
		scanf("%d",&judge1);getchar();
		switch(judge1)
		{
			case 1: sold_sort();break;
			case 2: price_sort();break;
		}
		puts("输入1继续进行数据统计，输入2退出");
		scanf("%d",&judge2);getchar();
		if(judge2==1) continue;
		if(judge2==2) break;
	}
	return;	
}

void sold_sort(void)
{
	GOO_N *head=readdata();
	int judge;
	char start[MAX],end[MAX];
	puts("请输入开始时间（请按照20210320_09:03:18格式输入）");
	gets(start);
	puts("请输入结束时间（请按照20210320_09:03:18格式输入）");
	gets(end);
	puts("输入1按从小到大排序，输入2按从大到小排序");
	scanf("%d",&judge);getchar();
	if(judge==1)
	{
		sort_list_small(head);
		GOO_N *now=head;
		while((now!=NULL)&&(strcmp(start,now->goods.time)<=0)&&(strcmp(end,now->goods.time)>=0))
		{
				printf("%d %s %d %lf %s %d\n",now->goods.type,now->goods.name,now->goods.num,now->goods.price,now->goods.time,now->goods.sold);
				now=now->node;
		}
		delete(head);
	} 
	if(judge==2)
	{
		sort_list_big(head);
		GOO_N *now=head;
		while((now!=NULL)&&(strcmp(start,now->goods.time)<=0)&&(strcmp(end,now->goods.time)>=0))
		{
				printf("%d %s %d %lf %s %d\n",now->goods.type,now->goods.name,now->goods.num,now->goods.price,now->goods.time,now->goods.sold);
				now=now->node;
		}
		delete(head);
	}	
	return;	
}

void price_sort(void)
{
	double price_least;//最低价格
	double price_most;//最高价格
	GOO_N *head=readdata();//读取数据得到链表
	GOO_N *now=head;
	puts("请输入最低价格：");
	scanf("%lf",&price_least);getchar();
	puts("请输入最高价格：");
	scanf("%lf",&price_most);getchar();
	price_sort_big(head);
	now=head;
	while((now!=NULL)&&(now->goods.price>=price_least)&&(now->goods.price<=price_most))
	{
		printf("%d %s %d %lf %s %d\n",now->goods.type,now->goods.name,now->goods.num,now->goods.price,now->goods.time,now->goods.sold);
		now=now->node;
	}
	delete(head);
	return;
}




void sort_list_small(GOO_N *head) //销售额从小到大排序
{
 	GOO t;//中转结构体
 	GOO_N *p,*q;//计数变量
 	for(p=head; p!=NULL; p=p->node)
 	{
		for(q=p->node;q!=NULL;q=q->node)
		{
			if((p->goods.price*p->goods.sold)>(q->goods.price*q->goods.sold))					//类似于数组中的 a[i]>a[j]
			{
				t=p->goods;					//类似于数组中的    t=a[i];
				p->goods=q->goods;				//类似于数组中的    a[i]=a[j];
				q->goods=t;					//类似于数组中的    a[j]=t;
			}
		}
	 }
	return; 
} 



void sort_list_big(GOO_N *head) //销售额从大到小排序
{
 	GOO t;//中转结构体
 	GOO_N *p,*q;//计数变量
 	for(p=head; p!=NULL;p=p->node)
 	{
		for(q=p->node;q!=NULL;q=q->node)
		{
			if((p->goods.price*p->goods.sold)<(q->goods.price*q->goods.sold))					//类似于数组中的 a[i]>a[j]
			{
				t=p->goods;					//类似于数组中的    t=a[i];
				p->goods=q->goods;				//类似于数组中的    a[i]=a[j];
				q->goods=t;					//类似于数组中的    a[j]=t;
			}
		}
	 }
	return; 
} 



void price_sort_big(GOO_N *head)//价格从大到小排序
{
	GOO t;//中转结构体
 	GOO_N *p,*q;
 	for(p=head; p!=NULL; p=p->node)
 	{
		for(q=p->node;q!=NULL;q=q->node)
		{
			if(p->goods.price<q->goods.price)					//类似于数组中的 a[i]>a[j]
			{
				t=p->goods;					//类似于数组中的    t=a[i];
				p->goods=q->goods;				//类似于数组中的    a[i]=a[j];
				q->goods=t;					//类似于数组中的    a[j]=t;
			}
		}
	 }
	return; 
}	