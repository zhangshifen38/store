#include "login.h"

//登录模块 
int login()
{
	int adm=0;
	
	FILE *user;
	if( (user=fopen(".//users.txt","r")) == NULL)		 
	{
		printf("未检测到用户数据！");
		if( (user=fopen(".//users.txt","w")) == NULL)
		{			
			printf("创建用户数据失败，请检查！\n");
		}
		else
		{
			printf("已自动为您初始化用户数据！\n"); 
		}
	}
	fclose(user);
	
	if((user=fopen(".//users.txt","a+"))!=NULL)
	{
		char ch=getc(user);
		rewind(user);
		//新用户创建 
		if(ch==EOF)
		{
			
			puts("未检测到已有用户，自动为您创建管理员账户！");
			USER new; 
			
			puts("请设置您的用户名：");
			gets(new.name);
			
			puts("请设置您的密码：（不超过16个字符）");
			password(new.pwd);
			
			fclose(user);
			user=fopen(".//users.txt","w");
			fprintf(user,"1 %s %s\n",new.name,new.pwd);
		}
	}
	fclose(user);
		//若已有用户 
	user=fopen(".//users.txt","a+");
			do
			{					
				puts("请登录系统！");
				USER_N *find;
				read_user(&find,user);
				
				USER_N *temp=find;
				while(temp!=NULL)
				{
					printf("%d %s %s\n",temp->user.adm,temp->user.name,temp->user.pwd);
					temp=temp->node;
				}
			 
				USER tmp;
				puts("请输入您的账号：");
				gets(tmp.name);
				puts("请输入您的密码：");
				password(tmp.pwd);
			
				adm=compare_user(tmp.name,tmp.pwd,find);
			}while(adm==0);

	putchar('\n');
	
	return adm;
}

//输入密码 
void password(char *pwd)
{
	int i=0;		//计数变量 
	do
	{
	    pwd[i]=getch();
		if(pwd[i]=='\b')
	    {
	       if(i==0)
	        {
	            continue;
	        }
	        pwd[i]='\0';
	        i=i-1;
	        printf("\b");
		}
	    else if(pwd[i]==' '||pwd[i]=='\r')
	    {
			continue;
		}
		else
	    {
            printf("*");
	    }
	}while(pwd[i++]!='\r' && i<16);			//为什么在windows的cmd下回车符是\r啊T_T 
	pwd[i]='\0';
	putchar('\n');
}

//读取用户存进用户链表中 

void read_user(USER_N **find,FILE *fp)
{
	USER_N *head=NULL;
	USER_N *previous,*current;
	while(!feof(fp))
	{
		current=(USER_N*)malloc(sizeof(USER_N));
		if(head==NULL)
		{
			head=current;
		}
		else
		{
			previous->node=current;
		}
		fscanf(fp,"%d %s %s",&current->user.adm,current->user.name,current->user.pwd);
		current->node=NULL;
		previous=current;
	}
	*find=head;
}

//寻找特定的用户 
int compare_user(char *name,char *pwd, USER_N *target)
{
	USER_N *current;
	current=target;
	
	int p=1;			//判断变量 
	while(current!=NULL)
	{
		int cmp_n=strcmp(name,current->user.name);			//比对用户名 
		if(cmp_n==0)
		{
			int cmp_p=strcmp(pwd,current->user.pwd);		//比对密码 
			if(cmp_p!=0)
			{
				puts("密码错误！");
				p=0; 
				break;
			}
			else
			{
				p=current->user.adm;		//获取用户的访问权限 
				break;
			}
		}
		else if(current->node==NULL)
		{
			puts("找不到用户！");
			p=0; 
		}
		current=current->node;
	}
	return p;
} 
