#include <bits/stdc++.h>
#define ri register int
using namespace std;
int dollar;
const int maxn=503;
bool vis[maxn];
struct event
{
	int _time;
	int cost;
}e[maxn];
int n;
bool cmp(event a,event b)
{
	return a.cost>b.cost;
}
int main()
{
	scanf("%d",&dollar);
	scanf("%d",&n);
	for(ri i=1;i<=n;i++)
	{
		scanf("%d",&e[i]._time);
	}
	for(ri i=1;i<=n;i++)
	{
		scanf("%d",&e[i].cost);
	}
	sort(e+1,e+n+1,cmp);
	for(ri i=1;i<=n;i++)
	{
		if(!vis[e[i]._time])
		{
			vis[e[i]._time]=true;
		}
		else
		{
			for(ri j=e[i]._time;j>0;j--)
			{
				if(!vis[j])
				{
					vis[j]=true;
					goto pass_cost;
				}
			}
			dollar-=e[i].cost;
			pass_cost:
				while(0);
		}
	}
	printf("%d",dollar);
}
