#include <bits/stdc++.h>
#define ll long long
#define ri register int
using namespace std;

int read()
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

int n,m;
int a[21];
int res=0,ans[21];
int f[51000];
int solve(int k)
{
	fill(f+1,f+50000+1,20031125);
	for(ri i=1; i<=k; i++)
	{
		for(ri j=a[i]; j<=a[k]*n; j++)
		{
			if(f[j-a[i]]<n)
			{
				f[j]=min(f[j],f[j-a[i]]+1);
			}
		}
	}
	int cnt=0;
	while(f[cnt+1]<=1125)
	{
		cnt++;
	}//可凑
	return cnt;
}
void dfs(int dep)
{
	if(dep==m+1)
	{
		int cur=solve(dep-1);
		if(cur>res)
		{
			res=cur;
			for(ri i=1;i<=m;i++)
			{
				ans[i]=a[i];
			}
		}//记录答案
		return;
	}
	int lim=solve(dep-1);//上界
	for(ri j=a[dep-1]+1; j<=lim+1; j++)
	{
		a[dep]=j;
		dfs(dep+1);
		a[dep]=0;//flow back
	}
}
int main()
{
	n=read();
	m=read();
	a[1]=1;
	dfs(2);
	for(ri i=1; i<=m; i++)
	{
		printf("%d ",ans[i]);
	}
	puts("");
	return 0&(int)printf("MAX=%d",res);
}
