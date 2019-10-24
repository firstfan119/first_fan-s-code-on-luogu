#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[10000],b[10000],cc[10000][10000],d[10000];
int jf(int a[],int b[],int x,int y,int z)
{
    int k=max(x,y);
    for(int i=0;i<k;i++)
    {
        cc[z][i]+=a[i]+b[i];
        if(cc[z][i]>=10)
        {
            cc[z][i]-=10;
            cc[z][i+1]++;
            if(i==k-1)
            {
                k++;
            }
        }
    }
    return k;
}
int main()
{
    int n;
    cin>>n;
    a[0]=1;
    a[1]=2;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        d[i]=jf(a+i-1,a+i-2,d[i-1],d[i-2],i);
    }
    for(int i=d[n]-1;i>=0;i--)
    {
        cout<<a[n];
    }
    return 0;
}
