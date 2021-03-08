#include <stdio.h>

void n_read(int n,int *sc) {
	printf("请输入一个不大于%d位的整数\n",n);
	scanf("%d",sc);/*读入一个整数*/
	int n1=0;/*n1为实际位数*/
	while(*sc!=0) {
		*sc=*sc%10;
		n1++;
		if(n1>n) {
			printf("位数大于%d位，请重新输入\n",n);
			scanf("%d",sc);
			n1=0;
		}
	}
}

void s_read(int n,char a[]) {
	printf("请输入长度不大于%d位的字符串\n",n);
	for(int i=0; i<n; i++) {
		scanf("%c",&a[i]);
		i++;
		if(i==n||i>n) {
			printf("位数大于%d位，请重新输入\n",n);
			i=0;
		}
	}

}

void d_read(int n,float *sc) {
	printf("请输入一个整数部分不大于%d位的浮点数\n",n);
	scanf("%f",sc);
	int sc1=(int)*sc;/*截取读入的数的整数部分*/
	int n1=0;/*n1为实际位数*/
	while(sc1!=0) {
		sc1=sc1%10;
		n1++;
		if(n1>n) {
			printf("整数位数大于%d位，请重新输入\n",n);
			scanf("%f",sc);
			n1=0;
		}
	}

}
