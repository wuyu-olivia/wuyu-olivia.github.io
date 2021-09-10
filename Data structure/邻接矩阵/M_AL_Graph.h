#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define VNUM 30
#define max 30
#define MAXV 20
typedef int QElemType;
//�����ڽӾ���
typedef struct
{
	int vexs[VNUM];   //��Ŷ�����Ϣ
	int arcs[VNUM][VNUM];   //�ڽӾ��󣨶���֮��Ĺ�ϵ��
	int vexNum,arcNum;    //���������ߣ�������
}MGraph;


//�����ڽӱ�߽��
typedef struct ANode
{
	int adjvex;  //�ڽӵ��������е�λ���±�
	struct ANode * nextArc; //ָ����һ���ڽӵ��ָ��
}ArcNode;


//�����ڽӱ��ͷ���
typedef struct 
{
	int data;
	ArcNode *FirstArc;
}AdjList[MAXV];


//����ͼ���ڽӱ�����
typedef struct
{
	AdjList vertices;   //�洢������ͷ�������飨�Ǳ�ͷ������ͣ�
	int vexnum,arcnum;
}ALGraph;

//���嵥������
typedef struct Lnode
{
	int data;
	struct Lnode *next;
}Lnode,*LinkList;
typedef struct QNode
{
    QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct{
	QueuePtr front;//��ͷָ��
	QueuePtr rear;//��βָ��
}LinkQueue;

void CreateGraph(MGraph *G,int v,int a,LinkList *L);

int initLinkList(LinkList *L);
void displayALGraph(ALGraph *G,int n);
void displayMGraph(MGraph *G,int v,int a);
void DFSTraverse(ALGraph G);//������ȱ���
void DFS(ALGraph G,int i);
void BFS(ALGraph G);//������ȱ���
int FirstAdjVex(ALGraph G,int u);
int NextAdjVex(ALGraph G,int u,int w);
LinkQueue InitQueue();
void DestroyQueue(LinkQueue &Q);
int EnQueue(LinkQueue &Q,QElemType e);
int DeQueue(LinkQueue &Q,QElemType &e);
int QueueEmpty(LinkQueue Q);
void CreateAdjlist(ALGraph *G,int v,MGraph *M);
void TurntoALGraph(MGraph G1,ALGraph &G2);
