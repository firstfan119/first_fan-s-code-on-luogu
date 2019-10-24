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

int f[maxn];
int find(int x)
{
	return x==f[x]?x:(f[x]=find(f[x]));
}

struct EDGE
{
	int u,v,val,id;
	bool operator<(const EDGE one) const
	{
		return val<one.val;
	}
} e[maxn];

int tim=0;
int nex[maxn],to[maxn],head[maxn],id[maxn],ans[maxn];
int dfn[maxn];
int tarjan(int u,int fa)
{
	int lowu=dfn[u]=++tim;
	for(ri i=head[u]; ~i; i=nex[i])
	{
		int v=to[i];
		if(!dfn[v])
		{
			int lowv=tarjan(v,i);
			lowu=min(lowu,lowv);
			if(lowv>dfn[u]) ans[id[i]]=2;
		}
		else if(dfn[v]<dfn[u]&&i!=(fa^1))
		{
			lowu=min(lowu,dfn[v]);
		}
	}
	return lowu;
}

int cnt=0;
void add(int u,int v,int x)
{
	nex[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	id[cnt]=x;
}

void uni(int u,int v)
{
	int fu=find(u);
	int fv=find(v);
	if(fu!=fv)
	{
		f[fu]=fv;
	}
}

int main()
{
	int n=read();
	int m=read();
	for(ri i=1; i<=n; i++)
	{
		f[i]=i;
	}
	for(ri i=1; i<=m; i++)
	{
		e[i].u=read();
		e[i].v=read();
		e[i].val=read();
		e[i].id=i;
	}
	sort(e+1,e+m+1);
	for(ri i=1; i<=m; i++)
	{
		int j=i;
		while(j<=m&&e[i].val==e[j].val)
		{
			j++;
		}
		j--;
		for(ri k=i; k<=j; k++)
		{
			int fu=find(e[k].u);
			int fv=find(e[k].v);
			if(fu==fv)
			{
				ans[e[k].id]=0;
				continue;
			}
			ans[e[k].id]=1;
			dfn[fu]=dfn[fv]=0;
			head[fu]=head[fv]=-1;
		}
		tim=0;
		cnt=-1;
		for(ri k=i; k<=j; k++)
		{
			int fu=find(e[k].u);
			int fv=find(e[k].v);
			if(fu!=fv)
			{
				add(fu,fv,e[k].id);
				add(fv,fu,e[k].id);
			}
		}
		for(ri k=i; k<=j; k++)
		{
			if(!dfn[find(e[k].u)])
			{
				tarjan(find(e[k].u),-1);
			}
		}
		for(ri k=i; k<=j; k++)
		{
			uni(find(e[k].u),find(e[k].v));
		}
		i=j;
	}
	for(ri i=1; i<=m; i++)
	{
		if(!ans[i])
		{
			puts("none");
		}
		else if(ans[i]==2)
		{
			puts("any");
		}
		else
		{
			puts("at least one");
		}
	}
}
