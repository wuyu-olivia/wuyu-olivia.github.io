#include<stdio.h>
#include<string.h>
int main(){
	char date[3];
	int starthour,startminute,timelength,endhour,endminute;
	double money;
	while(1){
	printf("请按照如下格式输入时间：\n星期几（如Mo,Tu,We...可不区分大小写）、开始通话的时间（以24小时格式输入）、通话时间（以分钟为单位的整数）\n");
	scanf("%s %d:%d %d",&date,&starthour,&startminute,&timelength);
	if((timelength+startminute)<60)		//先算出通话结束的时间
	{
		endhour=starthour;
		endminute=startminute+timelength;
	}
	if((timelength+startminute)>=60)
	{
		endminute=startminute+timelength;
		endhour=starthour+endminute/60;
		endminute=endminute%60;
	}
	if(stricmp(date,"mo")==0||stricmp(date,"tu")==0||stricmp(date,"we")==0||stricmp(date,"th")==0||stricmp(date,"fr")==0) //判断周几
	{
		if(starthour>=8&&starthour<18&&endhour>=8&&endhour<18)	//从上午八点后到下午六点之前
			money=timelength*0.4;
		if((starthour<8&&endhour<8)||(endhour>=18&&endhour>=18))    //从上八点前打到上八点前或从下六点后打到下六点后
			money=timelength*0.25;
		if(starthour<8&&endhour>=8)	//从上午八点前打到上午八点后
			money=(480-6*starthour-startminute)*0.25+(endhour*60+endminute-480)*0.4;
		if(starthour<18&&endhour>=18)	//从下午六点前打到下午六点后
			money=(18*60-starthour*60-startminute)*0.4+(endhour*60+endminute-18*60)*0.25;
		if(starthour>=18&&endhour>=24)	//从周五六点后打到周六
			money=(24*60-starthour*60-startminute)*0.25+(endhour*60+endminute-24*60)*0.15;
	}
	if(stricmp(date,"sa")==0||stricmp(date,"su")==0)
	{
		if(starthour>=0&&endhour<24)	//从周末打到周末
			money=timelength*0.15;
		if(endhour<32)	//从周日打到周一八点前
			money=(24*60-starthour*60-startminute)*0.15+(endhour*60+endminute-24*60)*0.25;
	}
	printf("电话费为：%.2f\n",money);
	}
	return 0;
}
