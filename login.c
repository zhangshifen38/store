#include "login.h"

//登录模块 
int login()
{
	int adm=0;
	FILE *user;
	
	//检测空文件 
	if( (user=fopen(".//users.txt","r")) == NULL)		 
	{
		printf("未检测到用户数据！");
		if( (user=fopen(".//users.txt","w")) == NULL)
		{			
			printf("创建用户数据失败，请检查！\n");
		}
		else
		{
			printf("已自动为您生成用户数据文件！\n"); 
		}
	}
	fclose(user);
	
	//创建新用户 
	if((user=fopen(".//users.txt","a+"))!=NULL)
	{
		char ch=getc(user);		
		rewind(user);				//检测是否空文件  
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
			fprintf(user,"1 %s %s\n",new.name,new.pwd);	//1为管理员代号 
			system("cls");
			printf("成功注册管理员账户“%s”\n",new.name);
		}
	}
	fclose(user);
	
	//已有用户 
	if((user=fopen(".//users.txt","a+")) != NULL)
	{
		do
		{	
			//读入用户 	
			rewind(user);		
			USER_N *find;
			read_user(&find,user);
			
			//选择操作 
			puts("请选择您要进行的操作：");
			puts("1) 登录\t\t2) 注册");
			int cho;
			scanf("%d",&cho); getchar();
			
			if(cho==1)
			//登录系统					
			{
			//读入账号密码 
			USER tmp;
			puts("请输入您的账号：");
			gets(tmp.name);
			puts("请输入您的密码：");
			password(tmp.pwd);
			
			//进行比对 
			adm=compare_user(tmp.name,tmp.pwd,find);
			}
			else
			//注册非管理员用户 
			{
				USER new; 
				while(1)
				{	
					puts("请设置您的用户名：");
					gets(new.name);
					if(repeat_user(new.name,find))
						puts("该用户名已存在，请重新输入！");
					else break; 
				}		
				
				puts("请设置您的密码：（不超过16个字符）");
				password(new.pwd);
				
				fseek(user,0L,SEEK_END);		//末尾添加
				fprintf(user,"2 %s %s\n",new.name,new.pwd);	//2为普通售货员代号 
				system("cls");
				printf("成功注册售货员账户“%s”！\n",new.name);
			}
			destroy_user(find);
		}while(adm==0);

	}
	fclose(user);

	putchar('\n');
	
	return adm;
}

//输入密码 
void password(char pwd[])
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
	        putchar('\b');
		}
	    else if(pwd[i]==' '||i==16)
	    {
			continue;
		}
		else if(pwd[i]=='\r')
		{
			if(i==0) pwd[i]='\0';
			else ++i;
		}
		else
	    {
            printf("*");
            ++i;
	    }
	}while(pwd[i-1]!='\r');			//为什么在windows的cmd下回车符是\r啊T_T 
	pwd[i-1]='\0';
	
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
		fscanf(fp,"%d %s %s",&(current->user).adm,(current->user).name,(current->user).pwd);
		current->node=NULL;
		previous=current;
	}
	*find=head;
}

//寻找特定的用户 
int compare_user(char name[],char pwd[], USER_N *target)
{
	USER_N *current;
	current=target;
	
	int p=1;			//判断变量 
	while(current!=NULL)
	{	 
		if(!strcmp(name,(current->user).name))
		{	
			if(strcmp(pwd,(current->user).pwd))
			{
				system("cls");
				puts("密码错误！");
				p=0; 
				break;
			}
			else
			{
				system("cls");
				p=(current->user).adm;		//获取用户的访问权限 
				break;
			}
		}
		else if(current->node==NULL)
		{
			system("cls");
			puts("找不到用户！");
			p=0; 
		}
		current=current->node;
	}
	return p;
} 

//销毁链表 
void destroy_user(USER_N *user)
{
	USER_N *current=user;
	
	while(current!=NULL)
	{
		user=current->node;
		free(current);
		current=user;
	}
}

//用户查重
int repeat_user(char name[],USER_N *target)
{
	USER_N *current=target;
	while(current!=NULL)
	{
		if(!strcmp(name,current->user.name))
			return 1;
		current=current->node;
	}
	return 0;
} 
