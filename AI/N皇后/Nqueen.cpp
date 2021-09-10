#include<iostream>
using namespace std;
 
 
int absFunc(int n)
{
    if(n<0)
        return -n;
    else
        return n;
}
 
bool Place(int k,int i,int *x)
{
    int j;
    for(j=0;j<k;j++)
        if((x[j]==i)||(absFunc(x[j]-i)==absFunc(j-k)))
            return false;
    return true;
}
 
void NQueens(int k,int n,int *x)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        if(Place(k,i,x))
        {
            x[k]=i;
            if(k==n-1)
            {
                if(x[0]<n/2)
                {
                for(j=0;j<n-1;j++)
                    cout<<x[j]<<" ";
                cout<<x[j]<<endl;
                }
            }
            else
                NQueens(k+1,n,x);
        }
    }
}
int main()
{
    int n;
    printf("请输入皇后个数（如8)");
    cin>>n;
    int *x=new int[n];
    printf("以下为（x1,x2,x3,...,xi）即第i行皇后所在列数\n");
    NQueens(0,n,x);
    delete []x;
    return 0;
}

