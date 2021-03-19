#ifndef DATAEDIT_H
#define DATAEDIT_H

#include "data.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void edit1(void);
void priceedit(void);
void priceeditbytype(void);
void priceeditbyname(void);
void nameedit(void);
void nameeditbytype(void);
void nameeditbyname(void);
void typeedit(void);
void typeeditbytype(void);
void typeeditbyname(void);
void pricesearch(void);
GOO_N * readdata(void);
void delete (GOO_N *now);
void rprint(GOO_N *head);



#endif