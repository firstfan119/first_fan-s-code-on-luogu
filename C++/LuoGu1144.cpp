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
} e[maxn];

int cnt=0;
int head[maxn];
void add(int u,int v,int val)//此处val必为1
{
	e[++cnt].to=v;
	e[cnt].val=val;
	e[cnt].nex=head[u];
	head[u]=cnt;
}

const int mod=100003;
int dis[maxn];
int res[maxn];
bool vis[maxn];
void spfa()
{
	queue<int> q;
	q.push(1);
	vis[1]=true;
	dis[1]=0;
	res[1]=1;
	while(q.size())
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
				res[to]=res[top];//更新
				if(!vis[to])
				{
					srand((time)(0));
					vis[to]=true;
					q.push(to);
				}
			}
			else if(dis[to]==dis[top]+e[i].val)
			{
				res[to]+=res[top];
				res[to]%=mod;
			}
		}
	}
}

int main()
{
	int n=read();
	int m=read();
	fill(dis+1,dis+n+1,20031125);
	for(ri i=1;i<=m;i++)
	{
		int u=read();
		int v=read();
		add(u,v,1);
		add(v,u,1);
	}
	spfa();
	for(ri i=1;i<=n;i++)
	{
		printf("%d\n",res[i]);
	}
}
/*
5 7
1 2
1 3
2 4
3 4
2 3
4 5
4 5
out:
1
1
1
2
4
*/
