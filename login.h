#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "data.h"

int login();		//��¼ 

void password(char *pwd);	//�������� 

void read_user(USER_N **find,FILE *fp);	//��ȡ�û���Ϣ 

int compare_user(char *name,char *pwd,USER_N *target);	//Ѱ���û� 

void destroy_user(USER_N *fp);			//�����û�����

int repeat_user(char *name,USER_N *target);		//�û����� 

#endif
