#include <bits/stdc++.h>
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

int qpow(ll m,ll n)
{
	ll res=1;
	while(n>0)
	{
		if(n&1)
		{
			res*=m;
		}
		n>>=1;
		m*=m;
	}
	return res;
}

const int maxn=1e6+7;
struct sub
{
	int v[3];
} e[maxn];

ll f[maxn];

int main()
{
	int n=read();
	int m=read();
	for(ri i=1; i<=m; i++)
	{
		e[i].v[1]=read();
		e[i].v[2]=read();
	}
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(ri i=1; i<=m; i++)
	{
		for(ri j=n; j>=1; j--)
		{
			for(ri k=0; k<=j; k++)
			{
				f[j]=min(f[j],f[j-k]+e[i].v[1]*qpow(k,e[i].v[2]));
			}
		}
	}
	return 0&printf("%lld",f[n]);
}
