//×ªÒÆ£ºf[i][j]=max(max(f[i-1][j],f[i-1][j-1]),f[i-1][j+1])+a[i][j];
#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
const int maxn=2003;
int f[maxn][maxn];
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
	return flg*num;
}

int maap[maxn][maxn];

int main()
{
	int n=read();
	int m=read();
	memset(maap,-0x3f3f3f,sizeof(maap));
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=m;j++)
		{
			maap[i][j]=read();
		}
	}
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=m;j++)
		{
			f[i][j]=max(max(f[i-1][j],f[i-1][j-1]),f[i-1][j+1])+maap[i][j];
		}
	}
	return 0&printf("%d",max(max(f[n][(m/2+1)],f[n][(m/2)]),f[n][m/2+2]));
}
