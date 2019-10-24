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

int ans[maxn];
bool vis[maxn];
bool f[maxn];

void dfs(int nd)
{
	vis[nd]=true;
	f[nd]=1;
	for(ri i=head[nd]; i; i=e[i].nex)
	{
		int to=e[i].to;
		if(f[to])
		{
			ans[e[i].val]=2;
		}
		else
		{
			ans[e[i].val]=1;
			if(!vis[to])
			{
				dfs(to);
			}
		}
	}
	f[nd]=0;
}

int main()
{
	int n=read();
	int m=read();
	for(ri i=1; i<=m; i++)
	{
		int u=read();
		int v=read();
		add(u,v,i);
	}
	for(ri i=1; i<=n; i++)
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
	bool flg=false;
	for(ri i=2; i<=m; i++)
	{
		if(ans[i]!=ans[i-1])
		{
			flg=1;
		}
	}
	printf("%d\n",flg+1);
	if(flg)
	{
		for(ri i=1;i<=m;i++)
		{
			printf("%d ",ans[i]);
		}
	}
	else
	{
		for(ri i=1;i<=m;i++)
		{
			printf("1 ");
		}
	}
	return 0;
}
