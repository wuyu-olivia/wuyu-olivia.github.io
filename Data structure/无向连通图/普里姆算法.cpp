#include"头文件.h"
#include<stdio.h>

void CreateGraph(MGraph *M,int vex,int arc){		//创建邻接矩阵
	int i,j,k;
	printf("请输入顶点的权值：");
	for(i=0;i<vex;i++)
		scanf("%d",&M->vexs[i]);
	for(i=0;i<vex;i++)
		for(j=0;j<vex;j++)
		{
			M->arcs[i][j]=0;
		}
	for(k=0;k<arc;k++)
	{
		printf("请输入第%d条边的两个顶点：",k+1);
		scanf("%d%d",&i,&j);
		M->arcs[i-1][j-1]=1;
		M->arcs[j-1][i-1]=1;
	}
}

/*void TurntoALGraph(MGraph G1,ALGraph &G2)
{
      int i,j;
	  ArcNode *p;
	  G2.vexnum=G1.vexnum;
	  G2.arcnum=G1.arcnum;
	  for(i=0;i<G2.vexnum;i++)
	  {
		  G2.vertices[i].data=i;
		  p=(ArcNode  *)malloc(sizeof(ArcNode));
		  p->nextarc=NULL;
		  G2.vertices[i].firstarc=p;
		  for(j=0;j<G2.vexnum;j++)         //头插法建立链接表
		  {
			  if(G1.arcs[i][j]==1)
			  {
                     p=(ArcNode  *)malloc(sizeof(ArcNode));
					 p->adjvex=j;
					 p->nextarc=G2.vertices[i].firstarc->nextarc;   
					 G2.vertices[i].firstarc->nextarc=p;
			  }
		  }
	  }
}
*/
void displayALGraph(ALGraph *A,int v)
{
	int i;
	ALGraph *p=A;
	for(i=0;i<v;i++)
	{
		printf("%d %d->",i,p->vertices[i].data);
		while(p->vertices[i].firstarc)
		{
			printf("%d->",p->vertices[i].firstarc->adjvex);
			p->vertices[i].firstarc=p->vertices[i].firstarc->nextarc;
		}
		printf("\n");
	}
	printf("\n");
}

void CreateAdj(ALGraph *&G,MGraph g,int n,int e)   //创建图的邻接表
{
	init(G);
	int i,j;
	ArcNode *p;
	G->n=n;
	G->e=e;

	for(i=0;i<n;i++)
	{
		for(j=n-1;j>=0;j--)
		{
			if(g.arcs[i][j]==1) 
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex=j;
				p->nextArc = G->adjlist[i].FirstArc->nextArc;
				G->adjlist[i].FirstArc->nextArc = p; 
			}
		}
	}

	for(i=0;i<n;i++)
	{
		G->adjlist[i].data =i+1;
	}
}
