#include "sort.h"

void sort(void)
{
	int judge1,judge2;
	while(1)
	{
		puts("����1��ĳʱ����Ʒ�������������");
		puts("����2�Լ۸�������Ʒ�������򣨼۸�Ӹߵ��ͣ�");
		scanf("%d",&judge1);getchar();
		switch(judge1)
		{
			case 1: sold_sort();break;
			case 2: price_sort();break;
		}
		puts("����1������������ͳ�ƣ�����2�˳�");
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
	puts("�����뿪ʼʱ�䣨�밴��20210320_09:03:18��ʽ���룩");
	gets(start);
	puts("���������ʱ�䣨�밴��20210320_09:03:18��ʽ���룩");
	gets(end);
	puts("����1����С������������2���Ӵ�С����");
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
	double price_least;//��ͼ۸�
	double price_most;//��߼۸�
	GOO_N *head=readdata();//��ȡ���ݵõ�����
	GOO_N *now=head;
	puts("��������ͼ۸�");
	scanf("%lf",&price_least);getchar();
	puts("��������߼۸�");
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




void sort_list_small(GOO_N *head) //���۶��С��������
{
 	GOO t;//��ת�ṹ��
 	GOO_N *p,*q;//��������
 	for(p=head; p!=NULL; p=p->node)
 	{
		for(q=p->node;q!=NULL;q=q->node)
		{
			if((p->goods.price*p->goods.sold)>(q->goods.price*q->goods.sold))					//�����������е� a[i]>a[j]
			{
				t=p->goods;					//�����������е�    t=a[i];
				p->goods=q->goods;				//�����������е�    a[i]=a[j];
				q->goods=t;					//�����������е�    a[j]=t;
			}
		}
	 }
	return; 
} 



void sort_list_big(GOO_N *head) //���۶�Ӵ�С����
{
 	GOO t;//��ת�ṹ��
 	GOO_N *p,*q;//��������
 	for(p=head; p!=NULL;p=p->node)
 	{
		for(q=p->node;q!=NULL;q=q->node)
		{
			if((p->goods.price*p->goods.sold)<(q->goods.price*q->goods.sold))					//�����������е� a[i]>a[j]
			{
				t=p->goods;					//�����������е�    t=a[i];
				p->goods=q->goods;				//�����������е�    a[i]=a[j];
				q->goods=t;					//�����������е�    a[j]=t;
			}
		}
	 }
	return; 
} 



void price_sort_big(GOO_N *head)//�۸�Ӵ�С����
{
	GOO t;//��ת�ṹ��
 	GOO_N *p,*q;
 	for(p=head; p!=NULL; p=p->node)
 	{
		for(q=p->node;q!=NULL;q=q->node)
		{
			if(p->goods.price<q->goods.price)					//�����������е� a[i]>a[j]
			{
				t=p->goods;					//�����������е�    t=a[i];
				p->goods=q->goods;				//�����������е�    a[i]=a[j];
				q->goods=t;					//�����������е�    a[j]=t;
			}
		}
	 }
	return; 
}	