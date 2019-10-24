#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
const int maxn=1125;
ll a[maxn][maxn],dp[maxn][maxn];

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
	ll n=read();
	ll m=read();
	for (ri i=1; i<=n;i++)
	{
		for (ri j=1; j<=m;j++)
		{
			a[i][j]=read();
		}
	}
	ll ans=0;
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=m;j++)
		{
			if (a[i][j]==1)
			{
				dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
			}
			ans=max(ans,dp[i][j]);
		}
	}
	return 0&printf("%lld",ans);
}
/*
4 4
0 1 1 1
1 1 1 0
0 1 1 0
1 1 0 1
out:
2
*/

