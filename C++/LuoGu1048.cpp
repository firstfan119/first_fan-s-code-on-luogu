#include <bits/stdc++.h>
using namespace std;
int main()
{
	int limtime,obj;
	int val[1010],vol[1010];
	int dp[101][1010];
	//  dp[ i ][ j ]
	//当体积占用j时第i个物体时的最佳的方案
	scanf("%d%d",&limtime,&obj);
	for(int i=1;i<=obj;i++)
	{
		cin>>vol[i]>>val[i];
	}
	for(int i=1;i<=obj;i++)
	{
		for(int j=limtime;j>=0;j--)
		{
			if(j>=vol[i])
			{
				dp[i][j]=max(dp[i-1][j-vol[i]]+val[i],dp[i-1][j]);
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[obj][limtime];
}
