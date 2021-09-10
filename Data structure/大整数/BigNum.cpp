#include"BigNum.h"
BIGINT ScanfBigInt()//�����������봦���������Ƿ���λ������λ���Ѿ�λ������������ǵ��ŵģ�
{
	BIGINT BigInt;
	int cnt;//�������ĳ���
	int i,j,k;
	char *tempnum=NULL;
	tempnum=(char *)malloc(sizeof(char)*(N+2));//�������ռ䣬һ��Ԥ���渺�ţ�һ����'\0' 
	BigInt.num=(char *)malloc(sizeof(char)*(N+2));
	printf("�������������");
	scanf("%s",tempnum);
	cnt=strlen(tempnum);
	BigInt.digit=cnt;	//ȷ����������λ��
	if(tempnum[0]=='-'){//ȷ�������������� 
		BigInt.sign=-1;
		tempnum[0]='0';//�Ѹ��Ż����ַ�0������ͳһ���� 
	}
	else{
		BigInt.sign=1;
	}
	for(i=0,j=cnt-1;i<cnt;j--,i++){//���򱣴��������ֵ 
		BigInt.num[j]=tempnum[i];
	}
	for(k=BigInt.digit-1;k>=0 && BigInt.num[k]=='0';k--);//������ܴ��ڵ�ǰ��0 
	if(k<BigInt.digit-1){//�������ǰ��0 
		BigInt.digit=k+1;
	}
	if(k==-1){//�������0
		BigInt.digit=1;
	}
	free(tempnum);
	return BigInt;
}
 
void PrintBigInt(BIGINT BigInt)//��ӡ������  
{
	int j;
	if(BigInt.sign==-1){ //�ȴ�ӡ����λ
		printf("-");
	}
	for(j=BigInt.digit-1;j>=0;j--){//�����ӡ
		printf("%c",BigInt.num[j]);
	}
	printf("\n");
}
BIGINT AddTwoBigInt(BIGINT BigInt1,BIGINT BigInt2)//��������Ԥ��������1������2�ҵ��üӺ���
{
	BIGINT BigIntSum;
	char *swap;
	int flag;
	int digit,sign;
	flag=CompareBigInt(BigInt1,BigInt2);//�Ƚ���������ֵ�Ĵ�С 
 
	if(flag==-1){//1 �� 2 С ������ֵ���򽻻������� 
		swap=BigInt1.num; //����������
		BigInt1.num=BigInt2.num;
		BigInt2.num=swap;
		 
		sign=BigInt1.sign; //��������λ
		BigInt1.sign=BigInt2.sign;
		BigInt2.sign=sign;
		
		digit=BigInt1.digit; //����λ��
		BigInt1.digit=BigInt2.digit;
		BigInt2.digit=digit;
	}//������ɺ�BigInt1 >= BigInt2������ֵ��
	BigIntSum.num=(char *)malloc(sizeof(char)*(BigInt1.digit+2));
	BigIntSum.digit=BigInt1.digit;
	
	//����ͬ�� 
	if(BigInt1.sign==1 && BigInt2.sign==1){// + +  �����������   
		BigIntSum=Sum(BigInt1,BigInt2);
		BigIntSum.sign=1;
	}
	if(BigInt1.sign==-1 && BigInt2.sign==-1){// - -  �����������  
		BigIntSum=Sum(BigInt1,BigInt2);
		BigIntSum.sign=-1;
	}
	
	//������� 
	if(BigInt1.sign+BigInt2.sign==0){
		if(flag==0){//b2==b1 ���Ϊ��  
			BigIntSum.sign=0;
			BigIntSum.digit=1;
			BigIntSum.num[0]='0';
		}
		else{//һ����b1>=b2
			BigIntSum=Sub(BigInt1,BigInt2);
		}
	}
	return BigIntSum;
}
 BIGINT Sum(BIGINT BigInt1,BIGINT BigInt2)//��ͺ��� 
{
	BIGINT Int;
	int t;
	int i=0,j=0,cp=0;
	int k=0;
	t=BigInt1.digit > BigInt2.digit ? BigInt1.digit : BigInt2.digit;//ȡλ������һ����ΪInt����ֵ��ֿռ� 
	Int.num=(char *)malloc(sizeof(char)*(t+2));
	Int.digit=t; 
	t=0;
	//��Ӳ��� BigInt1.num+BigInt2.num��ע��BigInt1�ľ���ֵ����BigInt2�ľ���ֵ�� 
	while(i<BigInt1.digit || j<BigInt2.digit){
		if(i<BigInt1.digit && j<BigInt2.digit){//������û���� 
			k=BigInt1.num[i++]-'0'+BigInt2.num[j++]-'0'+cp;
		}
		else{
			k=BigInt1.num[i++]-'0'+cp;  //��2���굫1û����
		}
		cp=k/10;
		Int.num[t++]=k%10+'0';//����ת�ַ� 
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
BIGINT SubTwoBigInt(BIGINT BigInt1,BIGINT BigInt2)//�������ݣ�������ɼ�
{
	BIGINT BigIntSub;
	BigInt2.sign=-BigInt2.sign;
	BigIntSub=AddTwoBigInt(BigInt1,BigInt2);
	return BigIntSub;
}
BIGINT Sub(BIGINT BigInt1,BIGINT BigInt2)//��������ݱ�֤ BigInt1.num > BigInt2.num������ֵ�����Խ��һ��Ϊ�� 
{
	BIGINT Int;
	int i,k;
	int borrow=0;
	int key; 
	Int.num=(char *)malloc(sizeof(char)*(BigInt1.digit+2));	
	Int.sign=1;//�������Ľ��һ��Ϊ�� 
	//���е�λ�����ֵ�������� 
	for(i=0;i<BigInt2.digit;i++){//ѭ���Ĵ�������С������λ��
		key=BigInt1.num[i]-BigInt2.num[i];
		if(key<0){//���ڽ�λ		
			Int.num[i]=10+key+'0'-borrow;
			borrow=1;
		}
		if(key>=0){//�����ڽ�λ 
			Int.num[i]=key+'0'-borrow;
			borrow=0;
		}
	}
	//���洦��BigInt1���ܻ�����λ��
	for(i=BigInt2.digit;i<BigInt1.digit;i++){
		Int.num[i]=BigInt1.num[i]-borrow;
		borrow=0;
	}
	//����ȷ���������λ�� ������ܴ��ڵ�ǰ��0
	Int.digit=BigInt1.digit;
	for(k=Int.digit-1;k>=0 && Int.num[k]=='0';k--);
	if(k<Int.digit-1){//�������ǰ��0 
		Int.digit=k+1;
	}
	return Int;
}
 
int CompareBigInt(BIGINT BigInt1,BIGINT BigInt2)//�ȽϾ���ֵ��С���� 
{
	int flag;
	int digit1,digit2;
	//digit1,digit2�ŵ����λ��
	digit1=BigInt1.digit-1;
	digit2=BigInt2.digit-1;
	if(digit1!=digit2){//λ����ͬ 
		return digit1>digit2 ? 1 : -1 ;
	}
	while(digit1>=0){//λ����ͬ 
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
	if(digit1<0)//��while�������˳�ѭ�� ������� 
	flag=0;
	return flag; 
}
