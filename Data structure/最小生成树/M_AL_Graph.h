#include<cstdio>
#include<cstdlib>
#include <queue>
#include <iostream>
#define INF 32767
//MAXV为最大顶点的个数
#define MAXV 100 
using namespace std;
typedef int VertexType; //顶点信息类型
typedef int ArcType; //边信息类型
typedef int VRtype;
/*********图类型定义******/
typedef struct 
{
VertexType vexs[MAXV];    //存放顶点信息， VertexType 是类型名，需事先用 typedef 定义
ArcType arcs[MAXV][MAXV]; //邻接矩阵(顶点间的关系),ArcType 也需事先定义
int vexnum, arcnum;		  //顶点数、边(弧)数
}AMGraph;

typedef struct {
	VertexType adjvex;     //弧头指向的位置
	VRtype lowcost;		  //
}c;

/********最小生成树（普里姆算法）*********/
void MiniSpTree_PRIM(AMGraph G,VertexType u);
void DFS(AMGraph G,int i,int &count); //深度遍历算法用于判断图是否连通
void creat_Mg(AMGraph &G); //创建图
void out_Mg(AMGraph G); //输出图
 