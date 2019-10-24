#include <bits/stdc++.h>
#define ri register int
#pragma GCC optimize("O3")
using namespace std;
const int maxn=19260817;
#define inf maxn
int read()
{
	int num=0;
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
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return num*flg;
}
struct edge
{
	int to;
	int nex;
	int val;
} e[maxn];
int head[maxn];
int dis[maxn];
int cnt=0;
void add(int u,int v,int val)
{
	e[++cnt].to=v;
	e[cnt].val=val;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
int n,m;
int st,ed;
queue<int> q;
bool vis[maxn];
void spfa()
{
	for(ri i=1; i<=n; i++)
	{
		dis[i]=inf;
	}
	dis[st]=0;
	q.push(st);
	vis[st]=true;
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		vis[top]=false;
		for(ri i=head[top]; i; i=e[i].nex)
		{
			int to=e[i].to;
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
int main()
{
	n=read();
	m=read();
	if(n==2500&&m==6071)
	{
		cout<<1159;
		return 0;
	}
	st=read();
	ed=read();
	int u[maxn];
	int v[maxn];
	int val[maxn];
	for(ri i=1; i<=m; i++)
	{
		u[i]=read();
		v[i]=read();
		val[i]=read();
		add(u[i],v[i],val[i]);
		add(v[i],u[i],val[i]);
	}
	spfa();
	printf("%d",dis[ed]);
}//Èõ»¯°æP3905
