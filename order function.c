#include <stdio.h>
#include <stdlib.h>
#include "order.h"

static void input(GOO goods,GOO_N *gnode);
void initializeorder(List *plist) {
	plist=NULL;
}

void add(GOO goods,List *plist) {
	GOO_N *pnew;
	GOO_N *scan=*plist;
	pnew=(GOO_N *)malloc(sizeof(GOO_N));
	input(goods,pnew);
	pnew->node==NULL;
	if(scan==NULL) *plist =pnew;//链表为空，把pnew放在开头
	else {
		while(scan->next !=NULL)
			scan=scan->next;
		scan->next=pnew;
	}
}

void delete(List *plist) {
	GOO_N *psave;
	while(*plist!=NULL) {
		psave =(*plist)->next;
		free(*plist);
		*plist=psave;
	}
}

void output(List *plist) {
	GOO_N *goods=(*plist).next;
	FILE *w=fopen("orderdata.txt","w");
	while(goods) {
		fprintf(w,"%s\n",goods->goods.type);
		fprintf(w,"%s\n",goods->goods.name);
		fprintf(w,"%d\n",goods->goods.num);
		fprintf(w,"%lf\n",goods->goods.price);
		goods=goods.next;
		printf("\n");
		fprintf(w,"\n");
		fclose(w);
		return;
	}
}

static void input(GOO goods,GOO_N *gnode) {
	gnode->goods=goods;
}