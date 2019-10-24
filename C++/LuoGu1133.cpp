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

const int maxn=1e5+7;

int f[maxn][5][5][5];
int v[maxn][5];

int main()
{
	int n=read();
	for(ri i=0; i<n; i++)
	{
		for(ri j=1; j<=3; j++)
		{
			v[i][j]=read();
		}
	}
	for(ri i=1; i<4; i++)
	{
		for(ri j=1; j<4; j++)
		{
			f[0][i][j][i]=v[0][i];
		}
	}
	for(ri i=1; i<n; i++)
	{
		for(ri j=1; j<4; j++)
		{
			for(ri x=1; x<4; x++)
			{
				for(ri y=1; y<4; y++)
				{
					for(ri z=1; z<4; z++)
					{
						if((y>x&&x<j)||(y<x&&x>j))
						{
							f[i][j][x][z]=max(f[i][j][x][z],f[i-1][x][y][z]+v[i][j]);
						}
					}
				}
			}
		}
	}
	int ans=0;
	for(ri j=1; j<4; j++)
	{
		for(ri p=1; p<4; p++)
		{
			for(ri l=1; l<4; l++)
			{
				if((p<j&&j>l)||(p>j&&j<l))
				{
					ans=max(ans,f[n-1][j][p][l]);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
