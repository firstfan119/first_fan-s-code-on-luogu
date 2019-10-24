#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define db double
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
	db val;
}e[maxn];

int cnt=0;
int head[maxn];
void add(int u,int v,db val)
{
	e[++cnt].to=v;
	e[cnt].nex=head[u];
	e[cnt].val=1.0-val;
	head[u]=cnt;
}

db dis[maxn];
bool vis[maxn];

void spfa(int st)
{
	deque<int> q;
	q.push_front(st);
	vis[st]=true;
	dis[st]=1;
	while(q.size())
	{
		int top=q.front();
		q.pop_front();
		vis[top]=false;
		for(ri i=head[top];i;i=e[i].nex)
		{
			int to=e[i].to;
			if(dis[to]<dis[top]*e[i].val)
			{
				dis[to]=dis[top]*e[i].val;
				if(!vis[to])
				{
					vis[to]=true;
					if(q.size()&&dis[to]>dis[q.front()])
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

int main()
{
	int n=read();
	int m=read();
	for(ri i=1;i<=m;i++)
	{
		int u=read();
		int v=read();
		db val;
		scanf("%lf",&val);
		val/=100.0;
		add(u,v,val);
		add(v,u,val);
	}
	int st=read();
	int ed=read();
	spfa(st);
	return 0&(int)printf("%.8lf",100.0/dis[ed]);
}
/*
3 3
1 2 1
2 3 2
1 3 3
1 3
out:
103.07153164
*/
