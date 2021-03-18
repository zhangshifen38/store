#include "login.h"

//��¼ģ�� 
int login()
{
	int adm=0;
	FILE *user;
	
	//�����ļ� 
	if( (user=fopen(".//users.txt","r")) == NULL)		 
	{
		printf("δ��⵽�û����ݣ�");
		if( (user=fopen(".//users.txt","w")) == NULL)
		{			
			printf("�����û�����ʧ�ܣ����飡\n");
		}
		else
		{
			printf("���Զ�Ϊ�������û������ļ���\n"); 
		}
	}
	fclose(user);
	
	//�������û� 
	if((user=fopen(".//users.txt","a+"))!=NULL)
	{
		char ch=getc(user);		
		rewind(user);				//����Ƿ���ļ�  
		if(ch==EOF)
		{
			
			puts("δ��⵽�����û����Զ�Ϊ����������Ա�˻���");
			USER new; 
			
			puts("�����������û�����");
			gets(new.name);
			
			puts("�������������룺��������16���ַ���");
			password(new.pwd);
			
			fclose(user);
			user=fopen(".//users.txt","w");
			fprintf(user,"1 %s %s\n",new.name,new.pwd);	//1Ϊ����Ա���� 
			system("cls");
			printf("�ɹ�ע�����Ա�˻���%s��\n",new.name);
		}
	}
	fclose(user);
	
	//�����û� 
	if((user=fopen(".//users.txt","a+")) != NULL)
	{
		do
		{	
			//�����û� 	
			rewind(user);		
			USER_N *find;
			read_user(&find,user);
			
			//ѡ����� 
			puts("��ѡ����Ҫ���еĲ�����");
			puts("1) ��¼\t\t2) ע��");
			int cho;
			scanf("%d",&cho); getchar();
			
			if(cho==1)
			//��¼ϵͳ					
			{
			//�����˺����� 
			USER tmp;
			puts("�����������˺ţ�");
			gets(tmp.name);
			puts("�������������룺");
			password(tmp.pwd);
			
			//���бȶ� 
			adm=compare_user(tmp.name,tmp.pwd,find);
			}
			else
			//ע��ǹ���Ա�û� 
			{
				USER new; 
				while(1)
				{	
					puts("�����������û�����");
					gets(new.name);
					if(repeat_user(new.name,find))
						puts("���û����Ѵ��ڣ����������룡");
					else break; 
				}		
				
				puts("�������������룺��������16���ַ���");
				password(new.pwd);
				
				fseek(user,0L,SEEK_END);		//ĩβ���
				fprintf(user,"2 %s %s\n",new.name,new.pwd);	//2Ϊ��ͨ�ۻ�Ա���� 
				system("cls");
				printf("�ɹ�ע���ۻ�Ա�˻���%s����\n",new.name);
			}
			destroy_user(find);
		}while(adm==0);

	}
	fclose(user);

	putchar('\n');
	
	return adm;
}

//�������� 
void password(char pwd[])
{
	int i=0;		//�������� 
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
	}while(pwd[i-1]!='\r');			//Ϊʲô��windows��cmd�»س�����\r��T_T 
	pwd[i-1]='\0';
	
	putchar('\n');
}

//��ȡ�û�����û������� 
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

//Ѱ���ض����û� 
int compare_user(char name[],char pwd[], USER_N *target)
{
	USER_N *current;
	current=target;
	
	int p=1;			//�жϱ��� 
	while(current!=NULL)
	{	 
		if(!strcmp(name,(current->user).name))
		{	
			if(strcmp(pwd,(current->user).pwd))
			{
				system("cls");
				puts("�������");
				p=0; 
				break;
			}
			else
			{
				system("cls");
				p=(current->user).adm;		//��ȡ�û��ķ���Ȩ�� 
				break;
			}
		}
		else if(current->node==NULL)
		{
			system("cls");
			puts("�Ҳ����û���");
			p=0; 
		}
		current=current->node;
	}
	return p;
} 

//�������� 
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

//�û�����
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


void change_user(USER_N *ptr)
{
	puts("������Ҫ�������û�����");
	char tmp[MAX];
	gets(tmp);
	
	USER_N *current=ptr;
	while(current!=NULL)
	{
		if(!strcmp(tmp,current->user.name))
		{
			int cho=1;
			while(cho)
			{
				puts("��������Ҫ���еĲ�����");
				puts("1) �޸�Ȩ��   2) �޸��û���   3) �޸�����");
				puts("0) �˳�");
				scanf("%d",&cho);getchar();
				if(cho==1)
				{
					if(current->user.adm==1) 
					{
						current->user.adm=2;
						puts("�ɹ��޸�Ȩ��Ϊ���ۻ�Ա����");
					}
					if(current->user.adm==2)
					{
						current->user.adm==1;
						puts("�ɹ��޸�Ȩ��Ϊ������Ա����");
					}
					puts("�´ε�¼��Ч��");
				} 
				else if(cho==2)
				{
					puts("�����������޸ĵ����ƣ�");
					gets(current->user.name);
					puts("�޸ĳɹ���"); 
				}
				else if(cho==3)
				{
					puts("������ԭ���룺");
					
				}
			}
			 
		}
		current=current->node;
	}
	
}


void account(void)
{
	USER_N *acc;
	FILE *fp;
	
	fp=fopen(".//user.txt","r");
	read_user(&acc,fp);
	fclose(fp);
	
	int cho=1;
	while(cho)
	{
		puts("��ѡ����Ҫ���еĲ�����");
		puts("1) �޸��û���Ϣ   2)������˻�");
		puts("0) �˳�"); 
		scanf("%d",&cho);getchar();
	
		switch(cho)
		{
			case 1:
				change_user(acc);
				break;
			case 2:
				
				break;
		}
	}
	
}

