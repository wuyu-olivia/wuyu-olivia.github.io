#include "Common.h.h"
#include "Sqlist.h.h"
void main()//������������������������ͼ���������
{
int k;
SqList l;
printf("\n\n=================================");
printf("\n 1. ����˳���" );//
printf("\n 2.������˳��� Lͷ��������������Ԫ��");//
printf("\n 3.������˳��� Lβ��������������Ԫ��");//
printf("\n 4. ���˳���");//
printf("\n 5.���˳���L�ĳ���");
printf("\n 6.�ж�˳���L�Ƿ�Ϊ��");
printf("\n 7.���ָ������Ԫ�أ��� 76����λ��");
printf("\n 8.�ڵ� 4 ��λ���ϲ���һ��������Ԫ��");//
printf("\n 9.ɾ��˳���ָ��Ԫ��");//
printf("\n 10.ɾ��˳��� L ����ָ��Ԫ��");//
printf("\n 11.���˳�� L �ĵ� 3 ������Ԫ��");
printf("\n 12.����˳���");//
printf("\n 13. ������������");
printf("\n=================================");
do
{
printf("\n ��ѡ��(1-11): ");
scanf("%d", &k);
switch(k)
{
        
		
		case 1://����˳���
			InitSeqlist(&Seq);
			break;
		case 4://���˳���
			PrintSeqlist(&Seq);
			break;
		case 3://β����������Ԫ��
			printf("������һ��Ҫ���������");
			scanf("%d",&x);
			PushBack(&Seq,x);
		    break;
		case 2://��ͷ������Ԫ��
			printf("������һ��Ҫ���������");
			scanf("%d",&x);
			PushFront(&Seq,x);
			break;
		case 8: //��˳���ָ��λ�ò���Ԫ��
			printf("������һ��Ҫ���������");
			scanf("%d",&x);
			printf("��ѡ��Ҫ�����λ�ã�");
			scanf("%d",&pos);
			Insert(&Seq,pos,x);
			break;
		case 9: //ɾ��ָ��Ԫ��
			printf("������Ҫɾ����Ԫ�أ�");
			scanf("%d",&x);
			Remove(&Seq,x); 
			break;
		case 10://ɾ������ָ��Ԫ��
			printf("������Ҫɾ����Ԫ�أ�");
			scanf("%d",&x);
			RemoveAll(&Seq,x);  
			break;
		case 13://
			printf("������Ҫ���ҵ�����");
			scanf("%d",&x);
			ret=BinarySearch(&Seq,x);
			if(ret!=-1)
			{
				if(pSeq->data[ret]==x)
				{
					printf("%d\n",x);
					printf("���ҳɹ���\n");
				}
				else
					printf("����ʧ��!\n");
			}
			if(ret==-1)
			{
				printf("����ʧ�ܣ�\n");
			}
			break;
		case 12://����˳���
			DestroySeqlist(&Seq);
			break;
		case 9://��ָ��λ��ɾ����Ԫ��
			printf("������Ҫɾ��Ԫ�ص�λ�ã�");
			scanf("%d",x);
			Erase(&Seq,x);
} //switch
}while(k!=13);
printf("\n �ټ���\n");
}//main