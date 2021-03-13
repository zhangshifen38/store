#include "login.h"

//登录模块 
int login()
{
	int adm;
	
	FILE *user;
	if(user=fopen(".//users.txt","r")==NULL)		 
	{
			printf("未检测到用户数据！");
		if(user=fopen(".//users.txt","w")==NULL)
		{			
			printf("创建用户数据失败，请检查！\n");
		}
		else
		{
			printf("已自动为您初始化用户数据！\n"); 
		}
	}
	else
	{
		char ch=getc(user);
		USER new;
		if(ch==EOF)
		{
			puts("未检测到已有用户，自动为您创建管理员账户！");
			puts("请设置您的用户名：");
			gets(new.name);
			puts("请设置您的密码：（不超过16个字符）");
			int i=0;		//计数变量 
			do
			{
			    new.pwd[i]=getch();
				if(new.pwd[i]=='\b')
			    {
			        if(i==0)
			        {
			            continue;
			        }
			        i=i-1;
			        printf("\b");
				}
			    else
			    {
		            printf("*");
		        }
			}while(new.pwd[i++]!='\r' && new.pwd[i]!='\n' && i<16);			//为什么在windows的cmd下回车符是\r啊T_T 
			fclose(user);
			user=fopen(".//users.txt","w");
			fprintf(user,"1 %s %s\n",new.name,new.pwd);
			fclose(user);
		}
		else
		{
			;
		}	
	}

	putchar('\n');
	adm=1;
	return adm;
}
