#include<stdio.h>
#include<malloc.h>
#include"M_AL_Graph.h"


int main()
{
	MGraph M;   //�����ڽӾ���
	ALGraph G;  //����ͼ���ڽӱ�����

	LinkList L;
	initLinkList(&L);

	printf("�����붥�����ͱ���\n");
	scanf("%d%d",&M.vexNum,&M.arcNum);

	printf("�����ڽӾ���\n");
	CreateGraph(&M,M.vexNum,M.arcNum,&L);

	printf("�����ڽӱ�\n");
    TurntoALGraph(M,G);

	printf("����ڽӾ���\n");
	displayMGraph(&M,M.vexNum,M.arcNum);

	printf("����ڽӱ�\n");
	displayALGraph(&G,M.vexNum);

	TurntoALGraph(M,G);
	printf("������ȱ�������Ϊ��\n");
	BFS(G);

	printf("\n ������ȱ�������Ϊ��\n");
	DFSTraverse(G);
	return 0;
}
