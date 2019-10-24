#include <bits/stdc++.h>
using namespace std;
int direx[]= {-1,0,1,0}; //x的坐标增量
int direy[]= {0,1,0,-1}; //y的坐标增量
int n,m;
int ans=0;
int maap[101][101],rout[101][101];
//rout[i][j]表示到[i,j]为止的最大长度
int dfs(int x,int y)//求到[x,y]点的最长路径
{
	int now=1;
	if (rout[x][y])
	{
		return rout[x][y];
	}
	for(int i=0; i<4; i++) //从四个方向上搜索
	{
		int x_now=x+direx[i];
		int y_now=y+direy[i];
		if(x_now>=1 && x_now<=n && y_now>=1 && y_now<=m && maap[x][y]<maap[x_now][y_now])
		{
			now=max(dfs(x_now,y_now)+1,now);//递归进行记忆化搜索
		}
	}
	rout[x][y]=now;//保存
	return now;
}
int main()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			cin>>maap[i][j];
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			ans=max(ans,dfs(i,j));
		}
	}
	printf("%d",ans);
	return 0;
}
