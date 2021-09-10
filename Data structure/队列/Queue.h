#define MAXQSIZE 100
#define OVERFLOW 0
typedef int QElemType;
typedef int Status;

typedef struct
{
	QElemType *base;
	int front;
	int rear;
} LinkQueue; //队列类型

Status InitQueue(LinkQueue &Q);
Status EnQueue(LinkQueue &Q,QElemType e);
Status Output(LinkQueue &Q);
Status DeQueue(LinkQueue &Q,QElemType &e);
