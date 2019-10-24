
/*
ll dis[1125][1125];

int cnt=0;
int head[20031125];
struct edge
{
	int to;
	int nex;
	int val;
}e[20031125];

void add(int u,int v,int val)
{
	e[++cnt].to=v;
	e[cnt].nex=head[u];
	e[cnt].val=val;
	head[u]=cnt;
}

int spfa(ll x)
{
	queue<int> q;
	int vis[125][1125];
}
*///²»ÐèÒªspfa!

#include <bits/stdc++.h>
#define ri register ll
#define db double
#define ll long long
using namespace std;
ll read()
{
	ll num=0;
	ll flg=1;
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

ll f[55][55][1125];

ll n,m;

void solve(ll x,ll y)
{
	db ans=66666.0;
	for(ri i=1; i<=n; i++)
	{
		ans=min(ans,1.0*f[x][y][i]/i);
	}
	if (ans<66666.0)
	{
		printf("%.3f\n",ans);
	}
	else
	{
		printf("OMG!\n");
	}
}

int main()
{
	n=read();
	m=read();
	memset(f,63,sizeof(f));
	for(ri i=1; i<=m; i++)
	{
		ll x=read();
		ll y=read();
		ll val=read();
		f[x][y][1]=min(f[x][y][1],val);
	}
	for(ri l=1; l<=n; l++)
	{
		for(ri k=1; k<=n; k++)
		{
			for(ri i=1; i<=n; i++)
			{
				for(ri j=1; j<=n; j++)
				{
					f[i][j][l]=min(f[i][j][l],f[i][k][l-1]+f[k][j][1]);
				}
			}
		}
	}
	ll opt=read();
	while (opt--)
	{
		ll x=read();
		ll y=read();
		solve(x,y);
	}
}
