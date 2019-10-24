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

const int maxn=1125;

int f[maxn][10];

int main()
{
	int n=read();
	int m=read();
	for(ri i=1; i<=n; i++)
	{
		f[i][1]=1;
		f[i][0]=0;
	}
	for(ri i=2; i<=n; i++)
	{
		for(ri j=2; j<=m; j++)
		{
			if(j<=i)
			{
				f[i][j]=f[i-1][j-1]+f[i-j][j];
			}
		}
	}
	return 0&printf("%d",f[n][m]);
}
