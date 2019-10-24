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

int main()
{
	int n=read();
	int x=0;
	int t=0;
	int ans=0;
	for(ri i=1; i<=n; i++)
	{
		int u=read();
		int v=read();
		x-=u-t;
		x=max(x,0);
		x+=v;
		ans=max(ans,x);
		t=u;
	}
	return 0&printf("%d %d",x+t,ans);
}

