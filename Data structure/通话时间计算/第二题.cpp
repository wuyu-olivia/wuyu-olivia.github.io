#include<stdio.h>
#include<string.h>
int main(){
	char date[3];
	int starthour,startminute,timelength,endhour,endminute;
	double money;
	while(1){
	printf("�밴�����¸�ʽ����ʱ�䣺\n���ڼ�����Mo,Tu,We...�ɲ����ִ�Сд������ʼͨ����ʱ�䣨��24Сʱ��ʽ���룩��ͨ��ʱ�䣨�Է���Ϊ��λ��������\n");
	scanf("%s %d:%d %d",&date,&starthour,&startminute,&timelength);
	if((timelength+startminute)<60)		//�����ͨ��������ʱ��
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
	if(stricmp(date,"mo")==0||stricmp(date,"tu")==0||stricmp(date,"we")==0||stricmp(date,"th")==0||stricmp(date,"fr")==0) //�ж��ܼ�
	{
		if(starthour>=8&&starthour<18&&endhour>=8&&endhour<18)	//������˵����������֮ǰ
			money=timelength*0.4;
		if((starthour<8&&endhour<8)||(endhour>=18&&endhour>=18))    //���ϰ˵�ǰ���ϰ˵�ǰ������������������
			money=timelength*0.25;
		if(starthour<8&&endhour>=8)	//������˵�ǰ������˵��
			money=(480-6*starthour-startminute)*0.25+(endhour*60+endminute-480)*0.4;
		if(starthour<18&&endhour>=18)	//����������ǰ�����������
			money=(18*60-starthour*60-startminute)*0.4+(endhour*60+endminute-18*60)*0.25;
		if(starthour>=18&&endhour>=24)	//����������������
			money=(24*60-starthour*60-startminute)*0.25+(endhour*60+endminute-24*60)*0.15;
	}
	if(stricmp(date,"sa")==0||stricmp(date,"su")==0)
	{
		if(starthour>=0&&endhour<24)	//����ĩ����ĩ
			money=timelength*0.15;
		if(endhour<32)	//�����մ���һ�˵�ǰ
			money=(24*60-starthour*60-startminute)*0.15+(endhour*60+endminute-24*60)*0.25;
	}
	printf("�绰��Ϊ��%.2f\n",money);
	}
	return 0;
}
