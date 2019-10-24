#include <bits/stdc++.h>
#define ri register int
using namespace std;
const int maxn=1e7;
int n,m;
int ans=0;
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
	return flg*num;
}
struct edge
{
	int u;
	int v;
	int val;
} e[maxn];
int f[maxn];
int find(int x)
{
	return x==f[x]?x:(f[x]=find(f[x]));
}
bool cmp(edge a,edge b)
{
	return a.val<b.val;
}
int main()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		f[i]=i;//初始化，把所有节点的父节点都当做自己
	}
	for(int i=1; i<=m; i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].val;
	}
	sort(e+1,e+m+1,cmp);//STL sort
	int cnt=0;
	for(int i=1; i<=m; i++)
	{
		int fx=find(e[i].u);
		int fy=find(e[i].v);
		if(fx!=fy)
		{
			f[fx]=fy;
			ans=max(ans,e[i].val);
			cnt++;
		}
		if(cnt==n-1)
		{
			break;
		}
	}
	cout<<ans;
}
