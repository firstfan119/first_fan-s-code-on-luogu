#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define db double
//这道题要二分
//二分答案，并且用单调队列检验可行性就完事儿了
//max{Σ s[i]}<k*(r-l+1) (such that i=l..r,r-l+1∈[s,t])
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

const int maxn=1e6+7;
int n;
int s,t;
int a[maxn];
int q[maxn];//单调队列
db b[maxn];
db sum[maxn];
bool check(db k)
{
	for(ri i=1; i<=n; i++)
	{
		b[i]=(db)a[i]-k;
		sum[i]=sum[i-1]+b[i];
	}
	int head=1,tail=0;
	for(ri i=1; i<=n; i++)
	{
		if(i>=s)
		{
			while(head<=tail&&sum[i-s]<sum[q[tail]])
			{
				tail--;
			}
			q[++tail]=i-s;
		}
		if(head<=tail&&q[head]<i-t)
		{
			head++;
		}
		if(head<=tail&&sum[i]-sum[q[head]]>=0)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	n=read();
	s=read();
	t=read();
	for(ri i=1; i<=n; i++)
	{
		a[i]=read();
	}
	db l=-10000;
	db r=10000;
	while(r-l>1e-5)
	{
		db mid=(l+r)/2;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	return 0&(int)printf("%.3f",l);
}
