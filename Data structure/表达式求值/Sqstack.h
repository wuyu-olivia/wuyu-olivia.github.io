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
void initStackN(SqStackN &);//��ʼ����ջ
void initStackC(SqStackC &);//��ʼ������ջ
void pushN(SqStackN &,double );//���ֽ�ջ
void pushC(SqStackC &,char );//���Ž�ջ
void popN(SqStackN &,double &);//���ֳ�ջ
void popC(SqStackC &,char &);//���ų�ջ

#endif