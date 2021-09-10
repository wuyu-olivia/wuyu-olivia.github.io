#include "stdio.h"
 
const int max=10000;
const int dist=50;
int optimize(int i,int bestpath[],int p)//检测节点是否已经加入bestpath[]中
{  
	int k;
    for(k=1;k<=p;k++)
        {
            if(i==bestpath[k])
                break;
 
        }
    if(k!=p+1)//新测试节点在a[]中
        return 1;
    else
        return 0;
 
}
 
int main()
{  
    int min=max;
    int minf=max;
    int num;//城市数量
    int mat[dist][dist];//城市间距离
    int bestpath[dist];//最佳路径
    int f=0,g=0,h=0;
    int ff[dist];//依次求每个城市的f值
    int gg[dist];//城市的g值
   
    printf("请输入城市个数：");
    scanf("%d",&num);
 
    printf("每两个城市间的距离为：\n");//输入各城市间距离的矩阵
    for(int i=0;i<num;i++)
        for(int j=0;j<num;j++)
            scanf("%d",&mat[i][j]);
   
    bestpath[0]=0;//起点为0，即城市A
    for(int p=0;p<num-1;p++)//依次求每个最优节点，每次循环得到一个新的最优城市放到bestpath[]中
    {
    	int i;
        for(int kk=0;kk<num;kk++)
            ff[kk]=max;//便于后面求最小值
        for(i=1;i<num;i++)//起点A不算，从非起点开始找寻最优城市
        {
            if(optimize(i,bestpath,p))//该点已经在bestpath[]中的话，忽略
            continue;
            else//计算该点的g值
            gg[i]=g+mat[bestpath[p]][i];//i点的g值
 
                for(int m=0;m<num;m++)//开始计算h值
            {
                if(optimize(m,bestpath,p))//该点已经在bestpath[]中的话，忽略
                    continue;
                for(int t=m+1;t<num;t++)
 
                {
                    if(optimize(t,bestpath,p))
                        continue;
                    if(m!=0||t!=i||p==num-2)//不是最后一个点的话，不算A点到这个点长度
                        if(mat[m][t]<min)
                            min=mat[m][t];
                }
            }
           h=min*(num-p-1);//h值
            ff[i]=gg[i]+h;//第i个节点的f值
            min=max;//重新赋值最大，以便下次循环
 
        }
        for(i=0;i<num;i++)//找寻最优点，即f值最小者
        {
            if(ff[i]<minf)
            {
                minf=ff[i];
                bestpath[p+1]=i;
            }
        }
        minf=max;//重新赋值最大，以便下次循环  
        g=g+mat[bestpath[p]][bestpath[p+1]];//更新g值
    }
   
printf("最优路径为（A,B,C...依次表示第一、第二...个城市）:");
int i;
for(i=0;i<num;i++)
  printf("%c ",bestpath[i]+65);
printf("A\n");
 
printf("总路程为:");
int sum=0;
for(i=0;i<num-1;i++)
  sum=sum+mat[bestpath[i]][bestpath[i+1]];
sum=sum+mat[bestpath[num-1]][0];//总路程最后一个城市要回到A，所以加上其距离
printf("%d\n",sum);
return 0;
}
