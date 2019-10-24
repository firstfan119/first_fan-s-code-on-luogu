#include <bits/stdc++.h>
#define db double
#define ll long long
using namespace std;
const ll inf=0x3f3f;
ll n;
struct activity
{
	ll st;
	ll ed;
};
bool cmp(activity a,activity b)
{
 return a.ed<b.ed;
}
int main()
{
	scanf("%lld",&n);
	activity ac[n+5];
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&ac[i].st,&ac[i].ed);
	}
	sort(ac+1,ac+n+1,cmp);
	int cnt=0;
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		if(ac[i].st>=cur)
		{
			cnt++;
			cur=ac[i].ed;
		}
	}
	printf("%d",cnt);
}

