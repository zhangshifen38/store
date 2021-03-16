#include "data.h"
#include "order.h"
#include "dataedit.h"

void edit(void)
{
	int judge;
	while(1)
	{
		puts("��1������Ʒ���Ʋ�ѯ���޸ġ�");
		puts("��2������Ʒ���Ų�ѯ���޸ġ�");
		puts("��3������Ʒ�۸��ѯ���޸ġ�");
		puts("��4���й̶��۸������ѯ��");
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
		puts("����1�������ݲ�ѯ���޸ģ�����2�˳�");
		scanf("%d",&judge);getchar();
		if(judge==1) continue;
		if(judge==2) break;
	}
	return;

}

void nameedit(void)//�����޸�
{
	int choice;
	puts("����1ʹ����Ʒ���Ų�ѯ������2ʹ����Ʒ���Ʋ�ѯ");
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
	int num;
	double price;
	int judge;
	FILE *edit=fopen("orderdata.txt","r+");
	GOO_N *head=NULL,*prev,*now;	
	while(fscanf(edit,"%d %s %d %lf",&type,name,&num,&price)!=EOF)
	{
		now=(GOO_N*)malloc(sizeof(GOO_N));
		if(head==NULL) head=now;
		else prev->node=now;
		now->node=NULL;
		(now->goods).type=type;
		strcpy((now->goods).name,name);
		(now->goods).num=num;
		(now->goods).price=price;
		prev=now;
	}//�����ݶ�������
	fclose(edit);
	now=head;
	puts("��������Ʒ���룺") ;
	scanf("%d",&type);getchar();
	puts("�������޸ĺ����Ʒ����:");
	gets(name);
	while(1)
	{
		if(now->goods.type==type)
		{
			strcpy(now->goods.name,name);
			puts("�޸ĳɹ�������1�����޸�������Ʒ���ƣ�����2�˳��޸ġ�");
			scanf("%d",&judge);getchar();
			if(judge==2) break;
			if(judge==1)
			{
				now=head;
				puts("��������Ʒ���룺") ;
				scanf("%d",&type);getchar();
				puts("�������޸ĺ����Ʒ���ƣ�");
				gets(name);
				continue;
			} 
		}
		if(now->goods.type!=type)
		{
			now=now->node;
		}
	}
	FILE *output=fopen("orderdata.txt","w");
	now=head;
	GOO_N *judgetotheend=head;//�ж��Ƿ񵽴����һ���ڵ�
	while(judgetotheend!=NULL)
	{
		fprintf(output,"%d ",(now->goods).type);
		fprintf(output,"%s ",(now->goods).name);
		fprintf(output,"%d ",(now->goods).num);
		fprintf(output,"%lf\n",(now->goods).price);
		judgetotheend=judgetotheend->node;
		now=now->node;
	}
	fclose(output);
	now=head;
	while(now!=NULL)
	{
		head=now->node;
		free(now);
		now=head;
	}
	return;
}

