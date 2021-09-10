#include"M_AL_Graph.h"
#define maxSize 20
int visited[MAXV]={0};
int initLinkList(LinkList *L)
{
	*L=(LinkList)malloc(sizeof(Lnode));
	if(*L==NULL)
		return 0;
	(*L)->next=NULL;
	return 1;
}


/************�����ڽӾ���*************/
void CreateGraph(MGraph *G,int v,int a,LinkList *L)
{
	int i,j,k;
	for(i=0;i<v;i++)
	{
		printf("�������%d�������ֵ\n",i+1);
		scanf("%d",&G->vexs[i]);  //����ͼ�Ķ�����Ϣ
		
	}
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			G->arcs[i][j]=0;  //����ߵ���Ϣ����ȫ�����㣨�ڽӾ���
	for(k=0;k<a;k++)   //a�Ǳ���
		{
			printf("�������%d�����ڽӵĻ�β�ͻ��׶���\n",k+1);
			scanf("%d%d",&i,&j);
			G->arcs[i-1][j-1]=1;
		}
}

/************�����ڽӱ�*************/
/*void CreateAdjlist(ALGraph *G,int v,MGraph *M)
{
	int i,m,n;
	ArcNode *p;   //�ڽӱ�߽��
	for(i=0;i<v;i++)
	{
		G->vertices[i].data=M->vexs[i];  //������Ϣ
		G->vertices[i].FirstArc=NULL;   //�ڽӱ��ͷ���
	}
	for(m=0;m<v;m++)
		for(n=0;n<v;n++)
		{
			if(M->arcs[m][n]==1)   //�����������б����
			{
			p=(ArcNode *)malloc(sizeof(ArcNode));   //����һ���ڽӱ���
			p->adjvex=n;
			p->nextArc=G->vertices[m].FirstArc;
			G->vertices[i].FirstArc=p;
			}
		}
		
}*/



//����ڽӾ���
void displayMGraph(MGraph *G,int v,int a)
{
	int i,j;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			printf("%d ",G->arcs[i][j]);
		}
		printf("\n");
	}
}

void TurntoALGraph(MGraph G1,ALGraph &G2)
{
      int i,j;
	  ArcNode *p;
	  p=(ArcNode *)malloc(sizeof(ArcNode));
	  G2.vexnum=G1.vexNum;
	  G2.arcnum=G1.arcNum;

	  for(i=0;i<G2.vexnum;i++)
	  {
		  G2.vertices[i].data=i;
		  p=(ArcNode  *)malloc(sizeof(ArcNode));
		  p->nextArc=NULL;
		  G2.vertices[i].FirstArc=p;
		  for(j=G2.vexnum-1;j>=0;j--)          //ͷ�巨�������ӱ�
		  {
			  if(G1.arcs[i][j]==1)
			  {
                     p=(ArcNode  *)malloc(sizeof(ArcNode));
					 p->adjvex=j;
					 p->nextArc=G2.vertices[i].FirstArc->nextArc;   
					 G2.vertices[i].FirstArc->nextArc=p;
			  }
		  }
	  }
}

//����ڽӱ�
void displayALGraph(ALGraph *A,int v)
{
	int i;
	ALGraph *p=A;
	for(i=0;i<v;i++)
	{
		printf("%d %d->",i,p->vertices[i].data);
		while(p->vertices[i].FirstArc)
		{
			printf("%d->",p->vertices[i].FirstArc->adjvex);
			p->vertices[i].FirstArc=p->vertices[i].FirstArc->nextArc;
		}
		printf("\n");
	}
	printf("\n");
}

/**************������ȱ���**************/
void DFSTraverse(ALGraph G)
{
	int v;
	for(v=0;v<G.vexnum;v++)		//���ʱ�־�����ʼ��
		visited[v]=0;
	for(v=0;v<G.vexnum;v++)		//����δ���ʵĶ������DFS
		if(!visited[v])
			DFS(G,v);
}

void DFS(ALGraph G,int i)
{
	printf("%d->",G.vertices[i].data);
	visited[i]=1;
	ArcNode *q=G.vertices[i].FirstArc->nextArc;
	while(q!=NULL)
	{
		if(!visited[q->adjvex])
		DFS(G,q->adjvex);
		q=q->nextArc;
	}
}

LinkQueue InitQueue()
{
	//����һ���ն���Q
	LinkQueue Q;
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)
		exit(-1);
	Q.front->next=NULL;
	return Q;
}
void DestroyQueue(LinkQueue &Q){
	//���ٶ���Q
	while(Q.front){
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
}
int EnQueue(LinkQueue &Q,QElemType e)
{
    QueuePtr p;
	p=(QueuePtr)malloc(sizeof (QNode));
	if(!p)
		exit(-1);
	p->data=e;p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return 0;
}
int DeQueue(LinkQueue &Q,QElemType &e){
     QueuePtr p;
	if(Q.front==Q.rear)return 1;
	 p=Q.front->next;
	 e=p->data;
	 Q.front->next=p->next;
	 if(Q.rear==p) Q.rear=Q.front;
	 free(p);
	 return 0;
}
int QueueEmpty(LinkQueue Q)
{
	if(Q.front==Q.rear )
	{
        return 1;
	}
    else
	{
		return 0;
	}
}
int FirstAdjVex(ALGraph G,int u)
{
	int w=-1;
	if(G.vertices[u].FirstArc->nextArc==NULL)    //�������
		return w;
    w=G.vertices[u].FirstArc->nextArc->adjvex;
	return w;
}
int NextAdjVex(ALGraph G,int u,int w)
{
    int n=-1;
	ArcNode  *q=G.vertices[u].FirstArc->nextArc;
	while(q->nextArc!=NULL)
	{
           if(q->adjvex==w)
		   {
			   n=q->nextArc->adjvex;
			   break;
		   }
		   q=q->nextArc;
	}
	return n;        //������ʾ����û�н����
}
void BFS(ALGraph G)
{
    int i;
  for(i=0;i<MAXV;i++)
  {
    visited[i]=0;
  }
	LinkQueue Q;
	int v,u,w;
    for(v=0;v<G.vexnum;++v) visited[v]=0;
	Q=InitQueue();
	for(v=0;v<G.vexnum;++v)
		if(!visited[v]){                         //v��δ����
			visited[v]=1;
			printf("%d->",G.vertices[v].data);
			EnQueue(Q,v);                        //v�����
			while(!QueueEmpty(Q)){
				DeQueue(Q,u);                    //��ͷԪ�س��Ӳ���
				for(w=FirstAdjVex(G,u);w>=0;w=NextAdjVex(G,u,w))    //FirstAdjVex(G,v)����ͼG �ж���v �ĵ�1 ���ڽӶ���(��ͼ�е�λ��)��NextAdjVex(G,v,w)��FirstAdjVex(G,v)����1���β�w��������ͼG �ж���v �������ڽӶ����������ڽӶ���w ������Ǹ��ڽӶ���(��ͼ�е�λ��)
					if(!visited[w]){
						printf("%d->",w);
						visited[w]=1;
						EnQueue(Q,w);
					}//if
			}//while
		}//if
}//BFS