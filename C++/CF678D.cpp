#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define int ll
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

const int mod=1e9+7;

main()
{
	int a=read();
	int b=read();
	int n=read();
	int x=read();
	while(n)
	{
		if(n&1)
		{
			x=(a*x+b)%mod;
		}
		b*=(a+1);
		b%=mod;
		a*=a;
		a%=mod;
		n>>=1;
	}
	return 0&printf("%lld",x%mod);
}
