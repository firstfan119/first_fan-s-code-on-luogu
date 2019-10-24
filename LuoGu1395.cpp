#include <bits/stdc++.h>
#define ri register int
#define ll long long
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
	int to;
	int nex;
}e[maxn];

int cnt=0;
int head[maxn];
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}

int n;
int dep[maxn];
int f[maxn];
int siz[maxn];

void dfs1(int nd,int fa)
{
	for(ri i=head[nd];i;i=e[i].nex)
	{
		int to=e[i].to;
		if(to!=fa)
		{
			dfs1(to,nd);
			siz[nd]+=siz[to]+1;
		}
	}
}

void dfs2(int nd,int fa)
{
	f[nd]=f[fa]-(siz[nd]+1)+(n-siz[nd]-1);
	for(ri i=head[nd];i;i=e[i].nex)
	{
		int to=e[i].to;
		if(to!=fa)
		{
			dfs2(to,nd);
		}
	}
}

void origin(int nd,int fa,int dep)//此函数计算原始值
{
	f[1]+=dep;
	for(ri i=head[nd];i;i=e[i].nex)
	{
		int to=e[i].to;
		if(to!=fa)
		{
			origin(to,nd,dep+1);
		}
	}
}

int ans1;
int ans2;

int main()
{
	n=read();
	for(ri i=1;i<=n-1;i++)
	{
		int u=read();
		int v=read();
		add(u,v);
		add(v,u);
	}
	dfs1(1,0);
	for(ri i=head[1];i;i=e[i].nex)
	{
		int to=e[i].to;
		origin(to,1,1);
	}
	for(ri i=head[1];i;i=e[i].nex)
	{
		int to=e[i].to;
		dfs2(to,1);
	}
	ans1=f[1];
	ans2=1;
	for(ri i=1;i<=n;i++)
	{
		if(f[i]<ans1)
		{
			ans1=f[i];
			ans2=i;
		}
	}
	return 0&printf("%d %d",ans2,ans1);//鬼知道我为啥顺序是反的……
}
