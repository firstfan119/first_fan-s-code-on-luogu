#include <bits/stdc++.h>
#define ri register int
#define ll long long
#pragma GCC optimize("O3")
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
int tot=0;
int n;
const int maxn=1125;
bool vis[maxn];
bool enemy[maxn][maxn];
bool res[maxn];
void dfs(int now,int cnt)
{
	cnt++;
	if(n+cnt-now<=tot)
	{
		return;
	}
	for(int i=1; i<now; i++)
	{
		if(vis[i]&enemy[i][now])//与门
		{
			return;
		}
	}
	vis[now]=true;
	for(int i=now+1; i<=n; i++)
	{
		dfs(i,cnt);//不选
	}
	if(cnt>tot)
	{
		tot=cnt;
		for(int i=1; i<=n; i++)
		{
			res[i]=vis[i];
		}
	}
	vis[now]=false;
}

int main()
{
	n=read();
	int m=read();
	for(ri i=1; i<=m; i++)
	{
		int u=read();
		int v=read();
		enemy[u][v]=true;
		enemy[v][u]=true;
	}
	for(ri i=1;i<=n;i++)
	{
		dfs(i,0);
	}
	printf("%d\n",tot);
	for(ri i=1;i<=n;i++)
	{
		printf("%d ",res[i]);
	}
}
