#include<stdio.h>
int main(){
	int a,b;
	char coper1;
	printf("请输入一个四则混合算式：");
	scanf("%d%c",&a,&coper1);
	while(coper1!='=')
	{
		scanf("%d",&b);
		switch(coper1){
		case '+': a=a+b;break;
		case '-': a=a-b;break;
		case '*': a=a*b;break;
		case '/': a=a/b;break;}
		scanf("%c",&coper1);
	}
	printf("%d\n",a);
	return 0;
}
