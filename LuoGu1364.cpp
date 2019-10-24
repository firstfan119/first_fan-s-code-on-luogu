#include <bits/stdc++.h>
#define ri register int
using namespace std;
const int inf=20031125;
#define maxn inf
int w[maxn];
int n;
int size[maxn];
int ans=inf;
int f[maxn];
int read()
{
	int cnt=0;
	int flg=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			flg=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		cnt=(cnt<<1)+(cnt<<3)+(c^48);
		c=getchar();
	}
	return cnt*flg;
}
struct edge
{
	int nex, to;
} e[maxn];
int head[maxn];
int cnt=0;
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
void dfs(int u,int fa,int dep)
{
	size[u]=w[u];
	for(int i=head[u];i;i=e[i].nex)
	{
		if(e[i].to!=fa)
		{
			dfs(e[i].to, u, dep+1), size[u]+=size[e[i].to];
		}
	}
	f[1]+=w[u]*dep;
}
void dp(int u,int fa)
{
	for(int i=head[u];i;i=e[i].nex)
	{
		if(e[i].to !=fa)
		{
			f[e[i].to]=f[u]+size[1]-(size[e[i].to]<<1),dp(e[i].to,u);
		}
	}
	ans=min(ans,f[u]);
}
int a,b;
int main()
{
	ans*=ans;
	n=read();
	for(ri i=1; i<=n; i++)
	{
		w[i]=read();
		a=read();
		b=read();
		if(a)
		{
			add(i,a);
			add(a,i);
		}
		if(b)
		{
			add(i,b);
			add(b,i);
		}
	}
	dfs(1,0,0);
	dp(1,0);
	printf("%d\n",ans);
}
