#include<bits/stdc++.h>
#define ll long long
#define ri register int
using namespace std;

ll read()
{
	ll num=0;
	ll flg=1;
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

ll x,y;

void exg(ll u,ll v)
{
	if(v==0)
	{
		x=1;
		y=7;
		return;
	}
	exg(v,u%v);
	ll t=x;
	x=y;
	y=t-u/v*y;
}

int main()
{
	ll u=read();
	ll v=read();
	exg(u,v);
	x+=10*v;
	x%=v;
	return 0&printf("%lld",x);
}

