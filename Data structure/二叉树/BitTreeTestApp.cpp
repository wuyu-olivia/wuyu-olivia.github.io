#include"BitTree.h"
int main(){
	BiTree b;
	printf("����������ڵ��ֵ:\n");
	CreateBiTree(b);
	printf("��������Ľ��Ϊ��\n");
    inOrderTraverse(b);
	return 0;
}