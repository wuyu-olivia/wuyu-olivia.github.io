#include"BitTree.h"
void CreateBiTree(BiTree &T){ //构造二叉链表表示的二叉树
	TElemType ch;
	scanf("%c",&ch);
	if(ch=='#')
		T=NULL;
	else{
		T=(BiTree)malloc(sizeof(BiTNode));
		if(!T)
			exit(-1);
		T->data=ch;
		CreateBiTree(T->lchild); //构造左子树
		CreateBiTree(T->rchild);//构造右子树
	}
}
int inOrderTraverse(BiTree T){
	if(T==NULL)
		return 1;
	if(T!=NULL){
		inOrderTraverse(T->lchild);
		printf("%5c",T->data);
		inOrderTraverse(T->rchild);
	}
}
