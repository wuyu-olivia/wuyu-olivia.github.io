#include"M_AL_Graph.h"
int visited[MAXV]={0};

/*******����ķ�㷨************/
void MiniSpTree_PRIM(AMGraph G,VertexType u){//�ӵ�u������������� 
	int i,j;
	int k=u;
	int min;
	c closedge[MAXV]; 
	for(j=0;j<G.vexnum;++j){
		if(j!=k){
			closedge[j].adjvex=u;
			closedge[j].lowcost=G.arcs[k][j];
		}
	}
	closedge[k].lowcost=0;
	printf("\n��С������������£�\n");
	for(i=1;i<G.vexnum;++i){
		min=INF;
		for(j=0;j<G.vexnum;j++){
			if(closedge[j].lowcost!=0&&closedge[j].lowcost<min){
				min=closedge[j].lowcost;
				k=j;
			}
		}
	printf("�ߣ�%d %d��ȨֵΪ:%d\n",closedge[k].adjvex,k,min);
	closedge[k].lowcost=0;
	for(j=0;j<G.vexnum;j++){
		if(G.arcs[k][j]!=0&&G.arcs[k][j]<closedge[j].lowcost){
			closedge[j].lowcost=G.arcs[k][j];
			closedge[j].adjvex=k;
		}
	}
	}
}

void DFS(AMGraph G,int i,int &count){
	int j=0;
	visited[i]=1;
	count++;
	for(j=0;j<G.vexnum;j++){
		if(G.arcs[i][j]!=0 && !visited[j]){
		//i��j�й�ϵ���ڣ�����j����û�б����ʹ�
            DFS(G, j, count);
        }
	}
}

void creat_Mg(AMGraph &G){
	int i, j, k;
	int weight;
    printf("���붥���� ����\n"); //������������
    scanf("%d%d", &G.vexnum, &G.arcnum);
    for(i=0; i<G.vexnum; i++) //��ʼ���ڽӾ���
	{
		G.vexs[i]=i; 
	}
    for(i=0; i<G.vexnum; i++) //��ʼ���ڽӾ���
	{
		for(j=0; j<G.vexnum; j++)
		{
			G.arcs[i][j]=0;
		}
	}
    for(k=0; k<G.arcnum; k++) //����������
    { 
		printf("�����(i, j)\n ");
		scanf("%d%d", &i, &j); //����һ���ߵ����������� i�� j
		printf("����Ȩ��:\n");
		scanf("%d",&weight);
		G.arcs[i][j]=weight;G.arcs[j][i]=weight; //����ͼ���ڽӾ����ǶԳƾ���
	} //������������ G.arcs[i][j]=w�� w ΪȨֵ
}
/******�������ͼ*********/
void out_Mg(AMGraph G){
	int i, j;
    for(i=0; i< G.vexnum; i++) //����ԭ�����
{
    printf("\n");
    for(j=0; j< G.vexnum; j++)
    printf("%5d", G.arcs[i][j]);
}
//��������ڵı�
	printf("\n�������ͼ�ı�Ϊ:\n");
    for(i=0; i< G.vexnum; i++)  //���ߣ�i,j�����ڣ���ֻ������ߣ�i,j����j,i��
{
    for(j=i; j< G.vexnum; j++)
{
    if(G.arcs[i][j]!=0)
    printf("\n ( %d, %d )", i, j);
}
}
    printf("\n");
} 

