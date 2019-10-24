#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll type;
ll want;
ll dp[10007];
ll v[37];
int read(ll &x)
{
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-48;
		c=getchar();
	}
	return true;
}
int main()
{
	dp[0]=1;
	read(type);
	read(want);
	for(register int i=1;i<=type;i++)
	{
		read(v[i]);
	}
	for(register int i=1;i<=type;i++)
	{
		for(register int j=v[i];j<=want;j++)
		{
			dp[j]+=dp[j-v[i]];
			//printf("dp[%d]=dp[%d-v[%d]]\n",j,j,i);
		}
	}
	printf("%lld",dp[want]);
}

