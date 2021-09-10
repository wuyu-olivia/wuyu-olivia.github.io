#include"BitTree.h"
int main(){
	BiTree b;
	printf("输入二叉树节点的值:\n");
	CreateBiTree(b);
	printf("中序遍历的结果为：\n");
    inOrderTraverse(b);
	return 0;
}