#include<bits/stdc++.h>
#define maxn 1125
#define ri register int
#define ll long long
using namespace std;
int a,dis[maxn][maxn];
ll read()
{
	ll num=0;
	int flg=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')
		{
			flg=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return num*flg;
}
int main()
{
	int n=read();
	for(ri i=1; i<=n; i++)
	{
		for(ri j=1; j<=n; j++)
		{
			scanf("%d",&dis[i][j]);
		}
	}
	for(ri i=1; i<=n; i++)
	{
		for(ri j=1; j<=n; j++)
		{
			for(ri k=1; k<=n; ++k)
			{
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}//floyd
	int p=read();

	int ans=0;
	int minn=0x7fffffff;
	int ts[11];//treasure
	for(ri i=1; i<=p; i++)
	{
		ts[i]=read();
	}
	sort(ts+1,ts+1+p);
	do
	{
		ans=dis[1][ts[1]]+dis[ts[p]][n];
		for(ri i=1; i<p; i++)
		{
			ans+=dis[ts[i]][ts[i+1]];
		}
		minn=min(minn,ans);
	}
	while(next_permutation(ts+1,ts+1+p)); //全排列大法吼
	printf("%d\n",minn);
	return 0;
}
