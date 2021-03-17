#ifndef DATA_H
#define DATA_H

#define ENTER putchar('\n');
#define MAX 200

typedef struct User{
	int adm;			//�û���ʶ��
	char name[MAX];		//�û��� 
	char pwd[17];		//���� 
}USER;
//�û��ṹ��

typedef struct User_Node{
	USER user;			//�û��ṹ������ 
	struct User_Node *node;	//�ṹ��ָ�� 
}USER_N; 

typedef struct Goods{
	int type;			//��Ʒ���� 
	char name[MAX];		//��Ʒ���� 
	int num;			//��Ʒ�������� 
	double price;		//��Ʒ�۸�
	int time;			//����ʱ��
	int sold;			//��Ʒ���� 
}GOO;
//��Ʒ�ṹ�� 

typedef struct Goods_Node{
	GOO goods;			//��Ʒ�ṹ������ 
	struct Goods_Node *node;	//�ṹ��ָ�� 
}GOO_N;
//��Ʒ������ṹ�� 

typedef struct Customer{
	char name[MAX];		//�˿����� 
	int star;			//�˿��Ǽ� 
	double cost;		//���Ѷ� 
}CUS;
//�˿���Ϣ�ṹ�� 

typedef struct Customer_Node{
	CUS customer;		//�˿ͽṹ������ 
	struct Customer_Node *node;//�ṹ��ָ�� 
}CUS_N;
//�˿���Ϣ������ṹ�� 

#endif
