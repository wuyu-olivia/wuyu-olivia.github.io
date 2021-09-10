#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
#define MAXBUFFER 10
typedef char SElemType;
typedef struct 
{
        SElemType *base;
        SElemType *top;
        int stacksize;
}sqstack;

int Initstack(sqstack *s)
{
        s->base=(SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
        if(!s->base)
        {
                exit(0);
        }
        s->top=s->base;
        s->stacksize=STACK_INIT_SIZE;
        return 0;
}

int SPush(sqstack *s,SElemType e)
{
        if(s->top-s->base>=s->stacksize)
        {
                s->base=(SElemType *)realloc(s->base,(s->stacksize + STACKINCREMENT) * sizeof(SElemType));
                if(!s->base)
                {
                        exit(0);
                }
        }
    *(s->top)=e;
        s->top++;
        return 0;
}

int SPop(sqstack *s,SElemType *e)
{
        if(s->top==s->base)
        {
                return 0;
        }
        *e=*(--s->top);
        return 0;
}

int stackLen(sqstack s)
{
        return (s.top-s.base);  
}

int main()
{
    sqstack s;
    char c, e;
	int i=0;
	double d;
	char str2[MAXBUFFER];
    Initstack( &s );
    printf("��������׺���ʽ����#��Ϊ������־��\n");
    scanf("%c", &c);

    while( c != '#' )
    {
		while(isdigit(c)||c=='.')  //��������
		{
			str2[i++]=c;
			str2[i]='\0';
			if(i>=10){
				printf("�������ݹ���");
				return -1;
			}
			scanf("%c",&c);
			if((!(c>='0' && c<='9'))&&(c!='.')){
				d=atof(str2);
				printf("%s",str2);
				printf("  ");
				i=0;
				break;
			}
		}

        if( ')' == c )
        {
            Pop(&s, &e);
            while( '(' != e ) //���������ž͵�ջ
            {
                printf("%c ", e);
                Pop(&s, &e);
            }
        }
        else if( '+'==c || '-'==c )  //����ջ�����ȼ�ջ��Ԫ�ص���
        {
            if( !stackLen(s) )
            {
                Push(&s, c);
            }
            else
            {
                do
                {
                    Pop(&s, &e);
                    if( '(' == e )
                    {
                        Push(&s, e);
                    }
                    else
                    {
                        printf("%c ", e);
                    }
                }while( stackLen(s) && '('!=e );
                Push(&s, c);
            }
        }
        else if( '*'==c || '/'==c || '('==c )  //���ȼ��ߵ�ֱ����ջ
        {
            Push(&s, c);
        }
        else if( '#'== c )
        {
            break;
        }
        /*else
        {
            printf("���������ʽ����\n");
            return -1;
        }*/
        scanf("%c", &c);
    }

    while( stackLen(s) ) //������󣬰�ջ��ʣ��Ԫ�ض���ջ
    {
        Pop(&s, &e);
        printf("%c ", e);
    }
    printf("\n");
    return 0;
}