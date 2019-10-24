#include <bits/stdc++.h>
#define ll long long
#define ri register int
using namespace std;
int read()
{
	int num=0;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		num=(num<<3)+(num<<1)+(c^48);
		c=getchar();
	}
	return num;
}
const int maxn=5e5+5;
int l[maxn<<2],r[maxn<<2];
int a[maxn<<2];
int main()
{
	int n=read();
	for (ri i=1; i<=n; ++i)
	{
		a[i]=read();
	}
	for (ri i=1; i<=n; ++i)
	{
		l[i]=i;
		while(l[i]>1&&a[l[i]-1]>a[i])
		{
			l[i]=l[l[i]-1];
		}
	}
	for (ri i=n;i>=1;i--)
	{
		r[i]=i;
		while(r[i]<=n&&a[r[i]+1]>a[i])
		{
			r[i]=r[r[i]+1];
		}
	}
	ll llx=0;
	for (ri i=1; i<=n; ++i)
	{
		llx+=(ll)a[i]*(i-l[i]+1)*(r[i]-i+1);
	}
	cout<<llx;
}
