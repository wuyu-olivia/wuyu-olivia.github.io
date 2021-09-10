void PrintSeqlist(pSeqlist pSeq);      //顺序表打印输出
void InitSeqlist(pSeqlist pSeq);       //进行初始化，建立顺序表
void DestroySeqlist(pSeqlist pSeq);		//销毁顺序表
void PushBack(pSeqlist pSeq,DataType x);//在顺序表尾部插入元素
void PopBack(pSeqlist pSeq);            //在顺序表尾部删除元素
void PushFront(pSeqlist pSeq,DataType x);//在顺序表头部插入元素
void PopFront(pSeqlist pSeq);            //在顺序表头部删除元素
void Insert(pSeqlist pSeq,int pos,DataType x);//在顺序表指定位置插入元素
void Erase(pSeqlist pSeq,DataType pos);       //在指定位置删除该元素
void Remove(pSeqlist pSeq,DataType x);        //删除指定元素
void RemoveAll(pSeqlist pSeq,DataType x);     //删除所有指定的元素
