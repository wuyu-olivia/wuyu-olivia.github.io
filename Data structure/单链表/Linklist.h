//学生信息的定义：
typedef struct{
	char sno[10];//学号
	char sname[20];//姓名
	double score;
}Student;
//链表节点的定义
typedef struct LNode{
	Student data;//数据域
	struct LNode *next;//指针域
}LNode,*LinkList;
void input(LNode *head);
void output(LNode *head);
void isEmpty(LNode *head);
void Listlength(LNode *head);
void Insert(LNode *head,Student stu);
void searchLocation(LNode *head);
void Delete(LNode *head,Student *stu);
void searchStu(LNode *head,Student stu);
void DestroyList(LNode *head);
