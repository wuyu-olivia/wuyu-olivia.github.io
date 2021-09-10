#include"M_AL_Graph.h"
int visited[MAXV]={0};

/*******普利姆算法************/
void MiniSpTree_PRIM(AMGraph G,VertexType u){//从第u个顶点出发构建 
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
	printf("\n最小生成树组成如下：\n");
	for(i=1;i<G.vexnum;++i){
		min=INF;
		for(j=0;j<G.vexnum;j++){
			if(closedge[j].lowcost!=0&&closedge[j].lowcost<min){
				min=closedge[j].lowcost;
				k=j;
			}
		}
	printf("边（%d %d）权值为:%d\n",closedge[k].adjvex,k,min);
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
		//i和j有关系相邻，并且j顶点没有被访问过
            DFS(G, j, count);
        }
	}
}

void creat_Mg(AMGraph &G){
	int i, j, k;
	int weight;
    printf("输入顶点数 边数\n"); //顶点数、边数
    scanf("%d%d", &G.vexnum, &G.arcnum);
    for(i=0; i<G.vexnum; i++) //初始化邻接矩阵
	{
		G.vexs[i]=i; 
	}
    for(i=0; i<G.vexnum; i++) //初始化邻接矩阵
	{
		for(j=0; j<G.vexnum; j++)
		{
			G.arcs[i][j]=0;
		}
	}
    for(k=0; k<G.arcnum; k++) //创建各条边
    { 
		printf("输入边(i, j)\n ");
		scanf("%d%d", &i, &j); //输入一条边的两个顶点编号 i， j
		printf("输入权重:\n");
		scanf("%d",&weight);
		G.arcs[i][j]=weight;G.arcs[j][i]=weight; //无向图的邻接矩阵是对称矩阵
	} //若是网，可让 G.arcs[i][j]=w， w 为权值
}
/******输出无向图*********/
void out_Mg(AMGraph G){
	int i, j;
    for(i=0; i< G.vexnum; i++) //矩阵原样输出
{
    printf("\n");
    for(j=0; j< G.vexnum; j++)
    printf("%5d", G.arcs[i][j]);
}
//输出所存在的边
	printf("\n组成无向图的边为:\n");
    for(i=0; i< G.vexnum; i++)  //若边（i,j）存在，则只需输出边（i,j）或（j,i）
{
    for(j=i; j< G.vexnum; j++)
{
    if(G.arcs[i][j]!=0)
    printf("\n ( %d, %d )", i, j);
}
}
    printf("\n");
} 

