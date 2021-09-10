/*************图的邻接矩阵**********/
#define MAXV 20 //最大顶点个数
#define VertexType int
typedef struct
{
int adj; //顶点关系(0 或 1)
InfoType info; //该弧或边的相关信息
} AdjMatrix[MAXV][MAXV];
typedef struct //图的定义
{
AdjMatrix arcs; //邻接矩阵
int vexnum, arcnum; //顶点数,弧数
VertexType vexs[MAXV]; //存放顶点信息
} MGraph;


/**********图的邻接表********/
typedef struct Anode //弧结点类型定义
{
int adjvex; //该弧的弧头
struct ANode *nextarc; //指向另一个弧结点的指针
}ArcNode;
typedef struct VNode //邻接表头结点类型定义
{
VetexType data; //顶点信息
ArcNode *firstarc; //指向第一个依附于该顶点的弧的指针
} AdjList[MAX];		//头结点是一个数组，有多个头结点
typedef struct //图定义
{
AdjList vertices; //邻接表定义
int vexnum, arcnum; //顶点数和弧数
}ALGraph;