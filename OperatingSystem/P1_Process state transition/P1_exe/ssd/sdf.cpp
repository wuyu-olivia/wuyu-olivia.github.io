#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

enum status{success,failed};
enum Jstate{ready,run,block,death};     //进程的三个状态和消亡 

typedef struct PCB{
	int id;
	char name[20];
	Jstate state;
	int timebin;
	int grade;
	int key;//?
}PCB;

queue<PCB> q;    //就绪队列 
PCB p_run;  //运行中的进程 
int p_flag=0;// 为零表示没有正在执行的进程 
queue<PCB> Qblock; //阻塞队列 
queue<PCB> Qdeath;//消亡队列 

status addtoReady(PCB a)//向就绪队列添加进程
{

	q.push(a);
	return success;
	
}

status Init()//初始化队列
{
	int n,i,num,max; //用来优先级入队 
	PCB t,a[100];
	cout<<"输入进程个数：\n";
	cin>>n;
	for(i=0;i<n;i++)
	{	
		a[i].id=i;
		a[i].state=ready;
		printf("输入第%d个进程名称、运行的时间片、优先级数:\n",i+1);
		scanf("%s",a[i].name);
		cin>>a[i].timebin;
		cin>>a[i].grade;				
	}
	cout<<"开始"<<endl; 
	for(num=0;num<n;num++) //n个进程按照优先级大小排序入队
	{
		max=-100; 
		for(i=num;i<n;i++)  
		{
			if(max<a[i].grade)
			{
				max=a[i].grade;
				t=a[num];
				a[num]=a[i];
				a[i]=t;
			}
		} 

		addtoReady(a[num]);
	}
	return success;	
}

status wakeUp() //将阻塞队列中的进程唤醒
{
	int flag=0; 
	PCB p;
	
	p=Qblock.front();//阻塞队列中第一个进程
	p.state=ready;  //改状态
	printf("唤醒进程%d %s\n",p.id,p.name);
	addtoReady(p);
	Qblock.pop();
	return success;	
}

status RuntoBlock(PCB j)  //从运行态变成阻塞态
{
	j.state=block;
	Qblock.push(j);
	return success; 
}

status RuntoDeath(PCB j) //进入消亡队列
{
	j.state=death;
	Qdeath.push(j);
	return success;
}

status RunJob() //执行进程 
{
	
	char S1;
	if(p_flag==0)//无正在运行的进程
	{
			
		if(q.size()==0)
		{
			cout<<"当前无就绪进程!"<<endl;
			if(p_flag==0)
			{
				printf("运行结束...\n");
				return success;
			}
		}
		else{ //就绪队列不为空
		PCB job=q.front(); //取就绪队列队头元素
		q.pop(); //队头元素出队
		if(job.timebin>0) //时间片未用完，继续执行
		{
			job.grade--;
			printf("%s开始进入执行状态...\n当前所需时间片：%d\n",job.name,job.timebin);
			job.timebin--;
			if(job.timebin<=0)
			{
				cout<<"执行完成后该进程已消亡.."<<endl;
				RuntoDeath(job);
				p_flag=0;
				return success;
			}
			if(job.timebin>0)
			{
				job.state=run; //修改状态			
				p_run=job; //运行中的进程
				p_flag=1;
			}

			if(Qblock.size()!=0)//执行一次时间片后，看是否需要唤醒阻塞队列的进程
			{
				printf("是否唤醒阻塞的进程？（输入Y/N）\n");
				cin>>S1;
				if(S1=='Y')
				{
					wakeUp();
					return success;
				}
			}

		
		}
		else if(job.timebin<=0&&job.state!=death)//时间片用完
		{
			cout<<"该进程时间片用完，进入消亡队列！"<<endl;
			RuntoDeath(job);//放到消亡队列
			return success;
		}

		return success;
		}//?
	}
	//已有正在执行的进程
	char S2;

	printf("是否阻塞（Y/N）ID:%d name:%s进程？\n",p_run.id,p_run.name);
	cin>>S2;
	if(S2=='Y')//将原来正在执行的进程阻塞
	{
		RuntoBlock(p_run);
		printf("ID:%d name:%s 进入阻塞队列\n",p_run.id,p_run.name);
		//阻塞完之后再将就绪队列第一个进程调出执行
		if(q.size()==0)
		{
			cout<<"当前无就绪进程!"<<endl;
			if(p_flag==0)
			{
				printf("运行结束...\n");
				return success;
			}
			else
			  wakeUp();//

		}
		PCB job=q.front(); //取就绪队列队头元素
		q.pop(); //队头元素出队
		if(job.timebin>0) //时间片未用完，继续执行
		{
			job.grade--;
			printf("%s开始进入执行状态...\n当前所需时间片：%d\n",job.name,job.timebin);
			job.timebin--;
			if(job.timebin<=0&&job.state!=death){
				cout<<"执行完成后该进程已消亡.."<<endl;
				RuntoDeath(job);
				p_flag=0;//
				return success;//?
			}
			if(job.timebin>0)
			{
				job.state=run; //修改状态			
				p_run=job; //运行中的进程
				p_flag=1;
			}
			
			if(Qblock.size()!=0)//执行一次时间片后，看是否需要唤醒阻塞队列的进程
			{
				printf("是否唤醒阻塞的进程？（输入Y/N）\n");
				cin>>S1;
				if(S1=='Y')
				{
					wakeUp();
					return success;
				}
			}
			//

		else if(job.timebin<=0&&job.state!=death)//时间片用完
		{
			cout<<"时间片已用完，进入消亡队列！"<<endl;
			RuntoDeath(job);//放到消亡队列
			return success;
		}
			return  success;
		}
		
	}
	else{
	p_run.timebin--;
	if(p_run.timebin==0&&p_run.state!=death)//消亡 
	{
		printf("ID:%d name:%s 时间片已用完,进入消亡队列\n",p_run.id,p_run.name);
		RuntoDeath(p_run);
		p_flag=0; 
	} 
	}
	return success; 
			
}


status Show(queue<PCB> temp)
{
	cout<<temp.size()<<endl; 
	PCB p;
	while(temp.size()!=0)
	{	
		p=temp.front();
		if(p.state==death)
		printf("进程%d\t进程名:%s\t运行时间片：%d\t优先级数：%d\n",p.id,p.name,p.timebin,p.grade);
		temp.pop();
	}
	cout<<endl;
	return success;
 }

int main()
{
	int x;  
	Init();
	do 
	{
	cout<<"请选择操作：（1：执行进程 2：输出就绪队列 3：输出阻塞队列 4：输出消亡队列 5：结束） "<<endl; 
		cin>>x;
		switch(x)
		{
		case 1: RunJob();break;
		case 2: Show(q);break;
		case 3: Show(Qblock);break;
		case 4: Show(Qdeath);break;
		case 5: return 0;break;
		}
		if(q.size()==0&&Qblock.size()==0&&p_flag==0)
		{
			cout<<"所有进程均结束"<<endl; 
			break;
	 	} 
	 }while(1); 
	cout<<"就绪队列进程："<<endl;
	Show(q);
	cout<<"阻塞队列进程："<<endl;
	Show(Qblock);
	cout<<"消亡队列进程："<<endl;
	Show(Qdeath);
	return 0;
}
