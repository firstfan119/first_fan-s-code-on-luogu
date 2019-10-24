#include <bits/stdc++.h>
using namespace std;
struct bian
{
    int to;
    int nt;
    int dis;
}e[100001];
int f[10001],head[10001],tot=0,ans=0;
bool flag=0;
int n,m,b;
void add(int from,int to,int dis)
{
    ++tot;
    e[tot].to=to;
    e[tot].dis=dis;
    e[tot].nt=head[from];
    head[from]=tot;
}
void check(int fr,int l,int x,int q)
{
    if(f[1]>q||f[n]>q)
    {
    	flag=0;
    	return;
    }
    if(fr==n)
    {
    	flag=1;
    	return;
    }
    for(int i=head[fr];i;i=e[i].nt)
    {
        if(f[e[i].to]<=q&&x-e[i].dis>0&&e[i].to!=l)
        {
            check(e[i].to,fr,x-e[i].dis,q);
        }
        if(flag==1)
        return;
    }
}
int main()
{
    cin>>n>>m>>b;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&f[i]);
    }
    for(int i=1;i<=m;++i)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    int l=0,r=2147483646;
    check(1,0,b,2147483646);
    if(flag==0)
    {
        cout<<"AFK";
        return 0;
    }
    while(l<=r)
    {
        flag=0;
        int mid=(l+r)>>1;
        check(1,0,b,mid);
        if(flag==1)
        {
            r=mid-1;
            ans=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}
