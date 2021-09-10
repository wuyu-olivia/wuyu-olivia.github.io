#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;
 

typedef struct PCB
{
    int ID;                            //��ʶ��
    int ComeTime;                    //����ʱ��
    int ServerTime;                    //����ʱ��
    int FinishTime;                    //���ʱ��
    int TurnoverTime;                //��תʱ��
    double WeightedTurnoverTime;    //��Ȩ��תʱ��
}PCB;
const int QueueNum = 3;//�������г���     
int timeslice[QueueNum];//��һ��ʱ��Ƭ

void create(vector<PCB> &PCBList, int xlice[]);//����ʱ��Ƭ��С����ҵ��Ϣ
bool Cmpp(const PCB &p1, const PCB &p2);//�Ƚϵ���ʱ����Ⱥ�
void MFQ(vector<PCB> &PCBList, int timeslice[]);//�༶�������е���
void output(vector<PCB> &PCBList);//��ʾ���

int main()
{
    vector<PCB> PCBList; 
    create(PCBList, timeslice);
    MFQ(PCBList, timeslice);//�༶�������е���
    output(PCBList);//��ʾ���
    return 0;
} 

void create(vector<PCB> &PCBList, int xlice[])
{
	int num;
    cout << "����3��ʱ��Ƭ��С: "<<endl;
    for(int i=0;i<3;i++){
        cin >> timeslice[i];
    }
	cout<<"�����������"<<endl;
    cin>>num;
	PCB temp[20];
    for(i=0;i<num;i++){
        cout << "�����ʶ��   "<<"����ʱ��    "<<"����ʱ�� "<<endl;
        cin >> temp[i].ID>> temp[i].ComeTime>> temp[i].ServerTime;
        temp[i].FinishTime = 0;        //��ʱ��������˶���ʱ�䣬���жϴ���ҵ�Ƿ����н���
        PCBList.push_back(temp[i]);
    }
}
 bool Cmpp(const PCB &p1, const PCB &p2)//�Ƚϵ���ʱ����Ⱥ�
{
    return p1.ComeTime < p2.ComeTime;
}

