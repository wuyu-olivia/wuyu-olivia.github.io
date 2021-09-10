#include "Sqstack.h"
#include"other.h"
//————————栈的声明操作函数——————————
void initStackN(SqStackN &S)//初始化数栈 
{
	S.base = (double*)malloc(INIT_STACK_SIZE*sizeof(double));	
	S.top = S.base ;
	S.stacksize = INIT_STACK_SIZE;
}
void pushN(SqStackN &S,double x)//数字进栈
{
	if(S.base-S.top>=S.stacksize)
		return ;
	*(S.top++)=x;
}
void popN(SqStackN &S,double &x)//数字出栈
{
	if(S.top==S.base)
		return ;
	x = *(--S.top);
}
void initStackC(SqStackC &S)//初始化符号栈
{
	S.base = (char*)malloc(INIT_STACK_SIZE*sizeof(char));	
	S.top = S.base ;
	S.stacksize = INIT_STACK_SIZE;
}
void pushC(SqStackC &S,char x)//符号进栈
{
	if(S.base-S.top>=S.stacksize)
		return ;
	*(S.top++)=x;
}
void popC(SqStackC &S,char &x)//符号出栈
{
	if(S.top==S.base)
		return ;
	x = *(--S.top);
}


