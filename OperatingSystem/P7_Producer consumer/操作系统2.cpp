#include <stdio.h>
#include <process.h>//_beginthread���� 
#include <windows.h>
#include <time.h>
//srand(time(NULL));
//x=rand()%6;
using namespace std;
#define N 5
//���ӻ����ö��� 
int buff[N];     
 /* ��N�������Ļ�����buf[N]����ʵ��ѭ��������� */
int front=0, rear=0;
/*
ReleaseSemaphore(mutex,1,NULL);//v����
WaitForSingleObject(mutex,INFINITE);//p����

ע�⣺��ʹ��WaitForSingleObject�ȴ��ź������ʱ��
���ź���Ϊsignal״̬����wait�����ź����Զ���1��
ֱ��ʹ��ReleaseSemaphore�ͷ��ź������ź����ſ�����
*/ 
int x;
int p_num=0;//��ʼ������Ʒ���� 
int c_num=0;//��ʼ���Ѳ�Ʒ���� 

HANDLE mutex=CreateSemaphore(NULL,1,1,NULL);//Handle����Դ�ı�ʶ������ϵͳҪ����Ͳ�����Щ��Դ������ͨ��������ҵ���Ӧ����Դ
//�ź�����ֵ1�����ֵ1    �ڶ�������Ϊ0ʱ���̻����ȴ�״̬ 
HANDLE full=CreateSemaphore(NULL,0,5,NULL);//CreateSemaphore�Ǵ����ź������� ͷ�ļ�<windows.h> 
HANDLE empty=CreateSemaphore(NULL,5,5,NULL);//��2��3��������ʼ��Դ��������󲢷����� 
void produce_item()
//������Ʒ 
{
	printf("������%d����Ʒ \n",++p_num);
}
void enter_item()
//���뻺���� 
{
	printf("���뻺������[%d]\n",rear);
	buff[rear]=1;
    rear=(rear+1)%N;
    if(rear==front)
    	printf("����������\n");
}
void remove_item()
//�ӻ�������ȡ 
{
	printf("                                        �ӻ�������ȡ[%d] \n",front);
	buff[front]=1;
    front=(front+1)%N;	
} 
void consume_item()
//���Ѳ�Ʒ
{
	printf("                                          ���Ѳ�Ʒ��%d����Ʒ\n",++c_num);
} 
/* ������ */
void producer(PVOID param)
{
    while(1){
    	Sleep(1000);//��1000���� 
        produce_item();
        WaitForSingleObject(empty,INFINITE);//p����   INFINITE�����󱻴����źź󣬺����Ż᷵�ص����߳�Ը����Զ�ȴ���ȥ������ʱ��������ֱ���ý�����ֹ����
        WaitForSingleObject(mutex,INFINITE);//p���� 
        enter_item();   /* ��һ���µ���������뻺���� */
        ReleaseSemaphore(mutex,1,NULL);//v����
        ReleaseSemaphore(full,1,NULL);//v����
    }
}
/* ������ */
void consumer(PVOID param)
{
    while(1){
    	
        	x=rand()%6+1;//1<=x<=6 
			printf("\n%d\n",x);
            Sleep(x*1000);
            WaitForSingleObject(full,INFINITE);//p���� 
            WaitForSingleObject(mutex,INFINITE);//p���� 
            remove_item(); /* �ӻ�������ȡ��һ�������� */
            ReleaseSemaphore(mutex,1,NULL);//v����
            ReleaseSemaphore(empty,1,NULL);//v����
            consume_item(); /* ����������в��������ѣ�*/
    }/* ����������в��������ѣ�*/
 }
int main(){
	srand((unsigned)time(0)); 
	_beginthread(producer, 0, NULL);
	_beginthread(consumer, 0, NULL);
	Sleep(15000);
    printf("\nend\n") ;
	return 0;
}


