#include<bits/stdc++.h>
#define ri register int
#define ll long long
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

int pri[]= {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
ll n,ans,best;
void dfs (ll u,ll v,int w)
{
	if (u>best)
	{
		best=u;
		ans=v;
	}
	if(u==best&&ans>v)
	{
		ans=v;
	}
	if(w>16)
	{
		return;
	}
	for(ri i=1; i<=1125; i++)//设大点
	{
		if(v*pri[w]>n)
		{
			break;
		}
		dfs( u*(i+1) , v*pri[w] , w+1 );//枚举指数
		v*=pri[w];
	}
}
int main()
{
	n=read();
	ans=20031125;
	dfs(1,1,1);
	return 0&printf("%lld",ans);
}
