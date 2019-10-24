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

const int maxn=2077;
int col[maxn][maxn];
int l[maxn][maxn];//最左
int r[maxn][maxn];//最右
int h[maxn][maxn];//高度
int ans[3];

int main()
{
	int n=read();
	int m=read();
	for(ri i=1; i<=n; i++)
	{
		for(ri j=1; j<=m; j++)
		{
			col[i][j]=read();
			l[i][j]=r[i][j]=j;
			h[i][j]=1;
		}
	}
	for(ri i=1; i<=n; i++)
	{
		for(ri j=2; j<=m; j++)
		{
			if(col[i][j]!=col[i][j-1])
			{
				l[i][j]=l[i][j-1];
			}
		}
	}
	for(ri i=1; i<=n; i++)
	{
		for(ri j=m-1; j>=1; j--)
		{
			if(col[i][j] !=col[i][j+1])
			{
				r[i][j]=r[i][j+1];
			}
		}
	}
	for(ri i=1; i<=n; i++)
	{
		for(ri j=1; j<=m; j++)
		{
			if(i>1&&col[i][j]!=col[i-1][j])
			{
				l[i][j]=max(l[i][j],l[i-1][j]);
				r[i][j]=min(r[i][j],r[i-1][j]);
				h[i][j]=h[i-1][j]+1;
			}
			int u=r[i][j]-l[i][j]+1;
			int v=min(u,h[i][j]);
			ans[1]=max(ans[1],v*v);
			ans[2]=max(ans[2],u*h[i][j]);
		}
	}
	return 0&printf("%d\n%d",ans[1],ans[2]);
}
