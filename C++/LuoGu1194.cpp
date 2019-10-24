#include <bits/stdc++.h>
#define ri register int
using namespace std;
const int maxn=25e4;
int n,m;
int ans;
int f[maxn];
int cnt=0;
int tot=0;

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
	while(c>='0'&&c<='9')
	{
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return num*flg;
}
struct edge
{
	int u;
	int v;
	int val;
} e[maxn];
bool cmp(edge a,edge b)
{
	return a.val<b.val;
}
int find(int x)
{
	return f[x]==x?x:(f[f[x]]=find(f[x]));
}
void add(int u,int v,int val)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].val=val;
}
void kruskal()
{
	for(ri i=1; i<=cnt&&tot<=m-1; i++)
	{
		int fu=find(e[i].u);
		int fv=find(e[i].v);
		if(fu!=fv)
		{
			tot++;
			ans+=e[i].val;
			f[fu]=fv;
		}
	}
}
int main()
{
	n=read();
	m=read();
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=m; j++)
		{
			int val=read();
			if(i<j&&val!=0)
			{
				add(i,j,val);
			}
		}
	}
	for(int i=1; i<=m; i++)
	{
		add(0,i,n);
	}
	for(int i=0; i<=m; i++)
	{
		f[i]=i;
	}
	sort(e+1,e+cnt+1,cmp);
	kruskal();
	printf("%d\n",ans);
	return 0;
}
