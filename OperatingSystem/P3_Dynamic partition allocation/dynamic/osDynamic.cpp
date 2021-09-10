#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define MAXNUMBER 100
//********************���������ĺ���******************
int ProcessNum; //���̸���
int PartitionNum;  //�ڴ��п��з����ĸ���
int FreePartition[MAXNUMBER];  //���з�����Ӧ���ڴ�
int begin[MAXNUMBER];
char ProcessName[MAXNUMBER];//��������
int ProcessNeed[MAXNUMBER];  //���̴�С
int Processarrive[MAXNUMBER];//���̵���ʱ��
int Processend[MAXNUMBER];//���̽���ʱ��
char NameProcessToPartition[MAXNUMBER][MAXNUMBER];//�����������ڷ���λ��
int choose;//�㷨ѡ��
int LeftFreePartition[MAXNUMBER];//ʣ�¿����ڴ�
int LeftProcessNeed[MAXNUMBER];//ʣ�½�����Ҫ�ռ�
int LeftProcessarrive[MAXNUMBER];//ʣ�½��̵���ʱ��
int LeftProcessend[MAXNUMBER];//ʣ�½��̽���ʱ��
typedef struct{    //���̽ṹ��
	char ProcessName;
	int ProcessNeed;
	int Processarrive;
	int Processend;
	int flag;//�ж��Ƿ���䵽�ռ�
}Process;
typedef struct lis{//���з�����
    int partitionSize;//��������С
    int id;		//���������
	int begin; //��ʼ��ַ
	lis *next;
}sortNeed;
bool cmp1(sortNeed a,sortNeed b) //�����Ӧ�㷨�����Ӧ�㷨�õ�����
{
    return a.partitionSize<b.partitionSize;  //�����return a<b �Ļ�������������
}
bool cmp2(sortNeed a,sortNeed b) //�����Ӧ�㷨�����Ӧ�㷨�õ�����
{
    return a.partitionSize>b.partitionSize;  //�����return a>b �Ļ����ǽ�������
}
int num1,num2;//�ֱ��¼���з������ѷ�������ĸ���
sortNeed Empty[MAXNUMBER];
sortNeed Full[MAXNUMBER];
sortNeed *Emptylist=NULL;
sortNeed *Fulllist=NULL;
Process run[MAXNUMBER];
bool operator<(Process a,Process b)  //�����Զ����������ȼ��Ƚ�
{
	return a.Processarrive>b.Processarrive;
}
void Enter();//����������ʹ�С����Դ���ʹ�С
void initial();//��ʼ��
void display();//��ʾ�������
void FirstFit();//�״���Ӧ�㷨FF
void NextFit();//ѭ���״���Ӧ�㷨NF
void BestFit();//�����Ӧ�㷨BF
void WorstFit();//���Ӧ�㷨WF
void choose_Algorithm();//ѡ���㷨
priority_queue<Process>PCB;
int main()
{
   Enter();
   choose_Algorithm();
   return 0;
}
void Enter(){
    int i;
	cout<<"�������������\n";
	cin>>PartitionNum;
	cout<<"��������̸���\n";
	cin>>ProcessNum;
	cout<<"������ÿ�������Ĵ�С����ʼ��ַ\n";
	 for (i=0;i<PartitionNum;i++){//��Ӧ���ڴ�
        cin>>FreePartition[i];
		cin>>begin[i];
    }
	
    for (i=0;i<ProcessNum;i++){//��ʼ������
        ProcessName[i]=i+65;
    }
	cout<<"������ÿ�����̵Ľ�����   ��С     ����ʱ��	  ����ʱ��\n";
    for(i=0;i<ProcessNum;i++){
		cin>>ProcessName[i];//������
        cin>>ProcessNeed[i];//���̴�С
		cin>>Processarrive[i];//���̵���ʱ��
		cin>>Processend[i];//���̽���ʱ��
    }
	//���յ���ʱ���˳��������ȶ���
    cout<<"��ȡ�������£�"<<endl;
    cout<<"��������: "<<"\t\t";
    for (i=0;i<ProcessNum;i++){
        cout<<ProcessName[i]<<"\t";
    }
    cout<<endl;
    cout<<"���̴�С�� "<<"\t\t";
    for (i=0;i<ProcessNum;i++){
        cout<<ProcessNeed[i]<<"\t";
    }
    cout<<endl;
	cout<<"���̵���ʱ�䣺 "<<"\t\t";
    for (i=0;i<ProcessNum;i++){
        cout<<Processarrive[i]<<"\t";
    }
    cout<<endl;
	cout<<"���̽���ʱ�䣺 "<<"\t\t";
    for (i=0;i<ProcessNum;i++){
        cout<<Processend[i]<<"\t";
    }
    cout<<endl;
    cout<<"��������: "<<"\t\t";
    for (i=0;i<PartitionNum;i++){
        cout<<"P"<<i+1<<"\t";
    }
    cout<<endl<<"�ڴ��С: "<<"\t\t";
    for (i=0;i<PartitionNum;i++){
        cout<<FreePartition[i]<<"\t";
    }
	cout<<endl<<"----------------------"<<endl;
}
void FirstFit()
{
	int count=0;//ͳ�ƽ��̵���ɸ���
	int t=0;//ͳ���������еĽ��̸���
	int x=PartitionNum;
	sortNeed *p;
	sortNeed *q;
	cout<<"FirstFit"<<endl;
    initial();
	int i,j;
	for(i=0;count!=ProcessNum;i++)//�����ǿռ䲻������
	{
		cout<<"��"<<i<<"ʱ��"<<"     ";
		 while(i==PCB.top().Processarrive&&PCB.empty()!=1)
		 {
			run[t++]=PCB.top();
			PCB.pop();
			cout<<"����"<<run[t-1].ProcessName<<"����"<<"     ";
			//ĳ�����̵���
		 }
		
		 for(j=0;j<t;j++)
		 {
			if(run[j].Processend==i) //���ս����ѱ�����ռ�
			{
				int sum=0;
				count++;
				cout<<"����"<<run[j].ProcessName<<"���"<<"     ";
				p=Emptylist;
				q=Fulllist;
				while(q->id+65!=run[j].ProcessName)
				{
					q=q->next;
				}
				while(1)
				{
					if(q->begin==p->begin+p->partitionSize)
					{
						p->partitionSize=p->partitionSize+q->partitionSize;
						break;
					}else if(q->begin+q->partitionSize==p->begin)
					{
						p->begin=q->begin;
						p->partitionSize=p->partitionSize+q->partitionSize;
						break;
					}else if(p->next==NULL)
					{
                          x++;
						  sortNeed *e;
						  if((e = (sortNeed *)malloc(sizeof(sortNeed)))==NULL)	//�����ѷ����
							{
							 perror("malloc");
							 exit(1);
							}
						  e->id=x-1;
						  e->begin=q->begin;
						  e->next=NULL;
						  e->partitionSize=q->partitionSize;
						  p->next=e;
						  break;
					}
					p=p->next;
				}
				sortNeed *e=Fulllist;	//�ѷ�������ɾ�����ģ��
				if(e==q)
				{
					Fulllist=Fulllist->next;
				}else
				{
					while(e->next!=q)
					{
						e=e->next;
					}
					e->next=q->next;
				}
				e=Emptylist;
				while(e!=NULL)
				{
					p=Emptylist;
					while(p!=NULL)	
					{
						if(e->begin+e->partitionSize==p->begin)
						{
							e->partitionSize=e->partitionSize+p->partitionSize;
							q=Emptylist;
							while(q->next!=p&&q->next!=NULL&&p!=Emptylist)
							{
								q=q->next;
							}
							if(p==Emptylist)
								Emptylist=Emptylist->next;
							q->next=p->next;
							break;
						}
						p=p->next;
					}
					e=e->next;
				}
			}
			if(run[j].flag==0&&(run[j].Processarrive<run[j].Processend))	//�����з��������Ƿ����㹻�ռ���������
			{
				p=Emptylist;
				while(p!=NULL)
				{
					if(p->partitionSize>=run[j].ProcessNeed)
					{
						if((q = (sortNeed *)malloc(sizeof(sortNeed)))==NULL)	//�����ѷ����
						{
							 perror("malloc");
							 exit(1);
						}
						q->id=run[j].ProcessName-65;
						q->partitionSize=run[j].ProcessNeed;
						q->begin=p->begin;
						q->next=Fulllist;
						Fulllist=q;
						p->begin =p->begin+run[j].ProcessNeed;
						p->partitionSize=p->partitionSize-run[j].ProcessNeed;	
						run[j].flag=1;
						cout<<"����"<<run[j].ProcessName<<"�õ�P"<<p->id<<"�Ŀռ�"<<"     ";
						break;
					}
					p=p->next;
				}
			 }
		 }
		 cout<<endl;
		 cout<<"��ʱ�����п��з������׵�ַ�ʹ�С"<<endl;
		 p=Emptylist;
		 while(p!=NULL)
		 {
			 cout<<"P"<<p->id<<"     "<<p->begin<<"     "<<p->partitionSize<<endl;
			 p=p->next;
		 }
		 cout<<"��ʱ�������ѷ���������׵�ַ�ʹ�С"<<endl;
		 q=Fulllist;
		 while(q!=NULL)
		 {
			 char c=q->id+65;
			 cout<<c<<"     "<<q->begin<<"     "<<q->partitionSize<<endl;
			 q=q->next;
		 }
		 cout<<endl;
	 }
}
void NextFit()
{
	cout<<"NextFit"<<endl;
	int count=0;//ͳ�ƽ��̵���ɸ���
	int t=0;//ͳ���������еĽ��̸���
	int x=PartitionNum;
	sortNeed *p;
	sortNeed *q;
    initial();
	int i,j;
	sortNeed *r=Emptylist; //���λ�ã�����һ�����￪ʼ����
	for(i=0;count!=ProcessNum;i++)//�����ǿռ䲻������
	{
		cout<<"��"<<i<<"ʱ��"<<"     ";
		 while(i==PCB.top().Processarrive&&PCB.empty()!=1)
		 {
			run[t++]=PCB.top();
			PCB.pop();
			cout<<"����"<<run[t-1].ProcessName<<"����"<<"     ";
			//ĳ�����̵���
		 }
		
		 for(j=0;j<t;j++)
		 {
			if(run[j].Processend==i) //���ս����ѱ�����ռ�
			{
				int sum=0;
				count++;
				cout<<"����"<<run[j].ProcessName<<"���"<<"     ";
				p=Emptylist;
				q=Fulllist;
				while(q->id+65!=run[j].ProcessName)
				{
					q=q->next;
				}
				while(1)
				{
					if(q->begin==p->begin+p->partitionSize)
					{
						p->partitionSize=p->partitionSize+q->partitionSize;
						break;
					}else if(q->begin+q->partitionSize==p->begin)
					{
						p->begin=q->begin;
						p->partitionSize=p->partitionSize+q->partitionSize;
						break;
					}else if(p->next==NULL)
					{
                          x++;
						  sortNeed *e;
						  if((e = (sortNeed *)malloc(sizeof(sortNeed)))==NULL)	//�����ѷ����
							{
							 perror("malloc");
							 exit(1);
							}
						  e->id=x-1;
						  e->begin=q->begin;
						  e->next=NULL;
						  e->partitionSize=q->partitionSize;
						  p->next=e;
						  break;
					}
					p=p->next;
				}
				sortNeed *e=Fulllist;	//�ѷ�������ɾ�����ģ��
				if(e==q)
				{
					Fulllist=Fulllist->next;
				}else
				{
					while(e->next!=q)
					{
						e=e->next;
					}
					e->next=q->next;
				}
				e=Emptylist;
				while(e!=NULL)
				{
					p=Emptylist;
					while(p!=NULL)	
					{
						if(e->begin+e->partitionSize==p->begin)
						{
							e->partitionSize=e->partitionSize+p->partitionSize;
							q=Emptylist;
							while(q->next!=p&&q->next!=NULL&&p!=Emptylist)
							{
								q=q->next;
							}
							if(p==Emptylist)
								Emptylist=Emptylist->next;
							q->next=p->next;
							break;
						}
						p=p->next;
					}
					e=e->next;
				}
			}
			if(run[j].flag==0&&(run[j].Processarrive<run[j].Processend))	//�����з��������Ƿ����㹻�ռ���������
			{
				p=r;
				do
				{
					if(p->partitionSize>=run[j].ProcessNeed)
					{
						if((q = (sortNeed *)malloc(sizeof(sortNeed)))==NULL)	//�����ѷ����
						{
							 perror("malloc");
							 exit(1);
						}
						q->id=run[j].ProcessName-65;
						q->partitionSize=run[j].ProcessNeed;
						q->begin=p->begin;
						q->next=Fulllist;
						Fulllist=q;
						p->begin =p->begin+run[j].ProcessNeed;
						p->partitionSize=p->partitionSize-run[j].ProcessNeed;	
						run[j].flag=1;
						cout<<"����"<<run[j].ProcessName<<"�õ�P"<<p->id<<"�Ŀռ�"<<"     ";
						break;
					}
					if(p->next!=NULL)
						p=p->next;
					else
						p->next=Emptylist;
				}while(p!=r);
				if(p->next!=NULL)
					r=p->next;
				else
					r=Emptylist;
			 }
		 }
		 cout<<endl;
		 cout<<"��ʱ�����п��з������׵�ַ�ʹ�С"<<endl;
		 p=Emptylist;
		 while(p!=NULL)
		 {
			 cout<<"P"<<p->id<<"     "<<p->begin<<"     "<<p->partitionSize<<endl;
			 p=p->next;
		 }
		 cout<<"��ʱ�������ѷ���������׵�ַ�ʹ�С"<<endl;
		 q=Fulllist;
		 while(q!=NULL)
		 {
			 char c=q->id+65;
			 cout<<c<<"     "<<q->begin<<"     "<<q->partitionSize<<endl;
			 q=q->next;
		 }
		 cout<<endl;
	 }
}
void BestFit()
{
	 cout<<"BestFit"<<endl;
	 initial();
	 sort(Empty,Empty+num1,cmp1);//�����̴�С��������
	 int count=0;//ͳ�ƽ��̵���ɸ���
	 int t=0;//ͳ���������еĽ��̸���
	 int i,j,l,k;
	 for(i=0;count!=ProcessNum;i++)//�����ǿռ䲻������
	 {
			cout<<"��"<<i<<"ʱ��"<<"     ";
			while(i==PCB.top().Processarrive&&PCB.empty()!=1)
			{
				run[t++]=PCB.top();
				PCB.pop();
				cout<<"����"<<run[t-1].ProcessName<<"����"<<"     ";
				//ĳ�����̵���
			}
			for(j=0;j<t;j++)
			{
				if(run[j].Processend==i) //���ս����ѱ�����ռ�
				{
						count++;
						cout<<"����"<<run[j].ProcessName<<"���"<<"     ";
						for(k=0;k<num2;k++)
						{
							if(Full[k].id+65==run[j].ProcessName)
								break;
						}
						for(l=0;l<num1;l++)
						{
							if(Full[k].begin==Empty[l].begin+Empty[l].partitionSize)
							{
								Empty[l].partitionSize=Empty[l].partitionSize+Full[k].partitionSize;
								sort(Empty,Empty+num1,cmp1);
								break;
							}else if(Full[k].begin+Full[k].partitionSize==Empty[l].begin)
							{
								Empty[l].begin=Full[k].begin;
								Empty[l].partitionSize=Empty[l].partitionSize+Full[k].partitionSize;
								sort(Empty,Empty+num1,cmp1);
								break;
							}else if(l==num1-1)
							{
								num1++;
								Empty[num1-1].partitionSize=Full[k].partitionSize;
								Empty[num1-1].begin=Full[k].begin;
								Empty[num1-1].next=NULL;
								Empty[num1-1].id=num1-1;
								sort(Empty,Empty+num1,cmp1);
								break;
							}
						}
						Full[k]=Full[num2-1];
						num2--;
						for(k=0;k<num1;k++)
						{
							for(l=0;l<num1;l++)
							{
								if(Empty[k].begin+Empty[k].partitionSize==Empty[l].begin)
								{
									Empty[k].partitionSize=Empty[k].partitionSize+Empty[l].partitionSize;
									Empty[l]=Empty[num1-1];
									num1--;
									break;
								}
							}
						}
				}
				if(run[j].flag==0&&(run[j].Processarrive<run[j].Processend))	//�����з��������Ƿ����㹻�ռ���������
				{
					run[j].flag=1;
					for(l=0;l<num1;l++)
					{
						if(Empty[l].partitionSize>=run[j].ProcessNeed)
						{
							Full[num2].next=NULL;
							Full[num2].id=run[j].ProcessName-65;
							Full[num2].begin=Empty[l].begin;
							Full[num2].partitionSize=run[j].ProcessNeed;
							num2++;
							Empty[l].begin=Empty[l].begin+run[j].ProcessNeed;
							Empty[l].partitionSize=Empty[l].partitionSize-run[j].ProcessNeed;
							cout<<"����"<<run[j].ProcessName<<"�õ�P"<<Empty[l].id<<"�Ŀռ�"<<"     ";
							sort(Empty,Empty+num1,cmp1);
							break;
						}
					}
				}
			}
		 cout<<endl;
		 cout<<"��ʱ�����п��з������׵�ַ�ʹ�С"<<endl;
		 for(l=0;l<num1;l++)
		 {
			 cout<<"P"<<Empty[l].id<<"     "<<Empty[l].begin<<"     "<<Empty[l].partitionSize<<endl;
		 }
		 cout<<"��ʱ�������ѷ���������׵�ַ�ʹ�С"<<endl;
		 for(l=0;l<num2;l++)
		 {
			 char c=Full[l].id+65;
			 cout<<c<<"     "<<Full[l].begin<<"     "<<Full[l].partitionSize<<endl;
		 }
		 cout<<endl;
	}
}
void WorstFit()
{
	 cout<<"WorstFit"<<endl;
	 initial();
	 sort(Empty,Empty+num1,cmp2);//�����̴�С��������
	 int count=0;//ͳ�ƽ��̵���ɸ���
	 int t=0;//ͳ���������еĽ��̸���
	 int i,j,l,k;
	 for(i=0;count!=ProcessNum;i++)//�����ǿռ䲻������
	 {
			cout<<"��"<<i<<"ʱ��"<<"     ";
			while(i==PCB.top().Processarrive&&PCB.empty()!=1)
			{
				run[t++]=PCB.top();
				PCB.pop();
				cout<<"����"<<run[t-1].ProcessName<<"����"<<"     ";
				//ĳ�����̵���
			}
			for(j=0;j<t;j++)
			{
				if(run[j].Processend==i) //���ս����ѱ�����ռ�
				{
						count++;
						cout<<"����"<<run[j].ProcessName<<"���"<<"     ";
						for(k=0;k<num2;k++)
						{
							if(Full[k].id+65==run[j].ProcessName)
								break;
						}
						for(l=0;l<num1;l++)
						{
							if(Full[k].begin==Empty[l].begin+Empty[l].partitionSize)
							{
								Empty[l].partitionSize=Empty[l].partitionSize+Full[k].partitionSize;
								sort(Empty,Empty+num1,cmp2);
								break;
							}else if(Full[k].begin+Full[k].partitionSize==Empty[l].begin)
							{
								Empty[l].begin=Full[k].begin;
								Empty[l].partitionSize=Empty[l].partitionSize+Full[k].partitionSize;
								sort(Empty,Empty+num1,cmp2);
								break;
							}else if(l==num1-1)
							{
								num1++;
								Empty[num1-1].partitionSize=Full[k].partitionSize;
								Empty[num1-1].begin=Full[k].begin;
								Empty[num1-1].next=NULL;
								Empty[num1-1].id=num1-1;
								sort(Empty,Empty+num1,cmp2);
								break;
							}
						}
						Full[k]=Full[num2-1];
						num2--;
						for(k=0;k<num1;k++)
						{
							for(l=0;l<num1;l++)
							{
								if(Empty[k].begin+Empty[k].partitionSize==Empty[l].begin)
								{
									Empty[k].partitionSize=Empty[k].partitionSize+Empty[l].partitionSize;
									Empty[l]=Empty[num1-1];
									num1--;
									break;
								}
							}
						}
				}
				if(run[j].flag==0&&(run[j].Processarrive<run[j].Processend))	//�����з��������Ƿ����㹻�ռ���������
				{
					run[j].flag=1;
					if(Empty[0].partitionSize>=run[j].ProcessNeed)
					{
						Full[num2].next=NULL;
						Full[num2].id=run[j].ProcessName-65;
						Full[num2].begin=Empty[0].begin;
						Full[num2].partitionSize=run[j].ProcessNeed;
						num2++;
						Empty[0].begin=Empty[0].begin+run[j].ProcessNeed;
						Empty[0].partitionSize=Empty[0].partitionSize-run[j].ProcessNeed;
						cout<<"����"<<run[j].ProcessName<<"�õ�P"<<Empty[0].id<<"�Ŀռ�"<<"     ";
						sort(Empty,Empty+num1,cmp2);
						break;
					}
				}
			}
		 cout<<endl;
		 cout<<"��ʱ�����п��з������׵�ַ�ʹ�С"<<endl;
		 for(l=0;l<num1;l++)
		 {
			 cout<<"P"<<Empty[l].id<<"     "<<Empty[l].begin<<"     "<<Empty[l].partitionSize<<endl;
		 }
		 cout<<"��ʱ�������ѷ���������׵�ַ�ʹ�С"<<endl;
		 for(l=0;l<num2;l++)
		 {
			 char c=Full[l].id+65;
			 cout<<c<<"     "<<Full[l].begin<<"     "<<Full[l].partitionSize<<endl;
		 }
		 cout<<endl;
	}
}
void choose_Algorithm()
{
	cout<<"��������ȷ��ѡ��1-�״���Ӧ�㷨	2-ѭ���״���Ӧ�㷨	3-�����Ӧ�㷨	4-���Ӧ�㷨	0-�˳���"<<endl;
	cin>>choose;
	cout<<endl;
	if (choose==1)
	{
		FirstFit();
		choose_Algorithm();
	}
		else if(choose==2)
		{
			NextFit();
			choose_Algorithm();
		}
		else if(choose==3){
            BestFit();
            choose_Algorithm();
		}
		else if(choose==4){
            WorstFit();
            choose_Algorithm();
		}
		else if(choose==0){
          exit(0);
		}
	else
	{
		cout<<"��������ȷ��ѡ��1-�״���Ӧ�㷨	2-ѭ���״���Ӧ�㷨	3-�����Ӧ�㷨	4-���Ӧ�㷨WF	0-�˳�"<<endl;
		cout<<"------------------------------------------------------"<<endl;
		choose_Algorithm();  //�ݹ�
	}
}
void initial(){		//��ʼ������
    int i,j;
	Emptylist=NULL;
	Fulllist=NULL;
    for (i=0;i<ProcessNum;i++){
        for (j=0;j<PartitionNum;j++){
            NameProcessToPartition[i][j] =NULL;
        }
    }
	for(i=PartitionNum-1;i>=0;i--)
	{
		sortNeed *p;
		if((p = (sortNeed *)malloc(sizeof(sortNeed)))==NULL)
		 {
			 perror("malloc");
			 exit(1);
		}
		p->id =i;
		p->begin =begin[i];
		p->partitionSize=FreePartition[i];
		p->next=Emptylist;
		Emptylist=p;
	}
	for(i=0;i<PartitionNum;i++)
	{
		Empty[i].id=i;
		Empty[i].begin=begin[i];
		Empty[i].next=NULL;
		Empty[i].partitionSize=FreePartition[i];
	}
	num1=PartitionNum;
	num2=0;
	for(i=0;i<ProcessNum;i++)
	{
		Process t;
		t.ProcessName=ProcessName[i];
		t.ProcessNeed=ProcessNeed[i];
		t.Processarrive=Processarrive[i];
		t.Processend=Processend[i];
		t.flag=0;
		PCB.push(t);
	}
}
