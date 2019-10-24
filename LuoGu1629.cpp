#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define maxn 20031125
#define inf maxn
using namespace std;
int dis[maxn];//可以共用
int head[maxn],head_f[maxn];//不可共用
int cnt,cnt_f,n,m;
bool vis[maxn];
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
struct edge
{
	int nex;
	int to;
	int val;
	void add(int u,int v,int val,edge e[])
	{
		e[++cnt].nex=head[u];
		e[cnt].to=v;
		e[cnt].val=val;
		head[u]=cnt;
	}
	void add_f(int u,int v,int val,edge e_f[])
	{
		e_f[++cnt_f].nex=head_f[u];
		e_f[cnt_f].to=v;
		e_f[cnt_f].val=val;
		head_f[u]=cnt_f;
	}
} e[maxn],e_f[maxn];

queue<int>q;//这玩意儿可以共用
void spfa()
{
	for(ri i=1;i<=n;i++)
	{
		dis[i]=inf;
	}
	dis[1]=0;
	vis[1]=1;
	q.push(1);
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		vis[top]=0;
		for(ri i=head[top]; i; i=e[i].nex)
		{
			int to=e[i].to;
			if(dis[to]>dis[top]+e[i].val)
			{
				dis[to]=dis[top]+e[i].val;
				if(!vis[to])
				{
					vis[to]=1;
					q.push(to);
				}
			}
		}
	}
}
void spfa_f()//加上_f表示反跑
{
	for(ri i=1;i<=n;i++)
	{
		dis[i]=inf;
	}
	dis[1]=0;
	vis[1]=1;
	q.push(1);
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		vis[top]=0;
		for(ri i=head_f[top]; i; i=e_f[i].nex)
		{
			int to=e_f[i].to;
			if(dis[to]>dis[top]+e_f[i].val)
			{
				dis[to]=dis[top]+e_f[i].val;
				if(!vis[to])
				{
					vis[to]=1;
					q.push(to);
				}
			}
		}
	}
}
int main()
{
	n=read();
	m=read();
	int ans=0;
	for(ri i=1; i<=m; i++)
	{
		int u=read(),v=read(),val=read();
		e[i].add(u,v,val,e);
		e[i].add_f(v,u,val,e_f);
	}
	spfa();
	for(ri i=2; i<=n; i++)
	{
		ans+=dis[i];
	}
	memset(vis,0,sizeof(vis));
	
	spfa_f();
	for(ri i=2; i<=n; i++)
	{
		ans+=dis[i];
	}
	
	printf("%d",ans);
}
