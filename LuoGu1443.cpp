#include <bits/stdc++.h>
using namespace std;
int stx,sty,edx,edy;
int n,m;
int maap[410][410];
bool vis[410][410];
int direx[]={1,1,2,2,-1,-1,-2,-2};
int direy[]={2,-2,1,-1,2,-2,1,-1};
void dfs(int x,int y,int step)
{
	if(step>maap[edx][edy])
	{
		return;
	}
	if(x==edx&&y==edy)
	{
		maap[edx][edy]=min(maap[edx][edy],step);
		return;
	}
	for(int i=0;i<8;i++)
	{
		int x_now=x+direx[i];
		int y_now=y+direy[i];
		if(x_now>=1&&x_now<=n&&y_now>=1&&y_now<=m&&vis[x_now][y_now]==false)
		{
			vis[x_now][y_now]=true;
			dfs(x_now,y_now,step+1);
			vis[x_now][y_now]=false;
		}
	}
}
void print()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(maap[i][j]>1125)
			{
				maap[i][j]=-1;
			}
			cout<<maap[i][j];
			cout<<setw(5);
		}
		cout<<setw(0);
		cout<<endl;
	}
}
int main()
{
	memset(maap,1125,sizeof(maap));
	scanf("%d%d%d%d",&n,&m,&stx,&sty);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			memset(vis,false,sizeof(vis));
			edx=i;
			edy=j;
			dfs(stx,sty,0);
		}
	}
	print();
	return 0;
}
