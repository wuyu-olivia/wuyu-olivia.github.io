#include"Common.h"
#include"Linklist.h"
int main()
{
int k;
LNode *head;
head=(LinkList)malloc(sizeof(LNode));
head->next=NULL;
Student stu;
printf("\n\n=================================");
printf("\n 1. β�巨����ѧ�����" );
printf("\n 2. ���ѧ����Ϣ");
printf("\n 3. �ж�L�Ƿ�Ϊ��");
printf("\n 4. ������������ָ��ѧ��" );
printf("\n 5. ����ָ��λ�ò���ѧ����Ϣ");
printf("\n 6. ����ѧ����Ϣ�������ָ����λ��" );
printf("\n 7. ɾ��ָ��λ�õ�ѧ����¼");
printf("\n 8. ͳ�Ʊ���ѧ���ĸ���");
printf("\n 9. ���ٵ�����L");
printf("\n=================================");
do
{
printf("\n ��ѡ��(1-9): ");
scanf("%d", &k);
switch(k)
{
case 1: input(head); break; //����ѧ����Ϣ
case 2: output(head); break; //���ѧ����Ϣ
case 3: isEmpty(head); break; //�ж��Ƿ�Ϊ�ձ�
case 4: searchStu(head,stu);break;//������������ѧ����Ϣ
case 5: searchLocation(head);break;//����λ�ò���ѧ��
case 6: Insert(head,stu);break;//����ѧ����Ϣ
case 7: Delete(head,&stu);break;//ɾ��ָ��λ�õĵ�ѧ��
case 8: Listlength(head);break;//ͳ�Ʊ���ѧ������
case 9: DestroyList(head);break;//���ٱ�

} //switch
}while(k!=10);
printf("\n �ټ���\n");
return 0;
}