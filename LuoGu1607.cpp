#include <bits/stdc++.h>
#define ri register int
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define mid ((l+r)>>1)
using namespace std;
int read()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		num=(num<<1)+(num<<3)+c-48;
		c=getchar();
	}
	return num;
}
struct routine
{
	int st;
	int ed;
	int num;
}r[2000019];
bool cmp(routine a,routine b)
{
	return a.ed<b.ed;
}
int tree[100007];
int tag[100007];
void push_down(int l,int r,int p)
{
	tree[ls(p)]+=tag[p];
	tree[rs(p)]+=tag[p];
	tag[ls(p)]+=tag[p];
	tag[rs(p)]+=tag[p];
	tag[p]=0;
}
void push_up(int p)
{
	tree[p]=max(tree[ls(p)],tree[rs(p)]);
}
void update(int l,int r,int p,int l_now,int r_now,int k)
{
	if(l>=l_now&&r<=r_now)
	{
		tree[p]+=k;
		tag[p]+=k;
		return;
	}
	push_down(l,r,p);
	if(l_now<=mid) update(l,mid,ls(p),l_now,r_now,k);
	if(r_now>=(int)mid+1) update(mid+1,r,rs(p),l_now,r_now,k);
	push_up(p);
}
int query(int l,int r,int p,int l_now,int r_now)
{
	int ans=0;
	if(l>=l_now&&r<=r_now)
	{
		return tree[p];
	}
	push_down(l,r,p);
	if(l_now<=mid) ans=max(ans,query(l,mid,ls(p),l_now,r_now));
	if(r_now>=(int)mid+1) ans=max(ans,query(mid+1,r,rs(p),l_now,r_now));
	return ans;
}
int main()
{
	int k=read();
	int n=read();
	int c=read();
	for(ri i=1;i<=k;i++)
	{
		r[i].st=read();
		r[i].ed=read()-1;
		r[i].num=read();
	}
	sort(r+1,r+1+k,cmp);
	int maxn=0;
	for(ri i=1;i<=k;i++)
	{
		int x=query(1,n,1,r[i].st,r[i].ed);
		if(x<c)
		{
			int f=min(c-x,r[i].num);
			maxn+=f;
			update(1,n,1,r[i].st,r[i].ed,f);
		}
	}
	printf("%d",maxn);
}
