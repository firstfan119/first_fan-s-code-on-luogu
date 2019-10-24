#include <bits/stdc++.h>
#define ri register ll
#define ll long long
using namespace std;
#define leaf (l==r)
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)

ll read()
{
	ll num=0;
	ll flg=1;
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
struct segment_tree
{
	ll l,r;
	ll gcd;
	ll sum;
}seg[2003125];

ll n,m,gcd;

void pushup(ll nd)
{
	seg[nd].gcd=__gcd(seg[ls(nd)].gcd,seg[rs(nd)].gcd);
	seg[nd].sum=0;
	if(seg[nd].gcd==seg[ls(nd)].gcd)
	{
		seg[nd].sum+=seg[ls(nd)].sum;
	}
	if(seg[nd].gcd==seg[rs(nd)].gcd)
	{
		seg[nd].sum+=seg[rs(nd)].sum;
	}
}

void build(ll nd,ll l,ll r)
{
	seg[nd].l=l;
	seg[nd].r=r;
	if(leaf)
	{
		seg[nd].gcd=read();
		seg[nd].sum=1;
		return ;
	}
	ll mid=(l+r)>>1;
	build(ls(nd),l,mid);
	build(rs(nd),mid+1,r);
	pushup(nd);
}

ll interval_gcd(ll nd,ll l,ll r)
{
	if(seg[nd].l==l&&seg[nd].r==r)
	{
		return seg[nd].gcd;
	}
	ll mid=(seg[nd].l+seg[nd].r)>>1;
	if(l>mid)
	{
		return interval_gcd(rs(nd),l,r);
	}
	else if(r<=mid)
	{
		return interval_gcd(ls(nd),l,r);
	}
	else
	{
		return __gcd(interval_gcd(ls(nd),l,mid),interval_gcd(rs(nd),mid+1,r));
	}
}

ll query(ll nd,ll l,ll r)
{
	if(seg[nd].l==l&&seg[nd].r==r)
	{
		return gcd==seg[nd].gcd?seg[nd].sum:0;
	}
	ll mid=(seg[nd].l+seg[nd].r)>>1;
	if(l>mid)
	{
		return query(rs(nd),l,r);
	}
	else if(r<=mid)
	{
		return query(ls(nd),l,r);
	}
	else
	{
		return query(ls(nd),l,mid)+query(rs(nd),mid+1,r);
	}
}

int main()
{
	n=read();
	build(1,1,n);
	m=read();
	while(m--)
	{
		ll l=read();
		ll r=read();
		gcd=interval_gcd(1,l,r);
		printf("%lld\n",r+1-l-query(1,l,r));
	}
}
