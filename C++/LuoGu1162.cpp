#include <bits/stdc++.h>
#define ri register int
#pragma GCC optimize("O3")
using namespace std;
int n;
const int maxn=50;
int a[maxn][maxn];
bool flg[5];
int main()
{
	cin>>n;
	for(ri i=1; i<=n; i++)
	{
		for(ri j=1; j<=n; j++)
		{
			cin>>a[i][j];
		}
	}
	for(ri i=1; i<=n; i++)
	{
		for(ri j=1; j<=n; j++)
		{
			if (a[i][j]==1)
			{
				continue;
			}
			for(ri k=1; k<=4; k++)
			{
				flg[k]=false;
			}
			for(ri k=1; k<=i && !flg[1]; k++)
			{
				if (a[k][j]==1)
				{
					flg[1]=true;
				}
			}
			for(ri k=i; k<=n && !flg[2]; k++)
			{
				if (a[k][j]==1)
				{
					flg[2]=true;
				}
			}
			for(ri k=1; k<=j && !flg[3]; k++)
			{
				if (a[i][k]==1)
				{
					flg[3]=true;
				}
			}
			for(ri k=j; k<=n && !flg[4]; k++)
			{
				if (a[i][k]==1)
				{
					flg[4]=true;
				}
			}


			if (flg[1]&&flg[2]&&flg[3]&&flg[4])
			{
				a[i][j]=2;
			}
		}
	}//huge simulate
	for(ri i=1; i<=n; i++)
	{
		for(ri j=1; j<=n; j++)
		{
			printf("%d ",a[i][j]);
		}
		putchar('\n');
	}
}
/*
6
0 0 0 0 0 0
0 0 1 1 1 1
0 1 1 0 0 1
1 1 0 0 0 1
1 0 0 0 0 1
1 1 1 1 1 1
*/
