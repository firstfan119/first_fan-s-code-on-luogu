#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
inline int read()
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

const int maxn=1125;
int dp[maxn][maxn];
int n;
int lim1,lim2;
struct object
{
	int cost1;
	int cost2;
}o[maxn];

int main()
{
	n=read();
	lim1=read();
	lim2=read();
	for(ri i=1;i<=n;i++)
	{
		o[i].cost1=read();
		o[i].cost2=read();
	}
	for(ri i=1;i<=n;i++)
	{
		for(ri j=lim1;j>=o[i].cost1;j--)
		{
			for(ri k=lim2;k>=o[i].cost2;k--)
			{
				dp[j][k]=max(dp[j][k],dp[j-o[i].cost1][k-o[i].cost2]+1);
			}
		}
	}
	return 0&printf("%d",dp[lim1][lim2]);
}
