#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
bool vis[410][410];
int dx[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,-1,1,2,-2,1,-1};
int stx,sty,edx,edy;
int n,m;
int dis[410][410];
queue < int > qx,qy;
void print()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if((i!=stx||j!=sty)&&!dis[i][j])
			{
				dis[i][j]=-1;
			}
			printf("%-5d",dis[i][j]);
		}
		printf("\n");
	}
}
void bfs(int stx,int sty)
{
	vis[stx][sty]=1;
	qx.push(stx);
	qy.push(sty);
	dis[stx][sty]=0;
	while(!qx.empty())
	{
		for(int i=0;i<8;i++)
		{
			int x_now=qx.front()+dx[i];
			int y_now=qy.front()+dy[i];
			if(x_now>=1&&x_now<=n&&y_now>=1&&y_now<=m&&!vis[x_now][y_now])
			{
				vis[x_now][y_now]=1;
				qx.push(x_now);
				qy.push(y_now);
				dis[x_now][y_now]=dis[qx.front()][qy.front()]+1;
			}
		}
		qx.pop();
		qy.pop();
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&stx,&sty);
	bfs(stx,sty);
	print();
	return 0;
}
