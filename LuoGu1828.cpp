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
	int val;
}e[maxn];

int cnt=0;
int head[maxn];
void add(int u,int v,int val)
{
	e[++cnt].to=v;
	e[cnt].nex=head[u];
	e[cnt].val=val;
	head[u]=cnt;
}

int dis[maxn];
bool vis[maxn];

void spfa(int st)
{
	deque<int>q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push_front(st);
	vis[st]=true;
	dis[st]=0;
	while(q.size())
	{
		int top=q.front();
		q.pop_front();
		vis[top]=false;
		for(ri i=head[top];i;i=e[i].nex)
		{
			int to=e[i].to;
			if(dis[to]>dis[top]+e[i].val)
			{
				dis[to]=dis[top]+e[i].val;
				if(!vis[to])
				{
					vis[to]=true;
					if(q.size()&&dis[to]<dis[q.front()])
					{
						q.push_front(to);
					}
					else
					{
						q.push_back(to);
					}
				}
			}
		}
	}
}

int id[maxn];
int main()
{
	int cow=read();
	int n=read();
	int m=read();
	int ans=20031125;
	for(ri i=1;i<=cow;i++)
	{
		id[i]=read();
	}
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
		int res=0;
		spfa(i);
		for(ri j=1;j<=cow;j++)
		{
			res+=dis[id[j]];
		}
		ans=min(ans,res);
	}
	return 0&printf("%d",ans);
}
