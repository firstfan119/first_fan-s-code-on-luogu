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

const int maxn=1125;
int rcp[maxn][maxn];//recipe
bool vis[maxn];
int dis[maxn];
int cnt[maxn];
int n;
void dijkstra()
{
	for(ri i=1; i<=n; i++)
	{
		int dist=20031125;
		int nex=20031125;
		for(ri j=1; j<=n; j++)
		{
			if(dist>dis[j]&&!vis[j])
			{
				nex=j;
				dist=dis[j];
			}
		}
		if(dist==20031125)//unupdated.
		{
			return ;
		}
		vis[nex]=true;
		for(ri j=1; j<=n; j++)
		{
			if(!rcp[nex][j]||!vis[j])
			{
				continue;
			}
			else if(dis[rcp[j][nex]]>dis[j]+dist)
			{
				dis[rcp[j][nex]]=dis[j]+dist;

				cnt[rcp[nex][j]]=cnt[nex]*cnt[j];
			}//≥À∑®‘≠¿Ì
			else if(dis[rcp[j][nex]]==dis[j]+dist)
			{
				cnt[rcp[nex][j]]+=cnt[nex]*cnt[j];
			}
		}
	}
}

int main()
{
	n=read();
	for(ri i=1; i<=n; i++)
	{
		dis[i]=read();
		cnt[i]=1;
	}
	int u,v,t;
	while(scanf("%d%d%d",&u,&v,&t)!=EOF)
	{
		rcp[u+1][v+1]=t+1;
		rcp[v+1][u+1]=t+1;
	}
	dijkstra();
	return 0&printf("%d %d",dis[1],cnt[1]);
}
