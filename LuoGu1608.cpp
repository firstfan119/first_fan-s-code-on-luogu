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

const int maxn=1e4+5;
int val[2005][2005];
int vis[maxn];
int dis[maxn];
int cnt=0;
int ans[maxn];
int n,m;
int main()
{
	int n=read();
	int m=read();
	fill(dis+1,dis+n+1,20031125);
	memset(val,0x3f,sizeof(val));
	for(ri i=1; i<=m; i++)
	{
		int u=read();
		int v=read();
		int w=read();
		val[u][v]=min(val[u][v],w);
	}
	queue<int>q;
	dis[1]=0;
	vis[1]=true;
	q.push(1);
	ans[1]=1;
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		if(top==n)
		{
			continue;
		}
		vis[top]=false;
		for(ri i=1; i<=n; i++)
		{
			if(val[top][i]>=20031125)
			{
				continue;
			}
			if(dis[i]>dis[top]+val[top][i])
			{
				dis[i]=dis[top]+val[top][i];
				ans[i]=ans[top];
			}
			else if(dis[i]==dis[top]+val[top][i])
			{
				ans[i]+=ans[top];
			}
			if(ans[i]&&!vis[i])
			{
				vis[i]=true;
				q.push(i);
			}
		}
		ans[top]=0;
	}
	if(dis[n]<20031125)
	{
		printf("%d %d\n",dis[n],ans[n]);
	}
	else
	{
		puts("No answer");
	}
}
