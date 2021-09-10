#include<stdio.h>
#include"Queue.h"
int main(){
	int k,e;
	LinkQueue q;
printf("\n\n=================================");
printf("\n 1. 初始化队列" );//
printf("\n 2. 入队");//
printf("\n 3. 出队");//
printf("\n 4. 输出队列元素");//
printf("\n 5. 结束！");
do
{
printf("\n 请选择(1-4): ");
scanf("%d", &k);
switch(k)
{
case 1: InitQueue(q); break;
case 2:
	printf("请输入入队元素");
	scanf("%d",&e);
	EnQueue(q,e);
	break;
case 3: 
	DeQueue(q,e);
	break;
case 4: Output(q);break;
}
}while(k!=5);
printf("\n 再见！\n");
return 0;
}//main
