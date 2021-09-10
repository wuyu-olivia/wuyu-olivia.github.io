#include"M_AL_Graph.h"
//主函数测试
int main()
{ 
	int count=0;
	printf("创建无向带权图\n"); 
	AMGraph A;
	creat_Mg(A);
    printf("邻接矩阵如下：\n"); 
    out_Mg(A); 
	/*******普里姆算法生成最小生成树********/
    MiniSpTree_PRIM(A,0);
    DFS(A,0,count);
   	if(count==A.vexnum)
	{
		printf("该无向图是连通图\n");
	}
    else 
		printf("该无向图不是连通图\n"); 
	return 0;
} 