void nameeditbyname(void)
{
	int type;
	char name[MAX];//��ѯ������
	char ename[MAX];//�޸�������
	int num;
	double price;
	int judge;
	FILE *edit=fopen("orderdata.txt","r+");
	GOO_N *head=NULL,*prev,*now;	
	while(fscanf(edit,"%d %s %d %lf",&type,name,&num,&price)!=EOF)
	{
		now=(GOO_N*)malloc(sizeof(GOO_N));
		if(head==NULL) head=now;
		else prev->node=now;
		now->node=NULL;
		(now->goods).type=type;
		strcpy((now->goods).name,name);
		(now->goods).num=num;
		(now->goods).price=price;
		prev=now;
	}//�����ݶ�������
	fclose(edit);
	now=head;
	puts("��������Ʒ���ƣ�") ;
	gets(name);
	puts("�������޸ĺ����Ʒ����:");
	gets(ename);
	while(1)
	{
		if(strcmp((now->goods).name,name)==0)
		{
			strcpy(now->goods.name,ename);
			puts("�޸ĳɹ�������1�����޸�������Ʒ���ƣ�����2�˳��޸ġ�");
			scanf("%d",&judge);getchar();
			if(judge==2) break;
			if(judge==1)
			{
				now=head;
				puts("��������Ʒ���ƣ�") ;
				gets(name);
				puts("�������޸ĺ����Ʒ���ƣ�");
				gets(ename);
				continue;
			} 
		}
		if(strcmp((now->goods).name,name)!=0)
		{
			now=now->node;
		}
	}
	FILE *output=fopen("orderdata.txt","w");
	now=head;
	GOO_N *judgetotheend=head;//�ж��Ƿ񵽴����һ���ڵ�
	while(judgetotheend!=NULL)
	{
		fprintf(output,"%d ",(now->goods).type);
		fprintf(output,"%s ",(now->goods).name);
		fprintf(output,"%d ",(now->goods).num);
		fprintf(output,"%lf\n",(now->goods).price);
		judgetotheend=judgetotheend->node;
		now=now->node;
	}
	fclose(output);
	now=head;
	while(now!=NULL)
	{
		head=now->node;
		free(now);
		now=head;
	}
	return;
}


void typeedit(void)//�۸��޸�
{
	int choice;
	puts("����1ʹ����Ʒ���Ų�ѯ������2ʹ����Ʒ���Ʋ�ѯ");
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
	int type;//��ѯ�ô���
	int etype;//�޸��ô���
	char name[MAX];
	int num;
	double price;
	int judge;
	FILE *edit=fopen("orderdata.txt","r+");
	GOO_N *head=NULL,*prev,*now;	
	while(fscanf(edit,"%d %s %d %lf",&type,name,&num,&price)!=EOF)
	{
		now=(GOO_N*)malloc(sizeof(GOO_N));
		if(head==NULL) head=now;
		else prev->node=now;
		now->node=NULL;
		(now->goods).type=type;
		strcpy((now->goods).name,name);
		(now->goods).num=num;
		(now->goods).price=price;
		prev=now;
	}//�����ݶ�������
	fclose(edit);
	now=head;
	puts("��������Ʒ���룺") ;
	scanf("%d",&type);getchar();
	puts("�������޸ĺ����Ʒ����:");
	scanf("%d",&etype);getchar();
	while(1)
	{
		if(now->goods.type==type)
		{
			now->goods.type=etype;
			puts("�޸ĳɹ�������1�����޸�������Ʒ���ţ�����2�˳��޸ġ�");
			scanf("%d",&judge);getchar();
			if(judge==2) break;
			if(judge==1)
			{
				now=head;
				puts("��������Ʒ���룺") ;
				scanf("%d",&type);getchar();
				puts("�������޸ĺ����Ʒ����:");
				scanf("%d",&etype);getchar();
				continue;
			} 
		}
		if(now->goods.type!=type)
		{
			now=now->node;
		}
	}
	FILE *output=fopen("orderdata.txt","w");
	now=head;
	GOO_N *judgetotheend=head;//�ж��Ƿ񵽴����һ���ڵ�
	while(judgetotheend!=NULL)
	{
		fprintf(output,"%d ",(now->goods).type);
		fprintf(output,"%s ",(now->goods).name);
		fprintf(output,"%d ",(now->goods).num);
		fprintf(output,"%lf\n",(now->goods).price);
		judgetotheend=judgetotheend->node;
		now=now->node;
	}
	fclose(output);
	now=head;
	while(now!=NULL)
	{
		head=now->node;
		free(now);
		now=head;
	}
	return;
}


