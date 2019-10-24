#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define db double
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

const int maxn=1e6+7;

int n;
int a[maxn];
int b[maxn];
int c[maxn];

db calc(db x)
{
	db res=-20031125;
	for(ri i=1; i<=n; i++)
	{
		res=max(res,1.0*a[i]*x*x+b[i]*x+c[i]);
	}
	return res;
}

const db eps=1e-8;

int main()
{
	int T=read();
	while(T--)
	{
		n=read();
		for(ri i=1; i<=n; i++)
		{
			a[i]=read();
			b[i]=read();
			c[i]=read();
		}
		db l=0;
		db r=1000;
		db mid=(l+r)/2;
		db lf=calc(mid-eps);
		db md=calc(mid);
		db rt=calc(mid+eps);
		while((r-l>eps)&&!(lf>md&&rt>md))
		{
			if(lf>md&&md>rt)
			{
				l=mid+eps;
			}
			else
			{
				r=mid-eps;
			}
			mid=(l+r)/2;
			lf=calc(mid-eps);
			md=calc(mid);
			rt=calc(mid+eps);
		}
		printf("%.4lf\n",md);//²»¼Ñ»»ÐÐ¼û×æ×Ú
	}
}
