#include <bits/stdc++.h>
using namespace std;
int lim,num;
struct good
{
	int pri;
	int imp;
} obj[30];
int  dp[30][30010];
//放了i件物品时，剩余j金钱时的最佳方案
int main()
{
	scanf("%d%d",&lim,&num);
	for(int i=1; i<=num; i++)
	{
		scanf("%d%d",&obj[i].pri,&obj[i].imp);
	}
	for(int i=1; i<=num; i++)
	{
		for(int j=lim; j>=1; j--)
		{
			if(j>=obj[i].pri)
			{
				dp[i][j]=max(dp[i-1][j-obj[i].pri]+obj[i].imp*obj[i].pri,dp[i-1][j]);
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[num][lim];
}

