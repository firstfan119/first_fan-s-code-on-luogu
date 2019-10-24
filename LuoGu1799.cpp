#include<bits/stdc++.h>
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

int f[11250];
int a[11250];

signed main()
{
	int n=read();
	for(ri i=1; i<=n; i++)
	{
		a[i]=read();
	}
	memset(f,20031125,sizeof(f));
	f[0]=0;
	int ans=0;
	for(ri i=1; i<=n; i++)
	{
		for(ri j=0; j<i; j++)
		{
			if(a[i]-a[j]<=i-j&&a[i]>a[j])
			{
				f[i]=max(f[i],f[j]+1);
			}
		}
		ans=max(ans,f[i]);
	}
	return 0&printf("%lld",ans);
}
