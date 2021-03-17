#include "customer.h"




void entering(void)
{
	CUS_N *head;
	CUS_N *p1,*p2;
	int n;
	n=0;
	int LEN=sizeof(CUS_N);
	p1=p2=(CUS_N *)malloc(LEN);
	printf("请输入客户的名砸！\n");
	scanf("%s",p1->customer.name);
	printf("请输入客户的星级！\n");
	scanf("%d",&p1->customer.star);
	printf("请输入客户的消费额度！\n");
	scanf("%lf",&p1->customer.cost);
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
	scanf("%lf",&p1->customer.cost);
	getchar();
	}
	p2->node=NULL;
	CUS_N *point;
	point=head;
		FILE *fp;
		if((fp=fopen(".//starcus.txt","w"))==NULL)
		{
		printf("cannot open file\n");
		exit(0);
		 } 
		 fprintf(fp,"客户名		客户星级		客户消费额度	\n");
		 while(point!=NULL)
		 {
		 	fprintf(fp,"%s		%d		%lf		\n",
			 	point->customer.name,point->customer.star,point->customer.cost);
		 	point=point->node;
		 }
		 free(head);
}
