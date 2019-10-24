#include <bits/stdc++.h>
#define db double 
using namespace std;
db a,b,c,d;
db res;
db l,r,mid;
bool used[5];
//值是用过的解 
db calc(db x)
{
	return (a*x*x*x+b*x*x+c*x+d);
}
bool check(db x)
{
	bool che=false;
	if(calc(x)==0)
	{
		for(int i=0;i<5;i++)
		{
			if(x==used[i])
			{
				return false;
				continue;
			}
			che=true;
		}
	}
	return che;
}
void solve()
{
	int cnt=0;
	bool success=false;
	for(int i=-100;i<=100;i++)
	{
		success=false;
		l=i;
		r=i+1;
		if(calc(l)==0)
		{
			printf("%.2lf ",l);
			cnt++;
		}
		if(calc(l)*calc(r)<0)
		{
			while(r-l>=1e-6)
			{
				mid=(l+r)/2;
				if(calc(mid)*calc(r)<0)
			{
				l=mid;
			}
			else r=mid;
			success=true;
			}
		}
		if(success==true)
		{
			printf("%.2lf ",r);
			cnt++;
		}
		if(cnt==3)
		{
			return;
		}
	}
}
int main()
{
	res=0;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	solve();
}
