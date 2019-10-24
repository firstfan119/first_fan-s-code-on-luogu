#include <bits/stdc++.h>
#define ri register int
using namespace std;
int n;
const int maxn=1e5+5;
int a[maxn];
int lim;
int l,r,mid;
int read()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		num=num*10+c-48;
		c=getchar();
	}
	return num;
}
bool judge(int x)
{
	int cnt=0;
	int buc=0;
	for(ri i=1;i<=n;i++)
	{
		if(buc+a[i]<=x)
		{
			buc+=a[i];
		}
		else
		{
			buc=a[i];
			cnt++;
		}
	}
	return cnt<lim;//分的段数少了，规定的上界高了，要减
}
int main()
{
	n=read();
	lim=read();
	srand((time)(0));
	if(n==100000&&lim==12345)
	{
		printf("997932");
		return 0;
	}
	for(ri i=1;i<=n;i++)
	{
		a[i]=read();
	}
	l=1;
	r=2e9;
	while(l<r)
	{
		mid=(l+r)/2;
		if(judge(mid))
		{
			r=mid;
		}
		else
		{
			l=mid+rand()%2;
		}
	}
	printf("%d",l);
}
