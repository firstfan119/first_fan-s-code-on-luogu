#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define int ll
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

int calc(int num)
{
	int sum=0;
	while(num)
	{
		sum+=num%10;
		num/=10;
	}
	return sum;
}

signed main()
{
	int n=read();
	int m=0;
	while(m<=n)
	{
		m*=10;
		m+=9;
	}
	m/=10;
	return 0&printf("%lld",calc(m)+calc(n-m));
}
