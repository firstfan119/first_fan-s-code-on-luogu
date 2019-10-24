#include<bits/stdc++.h>
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

int n,q,m;
int val[maxn];
int f[maxn];
int low[3005],dfn[3005],tim=0,top=0,stk[3005],tot=0,col[3005];
int rd[3005];


struct edge
{
	int nex;
	int to;
} e[maxn];


int cnt=0;
int head[maxn];
void add(int u,int v)
{
	e[++cnt].nex=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}

void tarjan(int u)
{
	dfn[u]=low[u]=++tim;
	stk[++top]=u;
	for(ri i=head[u]; i; i=e[i].nex)
	{
		int to=e[i].to;
		if(!dfn[to])
		{
			tarjan(to);
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
		f[tot]=min(f[tot],val[u]);
		while(stk[top]!=u)
		{
			col[stk[top]]=tot;
			f[tot]=min(f[tot],val[stk[top]]);
			top--;
		}
		top--;
	}
}
int main()
{
	n=read();
	q=read();
	memset(f,0x3f,sizeof(f));
	memset(val,0x3f,sizeof(f));
	for(ri i=1; i<=q; i++)
	{
		val[read()]=read();
	}
	m=read();
	
	for(ri i=1; i<=m; i++)
	{
		int u=read();
		int v=read();
		add(u,v);
	}
	
	for(ri i=1; i<=n; i++)
	{
		if(!dfn[i]&&val[i]<=20031125)
		{
			tarjan(i);
		}
	}
	
	for(ri i=1; i<=n; i++)
	{
		for(ri j=head[i]; j; j=e[j].nex)
		{
			if(col[i]!=col[e[j].to])
			{
				rd[col[e[j].to]]++;
			}
		}
	}

	for(ri i=1; i<=n; i++)
	{
		if(!dfn[i])
		{
			return 0&(int)printf("NO\n%d",i);
		}
	}
	
	int sum=0;
	for(ri i=1; i<=tot; i++)
	{
		if(rd[i]==0)
		{
			sum+=f[i];
		}
	}
	return 0&(int)printf("YES\n%d",sum);
}
