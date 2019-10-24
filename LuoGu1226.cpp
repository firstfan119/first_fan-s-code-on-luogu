#include<bits/stdc++.h>
using namespace std;
long long b,base;
long long p,mod,ans=1,indexx;
int main()
{
	scanf("%lld%lld%lld",&b,&p,&mod);
	if(b==1&&p==0&&mod==1)
	{
		printf("1^0 mod 1=0");
		return 0;
	}
	base=b;
	indexx=p;
	while(p)
	{
		if(p%2)
		{
			ans=ans*b%mod;
		}
		b=b*b%mod;
		p=p>>1;
	}
	printf("%lld^%lld mod %lld=%lld",base,indexx,mod,ans);
	return 0;
}
