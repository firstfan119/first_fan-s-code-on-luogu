#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,r;
int buc[23];
bool vis[23];
ll want;
void print()
{
	for(int i=1;i<=r;i++)
	{
		printf("%3d",buc[i]);
	}
	printf("\n");
}
void dfs(int dig)
{
	if(dig>r)
	{
		print();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&i>buc[dig-1])
		{
			buc[dig]=i;
			vis[i]=true;
			dfs(dig+1);
			vis[i]=false;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&r);
	dfs(1);
	return 0;
}
