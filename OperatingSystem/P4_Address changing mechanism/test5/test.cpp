#include"define.h"

int main(){
	int symbol;
	while(1){
		cout<<"========================================"<<endl;
		cout<<"==       地址变换机构及其变换方法     =="<<endl;
	    cout<<"========================================"<<endl;
		cout<<"== 1)分页存储管理      2)分段存储管理 =="<<endl;
		cout<<"== 3)退出                             =="<<endl;
		cout<<"========================================"<<endl;
		cout<<"选择变换方法：";
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