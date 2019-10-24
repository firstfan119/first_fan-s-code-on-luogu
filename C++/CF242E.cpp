#include <bits/stdc++.h>
#define ls(nd) (nd<<1)
#define rs(nd) (nd<<1|1)
#define mid ((seg[nd].l+seg[nd].r)>>1)
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

const int maxn=5e5+7;
int n,m;
int a[maxn>>2];
int sk[30];
ll ans;
struct node
{
	int l;
	int r;
	int bit[30];
	int tag[30];
} seg[maxn];

void pushdown(int nd)
{
	for(ri i=1; i<=23; i++)
	{
		if(seg[nd].tag[i])
		{
			seg[ls(nd)].bit[i]=seg[ls(nd)].r-seg[ls(nd)].l+1-seg[ls(nd)].bit[i];
			seg[ls(nd)].tag[i]^=1;
			seg[rs(nd)].bit[i]=seg[rs(nd)].r-seg[rs(nd)].l+1-seg[rs(nd)].bit[i];
			seg[rs(nd)].tag[i]^=1;
			seg[nd].tag[i]=0;
		}
	}
}
void pushup(int nd)
{
	for(ri i=1; i<=23; i++)
	{
		seg[nd].bit[i]=(seg[ls(nd)].bit[i]+seg[rs(nd)].bit[i]);
	}
}
void build(int nd,int l,int r)
{
	seg[nd].l=l,seg[nd].r=r;
	if(l==r)
	{
		int x=a[l];
		int g=1;
		while(x)
		{
			seg[nd].bit[g++]=x%2;
			x>>=1;
		}
		return ;
	}
	build(ls(nd),l,mid);
	build(rs(nd),mid+1,r);
	pushup(nd);
}
void upd(int nd,int l,int r,int flag)
{
	if(l<=seg[nd].l&&seg[nd].r<=r)
	{
		for(ri i=1; i<=23; i++)
		{
			if(flag&(1<<(i-1)))
			{
				seg[nd].bit[i]=seg[nd].r-seg[nd].l+1-seg[nd].bit[i];
				seg[nd].tag[i]^=1;
			}
		}
		return ;
	}
	pushdown(nd);
	if(l<=mid)
	{
		upd(ls(nd),l,r,flag);
	}
	if(r>mid)
	{
		upd(rs(nd),l,r,flag);
	}
	pushup(nd);
}
void query(int nd,int l,int r)
{
	if(l<=seg[nd].l&&seg[nd].r<=r)
	{
		for(ri i=1; i<=23; i++)
		{
			ans+=seg[nd].bit[i]*sk[i];
		}
		return ;
	}
	pushdown(nd);
	if(l<=mid)
	{
		query(ls(nd),l,r);
	}
	if(r>mid)
	{
		query(rs(nd),l,r);
	}
	pushup(nd);
}
signed main()
{
	sk[1]=1;
	for(ri i=2; i<=25; i++)
	{
		sk[i]=2*sk[i-1];
	}
	while(scanf("%lld",&n)!=EOF)//password QwQ
	{
		for(ri i=1; i<=n; i++)
		{
			a[i]=read();
		}
		build(1,1,n);
		m=read();
		while(m--)
		{
			int opt=read();
			if(opt==1)
			{
				ans=0;
				int l=read();
				int r=read();
				//printf("%lld\n",query(1,l,r));这样不行
				query(1,l,r);
				printf("%lld\n",ans);
			}
			if(opt==2)
			{
				int l=read();
				int r=read();
				int x=read();
				upd(1,l,r,x);
			}
		}
	}
}
/*
6
4 7 4 0 7 3
5
2 2 3 8
1 1 5
2 3 5 1
2 4 5 6
1 2 3
out:
38
28
*/
