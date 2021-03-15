#include "customer.h"



CUS_N * entering(void) //得到链表的头指针 
{
	CUS_N *head;
	CUS_N *p1,*p2;
	n=0;
	p1=p2=(CUS_N *)malloc(LEN);
	printf("请输入客户的名砸！\n");
	scanf("%s",p1->customer.name);
	printf("请输入客户的星级！\n");
	scanf("%d",&p1->customer.star);
	printf("请输入客户的消费额度！\n");
	scanf("%lld",&p1->customer.cost);
	head=NULL;
	while(p1->customer.star!=0) //结束条件：输入的星级为0时 
	{
	n=n+1;
	if(n==1)head=p1;
	else p2->node=p1;
	p2=p1;
	p1=(CUS_N *)malloc(LEN);
	printf("请输入客户的名砸！\n");
	scanf("%s",p1->customer.name);
	printf("请输入客户的星级！\n");
	scanf("%d",&p1->customer.star);
	printf("请输入客户的消费额度！\n");
	scanf("%lld",&p1->customer.cost);
	}
	p2->node=NULL;
	return(head);
}
