#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "data.h"
#include<stdio.h>
#include<stdlib.h>

void entering(void);

void check_cus(void);

int choose_cus(void);

void create_cus(CUS_N **target);

void change_cus(void);

void print();

void write_cus(CUS_N *point);

#endif
