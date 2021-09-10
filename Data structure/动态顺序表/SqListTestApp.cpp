#include "Common.h.h"
#include "Sqlist.h.h"
void main()//主函数，测试上述定义的类型及基本操作
{
int k;
SqList l;
printf("\n\n=================================");
printf("\n 1. 建立顺序表" );//
printf("\n 2.在上述顺序表 L头部插入若干数据元素");//
printf("\n 3.在上述顺序表 L尾部插入若干数据元素");//
printf("\n 4. 输出顺序表");//
printf("\n 5.输出顺序表L的长度");
printf("\n 6.判断顺序表L是否为空");
printf("\n 7.输出指定数据元素（如 76）的位置");
printf("\n 8.在第 4 个位置上插入一个新数据元素");//
printf("\n 9.删除顺序表指定元素");//
printf("\n 10.删除顺序表 L 所有指定元素");//
printf("\n 11.输出顺序 L 的第 3 个数据元素");
printf("\n 12.销毁顺序表");//
printf("\n 13. 结束程序运行");
printf("\n=================================");
do
{
printf("\n 请选择(1-11): ");
scanf("%d", &k);
switch(k)
{
        
		
		case 1://建立顺序表
			InitSeqlist(&Seq);
			break;
		case 4://输出顺序表
			PrintSeqlist(&Seq);
			break;
		case 3://尾部插入若干元素
			printf("请输入一个要插入的数：");
			scanf("%d",&x);
			PushBack(&Seq,x);
		    break;
		case 2://在头部插入元素
			printf("请输入一个要插入的数：");
			scanf("%d",&x);
			PushFront(&Seq,x);
			break;
		case 8: //在顺序表指定位置插入元素
			printf("请输入一个要插入的数：");
			scanf("%d",&x);
			printf("请选择要插入的位置：");
			scanf("%d",&pos);
			Insert(&Seq,pos,x);
			break;
		case 9: //删除指定元素
			printf("请输入要删除的元素：");
			scanf("%d",&x);
			Remove(&Seq,x); 
			break;
		case 10://删除所有指定元素
			printf("请输入要删除的元素：");
			scanf("%d",&x);
			RemoveAll(&Seq,x);  
			break;
		case 13://
			printf("请输入要查找的数：");
			scanf("%d",&x);
			ret=BinarySearch(&Seq,x);
			if(ret!=-1)
			{
				if(pSeq->data[ret]==x)
				{
					printf("%d\n",x);
					printf("查找成功！\n");
				}
				else
					printf("查找失败!\n");
			}
			if(ret==-1)
			{
				printf("查找失败！\n");
			}
			break;
		case 12://销毁顺序表
			DestroySeqlist(&Seq);
			break;
		case 9://在指定位置删除该元素
			printf("请输入要删除元素的位置：");
			scanf("%d",x);
			Erase(&Seq,x);
} //switch
}while(k!=13);
printf("\n 再见！\n");
}//main