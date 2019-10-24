#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
ll n,m;
ll a[19260817];
ll read()
{
	int num=0;
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
	while(c>='0'&&c<='9')
	{
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return num*flg;
}
int main()
{
	n=read();
	m=read();
	ll tail=n,head=1;
	for(ri i=1; i<=n; i++)
	{
		ll t=(n-i)*(n-i-1)>>1;
		if(t>=m)
		{
			a[head++]=i;
		}
		else
		{
			a[tail--]=i;
			m-=(tail-head+1);
		}
	}
	for(ri i=1; i<=n; i++)
	{
		printf("%lld ",a[i]);
	}
	return 0;
}
