#include "edit.h"

void edit(void)
{
	GOO_N *now,*head;
	head=inputfromfile();
	puts("���ļ��������ݳɹ���");
	now=head;
	while(now->node!=NULL)
	{
		printf("%d %s %d %lf %s\n",now->goods.type,now->goods.name,now->goods.num,now->goods.price,now->goods.time);
		now=now->node;
	}
	return;
} 

GOO_N * inputfromfile(void)
{
	FILE *input=fopen("orderdata.txt","r");
	GOO_N *head=NULL,*prev,*now;
	int type;//¼��ʱ��Ʒ�������ת����
	while(1)
	{
		now=(GOO_N*)malloc(sizeof(GOO_N));
		if(head==NULL) head=now;//����ǵ�һ���ڵ�
		else prev->node=now;
		now->node=NULL;
		if(fscanf(input,"%d %s %d %lf %s",&now->goods.type,now->goods.name,&now->goods.num,&now->goods.price,now->goods.time)==EOF)
		break;
		prev=now;
	}
	fclose(input);
	return head;	
}