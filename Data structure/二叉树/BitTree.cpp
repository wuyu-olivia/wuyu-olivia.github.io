#include"BitTree.h"
void CreateBiTree(BiTree &T){ //������������ʾ�Ķ�����
	TElemType ch;
	scanf("%c",&ch);
	if(ch=='#')
		T=NULL;
	else{
		T=(BiTree)malloc(sizeof(BiTNode));
		if(!T)
			exit(-1);
		T->data=ch;
		CreateBiTree(T->lchild); //����������
		CreateBiTree(T->rchild);//����������
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