void MFQ(vector<PCB> &PCBList, int timeslice[])//�༶�������е����㷨
{
    sort(PCBList.begin(), PCBList.end(), Cmpp); //������ʱ������
    vector<PCB> result;//���ڱ�����
    int BeginTime = (*PCBList.begin()).ComeTime;                    //��һ����ҵ��ʼʱ��
    queue<PCB> Ready[QueueNum];//����3����������
    Ready[0].push(*PCBList.begin());
    PCBList.erase(PCBList.begin());
    cout<<"��ǰʱ��:"<<BeginTime<<"   ��ǰ��������:"<<0<<endl;
    cout<<"��һ�����̽����������0"<<endl;
    cout<<endl;                
    while (!PCBList.empty())//�������鲻�� 
    {
		int i; //�˷�ֹǰ��Ľ����������ˣ�����Ľ��̻�û���������ѭ��
        bool flag=false;
        for(i=0;i<QueueNum;++i)
        {
            if(!Ready[i].empty())//�������в�Ϊ��
            {
                flag = true;
                break;
            }
        }
        if(!flag)//�������в�Ϊ��
        {
            Ready[0].push(*PCBList.begin());
            PCBList.erase(PCBList.begin());
            BeginTime=Ready[0].front().ComeTime;
        }
 
        for(i=0;i<QueueNum;++i)
        { 
        
            if (i!=QueueNum-1)        //�������һ������
            {
                while(!Ready[i].empty())    //��ǰ���в���
                {
                    if (!PCBList.empty()&&BeginTime>=(*PCBList.begin()).ComeTime)    //������ҵ�������������У�ת����һ����
                    {
                        cout<<"��ǰʱ��:"<<BeginTime<<endl;
                        cout<<"�½���"<<(*PCBList.begin()).ID<<"���������ڵ�һ����β��"<<endl;
                        cout<<endl;     
                        Ready[0].push(*PCBList.begin());
                        PCBList.erase(PCBList.begin());
                        i=0; 
                        continue;
                    }
 
                    if (Ready[i].front().FinishTime + timeslice[i]<Ready[i].front().ServerTime)//ʱ��Ƭ����û������,������һ���ж�β
                    {
                        cout<<"��ǰʱ��:"<<BeginTime+ timeslice[i]<<"   ��ǰ��������:"<<i<<endl;
                        cout<<"��ǰ����"<<Ready[i].front().ID<<"��ʱ��Ƭ��û�������꣬������һ������β����"<<endl; 
                        cout<<endl; 
                        Ready[i].front().FinishTime+=timeslice[i] ;
                        Ready[i+1].push(Ready[i].front());//������һ������ 
                        Ready[i].pop();
                        BeginTime+= timeslice[i] ;
                    }
                    else//����ҵ������
                    {   
                        BeginTime += Ready[i].front().ServerTime-Ready[i].front().FinishTime;
                        Ready[i].front().FinishTime = BeginTime;
                        Ready[i].front().TurnoverTime = Ready[i].front().FinishTime - Ready[i].front().ComeTime;
                        Ready[i].front().WeightedTurnoverTime = (double)Ready[i].front().TurnoverTime / Ready[i].front().ServerTime;
                         cout<<"��ǰʱ��:"<<BeginTime<<"   ��ǰ��������:"<<i<<endl;
                         cout<<"��ǰ����"<<    Ready[i].front().ID<<"��ʱ��Ƭ�������꣡"<<endl;
                         cout<<endl;
                        result.push_back(Ready[i].front());//�Ӿ����������Ƴ���ҵ
                        Ready[i].pop();
                    }
                }
            }
            else
            {
                while (!Ready[i].empty())
                {
                    if (!PCBList.empty() && BeginTime >= (*PCBList.begin()).ComeTime)//������ҵ�������������У�ת����һ����
                    {
                        cout<<"��ǰʱ��:"<<BeginTime<<endl;
                        cout<<"�½���"<<(*PCBList.begin()).ID<<"����������������β��"<<endl; 
                        cout<<endl;    
                        Ready[0].push(*PCBList.begin());
                        PCBList.erase(PCBList.begin());
                        i=-1;
                        break;
                    }
                    if(Ready[i].front().FinishTime + timeslice[i]  < Ready[i].front().ServerTime)//ʱ��Ƭ����û������,�����β
                    {   cout<<"��ǰʱ��:"<<BeginTime+ timeslice[i]<<"   ��ǰ��������:"<<i<<endl;
                        cout<<"��ǰ����"<<Ready[i].front().ID<<"��ʱ��Ƭ��û�������꣬����ö���β����"<<endl; 
                        cout<<endl;    
                        Ready[i].front().FinishTime += timeslice[i] ;
                        Ready[i].push(Ready[i].front());
                        Ready[i].pop();
                        BeginTime +=  timeslice[i] ;
                    }
                    else//����ҵ������
                    {
                        BeginTime+=Ready[i].front().ServerTime - Ready[i].front().FinishTime;
                        Ready[i].front().FinishTime=BeginTime;
                        Ready[i].front().TurnoverTime=Ready[i].front().FinishTime - Ready[i].front().ComeTime;
                        Ready[i].front().WeightedTurnoverTime=(double)Ready[i].front().TurnoverTime / Ready[i].front().ServerTime;
                         cout<<"��ǰʱ��:"<<BeginTime<<"   ��ǰ��������:"<<i<<endl;
                        cout<<"��ǰ����"<<    Ready[i].front().ID<<"��ʱ��Ƭ�������꣡"<<endl;
                        cout<<endl;
                        result.push_back(Ready[i].front());//�Ӿ����������Ƴ���ҵ
                        Ready[i].pop();
                    }
                }
            }
        }
    }
    //��ComeTime�������򣬱�����ʾ���
    PCBList=result;
    sort(PCBList.begin(),PCBList.end(),Cmpp);
}
 
//��ʾ���
void output(vector<PCB> &PCBList)
{
    int SumTurnoverTime=0;
    double SumWeightedTurnoverTime=0;
    cout<<"��ʶ��     "<<"�ﵽʱ��    "<<"����ʱ��    "<<"���ʱ��    "<<"��תʱ��    "<<"��Ȩ��תʱ��" <<endl;
    for (vector<PCB>::iterator it = PCBList.begin(); it < PCBList.end(); ++it){
        cout<<(*it).ID<<"          "<<(*it).ComeTime<<"            "<< (*it).ServerTime<<"            "<<(*it).FinishTime<<"            "<<(*it).TurnoverTime<<"           "<< (*it).WeightedTurnoverTime<<endl;
        SumTurnoverTime+=(*it).TurnoverTime;
        SumWeightedTurnoverTime+=(*it).WeightedTurnoverTime;
    }
    cout << "ƽ����תʱ��: " << (double)SumTurnoverTime/PCBList.size() << endl;
    cout << "ƽ����Ȩ��תʱ��: "<<SumWeightedTurnoverTime/PCBList.size() << endl;
}

