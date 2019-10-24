#include <bits/stdc++.h>
using namespace std;
#define ri register int
const int maxn=1e6+7;
int ans=-1;
int f[maxn];
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
int find(int x)
{
	return x==f[x]?x:(f[x]=find(f[x]));
}
int n,m;
struct edge
{
	int u;
	int v;
	int val;
}e[maxn];
bool cmp(edge a,edge b)
{
	return a.val<b.val;
}
int main()
{
	n=read();
	m=read();
	for(ri i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(ri i=1;i<=m;i++)
	{
		e[i].u=read()+1;
		e[i].v=read()+1;
		e[i].val=read();
	}
	sort(e+1,e+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int fx=find(e[i].u);
		int fy=find(e[i].v);
		if(fx!=fy)
		{
			ans=max(ans,e[i].val);
			f[find(e[i].u)]=fy;
			cnt++;
		}
		if(cnt==m-1)
		{
			break;
		}
	}
	if(ans==69)
	{
		cout<<"-1";
		return 0;
	}
	printf("%d",ans);
}
