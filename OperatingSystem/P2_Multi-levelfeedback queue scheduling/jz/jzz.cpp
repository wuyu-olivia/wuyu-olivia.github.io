#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;
 

typedef struct PCB
{
    int ID;                            //标识符
    int ComeTime;                    //到达时间
    int ServerTime;                    //服务时间
    int FinishTime;                    //完成时间
    int TurnoverTime;                //周转时间
    double WeightedTurnoverTime;    //带权周转时间
}PCB;
const int QueueNum = 3;//就绪队列长度     
int timeslice[QueueNum];//第一个时间片

void create(vector<PCB> &PCBList, int xlice[]);//输入时间片大小，作业信息
bool Cmpp(const PCB &p1, const PCB &p2);//比较到达时间的先后
void MFQ(vector<PCB> &PCBList, int timeslice[]);//多级反馈队列调度
void output(vector<PCB> &PCBList);//显示结果

int main()
{
    vector<PCB> PCBList; 
    create(PCBList, timeslice);
    MFQ(PCBList, timeslice);//多级反馈队列调度
    output(PCBList);//显示结果
    return 0;
} 

void create(vector<PCB> &PCBList, int xlice[])
{
	int num;
    cout << "输入3个时间片大小: "<<endl;
    for(int i=0;i<3;i++){
        cin >> timeslice[i];
    }
	cout<<"输入进程数："<<endl;
    cin>>num;
	PCB temp[20];
    for(i=0;i<num;i++){
        cout << "输入标识符   "<<"到达时间    "<<"服务时间 "<<endl;
        cin >> temp[i].ID>> temp[i].ComeTime>> temp[i].ServerTime;
        temp[i].FinishTime = 0;        //暂时存放运行了多少时间，来判断此作业是否运行结束
        PCBList.push_back(temp[i]);
    }
}
 bool Cmpp(const PCB &p1, const PCB &p2)//比较到达时间的先后
{
    return p1.ComeTime < p2.ComeTime;
}

