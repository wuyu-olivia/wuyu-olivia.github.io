#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 20	//�����Դ����ʮλ���ڵ����ֵ����� 
typedef struct bigint{
	char *num;	//������������ 
	int sign;	//����������λ 
	int digit;	//������λ�� 
}BIGINT;
 
BIGINT ScanfBigInt();	//�������Ķ�ȡ������ 
void PrintBigInt(BIGINT BigInt);//���������
BIGINT AddTwoBigInt(BIGINT BigInt1,BIGINT BigInt2);
BIGINT SubTwoBigInt(BIGINT BigInt1,BIGINT BigInt2);
int CompareBigInt(BIGINT BigInt1,BIGINT BigInt2);//�ȽϾ���ֵ
BIGINT Sum(BIGINT BigInt1,BIGINT BigInt2);
BIGINT Sub(BIGINT BigInt1,BIGINT BigInt2);
