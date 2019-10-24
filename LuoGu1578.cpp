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

const int maxn=10002;
int n,m;
int barrier;
bool v[maxn][maxn];
int l[maxn][maxn];
int r[maxn][maxn];
int h[maxn][maxn];
int ans=0;

int main()
{
	n=read();
	m=read();
	barrier=read();
	memset(v,-1,sizeof(v));
	for(ri i=1; i<=n; i++)
	{
		for(ri j=1; j<=m; j++)
		{
			v[i][j]=1;
			l[i][j]=j;
			r[i][j]=j;
			h[i][j]=1;
		}
	}
	for(ri i=1;i<=barrier;i++)
	{
		int x=read();
		int y=read();
		v[x][y]=0;
	}
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1; j<=m; j++)
		{
			if(v[i][j]&&v[i][j-1])
			{
				l[i][j]=l[i][j-1];
			}
		}
		for(ri j=m; j>=1; j--)
		{
			if(v[i][j+1]&&v[i][j])
			{
				r[i][j]=r[i][j+1];
			}
		}
	}
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=m;j++)
		{
			if(i>1&&v[i][j]&&v[i-1][j])
			{
				r[i][j]=min(r[i][j],r[i-1][j]);
				l[i][j]=max(l[i][j],l[i-1][j]);
				h[i][j]=h[i-1][j]+1;
			}
			ans=max(ans,(r[i][j]-l[i][j]+1)*h[i][j]);
		}
	}
	return 0&printf("%d",ans*3);
}

//´ýÐÞ¸Ä¡£
