#include <bits/stdc++.h>
using namespace std;
long long a[10000],x;
int n,p;
bool flag;
long long f(long long x)
{
	int b[20],p=0;
	while (x)
	{
		p++;
		b[p]=x%10;
		x/=10;
	}
	long long y=0;
	x=0;
	sort(b+1,b+p+1);
	for (int i=1; i<=p; i++)
	{
		x=x*10+b[i];
	}
	for (int i=p; i>=1; i--)
	{
		y=y*10+b[i];
	}
	return y-x;
}
int main()
{
	while (scanf("%lld",&x)!=EOF)
	{
		a[1]=x;
		p=1;
		flag=0;
		while (!flag)
		{
			p++;
			a[p]=f(a[p-1]);
			for (int i=1; i<p; i++) if (a[p]==a[i])
				{
					for (int j=i; j<p-1; j++) printf("%lld ",a[j]);
					printf("%lld\n",a[p-1]);
					flag=1;
					break;
				}

		}
	}
}
