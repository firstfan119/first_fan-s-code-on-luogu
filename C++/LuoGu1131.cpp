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
	int to;
	int nex;
	int val;
} e[maxn];

int cnt=0;
int head[maxn];
void add(int u,int v,int val)
{
	e[++cnt].to=v;
	e[cnt].nex=head[u];
	e[cnt].val=val;
	head[u]=cnt;
}

int dis[maxn];
//bool vis[maxn];
ll ans=0;
void dfs(int nd,int fa)
{
	for(ri i=head[nd]; i; i=e[i].nex)
	{
		int to=e[i].to;
		if(to==fa)
		{
			continue;
		}
		dfs(to,nd);
		dis[nd]=max(dis[nd],dis[to]+e[i].val);
	}
}
void Dfs(int nd,int fa)
{
	for(ri i=head[nd]; i; i=e[i].nex)
	{
		int to=e[i].to;
		if(to==fa)
		{
			continue;
		}
		Dfs(to,nd);
		ans+=dis[nd]-dis[to]-e[i].val;
	}
}
int main()
{
	int n=read();
	int st=read();
	for(ri i=1; i<=n-1; i++)
	{
		int u=read();
		int v=read();
		int val=read();
		add(u,v,val);
		add(v,u,val);
	}
	dfs(st,0);
	Dfs(st,0);
	return 0&printf("%lld",ans);
}
/*
3
1
1 2 1
1 3 3
out:
2
*/
