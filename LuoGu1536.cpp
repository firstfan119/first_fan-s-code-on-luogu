#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define ri register int
using namespace std;
const int maxn=1e7+7;
int read()
{
    int num=0;
    int flg=1;
    char c=getchar();
    while(c>'9'||c<'0')
    {
        if(c=='-')
        {
            flg=-1;
        }
        c=getchar();
    }
    while(c<='9'&&c>='0')
    {
        num=(num<<1)+(num<<3)+(c^48);
        c=getchar();
    }
    return num*flg;
}
int f[maxn];
int find(int x)
{
    return x==f[x]?x:(f[f[x]]=find(f[x]));
}
struct edge
{
    int u;
    int v;
    int val;
}e[maxn];
int cnt=0;
void add(int u,int v,int val)
{
    e[++cnt].u=u;
    e[cnt].v=v;
    e[cnt].val=val;
}
bool cmp(edge a,edge b)
{
    return a.val<b.val;
}
int n,m;
int main()
{
    while(1)
    {
        while(cnt--)
        {
            e[cnt].u=0;
            e[cnt].v=0;
            e[cnt].val=0;
        }
        cnt=0;
        n=read();
        if(n==0)
        {
            return 0;
        }
        m=read();
        for(ri i=1;i<=n;i++)
        {
            f[i]=i;
            for(ri j=i+1;j<=n;j++)
            {
                add(i,j,1);
            }
        }
        for(ri i=1;i<=m;i++)
        {
            add(read(),read(),0);
        }
        int tot=0;
        int ans=0;
        sort(e+1,e+cnt+1,cmp);
        for(int i=1;i<=cnt;i++)
        {
            int fu=find(e[i].u);
            int fv=find(e[i].v);
            if(fu!=fv)
            {
                f[fu]=fv;
                ans+=e[i].val;
                tot++;
            }
            if(tot==cnt-1)
            {
                break;
            }
        }
        printf("%d\n",ans);
    }
}
