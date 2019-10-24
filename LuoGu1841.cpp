#include <bits/stdc++.h>
#define ri register int
#define ll long long
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
	return num*flg;
}

const int maxm=3e6+7;
const int maxn=11250;
struct edge
{
	int fr;
	int to;
	int nex;
	int val;
}e[maxm];

int cnt=0;
int head[maxn];
void add(int u,int v,int val)
{
	e[++cnt].to=v;
	e[cnt].fr=u;
	e[cnt].nex=head[u];
	e[cnt].val=val;
	head[u]=cnt;
}

int n,m;
int dis[maxn];
bool vis[maxn];
bool ans[maxn];
bool flg[maxn];
int rd[maxn];
int tot=0;
priority_queue<pair<int,int> >q;
void spfa(int st)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[st]=0;
	q.push(make_pair(0,st));
	while(q.size())
	{
		int top=q.top().second;
		q.pop();
		if(!vis[top])
		{
			vis[top]=true;
			for(ri i=head[top];i;i=e[i].nex)
			{
				int to=e[i].to;
				if(dis[to]>dis[top]+e[i].val)
				{
					dis[to]=dis[top]+e[i].val;
					q.push(make_pair(-dis[to],to));
				}
			}
		}
	}
	memset(flg,0,sizeof(flg));
	memset(rd,0,sizeof(rd));
	for(ri i=1;i<=cnt;i++)
	{
		if(dis[e[i].fr]+e[i].val==dis[e[i].to])
		{
			flg[i]=true;
			rd[e[i].to]++;
		}
	}
	for(ri i=1;i<=cnt;i++)
	{
		if(flg[i]&&rd[e[i].to]==1&&e[i].fr!=st)
		{
			ans[e[i].fr]=true;
		}
	}
}

signed main()
{
	n=read();
	m=read();
	for(ri i=1;i<=m;i++)
	{
		int u=read();
		int v=read();
		int val=read();
		add(u,v,val);
		add(v,u,val);
	}
	for(ri i=1;i<=n;i++)
	{
		spfa(i);
	}
	bool success=false;
	for(ri i=1;i<=n;i++)
	{
		if(ans[i])
		{
			printf("%d ",i);
			success=true;
		}
	}
	if(!success)
	{
		puts("No important cities.");
		return 0;
	}
}
