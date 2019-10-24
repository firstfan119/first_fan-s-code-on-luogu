#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define leaf (l==r)
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

struct segment_tree
{
	int l;
	int r;
	int val;
	int type;
} seg[maxn];

int a[maxn];

void up(int nd)
{
	if(seg[nd].type%2)
	{
		seg[nd].val=seg[ls(nd)].val|seg[rs(nd)].val;
	}
	else
	{
		seg[nd].val=seg[ls(nd)].val^seg[rs(nd)].val;
	}
}

void build(int nd,int l,int r,int type)
{
	seg[nd].l=l;
	seg[nd].r=r;
	seg[nd].type=type;
	if(leaf)
	{
		seg[nd].val=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(ls(nd),l,mid,type-1);
	build(rs(nd),mid+1,r,type-1);
	up(nd);
}

void upd(int nd,int l,int r,int L,int R)
{
	if(leaf)
	{
		seg[nd].val=R;
		return ;
	}
	int mid=(l+r)>>1;
	if(L<=mid)
	{
		upd(ls(nd),l,mid,L,R);
	}
	else
	{
		upd(rs(nd),mid+1,r,L,R);
	}
	up(nd);
}

int main()
{
	int n=read();
	int m=read();
	int _n=1<<n;
	for(ri i=1;i<=_n;i++)
	{
		a[i]=read();
	}
	build(1,1,_n,n);
	for(ri i=1;i<=m;i++)
	{
		int l=read();
		int r=read();
		upd(1,1,_n,l,r);
		printf("%d\n",seg[1].val);
	}
}
