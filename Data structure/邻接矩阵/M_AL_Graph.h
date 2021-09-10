#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define VNUM 30
#define max 30
#define MAXV 20
typedef int QElemType;
//定义邻接矩阵
typedef struct
{
	int vexs[VNUM];   //存放顶点信息
	int arcs[VNUM][VNUM];   //邻接矩阵（顶点之间的关系）
	int vexNum,arcNum;    //顶点数、边（弧）数
}MGraph;


//定义邻接表边结点
typedef struct ANode
{
	int adjvex;  //邻接点在数组中的位置下标
	struct ANode * nextArc; //指向下一个邻接点的指针
}ArcNode;


//定义邻接表表头结点
typedef struct 
{
	int data;
	ArcNode *FirstArc;
}AdjList[MAXV];


//定义图的邻接表类型
typedef struct
{
	AdjList vertices;   //存储各链表头结点的数组（是表头结点类型）
	int vexnum,arcnum;
}ALGraph;

//定义单链表结点
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
	QueuePtr front;//队头指针
	QueuePtr rear;//队尾指针
}LinkQueue;

void CreateGraph(MGraph *G,int v,int a,LinkList *L);

int initLinkList(LinkList *L);
void displayALGraph(ALGraph *G,int n);
void displayMGraph(MGraph *G,int v,int a);
void DFSTraverse(ALGraph G);//深度优先遍历
void DFS(ALGraph G,int i);
void BFS(ALGraph G);//广度优先遍历
int FirstAdjVex(ALGraph G,int u);
int NextAdjVex(ALGraph G,int u,int w);
LinkQueue InitQueue();
void DestroyQueue(LinkQueue &Q);
int EnQueue(LinkQueue &Q,QElemType e);
int DeQueue(LinkQueue &Q,QElemType &e);
int QueueEmpty(LinkQueue Q);
void CreateAdjlist(ALGraph *G,int v,MGraph *M);
void TurntoALGraph(MGraph G1,ALGraph &G2);
