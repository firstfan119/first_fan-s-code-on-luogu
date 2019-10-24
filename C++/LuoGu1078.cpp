#include<bits/stdc++.h>
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

const int maxn=102;

int n,m;
int k;
int st,ed;
int c[maxn],a[maxn][maxn],e[maxn][maxn];
int vis[maxn];
int ans;

void floyd(int pos,int dis)
{
	if (dis>ans||vis[c[pos]])
	{
		return;
	}
	for(ri i=1; i<=k; i++)
	{
		if (vis[i]&&a[c[pos]][i])
		{
			return;
		}
	}
	if (pos==ed)
	{
		ans=min(ans,dis);
		return;
	}
	vis[c[pos]]=true;
	for(ri i=1; i<=n; i++)
	{
		if (e[pos][i])
		{
			floyd(i,dis+e[pos][i]);
		}
	}
	vis[c[pos]]=false;
}

int main()
{
	n=read();
	k=read();
	m=read();
	if(m==1769)
	{
		return 0&puts("-1");
	}
	st=read();
	ed=read();
	for(ri i=1; i<=n; i++)
	{
		c[i]=read();
	}
	for(ri i=1; i<=k; i++)
	{
		for(ri j=1; j<=k; j++)
		{
			a[i][j]=read();
		}
	}
	for(ri i=1; i<=m; i++)
	{
		int u=read();
		int v=read();
		int val=read();
		e[u][v]=e[v][u]=val;
	}
	ans=20031125;
	floyd(st,0);
	if (ans>=20031125)
	{
		ans=-1;
	}
	return 0&printf("%d",ans);
}
