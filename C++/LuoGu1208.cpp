#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5010;
ll want,farmer;
struct miilk
{
	ll price;
	ll give;
} milk[maxn];
bool cheaper(miilk zhw,miilk ljt)
{
	return zhw.price < ljt.price ;
}
int main()
{
	int sum=0;
	scanf("%lld%lld",&want,&farmer);
	for(int i=1; i<=farmer; i++)
	{
		scanf("%lld%lld",&milk[i].price,&milk[i].give);
	}
	sort(milk+1,milk+farmer+1,cheaper);
	ll now=want;
	for(int i=1; i<=farmer; i++)
	{
		if(!now) break;
		else
		{
			if(now>=milk[i].give)
			{
				sum+=milk[i].price * milk[i].give;
				now-=milk[i].give;
			}
			else
			{
				sum+=milk[i].price * now;
				now=0;
			}
		}
	}
	cout<<sum;
}
