#include <stdio.h>
#include <stdlib.h>
#include "order.h"
char * s_gets

int main() {
	List goods;
	GOO temp;
	initializeorder(&goods);
	puts("������Ʒ����:");
	while(gets(temp.type)!=NULL&&temp.type!='\0') {
		puts("������Ʒ����:");
		gets(temp.name);
		puts("������Ʒ����:");
		scanf("%d",&temp.num);
		while(getchar()!='\n') continue;
		puts("������Ʒ�۸�:");
		scanf("%lf",&temp.price);
		while(getchar()!='\n') continue;
		add(temp,&goods);
		puts("��������һ����Ʒ���ͣ����ո��˳���¼����Ϣ����")
	}
	output(goods);
	delete(&goods);
	puts("¼��ɹ���");
	return 0;
}
