#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

enum status{success,failed};
enum Jstate{ready,run,block,death};     //���̵�����״̬������ 

typedef struct PCB{
	int id;
	char name[20];
	Jstate state;
	int timebin;
	int grade;
	int key;//?
}PCB;

queue<PCB> q;    //�������� 
PCB p_run;  //�����еĽ��� 
int p_flag=0;// Ϊ���ʾû������ִ�еĽ��� 
queue<PCB> Qblock; //�������� 
queue<PCB> Qdeath;//�������� 

status addtoReady(PCB a)//�����������ӽ���
{

	q.push(a);
	return success;
	
}

status Init()//��ʼ������
{
	int n,i,num,max; //�������ȼ���� 
	PCB t,a[100];
	cout<<"������̸�����\n";
	cin>>n;
	for(i=0;i<n;i++)
	{	
		a[i].id=i;
		a[i].state=ready;
		printf("�����%d���������ơ����е�ʱ��Ƭ�����ȼ���:\n",i+1);
		scanf("%s",a[i].name);
		cin>>a[i].timebin;
		cin>>a[i].grade;				
	}
	cout<<"��ʼ"<<endl; 
	for(num=0;num<n;num++) //n�����̰������ȼ���С�������
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

status wakeUp() //�����������еĽ��̻���
{
	int flag=0; 
	PCB p;
	
	p=Qblock.front();//���������е�һ������
	p.state=ready;  //��״̬
	printf("���ѽ���%d %s\n",p.id,p.name);
	addtoReady(p);
	Qblock.pop();
	return success;	
}

status RuntoBlock(PCB j)  //������̬�������̬
{
	j.state=block;
	Qblock.push(j);
	return success; 
}

status RuntoDeath(PCB j) //������������
{
	j.state=death;
	Qdeath.push(j);
	return success;
}

status RunJob() //ִ�н��� 
{
	
	char S1;
	if(p_flag==0)//���������еĽ���
	{
			
		if(q.size()==0)
		{
			cout<<"��ǰ�޾�������!"<<endl;
			if(p_flag==0)
			{
				printf("���н���...\n");
				return success;
			}
		}
		else{ //�������в�Ϊ��
		PCB job=q.front(); //ȡ�������ж�ͷԪ��
		q.pop(); //��ͷԪ�س���
		if(job.timebin>0) //ʱ��Ƭδ���꣬����ִ��
		{
			job.grade--;
			printf("%s��ʼ����ִ��״̬...\n��ǰ����ʱ��Ƭ��%d\n",job.name,job.timebin);
			job.timebin--;
			if(job.timebin<=0)
			{
				cout<<"ִ����ɺ�ý���������.."<<endl;
				RuntoDeath(job);
				p_flag=0;
				return success;
			}
			if(job.timebin>0)
			{
				job.state=run; //�޸�״̬			
				p_run=job; //�����еĽ���
				p_flag=1;
			}

			if(Qblock.size()!=0)//ִ��һ��ʱ��Ƭ�󣬿��Ƿ���Ҫ�����������еĽ���
			{
				printf("�Ƿ��������Ľ��̣�������Y/N��\n");
				cin>>S1;
				if(S1=='Y')
				{
					wakeUp();
					return success;
				}
			}

		
		}
		else if(job.timebin<=0&&job.state!=death)//ʱ��Ƭ����
		{
			cout<<"�ý���ʱ��Ƭ���꣬�����������У�"<<endl;
			RuntoDeath(job);//�ŵ���������
			return success;
		}

		return success;
		}//?
	}
	//��������ִ�еĽ���
	char S2;

	printf("�Ƿ�������Y/N��ID:%d name:%s���̣�\n",p_run.id,p_run.name);
	cin>>S2;
	if(S2=='Y')//��ԭ������ִ�еĽ�������
	{
		RuntoBlock(p_run);
		printf("ID:%d name:%s ������������\n",p_run.id,p_run.name);
		//������֮���ٽ��������е�һ�����̵���ִ��
		if(q.size()==0)
		{
			cout<<"��ǰ�޾�������!"<<endl;
			if(p_flag==0)
			{
				printf("���н���...\n");
				return success;
			}
			else
			  wakeUp();//

		}
		PCB job=q.front(); //ȡ�������ж�ͷԪ��
		q.pop(); //��ͷԪ�س���
		if(job.timebin>0) //ʱ��Ƭδ���꣬����ִ��
		{
			job.grade--;
			printf("%s��ʼ����ִ��״̬...\n��ǰ����ʱ��Ƭ��%d\n",job.name,job.timebin);
			job.timebin--;
			if(job.timebin<=0&&job.state!=death){
				cout<<"ִ����ɺ�ý���������.."<<endl;
				RuntoDeath(job);
				p_flag=0;//
				return success;//?
			}
			if(job.timebin>0)
			{
				job.state=run; //�޸�״̬			
				p_run=job; //�����еĽ���
				p_flag=1;
			}
			
			if(Qblock.size()!=0)//ִ��һ��ʱ��Ƭ�󣬿��Ƿ���Ҫ�����������еĽ���
			{
				printf("�Ƿ��������Ľ��̣�������Y/N��\n");
				cin>>S1;
				if(S1=='Y')
				{
					wakeUp();
					return success;
				}
			}
			//

		else if(job.timebin<=0&&job.state!=death)//ʱ��Ƭ����
		{
			cout<<"ʱ��Ƭ�����꣬�����������У�"<<endl;
			RuntoDeath(job);//�ŵ���������
			return success;
		}
			return  success;
		}
		
	}
	else{
	p_run.timebin--;
	if(p_run.timebin==0&&p_run.state!=death)//���� 
	{
		printf("ID:%d name:%s ʱ��Ƭ������,������������\n",p_run.id,p_run.name);
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
		printf("����%d\t������:%s\t����ʱ��Ƭ��%d\t���ȼ�����%d\n",p.id,p.name,p.timebin,p.grade);
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
	cout<<"��ѡ���������1��ִ�н��� 2������������� 3������������� 4������������� 5�������� "<<endl; 
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
			cout<<"���н��̾�����"<<endl; 
			break;
	 	} 
	 }while(1); 
	cout<<"�������н��̣�"<<endl;
	Show(q);
	cout<<"�������н��̣�"<<endl;
	Show(Qblock);
	cout<<"�������н��̣�"<<endl;
	Show(Qdeath);
	return 0;
}
