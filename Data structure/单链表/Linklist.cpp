#include "Linklist.h"
#include "Common.h"
void input(LNode *head)//尾插法输入学生信息
{
	LinkList p,r;  //p指向新结点； r指向当前链表的尾结点
    int i,n;  //n表示学生的人数
    r=head;
    printf("请输入学生的人数:");
    scanf("%d",&n);
    printf("请输入学生的信息:\n");
    for(i=1;i<=n;i++)
    { 
        p=(LinkList)malloc(sizeof(LNode));
        p->next=NULL;
		printf("学号:");
		scanf("%s",p->data.sno); 
		printf("姓名:");
		scanf("%s",p->data.sname);
		printf("成绩:");
		scanf("%lf",&p->data.score);
		r->next=p;
		r=r->next;
	}
}
void output(LNode *head)//输出学生信息
{
	LinkList p;
	p=head->next;
	if(!p)
		printf("空");
	else
	{
	  while(p)
	  {
		  printf("学号为%s 姓名为%s 成绩为%.2f\n",p->data.sno,p->data.sname,p->data.score);
	      p=p->next;
	  }
	}
}
void isEmpty(LNode *head)	//判断是否为空表
{
	LinkList p;
	p=head;
	if(p->next==NULL)
		printf("此表为空！\n");
	else
		printf("此表不为空！\n");
}
void Listlength(LNode *head)//统计学生人数
{
	int length=0;
	LinkList p;
	p=head->next;
	while(p)
	{
		p=p->next;
		length++;
	}
	printf("学生的人数为%d\n",length);
}
void Insert(LNode *head,Student stu)//插入学生信息
{
	LNode *p;
	int j=0,location;
	p=head;
	printf("请输入学生信息:学号 姓名 成绩\n");
	scanf("%s %s %lf",&stu.sno,&stu.sname,&stu.score);
	printf("请输入插入位置：");
	scanf("%d",&location);
	  while(p&&j<location-1) //遍历，使p指向location前一个位置
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
void searchLocation(LNode *head)	//查找指定位置的学生信息
{
	int j,i;
	LinkList p;
	printf("请输入需要查询的位置：");
	scanf("%d",&i);
	if(i<0)
		printf("查找失败！");
	p=head;
	j=0;
	while(p->next!=NULL&&j<i)
	{
		p=p->next;
		j=j+1;
	}
	if(i==j)//说明已经找到
		printf("学号：%s  姓名：%s   成绩%.2f\n",p->data.sno,p->data.sname,p->data.score);
	else
		printf("查找失败！");
}
void Delete(LNode *head,Student *stu)	//删除指定位置的学生信息
{
	LinkList p,r;
	int k,i;
	r=head;k=0;
	printf("请输入你要删除的位置：\n");
	scanf("%d",&i);
	while(r->next!=NULL&&k<i-1)
	{
		r=r->next;
		k++;
	}
	if(r==NULL)
	{
		printf("删除失败！\n"); 
	}
	p=r->next;
	r->next=p->next;
	*stu=p->data;
	free(p);
	printf("删除成功！\n"); 
}
void searchStu(LNode *head,Student stu)	//根据姓名查找
{
	LinkList p;
	p=head;
	printf("请输入要查找的学生姓名\n");
	scanf("%s",&stu.sname);
	while((p->next!=NULL)&&strcmp(stu.sname,p->data.sname))
	{
		p=p->next;
	}
	printf("学号 %s\t  成绩 %.2f\n",p->data.sno,p->data.score);
}
void DestroyList(LNode *head)//销毁单链表
{
	LinkList p,q; 
	p=head;
    while(p)  
    {    
        q=p->next;
		free(p);  
        p=q;  
    }
	printf("已销毁！");
}


