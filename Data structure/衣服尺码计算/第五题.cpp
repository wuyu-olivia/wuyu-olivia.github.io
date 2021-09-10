#include<stdio.h>
double Funhat(double weight,double height);
double Funclothes(double height,double weight,int year);
double Funwaistline(int year,double weight);
int main(){
	double height,weight,hat,clothes,waistline;
	int year;
	printf("请输入身高，体重，年龄：");
	scanf("%lf%lf%d",&height,&weight,&year);
	hat=Funhat(weight,height);
	clothes=Funclothes(height,weight,year);
	waistline=Funwaistline(year,weight);
	printf("帽子的尺码为：%.2f，上衣的尺码为%.2f，腰围的尺码为%.2f\n",hat,clothes,waistline);
	return 0;
}
double Funhat(double weight,double height)	//用于计算帽子的尺码
{
	double hat;
	hat=weight/height*2.9;
	return hat;
}
double Funclothes(double height,double weight,int year)		//用于计算上衣的尺码
{
	double clothes;
	if(year<=30)
		clothes=height*weight/288;
	if(year>30)
	{
		clothes=(year-30)/10*0.125+height*weight/288;
	}
	return clothes;
}
double Funwaistline(int year,double weight)		//用于计算腰围的尺码
{
	double waistline;
	if(year<=28)
		waistline=weight/5.7;
	if(year>28)
		waistline=(year-28)/2*0.1+weight/5.7;
	return waistline;
}
