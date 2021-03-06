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

void destroy_user(USER_N *fp);			//销毁用户链表

int repeat_user(char *name,USER_N *target);		//用户查重

void account(void);		//用户管理

void change_user(USER_N *ptr);		//修改用户权限 

void write_user(USER_N *target,FILE *fp);	//写入文件 

void add_user(USER_N *target);		//添加用户 

#endif
