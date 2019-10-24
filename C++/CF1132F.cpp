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
char c[maxn];
int f[maxn][maxn];

int main()
{
	int n=read();
	scanf("%s",c+1);
	memset(f,0x3f,sizeof(f));
	for(ri i=1;i<=n;i++)
	{
		f[i][i]=1;
	}
	for(ri k=1;k<=n-1;k++)
	{
		for(ri l=1;l+k<=n;l++)
		{
			int r=l+k;
			for(ri j=l;j<r;j++)
			{
				if(c[l]!=c[r])
				{
					f[l][r]=min(f[l][r],f[l][j]+f[j+1][r]);
				}
				else
				{
					f[l][r]=min(f[l][r],f[l][j]+f[j+1][r]-1);
				}
			}
		}
	}
	return 0&printf("%d",f[1][n]);
}
