#include <bits/stdc++.h>
using namespace std;
const int direx[4] = {0,0,1,-1};
const int direy[4] = {1,-1,0,0};
int ans,stx,sty,edx,edy,n,m,c;
int vis[6][6];

void dfs(int x,int y)
{
	if(x > n||y > m||x < 1||y < 1||vis[x][y]==1)
	return;
	if(x == edx&&y ==edy)
	{
		ans++;
		return;
	}
	vis[x][y]=1;
	
	for(int i = 0; i < 4; i++)
	{
		int x_now=x + direx[i];
		int y_now=y + direy[i];
		dfs(x_now,y_now);
	}
	vis[x][y]=0;
}
int read()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		num=num*10+(c^48);
		c=getchar();
	}
	return num;
}
int main()
{
	n=read();
	m=read();
	c=read();
	stx=read();
	sty=read();
	edx=read();
	edy=read();
	for(int i = 1; i <= c; i++)
	{
		int mx,my;
		mx=read();
		my=read();
		vis[mx][my]=1;
	}
	dfs(stx,sty);
	cout << ans;
	return 0;
}
