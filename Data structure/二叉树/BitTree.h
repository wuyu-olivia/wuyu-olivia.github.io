#include<stdio.h>
#include<stdlib.h>
typedef  char TElemType;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree &T);
int inOrderTraverse(BiTree T);