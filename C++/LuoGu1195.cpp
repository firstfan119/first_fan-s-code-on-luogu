#include <bits/stdc++.h>
#define ll long long
#define ri register int
using namespace std;

int read()
{
	int num=0;
	int flg=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		{
			flg=-1;
		}
		c=getchar();
	}
	while(isdigit(c))
	{
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return num*flg;
}

const int maxn=1e6+7;
struct edge
{
	int u;
	int v;
	int val;
	friend bool operator <(edge one,edge two)
	{
		return one.val<two.val;
	}
} e[maxn];

int cnt=0;
void add(int u,int v,int val)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].val=val;
}

int f[maxn];
int find(int x)
{
	return f[x]==x?f[x]:f[x]=find(f[x]);
}

int main()
{
	int n=read();
	int m=read();
	int k=read();
	for(ri i=1; i<=n; i++)
	{
		f[i]=i;
	}
	for(ri i=1; i<=m; i++)
	{
		int u=read();
		int v=read();
		int val=read();
		add(u,v,val);
	}
	sort(e+1,e+m+1);
	int tot=0;
	int ans=0;
	for(ri i=1; i<=m; i++)
	{
		int fu=find(e[i].u);
		int fv=find(e[i].v);
		if(fu!=fv)
		{
			f[fu]=fv;
			tot++;
			ans+=e[i].val;
		}
		if(tot==n-k)
		{
			return 0&printf("%d",ans);
		}
	}
	return 0&(int)puts("No Answer");
}
