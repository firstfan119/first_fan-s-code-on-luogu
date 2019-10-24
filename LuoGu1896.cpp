#include<bits/stdc++.h>
#define ll long long
#define ri register int
using namespace std;
long long ago;//in a galaxy faraway.
const int M=1<<9;
ll g[M],h[M],dp[10][M][82],n,k,tot=0;

ll read()
{
	ll num=0;
	ri flg=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			flg=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return num*flg;
}
int main()
{
	n=read();
	k=read();
	for(ri x=0; x<(1<<n); x++)
	{
		if(!(x&(x>>1))&&!(x&(x<<1)))g[x]=1;
		ri w=x;
		while(w)
		{
			if(w%2!=0)
			{
				h[x]++;
			}
			w>>=1;
		}
		if(g[x])
		{
			dp[1][x][h[x]]=1;
		}
	}
	for(ri x=2; x<=n; x++)
	{
		for(ri y=0; y<(1<<n); y++)
		{
			if(g[y])
			{
				for(ri z=0; z<(1<<n); z++)
				{
					if(g[z]&&!(y&z)&&!(y&(z>>1))&&!(y&(z<<1)))
					{
						for(ri w=0; w+h[z]<=k; w++)
						{
							dp[x][z][w+h[z]]+=dp[x-1][y][w]; //w枚举总共放的国王的个数
						}
					}
				}
			}
		}
	}
	for(ri y=0; y<(1<<n); y++)
	{
		tot+=dp[n][y][k];
	}
	cout<<tot;
	return 0;
}
