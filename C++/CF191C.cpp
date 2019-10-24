#include<bits/stdc++.h>
#define ll long long
#define ri register int
#define fst first
#define scd second
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

#define ls(x) (x<<1)
#define rs(x) (x<<1|1)

const int maxn=1e6+7;
vector<int>e[150000];
int n;
int t[maxn];
int tag[maxn];

void pushup(int nd)
{
	t[nd]=t[ls(nd)]+t[rs(nd)];
}

void pushdown(int l,int r,int nd)
{
	if(tag[nd])
	{
		int mid=(l+r)>>1;
		tag[ls(nd)]+=tag[nd];
		tag[rs(nd)]+=tag[nd];
		t[ls(nd)]+=(mid-l+1)*tag[nd];
		t[rs(nd)]+=(r-mid)*tag[nd];
		tag[nd]=0;
	}
}
void build(int l,int r,int nd)
{
	t[nd]=0;
	tag[nd]=0;
	if(l==r)
	{
		t[nd]=0;
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls(nd));
	build(mid+1,r,rs(nd));
	pushup(nd);
}

void upd(int L,int R,int val,int l,int r,int nd)
{
	if(l>=L&&r<=R)
	{
		t[nd]+=(l-r+1)*val;
		tag[nd]+=val;
		return ;
	}
	pushdown(l,r,nd);
	int mid=(l+r)>>1;
	if(L<=mid)
	{
		upd(L,R,val,l,mid,ls(nd));
	}
	if(R>mid)
	{
		upd(L,R,val,mid+1,r,rs(nd));
	}
	pushup(nd);
}

int query(int L,int R,int l,int r,int nd)
{
	if(l>=L&&r<=R)
	{
		return t[nd];
	}
	int ans=0;
	pushdown(l,r,nd);
	int mid=(l+r)>>1;
	if(L<=mid)
	{
		ans+=query(L,R,l,mid,ls(nd));
	}
	if(R>mid)
	{
		ans+=query(L,R,mid+1,r,rs(nd));
	}
	pushup(nd);
	return ans;
}

int tim;
int dep[maxn];
int son[maxn];
int siz[maxn];
int f[maxn];
int dfn[maxn];
int top[maxn];

void updsiz(int nd,int fa,int depth)
{
	f[nd]=fa;
	dep[nd]=depth;
	son[nd]=-1;
	siz[nd]=1;
	for(ri i=0; i<e[nd].size(); i++)
	{
		int to=e[nd][i];
		if(to==fa)
		{
			continue;
		}
		updsiz(to,nd,depth+1);
		siz[nd]+=siz[to];
		if(son[nd]==-1||siz[to]>siz[son[nd]])
		{
			son[nd]=to;
		}
	}
}
void DFS(int nd,int fa,int cur)
{
	top[nd]=cur;
	dfn[nd]=++tim;
	if(son[nd]!=-1)
	{
		DFS(son[nd],nd,cur);
	}
	for(ri i=0; i<e[nd].size(); i++)
	{
		int to=e[nd][i];
		if(to==fa||to==son[nd])
		{
			continue;
		}
		DFS(to,nd,to);
	}
}
void calc(int u,int v)
{
	int fu=top[u];
	int fv=top[v];
	while(fu!=fv)
	{
		if(dep[fu]<dep[fv])
		{
			swap(u,v);
			swap(fu,fv);
		}
		upd(dfn[fu],dfn[u],1,1,n,1);
		u=f[fu];
		fu=top[u];
	}
	if(u==v)
	{
		return ;
	}
	if(dep[u]<dep[v])
	{
		swap(u,v);
	}
	upd(dfn[son[v]],dfn[u],1,1,n,1);
}

int U[maxn];
int V[maxn];
int id[maxn];
int main()
{
	while(~scanf("%d",&n))
	{
		build(1,n,1);
		for(ri i=1; i<=n; i++)
		{
			e[i].clear();
		}
		for(ri i=1; i<=n-1; i++)
		{
			U[i]=read();
			V[i]=read();
			e[U[i]].push_back(V[i]);
			e[V[i]].push_back(U[i]);
		}
		tim=0;
		updsiz(1,-1,1);
		DFS(1,-1,1);
		for(ri i=1; i<=n-1; i++)
		{
			if(dep[U[i]]<dep[V[i]])
			{
				swap(U[i],V[i]);
			}
			id[i]=dfn[U[i]];
		}
		int q=read();
		while(q--)
		{
			int u=read();
			int v=read();
			calc(u,v);
		}
		for(ri i=1; i<=n-1; i++)
		{
			printf("%d ",query(id[i],id[i],1,n,1));
		}
		puts("");
	}
}
/*
5
3 4
4 5
1 4
2 4
3
2 3
1 3
3 5
out:
3 1 1 1
*/
