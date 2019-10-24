#include <bits/stdc++.h>
using namespace std;
long long dp[1001][1001];
void horsecontrol(int hx,int hy)
{
	dp[hx][hy]=0;
	dp[hx+2][hy+1]=0;
	dp[hx+1][hy+2]=0;
	dp[hx-1][hy+2]=0;
	dp[hx-2][hy+1]=0;
	dp[hx-2][hy-1]=0;
	dp[hx-1][hy-2]=0;
	dp[hx+1][hy-2]=0;
	dp[hx+2][hy-1]=0;
}
int main()
{
	int edx,edy,hx,hy;
	cin>>edx>>edy>>hx>>hy;
	edx+=2;
	edy+=2;
	hx+=2;
	hy+=2;
	for(int i=2; i<=edx; i++)
		for(int j=2; j<=edy; j++)
		{
			dp[2][2]=1;
			horsecontrol(hx,hy);
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	cout<<dp[edx][edy]<<endl;
}
