#include<iostream>
#include<queue>
#include<stack>
/*
否定    	！
合取    	+
析取		－
蕴含		#
等价        $
*/
using namespace std;
char expression[100];
int deny(int a)
{
    if(a==0)
	{
        a=1;
	    return a;	
	}
	else
	{
	    a=0;
		return a;
	}
}
int both(int a,int b)
{
    int c;
	if(a==1&&b==1)
	{
	    c=1;
		return c;
	}
	else
	{
	    c=0;
		return c;
	}
}
int xiqu(int a,int b)
{
    int c;
	if(a==0&&b==0)
	{
	    c=1;
		return c;
	}
	else
	{
	    c=0;
		return c;
	}
}
int yunhan(int a,int b)
{
    int c;
    if(a==1&&b==0)
	{
	    c=0;
		return c;
	}
	else
	{
	    c=1;
		return c;
	}
}
int dengjia(int a,int b)
{
    int c;
	if((a==1&&b==1)||(a==0&&b==0))
	{
	    c=1;
		return c;
	}
	else
	{
	    c=0;
		return c;
	}
}
int main()
{
	
    int r1,r2,r3,result,cnt=0,zimu[10],num[10],cnt1=0,name;
	cout<<"请输入表达式："<<endl;
    cin>>expression;
	for(int n1=0;n1<100;n1++)
	{
        if(expression[n1]=='(')
		{
			cnt1++;
			continue;
		}
		if(expression[n1]==')')
		{
		    cnt1--;
			continue;
		}
	}
	if(cnt1==0)
	{
    queue<char> q1;//存后缀表达式
	stack<char> s1;
	stack<int> s2;
	for(int i=0;i<100;i++)
	{
	    if(expression[i]=='(')
		{
			s1.push(expression[i]);
			continue;
		}
		else if(expression[i]==')')
		{
		    q1.push(s1.top());
			s1.pop();
			s1.pop();
			continue;
		}
		else if(expression[i]>=97&&expression[i]<=122)
		{
		    q1.push(expression[i]);
			continue;
		}
		else if(expression[i]=='!'||expression[i]=='+'||expression[i]=='-'||expression[i]=='#'||expression[i]=='$')
		{
		    s1.push(expression[i]);
			continue;
		}
		else
		{
		    break;
		}
	}

	while(!q1.empty())
	{
		if(q1.front()>=97&&q1.front()<=122)
		{
			int k; 
			for(k=0;k<10;k++)
			{
			    if(q1.front()==zimu[k])
				{
					q1.pop();
					s2.push(num[k]);
					break;
				}
			}
            if(k==10)	
				{	
					cout<<"请输入"<<q1.front()<<"的真值："<<endl;
				    zimu[cnt]=q1.front();
			        cin>>name;
					num[cnt]=name;
			        s2.push(name);
			        q1.pop();
					cnt++;
					
				}
		}
		if(q1.front()=='!')
		{
		    q1.pop();
			r1=s2.top();
			s2.pop();
			r3=deny(r1);
            s2.push(r3);
		}
		if(q1.front()=='+')
		{
		    q1.pop();
			r2=s2.top();
			s2.pop();
			r1=s2.top();
			s2.pop();
			r3=both(r1,r2);
			s2.push(r3);
		}
		if(q1.front()=='-')
		{
		    q1.pop();
			r2=s2.top();
			s2.pop();
			r1=s2.top();
			s2.pop();
			r3=xiqu(r1,r2);
			s2.push(r3);
		}
		if(q1.front()=='#')
		{
		    q1.pop();
			r2=s2.top();
			s2.pop();
			r1=s2.top();
			s2.pop();
			r3=yunhan(r1,r2);
			s2.push(r3);
		}
		if(q1.front()=='$')
		{
		    q1.pop();
			r2=s2.top();
			s2.pop();
			r1=s2.top();
			s2.pop();
			r3=dengjia(r1,r2);
			s2.push(r3);
		}
	}
    result=s2.top();
	s2.pop();
	cout<<"该表达式结果为："<<result<<endl;
	}
	else 
		cout<<"括号输入错误!"<<endl;
	return 0;
}
