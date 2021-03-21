#include<stdio.h>
#include<stdlib.h>
#include "data.h"
#include "order.h"
#include<string.h>


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
		fprintf(w,"%lf ",(p->goods).price);
		fprintf(w,"%s ",(p->goods).time);
		fprintf(w,"%d\n",p->goods.sold);
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
			timeinput(now->goods.time);
			now->goods.sold=0;
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

void timeinput(char time1[])
{
	time_t cur;
	struct tm *tm_cur;//ʱ��ǰ������
	char year[MAX],month[MAX],day[MAX],hour[MAX],min[MAX],sec[MAX];//������Сʱ��������ʱ�ַ���
	char mid[MAX];//��ת����
	time(&cur) ;
			tm_cur = localtime(&cur);//��ȡʱ��
			itoa(tm_cur->tm_year+1900,year,10);
			itoa(tm_cur->tm_mon+1,month,10);
			itoa(tm_cur->tm_mday,day,10);
			itoa(tm_cur->tm_hour,hour,10);
			itoa(tm_cur->tm_min,min,10);
			itoa(tm_cur->tm_sec,sec,10);//��ʱ�������ʱ����
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

