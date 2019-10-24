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

int direx[]= {0,0,-1,0,1,1,-1,1,-1};
int direy[]= {0,-1,0,1,0,-1,1,1,-1};

const int maxn=1125;
struct sqr
{
	int x;
	int y;
	int val;
	int dir;
};

int v[maxn][maxn];
bool vis[maxn][maxn][10];//记方向的访问记录
queue<sqr>q;
int main()
{
	int m=read();
	int n=read();
	for(ri i=1; i<=n; i++)
	{
		for(ri j=1; j<=m; j++)
		{
			v[i][j]=read();
		}
	}
	q.push((sqr)
	{
		1,1,0,9
	});//方向乱设一个
	while(q.size())
	{
		sqr top=q.front();
		q.pop();
		if(top.x==n&&top.y==m)
		{
			return 0&printf("%d",top.val);
		}
		for(ri i=1; i<=8; i++)
		{
			int nx=top.x+direx[i]*v[top.x][top.y];
			int ny=top.y+direy[i]*v[top.x][top.y];
			if(nx>=1&&ny>=1&&nx<=n&&ny<=m&&i!=top.dir&&!vis[nx][ny][i])
			{
				vis[nx][ny][i]=true;
				q.push((sqr)
				{
					nx,ny,top.val+1,i
				});
			}
		}
	}
	return 0&(int)puts("NEVER");
}
