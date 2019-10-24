#include <bits/stdc++.h>
#defirstne ri register int
using namespace std;
int read()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		num*=10;
		num+=c-48;
		c=getchar();
	}
	return num;
}
const int maxn=1024;
int a[maxn][maxn];
int dp[maxn][maxn];
int n;
int main()
{
	n=read();
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=i;j++)
		{
			a[i][j]=read();
			dp[i][j]=a[i][j];
		}
	}
	int ans=-0x3f;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i][j]+=max(dp[i-1][j],dp[i-1][j-1]);
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans;
}
