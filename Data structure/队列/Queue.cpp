#include<stdio.h>
#include"Queue.h"
#include <stdlib.h>

Status InitQueue(LinkQueue &Q){
	Q.base=(QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
	if(!Q.front)
		exit(OVERFLOW);
	Q.front=Q.rear=0;
	return 0;

}
Status EnQueue(LinkQueue &Q,QElemType e){
	if((Q.rear+1)%MAXQSIZE==Q.front)
		return 1;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXQSIZE;
	return 0;
}
Status DeQueue(LinkQueue &Q,QElemType &e){
	if(Q.front==Q.rear)
		return 1;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXQSIZE;
	return 0;
}
Status Output(LinkQueue &Q){
	int length;
	length=(Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
	for(int i=0;i<length;i++)
		printf("%d",Q.base[i]);
	return 0;
}
	


