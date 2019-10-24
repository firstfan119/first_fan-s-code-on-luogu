#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define db double
using namespace std;

int read()
{
	int calc=0;
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
		calc=(calc<<1)+(calc<<3)+(c^48);
		c=getchar();
	}
	return calc*flg;
}

const int maxn=1e6+7;

int nex[maxn];
int to[maxn];
db val[maxn];

db dis[maxn];
bool vis[maxn];
db ans=20031125;

int n,m;

int x[maxn],y[maxn];
db calc(int i,int j)
{
	int x1=x[i]-x[j];
	int y1=y[i]-y[j];
	return sqrt(x1*x1+y1*y1);
}

int cnt=0;
int head[maxn];
int pre[maxn];
void add(int u,int v,db _val)
{
	nex[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	val[cnt]=_val;
}
void spfa(int f1,int f2)
{
	memset(vis,0,sizeof(vis));
	fill(dis+1,dis+n+1,20031125);
	deque<int>q;
	q.push_front(1);
	vis[1]=true;
	dis[1]=0;
	while(q.size())
	{
		int top=q.front();
		q.pop_front();
		vis[top]=false;
		for(ri i=head[top];i;i=nex[i])
		{
			int too=to[i];
			if((top==f1&&too==f2)||(top==f2&&too==f1))
			{
				continue;
			}
			if(dis[too]>dis[top]+val[i])
			{
				dis[too]=dis[top]+val[i];
				if(f1==-1&&f2==-1)
				{
					pre[too]=top;
				}
				if(!vis[too])
				{
					vis[too]=true;
					if(q.size()&&dis[too]<dis[q.front()])
					{
						q.push_front(too);
					}
					else
					{
						q.push_back(too);
					}
				}
			}
		}
	}
}
int main()
{
	n=read();
	m=read();
	for(ri i=1; i<=n; i++)
	{
		x[i]=read();
		y[i]=read();
	}
	for(ri i=1; i<=m; i++)
	{
		int u=read();
		int v=read();
		db val=calc(u,v);
		add(u,v,val);
		add(v,u,val);
	}
	spfa(-1,-1);
	for(ri i=n; pre[i]; i=pre[i])
	{
		spfa(pre[i],i);
		ans=min(ans,dis[n]);
	}
	if(ans==20031125)
	{
		return 0&printf("%d",-1);
	}
	return 0&printf("%.2lf",ans);
}