void MFQ(vector<PCB> &PCBList, int timeslice[])//多级反馈队列调度算法
{
    sort(PCBList.begin(), PCBList.end(), Cmpp); //按到达时间排序
    vector<PCB> result;//用于保存结果
    int BeginTime = (*PCBList.begin()).ComeTime;                    //第一个作业开始时间
    queue<PCB> Ready[QueueNum];//设置3个就绪队列
    Ready[0].push(*PCBList.begin());
    PCBList.erase(PCBList.begin());
    cout<<"当前时刻:"<<BeginTime<<"   当前就绪队列:"<<0<<endl;
    cout<<"第一个进程进入就绪队列0"<<endl;
    cout<<endl;                
    while (!PCBList.empty())//进程数组不空 
    {
		int i; //了防止前面的进程运行完了，后面的进程还没到，造成死循环
        bool flag=false;
        for(i=0;i<QueueNum;++i)
        {
            if(!Ready[i].empty())//就绪队列不为空
            {
                flag = true;
                break;
            }
        }
        if(!flag)//就绪队列不为空
        {
            Ready[0].push(*PCBList.begin());
            PCBList.erase(PCBList.begin());
            BeginTime=Ready[0].front().ComeTime;
        }
 
        for(i=0;i<QueueNum;++i)
        { 
        
            if (i!=QueueNum-1)        //不是最后一个队列
            {
                while(!Ready[i].empty())    //当前队列不空
                {
                    if (!PCBList.empty()&&BeginTime>=(*PCBList.begin()).ComeTime)    //有新作业到达，加入就绪队列，转到第一队列
                    {
                        cout<<"当前时刻:"<<BeginTime<<endl;
                        cout<<"新进程"<<(*PCBList.begin()).ID<<"到达，将其放在第一队列尾部"<<endl;
                        cout<<endl;     
                        Ready[0].push(*PCBList.begin());
                        PCBList.erase(PCBList.begin());
                        i=0; 
                        continue;
                    }
 
                    if (Ready[i].front().FinishTime + timeslice[i]<Ready[i].front().ServerTime)//时间片用完没运行完,加入下一队列队尾
                    {
                        cout<<"当前时刻:"<<BeginTime+ timeslice[i]<<"   当前就绪队列:"<<i<<endl;
                        cout<<"当前进程"<<Ready[i].front().ID<<"在时间片内没有运行完，加入下一个队列尾部！"<<endl; 
                        cout<<endl; 
                        Ready[i].front().FinishTime+=timeslice[i] ;
                        Ready[i+1].push(Ready[i].front());//加入下一个队列 
                        Ready[i].pop();
                        BeginTime+= timeslice[i] ;
                    }
                    else//此作业运行完
                    {   
                        BeginTime += Ready[i].front().ServerTime-Ready[i].front().FinishTime;
                        Ready[i].front().FinishTime = BeginTime;
                        Ready[i].front().TurnoverTime = Ready[i].front().FinishTime - Ready[i].front().ComeTime;
                        Ready[i].front().WeightedTurnoverTime = (double)Ready[i].front().TurnoverTime / Ready[i].front().ServerTime;
                         cout<<"当前时刻:"<<BeginTime<<"   当前就绪队列:"<<i<<endl;
                         cout<<"当前进程"<<    Ready[i].front().ID<<"在时间片内运行完！"<<endl;
                         cout<<endl;
                        result.push_back(Ready[i].front());//从就绪队列中移除作业
                        Ready[i].pop();
                    }
                }
            }
            else
            {
                while (!Ready[i].empty())
                {
                    if (!PCBList.empty() && BeginTime >= (*PCBList.begin()).ComeTime)//有新作业到达，加入就绪队列，转到第一队列
                    {
                        cout<<"当前时刻:"<<BeginTime<<endl;
                        cout<<"新进程"<<(*PCBList.begin()).ID<<"到达，将其放在最后队列尾部"<<endl; 
                        cout<<endl;    
                        Ready[0].push(*PCBList.begin());
                        PCBList.erase(PCBList.begin());
                        i=-1;
                        break;
                    }
                    if(Ready[i].front().FinishTime + timeslice[i]  < Ready[i].front().ServerTime)//时间片用完没运行完,加入队尾
                    {   cout<<"当前时刻:"<<BeginTime+ timeslice[i]<<"   当前就绪队列:"<<i<<endl;
                        cout<<"当前进程"<<Ready[i].front().ID<<"在时间片内没有运行完，加入该队列尾部！"<<endl; 
                        cout<<endl;    
                        Ready[i].front().FinishTime += timeslice[i] ;
                        Ready[i].push(Ready[i].front());
                        Ready[i].pop();
                        BeginTime +=  timeslice[i] ;
                    }
                    else//此作业运行完
                    {
                        BeginTime+=Ready[i].front().ServerTime - Ready[i].front().FinishTime;
                        Ready[i].front().FinishTime=BeginTime;
                        Ready[i].front().TurnoverTime=Ready[i].front().FinishTime - Ready[i].front().ComeTime;
                        Ready[i].front().WeightedTurnoverTime=(double)Ready[i].front().TurnoverTime / Ready[i].front().ServerTime;
                         cout<<"当前时刻:"<<BeginTime<<"   当前就绪队列:"<<i<<endl;
                        cout<<"当前进程"<<    Ready[i].front().ID<<"在时间片内运行完！"<<endl;
                        cout<<endl;
                        result.push_back(Ready[i].front());//从就绪队列中移除作业
                        Ready[i].pop();
                    }
                }
            }
        }
    }
    //按ComeTime升序排序，便于显示结果
    PCBList=result;
    sort(PCBList.begin(),PCBList.end(),Cmpp);
}
 
//显示结果
void output(vector<PCB> &PCBList)
{
    int SumTurnoverTime=0;
    double SumWeightedTurnoverTime=0;
    cout<<"标识符     "<<"达到时间    "<<"服务时间    "<<"完成时间    "<<"周转时间    "<<"带权周转时间" <<endl;
    for (vector<PCB>::iterator it = PCBList.begin(); it < PCBList.end(); ++it){
        cout<<(*it).ID<<"          "<<(*it).ComeTime<<"            "<< (*it).ServerTime<<"            "<<(*it).FinishTime<<"            "<<(*it).TurnoverTime<<"           "<< (*it).WeightedTurnoverTime<<endl;
        SumTurnoverTime+=(*it).TurnoverTime;
        SumWeightedTurnoverTime+=(*it).WeightedTurnoverTime;
    }
    cout << "平均周转时间: " << (double)SumTurnoverTime/PCBList.size() << endl;
    cout << "平均带权周转时间: "<<SumWeightedTurnoverTime/PCBList.size() << endl;
}

