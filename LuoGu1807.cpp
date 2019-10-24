#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define maxn 1000000
using namespace std;
int n,m;
struct Edge //存边
{
	int nex;
	int to;
	int val;
} e[maxn];
queue<int> q;//拓扑排序要用队列
int head[maxn];
int dis[maxn];//点的最大值
int rd[maxn];//点的入度
int a,b,p,cnt,x;
void add(int u,int v,int d)
{
	e[++cnt].nex=head[u];
	e[cnt].to=v;
	e[cnt].val=d;
	head[u]=cnt;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++)
	{
		scanf("%d%d%d",&a,&b,&p);
		add(a,b,p);
		rd[b]++;
	}
	memset(dis,-0x7f,sizeof(dis));
	for(int i=1; i<=n; i++)
	{
		if(!rd[i])q.push(i);
		if(i==1)dis[i]=0;
		else dis[i]=-maxn;
	}
	while(!q.empty()) //拓扑排序
	{
		x=q.front();
		q.pop();
		for(int i=head[x]; i; i=e[i].nex)
		{
			rd[e[i].to]--;
			dis[e[i].to]=max(dis[e[i].to],dis[x]+e[i].val);
			if(rd[e[i].to]==0)
			{
				q.push(e[i].to);
			}
		}
	}
	if(dis[n]<0)
	{
		printf("%d",-1);
		return 0;
	}
	printf("%d",dis[n]);
	return 0;
}
/*
5 6
1 2 2
1 3 3
1 4 1
4 3 4
2 3 6
3 5 5

out:13
*/
