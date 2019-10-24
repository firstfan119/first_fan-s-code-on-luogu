#include<bits/stdc++.h>
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

int n,p,ans;
char s[maxn],a[maxn];

int abs(int x,int y)
{
	if (x<y) swap(x,y);
	return min(x-y, y+26-x);
}

int main()
{
	int n=read();
	int p=read()-1;
	scanf("%s",s);
	for(ri i=0; i<n; i++)
	{
		a[i]=s[i];
	}
	int now,tmp;
	now=0;
	tmp=0;
	for(ri i=0; i<n; i++)
	{
		int x=(p+i)%n;
		if (a[x] !=a[n-1-x])
		{
			tmp+=abs((int)a[x]-(int)a[n-1-x]);
			now+=tmp;
			tmp=0;
			a[x]=a[n-1-x];
		}
		tmp++;
	}
	ans=now;
	now=0;
	tmp=0;
	for(ri i=0; i<n; i++)
	{
		a[i]=s[i];
	}
	for(ri i=0; i<n; i++)
	{
		int x=(p-i+n)%n;
		if (a[x] !=a[n-1-x])
		{
			tmp+=abs(a[x],a[n-1-x]);
			now+=tmp;
			tmp=0;
			a[x]=a[n-1-x];
		}
		tmp++;
	}
	ans=min(ans,now);

	p=min(n-1-p,p);
	int l=0,r=(n-1) / 2;
	int sum=0;
	while(l<=r&&(s[l] ==s[n-1-l]))
	{
		l++;
	}
	while(l<=r&&(s[r] ==s[n-1-r]))
	{
		r--;
	}
	if (l<=p&&p<=r)
	{
		for(ri i=l; i<=r; i++)
		{
			sum+=abs(s[i],s[n-1-i]);
		}
		sum+=(r-l)+min(r-p,p-l);
		ans=min(ans,sum);
	}
	return 0&printf("%d", ans);
}

