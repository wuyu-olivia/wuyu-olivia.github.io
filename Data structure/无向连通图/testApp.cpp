#include"ͷ�ļ�.h"
#include<stdio.h>

int main(){
	MGraph M;    //�ڽӾ���
	int vex,arc;
	printf("����ߵ�����������ĸ�����");
	scanf("%d%d",&vex,&arc);
	CreateGraph(&M,M.vexnum,M.vexnum);