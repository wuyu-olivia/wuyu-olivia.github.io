#include "Sqstack.h"
#include "other.h"
//——————————表达式求值操作函数————————————
 char priorSet[NUM]={'+','-','*','/','(',')','#','^'};
 char prior[NUM][NUM]={
	'>','>','<','<','<','>','>','<',
	'>','>','<','<','<','>','>','<',
	'>','>','>','>','<','>','>','<',
	'>','>','>','>','<','>','>','<',
	'<','<','<','<','<','=',' ','<',
	'>','>','>','>',' ','>','>','>',
	'<','<','<','<','<',' ','=','<',
	'>','>','>','>','<','>','>','>'};
int findInSet(char c)
{
	int i;
	for(i=0;i<NUM;i++)
	{
		if(priorSet[i]==c)
			return i;
	}
	return -1;
}

char compare(char optrtop,char c)
{
	int i,j;
	i = findInSet(optrtop);
	j = findInSet(c);
	if(i==-1||j==-1)
	{
		printf("不支持的该符号类型\n");
		exit(0);
	}
	else
		return prior[i][j];
}
double calculate(double a,char operation,double b)
{
	switch(operation)
	{
		case '+':
			return a+b;
		case '-':
			return b-a;
		case '*':
			return a*b;
		case '/':
			return b/a;
		case '^':
			return pow(b,a);
		default:
			return 0;
	}
}
void Calculation()
{
	char operation;
	char temp[N];
	int i=0,j=-1,begin=0;
	double sum,a,b,n;
	SqStackC OPTR;
	SqStackN OPND;
	initStackC(OPTR);
	initStackN(OPND);
	pushC(OPTR,'#');

	printf("请输入表达式以 # 结束\n");
	gets(temp);

	while(temp[i]!='#'||*(OPTR.top-1)!='#')
	{

		if(temp[i]>='0' && temp[i]<='9')
		{
			n=0;
			while(temp[i]>='0' && temp[i]<='9' || temp[i]=='.')
			{
				if(temp[i]=='.')
					begin=1;
				else 
					n = n*10 + temp[i]-'0';
				if(begin!=0)
					j++;
				i++;
			}
			if(j!=-1)
				n = n/pow(10,j);
			pushN(OPND,n);
			j = -1;
			begin=0;
		}
		else
		{
			switch(compare(*(OPTR.top-1),temp[i]))
			{
			case '>': popC(OPTR,operation);
					  popN(OPND,a);
					  popN(OPND,b);
					  sum = calculate(a,operation,b);
					  pushN(OPND,sum);
					  break;
			case '<': pushC(OPTR,temp[i]);
					  i++;
					  break;
			case '=': popC(OPTR,operation);
					  i++;
					  break;
			}
		}
	}
	printf("表达式的计算结果为：%.2f\n",*(OPND.top-1));
	printf("\n");
}