void typeeditbyname(void)
{
	int type;
	char name[MAX];//��ѯ������
	int num;
	double price;
	int judge;
	FILE *edit=fopen("orderdata.txt","r+");
	GOO_N *head=NULL,*prev,*now;	
	while(fscanf(edit,"%d %s %d %lf",&type,name,&num,&price)!=EOF)
	{
		now=(GOO_N*)malloc(sizeof(GOO_N));
		if(head==NULL) head=now;
		else prev->node=now;
		now->node=NULL;
		(now->goods).type=type;
		strcpy((now->goods).name,name);
		(now->goods).num=num;
		(now->goods).price=price;
		prev=now;
	}//�����ݶ�������
	fclose(edit);
	now=head;
	puts("��������Ʒ���ƣ�") ;
	gets(name);
	puts("�������޸ĺ����Ʒ����:");
	scanf("%d",&type);getchar();
	while(1)
	{
		if(strcmp((now->goods).name,name)==0)
		{
			now->goods.type=type;
			puts("�޸ĳɹ�������1�����޸�������Ʒ���ţ�����2�˳��޸ġ�");
			scanf("%d",&judge);getchar();
			if(judge==2) break;
			if(judge==1)
			{
				now=head;
				puts("��������Ʒ���ƣ�") ;
				gets(name);
				puts("�������޸ĺ����Ʒ����:");
				scanf("%d",&type);getchar();
				continue;
			} 
		}
		if(strcmp((now->goods).name,name)!=0)
		{
			now=now->node;
		}
	}
	FILE *output=fopen("orderdata.txt","w");
	now=head;
	GOO_N *judgetotheend=head;//�ж��Ƿ񵽴����һ���ڵ�
	while(judgetotheend!=NULL)
	{
		fprintf(output,"%d ",(now->goods).type);
		fprintf(output,"%s ",(now->goods).name);
		fprintf(output,"%d ",(now->goods).num);
		fprintf(output,"%lf\n",(now->goods).price);
		judgetotheend=judgetotheend->node;
		now=now->node;
	}
	fclose(output);
	now=head;
	while(now!=NULL)
	{
		head=now->node;
		free(now);
		now=head;
	}
	return;
}
void priceedit(void)//�۸�༭
{
	int choice;
	puts("����1ʹ����Ʒ���Ų�ѯ������2ʹ����Ʒ���Ʋ�ѯ");
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
	char name[MAX];
	int num;
	double price;
	int judge;
	FILE *edit=fopen("orderdata.txt","r+");
	GOO_N *head=NULL,*prev,*now;	
	while(fscanf(edit,"%d %s %d %lf",&type,name,&num,&price)!=EOF)
	{
		now=(GOO_N*)malloc(sizeof(GOO_N));
		if(head==NULL) head=now;
		else prev->node=now;
		now->node=NULL;
		(now->goods).type=type;
		strcpy((now->goods).name,name);
		(now->goods).num=num;
		(now->goods).price=price;
		prev=now;
	}//�����ݶ�������
	fclose(edit);
	now=head;
	puts("��������Ʒ���룺") ;
	scanf("%d",&type);getchar();
	puts("�������޸ĺ����Ʒ�۸�:");
	scanf("%lf",&price);getchar();
	while(1)
	{
		if(now->goods.type==type)
		{
			(now->goods).price=price;
			puts("�޸ĳɹ�������1�����޸�������Ʒ�۸�����2�˳��޸ġ�");
			scanf("%d",&judge);getchar();
			if(judge==2) break;
			if(judge==1)
			{
				now=head;
				puts("��������Ʒ���룺") ;
				scanf("%d",&type);getchar();
				puts("�������޸ĺ����Ʒ�۸�");
				scanf("%lf",&price);getchar();
				continue;
			} 
		}
		if(now->goods.type!=type)
		{
			now=now->node;
		}
	}
	FILE *output=fopen("orderdata.txt","w");
	now=head;
	GOO_N *judgetotheend=head;//�ж��Ƿ񵽴����һ���ڵ�
	while(judgetotheend!=NULL)
	{
		fprintf(output,"%d ",(now->goods).type);
		fprintf(output,"%s ",(now->goods).name);
		fprintf(output,"%d ",(now->goods).num);
		fprintf(output,"%lf\n",(now->goods).price);
		judgetotheend=judgetotheend->node;
		now=now->node;
	}
	fclose(output);
	now=head;
	while(now!=NULL)
	{
		head=now->node;
		free(now);
		now=head;
	}
	return;
}

