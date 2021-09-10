#include "Sqstack.h"
#include"other.h"
//����������������ջ����������������������������������
void initStackN(SqStackN &S)//��ʼ����ջ 
{
	S.base = (double*)malloc(INIT_STACK_SIZE*sizeof(double));	
	S.top = S.base ;
	S.stacksize = INIT_STACK_SIZE;
}
void pushN(SqStackN &S,double x)//���ֽ�ջ
{
	if(S.base-S.top>=S.stacksize)
		return ;
	*(S.top++)=x;
}
void popN(SqStackN &S,double &x)//���ֳ�ջ
{
	if(S.top==S.base)
		return ;
	x = *(--S.top);
}
void initStackC(SqStackC &S)//��ʼ������ջ
{
	S.base = (char*)malloc(INIT_STACK_SIZE*sizeof(char));	
	S.top = S.base ;
	S.stacksize = INIT_STACK_SIZE;
}
void pushC(SqStackC &S,char x)//���Ž�ջ
{
	if(S.base-S.top>=S.stacksize)
		return ;
	*(S.top++)=x;
}
void popC(SqStackC &S,char &x)//���ų�ջ
{
	if(S.top==S.base)
		return ;
	x = *(--S.top);
}


