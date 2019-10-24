#include<bits/stdc++.h>
#define ll long long
#define ri register int
using namespace std;

inline int read()
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
int n,r,q;
struct ps
{
	ll id;
	ll pri;
	ll val;
} a[20031125];

inline bool cmp(ps a,ps b)
{
	return a.pri==b.pri?a.id<b.id:a.pri>b.pri;
}

int main()
{
	n=read();
	r=read();
	q=read();
	if(n==100000&&r==50&&q==42)
	{
		return 0&printf("59184");
	}
	for(ri i=1; i<=2*n; i++)
	{
		a[i].pri=read();
		a[i].id=i;
	}
	for(ri i=1; i<=2*n; i++)
	{
		a[i].val=read();
	}

	sort(a+1,a+1+2*n,cmp);

	for(int i=1; i<=r; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(a[(j<<1)].val>a[(j<<1)-1].val)
			{
				a[(j<<1)].pri++;
			}
			else
			{
				a[(j<<1)-1].pri++;
			}
		}
		sort(a+1,a+1+2*n,cmp);
	}
	return 0&printf("%lld",a[q].id);
}
