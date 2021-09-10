#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 20	//最大可以处理二十位以内的数字的运算 
typedef struct bigint{
	char *num;	//大整数数据域 
	int sign;	//大整数符号位 
	int digit;	//大整数位数 
}BIGINT;
 
BIGINT ScanfBigInt();	//大整数的读取处理函数 
void PrintBigInt(BIGINT BigInt);//输出大整数
BIGINT AddTwoBigInt(BIGINT BigInt1,BIGINT BigInt2);
BIGINT SubTwoBigInt(BIGINT BigInt1,BIGINT BigInt2);
int CompareBigInt(BIGINT BigInt1,BIGINT BigInt2);//比较绝对值
BIGINT Sum(BIGINT BigInt1,BIGINT BigInt2);
BIGINT Sub(BIGINT BigInt1,BIGINT BigInt2);
