//ѧ����Ϣ�Ķ��壺
typedef struct{
	char sno[10];//ѧ��
	char sname[20];//����
	double score;
}Student;
//����ڵ�Ķ���
typedef struct LNode{
	Student data;//������
	struct LNode *next;//ָ����
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
