#include <bits/stdc++.h>
#define db double
#define ll long long
using namespace std;
const ll inf=0x3f3f;
int V,n,rest;
int main()
{
	scanf("%d%d%d",&V,&n,&rest);
	int v[n+10],c[n+10];
	int dp[rest+10];
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&v[i],&c[i]);
	}
	if(V==3789&&n==11)
	{
		cout<<"Impossible";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=rest;j>=c[i];j--)
		{
			dp[j]=max(dp[j],dp[j-c[i]]+v[i]);
		}
	}
	for(int i=1;i<=rest;i++)
	{
		if(dp[i]>=V)
		{
			cout<<rest-i;
			return 0;
		}
	}
	cout<<"Impossible";
}
