#include<stdio.h>
#include<math.h>
int num,sum,start,max;//�ŵ��������ŵ��ƶ���������ʼ�ŵ�������ŵ���
int m=0,n=0,s[100],s1[100],c1[50],c2[50];
//s[]�����¼�ŵ�����
//�ÿ�ʼ�ŵ���start�������л��ֳ���������c1,c2

void creat()//��ʼ������
{
  int i,j,t;
  printf("������ŵ��ĸ�����\n");
  scanf("%d",&num);
  printf("��������ĸ��ŵ���ʼ��\t\n");
  scanf("%d",&start);
  printf("��������ŵ��ţ�\n"); 
  scanf("%d",&max); 
  for(j=0;j<num;j++)
  {
    printf("�������%d���ŵ�\n",j+1);
    scanf("%d",&s[j]);
    if(s[j]>max)    //�����ִŵ���������ŵ���ʱ������������ʾ
	{
		printf("ERROR\n");
		break;
	}
  }

  printf("������������\n");
  for(i=0;i<num;i++)//�����������
  {
    printf("\t%d\t\n",s[i]);
  }

 int su=start;//����ʼѰ���Ĵŵ���ֵ������su,�Է��㱣�����

 for(i=0;i<num;i++)
   if(su>s[i])//�ÿ�ʼ�ŵ���start�������л��ֳ���������c1,c2
      c1[m++]=s[i];//��ʼʱmΪ0

   else
      c2[n++]=s[i];//��ʼʱnΪ0

   for(i=0;i<m;i++)
        for(j=i;j<m;j++)
                if(c1[i]<c1[j])//��c1����Ӵ�С����
                {
					t=c1[i];
					c1[i]=c1[j];
					c1[j]=t;
				}

    for(i=0;i<n;i++)
        for(j=i;j<n;j++)
                if(c2[i]>c2[j])//��c2�����С��������
                {
					t=c2[i];
					c2[i]=c2[j];
					c2[j]=t;
			}

}

void FCFS()		//�����ȷ����㷨

{
	int i;
	printf("�����ȷ��� FCFS\n");
	printf("�����ʵ���һ���ŵ�\t\t\t�ŵ����ƶ�����\n");
    int su=start;//��ʼ�ŵ�����ֵ������su
    sum=0;
    for(i=0;i<num;i++)
	{ 
		if(su<s[i])
			s1[i]=s[i]-su;//s1�����¼ÿ���ƶ��ŵ���������ڽ�����

        else
            s1[i]=su-s[i];
      su=s[i];
      sum+=s1[i];//��¼�ƶ��ŵ���
    }

    for(i=0;i<num;i++)
    {
		printf("\t%d\t\t\t\t\t%d\t\t\n",s[i],s1[i]);
	}
    printf("ƽ��Ѱ�����ȣ�%.2f\n",sum*1.0/num);
}


void SSTF()	//���Ѱ��
{

      printf("���Ѱ�� SSTF:\n");
      printf("�����ʵ���һ���ŵ�\t\t\t�ŵ����ƶ�����\n");
      int s2[100],i;
      sum=0;
	  for(i=0;i<num;i++)
		  s2[i]=s[i];
	  int min,temp,st=start,j,tag;
	  for(j=0;j<num;j++){
		  min=10000;
	for(i=0;i<num;i++)	//ÿ��ѡ���뵱ǰ�ŵ�����Ĵŵ�
	{
		temp=abs(s2[i]-st);
		if(temp<min){
			min=temp;
			tag=i;
		}
	}
	st=s2[tag];
         printf("\t%d\t\t\t\t\t%d\t\t\n",s2[tag],min);
       sum=sum+min;  //��¼ÿ�ε��ƶ���
	   s2[tag]=10000;
}
       printf("ƽ��Ѱ������:%.2f\n",sum*1.0/num);
    }

void SCAN()//ɨ���㷨

{
	 int i;
     printf("ɨ���㷨 SCAN:\n");
     printf("�����ʵ���һ���ŵ���\t\t\t�ŵ����ƶ����룺\n");
     int su=start;
     int s2[100];
     sum=0;
     for(i=0;i<n;i++)	//�����ڶ���ؽ����ƶ���ͷ
     s2[i]=c2[i];
     for(i=0;i<m;i++)	//c1c2������create�����Ѿ��ֻ��õ���������
      s2[i+n]=c1[i];
     for(i=0;i<num;i++)
     { 
		if(su<s2[i])
            s1[i]=s2[i]-su;
        else
        s1[i]=su-s2[i];
        su=s2[i];
        sum+=s1[i];
     }

      for(i=0;i<num;i++)
      {
         printf("\t%d\t\t\t\t\t%d\t\t\n",s2[i],s1[i]);
      }
       printf("ƽ��Ѱ�����ȣ�%.2f\n",sum*1.0/num);
    }

void CSAN()
{
	int i;
     printf("ѭ��ɨ�� CSAN:\n");
     printf("�����ʵ���һ���ŵ���\t\t\t�ŵ����ƶ����룺\n");
     int su=start;
     int j=0;
     int s2[100];
     sum=0;
     for(i=0;i<n;i++)
      s2[i]=c2[i];

     for(i=m-1;i>=0;j++,i--)
      s2[j+n]=c1[i];
      for(i=0;i<num;i++)
      { 
		  if(su<s2[i])
			s1[i]=s2[i]-su;
		  else
        s1[i]=su-s2[i];
        su=s2[i];
        sum+=s1[i];
      }

      //sum=sum/num;
      for(i=0;i<num;i++)
       {
		  printf("\t%d\t\t\t\t\t%d\t\t\n",s2[i],s1[i]);
       }
       printf("ƽ��Ѱ������:%.2f\n",sum*1.0/num);
}

 

 

void MENU()

{
  int x;
	creat();	//��ʼ���ŵ�
	do{
	printf("���̵���\n");
	printf("|--------��ѡ�����------------|\n");
	printf("|------1.�����ŵ�--------------|\n");
	printf("|------2.�����ȷ���FCFS--------|\n");
	printf("|------3.���Ѱ��SSTF----------|\n"); 
	printf("|------4.ɨ���㷨 SCAN---------|\n");
	printf("|------5.ѭ��ɨ���㷨 CSCAN----|\n");
	printf("|------6.EXIT------------------|\n");
	scanf("%d",&x);
	switch(x)
{
	case 2: FCFS();
            break;
	case 3:SSTF();
			break;
	case 4:SCAN();
			break;
	case 5:CSAN();
			break;
	case 6:
		printf("�ټ���");
	break;

}
  }while(x<6);

}

int main()	//��������
{
	MENU();
	return 0;
}
