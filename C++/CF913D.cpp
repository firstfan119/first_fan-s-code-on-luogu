#include <bits/stdc++.h>
#define ri int
#define ll long long
using namespace std;

struct pr
{
	ll a,t,r;
};
bool cmp(pr A,pr B)
{
	return A.t < B.t;
}

vector<pr> check(const vector<pr> v,const ll T,const ll s)
{

	ll rt(T),cnt(0);
	vector<pr> res;
	for(ri i=0; i<v.size(); i++)
	{
		if(v[i].a<s)
		{
			continue;
		}
		if(v[i].t>rt)
		{
			break;
		}
		cnt++;
		rt-=v[i].t;
		res.push_back(v[i]);
		if(cnt>=s)
		{
			break;
		}
	}

	return res;
}

int main()
{

	ll n,T;
	scanf("%lld %lld",&n,&T);
	vector<pr> v(n);
	for(ri i=0; i< n; i++)
	{
		scanf("%lld %lld",&v[i].a,&v[i].t);
		v[i].r=i+1;
	}
	sort(v.begin(),v.end(),cmp);

	ll l(0),r(n);
	vector<pr> res;
	while(l <=r)
	{
		ll mid=(l+r)/ 2;
		vector<pr> cand=check(v,T,mid);
		if(cand.size()>=mid)
		{
			res=cand;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	printf("%ld\n%ld\n",res.size(),res.size());
	for(ri i=0; i<res.size(); i++)
	{
		printf("%lld ",res[i].r);
	}
	puts("");

	return 0;
}
