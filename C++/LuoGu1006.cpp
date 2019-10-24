#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define int ll
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

const int maxn=60;
int f[maxn][maxn][maxn][maxn];
int v[maxn][maxn];

main()
{
	int n=read();
	int m=read();
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=m;j++)
		{
			v[i][j]=read();
		}
	}
 for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=m;j++)
		{
			for(ri p=1;p<=n;p++)
			{
				for(ri q=j+1;q<=m;q++)
				{
					f[i][j][p][q]=max(f[i][j-1][p-1][q],f[i-1][j][p][q-1]);
					f[i][j][p][q]=max(f[i][j][p][q],f[i][j-1][p][q-1]);
					f[i][j][p][q]=max(f[i][j][p][q],f[i-1][j][p-1][q]);
					f[i][j][p][q]+=v[i][j]+v[p][q];
				}
			}
		}
	}
	return 0&printf("%lld",f[n][m-1][n-1][m]);
}
