#include"M_AL_Graph.h"
//����������
int main()
{ 
	int count=0;
	printf("���������Ȩͼ\n"); 
	AMGraph A;
	creat_Mg(A);
    printf("�ڽӾ������£�\n"); 
    out_Mg(A); 
	/*******����ķ�㷨������С������********/
    MiniSpTree_PRIM(A,0);
    DFS(A,0,count);
   	if(count==A.vexnum)
	{
		printf("������ͼ����ͨͼ\n");
	}
    else 
		printf("������ͼ������ͨͼ\n"); 
	return 0;
} 