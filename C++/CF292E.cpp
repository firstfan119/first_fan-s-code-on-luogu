#include <bits/stdc++.h>
#define ri register int
#define ll long long
const int maxn=2e5+5;
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
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

struct segment_tree
{
	int l,r,pos1,pos2;
} seg[maxn*4];
int a[maxn],b[maxn];

void build(int x,int y, int cnt)
{
	seg[cnt].l=x;
	seg[cnt].r=y;
	seg[cnt].pos1=seg[cnt].pos2=0;
	if(x == y)
	{
		return;
	}
	int mid=(x+y)>>1;
	build(x,mid,ls(cnt));
	build(mid+1,y,rs(cnt));
}

void pushdown(int cnt)
{
	if(seg[cnt].pos1 == 0)
	{
		return;
	}
	seg[ls(cnt)].pos1=seg[rs(cnt)].pos1=seg[cnt].pos1;
	seg[ls(cnt)].pos2=seg[rs(cnt)].pos2=seg[cnt].pos2;
	seg[cnt].pos1=seg[cnt].pos2=0;
}

void update(int x,int y,int cnt,int f1,int f2)
{
	if(x == seg[cnt].l && y == seg[cnt].r)
	{
		seg[cnt].pos1=f1;
		seg[cnt].pos2=f2;
		return;
	}
	pushdown(cnt);
	int mid=(seg[cnt].l+seg[cnt].r)>>1;
	if(y<=mid)
	{
		update(x,y,ls(cnt),f1,f2);
	}
	else if(x >= mid+1)
	{
		update(x,y,rs(cnt),f1,f2);
	}
	else
	{
		update(x,mid,ls(cnt),f1,f2);
		update(mid+1,y,rs(cnt),f1,f2);
	}
}

void fid(int x,int y,int cnt)
{

	if(x == seg[cnt].l && y == seg[cnt].r)
	{
		if(seg[cnt].pos1 != 0)
		{
			printf("%d\n",a[x-seg[cnt].pos2+seg[cnt].pos1]);
		}

		else
		{
			printf("%d\n",b[x]);
		}

		return;
	}
	pushdown(cnt);
	int mid=(seg[cnt].l+seg[cnt].r)>>1;
	if(y<=mid)
	{
		fid(x,y,ls(cnt));
	}
	else if(x >= mid+1)
	{
		fid(x,y,rs(cnt));
	}
}

int main(void)
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1; i<=n; i++)
		{
			a[i]=read();
		}
		for(int i=1; i<=n; i++)
		{
			b[i]=read();
		}
		build(1,n,1);
		while(m--)
		{
			int op=read(),x,y,k;
			if(op == 2)
			{
				x=read();
				fid(x,x,1);
			}
			else
			{
				x=read();
				y=read();
				k=read();
				int tp=min(n,y+k-1);
				update(y,tp,1,x,y);
			}
		}
	}
}
