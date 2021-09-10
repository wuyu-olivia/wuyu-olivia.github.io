#ifndef _Sqstack_H_
#define _Sqstack_H_
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define INIT_STACK_SIZE 200
#define NUM 8
#define N 200
typedef struct
{
	char *base;
	char *top;
	int stacksize;
}SqStackC;

typedef struct
{
	double *base;
	double *top;
	int stacksize;
}SqStackN;
void initStackN(SqStackN &);//初始化数栈
void initStackC(SqStackC &);//初始化符号栈
void pushN(SqStackN &,double );//数字进栈
void pushC(SqStackC &,char );//符号进栈
void popN(SqStackN &,double &);//数字出栈
void popC(SqStackC &,char &);//符号出栈

#endif