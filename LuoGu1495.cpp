#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ri register ll
ll a[1125],b[1125];
ll n;
ll mod=1;
ll ans=0;
void exgcd(ll a,ll b,ll &d,ll &x,ll &y)
{
	if(b==0)
	{
		d=a,x=1,y=0;
	}
	else
	{
		exgcd(b,a%b,d,x,y);
		ll temp=x;
		x=y;
		y=temp-a/b*y;
	}
}
void crt()
{
	ll each,x,y,d;
	for(ll i=1; i<=n; i++)
	{
		each=mod/a[i];
		exgcd(each,a[i],d,x,y);
		ans=((ans+each*x*b[i])%mod+mod)%mod;
	}
}
int main()
{
	scanf("%d",&n);
	for(ri i=1; i<=n; i++)
	{
		scanf("%lld%lld",&a[i],&b[i]);
		mod*=a[i];
	}
	crt();
	return 0&printf("%lld",ans);//不开浪浪见祖宗系列
}//裸中剩
