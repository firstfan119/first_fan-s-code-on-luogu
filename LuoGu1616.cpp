#include<bits/stdc++.h>
using namespace std;
const int maxn=11111;
int lim,kind;
int val[maxn],vol[maxn],dp[100*maxn];
//dp[fst]:目前不超过fst体积的最大价值方案
int main()
{
	scanf("%d%d",&lim,&kind);
	for(int i=1;i<=kind;i++)
	{
		scanf("%d%d",&vol[i],&val[i]);
	}
	for(int i=1;i<=kind;i++)
	{
		for(int now=vol[i];now<=lim;now++)
		{
			if(dp[now-vol[i]]+val[i]>dp[now])
			{
				dp[now]=dp[now-vol[i]]+val[i];
			}
		}
	}
	cout<<dp[lim];
	return 0;
}
