#include <bits/stdc++.h>
#define ri register int
#define lowbit(x) (x&(-x))
using namespace std;

int n,len;
int a[500001],f[500001],pre[500001];
long long ans;

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

void single_add(int x,int val)    //修改树状数组
{
	while(x<=n)
	{
		pre[x]+=val;
		x+=lowbit(x);
	}
}

int interval_sum(int x)          //返回前x个数的和
{
	int sum=0;
	while(x>0)
	{
		sum+=pre[x];
		x-=lowbit(x);
	}
	return sum;
}

int main()
{
	n=read();
	for(int i=1; i<=n; ++i)
	{
		f[i]=a[i]=read();
	}
	sort(f+1,f+n+1);
	len=unique(f+1,f+n+1)-f;
	for(int i=1; i<=n;i++)
	{
		int pos=lower_bound(f+1,f+len+1,a[i])-f;
		a[i]=pos;
	}
	for(int i=1; i<=n; ++i)
	{
		single_add(a[i],1);
		ans+=i-interval_sum(a[i]);
	}
	printf("%lld\n",ans);
}
//STL去重舒服
