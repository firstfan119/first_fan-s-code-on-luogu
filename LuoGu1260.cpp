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

const int maxn=20031125;
struct edge
{
	int to;
	int nex;
	int val;
} e[maxn];

int cnt=0;
int head[maxn];
void add(int u,int v,int val)
{
	e[++cnt].nex=head[u];
	head[u]=cnt;
	e[cnt].val=val;
	e[cnt].to=v;
}

int dis[maxn];
bool vis[maxn];
int dfn[maxn];

int n,m;

void spfa(int st)
{
	queue<int>q;
	dis[st]=0;
	q.push(st);
	vis[st]=true;
	dfn[st]++;
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
					dfn[to]++;
					if(dfn[top]==n+1)
					{
						printf("NO SOLUTION\n");
						exit(0);
					}
					q.push(to);
				}
			}
		}
	}
	vis[st]=false;
}

int main()
{
	n=read();
	m=read();
	for(ri i=1; i<=m; i++)
	{
		int u=read();
		int v=read();
		add(v,u,read());
	}
	fill(dis+1,dis+n+1,0x3f);
	for(ri i=1; i<=n; i++)
	{
		if(dfn[i])
		{
			continue;
		}
		spfa(i);
	}
	int ans=0x3f3f3f;
	for(ri i=1; i<=n; i++)
	{
		ans=min(ans,dis[i]);
	}
	for(ri i=1; i<=n; i++)
	{
		printf("%d\n",dis[i]-ans);
	}
}
