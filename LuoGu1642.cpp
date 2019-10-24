#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define db double
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
	return flg*num;
}

const int maxn=1125;
struct edge
{
	int to;
	int nex;
} e[maxn];

struct factory
{
	int w1;
	int w2;
	db val;
} fac[maxn];

int n,m;
int cnt=0;
int head[maxn];
void add(int u,int v)
{
	e[++cnt].nex=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}

db f[maxn][maxn];
int siz[maxn];
bool flg=false;
void dfs(int nd,int fa)
{
	siz[nd]=1;
	f[nd][1]=fac[nd].val;
	for(ri i=head[nd]; i; i=e[i].nex)
	{
		int to=e[i].to;
		if(to==fa)
		{
			continue;
		}
		dfs(to,nd);
		if(flg)
		{
			return ;
		}
		siz[nd]+=siz[to];
		int r=min(siz[nd],n-m);
		for(ri j=r; j>=2; j--)
		{
			for(ri k=1; k<=j-1; k++)
			{
				f[nd][j]=max(f[nd][j],f[nd][j-k]+f[to][k]);
			}
		}
	}
	if(f[nd][n-m]>=0)
	{
		flg=true;
	}
}


bool check(db x)
{
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=n;j++)
		{
			f[i][j]=-20031125;
		}
	}
	for(ri i=1; i<=n; i++)
	{
		fac[i].val=(db)fac[i].w1-(db)x*fac[i].w2;
	}
	dfs(1,0);
	return flg;
}

signed main()
{
	n=read();
	m=read();
	for(ri i=1; i<=n; i++)
	{
		fac[i].w1=read();
	}
	for(ri i=1; i<=n; i++)
	{
		fac[i].w2=read();
	}
	for(ri i=1; i<=n-1; i++)
	{
		int u=read();
		int v=read();
		add(u,v);
		add(v,u);
	}
	db l=0;
	db r=1e6+7;
	while(r-l>1e-6)
	{
		flg=false;
		db mid=(l+r)/2.0;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	return 0&printf("%.1lf",l);
}
/*
3 2
2 3 4
1 1 1
1 2
2 3
out:
4.0
*/
