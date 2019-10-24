#include<bits/stdc++.h>
using namespace std;
int num1,num2;
int fig[15];
bool flag=true;

int GetFig(int size)
{
    int ans=0;
    for(register int i=1;i<=size;++i)
    {
        ans*=10;
        ans+=fig[i];
    }
    return ans;
}

bool PrimeIf(int k)
{
    for(register int i=2;i<=sqrt(k);++i)
        if(k%i==0) return false;
    return true;
}

void DFS(int size,int now)
{
    if(now<=(size+1)/2)
        for(register int i=0;i<=9;++i)
        {
            if(now==1&&(i==0||i%2==0)) continue;
            fig[now]=i;
            DFS(size,now+1);
            if(flag==false) return;
        }
    else
    {
        for(register int i=now;i<=size;++i) fig[i]=fig[size-i+1];
        int num=GetFig(size);
        if(num<num1) return;
        if(num>num2)
        {
            flag=false;
            return;
        }
        if(PrimeIf(num)) cout<<num<<endl;
        return;
    }
}

int main()
{
    cin>>num1>>num2;
    for(register int i=1;i<=9;++i) DFS(i,1);
    return 0;
}
