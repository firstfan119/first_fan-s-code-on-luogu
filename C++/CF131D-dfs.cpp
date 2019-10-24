#include <bits/stdc++.h>
#define ri register int
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

vector<vector<int> >e;
vector<bool>vis;
vector<int>dis;
vector<int>f;
int st=-1;
bool success=false;

void round(int u,int fa)
{
	if(success)
	{
		return;
	}
	if(f[u]>=0)
	{
		int anc=fa;
		st=fa;
		while(anc!=u)
		{
			dis[anc]=0;
			anc=f[anc];
		}
		dis[anc]=0;
		success=1;
		return;
	}
	f[u]=fa;
	for(ri p=0; p<e[u].size(); p++)
	{
		int to=e[u][p];
		if(to==fa)
		{
			continue;
		}
		round(to,u);
	}
}



void dfs(int u,int cur)
{
	if(vis[u])
	{
		return;
	}
	vis[u]=1;
	for(ri p=0; p<e[u].size(); p++)
	{
		int to=e[u][p];
		if(vis[to])
		{
			continue;
		}
		if(dis[to]<0)
		{
			dis[to]=1+cur;
		}
		dfs(to,dis[to]);
	}
}

int main()
{
	int n=read();
	e.resize(n+1);
	vis.resize(n+1,0);
	dis.resize(n+1,-1);
	f.resize(n+1,-1);
	for(ri p=0; p<n; p++)
	{
		int a=read();
		int b=read();
		e[a].push_back(b);
		e[b].push_back(a);
	}
	round(1,1);
	dfs(st,0);
	for(ri p=1; p<=n; p++)
	{
		printf("%d ",dis[p]);
	};
	puts("");

	return 0;
}
