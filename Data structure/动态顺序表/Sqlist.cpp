void PrintSeqlist(pSeqlist pSeq)     //˳����ӡ���
{
	int i=0;
	for(i=0;i<pSeq->sz;i++)
	{
		printf("%d\n",pSeq->data[i]);
	}
}
void InitSeqlist(pSeqlist pSeq)       //���г�ʼ��
{
	pSeq->data=(DataType *)malloc(DEFAULT_SZ*sizeof(DataType));
	if(pSeq->data==NULL)
	{
		printf("out of memory");
		exit(EXIT_FAILURE);
	}
	pSeq->sz=0;
	pSeq->capacity=0;
	memset(pSeq->data,0,DEFAULT_SZ*sizeof(DataType));
}
void DestroySeqlist(pSeqlist pSeq)
{
	free(pSeq->data);
	pSeq->data=NULL;
	pSeq->capacity=0;
    pSeq->sz=0;
 
}
void PushBack(pSeqlist pSeq,DataType x)     //��˳���β������Ԫ��
{
	Check_capacity(pSeq);
	pSeq->data[pSeq->sz]=x;
	pSeq->sz++;
}
void PopBack(pSeqlist pSeq)            //��˳���β��ɾ��Ԫ��
{
	if(pSeq->sz==0)
	{
		printf("˳����ѿգ�");
		return;
	}
	pSeq->sz--;
 
}
void PushFront(pSeqlist pSeq,DataType x)   //��˳���ͷ������Ԫ��
{
	int i=0;
	Check_capacity(pSeq);
	for(i=pSeq->sz-1;i>=0;i--)
	{
		pSeq->data[i+1]=pSeq->data[i];
	}
	pSeq->data[0]=x;
	pSeq->sz++;
 
}
void Insert(pSeqlist pSeq,int pos,DataType x)  //��˳���ָ��λ�ò���Ԫ��
{
	int i=0;
    Check_capacity(pSeq);
	for(i=pSeq->sz-1;i>=pos;i--)
	{
		pSeq->data[i+1]=pSeq->data[i];
	}
	pSeq->data[pos]=x;
	pSeq->sz++;
 
}
 
void Erase(pSeqlist pSeq,DataType pos)      //��˳���ָ��λ��ɾ��Ԫ��
{
	int i=0;
	if((pos<0)&&(pos>pSeq->sz))
	{
		printf("ɾ��λ�ò��Ϸ���");
		return;
	}
	for(i=pos;i<pSeq->sz-1;i++)
	{
		pSeq->data[i]=pSeq->data[i+1];
	}
	pSeq->sz--;
}
void Remove(pSeqlist pSeq,DataType x)        //ɾ��ָ��Ԫ��
{
	int i=0;
	int ret=0;
	ret=BinarySearch(pSeq,x);
	if(ret==-1)
	{
		printf("û���ҵ���Ԫ�أ�\n");
		return;
	}
	for(i=ret;i<pSeq->sz;i++)
	{
		pSeq->data[i]=pSeq->data[i+1];
	}
	pSeq->sz--;
}
void RemoveAll(pSeqlist pSeq,DataType x)    //ɾ������ָ����Ԫ��
{
	int i=0;
	int ret=0;
	ret=BinarySearch(pSeq,x);
	while(ret<pSeq->sz)
	{
		if(ret==-1)
		{
			printf("û���ҵ���Ԫ�أ�\n");
			return;
		}
		for(i=ret;i<pSeq->sz;i++)
		{
			pSeq->data[i]=pSeq->data[i+1];
		}
		pSeq->sz--;
		ret++;
	}
}

