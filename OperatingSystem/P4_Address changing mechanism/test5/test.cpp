#include"define.h"

int main(){
	int symbol;
	while(1){
		cout<<"========================================"<<endl;
		cout<<"==       ��ַ�任��������任����     =="<<endl;
	    cout<<"========================================"<<endl;
		cout<<"== 1)��ҳ�洢����      2)�ֶδ洢���� =="<<endl;
		cout<<"== 3)�˳�                             =="<<endl;
		cout<<"========================================"<<endl;
		cout<<"ѡ��任������";
		cin>>symbol;
		if(symbol==1){
			fpaging();
		}
		else if(symbol==2){
			fsubsection();
		}
		else if(symbol==3)
			break;
	}
	return 0;
}