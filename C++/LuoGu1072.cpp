#include <bits/stdc++.h>
#define ri register int
#define ll long long
//ÆÓËØÆ­·Ö
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

ll lcm(ll one,ll two)
{
	return one*two/__gcd(one,two);
}
int main()
{
	int n=read();
	while(n--)
	{
		ll ans=0;
		ll a0=read();
		ll a1=read();
		ll b0=read();
		ll b1=read();
		if(b1%a1)
		{
			printf("%d\n",0);
			continue;
		}
		int s=b1/a1;
		int c=a0/a1;
		int d=b1/b0;
		ri i;
		for(i=1; i*i<s; i++)
		{
			if (s%i!=0)
			{
				continue;
			}
			int j=s/i;
			if (__gcd(c,i)==1&&__gcd(d,j)==1)
			{
				ans++;
			}
			if (__gcd(c,j)==1&&__gcd(d,i)==1)
			{
				ans++;
			}
		}
		if (i*i==s&&__gcd(c,i)==1&&__gcd(d,i)==1)
		{
			ans++;
		}
		printf("%lld\n",ans);
	}
}
