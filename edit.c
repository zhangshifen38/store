#include "edit.h"

GOO_N * edit(void)
{
	GOO_N *now,*head;
	head=inputfromfile();
	puts("���ļ��������ݳɹ���");
	return head;
} 

GOO_N * inputfromfile(void)
{
	FILE *input=fopen("orderdata.txt","r");
	GOO_N *head=NULL,*prev,*now;
//	int type;//¼��ʱ��Ʒ�������ת����
	while(1)
	{
		now=(GOO_N*)malloc(sizeof(GOO_N));
		if(head==NULL) head=now;//����ǵ�һ���ڵ�
		else prev->node=now;
		now->node=NULL;
		if(fscanf(input,"%d %s %d %lf %s %d",&now->goods.type,now->goods.name,&now->goods.num,&now->goods.price,now->goods.time,now->goods.sold)==EOF)
		break;
		prev=now;
	}
	fclose(input);
	return head;	
}
