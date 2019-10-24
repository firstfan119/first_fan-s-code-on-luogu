#include <bits/stdc++.h>
#define ri register int
using namespace std;
int read()
{
	int num=0;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		num=(num<<3)+(num<<1)+(c^48);
		c=getchar();
	}
	return num;
}
int main()
{
	int n,m,line[100001],ans[100001],tot=0;
	n=read();
	for(ri i=1; i<=n; i++)
	{
		m=read();
		line[m]=i;
	}
	for(ri i=1; i<=n; i++)
	{
		m=read();
		int src=line[m];
		if(src>ans[tot])
		{
			ans[++tot]=src;
		}

		else
		{
			int l=0,r=tot;
			while(l<=r)
			{
				int mid=ans[(l+r)/2];
				if(src<mid)
				{
					r=(l+r)/2-1;
				}
				else
				{
					l=(l+r)/2+1;
				}
			}
			ans[l]=src;
		}
	}
	cout<<tot;
}
