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

int ans=0;
int n,len;
int f[maxn][525];
void dfs(int nd,int fa)
{
	f[nd][0]=1;
	for(ri i=head[nd]; i; i=e[i].nex)
	{
		int to=e[i].to;
		if(to!=fa)
		{
			dfs(to,nd);
			for(ri j=0;j<=len-1;j++)
			{
				ans+=f[to][j]*f[nd][len-j-1];
			}
			for(ri j=1;j<=len;j++)
			{
				f[nd][j]+=f[to][j-1];
			}
		}
	}
}

int main()
{
	n=read();
	len=read();
	for(ri i=1;i<=n-1;i++)
	{
		int u=read();
		int v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	return 0&printf("%d",ans);
}
