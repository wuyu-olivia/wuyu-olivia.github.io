#include "Linklist.h"
#include "Common.h"
void input(LNode *head)//β�巨����ѧ����Ϣ
{
	LinkList p,r;  //pָ���½�㣻 rָ��ǰ�����β���
    int i,n;  //n��ʾѧ��������
    r=head;
    printf("������ѧ��������:");
    scanf("%d",&n);
    printf("������ѧ������Ϣ:\n");
    for(i=1;i<=n;i++)
    { 
        p=(LinkList)malloc(sizeof(LNode));
        p->next=NULL;
		printf("ѧ��:");
		scanf("%s",p->data.sno); 
		printf("����:");
		scanf("%s",p->data.sname);
		printf("�ɼ�:");
		scanf("%lf",&p->data.score);
		r->next=p;
		r=r->next;
	}
}
void output(LNode *head)//���ѧ����Ϣ
{
	LinkList p;
	p=head->next;
	if(!p)
		printf("��");
	else
	{
	  while(p)
	  {
		  printf("ѧ��Ϊ%s ����Ϊ%s �ɼ�Ϊ%.2f\n",p->data.sno,p->data.sname,p->data.score);
	      p=p->next;
	  }
	}
}
void isEmpty(LNode *head)	//�ж��Ƿ�Ϊ�ձ�
{
	LinkList p;
	p=head;
	if(p->next==NULL)
		printf("�˱�Ϊ�գ�\n");
	else
		printf("�˱�Ϊ�գ�\n");
}
void Listlength(LNode *head)//ͳ��ѧ������
{
	int length=0;
	LinkList p;
	p=head->next;
	while(p)
	{
		p=p->next;
		length++;
	}
	printf("ѧ��������Ϊ%d\n",length);
}
void Insert(LNode *head,Student stu)//����ѧ����Ϣ
{
	LNode *p;
	int j=0,location;
	p=head;
	printf("������ѧ����Ϣ:ѧ�� ���� �ɼ�\n");
	scanf("%s %s %lf",&stu.sno,&stu.sname,&stu.score);
	printf("���������λ�ã�");
	scanf("%d",&location);
	  while(p&&j<location-1) //������ʹpָ��locationǰһ��λ��
	{
		p=p->next;
		j++;
	}
	  LNode *s;
	  s=new LNode;
	  s->data=stu;
	  s->next=p->next;
	  p->next=s;
}
void searchLocation(LNode *head)	//����ָ��λ�õ�ѧ����Ϣ
{
	int j,i;
	LinkList p;
	printf("��������Ҫ��ѯ��λ�ã�");
	scanf("%d",&i);
	if(i<0)
		printf("����ʧ�ܣ�");
	p=head;
	j=0;
	while(p->next!=NULL&&j<i)
	{
		p=p->next;
		j=j+1;
	}
	if(i==j)//˵���Ѿ��ҵ�
		printf("ѧ�ţ�%s  ������%s   �ɼ�%.2f\n",p->data.sno,p->data.sname,p->data.score);
	else
		printf("����ʧ�ܣ�");
}
void Delete(LNode *head,Student *stu)	//ɾ��ָ��λ�õ�ѧ����Ϣ
{
	LinkList p,r;
	int k,i;
	r=head;k=0;
	printf("��������Ҫɾ����λ�ã�\n");
	scanf("%d",&i);
	while(r->next!=NULL&&k<i-1)
	{
		r=r->next;
		k++;
	}
	if(r==NULL)
	{
		printf("ɾ��ʧ�ܣ�\n"); 
	}
	p=r->next;
	r->next=p->next;
	*stu=p->data;
	free(p);
	printf("ɾ���ɹ���\n"); 
}
void searchStu(LNode *head,Student stu)	//������������
{
	LinkList p;
	p=head;
	printf("������Ҫ���ҵ�ѧ������\n");
	scanf("%s",&stu.sname);
	while((p->next!=NULL)&&strcmp(stu.sname,p->data.sname))
	{
		p=p->next;
	}
	printf("ѧ�� %s\t  �ɼ� %.2f\n",p->data.sno,p->data.score);
}
void DestroyList(LNode *head)//���ٵ�����
{
	LinkList p,q; 
	p=head;
    while(p)  
    {    
        q=p->next;
		free(p);  
        p=q;  
    }
	printf("�����٣�");
}


