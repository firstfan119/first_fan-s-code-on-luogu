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

int v[maxn];

int main()
{
	int n=read();
	for(ri i=1;i<=n;i++)
	{
		v[i]=read();
	}
	int T=read();
	
	int cur=0;
	for(ri i=1;i<=n;i++)
	{
		int tot=1;
		for(ri j=i+2;j<=n;j++)
		{
			if(v[j]<=v[i]+T)
			{
				tot++;
			}
			else
			{
				break;
			}
		}
		if(tot>cur)
		{
			cur=tot;
		}
	}
	return 0&printf("%d",cur);
}
