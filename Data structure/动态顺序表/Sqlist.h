void PrintSeqlist(pSeqlist pSeq);      //˳����ӡ���
void InitSeqlist(pSeqlist pSeq);       //���г�ʼ��������˳���
void DestroySeqlist(pSeqlist pSeq);		//����˳���
void PushBack(pSeqlist pSeq,DataType x);//��˳���β������Ԫ��
void PopBack(pSeqlist pSeq);            //��˳���β��ɾ��Ԫ��
void PushFront(pSeqlist pSeq,DataType x);//��˳���ͷ������Ԫ��
void PopFront(pSeqlist pSeq);            //��˳���ͷ��ɾ��Ԫ��
void Insert(pSeqlist pSeq,int pos,DataType x);//��˳���ָ��λ�ò���Ԫ��
void Erase(pSeqlist pSeq,DataType pos);       //��ָ��λ��ɾ����Ԫ��
void Remove(pSeqlist pSeq,DataType x);        //ɾ��ָ��Ԫ��
void RemoveAll(pSeqlist pSeq,DataType x);     //ɾ������ָ����Ԫ��
