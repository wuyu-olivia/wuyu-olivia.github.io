#include<cstdio>
#include<cstdlib>
#include <queue>
#include <iostream>
#define INF 32767
//MAXVΪ��󶥵�ĸ���
#define MAXV 100 
using namespace std;
typedef int VertexType; //������Ϣ����
typedef int ArcType; //����Ϣ����
typedef int VRtype;
/*********ͼ���Ͷ���******/
typedef struct 
{
VertexType vexs[MAXV];    //��Ŷ�����Ϣ�� VertexType ������������������ typedef ����
ArcType arcs[MAXV][MAXV]; //�ڽӾ���(�����Ĺ�ϵ),ArcType Ҳ�����ȶ���
int vexnum, arcnum;		  //����������(��)��
}AMGraph;

typedef struct {
	VertexType adjvex;     //��ͷָ���λ��
	VRtype lowcost;		  //
}c;

/********��С������������ķ�㷨��*********/
void MiniSpTree_PRIM(AMGraph G,VertexType u);
void DFS(AMGraph G,int i,int &count); //��ȱ����㷨�����ж�ͼ�Ƿ���ͨ
void creat_Mg(AMGraph &G); //����ͼ
void out_Mg(AMGraph G); //���ͼ
 