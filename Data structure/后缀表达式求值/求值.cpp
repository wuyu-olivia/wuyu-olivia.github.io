#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
#define MAXBUFFER 10
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef int Status;
typedef double ElemType;
typedef struct
{
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;
Status InitStack(sqStack *s)
{
	s->base=(ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!s->base)
		exit(0);
	s->top=s->base;
	s->stackSize=STACK_INIT_SIZE;
    return 0;
}
Status Push(sqStack *s,ElemType e){
	if(s->top-s->base>=s->stackSize){
	s->base=(ElemType *)realloc(s->base,(s->stackSize+STACKINCREMENT)*sizeof(ElemType));
	if(!s->base)
		exit(0);
	s->top=s->base+s->stackSize;
	s->stackSize=s->stackSize+STACKINCREMENT;
	}
	*s->top++=e;
	return 0;
}
Status Pop(sqStack *s,ElemType *e){
	if(s->top==s->base)
		return 0;
	*e=*--(s->top);
	return 0;
}
int StackLen(sqStack s){
	return (s.top-s.base);
}
int main(){
	sqStack s;
	char c;
	double d,e;
	int i=0; 
	char str[MAXBUFFER];
	InitStack(&s);
	printf("输入后缀表达式，以#结束\n");
	scanf("%c",&c);
	while(c!='#')
	{
		while(isdigit(c)||c=='.')  //过滤数字
		{
			str[i++]=c;
			str[i]='\0';
			if(i>=10){
				printf("出错：数据过大");
				return -1;
			}
			scanf("%c",&c);
			if(c==' '){
				d=atof(str);
				Push(&s,d);
				i=0;
				break;
			}
		}
		switch(c){
		case '+': 
			Pop(&s,&e);
			Pop(&s,&d);
			Push(&s,d+e);
			break;
		case'-':
			Pop(&s,&e);
			Pop(&s,&d);
			Push(&s,d-e);
			break;
		case'*':
			Pop(&s,&e);
			Pop(&s,&d);
			Push(&s,d*e);
			break;
		case'/':
			Pop(&s,&e);
			Pop(&s,&d);
			if(e!=0)
			Push(&s,d/e);
			else
			{
				printf("出错！\n");
				return -1;
			}
			break;
		}
		scanf("%c",&c);
	}
	Pop(&s,&d);
	printf("最终计算结果为：%.2f\n",d);
	return 0;
}
