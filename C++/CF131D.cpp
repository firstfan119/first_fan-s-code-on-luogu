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
	int nex,to;
} e[maxn];

int v[maxn];

int cnt=0;
int head[maxn];
void add(int u,int v)
{
	e[++cnt].nex=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}

int tim=0;
int dfn[maxn];
int low[maxn];
int stk[maxn];
int top=0;
int siz[maxn];
int col[maxn];
int tot=0;
inline void tarjan(int u,int fa)
{
	stk[++top]=u;
	low[u]=dfn[u]=++tim;
	for(ri i=head[u]; i; i=e[i].nex)
	{
		int to=e[i].to;
		if(to==fa)
		{
			continue;
		}
		if(!dfn[to])
		{
			tarjan(to,u);
			low[u]=min(low[u],low[to]);
		}
		else if(!col[to])
		{
			low[u]=min(low[u],dfn[to]);
		}
	}
	if(low[u]==dfn[u])
	{
		col[u]=++tot;
		siz[tot]++;
		while(stk[top]!=u)
		{
			col[stk[top]]=tot;
			siz[tot]++;
			top--;
		}
		top--;
	}
}

int dep[maxn];
int f[maxn][20];
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(ri i=1; i<=15; i++)
	{
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(ri i=head[u]; i; i=e[i].nex)
	{
		int to=e[i].to;
		if(to==fa)
		{
			continue;
		}
		dfs(to,u);
	}
}

int lca(int u,int v)
{
	if(dep[u]>dep[v])
	{
		swap(u,v);
	}
	for(ri i=15; i>=0; i--)
	{
		if(dep[v]-(1<<i)>=dep[u])
		{
			v=f[v][i];
		}
	}
	if(u==v)
	{
		return u;
	}
	for(ri i=15; i>=0; i--)
	{
		if(f[u][i]!=f[v][i])
		{
			u=f[u][i];
			v=f[v][i];
		}
	}
	return f[u][0];
}

int one[maxn];
int two[maxn];
int ct[maxn];
int rt;

int main()
{
	int n=read();
	int m=n;
	for(ri i=1; i<=m; i++)
	{
		one[i]=read();
		two[i]=read();
		add(one[i],two[i]);
		add(two[i],one[i]);
	}
	for(ri i=1; i<=n; i++)
	{
		if(!dfn[i])
		{
			tarjan(i,-1);
		}
	}
	cnt=0;
	memset(head,0,sizeof(head));
	memset(e,0,sizeof(e));
	for(ri i=1; i<=m; i++)
	{
		if(col[one[i]]!=col[two[i]])
		{
			add(col[one[i]],col[two[i]]);
			add(col[two[i]],col[one[i]]);
		}
	}
	dfs(1,0);
	for(ri i=1; i<=n; i++)
	{
		ct[col[i]]++;
		if(ct[col[i]]>=2)
		{
			rt=i;
		}
	}
	for(ri i=1; i<=n; i++)
	{
		if(col[i]==col[rt])
		{
			printf("0 ");
		}
		else
		{
			printf("%d ",dep[col[i]]+dep[col[rt]]-2*dep[lca(col[i],col[rt])]);
		}
	}
}
