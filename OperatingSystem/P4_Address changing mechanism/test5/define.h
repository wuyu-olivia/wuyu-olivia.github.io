#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct{
	int blocknum;
}Page_table;//ҳ�ṹ

typedef struct{
	int length;
	int baddress;
}Seg_table;//�νṹ




void create_page(int &n,int &size,Page_table tab[]){
	int i;
	cout<<"����ҳ���ȣ�";
	cin>>n;
	cout<<"����ÿҳ��С(KB)��";
	cin>>size;
	cout<<"���ҳ��"<<endl;
	for(i=0;i<n;i++){
		cout<<"ҳ��"<<i<<"��Ӧ�Ŀ��Ϊ��";
		cin>>tab[i].blocknum;
	}
}

void fpaging(){
	cout<<"========================================"<<endl;
	cout<<"==             ��ҳ�洢����           =="<<endl;
	cout<<"========================================"<<endl;
	Page_table tab[100];
	int n,size,lg_address,py_address,i;
	int P,W;
	char sign;
	create_page(n,size,tab);
	while(1){
		cout<<"�����߼���ַ(B)��";
		cin>>lg_address;
		P=lg_address/(size*1024);
		W=lg_address%(size*1024);
		if(P>=n)
			cout<<"Խ���жϣ�"<<endl;
		else{
			cout<<"ҳ��Ϊ��"<<P<<"  ҳ��λ����Ϊ��"<<W<<endl;
			for(i=0;i<n;i++){
				if(i==P){
					py_address=tab[i].blocknum*(size*1024)+W;
			        cout<<"�����ַΪ(B)��"<<py_address<<" = "<<tab[i].blocknum<<" * "<<size*1024<<" + "<<W<<endl;
					break;
				}
			}
		}
		cout<<"�Ƿ����(��������Y,�˳�����N)��"<<endl;
		getchar();
		cin>>sign;
		if(sign=='Y')
			continue;
		else
			break;
	}
	
}

void create_seg(int &n,int &size,Seg_table tab[]){
	int i;
	cout<<"������α��ȣ�";
	cin>>n;
	cout<<"�������γ�(KB)��";
	cin>>size;
	cout<<"��ƶα�"<<endl;
	for(i=0;i<n;i++){
		cout<<"��"<<i<<"�εĶγ�(B)�ͻ�ַ(B)�ֱ�Ϊ��";
		cin>>tab[i].length>>tab[i].baddress;
	}
}

void fsubsection(){
	cout<<"========================================"<<endl;
	cout<<"==             �ֶδ洢����           =="<<endl;
	cout<<"========================================"<<endl;
	Seg_table tab[100];
	int n,i,lg_address,py_address,size;
	int P,W;
	char sign;
	create_seg(n,size,tab);
	while(1){
		cout<<"�����߼���ַ(B)��";
		cin>>lg_address;
		P=lg_address/(size*1024);
		W=lg_address%(size*1024);
		if(P>=n)
			cout<<"Խ���жϣ�"<<endl;
		else{
			cout<<"�κ�Ϊ��"<<P<<"  ���ڵ�ַΪ��"<<W<<endl;
			for(i=0;i<n;i++){
				if(i==P){
					if(W>tab[i].length){
						cout<<"Խ���жϣ�"<<endl;
					    break;
					}
					py_address=tab[i].baddress+W;
			        cout<<"�����ַΪ(B)��"<<py_address<<" = "<<tab[i].baddress<<" + "<<W<<endl;
					break;
				}
			}
		}
		cout<<"�Ƿ����(��������Y,�˳�����N)��"<<endl;
		getchar();
		cin>>sign;
		if(sign=='Y')
			continue;
		else
			break;
	}
}