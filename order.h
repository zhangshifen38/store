#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Goods {
	char type[MAX];		//��Ʒ����
	char name[MAX];		//��Ʒ����
	int num;			//��Ʒ��������
	double price;		//��Ʒ�۸�
	int time;			//����ʱ��
	int sold;			//��Ʒ����
} GOO;
//��Ʒ�ṹ������

typedef struct Goods_Node {
	GOO goods;			//��Ʒ�ṹ������
	struct Goods_Node *next;	//�ṹ��ָ��
} GOO_N;

typedef GOO_N * List;
//��Ʒ������ṹ��

void initializeorder(List *plist);//��ʼ������
void add(GOO goods,List *plist);//������ĩβ�����
void delete(List *plist);//ɾ������