#include"BigNum.h"
BIGINT ScanfBigInt()//大整数的输入处理（处理结果是符号位和数据位都已就位，处理过的数是倒着的）
{
	BIGINT BigInt;
	int cnt;//大整数的长度
	int i,j,k;
	char *tempnum=NULL;
	tempnum=(char *)malloc(sizeof(char)*(N+2));//多两个空间，一个预留存负号，一个存'\0' 
	BigInt.num=(char *)malloc(sizeof(char)*(N+2));
	printf("请输入大整数：");
	scanf("%s",tempnum);
	cnt=strlen(tempnum);
	BigInt.digit=cnt;	//确定大整数的位数
	if(tempnum[0]=='-'){//确定大整数的正负 
		BigInt.sign=-1;
		tempnum[0]='0';//把负号换成字符0，后面统一处理 
	}
	else{
		BigInt.sign=1;
	}
	for(i=0,j=cnt-1;i<cnt;j--,i++){//倒序保存大整数的值 
		BigInt.num[j]=tempnum[i];
	}
	for(k=BigInt.digit-1;k>=0 && BigInt.num[k]=='0';k--);//处理可能存在的前导0 
	if(k<BigInt.digit-1){//这个数有前导0 
		BigInt.digit=k+1;
	}
	if(k==-1){//这个数是0
		BigInt.digit=1;
	}
	free(tempnum);
	return BigInt;
}
 
void PrintBigInt(BIGINT BigInt)//打印大整数  
{
	int j;
	if(BigInt.sign==-1){ //先打印符号位
		printf("-");
	}
	for(j=BigInt.digit-1;j>=0;j--){//倒序打印
		printf("%c",BigInt.num[j]);
	}
	printf("\n");
}
BIGINT AddTwoBigInt(BIGINT BigInt1,BIGINT BigInt2)//进行数据预处理，让数1大于数2且调用加函数
{
	BIGINT BigIntSum;
	char *swap;
	int flag;
	int digit,sign;
	flag=CompareBigInt(BigInt1,BigInt2);//比较两数绝对值的大小 
 
	if(flag==-1){//1 比 2 小 （绝对值）则交换两个数 
		swap=BigInt1.num; //交换数据域
		BigInt1.num=BigInt2.num;
		BigInt2.num=swap;
		 
		sign=BigInt1.sign; //交换符号位
		BigInt1.sign=BigInt2.sign;
		BigInt2.sign=sign;
		
		digit=BigInt1.digit; //交换位数
		BigInt1.digit=BigInt2.digit;
		BigInt2.digit=digit;
	}//交换完成后BigInt1 >= BigInt2（绝对值）
	BigIntSum.num=(char *)malloc(sizeof(char)*(BigInt1.digit+2));
	BigIntSum.digit=BigInt1.digit;
	
	//两数同号 
	if(BigInt1.sign==1 && BigInt2.sign==1){// + +  两个正数相加   
		BigIntSum=Sum(BigInt1,BigInt2);
		BigIntSum.sign=1;
	}
	if(BigInt1.sign==-1 && BigInt2.sign==-1){// - -  两个负数相加  
		BigIntSum=Sum(BigInt1,BigInt2);
		BigIntSum.sign=-1;
	}
	
	//两数异号 
	if(BigInt1.sign+BigInt2.sign==0){
		if(flag==0){//b2==b1 结果为零  
			BigIntSum.sign=0;
			BigIntSum.digit=1;
			BigIntSum.num[0]='0';
		}
		else{//一定是b1>=b2
			BigIntSum=Sub(BigInt1,BigInt2);
		}
	}
	return BigIntSum;
}
 BIGINT Sum(BIGINT BigInt1,BIGINT BigInt2)//求和函数 
{
	BIGINT Int;
	int t;
	int i=0,j=0,cp=0;
	int k=0;
	t=BigInt1.digit > BigInt2.digit ? BigInt1.digit : BigInt2.digit;//取位数长的一个数为Int的数值域分空间 
	Int.num=(char *)malloc(sizeof(char)*(t+2));
	Int.digit=t; 
	t=0;
	//相加操作 BigInt1.num+BigInt2.num（注意BigInt1的绝对值大于BigInt2的绝对值） 
	while(i<BigInt1.digit || j<BigInt2.digit){
		if(i<BigInt1.digit && j<BigInt2.digit){//两个都没跑完 
			k=BigInt1.num[i++]-'0'+BigInt2.num[j++]-'0'+cp;
		}
		else{
			k=BigInt1.num[i++]-'0'+cp;  //数2跑完但1没跑完
		}
		cp=k/10;
		Int.num[t++]=k%10+'0';//数字转字符 
	}
	if(cp!=0){
		Int.num[t]='1';
		Int.digit=Int.digit+1;	
	}
	return Int;
}
 
/*   
	a-b = a+(-b)
*/
BIGINT SubTwoBigInt(BIGINT BigInt1,BIGINT BigInt2)//处理数据，将减变成加
{
	BIGINT BigIntSub;
	BigInt2.sign=-BigInt2.sign;
	BigIntSub=AddTwoBigInt(BigInt1,BigInt2);
	return BigIntSub;
}
BIGINT Sub(BIGINT BigInt1,BIGINT BigInt2)//传入的数据保证 BigInt1.num > BigInt2.num（绝对值）所以结果一定为正 
{
	BIGINT Int;
	int i,k;
	int borrow=0;
	int key; 
	Int.num=(char *)malloc(sizeof(char)*(BigInt1.digit+2));	
	Int.sign=1;//返回数的结果一定为正 
	//公有的位数部分的相减操作 
	for(i=0;i<BigInt2.digit;i++){//循环的次数等于小的数的位数
		key=BigInt1.num[i]-BigInt2.num[i];
		if(key<0){//存在借位		
			Int.num[i]=10+key+'0'-borrow;
			borrow=1;
		}
		if(key>=0){//不存在借位 
			Int.num[i]=key+'0'-borrow;
			borrow=0;
		}
	}
	//下面处理BigInt1可能会多出的位数
	for(i=BigInt2.digit;i<BigInt1.digit;i++){
		Int.num[i]=BigInt1.num[i]-borrow;
		borrow=0;
	}
	//下面确定最后结果的位数 处理可能存在的前导0
	Int.digit=BigInt1.digit;
	for(k=Int.digit-1;k>=0 && Int.num[k]=='0';k--);
	if(k<Int.digit-1){//这个数有前导0 
		Int.digit=k+1;
	}
	return Int;
}
 
int CompareBigInt(BIGINT BigInt1,BIGINT BigInt2)//比较绝对值大小函数 
{
	int flag;
	int digit1,digit2;
	//digit1,digit2放到最高位上
	digit1=BigInt1.digit-1;
	digit2=BigInt2.digit-1;
	if(digit1!=digit2){//位数不同 
		return digit1>digit2 ? 1 : -1 ;
	}
	while(digit1>=0){//位数相同 
		if(BigInt1.num[digit1]>BigInt2.num[digit1]){
			flag=1;
			break;
		}
		if(BigInt1.num[digit1]<BigInt2.num[digit1]){
			flag=-1;
			break;
		}
		digit1--;
	}
	if(digit1<0)//从while的条件退出循环 两数相等 
	flag=0;
	return flag; 
}
