#include <bits/stdc++.h>
using namespace std;
int type,lim;
int val[110];
int dp[110][10010];
//前i道菜当中恰好花j元的方案数
void input()
{
	scanf("%d%d",&type,&lim);
	for(int i=1;i<=type;i++)
	{
		scanf("%d",&val[i]);
	}
}
int main()
{
	input();
	for(int i=1;i<=type;i++)
	{
		for(int j=1;j<=lim;j++)
		{
			if(j==val[i])
			{
				dp[i][j]=dp[i-1][j]+1;
			}
			else if(j>val[i])
			{
				dp[i][j]=dp[i-1][j]+dp[i-1][j-val[i]];
			}
			else if(j<val[i])
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[type][lim];
	return 0;
}
