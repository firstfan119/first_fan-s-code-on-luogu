#include <bits/stdc++.h>
using namespace std;
#define ri register int
int read()
{
	int num=0;
	int flg=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			flg=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return flg*num;
}
const int maxn=107;
int n,m;
int cnt=0;
struct edge
{
	int to;
	int nex;
	int val;
}ed[maxn];
int head[maxn];
void add(int fr,int to,int val)
{
	ed[++cnt].to=to;
	ed[cnt].val=val;
	ed[cnt].nex=head[fr];
	head[fr]=cnt;
}
bool vis[maxn];
int maxx=-200;
void dfs(int node,int tot)
{
	if(tot>maxx)
	{
		maxx=tot;
	}
	for(ri i=head[node];i;i=ed[i].nex)
	{
		if(!vis[ed[i].to])
		{
			vis[ed[i].to]=true;
			dfs(ed[i].to,tot+ed[i].val);
			vis[ed[i].to]=false;
		}
	}
}
int main()
{
	n=read();
	m=read();
	for(ri i=1;i<=m;i++)
	{
		int fr=read(),to=read(),val=read();
		add(fr,to,val);
		add(to,fr,val);
	}
	for(ri i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		vis[i]=true;
		dfs(i,0);
	}
	printf("%d",maxx);
}
