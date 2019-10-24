#include <bits/stdc++.h>
#define ll unsigned long long
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

ll _pow(ll a, ll b)//快速幂
{
	ll ans = 1;
	ll base = a;
	while (b)
	{
		if ((b&1)!=0)
		{
			ans*=base;
		}
		base*=base;
		b>>=1;
	}
	return ans;
}

int main()
{
	int n=read();
	if(n<=12)
	{
		return 0&printf("%lld",_pow(2,n));
	}
	else
	{
		return 0&printf("%lld",8092*_pow(2,n-13));//达芬奇的错误
	}
}