void priceeditbyname(void)
{
	int type;
	char name[MAX];
	int num;
	double price;
	int judge;
	FILE *edit=fopen("orderdata.txt","r+");
	GOO_N *head=NULL,*prev,*now;	
	while(fscanf(edit,"%d %s %d %lf",&type,name,&num,&price)!=EOF)
	{
		now=(GOO_N*)malloc(sizeof(GOO_N));
		if(head==NULL) head=now;
		else prev->node=now;
		now->node=NULL;
		(now->goods).type=type;
		strcpy((now->goods).name,name);
		(now->goods).num=num;
		(now->goods).price=price;
		prev=now;
	}//�����ݶ�������
	fclose(edit);	
	now=head;
	puts("��������Ʒ���ƣ�") ;
	gets(name);
	puts("�������޸ĺ����Ʒ�۸�");
	scanf("%lf",&price);getchar();
	while(1)
	{
		if(strcmp((now->goods).name,name)==0)
		{
			(now->goods).price=price;
			puts("�޸ĳɹ�������1�����޸�������Ʒ�۸�����2�˳��޸ġ�");
			scanf("%d",&judge);getchar();
			if(judge==2) break;
			if(judge==1)
			{
				now=head;
				puts("��������Ʒ���ƣ�") ;
				gets(name);
				puts("�������޸ĺ����Ʒ�۸�");
				scanf("%lf",&price);getchar();
				continue;
			} 
		}
		if(strcmp((now->goods).name,name)!=0)
		{
			now=now->node;
		}
	}
	FILE *output=fopen("orderdata.txt","w");
	now=head;
	GOO_N *judgetotheend=head;//�ж��Ƿ񵽴����һ���ڵ�
	while(judgetotheend!=NULL)
	{
		fprintf(output,"%d ",(now->goods).type);
		fprintf(output,"%s ",(now->goods).name);
		fprintf(output,"%d ",(now->goods).num);
		fprintf(output,"%lf\n",(now->goods).price);
		judgetotheend=judgetotheend->node;
		now=now->node;
	}
	fclose(output);
	now=head;
	while(now!=NULL)
	{
		head=now->node;
		free(now);
		now=head;
	}
	return;
}

void pricesearch(void)
{
	double priceleast;//��ͼ۸�
	double pricemost;//��߼۸�
	int type;
	char name[MAX];
	int num;
	double price;
//	int judge;
	FILE *edit=fopen("orderdata.txt","r+");
	GOO_N *head=NULL,*prev,*now;	
	while(fscanf(edit,"%d %s %d %lf",&type,name,&num,&price)!=EOF)
	{
		now=(GOO_N*)malloc(sizeof(GOO_N));
		if(head==NULL) head=now;
		else prev->node=now;
		now->node=NULL;
		(now->goods).type=type;
		strcpy((now->goods).name,name);
		(now->goods).num=num;
		(now->goods).price=price;
		prev=now;
	}//�����ݶ�������
	fclose(edit);	
	now=head;
	puts("��������ͼ۸�");
	scanf("%lf",&priceleast);getchar();
	puts("��������߼۸�");
	scanf("%lf",&pricemost);getchar();
	while(now!=NULL)
	{
		if((now->goods.price>=priceleast)&&(now->goods.price<=pricemost))
		{
			printf("%d %s %d %lf\n",now->goods.type,now->goods.name,now->goods.sold,now->goods.price);
		}
		now=now->node;
	}
	return;
}
