#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define leaf (l==r)
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
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
struct segment_tree
{
	int l_val;
	int r_val;
	int val;
	bool ext;//exist or not.
} seg[maxn*4];

int arr[maxn];

void build(int nd,int l,int r)
{
	seg[nd].ext=true;
	if(leaf)
	{
		seg[nd].l_val=seg[nd].r_val=seg[nd].val=arr[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(ls(nd),l,mid);
	build(rs(nd),mid+1,r);
	seg[nd].l_val=seg[nd].r_val=seg[nd].val=seg[ls(nd)].val+seg[rs(nd)].val;
}

void upd(int nd,int ln,int rn,int l,int r)
//其实这里的l,r可以合并，因为每次只修改一个点的值.
{
	if(ln==l&&rn==r)
	{
		seg[nd].l_val=seg[nd].r_val=seg[nd].val=0;
		seg[nd].ext=false;
		return ;
	}
	int mid=(ln+rn)>>1;
	if(mid>=r)
	{
		upd(ls(nd),ln,mid,l,r);
	}
	else if(mid<l)
	{
		upd(rs(nd),mid+1,rn,l,r);
	}

	seg[nd].l_val=seg[ls(nd)].l_val;
	if(seg[ls(nd)].ext)
	{
		seg[nd].l_val+=seg[rs(nd)].l_val;
	}
	
	seg[nd].r_val=seg[rs(nd)].r_val;
	if(seg[rs(nd)].ext)
	{
		seg[nd].r_val+=seg[ls(nd)].r_val;
	}

	seg[nd].val=max(seg[rs(nd)].l_val+seg[ls(nd)].r_val,max(seg[ls(nd)].val,seg[rs(nd)].val));

	if(!seg[ls(nd)].ext||!seg[rs(nd)].ext)
	{
		seg[nd].ext=false;
	}
}

signed main()
{
	int n;
	while(scanf("%lld",&n)!=EOF)
	{
		for(ri i=1; i<=n; i++)
		{
			arr[i]=read();
		}
		build(1,1,n);
		for(ri i=1; i<=n; i++)
		{
			int u=read();
			upd(1,1,n,u,u);
			printf("%lli\n",seg[1].val);
		}
	}
}
