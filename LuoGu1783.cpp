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

const int maxn=1125;
int n,m;
int cnt;
int x[maxn];
int y[maxn];
int f[maxn];

struct node
{
	int u;
	int v;
	double val;
} e[11251125];

double calc(int x1,int y1,int x2,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool cmp(node a,node b)
{
	return a.val<b.val;
}

int find(int x)
{
	return f[x]==x?x:(f[x]=find(f[x]));
}

int main()
{
	n=read();
	m=read();
	for(ri i=1; i<=m+2; i++)
	{
		f[i]=i;
	}
	for(ri i=1; i<=m; i++)
	{
		x[i]=read();
		y[i]=read();
	}
	for(ri i=1; i<=m; i++)
	{
		for(ri j=i+1; j<=m; j++)
		{
			e[++cnt].u=i;
			e[cnt].v=j;
			e[cnt].val=calc(x[i],y[i],x[j],y[j])/2;
		}
	}
	for(ri i=1; i<=m; i++)
	{
		e[++cnt].u=i;
		e[cnt].v=0;
		e[cnt].val=x[i];
		
		e[++cnt].u=i;
		e[cnt].v=m+1;
		e[cnt].val=n-x[i];
	}

	sort(e+1,e+cnt+1,cmp);
	
	int ans=0;
	while(find(0)!=find(m+1))
	{
		ans++;
		int fu=find(e[ans].u);
		int fv=find(e[ans].v);
		if(fu!=fv)
		{
			f[fu]=fv;
		}
	}

	return 0&printf("%.2lf",e[ans].val);
}
