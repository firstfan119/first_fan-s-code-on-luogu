//使用lucas秒掉此题吧……
#include <bits/stdc++.h>
#define ri register int
#define int long long
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

int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
		{
			res=(res*a)% mod;
		}
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

int C(int a,int b)
{
	if(a<b)
	{
		return 0;
	}
	if(a==b)
	{
		return 1;
	}
	if(b>a-b)
	{
		b=a-b;
	}
	int ca=1;
	int cb=1;
	for(ri i=0; i<b; i++)
	{
		ca=(ca*(a-i))%mod;
		cb=(cb*(b-i))%mod;
	}
	return (ca*qpow(cb,mod-2))%mod;
}

int lucas(int n,int m)
{
	int res=1;
	while(n&&m&&res)
	{
		res=(res*C(n%mod,m%mod))%mod;
		n/=mod;
		m/=mod;
	}
	return res;
}

signed main()
{
	int n=read();
	int m=read();
	for(ri i=1;i<=m;i++)
	{
		n-=read();
	}
	return 0&printf("%d",lucas(n-1,m-1));
}
