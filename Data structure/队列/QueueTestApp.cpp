#include<stdio.h>
#include"Queue.h"
int main(){
	int k,e;
	LinkQueue q;
printf("\n\n=================================");
printf("\n 1. ��ʼ������" );//
printf("\n 2. ���");//
printf("\n 3. ����");//
printf("\n 4. �������Ԫ��");//
printf("\n 5. ������");
do
{
printf("\n ��ѡ��(1-4): ");
scanf("%d", &k);
switch(k)
{
case 1: InitQueue(q); break;
case 2:
	printf("���������Ԫ��");
	scanf("%d",&e);
	EnQueue(q,e);
	break;
case 3: 
	DeQueue(q,e);
	break;
case 4: Output(q);break;
}
}while(k!=5);
printf("\n �ټ���\n");
return 0;
}//main
