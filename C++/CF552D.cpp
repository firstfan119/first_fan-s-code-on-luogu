#include <bits/stdc++.h>
#define ri register int
#define ll long long
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

int x[maxn];
int y[maxn];

int main()
{
	int n=read();
	for(ri i=1;i<=n;i++)
	{
		x[i]=read();
		y[i]=read();
	}
	int ans=0;
	for(ri i=1;i<=n;i++)
	{
		for(ri j=i+1;j<=n;j++)
		{
			for(ri k=j+1;k<=n;k++)
			{
				if((x[j]-x[i])*(y[k]-y[j])!=(x[k]-x[j])*(y[j]-y[i]))
				{
					ans++;
				}
			}
		}
	}
	return 0&printf("%d",ans);
}
