#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
#define ls(x) x<<1
#define rs(x) x<<1|1
#define leaf (l==r)

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

const int maxn=20031125;
int n,m;
int seg[maxn];
int a[maxn];

void build(int nd,int l,int r)
{
	if(leaf)
	{
		seg[nd]=read();
		return ;
	}
	else
	{
		int mid=(l+r)>>1;
		build(ls(nd),l,mid);
		build(rs(nd),mid+1,r);
		seg[nd]=__gcd(seg[ls(nd)],seg[rs(nd)]);
	}
}

int query(int nd,int l,int r,int ln,int rn)
{
	if(ln>=l&&rn<=r)
	{
		return seg[nd];
	}
	else
	{
		int mid=(ln+rn)>>1;
		int res=0;
		if(l<=mid)
		{
			res=query(ls(nd),l,r,ln,mid);
		}
		if(r>mid)
		{
			res=__gcd(res,query(rs(nd),l,r,mid+1,rn));
		}
		return res;
	}
}

int main()
{
	n=read();
	m=read();
	build(1,1,n);
	for(ri i=1;i<=m;i++)
	{
		int u=read();
		int v=read();
		printf("%d\n",query(1,u,v,1,n));
	}
}
