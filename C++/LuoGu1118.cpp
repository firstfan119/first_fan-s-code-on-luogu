#include <bits/stdc++.h>
#define ri register int
using namespace std;
bool vis[20];
int ans[20];
int tri[20];//Yang Hui Triangle
int n,sum;
void yang_hui()
{
	tri[0]=1;
	tri[n-1]=1;
	for(ri i=1; n>1&&(i<<1)<n; i++)
	{
		tri[i]=tri[n-i-1]=(n-i)*tri[i-1]/i;
	}
}
bool dfs(int pos,int val,int _sum)
{
	if(_sum>sum)
	{
		return false;
	}
	if(pos==n)
	{
		if(_sum==sum)
		{
			ans[pos]=val;
			return true;
		}
		else
		{
			return 0;
		}
	}
	vis[val]=true;
	for(ri i=1; i<=n; i++)
	{
		if(!vis[i]&&dfs(pos+1,i,_sum+tri[pos]*i))
		{
			ans[pos]=val;
			return true;
		}
	}
	vis[val]=false;
	return false;
}
int read()
{
	int num=0;
	char c=getchar();
	while(!isdigit(c))
	{
		c=getchar();
	}
	while(isdigit(c))
	{
		num=10*num+c-48;
		c=getchar();
	}
	return num;
}
int solve()
{
	n=read();
	sum=read();
	yang_hui();
	if(dfs(0,-1,0))
	{
		for(ri i=1; i<=n; i++)
		{
			printf("%d ",*(ans+i));
		}
	}
	return 0;
}
int main()
{
	return solve();
}
