#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct{
	int blocknum;
}Page_table;//页结构

typedef struct{
	int length;
	int baddress;
}Seg_table;//段结构




void create_page(int &n,int &size,Page_table tab[]){
	int i;
	cout<<"输入页表长度：";
	cin>>n;
	cout<<"输入每页大小(KB)：";
	cin>>size;
	cout<<"设计页表："<<endl;
	for(i=0;i<n;i++){
		cout<<"页号"<<i<<"对应的块号为：";
		cin>>tab[i].blocknum;
	}
}

void fpaging(){
	cout<<"========================================"<<endl;
	cout<<"==             分页存储管理           =="<<endl;
	cout<<"========================================"<<endl;
	Page_table tab[100];
	int n,size,lg_address,py_address,i;
	int P,W;
	char sign;
	create_page(n,size,tab);
	while(1){
		cout<<"输入逻辑地址(B)：";
		cin>>lg_address;
		P=lg_address/(size*1024);
		W=lg_address%(size*1024);
		if(P>=n)
			cout<<"越界中断！"<<endl;
		else{
			cout<<"页号为："<<P<<"  页内位移量为："<<W<<endl;
			for(i=0;i<n;i++){
				if(i==P){
					py_address=tab[i].blocknum*(size*1024)+W;
			        cout<<"物理地址为(B)："<<py_address<<" = "<<tab[i].blocknum<<" * "<<size*1024<<" + "<<W<<endl;
					break;
				}
			}
		}
		cout<<"是否继续(继续输入Y,退出输入N)？"<<endl;
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
	cout<<"请输入段表长度：";
	cin>>n;
	cout<<"输入最大段长(KB)：";
	cin>>size;
	cout<<"设计段表："<<endl;
	for(i=0;i<n;i++){
		cout<<"第"<<i<<"段的段长(B)和基址(B)分别为：";
		cin>>tab[i].length>>tab[i].baddress;
	}
}

void fsubsection(){
	cout<<"========================================"<<endl;
	cout<<"==             分段存储管理           =="<<endl;
	cout<<"========================================"<<endl;
	Seg_table tab[100];
	int n,i,lg_address,py_address,size;
	int P,W;
	char sign;
	create_seg(n,size,tab);
	while(1){
		cout<<"输入逻辑地址(B)：";
		cin>>lg_address;
		P=lg_address/(size*1024);
		W=lg_address%(size*1024);
		if(P>=n)
			cout<<"越界中断！"<<endl;
		else{
			cout<<"段号为："<<P<<"  段内地址为："<<W<<endl;
			for(i=0;i<n;i++){
				if(i==P){
					if(W>tab[i].length){
						cout<<"越界中断！"<<endl;
					    break;
					}
					py_address=tab[i].baddress+W;
			        cout<<"物理地址为(B)："<<py_address<<" = "<<tab[i].baddress<<" + "<<W<<endl;
					break;
				}
			}
		}
		cout<<"是否继续(继续输入Y,退出输入N)？"<<endl;
		getchar();
		cin>>sign;
		if(sign=='Y')
			continue;
		else
			break;
	}
}