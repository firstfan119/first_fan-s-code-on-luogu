#include <bits/stdc++.h>
#define maxn 1000010
#define inf 0x7fffffff
#define ri register int
#define ll long long
using namespace std;
ll read()
{
	ll num=0;
	int flg=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')
		{
			flg=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return num*flg;
}
ll cnt=0;
ll head[maxn];
struct edge
{
	ll to;
	ll nex;
	ll val;
	void add(int u,int v,int val,edge e[])
	{
		e[++cnt].nex=head[u];
		e[cnt].to=v;
		e[cnt].val=val;
		head[u]=cnt;
	}
}e[maxn];
ll n,m;
ll dis[maxn];
bool vis[maxn];
ll st,ed;
void spfa()
{
	for(ri i=1;i<=n;i++)
	{
		dis[i]=inf;
	}
	queue<ll> q;
	q.push(st);
	dis[st]=0;
	vis[st]=true;
	while(!q.empty())
	{
		ll top=q.front();
		q.pop();
		vis[top]=false;
		for(ri i=head[top];i;i=e[i].nex)
		{
			ll to=e[i].to;
			if(dis[to]>dis[top]+e[i].val)
			{
				dis[to]=dis[top]+e[i].val;
				if(!vis[to])
				{
					vis[to]=true;
					q.push(to);
				}
			}
		}
	}
}
ll ans=0;
int main()
{
	n=read();
	m=read();
	ll pt=read();//party
	for(ri i=1;i<=m;i++)
	{
		ll fr=read();
		ll to=read();
		ll val=read();
		e[i].add(fr,to,val,e);
	}
	for(ri i=1;i<=n;i++)
	{
		ll now=0;
		st=i;
		spfa();
		now+=dis[pt];
		st=pt;
		spfa();//跑两遍spfa，完事。
		now+=dis[i];
		ans=max(ans,now);
	}
	printf("%lld",ans);
}//非常类似P2984，但是跑两次是必要的。
