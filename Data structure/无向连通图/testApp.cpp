#include"头文件.h"
#include<stdio.h>

int main(){
	MGraph M;    //邻接矩阵
	int vex,arc;
	printf("输入边的总数、顶点的个数：");
	scanf("%d%d",&vex,&arc);
	CreateGraph(&M,M.vexnum,M.vexnum);