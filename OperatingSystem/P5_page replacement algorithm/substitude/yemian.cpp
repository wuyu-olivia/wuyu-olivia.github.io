#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
using namespace std;
/*
�������� 
------------------------------------------- 
3
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1 #
------------------------------------------- 
*/
int GetDistance(int currentPageID,int page);//����ҳ���Ż�ȡ��������ڵ�ҳ�����δʹ�õ�ʱ�䣨�ĸ����뵱ǰpageID��Զ��
class BLOCK{
public:
	int blockNum;	//���������
	int pageNum;	//������е�ҳ������ 
	int *pageID;	//ҳ��ţ���СΪblockNum��
	int *stayTime;	//ҳ����������е�ͣ��ʱ�䣨�������ID��Ӧ��
	BLOCK(int num)
	{
		int i;
		pageNum=0;
		blockNum=num;
		pageID=new int[num];
		stayTime=new int[num];
		for(i=0;i<num;i++)
		{
			pageID[i]=-1;	//��ʼ��ÿ���������û�з��ã�ҳ��ű�ʾΪ-1
			stayTime[i]=0;	//��ʼ��ͣ��ʱ��Ϊ0
		}
	}
	void Init()
	{
		int i;
		int num=blockNum;
		pageNum=0;
		pageID=new int[num];
		stayTime=new int[num];
		for(i=0;i<num;i++)
		{
			pageID[i]=-1;	//��ʼ��ÿ���������û�з��ã�ҳ��ű�ʾΪ-1
			stayTime[i]=0;	//��ʼ��ͣ��ʱ��Ϊ0
		}
	}
	void ShowPage()
	{
		int i;
		for(i=0;i<blockNum;i++)
		cout<<"Page["<<i<<"]: "<<pageID[i]<<endl;
	}
	void ShowStayTime()
	{
		int i;
		for(i=0;i<blockNum;i++)
		cout<<"Stay["<<i<<"]: "<<stayTime[i]<<endl;
	}
	int GetLongestStay()	//��ȡ���������ͣ��ʱ�����ҳ������������ 
	{
		int i;
		int max_pos=0;
		for(i=0;i<pageNum;i++)
		if(stayTime[max_pos]<stayTime[i])
		max_pos=i;
		return max_pos;
	}
	int GetRencentNotUse(int currentPageID)	//��ȡ���������������δʹ�õ�ҳ���� 
	{
		//Ĭ��currentPageIDһ�����ڵ���BLOCKNUM
		int i;
		int DestID=0;
		for(i=0;i<blockNum;i++)
		{
			if(GetDistance(currentPageID,pageID[i])>GetDistance(currentPageID,pageID[DestID]))
			DestID=i;
		}
		return DestID;
	}
};	//��������ݽṹ����
 
