#include "stdio.h"
 
const int max=10000;
const int dist=50;
int optimize(int i,int bestpath[],int p)//���ڵ��Ƿ��Ѿ�����bestpath[]��
{  
	int k;
    for(k=1;k<=p;k++)
        {
            if(i==bestpath[k])
                break;
 
        }
    if(k!=p+1)//�²��Խڵ���a[]��
        return 1;
    else
        return 0;
 
}
 
int main()
{  
    int min=max;
    int minf=max;
    int num;//��������
    int mat[dist][dist];//���м����
    int bestpath[dist];//���·��
    int f=0,g=0,h=0;
    int ff[dist];//������ÿ�����е�fֵ
    int gg[dist];//���е�gֵ
   
    printf("��������и�����");
    scanf("%d",&num);
 
    printf("ÿ�������м�ľ���Ϊ��\n");//��������м����ľ���
    for(int i=0;i<num;i++)
        for(int j=0;j<num;j++)
            scanf("%d",&mat[i][j]);
   
    bestpath[0]=0;//���Ϊ0��������A
    for(int p=0;p<num-1;p++)//������ÿ�����Žڵ㣬ÿ��ѭ���õ�һ���µ����ų��зŵ�bestpath[]��
    {
    	int i;
        for(int kk=0;kk<num;kk++)
            ff[kk]=max;//���ں�������Сֵ
        for(i=1;i<num;i++)//���A���㣬�ӷ���㿪ʼ��Ѱ���ų���
        {
            if(optimize(i,bestpath,p))//�õ��Ѿ���bestpath[]�еĻ�������
            continue;
            else//����õ��gֵ
            gg[i]=g+mat[bestpath[p]][i];//i���gֵ
 
                for(int m=0;m<num;m++)//��ʼ����hֵ
            {
                if(optimize(m,bestpath,p))//�õ��Ѿ���bestpath[]�еĻ�������
                    continue;
                for(int t=m+1;t<num;t++)
 
                {
                    if(optimize(t,bestpath,p))
                        continue;
                    if(m!=0||t!=i||p==num-2)//�������һ����Ļ�������A�㵽����㳤��
                        if(mat[m][t]<min)
                            min=mat[m][t];
                }
            }
           h=min*(num-p-1);//hֵ
            ff[i]=gg[i]+h;//��i���ڵ��fֵ
            min=max;//���¸�ֵ����Ա��´�ѭ��
 
        }
        for(i=0;i<num;i++)//��Ѱ���ŵ㣬��fֵ��С��
        {
            if(ff[i]<minf)
            {
                minf=ff[i];
                bestpath[p+1]=i;
            }
        }
        minf=max;//���¸�ֵ����Ա��´�ѭ��  
        g=g+mat[bestpath[p]][bestpath[p+1]];//����gֵ
    }
   
printf("����·��Ϊ��A,B,C...���α�ʾ��һ���ڶ�...�����У�:");
int i;
for(i=0;i<num;i++)
  printf("%c ",bestpath[i]+65);
printf("A\n");
 
printf("��·��Ϊ:");
int sum=0;
for(i=0;i<num-1;i++)
  sum=sum+mat[bestpath[i]][bestpath[i+1]];
sum=sum+mat[bestpath[num-1]][0];//��·�����һ������Ҫ�ص�A�����Լ��������
printf("%d\n",sum);
return 0;
}
