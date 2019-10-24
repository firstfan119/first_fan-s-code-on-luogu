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
	int val;
}e[maxn];

int cnt=0;
int head[maxn];
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}

int f[maxn];
int w[maxn];
void dfs(int nd,int fa)
{
	f[nd]=w[nd];
	for(ri i=head[nd];i;i=e[i].nex)
	{
		int to=e[i].to;
		if(to==fa)
		{
			continue;
		}
		dfs(to,nd);
		f[nd]+=max(0,f[to]);
	}
}

int main()
{
	int n=read();
	for(ri i=1;i<=n;i++)
	{
		w[i]=read();
	}
	for(ri i=1;i<=n-1;i++)
	{
		int u=read();
		int v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	int ans=-20031125;
	for(ri i=1;i<=n;i++)
	{
		ans=max(ans,f[i]);
	}
	return 0&printf("%d",ans);
}
