#include<stdio.h>
#include<math.h>
int num,sum,start,max;//磁道个数，磁道移动总数，开始磁道数，最长磁道号
int m=0,n=0,s[100],s1[100],c1[50],c2[50];
//s[]数组记录磁道序列
//用开始磁道数start来将序列划分成两个数组c1,c2

void creat()//初始化操作
{
  int i,j,t;
  printf("请输入磁道的个数：\n");
  scanf("%d",&num);
  printf("请输入从哪个磁道开始：\t\n");
  scanf("%d",&start);
  printf("请输入最长磁道号：\n"); 
  scanf("%d",&max); 
  for(j=0;j<num;j++)
  {
    printf("请输入第%d个磁道\n",j+1);
    scanf("%d",&s[j]);
    if(s[j]>max)    //当出现磁道数大于最长磁道号时，给出错误提示
	{
		printf("ERROR\n");
		break;
	}
  }

  printf("访问序列如下\n");
  for(i=0;i<num;i++)//输出访问序列
  {
    printf("\t%d\t\n",s[i]);
  }

 int su=start;//将开始寻道的磁道赋值给变量su,以方便保存变量

 for(i=0;i<num;i++)
   if(su>s[i])//用开始磁道数start来将序列划分成两个数组c1,c2
      c1[m++]=s[i];//初始时m为0

   else
      c2[n++]=s[i];//初始时n为0

   for(i=0;i<m;i++)
        for(j=i;j<m;j++)
                if(c1[i]<c1[j])//将c1数组从大到小排序
                {
					t=c1[i];
					c1[i]=c1[j];
					c1[j]=t;
				}

    for(i=0;i<n;i++)
        for(j=i;j<n;j++)
                if(c2[i]>c2[j])//将c2数组从小到大排序
                {
					t=c2[i];
					c2[i]=c2[j];
					c2[j]=t;
			}

}

void FCFS()		//先来先服务算法

{
	int i;
	printf("先来先服务 FCFS\n");
	printf("被访问的下一个磁道\t\t\t磁道号移动距离\n");
    int su=start;//初始磁道数赋值给变量su
    sum=0;
    for(i=0;i<num;i++)
	{ 
		if(su<s[i])
			s1[i]=s[i]-su;//s1数组记录每次移动磁道数，输出在界面上

        else
            s1[i]=su-s[i];
      su=s[i];
      sum+=s1[i];//记录移动磁道数
    }

    for(i=0;i<num;i++)
    {
		printf("\t%d\t\t\t\t\t%d\t\t\n",s[i],s1[i]);
	}
    printf("平均寻道长度：%.2f\n",sum*1.0/num);
}


void SSTF()	//最短寻道
{

      printf("最短寻道 SSTF:\n");
      printf("被访问的下一个磁道\t\t\t磁道号移动距离\n");
      int s2[100],i;
      sum=0;
	  for(i=0;i<num;i++)
		  s2[i]=s[i];
	  int min,temp,st=start,j,tag;
	  for(j=0;j<num;j++){
		  min=10000;
	for(i=0;i<num;i++)	//每次选出离当前磁道最近的磁道
	{
		temp=abs(s2[i]-st);
		if(temp<min){
			min=temp;
			tag=i;
		}
	}
	st=s2[tag];
         printf("\t%d\t\t\t\t\t%d\t\t\n",s2[tag],min);
       sum=sum+min;  //记录每次的移动数
	   s2[tag]=10000;
}
       printf("平均寻道长度:%.2f\n",sum*1.0/num);
    }

void SCAN()//扫描算法

{
	 int i;
     printf("扫描算法 SCAN:\n");
     printf("被访问的下一个磁道：\t\t\t磁道号移动距离：\n");
     int su=start;
     int s2[100];
     sum=0;
     for(i=0;i<n;i++)	//先自内而外地进行移动磁头
     s2[i]=c2[i];
     for(i=0;i<m;i++)	//c1c2数组是create函数已经分化好的排序数组
      s2[i+n]=c1[i];
     for(i=0;i<num;i++)
     { 
		if(su<s2[i])
            s1[i]=s2[i]-su;
        else
        s1[i]=su-s2[i];
        su=s2[i];
        sum+=s1[i];
     }

      for(i=0;i<num;i++)
      {
         printf("\t%d\t\t\t\t\t%d\t\t\n",s2[i],s1[i]);
      }
       printf("平均寻道长度：%.2f\n",sum*1.0/num);
    }

void CSAN()
{
	int i;
     printf("循环扫描 CSAN:\n");
     printf("被访问的下一个磁道：\t\t\t磁道号移动距离：\n");
     int su=start;
     int j=0;
     int s2[100];
     sum=0;
     for(i=0;i<n;i++)
      s2[i]=c2[i];

     for(i=m-1;i>=0;j++,i--)
      s2[j+n]=c1[i];
      for(i=0;i<num;i++)
      { 
		  if(su<s2[i])
			s1[i]=s2[i]-su;
		  else
        s1[i]=su-s2[i];
        su=s2[i];
        sum+=s1[i];
      }

      //sum=sum/num;
      for(i=0;i<num;i++)
       {
		  printf("\t%d\t\t\t\t\t%d\t\t\n",s2[i],s1[i]);
       }
       printf("平均寻道长度:%.2f\n",sum*1.0/num);
}

 

 

void MENU()

{
  int x;
	creat();	//初始化磁道
	do{
	printf("磁盘调度\n");
	printf("|--------请选择操作------------|\n");
	printf("|------1.创建磁道--------------|\n");
	printf("|------2.先来先服务FCFS--------|\n");
	printf("|------3.最短寻道SSTF----------|\n"); 
	printf("|------4.扫描算法 SCAN---------|\n");
	printf("|------5.循环扫描算法 CSCAN----|\n");
	printf("|------6.EXIT------------------|\n");
	scanf("%d",&x);
	switch(x)
{
	case 2: FCFS();
            break;
	case 3:SSTF();
			break;
	case 4:SCAN();
			break;
	case 5:CSAN();
			break;
	case 6:
		printf("再见！");
	break;

}
  }while(x<6);

}

int main()	//主调函数
{
	MENU();
	return 0;
}
