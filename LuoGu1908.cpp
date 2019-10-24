//裸的树状数组求逆序对
#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define lowbit(x) (x&(-x))
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

int c[500010],rk[500010],n;
ll ans;
struct nd
{
	int id;
	int val;
	friend bool operator<(nd one,nd two)
	{
		return one.val==two.val?one.id<two.id:one.val<two.val;
	}
} a[500010];
void single_add(int p,int d)
{
	while(p<=n)
	{
		c[p]+=d;
		p+=lowbit(p);
	}
}
int interval_sum(int p)
{
	int res=0;
	while(p)
	{
		res+=c[p];
		p-=lowbit(p);
	}
	return res;
}
int main()
{
	n=read();
	for(ri i=1; i<=n; i++)
	{
		a[i].val=read();
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	for(ri i=1; i<=n; i++)
	{
		rk[a[i].id]=i;
	}
	for(ri i=1; i<=n; i++)
	{
		single_add(rk[i],1);
		ans+=i-interval_sum(rk[i]);
	}
	return 0&printf("%lld",ans);
}
