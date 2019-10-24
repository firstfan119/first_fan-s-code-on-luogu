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
}seg[maxn];

void build(int l,int r,int nd)
{
	seg[nd].l=l;
	seg[nd].r=r;
	if(leaf)
	{
		seg[nd].val=read();
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls(nd));
	build(mid+1,r,rs(nd));
	seg[nd].val=min(seg[ls(nd)].val,seg[rs(nd)].val);
}

int query(int l,int r,int nd)
{
	int res=20031125;
	if(l<=seg[nd].l&&r>=seg[nd].r)
	{
		return seg[nd].val;
	}
	int mid=(seg[nd].l+seg[nd].r)>>1;
	if(mid>=l)
	{
		res=min(res,query(l,r,ls(nd)));
	}
	if(mid+1<=r)
	{
		res=min(res,query(l,r,rs(nd)));
	}
	return res;
}

int main()
{
	int n=read();
	int m=read();
	build(1,n,1);
	for(ri i=1;i<=m;i++)
	{
		int l=read();
		int r=read();
		printf("%d ",query(l,r,1));
	}
}
