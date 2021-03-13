#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "data.h"

int login();		//登录 

void password(char *pwd);	//输入密码 

void read_user(USER_N **find,FILE *fp);	//读取用户信息 

int compare_user(char *name,char *pwd,USER_N *target);	//寻找用户 

#endif
