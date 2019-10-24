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

const int maxn=1e6+7;

struct knife
{
	int val;
	bool lr;
	friend bool operator<(knife one,knife two)
	{
		return one.val>two.val;
	}
} e[maxn];
int top=0;

main()
{
	int n=read();
	int m=read();
	for(ri i=1; i<n; i++)
	{
		e[++top].val=read();
		e[top].lr=0;
	}
	for(ri i=1; i<m; i++)
	{
		e[++top].val=read();
		e[top].lr=1;
	}
	sort(e+1,e+top+1);
	int l=1;
	int r=1;
	int ans=0;
	for(ri i=1; i<=top;i++)
	{
		if(e[i].lr)
		{
			ans+=e[i].val*r;
			l++;
		}
		else
		{
			ans+=e[i].val*l;
			r++;
		}
	}
	return 0&printf("%lld",ans);
}
