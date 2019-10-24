#include<iostream>
#define ri register int
#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
bool maap[2501][2501];
int f[2501][2501];
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
int main()
{
	n=read();
	m=read();
	for(ri  i = 1; i <= n; i++)
	{
		for(ri  j = 1; j <= m; j++)
		{
			maap[i][j]=read();
			f[i][j] = maap[i][j];
		}
	}
	for(ri  i = 1; i <= n; i++)
	{
		for(ri  j = 1; j <= m; j++)
		{
			if(maap[i][j] && f[i - 1][j - 1])
			{
				bool flg = 1;
				int l = 20031125;
				for(ri  k = i - 1; k >= i - f[i - 1][j - 1] && flg; k--)
				{
					if(maap[k][j])
					{
						flg = 0,l = min(l,i - k);
					}
				}

				for(ri  k = j - 1; k >= j - f[i - 1][j - 1] && flg; k--)
				{
					if(maap[i][k])
					{
						flg = 0,l = min(l,j - k);
					}
				}

				if(flg)
				{
					f[i][j] = f[i - 1][j - 1] + 1;
				}
				else
				{
					f[i][j] = l;
				}
			}
		}

	}

	for(ri  i = 1; i <= n; i++)
	{
		for(ri  j = 1; j <= m; j++)
		{
			ans = max(f[i][j],ans);
		}
	}


	for(ri  i = 1; i <= n; i++)
	{
		for(ri  j = 1; j <= m; j++)
		{
			f[i][j] = maap[i][j];
		}
	}


	for(ri  i = 1; i <= n; i++)
	{
		for(ri  j = m; j >= 1; j--)
		{
			if(maap[i][j] && f[i - 1][j + 1])
			{
				bool flg = 1;
				int l = 0x3f3f3f3f;
				for(ri  k = i - 1; k >= i - f[i - 1][j + 1] && flg; k--)
					if(maap[k][j]) flg = 0,l = min(l,i - k);
				for(ri  k = j + 1; k <= j + f[i - 1][j + 1] && flg; k++)
					if(maap[i][k]) flg = 0,l = min(l,k - j);
				if(flg) f[i][j] = f[i - 1][j + 1] + 1;
				else f[i][j] = l;
			}
		}
	}


	for(ri  i = 1; i <= n; i++)
		for(ri  j = 1; j <= m; j++)
			ans = max(f[i][j],ans);
	cout << ans;
	return 0;
}
