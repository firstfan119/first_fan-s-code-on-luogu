#include <bits/stdc++.h>
#define ri register int
#define ll long long
#pragma GCC optimize("O3")
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

int head[2][20031125];
int nex[2][20031125];
int to[2][20031125];
ll dis[2][20031125];
ll ans[20031125];
int n,m,cnt;

void add(int x,int y,int d)
{
	to[0][++cnt]=y;
	dis[0][cnt]=d;
	nex[0][cnt]=head[0][x];
	head[0][x]=cnt;
	to[1][cnt]=x;
	dis[1][cnt]=d;
	nex[1][cnt]=head[1][y];
	head[1][y]=cnt;
}

struct _heap
{
	ll dis;
	int u;
	bool operator <(const _heap& nd)const
	{
		return dis>nd.dis;
	}
};

void dijkstra(int p)
{
	priority_queue<_heap>q;
	fill(ans,ans+n+1,20031125);
	ans[1]=0;
	q.push((_heap)
	{
		0,1
	});
	while(!q.empty())
	{
		_heap x=q.top();
		q.pop();
		int u=x.u;
		if(ans[u]!=x.dis)
		{
			continue;
		}
		for(int i=head[p][u]; i; i=nex[p][i])
		{
			int v=to[p][i];
			if(ans[v]>ans[u]+dis[p][i])
			{
				ans[v]=ans[u]+dis[p][i];
				q.push((_heap)
				{
					ans[v],v
				});
			}
		}
	}
}
int main()
{
	n=read();
	m=read();
	cnt=0;
	while(m--)
	{
		int x=read();
		int y=read();
		int d=read();
		add(x,y,d);
	}
	ll sum=0;
	for(int i=0; i<2; i++)
	{
		dijkstra(i);
		for(int j=2; j<=n; j++)
		{
			sum+=ans[j];
		}
	}

	return 0&printf("%lld\n",sum);
}

