/*************ͼ���ڽӾ���**********/
#define MAXV 20 //��󶥵����
#define VertexType int
typedef struct
{
int adj; //�����ϵ(0 �� 1)
InfoType info; //�û���ߵ������Ϣ
} AdjMatrix[MAXV][MAXV];
typedef struct //ͼ�Ķ���
{
AdjMatrix arcs; //�ڽӾ���
int vexnum, arcnum; //������,����
VertexType vexs[MAXV]; //��Ŷ�����Ϣ
} MGraph;


/**********ͼ���ڽӱ�********/
typedef struct Anode //��������Ͷ���
{
int adjvex; //�û��Ļ�ͷ
struct ANode *nextarc; //ָ����һ��������ָ��
}ArcNode;
typedef struct VNode //�ڽӱ�ͷ������Ͷ���
{
VetexType data; //������Ϣ
ArcNode *firstarc; //ָ���һ�������ڸö���Ļ���ָ��
} AdjList[MAX];		//ͷ�����һ�����飬�ж��ͷ���
typedef struct //ͼ����
{
AdjList vertices; //�ڽӱ���
int vexnum, arcnum; //�������ͻ���
}ALGraph;