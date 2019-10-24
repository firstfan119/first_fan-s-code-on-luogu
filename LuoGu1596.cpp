#include <bits/stdc++.h>
using namespace std;
char field[110][110];
int direx[]={ 1, 1, 1, 0 , 0,-1,-1,-1};
int direy[]={ 1, 0,-1, 1 ,-1, 1, 0,-1};
//            ↗ → ↘ ↑ ↓  ↖ ← ↙
bool vis[110][110];
int height,width;
void dfs(int x,int y)
{
	vis[x][y]=true;
	for(int i=0;i<8;i++)
	{
		int x_now=x+direx[i];
		int y_now=y+direy[i];
		if(field[x_now][y_now]=='W'&&!vis[x_now][y_now])
		{
			
			dfs(x_now,y_now);
		}
	}
}
void printmap()
{
	cout<<endl<<endl;
	for(int i=1;i<=height;i++)
	{
		for(int j=1;j<=width;j++)
		{
			cout<<field[i][j];
		}
		cout<<endl;
	}//输入模块
}
int main()
{
	cin>>height>>width;
	for(int i=1;i<=height;i++)
	{
		for(int j=1;j<=width;j++)
		{
			cin>>field[i][j];
		}
	}//输入模块
	//printmap();
	int cnt=0;
	for(int i=1;i<=height;i++)
	{
		for(int j=1;j<=width;j++)
		{
			if(field[i][j]=='W'&&!vis[i][j])
			{
				dfs(i,j);
				cnt++;
			}
		}
	}
	cout<<cnt;
}
