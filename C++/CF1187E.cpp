#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define int ll
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
} e[maxn];

int cnt=0;
int head[maxn];
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}

int tot=0;
int siz[maxn];

void dfs1(int nd,int fa,int dep)
{
	tot+=dep;
	siz[nd]=1;
	for(ri i=head[nd];i;i=e[i].nex)
	{
		int to=e[i].to;
		if(to==fa)
		{
			continue;
		}
		dfs1(to,nd,dep+1);
		siz[nd]+=siz[to];
	}
}

int ans=0;
void dfs2(int nd,int fa,int val)//value会随换根而改变
{
	ans=max(ans,val);
	for(ri i=head[nd];i;i=e[i].nex)
	{
		int to=e[i].to;
		if(to==fa)
		{
			continue;
		}
		dfs2(to,nd,val-2*siz[to]+siz[1]);
	}
}

signed main()
{
	int n=read();
	for(ri i=1;i<=n-1;i++)
	{
		int u=read();
		int v=read();
		add(u,v);
		add(v,u);
	}
	dfs1(1,1,1);
	dfs2(1,1,tot);
	return 0&printf("%d",ans);
}
