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
} e[maxn];

int cnt=0;
int head[maxn];
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}

int f[maxn];
int sum=0;
int w[maxn];
void dfs(int nd,int fa)
{
	bool flg=false;
	for(ri i=head[nd]; i; i=e[i].nex)
	{
		flg=true;
		int to=e[i].to;
		dfs(to,nd);
		if(w[nd]==0)
		{
			f[nd]+=f[to];
		}
		else
		{
			f[nd]=min(f[nd],f[to]);
		}
	}
	if(!flg)
	{
		sum++;
		f[nd]=1;
	}
}

int main()
{
	int n=read();
	for(ri i=1; i<=n; i++)
	{
		w[i]=read();
		if(w[i]==0)
		{
			f[i]=0;
		}
		else
		{
			f[i]=n+1;
		}
	}
	for(ri i=2; i<=n; i++)
	{
		int u=read();
		add(u,i);
	}
	dfs(1,0);
	return 0&printf("%d\n",sum-f[1]+1);;
}
