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

const int maxn=125;
int tar;

int stx,edx;
int sty,edy;

char maap[maxn][maxn];
bool v[maxn][maxn];
int direx[]= {0,0,1,-1,0};
int direy[]= {0,1,0,0,-1};

int ans=0;

void dfs(int x,int y,int dep)
{
	if (dep>tar||abs(x-edx)+abs(y-edy)>tar-dep)//×îÓÅĞÔ¼ôÖ¦
	{
		return;
	}
	if (dep==tar&&x==edx&&y==edy)
	{
		ans++;
		return;
	}
	for(ri i=1; i<=4; i++)
	{
		int nx=x+direx[i];
		int ny=y+direy[i];
		if(v[nx][ny])
		{
			dfs(nx,ny,dep+1);
		}
	}
}
int main()
{
	int n=read();
	int m=read();
	tar=read();
	for (ri i=1; i<=n; i++)
	{
		scanf("%s",maap[i]+1);
		for (ri j=1; j<=m; j++)
		{
			if(maap[i][j]=='.')
			{
				v[i][j]=1;
			}
		}
	}
	stx=read();
	sty=read();
	edx=read();
	edy=read();
	dfs(stx,sty,0);
	return 0&printf("%d",ans);
}
