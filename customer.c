#include "customer.h"



CUS_N * entering(void) //�õ������ͷָ�� 
{
	CUS_N *head;
	CUS_N *p1,*p2;
	n=0;
	p1=p2=(CUS_N *)malloc(LEN);
	printf("������ͻ������ң�\n");
	scanf("%s",p1->customer.name);
	printf("������ͻ����Ǽ���\n");
	scanf("%d",&p1->customer.star);
	printf("������ͻ������Ѷ�ȣ�\n");
	scanf("%lld",&p1->customer.cost);
	head=NULL;
	while(p1->customer.star!=0) //����������������Ǽ�Ϊ0ʱ 
	{
	n=n+1;
	if(n==1)head=p1;
	else p2->node=p1;
	p2=p1;
	p1=(CUS_N *)malloc(LEN);
	printf("������ͻ������ң�\n");
	scanf("%s",p1->customer.name);
	printf("������ͻ����Ǽ���\n");
	scanf("%d",&p1->customer.star);
	printf("������ͻ������Ѷ�ȣ�\n");
	scanf("%lld",&p1->customer.cost);
	}
	p2->node=NULL;
	return(head);
}
