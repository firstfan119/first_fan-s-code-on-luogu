#include<bits/stdc++.h>
#define f(x) dp[x+base]//谁说下标不能负？
#define ri register int
using namespace std;

int _abs[1007];//01背包
int dp[15000];
int base=6666;
int n;
int sum=0;

int read()
{
	int num=0;
	int flg=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			flg=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return flg*num;
}

int main()
{
	n=read();
	for(ri i=1; i<=n; i++)
	{
		_abs[i]=read()-read();
		sum+=_abs[i];
	}
	memset(dp,127,sizeof(dp));
	f(sum)=0;
	for(ri i=1; i<=n; i++)
	{
		if(_abs[i]<0)
		{
			for(ri val=base; val>=-base; val--)
			{
				f(val)=min(f(val),f(val+2*_abs[i])+1);
			}
		}
		else if(_abs[i]>0)
		{
			for(ri val=-base; val<=base; val++)
			{
				f(val)=min(f(val),f(val+2*_abs[i])+1);
			}
		}
	}
	for(ri i=0; i<=abs(sum); i++)
	{
		if(min(f(i),f(-i))<=5000)
		{
			cout<<min(f(i),f(-i))<<endl;
			break;
		}
	}
}
