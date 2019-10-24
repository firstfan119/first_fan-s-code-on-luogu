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

const int maxn=1e4+7;

int f[maxn];

main()
{
	int n=read();
	int m=read();
	for(ri i=1; i<=n; i++)
	{
		int x=read();
		f[x]++;
	}
	ll cnt=0;
	if(!m)
	{
		for(ri i=1;i<=maxn;i++)
		{
			cnt+=f[i]*(f[i]-1)/2;
		}
		return 0&printf("%lld",cnt);
	}//全组合
	for(ri i=1;i<=maxn;i++)
	{
		if(!f[i])
		{
			continue;
		}
		for(ri j=1;j<=maxn;j++)
		{
			if(!f[j])
			{
				continue;
			}
			ll Xor=i^j;
			int res=0;
			while(Xor)
			{
				res+=Xor%2;
				Xor>>=1;
			}
			if(res==m)
			{
				cnt+=f[i]*f[j];
			}//组合
		}
	}
	return 0&printf("%lld",cnt);
}
