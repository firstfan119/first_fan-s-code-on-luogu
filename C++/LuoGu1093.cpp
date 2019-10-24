#include <bits/stdc++.h>
using namespace std;
int n;
struct student
{
	long long id;
	long long chi;
	long long sum;
};
inline bool cmp(student a,student b)
{
	if(a.sum==b.sum)
	{
		if(a.chi==b.chi)
		{
			return a.id<b.id;
		}
		else
		{
			return a.chi>b.chi;
		}
	}
	else
	{
		return a.sum>b.sum;
	}
}
int main()
{
	scanf("%d",&n);
	student st[n+500];
	for(int i=1;i<=n;i++)
	{
		int a,b;
		st[i].id=i;
		scanf("%lld%d%d",&st[i].chi,&a,&b);
		st[i].sum=st[i].sum + st[i].chi + a + b;
	}
	sort(st+1,st+n+1,cmp);
	for(int i=1;i<=5;i++)
	{
		printf("%lld %lld\n",st[i].id,st[i].sum);
	}
}
