#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
queue<int> qx;
queue<int> qy;
int cell[110][110];
bool vis[110][110]={false};
int direx[]={1,-1,0,0};
int direy[]={0,0,1,-1};
int n,m;
int cnt=0;
bool check()
{
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!vis[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
void dfs(int x,int y)
{if(check())
	{
		return;
	}
	for(int i=0;i<4;i++)
	{
		int x_now=x+direx[i];
		int y_now=y+direy[i];
		if(x_now>=1&&x_now<=n&&y_now>=1&&y_now<=m&&!vis[x_now][y_now]&&cell[x_now][y_now]!=0)
		{
			vis[x_now][y_now]=true;
			cnt++;
			dfs(x_now,y_now);
			vis[x_now][y_now]=false;
		}
	}
}
int main()
{
	int stx,sty;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%1d",&cell[i][j]);
			cin>>cell[i][j];
			if(cell[i][j]!=0)
			{
				stx=i;
				sty=j;
			}
		}
	}
	system("pause");
	dfs(stx,sty);
	cout<<cnt;
}
