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
struct edge
{
	int to;
	int nex;
} e[maxn];

int m=0;
int cnt=0;
int head[maxn];
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
int u[maxn];
int dfn[maxn];
int f[maxn];
void dfs(int x)
{
	dfn[x]=++m;
	for(ri i=head[x]; i; i=e[i].nex)
	{
		int to=e[i].to;
		if(to!=f[x])
		{
			f[to]=x;
			dfs(to);
		}
		u[x]=m;
	}
}

#define ls(x) (x<<1)
#define rs(x) (x<<1|1)

int ss[maxn];
int tt[maxn];

void pushdown(int p)
{
	ss[ls(p)]=ss[rs(p)]=1;
	tt[ls(p)]=tt[rs(p)]=1;
	tt[p]=0;
}

int res=0;
void upd(int p,int l,int r,int L,int R,int x)
{
	if(L<=l&&r<=R)
	{
		if(!ss[p])
		{
			res=0;
		}
		ss[p]=tt[p]=x;
		return;
	}
	if(tt[p])
	{
		pushdown(p);
	}
	int mid=(l+r)>>1;
	if(mid>=L)
	{
		upd(ls(p),l,mid,L,R,x);
	}
	if(mid<R)
	{
		upd(rs(p),mid+1,r,L,R,x);
	}
	ss[p]=ss[ls(p)]&&ss[rs(p)];
}
void query(int p,int l,int r,int L,int R)
{
	//printf("qwq\n");
	if(L<=l&&r<=R)
	{
		if(!ss[p])
		{
			res=0;
		}
		return;
	}
	if(tt[p])
	{
		pushdown(p);
	}
	int mid=(l+r)>>1;
	if(mid>=L)
	{
		query(ls(p),l,mid,L,R);
	}
	if(mid<R)
	{
		query(rs(p),mid+1,r,L,R);
	}
}
int main()
{
	int n=read();
	for(int i=1; i<=n-1; i++)
	{
		int u=read();
		int v=read();
		add(u,v);
		add(v,u);
	}
	m=0;
	dfs(1);
	int q=read();
	while(q--)
	{
		res=1;
		int opt=read();
		int val=read();
		switch(opt)
		{
			case 1:
			{
				upd(1,1,m,dfn[val],u[val],1);
				if(!res&&dfn[f[val]])
				{
					upd(1,1,m,dfn[f[val]],dfn[f[val]],0);
				}
				break;
			}
			case 2:
			{
				upd(1,1,m,dfn[val],dfn[val],0);
				break;
			}
			default:
			{
				query(1,1,m,dfn[val],u[val]);
				printf("%d\n",res);
				break;
			}
		}
	}
}
