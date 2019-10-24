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
int n,m;
int qst[maxn];
int lft[maxn];
int st[maxn],ed[maxn];
int d[maxn];
int dif[maxn];
bool check(int x)
{
	fill(dif+1,dif+n+1,0);
	for(ri i=1; i<=x; i++)
	{
		dif[st[i]]+=d[i];
		dif[ed[i]+1]-=d[i];
	}
	for(ri i=1; i<=n; i++)
	{
		qst[i]=qst[i-1]+dif[i];
		if(qst[i]>lft[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	n=read();
	m=read();
	for(ri i=1; i<=n; i++)
	{
		lft[i]=read();
	}
	for(ri i=1; i<=m; i++)
	{
		d[i]=read();
		st[i]=read();
		ed[i]=read();
	}
	int l=1,r=m;
	if(check(m))
	{
		return 0&printf("0");
	}
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	return 0&printf("-1\n%d",l);
}
