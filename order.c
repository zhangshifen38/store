#include<stdio.h>
#include<stdlib.h>
#include "data.h"
#include "order.h"

void output(GOO_N *head)//������������ļ�
{
	GOO_N *p=head;
	FILE *w=fopen("orderdata.txt","a+");
	if(w==NULL)
	{
		printf("�򿪽����������ĵ�ʧ�ܣ�\n");
		return;
	}
	fseek(w,0,SEEK_END);
	while(p)
	{
		
		fprintf(w,"%d ",(p->goods).type);
		fprintf(w,"%s ",(p->goods).name);
		fprintf(w,"%d ",(p->goods).num);
		fprintf(w,"%lf\n",(p->goods).price);
		p=p->node;
	}
	fclose(w);
	puts("����������¼��ɹ���");
	return;
}

void order(void)//���������ݽ��ա�¼�롢�����ɾ��
{
	int judge;
	GOO_N *head=NULL;//�������ڵ�ͷָ��
	GOO_N *prev,*now;//��������һ�ڵ㣬��ǰ�ڵ�
	int type;//¼��ʱ��Ʒ�������ת����
	puts("��������Ʒ���룺");
	while(scanf("%d",&type)!=EOF)
		{
			while(getchar()!='\n')
				continue;
			now=(GOO_N*)malloc(sizeof(GOO_N));
			if(head==NULL) head=now;//����ǵ�һ���ڵ�
			else prev->node=now;
			now->node=NULL;
			(now->goods).type=type;
			puts("��������Ʒ���ƣ�");
			gets((now->goods).name);
			puts("��������Ʒ��������:");
			scanf("%d",&((now->goods).num));
			while(getchar()!='\n')
				continue;
			puts("��������Ʒ�۸�");
			scanf("%lf",&(now->goods).price);
			while(getchar()!='\n')
				continue;
			puts("��������һ����Ʒ����(ctrl+zֹͣ¼��)��");
			prev=now;
		}
		puts("����1�˳�¼��ģʽ������0¼�����ݲ��˳�¼��ģʽ");
		scanf("%d",&judge);
		while(getchar()!='\n')
				continue;
		if(judge==1) return;
		if(judge==0)
		{
			output(head);
			now=head;//����ɾ��
			while(now!=NULL)
			{
				head=now->node;
				free(now);
				now=head;
			}
		}
}