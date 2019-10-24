#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define max(one,two,three,four) (max(max(one,two),max(three,four)))
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

int f[12][12][12][12];
int maap[12][12];
int main()
{
	int n=read();
	while(1)
	{
		int u=read();
		int v=read();
		int val=read();
		if(val==0)
		{
			break;
		}
		maap[u][v]=val;
	}
	for(ri i=1; i<=n; i++)
	{
		for(ri j=1; j<=n; j++)
		{
			for(ri k=1; k<=n; k++)
			{
				for(ri l=1; l<=n; l++)
				{
					f[i][j][k][l]=max(f[i-1][j][k-1][l],f[i-1][j][k][l-1],f[i][j-1][k-1][l],f[i][j-1][k][l-1])+maap[i][j]+maap[k][l];
					if(i==k&&j==l)
					{
						f[i][j][k][l]-=maap[i][j];
					}
				}
			}
		}
	}
	return 0&printf("%d",f[n][n][n][n]);
}
/*
8
2 3 13
2 6  6
3 5  7
4 4 14
5 2 21
5 6  4
6 3 15
7 2 14
0 0  0
out:
67
*/
