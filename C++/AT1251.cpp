#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define lowbit(x) (x&(-x))
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

const int maxn=3e5+1;
int n;
int a[maxn],sorted[maxn],t[maxn];
int val[maxn];

void single_modify(int p)
{
	while(p)
	{
		val[p]++;
		p-=lowbit(p);
	}
}
int interval_sum(int p)
{
	int res=0;
	while(p<=n)
	{
		res+=val[p];
		p+=lowbit(p);
	}
	return res;
}
int main()
{
	n=read();
	for(ri i=1; i<=n; i++)
	{
		a[i]=sorted[i]=read();
	}
	sort(sorted+1,sorted+n+1);
	for(ri i=1; i<=n; i++)
	{
		a[i]=lower_bound(sorted+1,sorted+n+1,a[i])-sorted;
	}
	fill(t+1,t+n+1,20031125);
	for(ri i=1; i<=n; i++)
	{
		single_modify(a[i]);
		t[i]=min(t[i],interval_sum(a[i]+1));
	}
	fill(val+1,val+n+1,0);
	for(ri i=n; i>=1; i--)
	{
		single_modify(a[i]);
		t[i]=min(t[i],interval_sum(a[i]+1));
	}
	ll ans=0;
	for(ri i=1; i<=n; i++)
	{
		ans+=t[i];
	}
	return 0&printf("%lld",ans);
}
