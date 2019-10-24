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

int direx[]={-1,0,1,0};
int direy[]={0,1,0,-1};
const int maxn=1125;
char maap[maxn][maxn];
bool vis[maxn][maxn];

int n,m;
int k;
void dfs(int x,int y)
{
	if(vis[x][y]||maap[x][y]!='.')
	{
		return ;
	}
	vis[x][y]=true;
	for(ri i=0;i<4;i++)
	{
		int x_now=x+direx[i];
		int y_now=y+direy[i];
		if(x_now>=1&&x_now<=n&&y_now>=1&&y_now<=m)
		{
			dfs(x_now,y_now);
		}
	}
	if(k)
	{
		maap[x][y]='X';
		k--;
	}
}

int main()
{
	n=read();
	m=read();
	k=read();
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=m;j++)
		{
			cin>>maap[i][j];
		}
	}
	for(ri i=1;i<=n&&k;i++)
	{
		for(ri j=1;j<=m&&k;j++)
		{
			dfs(i,j);
		}
	}
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=m;j++)
		{
			printf("%c",maap[i][j]);
		}
		printf("\n");
	}
}