//-----------------------ȫ�ֱ���-------------------------
int BLOCKNUM;		//�������
int *PVS;			//PageVisitSequenceҳ���������
int PVS_NUM;		//ҳ��������г���
int **replaceTable;	//ҳ���û����ά�ȣ�BLOCKNUM*PVS_NUM��
int *replaceArray;	//ҳ���û���־���飨��СΪ����ҳ��Ĵ������洢ÿ�η����Ƿ����ҳ���û��� 
int *lackArray;		//ȱҳ�жϱ�־���飨��СΪ����ҳ��Ĵ������洢ÿ�η����Ƿ����ȱҳ�жϣ� 
//-----------------------��������-------------------------
void showMenu();							//�˵���ʾ
void InputAndInit();						//��������ͱ�����ʼ��
void ReplaceFIFO(BLOCK block);				//FIFOҳ���û��㷨
int FindPage(int pageID,BLOCK block);		//ҳ����ң�����ҳ������������в���ҳ���Ƿ���ڣ� 
void ShowReplaceTable();					//�û�������
void ReplaceLRU(BLOCK block);				//LRUҳ���û��㷨
void InfoDisplay();							//��ʼ����Ϣ��ʾ 
int GetReplaceTimes();						//��ȡҳ���û��ܴ���
int GetLackTimes();							//��ȡȱҳ�ж��ܴ��� 
//-----------------------��������-------------------------
int main()
{
	int select;
	int i;
	InputAndInit();
	BLOCK block(BLOCKNUM);	//��������飨ע����������ڱ��������ݳ�ʼ���󣬷���BLOCKNUMδ֪�� 
	cout<<"��Ϣ��ʼ����ɣ�"<<endl<<endl;
	showMenu();
	cout<<"������Ҫ���еĲ�����"<<endl;
	cin>>select;
	while(1)
	{
		switch(select)
		{
			case 1:
				InfoDisplay();
				cout<<endl;
			break;
			case 2:
				ReplaceFIFO(block);
				cout<<"|=================> FIFOҳ������㷨����ִ��......"<<endl;
				ShowReplaceTable();
				cout<<"ҳ���û�����Ϊ��"<<GetReplaceTimes()<<endl;
				cout<<"ȱҳ�жϴ���Ϊ��"<<GetLackTimes()<<endl;
				cout<<endl;
				cout<<endl;
			break;
			case 3:
				ReplaceLRU(block);
				cout<<"|=================> LRUҳ������㷨����ִ��......"<<endl;
				ShowReplaceTable();
				cout<<"ҳ���û�����Ϊ��"<<GetReplaceTimes()<<endl;
				cout<<"ȱҳ�жϴ���Ϊ��"<<GetLackTimes()<<endl;
				cout<<endl;
				cout<<endl;
			break;
			case 0:
			return 0;
			default:
				cout<<"������������������..."<<endl;
				cout<<endl;
			break; 
		}
		//------��ֹҳ���û���ȱҳ�����������------------- 
		for(i=0;i<PVS_NUM;i++)
		{
			replaceArray[i]=0; 					//ҳ���û���־�����ʼ��Ϊ0 
			lackArray[i]=0; 					//ȱҳ�жϱ�־�����ʼ��Ϊ0 
		} 
		showMenu();
		cout<<"������Ҫ���еĲ������˳�������0��..."<<endl;
		cin>>select;
	}
	
	delete[] PVS;
	delete[] replaceArray;
	delete[] lackArray;
	for(i=0;i<BLOCKNUM;i++)
	delete[] replaceTable[i];
	delete[] replaceTable;
	return 0;
}
//----------------------FIFOҳ���û��㷨--------------------------
void ReplaceFIFO(BLOCK block)			//FIFOҳ���û��㷨
{
	int i,j;
	for(i=0;i<BLOCKNUM;i++)
		for(j=0;j<PVS_NUM;j++)
			replaceTable[i][j]=0;
	block.Init();
	int replacePosition;				//���û�λ�� 
	for(i=0;i<PVS_NUM;i++)				//���ζ�ҳ��������е�ÿһ��ҳ��PVS[i]���в���
	{
		for(j=0;j<block.pageNum;j++)
		block.stayTime[j]++;			//ÿѭ��һ�Σ�����飨0~pageNum��ͣ��ʱ������ 
		if(block.pageNum<block.blockNum)
		{
			if(!FindPage(PVS[i],block))	//��ҳ��PVS[i]������
			{
				lackArray[i]=1;			//���ڷ���ҳ�治�������ҳ���ж� 
				block.pageID[block.pageNum]=PVS[i];
				block.pageNum++;
			}
		}
		else							//FIFO�㷨���û�ͣ��ʱ�����ҳ�����������λ�ã� 
		{
//			��ҳ���Ѵ��ڵ�����������������Ӧ����ҳ�治���ڵ������Ӧ����if(ҳ����������в�����)���жϣ� 
			if(!FindPage(PVS[i],block))	//��ҳ��PVS[i]������
			{
				replaceArray[i]=1;		//���ڷ���ҳ�治�������޿�����������ҳ���û�
				lackArray[i]=1;			//���ڷ���ҳ�治�������ҳ���ж� 
				replacePosition=block.GetLongestStay();
				block.pageID[replacePosition]=PVS[i];	//ѡ��ͣ��ʱ�����ҳ���û�
				block.stayTime[replacePosition]=0;		//�û��󣬸�ҳ����������λ��ͣ��ʱ������ 
			}
		}
		for(j=0;j<BLOCKNUM;j++)
		replaceTable[j][i]=block.pageID[j];	//������һ��ҳ���Ľ�����������У�replaceTable��
	}
}
int FindPage(int pageID,BLOCK block)		//ҳ����ң�����ҳ�������Դ��ҳ�������飨����ΪpageNum���в���ҳ���Ƿ���ڣ� 
{
	int i=0;
	for(i=0;i<block.pageNum;i++)
	if(block.pageID[i]==pageID)
	break;
	return !(i==block.pageNum);				//��ҳ����ڣ��򷵻�1�����򷵻�0 
}
//----------------------LRUҳ���û��㷨--------------------------
void ReplaceLRU(BLOCK block)			//LRUҳ���û��㷨
{
	int i,j;
	for(i=0;i<BLOCKNUM;i++)
		for(j=0;j<PVS_NUM;j++)
			replaceTable[i][j]=0;
	block.Init();
	int replacePosition;				//���û�λ�� 
	for(i=0;i<PVS_NUM;i++)				//���ζ�ҳ��������е�ÿһ��ҳ��PVS[i]���в���
	{
		for(j=0;j<block.pageNum;j++)
		block.stayTime[j]++;			//ÿѭ��һ�Σ�����飨0~pageNum��ͣ��ʱ������ 
		if(block.pageNum<block.blockNum)
		{
			if(!FindPage(PVS[i],block))	//��ҳ��PVS[i]������
			{
				lackArray[i]=1;			//���ڷ���ҳ�治�������ҳ���ж� 
				block.pageID[block.pageNum]=PVS[i];
				block.pageNum++;
			}
		}
		else							//FIFO�㷨���û�ͣ��ʱ�����ҳ�����������λ�ã� 
		{
//			��ҳ���Ѵ��ڵ�����������������Ӧ����ҳ�治���ڵ������Ӧ����if(ҳ����������в�����)���жϣ�
			if(!FindPage(PVS[i],block))	//��ҳ��PVS[i]������
			{
				replaceArray[i]=1;		//���ڷ���ҳ�治�������޿�����������ҳ���û�
				lackArray[i]=1;			//���ڷ���ҳ�治�������ҳ���ж� 
				replacePosition=block.GetRencentNotUse(i);
				block.pageID[replacePosition]=PVS[i];	//ѡ��ͣ��ʱ�����ҳ���û�
				block.stayTime[replacePosition]=0;		//�û��󣬸�ҳ����������λ��ͣ��ʱ������ 
			}
		}
		for(j=0;j<BLOCKNUM;j++)
		replaceTable[j][i]=block.pageID[j];	//������һ��ҳ���Ľ�����������У�replaceTable��
	}
}
//----------------------OTHRES--------------------------
void showMenu()						//�˵���ʾ 
{
	cout<<"\t\t|----------------------------MENU-------------------------------|"<<endl;
	cout<<"\t\t|\t1. ��ʼ����Ϣ��ʾ                                       |"<<endl;
	cout<<"\t\t|\t2. FIFOҳ���û��㷨                                     |"<<endl;
	cout<<"\t\t|\t3. LRUҳ���û��㷨                                      |"<<endl;
	cout<<"\t\t|\t0. �˳�����                                             |"<<endl;
	cout<<"\t\t|---------------------------------------------------------------|"<<endl;
}
void InputAndInit()					//��������ͱ�����ʼ�� 
{
	int i=0;
	int j=0;
	char PVS_char[100];
	cout<<"�������������..."<<endl;
	cin>>BLOCKNUM;
	cout<<"����������ҳ��������У�����0~9��ÿ������֮���пո���#������..."<<endl;
	cin>>PVS_char[i];
	getchar();
	while(PVS_char[i]!='#')
	{
		i++;
		cin>>PVS_char[i];
		getchar();
	}
	PVS_char[i]='\0';					//�����ַ�����ֹ��
	PVS_NUM=i;
	PVS=new int[PVS_NUM];
	for(i=0;i<PVS_NUM;i++)
	PVS[i]=PVS_char[i]-'0';				//�ַ�ת���֣�ҳ��ţ�
	
	replaceArray=new int[PVS_NUM];
	lackArray=new int[PVS_NUM];
	for(i=0;i<PVS_NUM;i++)
	{
		replaceArray[i]=0; 					//ҳ���û���־�����ʼ��Ϊ0 
		lackArray[i]=0; 					//ȱҳ�жϱ�־�����ʼ��Ϊ0 
	} 
	replaceTable=new int*[BLOCKNUM];	//ҳ���û����ʼ��
	for(i=0;i<BLOCKNUM;i++)
		replaceTable[i]=new int[PVS_NUM];
}
void ShowReplaceTable()						//�û������� 
{
	int i,j;
	cout<<"ҳ���û���������ͼ��ʾ"<<endl<<endl;
	cout<<setw(PVS_NUM*3+14)<<setfill('-')<<"-"<<endl;
	cout.fill(' ');
	cout<<"ҳ��������� ";
	for(i=0;i<PVS_NUM;i++)
	cout<<" "<<setw(2)<<PVS[i];
	cout<<endl;
	cout<<setw(PVS_NUM*3+14)<<setfill('-')<<"-"<<endl;
	cout.fill(' ');
	cout<<"ҳ���û����� ";
	for(i=0;i<BLOCKNUM;i++)
	{
		if(i>0)
		cout<<"\t     ";
		for(j=0;j<PVS_NUM;j++)
		{
			if(replaceTable[i][j]!=-1)
			cout<<"|"<<setw(2)<<replaceTable[i][j];
			else cout<<"|"<<setw(2)<<" ";	//-1ʱ������������ҳ�棬�����
		}
		cout<<"|"<<endl;
	}
	cout<<setw(PVS_NUM*3+14)<<setfill('-')<<"-"<<endl;
	cout<<"ҳ���û���־ ";
	cout.fill(' ');
	for(i=0;i<PVS_NUM;i++)
		cout<<" "<<setw(2)<<replaceArray[i];
	cout<<endl;
	cout<<setw(PVS_NUM*3+14)<<setfill('-')<<"-"<<endl;
	cout<<"ҳ���жϱ�־ ";
	cout.fill(' ');
	for(i=0;i<PVS_NUM;i++)
		cout<<" "<<setw(2)<<lackArray[i];
	cout<<endl;
	cout<<setw(PVS_NUM*3+14)<<setfill('-')<<"-"<<endl<<endl;
}
int GetDistance(int currentPageID,int page)	//����ҳ���Ż�ȡ��������ڵ�ҳ�����δʹ�õ�ʱ�䣨�ĸ����뵱ǰpageID��Զ��
{
	int distance=0;
	int i;
	for(i=currentPageID-1;i>=0;i--)
	if(PVS[i]!=page)
	distance++;
	else break;
	return distance;
}
void InfoDisplay()							//��ʼ����Ϣ��ʾ 
{
	int i;
	cout<<"��ҳ���û�ģ���㷨��: "<<endl;
	cout<<"�������Ϊ�� "<<BLOCKNUM<<endl;
	cout<<"ҳ���������Ϊ��";
	for(i=0;i<PVS_NUM;i++)
	cout<<PVS[i]<<" ";
	cout<<endl;
}
int GetReplaceTimes()						//��ȡҳ���û��ܴ��� 
{
	int sum=0;
	int i;
	for(i=0;i<PVS_NUM;i++)
	sum+=replaceArray[i];
	return sum;
}
int GetLackTimes()							//��ȡҳ���ж��ܴ��� 
{
	int sum=0;
	int i;
	for(i=0;i<PVS_NUM;i++)
	sum+=lackArray[i];
	return sum;
}
