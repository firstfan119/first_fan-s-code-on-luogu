#include<bits/stdc++.h>
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

struct interval
{
	int l;
	int r;
	int v;
	friend bool operator<(interval one,interval two)
	{
		return one.r<two.r;
	}
}e[maxn];

bool vis[maxn];
int ans=0;

int main()
{
	int n=read();
	int m=read();
	for(ri i=1;i<=m;i++)
	{
		e[i].l=read();
		e[i].r=read();
		e[i].v=read();
	}
	sort(e+1,e+m+1);
	for(ri i=1;i<=m;i++)
	{
		int cur=0;
		for(ri j=e[i].l;j<=e[i].r;j++)
		{
			if(vis[j])
			{
				cur++;
			}
		}
		if(cur>=e[i].v)
		{
			continue;
		}
		for(ri j=e[i].r;j>=e[i].l;j--)
		{
			if(!vis[j])
			{
				vis[j]=true;
				cur++;
				ans++;
				if(cur==e[i].v)
				{
					break;
				}
			}
		}
	}
	return 0&printf("%d",ans);
}
