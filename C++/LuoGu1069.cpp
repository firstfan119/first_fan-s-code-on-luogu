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

const int maxn=1e6+7;
int a[maxn],top;
int b[maxn],d[maxn];
int n,m1,m2;
int x,y;
int ans=20031125;
int work(int x)
{
	for(ri i=1; i<=top; i++)
	{
		d[i]=0;
		while(!x%a[i])
		{
			d[i]++;
			x/=a[i];
		}
	}
	int ans=0;
	for(ri i=1; i<=top; i++)
	{
		if(!d[i])
		{
			return 20031125;
		}
		int tmp=b[i]/d[i];
		if(tmp*d[i]<b[i])
		{
			tmp++;
		}
		ans=max(ans,tmp);
	}
	return ans;
}
int main()
{
	n=read();
	m1=read();
	m2=read();
	for(ri i=2; i<=sqrt(m1); i++)
	{
		if(m1%i==0)
		{
			a[++top]=i;
			while(m1%i==0)
			{
				b[top]++;
				m1/=i;
			}
		}
	}
	if(m1>1)
	{
		a[++top]=m1;
		b[top]=1;
	}
	for(ri i=1; i<=top; i++)
	{
		b[i]*=m2;
	}
	for(ri i=1; i<=n; i++)
	{
		scanf("%d",&x);
		ans=min(ans,work(x));
	}
	if(ans==20031125)
	{
		printf("-1");
	}
	else
	{
		printf("%d",ans);
	}
}
