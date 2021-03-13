#include <stdio.h>
#include <stdlib.h>
#include "order.h"
char * s_gets

int main() {
	List goods;
	GOO temp;
	initializeorder(&goods);
	puts("输入商品类型:");
	while(gets(temp.type)!=NULL&&temp.type!='\0') {
		puts("输入商品名称:");
		gets(temp.name);
		puts("输入商品数量:");
		scanf("%d",&temp.num);
		while(getchar()!='\n') continue;
		puts("输入商品价格:");
		scanf("%lf",&temp.price);
		while(getchar()!='\n') continue;
		add(temp,&goods);
		puts("请输入下一件商品类型（按空格退出并录入信息）：")
	}
	output(goods);
	delete(&goods);
	puts("录入成功！");
	return 0;
}
