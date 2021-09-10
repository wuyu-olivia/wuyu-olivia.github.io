#include<stdio.h>
#include<malloc.h>
#include"M_AL_Graph.h"


int main()
{
	MGraph M;   //定义邻接矩阵
	ALGraph G;  //定义图的邻接表类型

	LinkList L;
	initLinkList(&L);

	printf("请输入顶点数和边数\n");
	scanf("%d%d",&M.vexNum,&M.arcNum);

	printf("创建邻接矩阵\n");
	CreateGraph(&M,M.vexNum,M.arcNum,&L);

	printf("创建邻接表\n");
    TurntoALGraph(M,G);

	printf("输出邻接矩阵\n");
	displayMGraph(&M,M.vexNum,M.arcNum);

	printf("输出邻接表\n");
	displayALGraph(&G,M.vexNum);

	TurntoALGraph(M,G);
	printf("广度优先遍历序列为：\n");
	BFS(G);

	printf("\n 深度优先遍历序列为：\n");
	DFSTraverse(G);
	return 0;
}
