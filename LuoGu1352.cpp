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

const int maxn=1e5+7;
struct edge
{
	int to;
	int nex;
} e[maxn];

int cnt=0;
int head[maxn];
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}

int w[maxn];
int yes[maxn];
int no[maxn];
void dfs(int nd)
{
	for(ri i=head[nd]; i; i=e[i].nex)
	{
		int to=e[i].to;
		dfs(to);
		no[nd]+=max(no[to],yes[to]);
		yes[nd]+=no[to];
	}
	yes[nd]+=w[nd];
}

int rd[maxn];
int main()
{
	int n=read();
	for(ri i=1; i<=n; i++)
	{
		w[i]=read();
	}
	for(ri i=1; i<=n; i++)
	{
		int u=read();
		int v=read();
		rd[u]++;
		if(u&&v)
		{
			add(v,u);
		}
	}
	int ans=0;
	for(ri i=1; i<=n; i++)
	{
		if(!rd[i])
		{
			dfs(i);
			ans=max(yes[i],no[i]);
			break;
		}
	}
	return 0&printf("%d",ans);
}
