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

const int maxn=1e5+7;
struct obj
{
	int q[25];
	int p[25];
	int u;
	int v;
} e[25];

int ord[25];
bool vi[25][maxn];

int check(int x,int q,int cur)
{
	for(ri i=cur; i<cur+q; i++)
	{
		if(vi[x][i]) return 0;
	}
	for(ri i=cur; i<cur+q; i++)
	{
		vi[x][i]=1;
	}
	return 1;
}
int main()
{
	int m=read();
	int n=read();
	for(ri i=1; i<=n*m; i++)
	{
		ord[i]=read();
	}
	for(ri i=1; i<=n; i++)
	{
		e[i].u=1;
		e[i].v=0;
		for(ri j=1; j<=m; j++)
		{
			e[i].p[j]=read();
		}
	}
	for(ri i=1; i<=n; i++)
	{
		for(ri j=1; j<=m; j++)
		{
			e[i].q[j]=read();
		}
	}
	int ans=0;
	for(ri i=1; i<=n*m; i++)
	{
		for(ri j=e[ord[i]].v+1; j<=100000; j++)
		{
			if(vi[e[ord[i]].p[e[ord[i]].u]][j])
			{
				continue;
			}
			if(check(e[ord[i]].p[e[ord[i]].u],e[ord[i]].q[e[ord[i]].u],j))
			{
				e[ord[i]].v=j+e[ord[i]].q[e[ord[i]].u]-1;
				e[ord[i]].u++;
				break;
			}
		}
		ans=max(ans,e[ord[i]].v);
	}
	return 0&printf("%d",ans);
}
