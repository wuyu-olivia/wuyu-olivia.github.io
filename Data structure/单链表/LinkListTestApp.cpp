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
printf("\n 1. 尾插法插入学生结点" );
printf("\n 2. 输出学生信息");
printf("\n 3. 判断L是否为空");
printf("\n 4. 根据姓名查找指定学生" );
printf("\n 5. 根据指定位置查找学生信息");
printf("\n 6. 给定学生信息插入表中指定的位置" );
printf("\n 7. 删除指定位置的学生记录");
printf("\n 8. 统计表中学生的个数");
printf("\n 9. 销毁单链表L");
printf("\n=================================");
do
{
printf("\n 请选择(1-9): ");
scanf("%d", &k);
switch(k)
{
case 1: input(head); break; //输入学生信息
case 2: output(head); break; //输出学生信息
case 3: isEmpty(head); break; //判断是否为空表
case 4: searchStu(head,stu);break;//根据姓名查找学生信息
case 5: searchLocation(head);break;//根据位置查找学生
case 6: Insert(head,stu);break;//插入学生信息
case 7: Delete(head,&stu);break;//删除指定位置的的学生
case 8: Listlength(head);break;//统计表中学生人数
case 9: DestroyList(head);break;//销毁表

} //switch
}while(k!=10);
printf("\n 再见！\n");
return 0;
}