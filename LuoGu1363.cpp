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

const int maxn=1502;

char maap[maxn][maxn];
bool vis1[maxn<<1][maxn<<1];//是否到过此点
bool vis2[maxn][maxn];//映射点
int direx[]= {0,1,0,-1};
int direy[]= {1,0,-1,0};

int n,m;

bool dfs(int x,int y)
{
	if(x==-1)
	{
		return dfs(2*n-1,y);
	}
	if(x==2*n)
	{
		return dfs(0,y);
	}
	if(y==-1)
	{
		return dfs(x,2*m-1);
	}
	if(y==2*m)
	{
		return dfs(x,0);
	}//edge of the map.
	if(!vis1[x][y]&&maap[x%n][y%m]!='#')
	{
		if(vis2[x%n][y%m])
		{
			return true;
		}
		else
		{
			vis1[x][y]=true;
			vis2[x%n][y%m]=true;
			for(ri i=0; i<4; i++)
			{
				int nx=x+direx[i];
				int ny=y+direy[i];
				if(dfs(nx,ny))
				{
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	while(cin>>n>>m)
	{
		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2));
		int stx;
		int sty;
		for(ri i=0; i<n; i++)
		{
			for(ri j=0; j<m; j++)
			{
				cin>>maap[i][j];
				if(maap[i][j]=='S')
				{
					stx=i;
					sty=j;
				}
			}
		}
		printf("%s",dfs(stx,sty)?"Yes\n":"No\n");
	}
}
